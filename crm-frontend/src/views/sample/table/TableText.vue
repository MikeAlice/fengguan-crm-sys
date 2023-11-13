<script setup>
import Table from '@/components/table/Table.vue'
// import VueLine from 'v-charts/lib/line.common.js'
// import { onMounted, toRefs } from 'vue'
import PopMessage from '@/components/PopMessage/PopMessage.vue'
import { ref } from 'vue'
const tableData = ref([
  {
    date: '2016-05-03',
    name: 'Tom',
    address: 'No. 189, Grove St, Los Angeles'
  },
  {
    date: '2016-05-02',
    name: 'Tom',
    address: 'No. 189, Grove St, Los Angeles'
  },
  {
    date: '2016-05-04',
    name: 'Tom',
    address: 'No. 189, Grove St, Los Angeles'
  },
  {
    date: '2016-05-01',
    name: 'Tom',
    address: 'No. 189, Grove St, Los Angeles'
  }
])
// 图标数据
// const chartData = ref({
//   columns: ['日期', '销售额'],
//   rows: [
//     { 日期: '1月1日', 销售额: 123 },
//     { 日期: '1月2日', 销售额: 1223 },
//     { 日期: '1月3日', 销售额: 2123 },
//     { 日期: '1月4日', 销售额: 4123 },
//     { 日期: '1月5日', 销售额: 3123 },
//     { 日期: '1月6日', 销售额: 7123 }
//   ]
// })
// const labelArr = ref([])
// onMounted(() => {
//   const arr = tableData.value
//   const obj = arr[0]
//   let theArr = []
//   if (obj) {
//     //表格数据第一个对象有数据
//     for (let key in obj) {
//       theArr.push(key)
//     }
//     labelArr.value = theArr
//   } else {
//     return false
//   }
//   // 处理表格数据拿到的表头属性
//   console.log(theArr)
// })
</script>
<template>
  <!-- <h1>这里是表格测试页面</h1> -->
  <el-card class="box-card">
    <template #header>
      <div class="card-header">
        <span>XX-列表数据</span>
        <el-button class="button" text type="primary">按钮</el-button>
        <span>表头支持自定义，（面包屑）</span>
      </div>
    </template>
    <!-- 这里是表格 -->
    <Table :dataArr="tableData" :isSelect="true">
      <template #default>
        <el-table-column label="操作">
          <template #default>
            <el-button size="small">编辑</el-button>
            <!-- <el-button
              size="small"
              type="danger"
              @click="handleDelete(scope.$index, scope.row)"
              >删除</el-button
            > -->
            <PopMessage
              :megObj="{ btn: '删除', mes: '你确认要删除吗？' }"
              @confirm="console.log('父组件监听到子组件点了确认')"
            ></PopMessage>
          </template>
        </el-table-column>
      </template>
      <template #footer> <p>这里可以合计表格数据</p> </template>
    </Table>
    <!-- <p>这里可以合计表格数据</p> -->
  </el-card>
  <!-- <VueLine :data="chartData"></VueLine> -->
</template>

<style>
.box-card {
  height: 100%;
}
.card-header {
  display: flex;
  justify-content: flex-start;
  align-items: center;
}

.text {
  font-size: 14px;
}
</style>
