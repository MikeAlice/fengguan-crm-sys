import { defineStore } from 'pinia'
import { ref } from 'vue'
import { postCustomer } from '@/apis/customer/index.js'

const useSeasClient = defineStore('seasClient', () => {
  const total = ref(0)
  // 表格数据
  let tableData = ref([])
  // 初始化tableData
  const gettableData = (data = []) => {
    tableData.value = data
  }

  // 存放添加或修改的客户信息
  let customerInfo = ref({
    customer_id: '',
    name: '',
    source: '',
    grade: '',
    industry: '',
    tel: '',
    mobile: '',
    address: '',
    intro: '',
    needs: '',
    seaCustomer: true
  })
  // 新增客户信息
  const addNewCustomer = async () => {
    await postCustomer(customerInfo.value)
  }
  // 重置数据
  const customerReset = () => {
    customerInfo.value = {
      customer_id: '',
      name: '',
      source: '',
      grade: '',
      industry: '',
      tel: '',
      mobile: '',
      address: '',
      intro: '',
      needs: '',
      seaCustomer: true
    }
  }

  // 存储联系人的数据
  let contactInfo = ref({
    linkman_id: -1, //联系人ID
    customer_id: '', //客户ID
    customerName: '', //客户名称
    linkman_name: '', //联系人名称
    gender: 0, //联系人性别 1=男，0=女
    postion: '', //联系人职位
    tel: '', //联系人座机
    mobile: '', //联系人手机
    qicq: '', //联系人QQ
    email: '', //联系人邮箱
    address: '' //联系人地址
  })
  // 重置数据
  const contactReset = () => {
    contactInfo.value = {
      linkman_id: -1, //联系人ID
      customer_id: '', //客户ID
      customerName: '', //客户名称
      linkman_name: '', //联系人名称
      gender: 0, //联系人性别 1=男，0=女
      postion: '', //联系人职位
      tel: '', //联系人座机
      mobile: '', //联系人手机
      qicq: '', //联系人QQ
      email: '', //联系人邮箱
      address: '' //联系人地址
    }
  }

  const total1 = ref(0)
  // 联系人表格数据
  let linksTableData = ref([])
  const getLinksTableData = (data = []) => {
    linksTableData.value = data
  }

  // 存放添加沟通记录的数据
  let communicateInfo = ref({
    customer_id: '',
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
      customer_id: '',
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
    customer_id: '', // 客户id
    linkman_id: '', //联系人id
    services: '', // 服务类型
    servicesmodel: '', //服务方式
    price: '', // 价格
    status: '', //服务记录状态 1=无需处理，2未处理，3=处理中，4处理完成
    service_time: '', // 服务日期
    tlen: 0, //服务时长
    content: '', //服务内容
    intro: '', //备注
    customer_name: '', //客户姓名
    linkman_name: '' //联系人姓名
  })

  // 重置数据
  const serviceReset = () => {
    serviceInfo.value = {
      customer_id: '', // 客户id
      linkman_id: '', //联系人id
      services: '', // 服务类型
      servicesmodel: '', //服务方式
      price: '', // 价格
      status: '', //服务记录状态 1=无需处理，2未处理，3=处理中，4处理完成
      service_time: '', // 服务日期
      tlen: 0, //服务时长
      content: '', //服务内容
      intro: '', //备注
      customer_name: '', //客户姓名
      linkman_name: '' //联系人姓名
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
    total,
    tableData,
    gettableData,
    customerInfo,
    addNewCustomer,
    customerReset,
    contactInfo,
    contactReset,
    total1,
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

export default useSeasClient
