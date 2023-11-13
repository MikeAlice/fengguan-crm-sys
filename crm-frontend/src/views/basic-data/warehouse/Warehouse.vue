<template>
  <div class="warehouse">
    <BaseDataList
      title="仓库管理"
      :table-data="warehouseStore.tableData"
      :table-column-attribute="tableColumnAttribute"
      :use-dropdown-menu="true"
      :dropdown-menu-actions-info="dropdownMenuActionsInfo"
      :page-sizes="[5, 10, 15]"
      :total="warehouseStore.total"
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
            <el-button
              type="danger"
              style="margin-right: 8px"
              @click="handleManyDelete"
            >
              批量删除</el-button
            >
            <BulkOPe
              :getOpt="() => [0, 1]"
              :export-excel="handleExport"
              :import-excel="handleImport"
              :handle-change="
                (file) => {
                  excelFile = file
                }
              "
            ></BulkOPe>
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
      </template></BaseDataList
    >
    <WarehouseFrom
      ref="warehouseFromRef"
      :title="title"
      :handle-submit="handleSubmit"
    ></WarehouseFrom>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import WarehouseFrom from './WarehouseFrom.vue'
import { useWarehouseStore } from '@/stores/basic-data/warehouse/warehouse'
import BulkOPe from '@/components/BulkOpe/BulkOPe.vue'
import downloadFile from '@/utils/downloadfile.js'
const warehouseStore = useWarehouseStore()
const baseDataListRef = ref(null)
const warehouseFromRef = ref(null)
const tableColumnAttribute = ref([
  {
    prop: 'name',
    label: '仓库名称'
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
const title = ref('')

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
          await deleteTableData({ ids: [row.storeId] }).then((res) => {
            ElMessage({
              message: res.message,
              type: 'success'
            })
          })
          baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
          await isUseInputValueGetTableData(
            baseDataListRef.value.paginationData.pageSize,
            baseDataListRef.value.paginationData.currentPage
          )
          baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
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
      warehouseFromRef.value.visible = true
      title.value = '修改'
      const { name, sort, visible, intro } = row
      storeId.value = row.storeId
      warehouseFromRef.value.form = {
        name,
        sort,
        visible: visible ? true : false,
        intro
      }
    },
    actionName: '修改'
  }
]
const inputValue = ref('')
const storeId = ref('')
const excelFile = ref(null)
const getTableData = async (params) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await warehouseStore.getStoreList(params)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}

const deleteTableData = async (params) => {
  return await warehouseStore.deleteStoreItem(params)
}

const addTableData = async (params) => {
  return await warehouseStore.addStoreItem(params)
}

const modifyTableData = async (params) => {
  return await warehouseStore.modifyStoreItem(params)
}

const exportTableData = async (params) => {
  return await warehouseStore.exportStoreItem(params)
}

const importTableData = async (params) => {
  return await warehouseStore.importStoreItem(params)
}

const isUseInputValueGetTableData = async (pageSize, pageIndex) => {
  if (inputValue.value) {
    // 输入框有值
    await warehouseStore.getStoreList({
      pageIndex,
      pageSize,
      keyWord: inputValue.value
    })
  } else {
    await warehouseStore.getStoreList({
      pageIndex,
      pageSize
    })
  }
}

const updateSwitchState = async (state, row) => {
  baseDataListRef.value.openSwitchLoading =
    !baseDataListRef.value.openSwitchLoading
  await modifyTableData({ visible: state ? 1 : 0, storeId: row.storeId }).then(
    (res) => {
      ElMessage({
        message: res.message,
        type: 'success'
      })
    }
  )
  await isUseInputValueGetTableData(
    baseDataListRef.value.paginationData.pageSize,
    baseDataListRef.value.paginationData.currentPage
  )
  baseDataListRef.value.openSwitchLoading =
    !baseDataListRef.value.openSwitchLoading
}

const updateTableData = async (pageSize, pageIndex) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await isUseInputValueGetTableData(pageSize, pageIndex)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}

const handleAdd = () => {
  title.value = '添加'
  warehouseFromRef.value.visible = true
}

const handleSearch = async () => {
  if (inputValue.value) {
    // 执行搜索后初始化分页数据
    baseDataListRef.value.paginationData.pageSize = 5
    baseDataListRef.value.paginationData.currentPage = 1
    const params = {
      pageSize: 5,
      pageIndex: 1,
      keyWord: inputValue.value
    }
    await getTableData(params)
  } else {
    ElMessage.error('输入不能为空')
  }
}

const handleSubmit = () => {
  warehouseFromRef.value.formRef.validate(async (vaild) => {
    if (vaild) {
      const params = {
        ...warehouseFromRef.value.form
      }
      params.visible = params.visible ? 1 : 0
      if (title.value === '修改') {
        await modifyTableData({
          ...params,
          storeId: storeId.value
        }).then((res) => {
          ElMessage({
            message: res.message,
            type: 'success'
          })
        })
      } else {
        await addTableData(params).then((res) => {
          ElMessage({
            message: res.message,
            type: 'success'
          })
        })
      }
      baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
      await isUseInputValueGetTableData(
        baseDataListRef.value.paginationData.pageSize,
        baseDataListRef.value.paginationData.currentPage
      )
      baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
      warehouseFromRef.value.form = {
        name: '',
        visible: true,
        sort: 0,
        intro: ''
      }
      warehouseFromRef.value.visible = false
    }
  })
}
const handleExport = () => {
  if (!baseDataListRef.value.rows.length) {
    ElMessage.error('请先选择要导出的数据')
  } else {
    const ids = baseDataListRef.value.rows.map((row) => {
      return row.storeId
    })
    exportTableData({ ids }).then(async (res) => {
      const originalString = res.data
      const searchStr = 'http://8.130.45.222:8888'
      const startIndex = originalString.indexOf(searchStr) // 查找要截取内容的起始位置
      const extractedString = originalString.slice(
        startIndex + searchStr.length
      ) // 提取后面的内容
      // 下载文件
      await downloadFile('/file-server' + extractedString, '仓库管理')
      ElMessage({
        message: '导出成功',
        type: 'success'
      })
    })
  }
}

const handleManyDelete = async () => {
  if (!baseDataListRef.value.rows.length) {
    ElMessage.error('请先选择要删除的数据')
  } else {
    const ids = baseDataListRef.value.rows.map((row) => {
      return row.storeId
    })
    await deleteTableData({ ids }).then((res) => {
      ElMessage({
        message: res.message,
        type: 'success'
      })
    })
    baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
    await isUseInputValueGetTableData(
      baseDataListRef.value.paginationData.pageSize,
      baseDataListRef.value.paginationData.currentPage
    )
    baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  }
}
const handleImport = () => {
  importTableData({
    excelFile: excelFile.value.raw
  })
    .then(async (res) => {
      ElMessage({
        message: res.message,
        type: 'success'
      })
      await getTableData({
        pageIndex: baseDataListRef.value.paginationData.currentPage,
        pageSize: baseDataListRef.value.paginationData.pageSize
      })
    })
    .catch((error) => {
      console.log('error', error)
    })
}

onMounted(async () => {
  await getTableData({
    pageSize: 5,
    pageIndex: 1
  })
})
</script>

<style lang="scss" scoped>
.warehouse {
  .content {
    height: 38px;
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
