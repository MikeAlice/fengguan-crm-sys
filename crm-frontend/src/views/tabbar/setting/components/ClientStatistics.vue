<template>
  <div class="boxs">
    <CustomDataPie :getData="getDatas"></CustomDataPie>
  </div>
</template>

<script setup>
import { onMounted } from 'vue'
import useMessageInfo from '@/stores/system-page/messageInfo.js'
import CustomDataPie from '@/components/customDataPie/CustomDataPie.vue'

const messageInfo = useMessageInfo()

onMounted(() => {})

const getDatas = (time = 1) => {
  let datas = {
    title: '统计客户数量',
    customers: [],
    amount: []
  }
  let levelName = []
  let levelNum = []
  let industryName = []
  let industryNum = []
  let belongName = []
  let belongNum = []
  switch (time) {
    case 1:
      messageInfo.level.forEach((item) => {
        levelName.push(item.statisticsName)
        levelNum.push(item.statisticsNumber)
      })
      datas.title = '根据客户等级统计数量'
      datas.customers = levelName
      datas.amount = levelNum
      break
    case 2:
      messageInfo.industry.forEach((item) => {
        industryName.push(item.statisticsName)
        industryNum.push(item.statisticsNumber)
      })
      datas.title = '根据客户行业统计数量'
      datas.customers = industryName
      datas.amount = industryNum
      break
    case 3:
      messageInfo.belong.forEach((item) => {
        belongName.push(item.statisticsName)
        belongNum.push(item.statisticsNumber)
      })
      datas.title = '根据客户来源统计数量'
      datas.customers = belongName
      datas.amount = belongNum
      break
    case 4:
      datas.title = '我的客户总数量'
      datas.customers = [messageInfo.customerNum.statisticsName]
      datas.amount = [messageInfo.customerNum.statisticsNumber]
      break
  }
  levelName = []
  levelNum = []
  industryName = []
  industryNum = []
  belongName = []
  belongNum = []
  return datas
}
</script>

<style lang="scss" scoped>
.boxs {
  display: inline-block;
  width: 40vw;
  height: 70vh;
}
</style>
