/*
 * @Author: BINGWU
 * @Date: 2023-10-31 16:45:52
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-06 21:11:17
 * @FilePath: \crm-frontend\src\apis\basic-data\data-dictionary\management.js
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
import Request from '@/apis/request.js'
const baseUrl = ''
/**
 * @description: 查询字典管理数据
 * @param {Object} params // pageSize pageIndex name  分类名称 typetag 调用标识
 * @return {Promise}
 */
export const getDict = async (params) => {
  return await Request.requestJson(
    Request.GET,
    baseUrl + '/data-dictionary/dictmanage/get-dict',
    params
  )
}

/**
 * @description: 删除字典管理数据
 * @param {Object} params  id
 * @return {Promise}
 */
export const deleteDict = async (params) => {
  return await Request.requestJson(
    Request.DELETE,
    baseUrl + `/data-dictionary/dictmanage/delete-dict/${params.id}`,
    params
  )
}

export const modifyDict = async (params) => {
  return await Request.requestJson(
    Request.PUT,
    baseUrl + '/data-dictionary/dictmanage/modify-dict',
    params
  )
}

export const addDict = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/data-dictionary/dictmanage/add-dict',
    params
  )
}
