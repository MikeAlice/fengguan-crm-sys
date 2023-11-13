/*
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-11-02 15:21:31
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-10 16:16:45
 * @FilePath: \zero-one-crmsys\crm-frontend\src\stores\organizationStructure\rolesManage.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 角色管理的仓库
import { defineStore } from 'pinia'
import { ref } from 'vue'
import { getRoleListApi } from '../../apis/organizationStructure/Roles'
export const useRoleManageStore = defineStore('roleManage', () => {
  // 定义角色名称结构树
  const roleTreeList = ref([])
  // 修改角色名称结构树的方法
  const setRoleTreeList = (dataList) => {
    roleTreeList.value = dataList
  }
  // 获取角色列表(分页+条件)api方法
  /**
   *
   * @param {*} paramsObj
   * {
   *  keyword: 角色关键词,示例值(超级管理员),
   *  pageIndex: '查询页码,示例值(1)',
   *  pageSize: 查询条数,示例值(10),
   *  pid: 父级id
   * }
   */
  const getTheRoleList = async (paramsObj) => {
    const { keyword, pageIndex, pageSize, pid } = paramsObj
    const $res = ref()
    await getRoleListApi(
      {
        keyword,
        pageIndex,
        pageSize,
        pid
      },
      (res) => {
        console.log(
          '获取角色列表(分页+条件):',
          res,
          '传入参数是:',
          keyword,
          pageIndex,
          pageSize,
          pid
        )
        $res.value = res
      },
      (error) => {
        console.log(error)
      }
    )
    return $res
  }
  // 菜单权限的数据
  const roleMeauPower = ref([])
  // 设置菜单权限数据的方法
  const setroleMeauPower = (dataList)=> {
    roleMeauPower.value = dataList
  }
  return {
    roleTreeList,
    setRoleTreeList,
    getTheRoleList,
    roleMeauPower,
    setroleMeauPower
  }
})
export default useRoleManageStore
