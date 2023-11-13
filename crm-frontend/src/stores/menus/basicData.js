const basicData = {
  text: '基础数据',
  href: '/basicData',
  icon: 'IconPostCard',
  children: [
    {
      text: '数据字典',
      href: '/basicData/dictionary',
      icon: 'IconPostCard',
      children: [
        {
          text: '字典分类',
          href: '/basicData/dictionary/classification',
          icon: 'IconPostCard'
        },
        {
          text: '字典管理',
          href: '/basicData/dictionary/management',
          icon: 'IconPostCard'
        }
      ]
    },
    {
      text: '地区管理',
      href: '/basicData/regional',
      icon: 'IconPostCard'
    },
    {
      text: '财务类型',
      href: '/basicData/financial',
      icon: 'IconPostCard',
      children: [
        {
          text: '费用收入类型',
          href: '/basicData/financial/incomeType',
          icon: 'IconPostCard'
        },
        {
          text: '费用开支类型',
          href: '/basicData/financial/expenseType',
          icon: 'IconPostCard'
        },
        {
          text: '银行账号管理',
          href: '/basicData/financial/bankAccount',
          icon: 'IconPostCard'
        }
      ]
    },
    {
      text: '仓库管理',
      href: '/basicData/warehouse',
      icon: 'IconPostCard'
    },
    {
      text: '商品管理',
      href: '/basicData/product',
      icon: 'IconPostCard',
      children: [
        {
          text: '商品品牌',
          href: '/basicData/product/brand',
          icon: 'IconPostCard'
        },
        {
          text: '商品类型',
          href: '/basicData/product/type',
          icon: 'IconPostCard'
        },
        {
          text: '商品分类',
          href: '/basicData/product/classification',
          icon: 'IconPostCard'
        },
        {
          text: '商品规格',
          href: '/basicData/product/specification',
          icon: 'IconPostCard'
        },
        {
          text: '商品维护',
          href: '/basicData/product/maintenace',
          icon: 'IconPostCard'
        },
        {
          text: '商品SKU',
          href: '/basicData/product/SKU',
          icon: 'IconPostCard'
        }
      ]
    }
  ]
}

export default basicData
