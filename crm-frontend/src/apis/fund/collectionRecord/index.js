/*
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-11-05 21:59:04
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-11-07 12:18:03
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\fund\collectionRecord\index.js
 * @Description:
 *
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved.
 */
import Request from '@/apis/request'
//查询回款记录列表-搜索
const getCollectionRecordList = (pageParams, searchParams = {}) => {
  return Request.requestForm(
    Request.GET,
    'collection-man/collectionRecord/qurery',
    {
      ...pageParams,
      ...searchParams
    }
  )
}
//新增回款记录
const addCollectionRecord = (data) => {
  return Request.requestJson(Request.POST, +'/CollectionRecord/add', data)
}
//删除回款记录
const deleteCollectionRecord = (data) => {
  return Request.requestJson(Request.DELETE, +'/collectionRecord/delete', data)
}

//导出回款记录
const exportCollectionRecord = (data) => {
  return Request.requestJson(Request.GET, +'/collectionRecord/download', data)
}

export {
  getCollectionRecordList,
  addCollectionRecord,
  deleteCollectionRecord,
  exportCollectionRecord
}
