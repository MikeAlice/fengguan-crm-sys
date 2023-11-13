/*
 * @Author: pipazi 2283356040@qq.com
 * @Date: 2023-11-03 12:56:03
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2023-11-09 17:09:58
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\personal-homapage\message.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

import Request from '@/apis/request.js'
const baseUrl = '/java3-personal-homepage'


// 根据分页条件获取消息列表
export const queryMessage = async (params) => {
  return await Request.requestForm(
    Request.GET,
    '/j3-message-remind/queryMessage',
    params
  )
}

// 查看消息详情
export const queryMessageId = async (params) => {
  return await Request.requestForm(
    Request.GET,
    '/j3-message-remind/{id}',
    params
  )
    // .then((res) => {
    //   console.log(res)
    // })
    // .catch((err) => {
    //   console.log(err)
    // })
}

// 消息删除
export const deleteMassage = async (params) => {
  return  await Request.requestJson(
      Request.DELETE,
      '/j3-message-remind/deleteMassage',
      params
    )
      // .then((res) => {
      //   console.log(res)
      // })
      // .catch((err) => {
      //   console.log(err)
      // })
}

// 批量消息已读（批量操作）
export const markReadMessage = async (params) => {
  return  await Request.requestJson(
      Request.POST,
      '/j3-message-remind/mark-read-message',
      params
    )
      // .then((res) => {
      //   console.log(res)
      // })
      // .catch((err) => {
      //   console.log(err)
      // })
}

// 发布消息
export const publishMessage = async (params) => {
  return  await Request.requestForm(
      Request.POST,
      '/j3-message-remind/publish-message',
      params
    )
      // .then((res) => {
      //   console.log(res)
      // })
      // .catch((err) => {
      //   console.log(err)
      // })
}


