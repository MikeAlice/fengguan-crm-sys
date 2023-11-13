/*
 * @Author: pipazi 2283356040@qq.com
 * @Date: 2023-11-01 21:29:40
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2023-11-10 00:57:32
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\personal-homapage\notice.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

import Request from '@/apis/request.js'
// const baseUrl = '/java3-personal-homepage'

/**
 * @description: 公告通知
 * @param {Object} params // pageIndex pageSize
 * @return {Promise}
 */

// 获取系统公告
export const queryNotion = async (params) => {
  return await Request.requestForm(
    Request.GET,
    // baseUrl  + '/j3-notice-remind/query-notion',
    '/j3-notice-remind/query-notion',
    params
  )
}

// 发布公告（通过添加按钮）
export const addNotice = async (params) => {
  console.log('222222');
  return await Request.requestForm(
    Request.POST,
    '/j3-notice-remind/add-notice',
    params
  )
    // .then((res) => {
    //   console.log(res)
    // })
    // .catch((err) => {
    //   console.log(err)
    // })
}

// 查看指定公告详情（通过查看操作）
export const getNotice = async (params) => {
 
  await Request.requestForm(
    Request.GET,
    '/j3-notice-remind/get-notice',
    params
  )
    // .then((res) => {
    //   console.log(res)
    // })
    // .catch((err) => {
    //   console.log(err)
    // })
}


// 删除公告（可批量删除)按钮
export const removeNotice = async (params) => {
  return await Request.requestJson(
    Request.POST,
    '/j3-notice-remind/remove-notice',
    params
  )
  // .then((res) => {
  //   console.log(res)
  // })
  // .catch((err) => {
  //   console.log(err)
  // })
}


// 标记已读公告(可批量标记)按钮
export const updateNotice = async (params) => {
  return await Request.requestJson(
    Request.POST,
    '/j3-notice-remind/update-notice',
    params
  )
  // .then((res) => {
  //   console.log(res)
  // })
  // .catch((err) => {
  //   console.log(err)
  // })
}

