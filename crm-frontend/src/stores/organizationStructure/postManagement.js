/*
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-11-04 23:26:00
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-08 23:13:29
 * @FilePath: \zero-one-crmsys\crm-frontend\src\stores\organizationStructure\postManagement.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-11-02 15:23:01
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-05 16:18:48
 * @FilePath: \zero-one-crmsys\crm-frontend\src\stores\organizationStructure\postManagement.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 岗位管理仓库
import { defineStore } from 'pinia'
import { ref } from 'vue'
const usePostManageStore = defineStore('post', () => {
  // 定义岗位名称列表数据
  const usePostList = ref([])
  // 设置岗位名称列表数据
  const setUserPostList = (dataList) => {
    usePostList.value = dataList
  }
  // 定义岗位名称结构树
  const postTreeMeau = ref()
  const setPostTreeMeau = (dataList) => {
    postTreeMeau.value = dataList
  }
  // 页面表格的数据
  const postListTable = ref()
  const setPostListTable = (dataList) => {
    postListTable.value = dataList
  }

  return {
    usePostList,
    setUserPostList,
    postTreeMeau,
    setPostTreeMeau,
    postListTable,
    setPostListTable
  }
})
export default usePostManageStore
