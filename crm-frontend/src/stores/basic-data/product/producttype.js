/*
 * @Author: BINGWU
 * @Date: 2023-11-08 15:14:23
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-08 15:36:20
 * @FilePath: \crm-frontend\src\stores\basic-data\product\producttype.js
 * @Describe:
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  addType,
  deleteType,
  findDetailedType,
  findSimpleType,
  modifyDetailedType
} from '@/apis/basic-data/product/producttype'
export const useProductTypeStore = defineStore('producttype', () => {
  const tableData = ref([])
  const total = ref(0)
  const addTypeItem = async (params) => {
    return await addType(params)
  }
  const findSimpleTypeItem = async (params) => {
    await findSimpleType(params).then((res) => {
      tableData.value = res.data.rows.map((row) => {
        row.detailedTypeInfoDTOList = ''
        row.attrValueName.forEach((item) => {
          row.detailedTypeInfoDTOList += `[${item}] `
        })
        return row
      })
    })
  }
  return {
    tableData,
    total,
    addTypeItem,
    findSimpleTypeItem
  }
})
