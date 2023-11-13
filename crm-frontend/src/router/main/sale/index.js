/*
 * @Author: seven 1473008948@qq.com
 * @Date: 2023-10-26 21:58:11
 * @LastEditors: seven 1473008948@qq.com
 * @LastEditTime: 2023-10-28 14:27:04
 * @FilePath: \zero-one-crmsys\crm-frontend\src\router\main\sale\index.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
const routes = [
  {
    path: '/sale',
    redirect: '/sale/opportunity',
    children: [
      {
        // 销售机会
        path: '/sale/opportunity',
        name: 'opportunity',
        component: () => import('@/views/sale/opportunity/SaleOpportunity.vue')
      },
      {
        // 跟踪记录
        path: '/sale/trackRecords',
        name: 'trackRecords',
        component: () => import('@/views/sale/trackRecords/TrackRecords.vue')
      },
      {
        // 销售合同
        path: '/sale/saleContract',
        name: 'saleContract',
        component: () => import('@/views/sale/saleContract/SaleContract.vue')
      },
      {
        // 销售简报
        path: '/sale/saleKit',
        name: 'saleKit',
        component: () => import('@/views/sale/saleKit/Salekit.vue')
      }
    ]
  }
]

export default routes
