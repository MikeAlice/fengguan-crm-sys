<template>
  <div class="message">
    <BaseDataList
      title="消息通知"
      :table-column-attribute="tableColumnAttribute"
      :use-operate-column="true"
      :dropdown-menu-actions-info="dropdownMenuActionsInfo"
      :page-sizes="[5, 10, 15]"
      :table-data="messageStore.tableData"
      :total="messageStore.total"
      :handle-delete="handleDelete"
      ref="baseDataListRef"
      @update-table-data="updateTableData"
    >
      <!-- 导航图标 -->
      <template #ico>
        <el-icon>
          <icon-Comment />
        </el-icon>
      </template>
      <!-- 中间搜索栏 -->
      <template #menu>
        <div class="menu">
          <div class="left">
            <el-button type="primary" @click="readBatches">
              <el-icon style="padding-right: 4px">
                <icon-FolderChecked />
              </el-icon>
              标记已读
            </el-button>
            <el-button type="danger" icon="IconDelete" @click="deleteBatches"
              >批量删除</el-button
            >
          </div>
          <!-- 右侧搜索栏 -->
          <div class="right">
            <el-input
              v-model="inputValue"
              placeholder="输入关键字搜索"
              style="margin-right: 4px; width: 224px"
              clearable
            />
            <!-- 搜索按钮还差读取数据逻辑和加载动画 -->
            <el-button
              type="primary"
              style="margin-left: 4px"
              @click="searchDetails"
            >
              <el-icon style="margin-right: 4px"> <icon-search /> </el-icon>
              搜索
            </el-button>
          </div>
        </div>
      </template>
    </BaseDataList>

    <!-- 查看消息详情的的抽屉内容 -->
    <el-drawer v-model="dialogVisible" title="查看通知">
      <el-card>
        <template #header>
          <div class="card-header" style="text-align: center">
            <span style="font-size: 24px; font-weight: 150">
              <!-- {{ detail.title }} -->聚餐
            </span>
          </div>
        </template>
        <div class="card-body" style="margin-top: 20px">
          <!-- {{ detail.content }} -->七点半, 01烧烤店集合
        </div>
      </el-card>
      <template #footer>
        <span class="dialog-footer">
          <el-button type="primary" @click="dialogVisible = false"
            >确定</el-button
          >
        </span>
      </template>
    </el-drawer>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import { useMessageStore } from '@/stores/person-homepage/messagepro'

// 批量删除的逻辑
const deleteBatches = async () => {
  if (!baseDataListRef.value.rows.length) {
    ElMessage.error('请先选择要删除的数据')
  } else {
    const ids = baseDataListRef.value.rows.map((row) => {
      return row.id
    })
    await deleteTableData({ ids }).then((res) => {
      ElMessage({
        message: res.message,
        type: 'success'
      })
    })
    baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
    await isUseInputValueGetTableData(
      baseDataListRef.value.paginationData.currentPage,
      baseDataListRef.value.paginationData.pageSize
    )
    baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  }
}
// 批量已读的逻辑(批量已读的逻辑未定)
const readBatches = async () => {
  if (!baseDataListRef.value.rows.length) {
    ElMessage.error('请先选择数据')
  } else {
    const ids = baseDataListRef.value.rows.map((row) => {
      return (row.status = {
        value: row.status ? '已读' : '未读',
        tagType: row.status ? 'info' : 'danger'
      })
    })
    await updateTableData({ ids }).then((res) => {
      ElMessage({
        message: res.message,
        type: 'success'
      })
    })
    await getTableData({
      pageIndex: baseDataListRef.value.paginationData.currentPage,
      pageSize: baseDataListRef.value.paginationData.pageSize
    })
  }
}

// 表格数据引入（必须
const messageStore = useMessageStore()

// 表格标题栏
const tableColumnAttribute = ref([
  {
    prop: 'msgType',
    label: '消息类型'
  },
  {
    prop: 'msgTitle',
    label: '提醒内容'
  },
  {
    prop: 'remindTime',
    label: '提醒时间'
  },
  {
    prop: 'createTime',
    label: '创建时间'
  },
  {
    prop: 'status',
    label: '状态',
    useTag: true
  }
])
const dropdownMenuActionsInfo = [
  {
    command: 'check',
    // row为当前行的数据
    handleAction: (row) => {
      dialogVisible.value = true
      console.log('查看的回调函数', row)
    },
    actionName: '查看'
  },
  {
    command: 'delete',
    handleAction: async (row) => {
      ElMessageBox.confirm('您确定要删除该条数据吗?', '警告', {
        confirmButtonText: '确认',
        cancelButtonText: '取消',
        type: 'warning'
      })
        .then(() => {
          deleteTableData({ ids: [row.id] }).then((res) => {
            ElMessage({
              message: res.message,
              type: 'success'
            })
          })
          getTableData({
            pageIndex: baseDataListRef.value.paginationData.currentPage,
            pageSize: baseDataListRef.value.paginationData.pageSize
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
  }
]

const baseDataListRef = ref(null)
const inputValue = ref('')

//搜索框条件
// const messageStore = useMessageStore()
const searchDetails = () => {
  console.log('t', messageStore.tableData)
  if (!inputValue.value) {
    ElMessage.error('输入不能为空')
  } else {
    console.log('pp', baseDataListRef.value.paginationData)
    baseDataListRef.value.paginationData.pageSize = 5
    baseDataListRef.value.paginationData.currentPage = 1
    // 搜索数据的时候就重新初始化页面容量和当前页的页码
    const params = {
      pageSize: 5,
      pageIndex: 1
    }
    // queryMessageStore(params)
  }
}

const getTableData = async (params) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await messageStore.getMessageList(params)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}

const getItemData = async (params) => {
  return await messageStore.getMessageIdList(params)
}

const markTableData = async (params) => {
  return await messageStore.markMessageItem(params)
}

const publishTableData = async (params) => {
  return await messageStore.publishMessageItem(params)
}

const deleteTableData = async (params) => {
  return await messageStore.deleteMessageItem(params)
}

// 分页逻辑
onMounted(() => {
  const params = {
    pageIndex: 1,
    pageSize: 5
  }
  messageStore.getMessageList(params)
})

// 删除单条数据
const handleDelete = (row) => {
  console.log('删除', row)
  ElMessageBox.confirm('你确定要删除这条数据吗?', '警告', {
    confirmButtonText: '确定',
    cancelButtonText: '取消',
    type: 'warning'
  }).then(() => {
    ElMessage({
      type: 'success',
      message: '删除成功'
    })
  })
}

// 查看公告抽屉罗辑
const detail = ref({
  id: '',
  title: '',
  content: ''
})
const dialogVisible = ref(false)
const look = (row) => {
  ;(detail.value.id = row.id),
    (detail.value.title = row.title),
    (detail.value.content = row.content),
    (dialogVisible.value = true)
}
</script>

<style lang="scss" scoped>
.message {
  width: 100%;
  height: 100%;
  .menu {
    display: flex;
    align-items: center;
    justify-content: space-between;
    margin-bottom: 10px;
    .left {
      height: 40px;
    }
    .right {
      height: 40px;
      display: flex;
      align-items: center;
    }
    .el-button {
      margin-left: 10px;
    }
  }
}
// 表格里的内容换行用
:deep(.el-table .cell) {
  white-space: pre-wrap;
}
</style>
