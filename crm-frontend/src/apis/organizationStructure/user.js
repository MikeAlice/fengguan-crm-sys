/*
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-11-02 15:18:28
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-06 13:12:12
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\organizationStructure\user.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 用户管理接口
import Request from '../request'
/**
 * @description: 获取用户列表 分页+条件
 * @param {*} params 请求参数:{deptId(部门id), name(姓名),pageIndex(查询页码), pageSize(查询条数)}
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const getUserTableList = async (params, success, fail) => {
  await Request.requestForm(
    Request.GET,
    'http://101.34.252.80:10110/orgstructure/user/user/query-all-by-deptid-or-name',
    { ...params }
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * @description: 新增用户
 * @param {*} params 请求参数:
 * {
 *  account(账号)
 *  deptID(部门id)
 *  email(邮箱)
 *  gender(性别)
 *  intro:(简介)
 *  mobile(手机号)
 *  name:(用户昵称)
 *  password:(密码)
 *  positionID(岗位id)
 *  qicq(qq号)
 *  roleID(角色id)
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const addUserApi = async (params, success, fail) => {
  await Request.requestJson(
    Request.POST,
    'http://101.34.252.80:10110/orgstructure/user/user/add-user',
    params
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * @description: 修改用户
 * @param {*} params 请求参数:
 * {
 *  account(账号)
 *  deptID(部门id)
 *  email(邮箱)
 *  gender(性别)
 *  intro:(简介)
 *  mobile(手机号)
 *  name:(用户昵称)
 *  password:(密码)
 *  positionID(岗位id)
 *  qicq(qq号)
 *  roleID(角色id)
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const editUserApi = async (params, success, fail) => {
  await Request.requestJson(
    Request.PUT,
    'http://101.34.252.80:10110/orgstructure/user/user/update-user',
    { ...params }
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * @description: 删除用户
 * @param {*} params 请求参数:
 * {
 *  userId(用户ID)
 * }
 * @param {*} success 成功回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const deleteUserApi = async (params, success) => {
  await Request.requestForm(
    Request.DELETE,
    'http://101.34.252.80:10110/orgstructure/user/user/delete-user',
    { ...params }
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      success(response)
    })
    .catch((error) => {
      console.log(error)
      ElMessage({
        message: '删除失败',
        type: 'warning'
      })
    })
}
