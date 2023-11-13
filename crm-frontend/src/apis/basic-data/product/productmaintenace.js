/*
 * @Author: BINGWU
 * @Date: 2023-11-04 11:38:59
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-04 13:54:34
 * @FilePath: \crm-frontend\src\apis\basic-data\product\productmaintenace.js
 * @Describe: 商品维护模块的api
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */

import Request from '@/apis/request.js'
const baseUrl = ''
/**
 * @description: 发布商品
 * @param {Object} params
 * @return {Promise}
 */
export const addGoods = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/goods/maintenance/add-goods',
    params
  )
}
