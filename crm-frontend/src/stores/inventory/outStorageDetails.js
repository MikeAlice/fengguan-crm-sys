import { defineStore } from 'pinia'
import { ref } from 'vue'

const useOutStorageDetails = defineStore('outStorageDetails', () => {
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

export default useOutStorageDetails
