import { defineStore } from 'pinia'
import { ref } from 'vue'
import { postCustomer } from '@/apis/customer/index.js'

const useMyClient = defineStore('myClient', () => {
  // 表格数据
  let tableData = ref([])
  // 初始化tableData
  const gettableData = (data = []) => {
    tableData.value = data
  }

  // 存放添加或修改的客户信息
  let customerInfo = ref({
    id: '',
    name: '',
    belong: '',
    level: '',
    industry: '',
    tel: '',
    mobile: '',
    address: '',
    intro: '',
    demand: '',
    seaCustomer: false
  })
  // 新增客户信息
  const addNewCustomer = async () => {
    await postCustomer(customerInfo.value)
  }
  // 重置数据
  const customerReset = () => {
    customerInfo.value = {
      id: '',
      name: '',
      belong: '',
      level: '',
      industry: '',
      tel: '',
      mobile: '',
      address: '',
      intro: '',
      demand: '',
      seaCustomer: false
    }
  }

  // 存储联系人的数据
  let contactInfo = ref({
    id: '',
    name: '',
    gender: '',
    mobile: '',
    position: '',
    tel: '',
    qq: '',
    email: '',
    address: '',
    customerName: ''
  })
  // 重置数据
  const contactReset = () => {
    contactInfo.value = {
      id: '',
      name: '',
      gender: '',
      mobile: '',
      position: '',
      tel: '',
      qq: '',
      email: '',
      address: '',
      customerName: ''
    }
  }

  // 联系人表格数据
  let linksTableData = ref([])
  const getLinksTableData = (data = []) => {
    linksTableData.value = data
  }

  // 存放添加沟通记录的数据
  let communicateInfo = ref({
    id: '',
    customerName: '', //客户名称
    contact: '', //客户联系人
    opportnity: '', //客户销售机会
    satge: '', //当前阶段
    way: '', //沟通方式
    data: '', //沟通日期（具体到天）
    time: '', //沟通时间（具体到秒）
    content: '', //联系内容
    nextData: '', //下次沟通日期（具体到天）
    nextTime: '' //下次沟通时间（具体到秒）
  })
  // 重置数据
  const communicateReset = () => {
    communicateInfo.value = {
      id: '',
      customerName: '',
      contact: '',
      opportnity: '',
      satge: '',
      way: '',
      data: '',
      time: '',
      content: '',
      nextData: '',
      nextTime: ''
    }
  }

  // 存放添加服务记录的数据
  let serviceInfo = ref({
    id: '',
    type: '',
    way: '',
    data: '',
    spendTime: '',
    content: '',
    customerName: ''
  })

  // 重置数据
  const serviceReset = () => {
    serviceInfo.value = {
      id: '',
      type: '',
      way: '',
      data: '',
      spendTime: '',
      content: '',
      customerName: ''
    }
  }

  // 存放添加销售机会的数据
  let opportunityInfo = ref({
    id: '',
    theme: '', //主题
    customerName: '', //客户名称
    contact: '', //客户联系人
    stage: '', //当前阶段
    data: '', //发现日期
    preData: '', //预签订日期
    price: '', //金额
    intro: '' //介绍
  })
  // 重置数据
  const opportunityReset = () => {
    opportunityInfo.value = {
      id: '',
      theme: '',
      customerName: '',
      contact: '',
      stage: '',
      data: '',
      preData: '',
      price: '',
      intro: ''
    }
  }

  // 合同详情
  let contractInfo = {
    id: '',
    theme: '',
    customerName: '',
    contact: '',
    opportnity: '',
    data: '',
    endData: '',
    price: '',
    intro: '',
    represent: ''
  }
  // 重置数据
  const contractReset = () => {
    contractInfo.value = {
      id: '',
      theme: '',
      customerName: '',
      contact: '',
      opportnity: '',
      data: '',
      endData: '',
      price: '',
      intro: '',
      represent: ''
    }
  }

  return {
    tableData,
    gettableData,
    customerInfo,
    addNewCustomer,
    customerReset,
    contactInfo,
    contactReset,
    linksTableData,
    getLinksTableData,
    communicateInfo,
    communicateReset,
    serviceInfo,
    serviceReset,
    opportunityInfo,
    opportunityReset,
    contractInfo,
    contractReset
  }
})

export default useMyClient
