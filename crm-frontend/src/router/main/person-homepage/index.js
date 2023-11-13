const routes = [
  {
    path: '/homepage',
    redirect: '/homepage/notice',
    children: [
      {
        // 公告通知
        path: '/homepage/notice',
        name: 'notice',
        component: () => import('@/views/person-homepage/notice/Notice.vue')
      },
      {
        // 消息通知
        path: '/homepage/message',
        name: 'message',
        component: () => import('@/views/person-homepage/message/Message.vue')
      },
      {
        // 修改密码
        path: '/homepage/password',
        name: 'password',
        component: () => import('@/views/person-homepage/password/Password.vue')
      },
      {
        // 编辑资料
        path: '/homepage/information',
        name: 'information',
        component: () =>
          import('@/views/person-homepage/information/Information.vue')
      }
    ]
  }
]

export default routes
