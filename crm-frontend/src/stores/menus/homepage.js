const homepage = {
  id: 5,
  text: '个人首页',
  href: '/homepage',
  icon: 'IconUser',
  children: [
    {
      id: 2,
      text: '公告通知',
      href: '/homepage/notice',
      icon: 'IconUser',
      pid: 5
    },
    {
      id: 3,
      text: '消息通知',
      href: '/homepage/message',
      icon: 'IconUser',
      pid: 5
    },
    {
      id: 4,
      text: '修改密码',
      href: '/homepage/password',
      icon: 'IconUser',
      pid: 5
    },
    {
      id: 5,
      text: '编辑资料',
      href: '/homepage/information',
      icon: 'IconUser',
      pid: 5
    }
  ]
}

export default homepage
