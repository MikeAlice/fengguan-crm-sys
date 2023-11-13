/*
 * @Author: BINGWU
 * @Date: 2023-11-04 10:55:19
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-08 12:17:30
 * @FilePath: \crm-frontend\src\apis\basic-data\product\productbrand.js
 * @Describe: 商品品牌模块的api
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */

import Request from '@/apis/request.js'
const baseUrl = ''

/**
 * @description:分页查询品牌列表
 * @param {Object} params   {pageSize,pageNumber}
 * @return {Promise}
 */
export const queryBrand = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/goods/commodityBrand/query-brand',
    params
  )
}
/**
 * @description: 添加品牌
 * @param {Object} params
 * @return {Promise}
 */
export const addBrand = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/goods/commodityBrand/add-brand',
    params
  )
}

export const modifyBrand = async (params) => {
  return await Request.requestJson(
    Request.PUT,
    baseUrl + '/goods/commodityBrand/modify-brand',
    params
  )
}

export const removeBrand = async (params) => {
  return await Request.requestJson(
    Request.PUT,
    baseUrl + '/goods/commodityBrand/remove-brand',
    params
  )
}
