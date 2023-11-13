/*
 * @Author: BINGWU
 * @Date: 2023-11-07 22:08:16
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-09 22:37:47
 * @FilePath: \crm-frontend\src\apis\basic-data\financial-type\incometype.js
 * @Describe: 费用收入模块api
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
import Request from '@/apis/request.js'
const baseUrl = ''
export const addFeeincome = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/feeincome/add-feeincome',
    params
  )
}
export const modifyFeeincome = async (params) => {
  return await Request.requestJson(
    Request.PUT,
    baseUrl + '/feeincome/modify-feeincome',
    params
  )
}
export const deleteFeeincome = async (params) => {
  return await Request.requestJson(
    Request.DELETE,
    baseUrl + `/feeincome/delete-feeincome/${params.id}`
  )
}
