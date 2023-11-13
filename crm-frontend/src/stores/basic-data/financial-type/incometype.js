import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  addFeeincome,
  modifyFeeincome,
  deleteFeeincome
} from '@/apis/basic-data/financial-type/incometype.js'
import { queryAllFeeincome } from '@/apis/publicInterface'

function traverseArray(arr) {
  for (const item of arr) {
    if (typeof item === 'object') {
      for (const key in item) {
        if (Array.isArray(item[key])) {
          // 如果属性是数组就继续递归
          traverseArray(item[key])
        } else {
          if (key === 'name') {
            // label 为name
            item.label = item[key]
          } else if (key === 'id') {
            // value 为 id
            item.value = item[key]
          }
        }
      }
    }
  }
}
export const useIncomeTypeStore = defineStore('incometype', () => {
  const treeData = ref([])
  const queryAllFeeincomeItem = async () => {
    await queryAllFeeincome(
      (res) => {
        treeData.value = res.data
        traverseArray(treeData.value)
      },
      (err) => {
        console.log('err', err)
      }
    )
  }
  const addFeeincomeItem = async (params) => {
    await addFeeincome(params)
  }
  const modifyFeeincomeItem = async (params) => {
    await modifyFeeincome(params)
  }
  const deleteeeincomeItem = async (params) => {
    await deleteFeeincome(params)
  }
  return {
    treeData,
    queryAllFeeincomeItem,
    addFeeincomeItem,
    modifyFeeincomeItem,
    deleteeeincomeItem
  }
})
