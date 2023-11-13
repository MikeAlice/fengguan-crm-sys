import { defineStore } from 'pinia'
import { ref } from 'vue'

const useMessageInfo = defineStore('messageInfo', () => {
  const messageInfo = ref([
    // {
    //   id: '', //消息id
    //   msgTitle: '', //消息标题
    //   message: '', //消息内容
    //   msgType: '', //消息类型
    //   urlId: 0, //跳转链接
    //   urlType: '', //链接类型
    //   remindTime: '', // 提醒时间
    //   flag: '' // 消息状态，是否已读
    // }
  ])
  const index = ref(0)

  const setIndex = (data = 0) => {
    index.value = data
  }

  // 设置消息内容
  const setMessageInfo = (data = []) => {
    messageInfo.value = data
  }

  // 根据客户等级统计数量
  const level = ref([])
  const setLevel = (data = []) => {
    level.value = data
  }

  // 根据客户行业统计数量
  const industry = ref([])
  const setIndustry = (data = []) => {
    industry.value = data
  }

  // 根据客户等级统计数量
  const customerNum = ref([])
  const setCustomerNum = (data = []) => {
    customerNum.value = data
  }

  // 根据客户等级统计数量
  const belong = ref([])
  const setBelong = (data = []) => {
    belong.value = data
  }

  // 根据销售状态分类统计商机数量
  const states = ref([])
  const setStates = (data = []) => {
    states.value = data
  }

  // 商机总数
  const busNum = ref({})
  const setBusNum = (data) => {
    busNum.value = data
  }

  // 根据商机预计销售额统计商机数量
  const countMoney = ref([])
  const setCountMoney = (data = []) => {
    countMoney.value = data
  }

  // 根据商机预计销售额统计商机数量
  const countSucc = ref([])
  const setCountSucc = (data = []) => {
    countSucc.value = data
  }

  return {
    messageInfo,
    setMessageInfo,
    index,
    setIndex,
    level,
    setLevel,
    industry,
    setIndustry,
    customerNum,
    setCustomerNum,
    belong,
    setBelong,
    states,
    setStates,
    busNum,
    setBusNum,
    countMoney,
    setCountMoney,
    countSucc,
    setCountSucc
  }
})

export default useMessageInfo
