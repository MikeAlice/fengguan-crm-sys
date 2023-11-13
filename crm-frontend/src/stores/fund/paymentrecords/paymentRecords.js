/*
 * @Author: seven 1473008948@qq.com
 * @Date: 2023-11-03 15:44:58
 * @LastEditors: seven 1473008948@qq.com
 * @LastEditTime: 2023-11-03 15:45:00
 * @FilePath: \zero-one-crmsys\crm-frontend\src\stores\fund\paymentrecords\paymentRecords.js
 */

import { defineStore } from 'pinia'
import { ref } from 'vue'
import { queryPaymentRecordsList } from '@/apis/fund/payment/paymentrecords/index.js'

/**
 * 获取销售合同列表的仓库
 */
export const usePaymentRecordsStore = defineStore(
  'paymentrecords',
  () => {
    // 表格数据
    const tableData = ref([])
    // 数据总计
    const tableTotal = ref(100)
    // const pageSize = ref(5)
    // 获取表格数据的方法
    const getTableData = async (params) => {
      await queryPaymentRecordsList(
        params
      ).then((res) => {
        console.log('res的值',res);
        console.log('5')
        const rows = res.data.data
        tableData.value = rows.map((item) => {
          return {
            id: item.id,
            supplier_name: item.supplier_name,
            procurement_contract: item.procurement_contract,
            payment_date: item.payment_date,
            period: item.period,
            money: item.money,
            zero_money: item.zero_money,
            create_man: item.create_man,
            create_date: item.create_date,
            intro: item.intro
          }
        })
      }).catch((err) => {
        console.log(err)
      })
    }
    return {
      getTableData,
      tableData,
      tableTotal
    }
  })
