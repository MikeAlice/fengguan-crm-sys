const routes = [
  {
    path: '/inventory',
    redirect: '/inventory/inventoryList',
    children: [
      {
        // 入库明细
        path: '/inventory/StockStorageDetails',
        name: 'ru_ku_ming_xi',
        component: () =>
          import(
            '@/views/inventoryManagement/StockStorageDetails/StockStorageDetails.vue'
          )
      },
      {
        // 出库明细
        path: '/inventory/outstoragedetails',
        name: 'outstoragedetails',
        component: () =>
          import(
            '@/views/inventoryManagement/outstoragedetails/OutStorageDetails.vue'
          )
      },
      {
        // 库存清单
        path: '/inventory/inventoryList',
        name: 'inventoryList',
        component: () =>
          import('@/views/inventoryManagement/InventoryList/InventoryList.vue')
      },
      {
        // 入库单
        path: '/inventory/storageReceipt',
        name: 'storageReceipt',
        component: () =>
          import(
            '@/views/inventoryManagement/StorageReceipt/storageReceipt.vue'
          )
      },
      {
        // 出库单
        path: '/inventory/WarehousingDetails',
        name: 'WarehousingDetails',
        component: () =>
          import(
            '@/views/inventoryManagement/StorageDetails/StorageDetails.vue'
          )
      }
    ]
  }
]

export default routes
