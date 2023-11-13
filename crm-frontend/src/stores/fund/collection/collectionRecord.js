/*
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-11-01 18:21:22
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-11-01 20:37:25
 * @FilePath: \zero-one-crmsys\crm-frontend\src\stores\fund\collection\collectionRecord.js
 * @Description:
 *
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved.
 */
import { defineStore } from 'pinia'
import { getCollectionRecordList } from '@/apis/fund/collectionRecord/index.js'
export const useCollectionRecord = defineStore('collectionRecord', {
  state: () => ({
    clientNameList: ['sayoriqwq', 'sayori'],
    saleContractList: ['合同1', '合同2'],
    payAccountList: ['账户1', '账户2'],
    sendData: {
      tableColumnAttribute: [
        {
          prop: 'record_id',
          label: '汇款记录编号'
        },
        {
          prop: 'customer_name',
          label: '客户名称'
        },
        {
          prop: 'contract_id',
          label: '合同订单'
        },
        {
          prop: 'back_date',
          label: '回款日期'
        },
        {
          prop: 'stages',
          label: '期次'
        },
        {
          prop: 'back_id',
          label: '回款账号'
        },
        {
          prop: 'money',
          label: '金额'
        },
        {
          prop: 'create_user_id',
          label: '创建人'
        },
        {
          prop: 'create_time',
          label: '创建时间'
        }
      ],
      tableData: [
        {
          record_id: 1,
          customer_name: '成都零起飞科技',
          contract_id: '合同1',
          back_date: '2023-09-20 18:35:14',
          stages: '第一期',
          back_id: '账户1',
          money: '10000',
          create_user_id: 'sayoriqwq',
          create_time: '2023-09-20 18:35:14'
        },
        {
          record_id: 2,
          customer_name: '成都零起飞123',
          contract_id: '合同1',
          back_date: '2023-09-20 18:35:14',
          stages: '第一期',
          back_id: '账户1',
          money: '10000',
          create_user_id: 'sayoriqwq',
          create_time: '2023-09-20 18:35:14'
        }
      ],
      useHeader: false,
      usePagination: true,
      pageSizes: [2, 4, 6, 10],
      total: 10
    }
  }),
  getters: {},
  actions: {
    async getCollectionRecordList(pageParams, searchParams) {
      const res = await getCollectionRecordList(pageParams, searchParams).catch(
        (e) => e
      )
      console.log('res', res)
    }
  }
})
