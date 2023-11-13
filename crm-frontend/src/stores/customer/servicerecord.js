import { defineStore } from 'pinia'
import { ref } from 'vue'

const useServiceRecord = defineStore('serviceRecord', () => {
  const total = ref(0)
  let tableData = ref([])

  // 设置表格数据
  const setTableData = (data = []) => {
    tableData.value = data
  }

  // 添加或修改数据的暂存区
  let temp = ref({
    customer_id: 1, // 客户id
    linkman_id: 1, //联系人id
    services: 1, // 服务类型
    servicesmodel: 1, //服务方式
    price: 1, // 价格
    status: 1, //服务记录状态 1=无需处理，2未处理，3=处理中，4处理完成
    service_time: '', // 服务日期
    tlen: 0, //服务时长
    content: '', //服务内容
    intro: '', //备注
    customer_name: '', //客户姓名
    linkman_name: '' //联系人姓名
  })

  const tempReset = () => {
    temp.value = {
      customer_id: 1, // 客户id
      linkman_id: 1, //联系人id
      services: 1, // 服务类型
      servicesmodel: 1, //服务方式
      price: 1, // 价格
      status: 1, //服务记录状态 1=无需处理，2未处理，3=处理中，4处理完成
      service_time: '', // 服务日期
      tlen: 0, //服务时长
      content: '', //服务内容
      intro: '', //备注
      customer_name: '', //客户姓名
      linkman_name: '' //联系人姓名
    }
  }

  return {
    total,
    tableData,
    setTableData,
    temp,
    tempReset
  }
})

export default useServiceRecord
