/*
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-11-02 15:19:55
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-10 16:00:11
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\organizationStructure\Roles.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 角色管理接口
import Request from '../request'
/**
 * @description: 获取角色名称结构树
 * @param {*} params 请求参数:
 * {
 *  depth: 查询深度,
 *  pid: '父级角色ID'
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const getRoleTree = async (params, success, fail) => {
  await Request.requestForm(
    Request.GET,
    'http://101.34.252.80:10110/orgstructure/role/role/list-name-tree',
    { params }
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
 * @description: 获取角色列表(分页+条件)
 * @param {*} params 请求参数:
 * {
 *  keyword: 角色关键词,示例值(超级管理员),
 *  pageIndex: '查询页码,示例值(1)',
 *  pageSize: 查询条数,示例值(10),
 *  pid: 父级id
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const getRoleListApi = async (params, success, fail) => {
  await Request.requestForm(
    Request.GET,
    'http://101.34.252.80:10110/orgstructure/role/role/query-all',
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
 * @description: 新增角色
 * @param {*} params 请求参数:
 * {
 *  intro: 简介,
 *  name: '角色名称',
 *  parentID: 父id,
 *  sort: 排序,
 *  visible: 	是否启用 1-启用，2-禁用
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const addRoleListApi = async (params, success, fail) => {
  await Request.requestJson(
    Request.POST,
    'http://101.34.252.80:10110/orgstructure/role/role/add-role',
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
 * @description: 修改角色
 * @param {*} params 请求参数:
 * {
 *  id: id,
 *  intro: '简介',
 *  name: '角色名称,
 *  parentID: 父id,
 *  sort: 排序,
 *  visible: 	是否启用 1-启用，2-禁用
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const editRoleListApi = async (params, success) => {
  await Request.requestJson(
    Request.PUT,
    'http://101.34.252.80:10110/orgstructure/role/role/modify-role',
    params
  )
    .then((response) => {
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
 * @description: 删除角色
 * @param {*} params 请求参数:
 * {
 *  id: 角色id,
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const deleteRoleListApi = async (params, success) => {
  await Request.requestForm(
    Request.DELETE,
    'http://101.34.252.80:10110/orgstructure/role/role/remove-role',
    params
  )
    .then((response) => {
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
 * @description: 获取角色菜单权限树形数据
 * @param {*} params 请求参数:
 * {
 *  roleId: 角色id
 * }
 * @param {*} success 成功回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const getRolePowerApi = async (params, success) => {
  await Request.requestForm(
    Request.GET,
    'http://101.34.252.80:10110/orgstructure/role/role-menu/role-check-power',
    params
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      console.log(error)
      ElMessage({
        message: '权限获取失败',
        type: 'warning'
      })
    })
}