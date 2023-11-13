import Request from '../request'

/**
 * 获取跟踪记录列表
 * @param {*} params
 * @returns
 */
export const getTrackRecordsAPI = (params) => {
  // console.log('发送请求', params)
  return Request.requestJson(Request.GET, '/crm-c4-sales-man/get', params)
}

/**
 * 添加跟踪记录
 * @param {*} params
 * @returns
 */
export const addTrackRecordsAPI = (params) => {
  // console.log('发送请求', params)
  return Request.requestJson(
    Request.POST,
    '/crm-c4-sales-man/add-trace',
    params
  )
}
