/*
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-11-03 21:20:58
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-07 22:40:01
 * @FilePath: \zero-one-crmsys\crm-frontend\src\stores\fundManagement\fundInjection.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import { defineStore } from 'pinia'
import { ref } from 'vue'
import { getFundInjectionApi } from '../../apis/fund/InjectionExtraction/InjectionExtraction'
// 这里是 资金管理/资金注入抽取 仓库
const useFundInjectionStore = defineStore('fundInjection', () => {
  // 银行账户列表数据 => 输入框下拉菜单
  const bankSelectList = ref()
  // 修改银行账户列表数据
  const setBankSelectList = (data) => {
    bankSelectList.value = data
  }
  // 获取数据列表(分页+条件)
  const getFundStoreApi = async (dataObj) => {
    const $res = ref()
    const {
      pageIndex,
      pageSize,
      record_id,
      money,
      bank,
      happen_date,
      create_time
    } = dataObj
    await getFundInjectionApi(
      {
        pageIndex,
        pageSize,
        record_id,
        money,
        bank,
        happen_date,
        create_time
      },
      (res) => {
        console.log('获取数据列表:', res)
        $res.value = res
      }
    )
    return $res
  }
  return {
    bankSelectList,
    setBankSelectList,
    getFundStoreApi
  }
})
export default useFundInjectionStore
