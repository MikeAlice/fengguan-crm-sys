<template>
  <CustomDataStatistics
    :getData="getData"
    style="margin-right: 10%"
  ></CustomDataStatistics>
</template>

<script setup>
import { onMounted } from 'vue'
import {
  countBusinessMoney,
  countBusinessNumber,
  countBusinessSalestage,
  countBusinessSuccessrate
} from '@/apis/systemPage/index.js'
import CustomDataStatistics from '@/components/customDataStatistics/CustomDataStatistics.vue'
import useMessageInfo from '@/stores/system-page/messageInfo.js'

const messageInfo = useMessageInfo()

onMounted(() => {
  countBusinessMoney(20, 60, (response) => {
    console.log(response)
  })
  countBusinessNumber((response) => {
    console.log(response)
  })
  countBusinessSalestage((response) => {
    console.log(response)
  })
  countBusinessSuccessrate(20, 60, (response) => {
    console.log(response)
  })
})

const getData = (time = 1) => {
  let data = {
    title: '数据统计',
    x: []
  }
  let xs = []
  let amount = []
  switch (time) {
    case 1:
      messageInfo.states.forEach((item) => {
        xs.push(item.statisticsName)
        amount.push(item.statisticsNumber)
      })
      data.title = '根据销售状态统计商机数量'
      data.x = xs
      data.amount = amount
      break
    case 2:
      data.title = '商机总数量'
      data.x = [messageInfo.busNum.statisticsName]
      data.amount = [messageInfo.busNum.statisticsNumber]
      break
  }
  return data
}
</script>

<style lang="scss" scoped>
.box {
  display: inline-block;
  width: 100%;
  height: 100%;
  .select {
    margin-left: 60%;
    right: 0;
  }
  .charts {
    width: 45vw;
    height: 60vh;
  }
}
</style>
