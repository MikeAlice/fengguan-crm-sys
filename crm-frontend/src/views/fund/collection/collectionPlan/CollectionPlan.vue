<template>
  <div class="container">
    <div class="app-container">
      <BaseDataList
        :tableData="$store.sendData.tableData"
        :tableColumnAttribute="$store.sendData.tableColumnAttribute"
        :useHeader="$store.sendData.useHeader"
        :useDropdownMenu="$store.sendData.useDropdownMenu"
        :dropdownMenuActionsInfo="dropdownMenuActionsInfo"
        :usePagination="$store.sendData.usePagination"
        :page-sizes="$store.sendData.pageSizes"
        :total="$store.sendData.total"
        @update-table-data="updateTableData"
      >
        <template #menu>
          <div class="space-between">
            <div class="left">
              <el-button @click="handleAdd">
                <el-icon><Plus /></el-icon>
                添加
              </el-button>
              <el-button
                type="danger"
                @click="handleBatchDelete"
                style="margin-right: 10px"
                >批量删除</el-button
              >
              <BulkOPe
                :getOpt="() => [3, 4]"
                :msgSend="handleMsgSend"
                :emailSend="handleEmailSend"
              ></BulkOPe>
            </div>
            <div class="right">
              <div class="search">
                <el-input
                  v-model="searchData"
                  placeholder="搜索(按照计划时间)"
                ></el-input>
                <el-button
                  type="primary"
                  :icon="Search"
                  style="margin-left: 10px; padding-left: 10px"
                  @click="handleSearch"
                >
                  搜索
                </el-button>
              </div>
            </div>
          </div>
        </template></BaseDataList
      >
    </div>
    <el-dialog v-model="showDialog" :before-close="handleClose">
      <template #header>
        <h3>确认回款</h3>
      </template>
      <template #default>
        <div>
          <el-form v-model="confirmData">
            <el-form-item label="客户名称" prop="supplierName">
              <el-select
                v-model="confirmData.supplierName"
                placeholder="请选择客户名称"
                @change="handleClientNameChange"
              >
                <el-option
                  v-for="item in $store.clientNameList"
                  :label="item"
                  :value="item"
                  :key="item"
                ></el-option>
              </el-select>
            </el-form-item>
            <el-form-item label="销售合同" prop="purchaseOrder">
              <el-select
                v-model="confirmData.purchaseOrder"
                placeholder="请选择客户销售合同"
              >
                <el-option
                  v-for="item in $store.saleContractList"
                  :label="item"
                  :value="item"
                  :key="item"
                ></el-option>
              </el-select>
            </el-form-item>
            <el-form-item label="总金额" prop="totalAmount">
              <el-input v-model="totalAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="去零金额">
              <el-input v-model="noZeroAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="已回款金额">
              <el-input v-model="havePayAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="已开发票金额">
              <el-input v-model="invoiceAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="回款日期" prop="planBackDate"></el-form-item>
            <el-form-item label="期次" prop="period">
              <el-input v-model="totalAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="回款金额" prop="planBackAmount">
              <el-input v-model="planBackAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="回款账户">
              <el-select
                v-model="confirmData.payAccount"
                placeholder="请选择客户销售合同"
              >
                <el-option
                  v-for="item in $store.payAccountList"
                  :label="item"
                  :value="item"
                  :key="item"
                ></el-option>
              </el-select>
            </el-form-item>
          </el-form>
        </div>
      </template>
      <template #footer>
        <div class="space-between">
          <el-button @click="handleCancel">取消</el-button>
          <el-button type="primary" @click="saveConfirmData"
            >保存数据</el-button
          >
        </div>
      </template>
    </el-dialog>
    <el-drawer
      v-model="showAddDrawer"
      :before-close="handleClose"
      direction="rtl"
      :destroy-on-close="true"
    >
      <template #header>
        <h3>添加回款计划</h3>
      </template>
      <template #default>
        <div>
          <el-form v-model="addData">
            <el-form-item label="客户名称" prop="supplierName">
              <el-select
                v-model="confirmData.supplierName"
                placeholder="请选择客户名称"
                @change="handleClientNameChange"
              >
                <el-option
                  v-for="item in $store.clientNameList"
                  :label="item"
                  :value="item"
                  :key="item"
                ></el-option>
              </el-select>
            </el-form-item>
            <el-form-item label="销售合同" prop="purchaseOrder">
              <el-select
                v-model="confirmData.purchaseOrder"
                placeholder="请选择客户销售合同"
              >
                <el-option
                  v-for="item in $store.saleContractList"
                  :label="item"
                  :value="item"
                  :key="item"
                ></el-option>
              </el-select>
            </el-form-item>
            <el-form-item label="总金额" prop="totalAmount">
              <el-input v-model="totalAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="去零金额">
              <el-input v-model="noZeroAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="已回款金额">
              <el-input v-model="havePayAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="已开发票金额">
              <el-input v-model="invoiceAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="回款日期" prop="planBackDate"></el-form-item>
            <el-form-item label="期次" prop="period">
              <el-input v-model="totalAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="回款金额" prop="planBackAmount">
              <el-input v-model="planBackAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="回款账户">
              <el-select
                v-model="confirmData.payAccount"
                placeholder="请选择客户销售合同"
              >
                <el-option
                  v-for="item in $store.payAccountList"
                  :label="item"
                  :value="item"
                  :key="item"
                ></el-option>
              </el-select>
            </el-form-item>
          </el-form>
        </div>
      </template>
      <template #footer>
        <div class="space-between">
          <el-button @click="handleCancel">取消</el-button>
          <el-button type="primary" @click="saveAddData">保存数据</el-button>
        </div>
      </template>
    </el-drawer>
    <el-drawer
      v-model="showEditDrawer"
      :before-close="handleClose"
      direction="rtl"
      :destroy-on-close="true"
    >
      <template #header>
        <h3>修改回款计划</h3>
      </template>
      <template #default>
        <div>
          <el-form v-model="editData">
            <el-form-item label="客户名称" prop="clientName">
              <el-select
                v-model="editData.clientName"
                placeholder="请选择客户名称"
                @change="handleClientNameChange"
              >
                <el-option
                  v-for="item in $store.clientNameList"
                  :label="item"
                  :value="item"
                  :key="item"
                ></el-option>
              </el-select>
            </el-form-item>
            <el-form-item label="销售合同" prop="purchaseOrder">
              <el-select
                v-model="editData.saleContract"
                placeholder="请选择客户销售合同"
              >
                <el-option
                  v-for="item in $store.saleContractList"
                  :label="item"
                  :value="item"
                  :key="item"
                ></el-option>
              </el-select>
            </el-form-item>
            <el-form-item label="总金额" prop="totalAmount">
              <el-input v-model="totalAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="去零金额">
              <el-input v-model="noZeroAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="已回款金额">
              <el-input v-model="havePayAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="已开发票金额">
              <el-input v-model="invoiceAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="回款日期" prop="planBackDate">
              <el-date-picker
                type="datetime"
                v-model="editData.planBackDate"
              ></el-date-picker>
            </el-form-item>
            <el-form-item label="期次" prop="period">
              <el-input v-model="totalAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="回款金额" prop="planBackAmount">
              <el-input v-model="planBackAmount" disabled></el-input>
            </el-form-item>
            <el-form-item label="回款账户">
              <el-select
                v-model="confirmData.payAccount"
                placeholder="请选择客户销售合同"
              >
                <el-option
                  v-for="item in $store.payAccountList"
                  :label="item"
                  :value="item"
                  :key="item"
                ></el-option>
              </el-select>
            </el-form-item>
          </el-form>
        </div>
      </template>
      <template #footer>
        <div class="space-between">
          <el-button @click="handleCancel">取消</el-button>
          <el-button type="primary" @click="handleEdit">保存数据</el-button>
        </div>
      </template>
    </el-drawer>
  </div>
</template>

<script setup>
import { useCollectionPlan } from '@/stores/fund/collection/collectionPlan.js'
import { onMounted, ref } from 'vue'
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import { Plus, Search } from '@element-plus/icons-vue'
import BulkOPe from '@/components/BulkOpe/BulkOPe.vue'
const $store = useCollectionPlan()

onMounted(() => {
  //页面初始化，加载数据
  $store.getCollectionPlanList({ pageIndex: 1, pageSize: 2 })
})
const updateTableData = (pageSize, pageIndex) => {
  $store.pageParams = [pageIndex, pageSize]
  $store.getCollectionPlanList({ pageIndex, pageSize })
}
const searchData = ref('')
const handleSearch = () => {
  searchData.value === ''
    ? $store.getCollectionPlanList({
        pageIndex: $store.pageParams.pageIndex,
        pageSize: $store.pageParams.pageSize
      })
    : $store.getCollectionPlanList(
        {
          pageIndex: $store.pageParams.pageIndex,
          pageSize: $store.pageParams.pageSize
        },
        { backdate: searchData.value }
      )
}
const handleMsgSend = (title, desc) => {
  console.log(title, desc)
}

const handleEmailSend = (title, desc) => {
  console.log(title, desc)
}

const handleClose = () => {
  console.log('handleClose')
  showAddDrawer.value = false
  showEditDrawer.value = false
  showDialog.value = false
}

const handleBatchDelete = () => {
  console.log('delete')
}
const dropdownMenuActionsInfo = [
  {
    command: '回款',
    // row为当前行的数据
    handleAction: (row) => {
      showDialog.value = true
      console.log('回款', row)
      confirmData.value = row
    },
    actionName: '回款'
  },
  {
    command: '修改',
    // row为当前行的数据
    handleAction: (row) => {
      console.log('修改', row)
      showEditDrawer.value = true
    },
    actionName: '修改'
  },
  {
    command: '删除',
    // row为当前行的数据
    handleAction: (row) => {
      console.log('删除', row)
    },
    actionName: '删除'
  }
]

const handleClientNameChange = (e) => {
  console.log('handleClientNameChange', e)
}

const handleCancel = () => {
  console.log('handleCancel')
  showDialog.value = false
}

//SECTION - add
const showAddDrawer = ref(false)

const addData = ref({
  name: 'string',
  contract: 'string',
  backdate: 'string',
  stages: 'string',
  money: 'string',
  invoicevalue: 'string'
})

const handleAdd = () => {
  showAddDrawer.value = true
  console.log('handleAdd')
}
const saveAddData = () => {
  console.log('add请求', addData.value)
}

//!SECTION
//SECTION - edit
const showEditDrawer = ref(false)

const editData = ref({
  clientName: '',
  saleContract: '',
  totalAmount: 0,
  noZeroAmount: 0,
  backAmount: 0,
  invoiceAmount: 0,
  planBackDate: '',
  period: 0,
  planBackAmount: 0
})
const handleEdit = (row) => {
  console.log('row', row)
  console.log('editData', editData)
  $store.updateCollectionPlan(editData.value)
}
//!SECTION
//SECTION - confirm
const showDialog = ref(false)

const confirmData = ref({
  supplierName: '',
  purchaseOrder: '',
  totalAmount: 0,
  noZeroAmount: 0,
  havePayAmount: 0,
  invoiceAmount: 0,
  planBackDate: '',
  period: 0,
  payAmount: 0,
  payAccount: ''
})

const saveConfirmData = () => {
  //confirm
  showDialog.value = false
  console.log('confirm请求', confirmData.value)
}

//!SECTION
</script>

<style lang="scss" scoped>
.space-between {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 0 10px 20px;
}

.search {
  display: flex;
  align-items: center;
}
</style>
