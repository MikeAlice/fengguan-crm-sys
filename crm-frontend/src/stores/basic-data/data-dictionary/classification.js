/*
 * @Date: 2023-10-31 15:54:40
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-03 17:27:11
 * @FilePath: \crm-frontend\src\stores\basic-data\data-dictionary\classification.js
 */
import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  queryDictclassify,
  addDictclassify,
  modifyDictclassify,
  deleteDictclassify
} from '@/apis/basic-data/data-dictionary/classification'
export const useClassificationStore = defineStore('classification', () => {
  const tableData = ref([])
  const total = ref(0)
  const getDictclassify = async (params) => {
    await queryDictclassify(params)
      .then((response) => {
        tableData.value = response.data.rows
        total.value = response.data.total
      })
      .catch((err) => {
        console.log('err', err)
      })
  }
  const addDictclassifyItem = async (params) => {
    return await addDictclassify(params)
  }
  const modifyDictclassifyItem = async (params) => {
    return await modifyDictclassify(params)
  }
  const deleteDictclassifyItem = async (params) => {
    return await deleteDictclassify(params)
  }
  return {
    tableData,
    total,
    getDictclassify,
    addDictclassifyItem,
    modifyDictclassifyItem,
    deleteDictclassifyItem
  }
})
