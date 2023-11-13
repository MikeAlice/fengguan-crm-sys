import { defineStore } from 'pinia'
import { ref } from 'vue'

const useCommonStore = defineStore('commonStore', () => {
  // 供应商名称列表
  const supplierNameList = ref([])
  const setSupplierNameList = (data = []) => {
    supplierNameList.value = data
  }

  // 供应商联系人列表
  const linkmanNameList = ref([])
  const setLinkmanNameList = (data = []) => {
    linkmanNameList.value = data
  }

  // 仓库名称列表
  const warehouse = ref([])
  const setWarehouse = (data = []) => {
    warehouse.value = data
  }

  // 区域名称列表
  const area = ref([])
  const setArea = (data = []) => {
    area.value = data
  }

  //部门名称列表
  const departmentNameList = ref([])
  const setDepartmentNameList = (data = []) => {
    departmentNameList.value = data
  }
  //部门名称列表
  const positionNameList = ref([])
  const setPositionNameList = (data = []) => {
    positionNameList.value = data
  }

  //角色名称列表
  const roleNameList = ref([])
  const setRoleNameList = (data = []) => {
    roleNameList.value = data
  }

  //角色用户名称列表
  const sysUserNameList = ref([])
  const setSysUserNameList = (data = []) => {
    sysUserNameList.value = data
  }

  //客户名称名称列表
  const clientNameList = ref([])
  const setClientNameList = (data = []) => {
    clientNameList.value = data
  }

  //联系人名称列表
  const contactNameList = ref([])
  const setContactNameList = (data = []) => {
    contactNameList.value = data
  }

  //费用收入类型名称列表
  const costIncomeTypeNameList = ref([])
  const setCostIncomeTypeNameList = (data = []) => {
    costIncomeTypeNameList.value = data
  }

  //费用开支类型名称列表
  const costExpenseTypeNameList = ref([])
  const setCostExpenseTypeNameList = (data = []) => {
    costExpenseTypeNameList.value = data
  }

  //银行账户列表
  const bankAccountList = ref([])
  const setBankAccountList = (data = []) => {
    bankAccountList.value = data
  }

  //指定字典分类对应字典列表
  const dataDictNameList = ref([])
  const setDataDictNameList = (data = []) => {
    dataDictNameList.value = data
  }

  //销售机会名称列表
  const saleOpportunityNameList = ref([])
  const setSaleOpportunityNameList = (data = []) => {
    saleOpportunityNameList.value = data
  }

  //销售合同名称列表
  const saleContractNameList = ref([])
  const setSaleContractNameList = (data = []) => {
    saleContractNameList.value = data
  }

  //商品分类名称列表
  const goodsCategoryNameList = ref([])
  const setGoodsCategoryNameList = (data = []) => {
    goodsCategoryNameList.value = data
  }
  return {
    supplierNameList,
    setSupplierNameList,
    linkmanNameList,
    setLinkmanNameList,
    warehouse,
    setWarehouse,
    area,
    setArea,
    departmentNameList,
    setDepartmentNameList,
    positionNameList,
    setPositionNameList,
    roleNameList,
    setRoleNameList,
    sysUserNameList,
    setSysUserNameList,
    clientNameList,
    setClientNameList,
    contactNameList,
    setContactNameList,
    costIncomeTypeNameList,
    setCostIncomeTypeNameList,
    costExpenseTypeNameList,
    setCostExpenseTypeNameList,
    bankAccountList,
    setBankAccountList,
    dataDictNameList,
    setDataDictNameList,
    saleOpportunityNameList,
    setSaleOpportunityNameList,
    saleContractNameList,
    setSaleContractNameList,
    goodsCategoryNameList,
    setGoodsCategoryNameList
  }
})

export default useCommonStore
