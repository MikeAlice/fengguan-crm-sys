<!--
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-21 15:12:41
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-10-21 15:30:27
 * @FilePath: \zero-one-crmsys\crm-frontend\src\views\sample\orgStructure\testTable.vue
 * @Description: 
 * 
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved. 
-->


<template>
  <div style="color: red">测试BaseDataList组件</div>
  <!-- 测试 -->
  <BaseDataList
    :table-column-attribute="sendData.tableColumnAttribute"
    :handle-delete="sendData.handleDelete"
    :handle-edit="sendData.handleEdit"
    :table-data="sendData.tableData"
    :page-sizes="sendData.pageSizes"
    :total="sendData.total"
    @update-table-data="get"
    ref="baseDataListRef"
    >s
    <template #menu>
      <div>
        插槽区
        <el-button @click="getRows">获取被勾选的列</el-button>
        <el-button @click="changeLoadAnimation"
          >off或者open表格加载动画></el-button
        >
      </div>
    </template>
  </BaseDataList>
</template>

<script setup>
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import { ref } from 'vue'

// 测试数据传递

const sendData = {
  tableColumnAttribute: [
    {
      prop: 'sex',
      label: '性别',
      sortable: true
    },
    {
      prop: 'age',
      label: '年龄',
      sortable: true
    },
    {
      prop: 'hoby',
      label: '爱好'
    }
  ],
  tableData: [
    {
      sex: '男',
      age: 19,
      hoby: '唱歌'
    },
    {
      sex: '女',
      age: 21,
      hoby: 'rap'
    },
    {
      sex: '男',
      age: 22,
      hoby: '篮球'
    }
  ],
  // 传入删除操作的函数就会显示删除按钮
  handleDelete: (row) => {
    console.log('删除', row)
  },
  handleEdit: (row) => {
    console.log('编辑', row)
  },
  pageSizes: [2, 10, 15, 200],
  total: 100
}
const baseDataListRef = ref(null)
//分页器组件点击调用get
const get = (pageSize, currentPage) => {
  console.log('调用父组件的更新数据的函数')
  console.log('pageSize', pageSize)
  console.log('currentPage', currentPage)
}
const getRows = () => {
  // 获取组件暴露出来的rows
  console.log('rows', baseDataListRef.value.rows)
}
const changeLoadAnimation = () => {
  // 关闭表格加载动画
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}
</script>

<style lang="scss" scoped></style>
