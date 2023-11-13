/*
 * @Author: BINGWU
 * @Date: 2023-11-04 11:33:37
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-08 18:23:06
 * @FilePath: \crm-frontend\src\apis\basic-data\product\productclassification.js
 * @Describe: 商品分类模块的api
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */

import Request from '@/apis/request.js'
const baseUrl = ''
/**
 * @description: 新增商品分类
 * @param {Object} params
 * @return {Promise}
 */
export const addGoodsCategory = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/goods/category/add',
    params
  )
}

export const getGoodsCategory = async (params) => {
  return await Request.requestJson(
    Request.GET,
    baseUrl + `/goods/category/get/${params.goodsCategoryId}`
  )
}

export const listGoodsCategory = async (params) => {
  return await Request.requestJson(
    Request.GET,
    baseUrl + '/goods/category/list-goods-category',
    params
  )
}

export const listGoodsCategoryNameTree = async () => {
  return await Request.requestJson(
    Request.GET,
    baseUrl + '/goods/category/list-goods-category-name-tree'
  )
}

export const modifyGoodsCategory = async (params) => {
  return await Request.requestJson(
    Request.PUT,
    baseUrl + '/goods/category/modify',
    params
  )
}

export const removeGoodsCategory = async (params) => {
  return await Request.requestJson(
    Request.DELETE,
    baseUrl + `/goods/category/remove/${params.goodsCategoryId}`
  )
}
