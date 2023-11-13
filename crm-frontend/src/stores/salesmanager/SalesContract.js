/*
 * @Author: seven 1473008948@qq.com
 * @Date: 2023-11-01 23:08:00
 * @LastEditors: seven 1473008948@qq.com
 * @LastEditTime: 2023-11-01 23:09:05
 * @FilePath: \zero-one-crmsys\crm-fronend\src\stores\sales-manager\SalesContract.js
 */

import { defineStore } from 'pinia'
import { ref } from 'vue'
// import { getSalesContractDataForSelectAPI } from '@/apis/publicInterface.js'
import {
  querySalesContractData,
  getSalesContractIDListAPI,
  getSalesContractDetailsAPI,
  getSalesContractListAPI,
  addNewContractAPI,
  updateSalesContractDataAPI,
  deleteSalesAPI,
  updateDeliverStatusAPI,
  insertDetailsAPI,
  deleteDetailsAPI,
  importFileAPI,
  makeOrderListAPI,
  exportContractAPI,
  sendMailsAPI,
  sendEMailsAPI
} from '@/apis/sales-manager/salescontract.js'
/**
 * 获取销售合同列表的仓库
 */
export const useSalesContractStore = defineStore('salescontract', () => {
  // 表格数据
  const tableData = ref([])
  // 合同列表项
  const tableColumnAttribute = [
    {
      prop: 'titleAndCreateDate',
      label: '合同主题',
      sortable: false
    },
    {
      prop: 'customer_nameAndLinkman_name',
      label: '客户名称',
      sortable: true
    },
    {
      prop: 'money',
      label: '合同金额',
      sortable: true
    },
    {
      prop: 'back_money_status',
      label: '回款/金额/状态',
      sortable: true
    },
    {
      prop: 'invoice_money_status',
      label: '发票/金额/状态',
      sortable: true
    },
    {
      prop: 'start_date',
      label: '开始时间',
      sortable: true
    },
    {
      prop: 'end_date',
      label: '结束时间',
      sortable: true
    },
    {
      prop: 'status',
      label: '合同状态',
      // 是否使用标签功能
      useTag: true
    },
    {
      prop: 'deliver_status',
      label: '交付状态',
      // 是否使用标签功能
      useTag: true
    }
  ]
  // 数据总计
  const tableTotal = ref(100)
  // const pageSize = ref(5)
  // 获取表格数据的方法
  const getTableData = async (params) => {
    await querySalesContractData(params)
      .then((res) => {
        console.log('获取表格数据的方法', res)
        // 这里是为了拿到res里的rows
        const rows = res.data.rows
        for (let i = 0; i < rows.length; i++) {
          switch (rows[i].status) {
            case 1:
              rows[i].status = {
                value: '临时单',
                tagType: 'info'
              }
              break
            case 2:
              rows[i].status = {
                value: '执行中',
                tagType: 'warning'
              }
              break
            case 3:
              rows[i].status = {
                value: '已完成',
                tagType: 'success'
              }
              break
            case 4:
              rows[i].status = {
                value: '撤销',
                tagType: 'danger'
              }
              break
          }
          switch (rows[i].back_status) {
            case 1:
              rows[i].back_status = '未付'
              break
            case 2:
              rows[i].back_status = '部分'
              break
            case 3:
              rows[i].back_status = '已付'
              break
          }
          switch (rows[i].deliver_status) {
            case -1:
              rows[i].deliver_status = {
                value: '无需交付',
                tagType: 'info'
              }
              break
            case 1:
              rows[i].deliver_status = {
                value: '需要',
                tagType: 'success'
              }
              break
            case 2:
              rows[i].deliver_status = {
                value: '录入明细',
                tagType: 'info'
              }
              break
            case 3:
              rows[i].deliver_status = {
                value: '待出库',
                tagType: 'warning'
              }
              break
            case 4:
              rows[i].deliver_status = {
                value: '部分',
                tagType: 'el'
              }
              break
            case 5:
              rows[i].deliver_status = {
                value: '全部',
                tagType: 'success'
              }
              break
          }
          switch (rows[i].invoice_status) {
            case 0:
              rows[i].invoice_status = '不需要'
              break
            case 1:
              rows[i].invoice_status = '需要'
              break
            case 2:
              rows[i].invoice_status = '部分'
              break
            case 3:
              rows[i].invoice_status = '全部'
              break
          }
        }
        console.log('rows数据', rows)

        tableData.value = rows.map((item) => {
          item.titleAndCreateDate = `${item.title}\n(创建：${item.create_time})`
          item.customer_nameAndLinkman_name = `${item.customer_name}\n(代表：${item.linkman_name})`
          item.back_money_status = `回款：${item.back_money}\n去零： ${item.zero_money}\n欠款： ${item.owe_money}\n状态：${item.back_status}`
          item.invoice_money_status = `开票： ${item.invoice_money}\n状态：${item.invoice_status}`
          return item
        })
      })
      .catch((err) => {
        console.log(err)
      })
  }

  /**
   * 获取销售合同数据 用于下拉列表
   * @param {*} params
   * @returns
   */
  const getSalesContractDataForSelect = async (params) => {
    console.log(params)
    // return await getSalesContractDataForSelectAPI(params)
  }

  /**
   * 获取销售合同唯一ID
   * @param {*} params
   * @returns
   */
  const getSalesContractIDList = async (params) => {
    console.log('参数', params)
    return await getSalesContractIDListAPI(params)
  }
  /**
   * 获取销售合同详情
   * @param {*} params
   * @returns
   */
  const getSalesContractDetails = async (params) => {
    return await getSalesContractDetailsAPI(params)
  }

  /**
   * 获取销售合同查看清单的数据
   * @param {*} params
   * @returns
   */
  const getSalesContractList = async (params) => {
    return await getSalesContractListAPI(params)
  }

  /**
   * 添加销售合同的方法
   * @param {*} params
   * @returns
   */
  const addNewContract = async (params) => {
    return await addNewContractAPI(params)
  }

  // 重置新增合同的数据
  const resetNewSalesContract = ref({
    contract_no: '',
    title: '',
    customer_name: '',
    linkman_name: '',
    chance_name: '',
    start_date: '',
    end_date: '',
    money: 0,
    intro: '',
    our_user_name: ''
  })

  /**
   * 更新销售合同数据
   * @param {*} params
   * @returns
   */
  const updateSalesContractData = async (params) => {
    return await updateSalesContractDataAPI(params)
  }

  /**
   * 删除销售合同
   * @param {*} params
   * @returns
   */
  const deleteSales = async (params) => {
    return await deleteSalesAPI(params)
  }

  const updateDeliverStatus = async (params) => {
    return await updateDeliverStatusAPI(params)
  }
  /**
   * 添加销售合同详情
   * @param {*} params
   * @returns
   */
  const insertDetails = async (params) => {
    return await insertDetailsAPI(params)
  }

  const deleteDetails = async (params) => {
    return await deleteDetailsAPI(params)
  }

  const importFile = async (params) => {
    return await importFileAPI(params)
  }

  const makeOrderList = async (params) => {
    return await makeOrderListAPI(params)
  }

  const exportContract = async (params) => {
    return await exportContractAPI(params)
  }
  const sendMails = async (params) => {
    return await sendMailsAPI(params)
  }

  const sendEMails = async (params) => {
    return await sendEMailsAPI(params)
  }

  return {
    getTableData,
    tableColumnAttribute,
    getSalesContractDataForSelect,
    getSalesContractIDList,
    getSalesContractDetails,
    getSalesContractList,
    addNewContract,
    updateSalesContractData,
    deleteSales,
    updateDeliverStatus,
    insertDetails,
    deleteDetails,
    importFile,
    makeOrderList,
    exportContract,
    sendMails,
    sendEMails,
    tableData,
    tableTotal,
    resetNewSalesContract
  }
})
