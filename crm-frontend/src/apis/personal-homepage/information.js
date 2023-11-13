/*
 * @Author: pipazi 2283356040@qq.com
 * @Date: 2023-11-03 12:55:47
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2023-11-06 16:06:06
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\personal-homapage\infomation.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

import Request from '@/apis/request.js'
const baseUrl = '/java3-personal-homepage'

// 编辑资料
export const modifyOwnerInfo = async (params) => {
  await Request.requestForm(
    Request.POST,
    '/j3-owner-info/modify-owner-info',
    params
  )
    .then((res) => {
      console.log(res)
    })
    .catch((err) => {
      console.log(err)
    })
}
