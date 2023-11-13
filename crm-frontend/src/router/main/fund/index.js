const routes = [
  {
    // 资金管理
    path: '/fund',
    redirect: '/fund/injectionExtraction',
    children: [
      {
        // 资金注入抽取
        path: '/fund/injectionExtraction',
        name: 'injectionExtraction',
        component: () =>
          import('@/views/fund/injectionExtraction/InjectionExtraction.vue')
      },
      {
        // 回款管理
        path: '/fund/collection',
        name: 'collection',
        redirect: '/fund/collection/collectionPlan',
        children: [
          {
            // 回款计划
            path: '/fund/collection/collectionPlan',
            name: 'collectionPlan',
            component: () =>
              import(
                '@/views/fund/collection/collectionPlan/CollectionPlan.vue'
              )
          },
          {
            // 回款记录
            path: '/fund/collection/collectionRecords',
            name: 'collectionRecords',
            component: () =>
              import(
                '@/views/fund/collection/collectionRecords/CollectionRecords.vue'
              )
          },
          {
            // 开票记录
            path: '/fund/collection/invoiceRecords',
            name: 'invoiceRecords',
            component: () =>
              import(
                '@/views/fund/collection/invoiceRecords/InvoiceRecords.vue'
              )
          }
        ]
      },
      {
        // 收入开支
        path: '/fund/incomeExpense',
        name: 'incomeExpense',
        redirect: '/fund/incomeExpense/income',
        children: [
          {
            // 其他收入单
            path: '/fund/incomeExpense/income',
            name: 'income',
            component: () =>
              import('@/views/fund/incomeExpense/income/Income.vue')
          },
          {
            // 费用支出单
            path: '/fund/incomeExpense/expense',
            name: 'expense',
            component: () =>
              import('@/views/fund/incomeExpense/expense/Expense.vue')
          }
        ]
      },
      {
        // 账户流水记录
        path: '/fund/records',
        name: 'records',
        component: () => import('@/views/fund/records/Records.vue')
      },
      {
        // 付款管理
        path: '/fund/payment',
        name: 'payment',
        redirect: '/fund/incomeExpense/income',
        children: [
          {
            // 付款计划
            path: '/fund/payment/plan',
            name: 'plan',
            component: () => import('@/views/fund/payment/plan/Plan.vue')
          },
          {
            // 付款记录
            path: '/fund/payment/paymentRecords',
            name: 'paymentRecords',
            component: () =>
              import('@/views/fund/payment/paymentRecords/PaymentRecords.vue')
          },
          {
            // 收票记录
            path: '/fund/payment/ticketRecords',
            name: 'ticketRecords',
            component: () =>
              import('@/views/fund/payment/ticketRecords/TicketRecords.vue')
          }
        ]
      }
    ]
  }
]

export default routes
