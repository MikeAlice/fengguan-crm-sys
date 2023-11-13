/*
 * @Author: BINGWU
 * @Date: 2023-11-08 16:25:02
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-08 18:22:41
 * @FilePath: \crm-frontend\src\stores\basic-data\product\productclassification.js
 * @Describe:
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  addGoodsCategory,
  getGoodsCategory,
  listGoodsCategory,
  listGoodsCategoryNameTree,
  modifyGoodsCategory,
  removeGoodsCategory
} from '@/apis/basic-data/product/productclassification'

function traverseArray(arr) {
  for (const item of arr) {
    if (typeof item === 'object') {
      for (const key in item) {
        if (Array.isArray(item[key])) {
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

export const useProductClassificationStore = defineStore(
  'productclassification',
  () => {
    const treeData = ref([])
    const addGoodsCategoryItem = async (params) => {
      return await addGoodsCategory(params)
    }
    const listGoodsCategoryNameTreeItem = async () => {
      await listGoodsCategoryNameTree().then((res) => {
        treeData.value = res.data
        traverseArray(treeData.value)
      })
    }
    // 获取数据详情
    const getGoodsCategoryItem = async (params) => {
      return await getGoodsCategory(params)
    }
    const removeGoodsCategoryItem = async (params) => {
      return await removeGoodsCategory(params)
    }
    const modifyGoodsCategoryItem = async (params) => {
      return await modifyGoodsCategory(params)
    }
    return {
      treeData,
      listGoodsCategoryNameTreeItem,
      getGoodsCategoryItem,
      addGoodsCategoryItem,
      removeGoodsCategoryItem,
      modifyGoodsCategoryItem
    }
  }
)
