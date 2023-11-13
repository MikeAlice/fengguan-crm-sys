import { defineStore } from 'pinia'
import { ref } from 'vue'

const useSupplierLinkman = defineStore('supplierLinkman', () => {
  // 总页数
  const pageTotal = ref(0)
  const tableData = ref([])
  const setTableData = (data = []) => {
    tableData.value = data
  }

  //新增或修改供应商联系人
  const tempLinkData = ref({
    supplier_id: '', // 供应商ID
    gender: '', //性别
    position: '', //职位
    tel: '', //座机
    mobile: '', //手机
    qicq: '', // QQ
    email: '', //邮箱
    address: '', //联系地址
    intro: '', //介绍
    name: '' // 供应商联系人名称
  })

  // 重置数据
  const tempLinkDataReset = () => {
    tempLinkData.value = {
      supplier_id: '', // 供应商ID
      gender: '', //性别
      position: '', //职位
      tel: '', //座机
      mobile: '', //手机
      qicq: '', // QQ
      email: '', //邮箱
      address: '', //联系地址
      intro: '', //介绍
      name: '' // 供应商联系人名称
    }
  }
  return {
    pageTotal,
    tableData,
    setTableData,
    tempLinkData,
    tempLinkDataReset
  }
})
export default useSupplierLinkman
