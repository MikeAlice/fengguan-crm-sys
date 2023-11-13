import { defineStore } from 'pinia'
import { ref } from 'vue'

const useRecords = defineStore('records', () => {
  const total = ref(0)
  const tableData = ref([])
  // 设置表格数据
  const setTableData = (data = []) => {
    tableData.value = data
  }
  // 收入合计
  const totalIncome = ref(0)
  // 设置收入合计
  const setTotalIncome = (data = 0) => {
    totalIncome.value = data
  }
  // 支出合计
  const totalExpenditure = ref(0)
  // 设置支出合计
  const setTotalExpenditure = (data = 0) => {
    totalExpenditure.value = data
  }
  return {
    total,
    tableData,
    setTableData,
    totalIncome,
    setTotalIncome,
    totalExpenditure,
    setTotalExpenditure
  }
})

export default useRecords
