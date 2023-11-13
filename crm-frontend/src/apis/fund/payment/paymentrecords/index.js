/*
 * @Author: seven 1473008948@qq.com
 * @Date: 2023-11-03 15:42:16
 * @LastEditors: seven 1473008948@qq.com
 * @LastEditTime: 2023-11-03 15:44:01
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\fund\payment\paymentrecords\index.js
 */

import Request from '@/apis/request'

/**
 * @description: 获取付款记录列表  参数字段配置的路径:  crm-frontend\src\stores\salesmanager\SalesContract.js
 * @param {*} data 
 * @param {*} success 成功回调 这里直接返回一个promise对象去store里处理了 store地址如上
 * @param {*} fail 失败回调
 * @Author{*} seven(有问题找我)
 * @return {*}
 */
export const queryPaymentRecordsList = async(data) => {
  return Request.requestJson(
  Request.GET,
  'https://mockapi.eolink.com/fhdz9TQ7632232d76db4f62838f5c8793d22b77760ead7b/paymentrecords',
  {
  data
  }
)
}
