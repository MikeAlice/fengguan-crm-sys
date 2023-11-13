import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  queryBankaccount,
  modifyBankaccount,
  deleteBankaccount,
  addBankaccount
} from '@/apis/basic-data/financial-type/bankaccount.js'
export const useBankAccountStore = defineStore('bankaccount', () => {
  const tableData = ref([])
  const total = ref(0)
  const queryBankaccountItem = async (params) => {
    await queryBankaccount(params).then((res) => {
      tableData.value = res.data.rows
      total.value = res.data.total
    })
  }
  const modifyBankaccountItem = async (params) => {
    return await modifyBankaccount(params)
  }
  const deleteBankaccountItem = async (params) => {
    return await deleteBankaccount(params)
  }
  const addBankaccountItem = async (params) => {
    return await addBankaccount(params)
  }
  return {
    tableData,
    total,
    queryBankaccountItem,
    modifyBankaccountItem,
    deleteBankaccountItem,
    addBankaccountItem
  }
})
