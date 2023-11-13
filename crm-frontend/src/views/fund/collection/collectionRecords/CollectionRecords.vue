<template>
  <div class="container">
    <div class="app-container">
      <BaseDataList
        :table-column-attribute="$store.sendData.tableColumnAttribute"
        :table-data="$store.sendData.tableData"
        :handle-delete="handleDelete"
        :use-pagination="$store.sendData.usePagination"
        :page-sizes="$store.sendData.pageSizes"
        :total="$store.sendData.total"
        :use-header="$store.sendData.useHeader"
        @update-table-data="get"
        ref="baseDataListRef"
      >
        <template #menu>
          <div class="space-between">
            <div class="left">
              <el-button @click="handleAdd">
                <el-icon><Plus /></el-icon>
                添加
              </el-button>
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
        </template>

        <template #empty>
          <el-empty class="emptyTable" description="没有数据"></el-empty>
        </template>
      </BaseDataList>
    </div>
    <el-drawer
      v-model="showAddDrawer"
      direction="rtl"
      :before-close="handleClose"
    >
      <template #header>
        <h3>添加回款记录</h3>
      </template>
      <template #default>
        <div>
          <el-form
            v-model="addFormData"
            ref="addDrawerRef"
            :model="addFormData"
          >
            <el-form-item label="客户名称" prop="customer_name">
              <el-select
                v-model="addFormData.customer_name"
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
                v-model="addFormData.purchaseOrder"
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
            <el-form-item label="金额" prop="money">
              <el-input v-model="money" disabled></el-input>
            </el-form-item>
            <el-form-item label="回款日期" prop="back_date"></el-form-item>
            <el-form-item label="期次" prop="stages">
              <el-input v-model="stages" disabled></el-input>
            </el-form-item>
            <el-form-item label="回款账户">
              <el-select
                v-model="addFormData.payAccount"
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
  </div>
</template>

<script setup>
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import { useCollectionRecord } from '@/stores/fund/collection/collectionRecord.js'
import { Search, Plus } from '@element-plus/icons-vue'
import { onMounted, ref } from 'vue'
const $store = useCollectionRecord()

onMounted(() => {
  $store.getCollectionRecordList({ pageIndex: 1, pageSize: 10 })
})
const addFormData = ref({
  record_id: 0,
  customer_name: 'string',
  contract_id: 0,
  back_date: 'string',
  stages: 0,
  bank_id: 0,
  money: 0,
  create_user_id: 'string',
  create_time: 0,
  purchaseOrder: '',
  payAccount: ''
})

const searchData = ref('')

const showAddDrawer = ref(false)

const addDrawerRef = ref()
const handleAdd = () => {
  showAddDrawer.value = true
}

const handleDelete = (row) => {
  console.log('删除', row)
}

const handleSearch = () => {
  console.log('搜索', searchData.value)
}

const saveAddData = () => {
  console.log('带着data', addFormData, '发add请求')
  showAddDrawer.value = false
  ElMessage.success('添加成功')
  console.log('addDrawerRef', addDrawerRef.value)
  addDrawerRef.value.resetFields()
}

const handleClose = (done) => {
  console.log('关闭前的confirm')
  done()
}

const handleCancel = () => {
  showAddDrawer.value = false
  console.log('取消')
}
const get = (pageSize, currentPage) => {
  console.log('调用父组件的更新数据的函数')
  console.log('pageSize', pageSize)
  console.log('currentPage', currentPage)
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

.tree-card {
  min-width: 200px;
  min-height: 500px;
  width: 300px;
  height: 600px;
  margin-right: 50px;
}
</style>
