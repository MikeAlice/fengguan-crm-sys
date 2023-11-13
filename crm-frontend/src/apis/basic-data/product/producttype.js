/*
 * @Author: BINGWU
 * @Date: 2023-11-04 14:08:41
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-08 15:12:15
 * @FilePath: \crm-frontend\src\apis\basic-data\product\producttype.js
 * @Describe: 商品类型模块的api
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
import Request from '@/apis/request.js'
const baseUrl = ''
/**
 * @description: 添加类型
 * @param {Object} params
 * @return {Promise}
 */
export const addType = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/goods/type/add-type',
    params
  )
}

export const deleteType = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/goods/type/delete-type',
    params
  )
}

export const findDetailedType = async (params) => {
  return await Request.requestJson(
    Request.GET,
    baseUrl + '/goods/type/find-detailed-type',
    params
  )
}

export const findSimpleType = async (params) => {
  return await Request.requestJson(
    Request.GET,
    baseUrl + '/goods/type/find-simple-type',
    params
  )
}

export const modifyDetailedType = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/goods/type/modify-detailed-type',
    params
  )
}
