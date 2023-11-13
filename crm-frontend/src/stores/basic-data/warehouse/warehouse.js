import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  queryStore,
  addStore,
  modifyStoreInfo,
  deleteStore,
  exportStore,
  importStore
} from '@/apis/basic-data/warehouse/warehouse'
export const useWarehouseStore = defineStore('warehouse', () => {
  const tableData = ref([])
  const total = ref(0)
  const getStoreList = async (params) => {
    console.log('getStoreList', params)
    await queryStore(params)
      .then((res) => {
        tableData.value = res.data.rows
        total.value = res.data.total
      })
      .catch((err) => {
        console.log('err', err)
      })
  }
  const addStoreItem = async (params) => {
    return await addStore(params)
  }
  const modifyStoreItem = async (params) => {
    return await modifyStoreInfo(params)
  }
  const deleteStoreItem = async (params) => {
    return await deleteStore(params)
  }
  const exportStoreItem = async (params) => {
    return await exportStore(params)
  }
  const importStoreItem = async (params) => {
    return await importStore(params)
  }
  return {
    tableData,
    total,
    getStoreList,
    addStoreItem,
    modifyStoreItem,
    deleteStoreItem,
    exportStoreItem,
    importStoreItem
  }
})
