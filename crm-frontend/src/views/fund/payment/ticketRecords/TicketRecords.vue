<!--
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-27 14:52:16
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-11-03 16:44:35
 * @FilePath: \zero-one-crmsys\crm-frontend\src\views\fund\payment\ticketRecords\TicketRecords.vue
 * @Description: 
 * 
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved. 
-->
<template>
  <div class="container">
    <div class="app-container">
      <BaseDataList
        :tableData="$store.sendData.tableData"
        :tableColumnAttribute="$store.sendData.tableColumnAttribute"
        :useHeader="$store.sendData.useHeader"
        :usePagination="$store.sendData.usePagination"
        :page-sizes="$store.sendData.pageSizes"
        :total="$store.sendData.total"
        :handle-delete="handleDelete"
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
              <BulkOPe :getOpt="() => [0]" :exportExcel="exportExcel"></BulkOPe>
            </div>
            <div class="right">
              <div class="search">
                <el-input v-model="searchData" placeholder="搜索"></el-input>
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
    <el-drawer
      v-model="showAddDrawer"
      :before-close="handleClose"
      direction="rtl"
    >
      <template #header>
        <h3>添加回款计划</h3>
      </template>
      <template #default>
        <div>
          <el-form v-model="addData">
            <el-form-item label="供应商名称" prop="supplierName">
              <el-select
                v-model="addFormData.supplierName"
                placeholder="请选择供应商名称"
                @change="handleSupplierNameChange"
              >
                <el-option
                  v-for="item in $store.supplierNameList"
                  :label="item"
                  :value="item"
                  :key="item"
                ></el-option>
              </el-select>
            </el-form-item>
            <el-form-item label="销售合同" prop="saleContract">
              <el-select
                v-model="addFormData.saleContract"
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
            <el-form-item label="总金额" prop="zongjine">
              <el-input
                v-model="$store.contractAmountInfo.zongjine"
                disabled
              ></el-input>
            </el-form-item>
            <el-form-item label="去零金额">
              <el-input
                v-model="$store.contractAmountInfo.qulingjine"
                disabled
              ></el-input>
            </el-form-item>
            <el-form-item label="已付金额">
              <el-input
                v-model="$store.contractAmountInfo.yifujine"
                disabled
              ></el-input>
            </el-form-item>
            <el-form-item label="已收发票金额">
              <el-input
                v-model="$store.contractAmountInfo.yishoufapiaojine"
                disabled
              ></el-input>
            </el-form-item>
            <el-form-item label="发票内容">
              <el-input v-model="addFormData.name"></el-input>
            </el-form-item>
            <el-form-item label="发票金额">
              <el-input v-model="addFormData.money"></el-input>
            </el-form-item>
            <el-form-item label="发票编号">
              <el-input v-model="addFormData.contract_id"></el-input>
            </el-form-item>
            <el-form-item label="收票日期">
              <el-date-picker
                v-model="addFormData.datee"
                type="date"
                placeholder="请选择收票日期"
              />
            </el-form-item>
            <el-form-item label="期次">
              <el-input v-model="addFormData.stage"></el-input>
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
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import { Plus, Search } from '@element-plus/icons-vue'
import { useTicketsRecord } from '@/stores/fund/payment/tickets.js'
const $store = useTicketsRecord()
onMounted(() => {
  //页面初始化，加载数据
  $store.getTicketsList({ pageIndex: 1, pageSize: 10 })
})

const handleDelete = (row) => {
  console.log('row', row)
}

const handleBatchDelete = (row) => {
  console.log('批量删除', row)
}

const exportExcel = () => {
  console.log('导出excel')
}

const handleSearch = () => {
  console.log('搜索')
}

const searchData = ref('')

const showAddDrawer = ref(false)

const handleAdd = () => {
  showAddDrawer.value = true
}

const addFormData = ref({
  supplierName: '',
  saleContract: '',
  contract_id: '123',
  //这里的是另一个请求解构之后的数据拿到
  zongjine: '',
  qulingjine: '',
  yifujine: '',
  yishoufapiaojine: '',
  suplier_name: '',
  datee: '2023-01-01',
  stage: 123,
  money: 123
})

const handleSupplierNameChange = (e) => {
  console.log(e)
}

const saveAddData = () => {
  showAddDrawer.value = false
  //发请求 保存
}

const handleCancel = () => {
  showAddDrawer.value = false
  console.log('取消')
}
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
