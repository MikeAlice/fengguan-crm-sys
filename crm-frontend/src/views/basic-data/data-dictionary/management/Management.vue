<template>
  <div class="management">
    <BaseDataList
      title="字典管理"
      :table-data="managementStore.tableData"
      :table-column-attribute="tableColumnAttribute"
      :use-dropdown-menu="true"
      :dropdown-menu-actions-info="dropdownMenuActionsInfo"
      :page-sizes="[5, 10, 15]"
      :total="managementStore.total"
      @update-table-data="updateTableData"
      @update-switch-state="updateSwitchState"
      ref="baseDataListRef"
    >
      <template #ico>
        <el-icon><icon-message-box /></el-icon
      ></template>
      <template #menu>
        <div class="content">
          <div class="left">
            <el-button type="primary" @click="handleAdd">添加数据</el-button>
            <el-button type="danger" @click="handleManyDelete"
              >批量删除</el-button
            >
          </div>
          <div class="right">
            <ChooseSelect
              des="请选择字典分类"
              :options="managementStore.options"
              @update:cid="updateCid"
              ref="chooseSelectRef"
            ></ChooseSelect>
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
    <DictionaryManageFormCom
      :title="title"
      :options="managementStore.options"
      :handle-submit="handleSubmit"
      ref="dictionaryManageFormRef"
    ></DictionaryManageFormCom>
  </div>
</template>

<script setup>
import { ref, onMounted, nextTick } from 'vue'
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'
import DictionaryManageFormCom from '@/views/basic-data/data-dictionary/components/FormCom/DictionaryManageFormCom.vue'
import { useManagementStore } from '@/stores/basic-data/data-dictionary/management'
const baseDataListRef = ref(null)
const chooseSelectRef = ref(null)
const managementStore = useManagementStore()
// 列的数据id
const rowId = ref('')
const inputValue = ref('')
const tableColumnAttribute = ref([
  {
    prop: 'id',
    label: '编号'
  },
  {
    prop: 'name',
    label: '字典名称'
  },
  {
    prop: 'typetag',
    label: '调用标识'
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
])
const dictionaryManageFormRef = ref(null)
const title = ref('')
const selectVal = ref('')
const dropdownMenuActionsInfo = [
  {
    command: 'delete',
    // row为当前行的数据
    handleAction: async (row) => {
      ElMessageBox.confirm('确认要删除吗?', 'Warning', {
        confirmButtonText: '确认',
        cancelButtonText: '取消',
        type: 'warning'
      })
        .then(async () => {
          await deleteTableData({ id: row.id }).then(async () => {
            ElMessage({
              type: 'success',
              message: '删除成功'
            })
            baseDataListRef.value.openLoading =
              !baseDataListRef.value.openLoading
            await isUseInputValueGetTableData(
              baseDataListRef.value.paginationData.pageSize,
              baseDataListRef.value.paginationData.currentPage
            )
            baseDataListRef.value.openLoading =
              !baseDataListRef.value.openLoading
          })
        })
        .catch(() => {
          ElMessage({
            type: 'info',
            message: '删除已取消'
          })
        })
    },
    actionName: '删除'
  },
  {
    command: 'edit',
    handleAction: (row) => {
      title.value = '字典修改'
      dictionaryManageFormRef.value.visible = true
      const { name, sort, visible, id, typetag } = row
      rowId.value = id
      //  数据回显
      dictionaryManageFormRef.value.form = {
        name,
        sort,
        visible
      }
      // 等待dom加载完毕后再回显下拉框数据
      nextTick(() => {
        const option = managementStore.options.find((item) => {
          return item.typetag === typetag
        })
        // 回显下拉框的值
        dictionaryManageFormRef.value.chooseSelectRef.selectValue = {
          label: option.label,
          value: option.value,
          typetag
        }
      })
    },
    actionName: '修改'
  }
]
const getOptions = async () => {
  await managementStore.getOptions()
}

const getTableData = async (params) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await managementStore.queryDictList(params)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}
const addTableData = async (params) => {
  await managementStore.addDictList(params)
}
const deleteTableData = async (params) => {
  return await managementStore.deleteDictList(params)
}

const modifyTableData = async (params) => {
  return await managementStore.modifyDictList(params)
}

const handleManyDelete = async () => {
  if (!baseDataListRef.value.rows.length) {
    ElMessage.error('请先选择')
  } else {
    // 删除的逻辑
    baseDataListRef.value.rows.forEach(async (row) => {
      await deleteTableData({ id: row.id })
    })
    ElMessage({
      type: 'success',
      message: '删除成功'
    })
    baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
    await isUseInputValueGetTableData(
      baseDataListRef.value.paginationData.pageSize,
      baseDataListRef.value.paginationData.currentPage
    )
    baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  }
}

const handleSearch = async () => {
  if (!inputValue.value.length) {
    ElMessage.error('输入不能为空')
  } else {
    // 清空下拉框的选项
    chooseSelectRef.value.selectValue = selectVal.value = ''
    await getTableData({
      pageIndex: 1,
      pageSize: 5,
      name: inputValue.value
    })
  }
}

const updateTableData = async (pageSize, pageIndex) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await isUseInputValueGetTableData(pageSize, pageIndex)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}

const isUseInputValueGetTableData = async (pageSize, pageIndex) => {
  if (inputValue.value) {
    // 输入框有值
    await managementStore.queryDictList({
      pageIndex,
      pageSize,
      name: inputValue.value
    })
  } else if (selectVal.value) {
    // 下拉框有值
    await managementStore.queryDictList({
      pageIndex,
      pageSize,
      typetag: selectVal.value.typetag
    })
  } else {
    await managementStore.queryDictList({
      pageIndex,
      pageSize
    })
  }
}

const updateSwitchState = async (state, row) => {
  baseDataListRef.value.openSwitchLoading =
    !baseDataListRef.value.openSwitchLoading
  row.visible = state ? 1 : 0
  await modifyTableData({ ...row }).then(async () => {
    ElMessage({
      message: '操作成功',
      type: 'success'
    })
    await isUseInputValueGetTableData(
      baseDataListRef.value.paginationData.pageSize,
      baseDataListRef.value.paginationData.currentPage
    )
    baseDataListRef.value.openSwitchLoading =
      !baseDataListRef.value.openSwitchLoading
  })
}

const handleAdd = () => {
  title.value = '字典添加'
  dictionaryManageFormRef.value.visible = true
}
// 下拉框事件函数
const updateCid = async (selectValue) => {
  // 清空搜索框的值
  inputValue.value = ''
  selectVal.value = selectValue
  baseDataListRef.value.paginationData.pageSize = 5
  baseDataListRef.value.paginationData.currentPage = 1
  await getTableData({
    pageIndex: 1,
    pageSize: 5,
    typetag: selectValue.typetag
  })
}

const handleSubmit = () => {
  dictionaryManageFormRef.value.formRef.validate(async (vaild) => {
    if (vaild) {
      const params = {
        ...dictionaryManageFormRef.value.form,
        typetag:
          dictionaryManageFormRef.value.chooseSelectRef.selectValue.typetag
      }
      params.visible = params.visible ? 1 : 0
      if (title.value === '字典添加') {
        await addTableData(params).then(() => {
          ElMessage({
            message: '操作成功',
            type: 'success'
          })
        })
      } else {
        await modifyTableData({
          ...params,
          id: rowId.value
        }).then(() => {
          ElMessage({
            message: '操作成功',
            type: 'success'
          })
        })
      }

      dictionaryManageFormRef.value.visible = false
      // 清空表单
      dictionaryManageFormRef.value.form = {
        name: '',
        sort: 0,
        visible: false
      }
      // 清空下拉框的选项
      chooseSelectRef.value.selectValue = selectVal.value = ''
      // 清空表单里下拉框的选项
      dictionaryManageFormRef.value.chooseSelectRef.selectValue = ''
      baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
      await isUseInputValueGetTableData(
        baseDataListRef.value.paginationData.pageSize,
        baseDataListRef.value.paginationData.currentPage
      )
      baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
    }
  })
}

onMounted(async () => {
  await getOptions()
  await getTableData({ pageIndex: 1, pageSize: 5 })
})
</script>

<style lang="scss" scoped>
.management {
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
:deep(.el-select .el-input__wrapper) {
  height: 32px;
}
</style>
