/*
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-11-02 15:17:44
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-07 21:19:03
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\organizationStructure\department.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import Request from '../request'
// 部门管理接口
// import useDepartmentManageStore from '@/stores/organizationStructure/departmentManage.js'
// const departmentManage = useDepartmentManageStore()
/**
 * @description: 获取部门名称结构树
 * @param {*} params 请求参数:{depth(查询深度), pid:父级部门id}
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const getDepartmentTree = async (params, success, fail) => {
  await Request.requestForm(
    Request.GET,
    'http://101.34.252.80:10110/orgstructure/dept/dept/list-name-tree',
    {
      params
    }
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
 * @description: 获取部门列表(分页+条件)
 * @param {*} params 请求参数:
 * {
 *  keywords: 部门关键字,
 *  pageIndex： 查询页码,
 *  pageSize: 查询条数,
 *  pid:父级部门id
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const getDepartmentListApi = async (params, success) => {
  await Request.requestForm(
    Request.GET,
    'http://101.34.252.80:10110/orgstructure/dept/dept/query-all',
    {
      ...params
    }
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
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
 * @description: 新增部门
 * @param {*} params 请求参数:
 * {
 *  fax: 部门传真号,
 *  intro 部门介绍,
 *  name: 部门名称,
 *  parentID:父级ID,
 *  sort: 排序,
 *  tel: 部门电话，
 *  visible: 是否启用 (1启用，2禁用)
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const addDepartmentApi = async (params, success) => {
  await Request.requestJson(
    Request.POST,
    'http://101.34.252.80:10110/orgstructure/dept/dept/add-dept',
    params
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
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
 * @description: 删除部门
 * @param {*} params 请求参数:
 * {
 *  id:部门ID,
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const deleteDepartmentApi = async (params, success) => {
  await Request.requestForm(
    Request.DELETE,
    'http://101.34.252.80:10110/orgstructure/dept/dept/remove-dept',
    params
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
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