<template>
  <div class="Regional">
    <BaseDataList
      title="地区管理"
      :tableColumnAttribute="tableColumnAttribute"
      :tableData="regionalStore.tableData"
      :handleDelete="handleDelete"
      :handleEdit="handleEdit"
      :total="regionalStore.total"
      :pageSizes="[5, 10, 15]"
      :usePagination="true"
      :useSelectColumn="false"
      @update-table-data="updateTableData"
      @update-switch-state="updateSwitchState"
      ref="baseDataListRef"
    >
      <template #ico>
        <el-icon><icon-message-box /></el-icon>
      </template>
      <!-- 左边树形菜单 -->
      <template #treeMeau>
        <el-card class="card" v-loading="treeLoading">
          <template #header>
            <div class="card-header">
              <span>地区管理</span>
              <el-button
                @click="
                  () => {
                    getTreeData()
                  }
                "
                >刷新</el-button
              >
            </div>
          </template>
          <el-tree
            :data="regionalStore.areaTreeData"
            highlight-current
            default-expand-all
            draggable
            check-strictly
            empty-text="树形菜单内容为空"
            @node-click="handleNodeClick"
          />
        </el-card>
      </template>
      <template #menu
        ><div class="content">
          <div class="left">
            <el-button type="primary" @click="handleAdd">添加数据</el-button>
          </div>
          <div class="right">
            <el-input
              v-model="inputValue"
              placeholder="请输入搜索名称"
              style="margin: 0 4px; width: 200px"
            />
            <el-button
              type="primary"
              style="margin-left: 4px"
              @click="handleSearch"
            >
              <el-icon style="margin-right: 4px"><icon-search /></el-icon
              >搜索</el-button
            >
          </div>
        </div>
      </template>
    </BaseDataList>
    <RegionalForm
      ref="regionalFormRef"
      :title="title"
      :area-tree-data="regionalStore.areaTreeData"
      :handle-submit="handleSubmit"
    ></RegionalForm>
  </div>
</template>

<script setup>
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import RegionalForm from './RegionalForm.vue'
import { useRegionalStore } from '@/stores/basic-data/regional/regional'
import { ref, onMounted } from 'vue'
const regionalFormRef = ref(null)
const regionalStore = useRegionalStore()
const treeLoading = ref(false)
const title = ref('')
const rowId = ref('')
const nodeId = ref('')
const tableColumnAttribute = [
  {
    prop: 'name',
    label: '地区名称'
  },
  {
    prop: 'intro',
    label: '地区描述'
  },
  {
    prop: 'sort',
    label: '排序',
    sortable: true
  },
  {
    prop: 'visible',
    label: '是否启用',
    useSwitch: true
  }
]
const baseDataListRef = ref(null)
const inputValue = ref('')
const getTreeData = async (params) => {
  treeLoading.value = !treeLoading.value
  await regionalStore.queryTreeItem(params)
  treeLoading.value = !treeLoading.value
}

const getTableData = async (params) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await regionalStore.getListAreaItem(params)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}
const deleteTableData = async (params) => {
  return await regionalStore.deleteAreaItem(params)
}
const modifyTableData = async (params) => {
  return await regionalStore.modifyAreaItem(params)
}

function findObjectById(arr, id) {
  for (const item of arr) {
    if (item.id === id) {
      return item
    }
    if (item.children && item.children.length > 0) {
      const foundInChildren = findObjectById(item.children, id)
      if (foundInChildren) {
        return foundInChildren
      }
    }
  }
  return null
}

const handleDelete = (row) => {
  const option = findObjectById(regionalStore.areaTreeData, row.id)
  if (option.children.length > 0) {
    ElMessage.error('禁止删除根节点')
  } else {
    ElMessageBox.confirm('确认要删除吗?', 'Warning', {
      confirmButtonText: '确认',
      cancelButtonText: '取消',
      type: 'warning'
    })
      .then(async () => {
        await deleteTableData({ id: row.id })
          .then(async (res) => {
            ElMessage({
              message: res.message,
              type: 'success'
            })
            baseDataListRef.value.openLoading =
              !baseDataListRef.value.openLoading
            await isUseInputValueGetTableData(
              baseDataListRef.value.paginationData.pageSize,
              baseDataListRef.value.paginationData.currentPage
            )
            baseDataListRef.value.openLoading =
              !baseDataListRef.value.openLoading
            await getTreeData()
          })
          .catch((err) => {
            console.log('error', err)
          })
      })
      .catch(() => {
        ElMessage({
          type: 'info',
          message: '删除取消'
        })
      })
  }
}
const handleEdit = (row) => {
  regionalFormRef.value.visible = true
  rowId.value = row.id
  row.visible = row.visible ? true : false
  // 如果为tree的根节点 则父级栏目就是它自己
  row.parentID = row.parentID === 0 ? row.name : row.parentID
  title.value = '修改'
  // 数据回显
  regionalFormRef.value.form = {
    ...row
  }
}

const updateTableData = async (pageSize, pageIndex) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await isUseInputValueGetTableData(pageSize, pageIndex)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}

const updateSwitchState = async (state, row) => {
  baseDataListRef.value.openSwitchLoading =
    !baseDataListRef.value.openSwitchLoading
  await modifyTableData({ id: row.id, visible: state ? 1 : 0 }).then(
    async (res) => {
      ElMessage({
        message: res.message,
        type: 'success'
      })
      await isUseInputValueGetTableData(
        baseDataListRef.value.paginationData.pageSize,
        baseDataListRef.value.paginationData.currentPage
      )
      baseDataListRef.value.openSwitchLoading =
        !baseDataListRef.value.openSwitchLoading
    }
  )
}

const addTableData = async (params) => {
  return await regionalStore.insertAreaItem(params)
}

const isUseInputValueGetTableData = async (pageSize, pageIndex) => {
  if (inputValue.value) {
    // 输入框有值
    await regionalStore.getListAreaItem({
      pageIndex,
      pageSize,
      queryCondition: inputValue.value
    })
  } else if (nodeId.value) {
    // 如果左边选中了tree
    await regionalStore.getListAreaItem({
      pageSize,
      pageIndex,
      pid: nodeId.value
    })
  } else {
    await regionalStore.getListAreaItem({
      pageIndex,
      pageSize
    })
  }
}

const handleSearch = async () => {
  if (!inputValue.value) {
    ElMessage.error('输入不能为空')
  } else {
    nodeId.value = ''
    // 执行搜索后初始化分页数据
    baseDataListRef.value.paginationData.pageSize = 5
    baseDataListRef.value.paginationData.currentPage = 1
    await getTableData({
      pageSize: 5,
      pageIndex: 1,
      queryCondition: inputValue.value
    })
  }
}
const handleAdd = () => {
  title.value = '添加'
  regionalFormRef.value.visible = true
}
const handleSubmit = async () => {
  regionalFormRef.value.formRef.validate(async (vaild) => {
    if (vaild) {
      const params = {
        ...regionalFormRef.value.form
      }
      params.parentId = params.parentID
      params.visible = params.visible ? 1 : 0
      if (title.value === '修改') {
        await modifyTableData({
          ...params,
          id: rowId.value
        })
          .then((res) => {
            ElMessage({
              message: res.message,
              type: 'success'
            })
          })
          .catch((err) => {
            ElMessage.error(err.data.message)
          })
      } else {
        // 如果没选父级就默认自己为父级
        params.parentId = params.parentId ? params.parentId : 0
        await addTableData(params).then((res) => {
          ElMessage({
            message: res.message,
            type: 'success'
          })
        })
      }
      regionalFormRef.value.form = {
        name: '',
        sort: 0,
        visible: false,
        intro: '',
        parentID: ''
      }
      regionalFormRef.value.visible = false
      baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
      await isUseInputValueGetTableData(
        baseDataListRef.value.paginationData.pageSize,
        baseDataListRef.value.paginationData.currentPage
      )
      baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
      await getTreeData()
    }
  })
}
const handleNodeClick = (node) => {
  inputValue.value = ''
  nodeId.value = node.id
  getTableData({
    pageSize: 5,
    pageIndex: 1,
    pid: node.id
  })
}
onMounted(async () => {
  await getTreeData()
  await getTableData({ pageSize: 5, pageIndex: 1 })
})
</script>

<style lang="scss" scoped>
.Regional {
  .card {
    width: 40%;
    .card-header {
      display: flex;
      align-items: center;
      justify-content: space-between;
    }
  }
  .content {
    display: flex;
    align-items: center;
    justify-content: space-between;
    .right {
      display: flex;
      align-items: center;
    }
  }
}
</style>
