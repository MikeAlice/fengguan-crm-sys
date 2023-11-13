/*
 * @Author: BINGWU
 * @Date: 2023-11-07 15:58:45
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-07 20:03:55
 * @FilePath: \crm-frontend\src\apis\basic-data\financial-type\bankaccount.js
 * @Describe: 银行账号管理模块接口
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */

import Request from '@/apis/request.js'
const baseUrl = ''

export const queryBankaccount = async (params) => {
  return await Request.requestJson(
    Request.GET,
    baseUrl + '/financial-management/bankaccount/query-bankaccount',
    params
  )
}

export const modifyBankaccount = async (params) => {
  return await Request.requestJson(
    Request.PUT,
    baseUrl + '/financial-management/bankaccount/modify-bankaccount',
    params
  )
}

export const deleteBankaccount = async (params) => {
  return await Request.requestJson(
    Request.DELETE,
    baseUrl +
      `/financial-management/bankaccount/delete-bankaccount/${params.bank_id}`,
    params
  )
}

export const addBankaccount = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/financial-management/bankaccount/add-bankaccount',
    params
  )
}
