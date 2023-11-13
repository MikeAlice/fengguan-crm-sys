/*
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-11-04 23:26:00
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-08 09:35:42
 * @FilePath: \zero-one-crmsys\crm-frontend\src\stores\organizationStructure\departmentManage.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 部门管理仓库223
import { defineStore } from 'pinia'
import { ref } from 'vue'
import { getDepartmentListApi } from '../../apis/organizationStructure/department'
const useDepartmentManageStore = defineStore('DepartmentManage', () => {
  // 定义部门名称结构树 的数据
  const DepartmentTree = ref([])
  const setDepartmentTree = (dataList) => {
    DepartmentTree.value = dataList
  }

  // 定义部门名称列表数据
  const departmentSelect = ref([])
  const setDepartmentSelect = (dataArr) => {
    departmentSelect.value = dataArr
  }

  /**
   * 封装获取部门列表(分页+条件)api方法
   * @param {*} dataObj
   * {
   *  keywords: 部门关键字,
   *  pageIndex： 查询页码,
   *  pageSize: 查询条数,
   *  pid:父级部门id
   * }
   */
  const getDepartmentList = async (dataObj) => {
    const { keywords, pageIndex, pageSize, pid } = dataObj
    const $res = ref()
    await getDepartmentListApi(
      {
        keywords,
        pageIndex,
        pageSize,
        pid
      },
      (res) => {
        console.log('获取部门列表成功回调', res)
        $res.value = res
      }
    )
    return $res
  }
  return {
    DepartmentTree,
    setDepartmentTree,
    getDepartmentList,
    departmentSelect,
    setDepartmentSelect
  }
})
export default useDepartmentManageStore
