/*
 * @Author: BINGWU
 * @Date: 2023-11-01 14:52:14
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-06 18:33:57
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-03 13:26:55
 * @FilePath: \crm-frontend\src\apis\basic-data\data-dictionary\classification.js
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
//test
import Request from '@/apis/request.js'
const baseUrl = ''
/**
 * @description: 分页查询字典分类的数据
 * @param {Object} params // pageIndex pageSize
 * @return {Promise}
 */
export const queryDictclassify = (params) => {
  return Request.requestJson(
    Request.GET,
    baseUrl + '/data-dictionary/dictclassify/query-dictclassify',
    params
  )
}

/**
 * @description: 
 * @param {*} params 
 * 字段
 * {
  "id": 0,
  "typeName": "string",
  "typetag": "string",
  "sort": 0,
  "visible": 0,
  "intro": "string",
  "seotitle": 0,
  "keywords": 0
}
 * @return {Promise}
 */
export const addDictclassify = (params) => {
  return Request.requestJson(
    Request.POST,
    baseUrl + '/data-dictionary/dictclassify/add-dictclassify',
    params
  )
}

/**
 * @description: 修改字典分类
 * @param {*} params
 * {
  "id": 0,
  "typeName": "string",
  "typetag": "string",
  "sort": 0,
  "visible": 0,
  "intro": "string",
  "seotitle": 0,
  "keywords": 0
}
 * @return {Promise}
 */
export const modifyDictclassify = (params) => {
  return Request.requestJson(
    Request.PUT,
    baseUrl + '/data-dictionary/dictclassify/modify-dictclassify',
    params
  )
}

/**
 * @description: 删除字典分类数据
 * @param {Object} params
 * id
 * @return {Promise}
 */
export const deleteDictclassify = (params) => {
  return Request.requestJson(
    Request.DELETE,
    baseUrl + `/data-dictionary/dictclassify/delete-dictclassify/${params.id}`
  )
}
