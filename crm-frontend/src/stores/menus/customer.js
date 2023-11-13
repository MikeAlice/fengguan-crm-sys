const customer = {
  text: '客户管理',
  href: '/customer',
  icon: 'IconAvatar',
  children: [
    {
      text: '我的客户',
      href: '/customer/client',
      icon: 'IconAvatar'
    },
    {
      text: '下属客户',
      href: '/customer/subCustomers',
      icon: 'IconAvatar'
    },
    {
      text: '公海客户',
      href: '/customer/seasClients',
      icon: 'IconAvatar'
    },
    {
      text: '联系人',
      href: '/customer/links',
      icon: 'IconAvatar'
    },
    {
      text: '服务记录',
      href: '/customer/serviceRecord',
      icon: 'IconAvatar'
    }
  ]
}

export default customer
