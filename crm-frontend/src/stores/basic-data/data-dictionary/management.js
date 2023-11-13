/*
 * @Author: BINGWU
 * @Date: 2023-11-01 14:46:01
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-06 23:23:03
 * @FilePath: \crm-frontend\src\stores\basic-data\data-dictionary\management.js
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */

import { defineStore } from 'pinia'
import { ref } from 'vue'
import { getDictclassifylist } from '@/apis/publicInterface.js'
import {
  getDict,
  deleteDict,
  modifyDict,
  addDict
} from '@/apis/basic-data/data-dictionary/management'
export const useManagementStore = defineStore('management', () => {
  const options = ref([])
  const tableData = ref([])
  const total = ref(0)
  // 获取字典下拉列表分类
  const getOptions = async (params) => {
    console.log('getOptions', params)
    await getDictclassifylist(
      params,
      (response) => {
        options.value = response.data.map((item) => {
          return {
            value: item.id,
            label: item.typeName,
            typetag: item.typetag
          }
        })
      },
      (error) => {
        console.log('error', error)
      }
    )
  }

  const queryDictList = async (params) => {
    await getDict(params)
      .then((response) => {
        total.value = response.data.total
        tableData.value = response.data.rows.map((row) => {
          row.visible = row.visible ? true : false
          return row
        })
      })
      .catch((error) => {
        console.log('error: ', error)
      })
  }
  const deleteDictList = async (params) => {
    console.log('deleteDictList', params)
    return await deleteDict(params)
  }
  const modifyDictList = async (params) => {
    console.log('modifyDictList', params)
    return await modifyDict(params)
  }
  const addDictList = async (params) => {
    return await addDict(params)
  }
  return {
    options,
    tableData,
    total,
    getOptions,
    queryDictList,
    deleteDictList,
    modifyDictList,
    addDictList
  }
})
