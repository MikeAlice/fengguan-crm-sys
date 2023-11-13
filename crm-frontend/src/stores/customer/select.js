import { defineStore } from 'pinia'
import { ref } from 'vue'

const useSelect = defineStore('select', () => {
  // 客户名称下拉列表
  let name = ref('')
  // 设置客户名称
  const setName = (data) => {
    name.value = data
  }

  // 客户联系人下拉列表
  let contacts = ref('')
  // 设置客户联系人
  const setContacts = (data) => {
    contacts.value = data
  }

  // 客户归属下拉列表
  let belong = ref('')
  // 设置客户归属
  const setBelong = (data) => {
    belong.value = data
  }

  // 客户等级下拉列表
  let level = ref('')
  // 设置客户等级
  const setLevel = (data) => {
    level.value = data
  }

  // 客户行业下拉列表
  let industy = ref('')
  // 设置客户行业
  const setIndusty = (data) => {
    industy.value = data
  }

  // 客户销售机会列表
  let opportnity = ref('')
  // 设置销售机会
  const setOpportnity = (data) => {
    opportnity.value = data
  }

  // 沟通方式列表
  let way = ref('')
  // 设置沟通方式
  const setWay = (data) => {
    way.value = data
  }

  // 当前阶段列表
  let stage = ref('')
  // 设置当前阶段
  const setStage = (data) => {
    stage.value = data
  }

  // 服务方式列表
  let serviceWay = ref('')
  // 设置服务方式
  const setServiceWay = (data) => {
    serviceWay.value = data
  }

  // 服务类型列表
  let serviceType = ref('')
  // 设置服务类型
  const setServiceType = (data) => {
    serviceType.value = data
  }

  // 我方代表列表
  let represent = ref('')
  // 设置我方代表
  const setRepresent = (data) => {
    represent.value = data
  }

  const resetData = () => {
    ;(name.value = ''),
      (belong.value = ''),
      (level.value = ''),
      (opportnity.value = ''),
      (stage.value = ''),
      (way.value = ''),
      (contacts.value = ''),
      (serviceWay.value = ''),
      (serviceType.value = ''),
      (represent.value = ''),
      (industy.value = '')
  }

  return {
    name,
    belong,
    level,
    opportnity,
    stage,
    way,
    contacts,
    setContacts,
    setName,
    setBelong,
    setLevel,
    setOpportnity,
    setStage,
    setWay,
    serviceWay,
    setServiceWay,
    serviceType,
    setServiceType,
    represent,
    setRepresent,
    industy,
    setIndusty,
    resetData
  }
})

export default useSelect
