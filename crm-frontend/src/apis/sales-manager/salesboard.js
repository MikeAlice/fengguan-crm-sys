import Request from '../request'

/**
 * 获取销售榜数据
 * @param {*} params
 * @returns
 */
export const getSalesBoardAPI = async (params) => {
  return await Request.requestJson(
    Request.GET,
    '/crm-c4-sales-man/querySalesChart',
    params
  )
}
