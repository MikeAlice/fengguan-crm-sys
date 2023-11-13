import { defineStore } from 'pinia'
import { ref } from 'vue'

const useInventoryList = defineStore('inventoryList', () => {
  const tableData = ref([])
  const totalTable = ref(0)
  const setTableData = (data = []) => {
    tableData.value = data
  }
  return {
    tableData,
    totalTable,
    setTableData
  }
})

export default useInventoryList
