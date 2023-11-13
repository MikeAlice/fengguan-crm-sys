/*
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-11-03 15:02:57
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-11-03 15:15:26
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\fund\tickets\index.js
 * @Description:
 *
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved.
 */
import Request from '@/apis/request'

//获取收票记录列表
const getTicketsRecordList = (pageParams, searchParams = {}) => {
  return Request.requestJson(Request.GET, '/fin-invoice-rece/query', {
    ...pageParams,
    ...searchParams
  })
}

//删除收票记录-支持批量
const deleteTicketsRecord = (idList) => {
  return Request.requestJson(Request.DELETE, +'/receipt-record/remove', {
    record_id: [...idList]
  })
}

const addTicketsRecord = (data) => {
  return Request.requestJson(
    Request.POST,
    +'/financial-manager/add-invoice',
    data
  )
}

//导出收票记录 目前是POST
const exportTicketsRecord = (id) => {
  return Request.requestJson(Request.POST, +'/exportcapitalrecord', {
    record_id: id
  })
}

export {
  getTicketsRecordList,
  deleteTicketsRecord,
  addTicketsRecord,
  exportTicketsRecord
}
