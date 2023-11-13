const routes = [
  {
    path: '/organization',
    redirect: '/organization/department',
    children: [
      {
        // 部门管理
        path: '/organization/department',
        name: 'department',
        component: () =>
          import('@/views/organization-structure/department/Department.vue')
      },
      {
        // 岗位管理
        path: '/organization/post',
        name: 'post',
        component: () => import('@/views/organization-structure/post/Post.vue')
      },
      {
        // 角色管理
        path: '/organization/role',
        name: 'role',
        component: () => import('@/views/organization-structure/role/Role.vue')
      },
      {
        // 用户管理
        path: '/organization/user',
        name: 'user',
        component: () => import('@/views/organization-structure/user/User.vue')
      }
    ]
  }
]

export default routes
