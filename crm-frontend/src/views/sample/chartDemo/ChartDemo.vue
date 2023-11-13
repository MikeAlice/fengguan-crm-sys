/* * @Author: seven * @Date: 2023-10-21 22:24:45 * @Last Modified by: seven *
@Last Modified time: 2023-10-21 22:24:45 */

<template>
  <div>
    <SalesKit :getData="getData" style="margin-bottom: 2%"></SalesKit>
    <SalesBoard :getData="getDatas"></SalesBoard>
  </div>
</template>

<script setup>
import SalesKit from '@/components/chartStatistics/salesManagement/SalesKit.vue'
import SalesBoard from '@/components/chartStatistics/salesManagement/SalesBoard.vue'
const getData = (timePick = '本周') => {
  let chartData = {}
  switch (timePick) {
    case '本周':
      chartData.contractsNum = [25, 53, 23, 64, 67, 56, 81]
      chartData.amount = [
        100000, 120000, 430000, 590000, 690000, 280000, 810000
      ]
      break
    case '上周':
      chartData.contractsNum = [31, 23, 35, 63, 34, 71, 12]
      chartData.amount = [
        210000, 230000, 520000, 630000, 360000, 320000, 620000
      ]
      break
    case '本月':
      chartData.contractsNum = [35, 63, 37, 72]
      chartData.amount = [120000, 110000, 530000, 590000]
      break
    case '上月':
      chartData.contractsNum = [41, 53, 13, 72]
      chartData.amount = [100000, 120000, 430000, 410000]
      break
    case '本季度':
      chartData.contractsNum = [31, 23, 54]
      chartData.amount = [120000, 140000, 233000]
      break
    case '上季度':
      chartData.contractsNum = [24, 41, 32]
      chartData.amount = [410000, 230000, 220000]
      break
    case '本年':
      chartData.contractsNum = [31, 25, 41, 14]
      chartData.amount = [120000, 140000, 233000, 123000]
      break
    case '上年':
      chartData.contractsNum = [41, 53, 23, 64]
      chartData.amount = [100000, 120000, 430000, 410000]
      break

    default:
  }

  return chartData
}

const getDatas = (timePick = '本周') => {
  // 获取销售人员及其对应的销售额的数据
  let chartData = {}
  switch (timePick) {
    case '本周':
      chartData.data = [
        100000, 120000, 430000, 590000, 690000, 280000, 810000, 780000, 833000,
        910000
      ]

      // [
      //   [100000, 'A销售员'],
      //   [120000, 'B销售员'],
      //   [430000, 'C销售员'],
      //   [590000, 'D销售员'],
      //   [690000, 'E销售员'],
      //   [280000, 'F销售员'],
      //   [810000, 'G销售员'],
      //   [780000, 'H销售员'],
      //   [833000, 'I销售员'],
      //   [910000, 'J销售员']
      // ]
      chartData.salesman = [
        'J销售员',
        'I销售员',
        'H销售员',
        'G销售员',
        'F销售员',
        'E销售员',
        'D销售员',
        'C销售员',
        'B销售员',
        'A销售员'
      ]
      // chartData = chartData.data.map((e, i) => [e, chartData.salesman[i]])
      break
    case '上周':
      chartData.data = [
        210000, 230000, 520000, 630000, 360000, 320000, 620000, 330000, 780000,
        833000
      ]
      chartData.salesman = [
        'J销售员',
        'I销售员',
        'H销售员',
        'G销售员',
        'F销售员',
        'E销售员',
        'D销售员',
        'C销售员',
        'B销售员',
        'A销售员'
      ]
      break
    case '本月':
      chartData.data = [
        210000, 230000, 520000, 630000, 410000, 230000, 210000, 420000, 320000,
        620000
      ]
      chartData.salesman = [
        'J销售员',
        'I销售员',
        'H销售员',
        'G销售员',
        'F销售员',
        'E销售员',
        'D销售员',
        'C销售员',
        'B销售员',
        'A销售员'
      ]
      break
    case '上月':
      chartData.data = [
        100000, 120000, 430000, 410000, 230000, 210000, 420000, 190000, 580000,
        280000
      ]
      chartData.salesman = [
        'J销售员',
        'I销售员',
        'H销售员',
        'G销售员',
        'F销售员',
        'E销售员',
        'D销售员',
        'C销售员',
        'B销售员',
        'A销售员'
      ]
      break
    case '本季度':
      chartData.data = [
        120000, 140000, 233000, 100000, 120000, 430000, 410000, 230000, 210000,
        420000
      ]
      chartData.salesman = [
        'J销售员',
        'I销售员',
        'H销售员',
        'G销售员',
        'F销售员',
        'E销售员',
        'D销售员',
        'C销售员',
        'B销售员',
        'A销售员'
      ]
      break
    case '上季度':
      chartData.data = [
        410000, 230000, 220000, 230000, 520000, 630000, 360000, 320000, 620000,
        833000
      ]
      chartData.salesman = [
        'J销售员',
        'I销售员',
        'H销售员',
        'G销售员',
        'F销售员',
        'E销售员',
        'D销售员',
        'C销售员',
        'B销售员',
        'A销售员'
      ]
      break
    case '本年':
      chartData.data = [
        120000, 140000, 233000, 123000, 140000, 233000, 100000, 120000, 430000,
        410000
      ]
      chartData.salesman = [
        'J销售员',
        'I销售员',
        'H销售员',
        'G销售员',
        'F销售员',
        'E销售员',
        'D销售员',
        'C销售员',
        'B销售员',
        'A销售员'
      ]
      break
    case '上年':
      chartData.data = [
        100000, 120000, 430000, 410000, 130000, 770000, 420000, 590000, 690000,
        280000
      ]
      chartData.salesman = [
        'J销售员',
        'I销售员',
        'H销售员',
        'G销售员',
        'F销售员',
        'E销售员',
        'D销售员',
        'C销售员',
        'B销售员',
        'A销售员'
      ]
      break

    default:
  }

  return chartData
}
</script>

<style lang="scss" scoped></style>
