<template>
  <div class="warehouse">
    <BaseDataList
      title="银行账号管理"
      :table-data="bankAccountStore.tableData"
      :table-column-attribute="tableColumnAttribute"
      :use-dropdown-menu="true"
      :dropdown-menu-actions-info="dropdownMenuActionsInfo"
      :page-sizes="[5, 10, 15]"
      :total="bankAccountStore.total"
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
            <el-input
              v-model="inputValue"
              placeholder="请输入银行名称"
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
    <BankAccountForm
      :title="title"
      ref="bankAccountFormRef"
      :handle-submit="handleSubmit"
    ></BankAccountForm>
  </div>
</template>

<script setup>
import { onMounted, ref } from 'vue'
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import BankAccountForm from './BankAccountForm.vue'
import { useBankAccountStore } from '@/stores/basic-data/financial-type/bankaccount'
const baseDataListRef = ref(null)
const tableColumnAttribute = ref([
  {
    prop: 'name',
    label: '银行名称'
  },
  {
    prop: 'card',
    label: '银行账号'
  },
  {
    prop: 'holders',
    label: '开户人'
  },
  {
    prop: 'address',
    label: '开户地址'
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
const bankAccountFormRef = ref(null)
const title = ref('')
const dropdownMenuActionsInfo = [
  {
    command: 'delete',
    // row为当前行的数据
    handleAction: (row) => {
      ElMessageBox.confirm('确认要删除吗?', 'Warning', {
        confirmButtonText: '确认',
        cancelButtonText: '取消',
        type: 'warning'
      })
        .then(async () => {
          await deleteTableData({ bank_id: row.bank_id })
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
    },
    actionName: '删除'
  },
  {
    command: 'edit',
    handleAction: (row) => {
      title.value = '修改'
      bankAccountFormRef.value.visible = true
      bank_id.value = row.bank_id
      bankAccountFormRef.value.form = { ...row }
    },
    actionName: '修改'
  }
]
const bank_id = ref('')
const bankAccountStore = useBankAccountStore()
const inputValue = ref('')
const getTableData = async (params) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await bankAccountStore.queryBankaccountItem(params)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}

const modifyTableData = async (params) => {
  return await bankAccountStore.modifyBankaccountItem(params)
}

const addressTableData = async (params) => {
  return await bankAccountStore.addBankaccountItem(params)
}

const deleteTableData = async (params) => {
  return await bankAccountStore.deleteBankaccountItem(params)
}

const handleAdd = () => {
  title.value = '添加'
  bankAccountFormRef.value.visible = true
}

const updateTableData = async (pageSize, pageIndex) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await isUseInputValueGetTableData(pageSize, pageIndex)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}

const isUseInputValueGetTableData = async (pageSize, pageIndex) => {
  if (inputValue.value) {
    // 输入框有值
    await bankAccountStore.queryBankaccountItem({
      pageIndex,
      pageSize,
      name: inputValue.value
    })
  } else {
    await bankAccountStore.queryBankaccountItem({
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

const handleSubmit = () => {
  bankAccountFormRef.value.formRef.validate(async (vaild) => {
    if (vaild) {
      const params = {
        ...bankAccountFormRef.value.form
      }
      params.visible = params.visible ? 1 : 0
      if (title.value === '修改') {
        await modifyTableData({
          bank_id: bank_id.value,
          ...params
        }).then(() => {
          ElMessage({
            message: '操作成功',
            type: 'success'
          })
        })
      } else {
        await addressTableData({ ...params }).then(() => {
          ElMessage({
            message: '操作成功',
            type: 'success'
          })
        })
      }
      bankAccountFormRef.value.form = {
        name: '',
        card: 0,
        holders: '',
        address: '',
        visible: true,
        sort: 0
      }
      bankAccountFormRef.value.visible = false
      baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
      await isUseInputValueGetTableData(
        baseDataListRef.value.paginationData.pageSize,
        baseDataListRef.value.paginationData.currentPage
      )
      baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
    }
  })
}

const handleManyDelete = async () => {
  if (!baseDataListRef.value.rows.length) {
    ElMessage.error('请先选择')
  } else {
    // 删除的逻辑
    await baseDataListRef.value.rows.forEach(async (row) => {
      await deleteTableData({ bank_id: row.bank_id })
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

const handleSearch = () => {
  if (inputValue.value) {
    getTableData({
      pageSize: 5,
      pageIndex: 1,
      name: inputValue.value
    })
    baseDataListRef.value.paginationData.pageSize = 5
    baseDataListRef.value.paginationData.currentPage = 1
  } else {
    ElMessage.error('输入不能为空')
  }
}

onMounted(() => {
  getTableData({
    pageSize: 5,
    pageIndex: 1
  })
})
</script>

<style lang="scss" scoped>
.warehouse {
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
