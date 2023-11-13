import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  queryBrand,
  addBrand,
  modifyBrand,
  removeBrand
} from '@/apis/basic-data/product/productbrand'
export const useProductBrandStore = defineStore('productbrand', () => {
  const tableData = ref([])
  const total = ref(0)
  const queryBrandItem = async (params) => {
    await queryBrand(params).then((res) => {
      console.log('res', res)
    })
  }
  return {
    tableData,
    total,
    queryBrandItem
  }
})

