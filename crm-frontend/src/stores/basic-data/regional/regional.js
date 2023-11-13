/*
 * @Author: BINGWU
 * @Date: 2023-11-04 00:21:11
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-07 16:32:16
 * @FilePath: \crm-frontend\src\stores\basic-data\regional\regional.js
 * @Describe: 
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  queryListArea,
  deleteArea,
  insertArea,
  modifyArea,
  queryTree
} from '@/apis/basic-data/regional/regional'

function traverseArray(arr) {
  for (const item of arr) {
    if (typeof item === 'object') {
      for (const key in item) {
        if (Array.isArray(item[key])) {
          // children 为nodes
          item.children = item[key]
          // 如果属性是数组就继续递归
          traverseArray(item[key])
        } else {
          if (key === 'id') {
            // value 为 id
            item.value = item[key]
          } else if (key === 'name') {
            // label 为name
            item.label = item[key]
          }
        }
      }
    }
  }
}

export const useRegionalStore = defineStore('regional', () => {
  const tableData = ref([])
  const total = ref(0)
  const areaTreeData = ref()
  const getListAreaItem = async (params) => {
    await queryListArea(params)
      .then((response) => {
        tableData.value = response.data.rows
        total.value = response.data.total
      })
      .catch((err) => {
        console.log('err', err)
      })
  }
  const deleteAreaItem = async (params) => {
    return await deleteArea(params)
  }
  const insertAreaItem = async (params) => {
    return await insertArea(params)
  }
  const modifyAreaItem = async (params) => {
    return await modifyArea(params)
  }
  const queryTreeItem = async () => {
    await queryTree()
      .then((response) => {
        areaTreeData.value = response.data
        traverseArray(areaTreeData.value)
      })
      .catch((error) => {
        console.log('err', error)
      })
  }

  return {
    tableData,
    total,
    areaTreeData,
    getListAreaItem,
    deleteAreaItem,
    insertAreaItem,
    modifyAreaItem,
    queryTreeItem
  }
})
