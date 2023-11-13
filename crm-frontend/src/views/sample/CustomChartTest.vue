<template>
  <CustomDataStatistics
    :getData="getData"
    style="margin-right: 10%"
  ></CustomDataStatistics>
  <CustomDataPie :getData="getDatas"></CustomDataPie>
</template>

<script setup>
import CustomDataStatistics from '@/components/customDataStatistics/CustomDataStatistics.vue'
import CustomDataPie from '@/components/customDataPie/CustomDataPie.vue'
const getData = (time = 1) => {
  let data = { title: '客户数据统计', x: ['我的客户', '下属客户', '公海客户'] }
  switch (time) {
    case 1:
      data.contractsNumber = [3, 2, 1]
      data.amount = [0.45, 0.48, 0.79]
      break
    case 2:
      data.contractsNumber = [6, 3, 3]
      data.amount = [1.75, 1.03, 0.89]
      break
    case 7:
      data.contractsNumber = [16, 9, 7]
      data.amount = [5.78, 9.78, 6.54]
      break
    case 30:
      data.contractsNumber = [34, 25, 9]
      data.amount = [30.79, 20.45, 10.56]
      break
    case 90:
      data.contractsNumber = [89, 35, 54]
      data.amount = [146.78, 64.75, 95.98]
      break
    case 365:
      data.contractsNumber = [240, 110, 130]
      data.amount = [357.154, 294.16, 156.578]
      break
  }
  return data
}
const getDatas = (time = 1) => {
  let datas = {
    title: '预计签单客户合同金额',
    customers: ['甲', '乙', '丙', '丁', '其他']
  }
  switch (time) {
    case 1:
      datas.amount = [29, 75, 61, 37, 10]
      break
    case 2:
      datas.amount = [57.65, 59.17, 56.89, 102.15, 42.12]
      break
    case 7:
      datas.amount = [124.69, 265.15, 133.14, 78.45, 35.45]
      break
    case 30:
      datas.amount = [356.12, 549.21, 365.21, 129.56, 78.98]
      break
    case 90:
      datas.amount = [785.65, 984.321, 557.68, 459.68, 256.12]
      break
    case 365:
      datas.amount = [1298.65, 1863.145, 1779.14, 1682.14, 586.35]
      break
  }
  return datas
}
</script>

<style lang="css" scoped>
.contain {
  text-align: center;
  padding: 20%;
}
.code {
  font-size: xxx-large;
  font-weight: bold;
  color: #222222;
}
.info {
  font-weight: bold;
  color: dimgray;
}
</style>
