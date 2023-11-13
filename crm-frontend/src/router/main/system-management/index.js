const routes = [
  {
    path: '/system',
    redirect: '/system/notice',
    children: [
      {
        // 系统参数
        path: '/system/parameter',
        name: 'parameter',
        component: () =>
          import('@/views/systemManagement/parameter/Parameter.vue')
      },
      {
        // 菜单管理
        path: '/system/menu',
        name: 'menu',
        component: () => import('@/views/systemManagement/menu/Menu.vue')
      },
      {
        // 权限管理
        path: '/system/power',
        name: 'power',
        component: () => import('@/views/systemManagement/power/Power.vue')
      },
      {
        // 字段扩展
        path: '/system/field',
        name: 'field',
        component: () => import('@/views/systemManagement/field/Field.vue')
      }
    ]
  }
]

export default routes
