import { defineStore } from 'pinia'
import { ref } from 'vue'

const useSupplierList = defineStore('supplierList', () => {
  // 总页数
  const pageTotal = ref(0)
  const tableData = ref([])
  const setTableData = (data) => {
    tableData.value = data
  }
  // 新增或修改供应商信息
  const addOrUpdateSupplier = ref({
    supplier_id: '', //供应商Id
    name: '', //供应商名称
    ecotype: 0, //经济类型
    trade: 0, //行业类型
    linkman_name: '', //联系人
    tel: '', //电话号码
    fax: '', // 传真
    email: '', //邮箱
    address: '', //联系地址
    intro: '' //介绍
  })

  //重置数据
  const addOrUpdateSupplierReset = () => {
    addOrUpdateSupplier.value = {
      supplier_id: '', //供应商Id
      name: '', //供应商名称
      ecotype: 0, //经济类型
      trade: 0, //行业类型
      linkman_name: '', //联系人
      tel: '', //电话号码
      fax: '', // 传真
      email: '', //邮箱
      address: '', //联系地址
      intro: '' //介绍
    }
  }

  // 存储联系人的数据
  let contactInfo = ref({
    supplier_id: '',
    name: '',
    gender: '',
    mobile: '',
    position: '',
    tel: '',
    qicq: '',
    email: '',
    address: '',
    intro: '',
    customer_id: '',
    customer_name: ''
  })
  // 重置数据
  const contactReset = () => {
    contactInfo.value = {
      supplier_id: '',
      name: '',
      gender: '',
      mobile: '',
      position: '',
      tel: '',
      qicq: '',
      email: '',
      address: '',
      intro: ''
    }
  }
  return {
    pageTotal,
    tableData,
    setTableData,
    addOrUpdateSupplier,
    addOrUpdateSupplierReset,
    contactInfo,
    contactReset
  }
})
export default useSupplierList
