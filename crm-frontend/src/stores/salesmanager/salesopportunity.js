/*
 * @Author: seven 1473008948@qq.com
 * @Date: 2023-11-04 15:57:42
 * @LastEditors: seven 1473008948@qq.com
 * @LastEditTime: 2023-11-04 15:58:15
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\sales-manager\salesopportunity.js
 */

import { defineStore } from 'pinia'
import { querySalesOpportunityNameList } from '@/apis/publicInterface.js'
import { ref } from 'vue'
import {
  querySalesOpportunityList,
  addSalesOpportunity,
  updateSalesOpportunity,
  deleteSalesOpportunity,
  exportSalesOpportunity,
  sendMails,
  sendEmail
} from '@/apis/sales-manager/salesopportunity.js'

/**
 * 获取销售合同列表的仓库
 */
export const useSalesOpportunityStore = defineStore('salesopportunity', () => {
  // 表格数据
  const tableData = ref([])
  // 数据总计
  const tableTotal = ref(100)
  // 获取表格数据的方法
  const getTableData = async (params) => {
    await querySalesOpportunityList(params)
      .then((res) => {
        console.log('销售机会列表的值', res.data.rows)
        // console.log('5')
        const rows = res.data.rows
        tableData.value = rows.map((item) => {
          return {
            // 销售机会id
            // chance_id: item.chance_id,
            // 销售机会主题
            opportunity_title: item.name,
            // 主题和创建时间
            titleAndCreateDate: `${item.name}\n(创建：${item.create_time})`,
            // 客户id
            // customer_id: item.customer_id,
            // 客户名和联系人
            customer_nameAndLinkman_name: `${item.customer_name}\n(联系人：${item.linkman_name})`,

            // 联系人id
            linkman_name: item.linkman_name,
            //发现日期
            find_date: item.find_date,
            // 预计签单日期
            bill_date: item.bill_date,
            // 销售阶段
            sales_stage: item.salestage,
            // 销售金额
            money: item.money,

            // 用户姓名
            customer_name: item.customer_name,
            // 需求
            intro: item.intro,
            // 当前阶段
            status: item.status,
            // 创建的联系人ID
            create_user_id: item.create_user_id,
            // 创建时间
            create_time: item.create_time
          }
        })
        // 获取数据总量
        tableTotal.value = res.data.total
      })
      .catch((err) => {
        console.log(err)
      })
  }

  const getSalesOpportunityName = async (params) => {
    return await querySalesOpportunityNameList(params)
  }
  const addItem = async (params) => {
    return await addSalesOpportunity(params)
  }

  const updateItem = async (params) => {
    return await updateSalesOpportunity(params)
  }

  const deleteItem = async (params) => {
    return await deleteSalesOpportunity(params)
  }

  const exportItem = async (params) => {
    return await exportSalesOpportunity(params)
  }

  const sendEM = async (params) => {
    return await sendEmail(params)
  }

  const sendMSG = async (params) => {
    return await sendMails(params)
  }

  return {
    getTableData,
    tableData,
    getSalesOpportunityName,
    tableTotal,
    addItem,
    updateItem,
    deleteItem,
    sendEM,
    sendMSG,
    exportItem
  }
})
