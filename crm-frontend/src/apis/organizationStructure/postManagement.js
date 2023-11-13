/*
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-11-02 15:19:11
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-09 00:41:21
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\organizationStructure\postManagement.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 岗位管理接口
import Request from '../request'
/**
 * @description: 获取岗位名称结构树
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
export const getPostTree = async (params, success, fail) => {
  await Request.requestForm(
    Request.GET,
    'http://101.34.252.80:10110/orgstructure/position/position/list-name-tree',
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
 * @description: 获取岗位列表(分页+条件)
 * @param {*} params 请求参数:
 * {
 *  keyword: 岗位关键词,
 *  pageIndex: '查询页码',
 *  pageSize: '查询条数',
 *  pid: '父级id'
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const getPostListApi = async (params, success) => {
  await Request.requestForm(
    Request.GET,
    'http://101.34.252.80:10110/orgstructure/position/position/query-all',
    { ...params }
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      success(response)
    })
    .catch((error) => {
      console.log(error)
      ElMessage({
        message: '获取数据失败',
        type: 'warning'
      })
    })
}

/**
 * @description: 新增岗位
 * @param {*} params 请求参数:
 * {
 *  intro: 介绍,
 *  name: '名称',
 *  parentID: '父级ID ',
 *  sort: '排序',
 *  visible: '是否启用'
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const addPostListApi = async (params, success) => {
  await Request.requestJson(
    Request.POST,
    'http://101.34.252.80:10110/orgstructure/position/position/add-position',
    { ...params }
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      success(response)
    })
    .catch((error) => {
      console.log(error)
      ElMessage({
        message: '添加失败',
        type: 'warning'
      })
    })
}

/**
 * @description: 删除岗位
 * @param {*} params 请求参数:
 * {
 *  positionId: '岗位ID ',
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const deletePostListApi = async (params, success) => {
  await Request.requestForm(
    Request.DELETE,
    'http://101.34.252.80:10110/orgstructure/position/position/delete-position',
    params
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      success(response)
    })
    .catch((error) => {
      console.log(error)
      ElMessage({
        message: '删除失败',
        type: 'danger'
      })
    })
}
