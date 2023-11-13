/*
 * @Author: BINGWU
 * @Date: 2023-11-03 23:36:26
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-06 13:19:05
 * @FilePath: \crm-frontend\src\apis\basic-data\warehouse\warehouse.js
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
import Request from '@/apis/request.js'
const baseUrl = ''

export const queryStore = async (params) => {
  return await Request.requestJson(
    Request.GET,
    baseUrl + '/j3-controller-warehouse/query-store',
    params
  )
}

export const addStore = async (params) => {
  return await Request.requestForm(
    Request.POST,
    baseUrl + '/j3-controller-warehouse/add-store',
    params
  )
}

export const modifyStoreInfo = async (params) => {
  return await Request.requestForm(
    Request.POST,
    baseUrl + '/j3-controller-warehouse/modify-store-info',
    params
  )
}

export const deleteStore = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/j3-controller-warehouse/delete-store',
    params
  )
}

export const exportStore = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/j3-controller-warehouse/export-store',
    params
  )
}

export const importStore = async (params) => {
  return await Request.postFile(
    baseUrl + '/j3-controller-warehouse/import-store',
    params
  )
}
