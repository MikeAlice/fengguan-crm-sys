/*
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-11-07 21:54:14
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-08 20:12:57
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\fund\InjectionExtraction\InjectionExtraction.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 这里是资金注入抽取的api
import Request from '../../request'
const BASEURL = ''
/**
 * @description: 查询资金注入抽取单号记录(分页+条件)
 * @param {*} params 请求参数:
 * {
 *  pageIndex:'当前页数',
 *  pageSize: '条数',
 *  record_id: '单号,
 *  money: '金额',
 *  bank: '银行账号',
 *  happen_date: '产生日期',
 *  create_time: '创建时间'
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @return {*}
 */
export const getFundInjectionApi = async (params, success) => {
  await Request.requestJson(
    Request.GET,
    BASEURL + '/fin-capital-record/query-data',
    params
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      console.log(response)
      success(response)
    })
    .catch((error) => {
      console.log(error)
      ElMessage({
        message: '操作失败',
        type: 'warning'
      })
    })
}

/**
 * @description: 添加资金注入抽取单号记录
 * @param {*} params 请求参数:
 * {
 *  type_id:'支出类型',
 *  bank_id: '银行账号id',
 *  create_user_id: '创建人id,
 *  money: '金额',
 *  happen_date: '产生日期',
 *  intro: '备注'
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @return {*}
 */
export const addFundInjectionApi = async (params, success) => {
  await Request.requestForm(
    Request.POST,
    BASEURL + '/fin-capital-record/add-data',
    params
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      // console.log(response)
      success(response)
    })
    .catch((error) => {
      console.log(error)
      ElMessage({
        message: '操作失败',
        type: 'danger'
      })
    })
}

/**
 * @description: 删除资金注入抽取单号记录
 * @param {*} params 请求参数:
 * {
 *  record_id: '单号
 * }
 * @param {*} success 成功回调
 * @return {*}
 */
export const deleteFundInjectionApi = async (params, success) => {
  await Request.requestForm(
    Request.DELETE,
    BASEURL + '/fin-capital-record/remove-data',
    params
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      // console.log(response)
      success(response)
    })
    .catch((error) => {
      console.log(error)
      ElMessage({
        message: '操作失败',
        type: 'warning'
      })
    })
}
