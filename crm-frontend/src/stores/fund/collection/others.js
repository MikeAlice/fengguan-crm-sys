/*
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-11-02 14:19:40
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-11-02 14:35:47
 * @FilePath: \zero-one-crmsys\crm-frontend\src\stores\fund\collection\others.js
 * @Description:
 *
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved.
 */
//因为几个页面都需要客户和合同，单独抽出来
import { defineStore } from 'pinia'
import { getCustomerName, getBankAccountList } from '@/apis/publicInterface'
export const useCollectionOthers = defineStore('collectionOthers', {
  state: () => ({
    clientNameList: ['sayoriqwq', 'sayori'],
    saleContractList: ['合同1', '合同2'],
    payAccountList: ['账户1', '账户2']
  }),
  actions: {
    //后续在这里发对应请求拿数据
    //不知道要param干嘛
    async getCilentNameList(param) {
      const res = await getCustomerName(param).catch((e) => {
        ElMessage(e.message)
      })
      if (!res.data) return
      this.clientNameList = res.data
    },
    //银行账号列表
    async getPayAccountList(param) {
      const res = await getBankAccountList(param).catch((e) => {
        ElMessage(e.message)
      })
      if (!res.data) return
      this.payAccountList = res.data
    }
  }
})
