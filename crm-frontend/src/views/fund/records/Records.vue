<template>
  <el-card>
    <!-- 头部 -->
    <header>
      <h3>
        <slot name="ico"></slot>
        <div style="margin-left: 8px">账户流水记录</div>
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
          placeholder="输入银行账户ID"
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
      :data="records.tableData"
      @selection-change="selectChange"
    >
      <el-table-column type="selection" width="55" />
      <el-table-column label="银行账号" prop="bank_id"></el-table-column>
      <el-table-column label="收入" prop="income" sortable>
        <template #default="{ row }">
          {{ '+' + row.income }}
        </template>
      </el-table-column>
      <el-table-column label="支出" prop="expenditure" sortable>
        <template #default="{ row }">
          {{ '-' + row.expenditure }}
        </template>
      </el-table-column>
      <el-table-column label="余额" prop="surplus" sortable>
        <template #default="{ row }">
          {{ row.surplus }}
        </template>
      </el-table-column>
      <el-table-column label="支出类型" prop="type">
        <template #default="{ row }">
          <el-tag type="success">{{ row.type || '未填写' }}</el-tag>
        </template>
      </el-table-column>
      <el-table-column label="关联单号" prop="connect_id"></el-table-column>
      <el-table-column label="创建人" prop="create_user"></el-table-column>
      <el-table-column label="创建时间" prop="create_time"></el-table-column>
    </el-table>
    <section>
      支出金额合计：¥<span style="color: red">
        {{ records.totalExpenditure }}
      </span>
      收入金额合计：¥<span style="color: red">
        {{ records.totalIncome }}
      </span>
    </section>
    <!-- 分页器 -->
    <el-pagination
      v-model:current-page="currentPage"
      v-model:page-size="pageSize"
      :page-sizes="[5, 10, 20, 50]"
      :total="records.total"
      layout="prev, pager, next, jumper, ->, total, sizes"
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
    />
  </el-card>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import useRecords from '@/stores/fund/records/records.js'
import {
  queryFlowredords,
  exportFlowrecords
} from '@/apis/fund/recoreds/index.js'
import { ElMessage } from 'element-plus'

const records = useRecords()

// 初始化数据
const initRecords = (currentPage, pageSize, bankId) => {
  queryFlowredords(currentPage, pageSize, bankId)
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
    data.push(item.bank_id)
  })
  exportFlowrecords(
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
