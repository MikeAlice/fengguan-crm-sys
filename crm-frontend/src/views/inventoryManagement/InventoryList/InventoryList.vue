<template>
  <el-card>
    <!-- 头部 -->
    <header>
      <h3>
        <slot name="ico"></slot>
        <div style="margin-left: 8px">库存清单</div>
      </h3>
    </header>
    <!-- 操作搜索栏 -->
    <section class="menu">
      <div class="left">
        <el-button
          type="primary"
          style="margin-right: 10px"
          :disabled="selectIdArr.length ? false : true"
          @click="exportExcel"
          >批量导出</el-button
        >
      </div>
      <div class="right" style="display: flex">
        <el-input
          v-model="content"
          placeholder="输入商品名称"
          style="margin-right: 4px; width: 200px"
        />
        <el-button
          type="primary"
          style="margin-left: 4px"
          @click="searchDetails"
          :disabled="content ? false : true"
          icon="IconSearch"
        >
          搜索
        </el-button>
      </div>
    </section>
    <!-- 表格部分 -->
    <el-table
      style="width: 100%; margin-bottom: 20px"
      table-layout="auto"
      :data="inventoryList.tableData"
      @selection-change="selectChange"
    >
      <el-table-column type="selection" width="55" />
      <el-table-column label="商品ID" prop="goods_id"></el-table-column>
      <el-table-column label="SKUID" prop="sku_id"></el-table-column>
      <el-table-column
        label="商品名称"
        prop="goods_name"
        sortable
      ></el-table-column>
      <el-table-column label="SKU名称" prop="sku_name"></el-table-column>
      <el-table-column
        label="库存数量"
        prop="number"
        sortable
      ></el-table-column>
      <el-table-column label="商品类型" prop="category_name"></el-table-column>
      <el-table-column
        label="仓库名称"
        prop="store_name"
        sortable
      ></el-table-column>
      <el-table-column
        label="销售价格"
        prop="sale_price"
        sortable
      ></el-table-column>
      <el-table-column
        label="成本价格"
        prop="cost_amount"
        sortable
      ></el-table-column>
      <el-table-column label="预计利润" prop="anticipated_profit" sortable>
      </el-table-column>
      <el-table-column label="原厂编码" prop="Original_code"></el-table-column>
      <el-table-column
        label="供应商名称"
        prop="supplier_name"
      ></el-table-column>
    </el-table>
    <!-- 分页器 -->
    <el-pagination
      v-model:current-page="currentPage"
      v-model:page-size="pageSize"
      :page-sizes="[5, 10, 20, 50]"
      :total="inventoryList.totalTable"
      layout="prev, pager, next, jumper, ->, total, sizes"
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
    />
  </el-card>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import useInventoryList from '@/stores/inventory/inventoryList.js'
import {
  queryInVentoryList,
  exportInventoryList
} from '@/apis/inventory-manager/index.js'
import { ElMessage } from 'element-plus'

const inventoryList = useInventoryList()

// 初始化数据
const initRecords = (currentPage, pageSize, goods_name) => {
  queryInVentoryList(
    currentPage,
    pageSize,
    goods_name,
    (response) => {
      inventoryList.setTableData(response.data.rows)
      inventoryList.totalTable = response.data.total
    },
    (error) => {
      ElMessage.error(error)
    }
  )
}
onMounted(() => {
  initRecords(currentPage.value, pageSize.value)
})
// 当前页数
const currentPage = ref(1)
// 每页数据
const pageSize = ref(5)
const handleSizeChange = (val) => {
  pageSize.value = val
  initRecords(currentPage.value, pageSize.value)
}
const handleCurrentChange = (val) => {
  currentPage.value = val
  initRecords(currentPage.value, pageSize.value)
}

/**
 * 批量导出
 */
// 存储批量导出的客户的id
let selectIdArr = ref([])
// table复选框勾选时触发的事件
const selectChange = (value) => {
  selectIdArr.value = value
}
// 导出文件按钮回调
const exportExcel = () => {
  let data = []
  selectIdArr.value.forEach((item) => {
    data.push(item.goods_id)
  })
  exportInventoryList(
    data,
    () => {
      ElMessage.success('导出成功')
    },
    () => {
      ElMessage.error('导出失败')
    }
  )
}

/**
 * 搜索
 */
let content = ref('')
const searchDetails = () => {
  initRecords(
    currentPage.value,
    pageSize.value,
    content.value,
    () => {
      ElMessage.success('查询成功')
    },
    () => {
      ElMessage.error('查询失败')
    }
  )
  content.value = ''
}
</script>

<style lang="scss" scoped>
header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 20px;
}
.menu {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 10px;
}
.dialog-footer {
  display: flex;
  justify-content: space-around;
}
</style>
