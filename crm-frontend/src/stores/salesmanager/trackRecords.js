import { defineStore } from 'pinia'
import {
  getTrackRecordsAPI,
  addTrackRecordsAPI
} from '@/apis/sales-manager/trackRecords.js'
import { ref } from 'vue'

export const useTrackRecordsStore = defineStore('trackrecords', () => {
  const tableColumnAttribute = [
    {
      prop: 'AC',
      label: '关联客户',
      sortable: false
    },
    {
      prop: 'cus_linkman',
      label: '客户联系人',
      sortable: false
    },
    {
      prop: 'FM',
      label: '跟进方式'
    },
    {
      prop: 'FT',
      label: '跟进时间'
    },
    {
      prop: 'NT',
      label: '下次联系时间'
    },
    {
      prop: 'CContent',
      label: '沟通内容'
    },
    {
      prop: 'CS',
      label: '当前阶段'
    },
    {
      prop: 'sale_opp',
      label: '销售机会'
    }
  ]
  // 表格数据
  const tableData = ref([])
  // 数据总计
  const tableTotal = ref(100)
  // 获取表格数据的方法
  const getTableData = async (params) => {
    await getTrackRecordsAPI(params)
      .then((res) => {
        console.log('跟踪记录列表的值', res.data.rows)
        // console.log('5')
        const rows = res.data.rows
        tableData.value = rows
        // 获取数据总量
        tableTotal.value = res.data.total
      })
      .catch((err) => {
        console.log(err)
      })
  }
  /**
   * 添加跟踪记录的仓库用来存储数据
   * @param {*} params
   */
  const addTrackRecords = async (params) => {
    await addTrackRecordsAPI(params)
  }

  return {
    getTableData,
    tableData,
    tableColumnAttribute,
    addTrackRecords
  }
})
