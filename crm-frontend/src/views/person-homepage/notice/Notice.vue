<template>
  <div class="notice">
    <BaseDataList
      title="公告通知"
      :table-column-attribute="tableColumnAttribute"
      :use-operate-column="true"
      :page-sizes="[5, 10, 15]"
      :total="noticeStore.total"
      :table-data="noticeStore.tableData"
      :dropdown-menu-actions-info="dropdownMenuActionsInfo"
      :useDropdownMenu="true"
      @update-table-data="updateTableData"
      ref="baseDataListRef"
    >
      <!-- 导航图标 -->
      <template #ico>
        <el-icon>
          <icon-BellFilled />
        </el-icon>
      </template>

      <!-- 中间搜索栏 -->
      <template #menu>
        <div class="menu">
          <div class="left">
            <!-- 左侧按钮区域 -->
            <el-button type="success" @click="addEvent">
              <el-icon style="padding-rigt: 5px">
                <icon-Plus />
              </el-icon>
              添加
            </el-button>
            <el-button
              type="primary"
              icon="IconChatDotRound"
              @click="readBatches"
              >批量已读</el-button
            >

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
            <!-- 搜索按钮：还差数据读取逻辑和加载loading动画 -->
            <el-button
              type="primary"
              style="margin-left: 4px"
              @click="handleSearch"
            >
              <el-icon style="margin-right: 4px"> <icon-search /> </el-icon>
              搜索
            </el-button>
          </div>
        </div>
      </template>
    </BaseDataList>

    <!-- 添加的抽屉内容 -->
    <el-drawer v-model="addDrawer" title="添加通知">
      <el-form
        ref="noticeFormRef"
        :model="form"
        :rules="rules"
        label-width="120px"
      >
        <el-form-item label="通知标题" prop="title">
          <el-input v-model="form.title" placeholder="输入标题" clearable />
        </el-form-item>
        <el-form-item label="通知对象" prop="ownerDeptId">
          <ChooseSelect
            v-model="form.ownerDeptId"
            :options="noticeStore.optionsDepartmentName"
            des="请选通知部门"
            style="width: 60%"
          ></ChooseSelect>
        </el-form-item>
        <el-form-item label="指定对象" prop="ownerUserId">
          <ChooseSelect
            v-model="form.ownerUserId"
            :options="noticeStore.optionsUserName"
            des="请选指定对象"
            style="width: 60%"
          >
          </ChooseSelect>
        </el-form-item>
        <el-form-item label="通知内容" prop="content">
          <el-input v-model="form.content" :rows="2" type="textarea" />
        </el-form-item>
        <el-form-item margin-top="20px">
          <el-button>取消</el-button>
          <el-button type="primary" @click="handleSubmit">提交</el-button>
        </el-form-item>
      </el-form>
    </el-drawer>

    <!-- 查看公告的抽屉内容 -->
    <el-drawer
      v-model="dialogVisible"
      title="查看通知"
      ref="checkNoticeFormRef"
      :handle-submit="submitDialogVisible"
    >
      <template #default>
        <el-form :model="checkform" :rules="rules" ref="formRef">
          <el-form-item label="消息主题">
            <el-input v-model="checkform.title" disabled> </el-input>
          </el-form-item>
          <el-form-item label="消息内容">
            <el-input v-model="checkform.content" type="textarea" disabled>
            </el-input>
          </el-form-item>
        </el-form>
      </template>
      <template #footer>
        <div class="dialog-footer">
          <el-button type="primary" @click="checkSubmit">确定</el-button>
        </div>
      </template>
    </el-drawer>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import { getDepartmentList } from '../../../apis/publicInterface'
import { useNoticeStore } from '@/stores/person-homepage/notice.js'
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'
// 表格数据引入
const noticeStore = useNoticeStore()
// 放入值的逻辑
const baseDataListRef = ref(null)
const noticeFormRef = ref(null)
const inputValue = ref('')
const storeId = ref('')
const formRef = ref(null)
// const checkNoticeFormRef = ref({
//   noticeTitle: '',
//   noticeContent: ''
// })
const checkform = ref({
  title: '',
  content: ''
})
// 表格标题栏
const tableColumnAttribute = [
  {
    prop: 'title',
    label: '标题'
  },
  {
    prop: 'content',
    label: '发布内容'
  },
  {
    prop: 'createTime',
    label: '发布时间'
  },
  {
    prop: 'createUserId',
    label: '发布人'
  },
  {
    prop: 'status',
    label: '状态',
    useTag: true,
    sortable: true
  },
  {
    prop: 'ownerUserId',
    label: '接收人'
  }
]
const rowId = ref('')
const rowStatus = ref('')
// 操作栏下拉菜单选项
const dropdownMenuActionsInfo = [
  {
    command: 'check',
    // row为当前行的数据
    handleAction: (row) => {
      dialogVisible.value = true
      const { title, content } = row
      rowId.value = row.id
      rowStatus.value = row.status.value
      // storeId不能动，否则没有回调函数
      storeId.value = row.id
      checkform.value = {
        title,
        content
      }
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
        .then(async () => {
          await deleteTableData({ ids: [row.id] }).then((res) => {
            ElMessage({
              type: 'success',
              message: res.message
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
            message: '操作已取消'
          })
        })
    },
    actionName: '删除'
  }
]

const checkSubmit = async () => {
  if (rowStatus.value === '未读') {
    console.log(1111)
    await changeState()
  }

  dialogVisible.value = false
}

// 获取表格公告列表逻辑
const getTableData = async (params) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await noticeStore.getStoreList(params)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}

// 删除公告逻辑
const deleteTableData = async (params) => {
  return await noticeStore.removeNoticeItem(params)
}
// 添加新公告(post修改公告以添加新公告)逻辑
const addTableData = async (params) => {
  return await noticeStore.addNoticeItem(params)
}
// 标记已读公告(可批量标记)逻辑
const checkTableData = async (params) => {
  return await noticeStore.updateNoticeItem(params)
}
// 更新系统公告列表逻辑
const updateTableData = async (pageSize, pageIndex) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await isUseInputValueGetTableData(pageSize, pageIndex)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}

// 是否使用搜索关键字获取列表数据逻辑
const isUseInputValueGetTableData = async (pageSize, pageIndex) => {
  if (inputValue.value) {
    // 输入框有值
    await noticeStore.getStoreList({
      pageIndex,
      pageSize,
      title: inputValue.value
    })
  } else {
    await noticeStore.getStoreList({
      pageIndex,
      pageSize
    })
  }
}

// 公告状态跳转（已读/未读）
const changeState = async () => {
  baseDataListRef.value.openSwitchLoading =
    !baseDataListRef.value.openSwitchLoading
  await checkTableData({ ids: [rowId.value] }).then((res) => {
    console.log('1111', res)
    ElMessage({
      message: res.message,
      type: 'success'
    })
  })
  // await isUseInputValueGetTableData(

  // )
  await getTableData({
    pageSize: baseDataListRef.value.paginationData.pageSize,
    pageIndex: baseDataListRef.value.paginationData.currentPage
  })
  baseDataListRef.value.openSwitchLoading =
    !baseDataListRef.value.openSwitchLoading
}

const handleSearch = async () => {
  if (inputValue.value) {
    // 执行搜索后初始化分页数据
    baseDataListRef.value.paginationData.pageSize = 5
    baseDataListRef.value.paginationData.currentPage = 1
    const params = {
      pageSize: 5,
      pageIndex: 1,
      title: inputValue.value
    }
    await getTableData(params)
  } else {
    ElMessage.error('输入不能为空')
  }
}

// 批量删除的逻辑
const deleteBatches = async () => {
  if (!baseDataListRef.value.rows.length) {
    ElMessage.error('请先选择要删除的数据')
  } else {
    const ids = baseDataListRef.value.rows.map((row) => {
      return row.id
    })
    await deleteTableData({ ids }).then(() => {
      ElMessage({
        message: '删除成功',
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
// 批量已读的逻辑
const readBatches = async () => {
  if (!baseDataListRef.value.rows.length) {
    ElMessage.error('请先选择数据')
  } else {
    const ids = baseDataListRef.value.rows.map((row) => {
      if (row.status.value === '未读') {
        return row.id
      }
    })
    await checkTableData({ids}).then(res=>{
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

// 公告已读表单的确认逻辑
const submitDialogVisible = async () => {
  const id = baseDataListRef.value.rows.map((row) => {
    return (row.status = {
      value: row.status ? '已读' : '未读',
      tagType: row.status ? 'info' : 'danger'
    })
  })
  await updateTableData({ id }).then((res) => {
    ElMessage({
      message: res.message,
      type: 'success'
    })
  })
}

// 添加公告抽屜表单
const addDrawer = ref(false)
// 添加公告逻辑
const addEvent = () => {
  addDrawer.value = true
}

// 存放添加表单的数据
const form = ref({
  title: '',
  ownerDeptId: '',
  ownerUserId: '',
  content: ''
})
// 添加公告中的部门下拉选项
const options = ref([
  {
    value: 'Option1',
    label: '零起飞工作室'
  },
  {
    value: 'Option2',
    label: '商务部'
  },
  {
    value: 'Option3',
    label: '技术部'
  }
])
// 添加公告提交表单校验规则
const rules = {
  title: [
    {
      required: true,
      message: '请输入标题',
      trigger: 'blur'
    }
  ],
  ownerDeptId: [
    {
      required: true,
      message: '通知需要下发的团队员及成员，默认当前用户及下级成员',
      trigger: 'blur'
    }
  ],
  ownerUserId: [
    {
      required: true,
      message: '请指定接收对象',
      trigger: 'blur'
    }
  ],
  content: [
    {
      message: '请输入内容',
      trigger: 'blur'
    }
  ]
}

//添加公告表单提交逻辑
const handleSubmit = async () => {
  noticeFormRef.value.validate(async (valid) => {
    if (valid) {
      const params = {
        content: form.value.content,
        title: form.value.title,
        ownerDeptId: form.value.ownerDeptId.value,
        ownerUserId: form.value.ownerUserId.value
      }
      await addTableData(params).then((res) => {
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
      addDrawer.value = false
    }
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

// 分页逻辑
onMounted(async () => {
  // await getTableData({
  //   pageSize: 5,
  //   currentPage: 1
  // })
  // noticeStore
  //   .addNoticeItem({
  //     title: '今晚开会',
  //     ownerDeptId: 1,
  //     ownerUserId: 1,
  //     content: ''
  //   })
  //   .then((res) => {
  //     console.log('res', res)
  //   })
  const params = {
    pageIndex: 1,
    pageSize: 5
  }
  await noticeStore.getStoreList(params)
  await noticeStore.getOptionsUserName()

  await getDepartmentList(
    {
      deptName: ''
    },
    (res) => {
      const { data } = res
      console.log('获取部门名称列表数据', data)
      const newData = data.map((item) => {
        const obj = { value: '', label: '' }
        for (let key in item) {
          if (key === 'id') {
            obj.value = item[key]
          }
          if (key === 'name') {
            obj.label = item[key]
          }
        }
        return obj
      })
      // console.log(newData)
      // 把下拉数据存到notice仓库
      noticeStore.setOptionsDepartmentName(newData)
    }
  )
})
</script>

<style lang="scss" scoped>
.notice {
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

.dialog-footer {
  display: flex;
  justify-content: space-around;
}
</style>
