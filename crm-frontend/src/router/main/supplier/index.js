const routes = [
  {
    //供应商管理
    path: '/supplier',
    redirect: '/supplier/list',
    children: [
      {
        // 供应商列表
        path: '/supplier/list',
        name: 'list',
        component: () =>
          import('@/views/supplier/supplierList/SupplierList.vue')
      },
      {
        // 供应商联系人
        path: '/supplier/contact',
        name: 'contact',
        component: () =>
          import('@/views/supplier/supplierContact/SupplierContact.vue')
      }
    ]
  }
]

export default routes
