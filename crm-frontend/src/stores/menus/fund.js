const fund = {
  text: '资金管理',
  href: '/fund',
  icon: 'IconCollectionTag',
  children: [
    {
      text: '资金注入抽取',
      href: '/fund/injectionExtraction',
      icon: 'IconCollectionTag'
    },
    {
      text: '回款管理',
      href: '/fund/collection',
      icon: 'IconCollectionTag',
      children: [
        {
          text: '回款计划',
          href: '/fund/collection/collectionPlan',
          icon: 'IconCollectionTag'
        },
        {
          text: '回款记录',
          href: '/fund/collection/collectionRecords',
          icon: 'IconCollectionTag'
        },
        {
          text: '开票记录',
          href: '/fund/collection/invoiceRecords',
          icon: 'IconCollectionTag'
        }
      ]
    },
    {
      text: '收入开支',
      href: '/fund/incomeExpense',
      icon: 'IconCollectionTag',
      children: [
        {
          text: '其他收入单',
          href: '/fund/incomeExpense/income',
          icon: 'IconCollectionTag'
        },
        {
          text: '费用支出单',
          href: '/fund/incomeExpense/expense',
          icon: 'IconCollectionTag'
        }
      ]
    },
    {
      text: '账户流水记录',
      href: '/fund/records',
      icon: 'IconCollectionTag'
    },
    {
      text: '付款管理',
      href: '/fund/payment',
      icon: 'IconCollectionTag',
      children: [
        {
          text: '付款计划',
          href: '/fund/payment/plan',
          icon: 'IconCollectionTag'
        },
        {
          text: '付款记录',
          href: '/fund/payment/paymentRecords',
          icon: 'IconCollectionTag'
        },
        {
          text: '收票记录',
          href: '/fund/payment/ticketRecords',
          icon: 'IconCollectionTag'
        }
      ]
    }
  ]
}

export default fund
