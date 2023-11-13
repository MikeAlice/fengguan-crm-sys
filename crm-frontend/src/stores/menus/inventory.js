const inventory = {
  text: '库存管理',
  href: '/inventory',
  icon: 'IconHouse',
  children: [
    // pipazi
    {
      text: '库存清单',
      href: '/inventory/inventoryList',
      icon: 'IconHouse'
    },
    // qianmeng
    {
      text: '入库单',
      href: '/inventory/storageReceipt',
      icon: 'IconHouse'
    },
    // 冰雾
    {
      text: '入库明细',
      href: '/inventory/StockStorageDetails',
      icon: 'IconHouse'
    },
    // 暮秋
    {
      text: '出库单',
      href: '/inventory/WarehousingDetails',
      icon: 'IconHouse'
    },
    // seven
    {
      text: '出库明细',
      href: '/inventory/outstoragedetails',
      icon: 'IconHouse'
    }
  ]
}

export default inventory
