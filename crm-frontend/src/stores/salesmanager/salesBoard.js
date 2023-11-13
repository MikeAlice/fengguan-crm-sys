import { defineStore } from 'pinia'
import { ref } from 'vue'

import { getSalesBoardAPI } from '../../apis/sales-manager/salesboard.js'

export const useSalesBoardStore = defineStore('salesboard', () => {
  const tableData = ref([])
  // 获取表格数据的方法
  const getData = async (params) => {
    await getSalesBoardAPI(params)
      .then((res) => {
        console.log('获取表格数据的方法', res)
        // 这里是为了拿到res里的rows
        const rows = res.data
        console.log('rows数据', rows)
        tableData.value = rows
      })
      .catch((err) => {
        console.log(err)
      })
  }
  return {
    getData,
    tableData
  }
})
