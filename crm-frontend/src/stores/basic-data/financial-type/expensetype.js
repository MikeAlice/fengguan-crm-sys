import { defineStore } from 'pinia'
import { ref } from 'vue'
import {} from '@/apis/basic-data/financial-type/bankaccount.js'
export const useExpenseTypeStore = defineStore('expensetype', () => {
  const tableData = ref([])
  const total = ref(0)

  return {
    tableData,
    total
  }
})
