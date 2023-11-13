const routes = [
  {
    path: '/customer',
    redirect: '/customer/client',
    children: [
      {
        // 我的客户
        path: '/customer/client',
        name: 'client',
        component: () => import('@/views/customer/myClient/MyClient.vue')
      },
      {
        // 下属客户
        path: '/customer/subCustomers',
        name: 'subCustomers',
        component: () =>
          import('@/views/customer/subCustomers/SubCustomers.vue')
      },
      {
        // 公海客户
        path: '/customer/seasClients',
        name: 'seasClients',
        component: () => import('@/views/customer/seasClients/SeasClients.vue')
      },
      {
        // 联系人
        path: '/customer/links',
        name: 'links',
        component: () => import('@/views/customer/links/Links.vue')
      },
      {
        // 服务记录
        path: '/customer/serviceRecord',
        name: 'serviceRecord',
        component: () =>
          import('@/views/customer/serviceRecord/ServiceRecord.vue')
      }
    ]
  }
]

export default routes
