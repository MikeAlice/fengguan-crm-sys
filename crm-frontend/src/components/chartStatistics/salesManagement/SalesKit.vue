<!-- 销售管理 数量统计 -->

<template>
  <!-- 销售管理的div标签 -->
  <div class="salesKit">
    <el-row>
      <el-select
        class="chartCheckBox"
        v-model="timePick"
        placeholder="请选择时间范围"
      >
        <el-option
          v-for="item in options"
          :key="item.value"
          :label="item.label"
          :value="item.value"
        >
        </el-option>
      </el-select>
    </el-row>
    <div class="chart" ref="chartRef"></div>
  </div>
</template>

<script setup>
// 局部引入echarts
import * as echarts from 'echarts'
import { onMounted, ref, watch } from 'vue'
import dayjs from 'dayjs'
import quarterOfYear from 'dayjs/plugin/quarterOfYear'
//day.js年份插件
dayjs.extend(quarterOfYear)

// 相应时间返回的方法
function timeSpan() {
  let start = ''
  let end = ''

  switch (timePick.value) {
    case '本年':
      start = dayjs().startOf('year').format('YYYY-MM-DD')
      end = dayjs().endOf('year').format('YYYY-MM-DD')
      break
    case '上年':
      start = dayjs().add(-1, 'year').startOf('year').format('YYYY-MM-DD')
      end = dayjs().add(-1, 'year').endOf('year').format('YYYY-MM-DD')
      break
    case '下年':
      start = dayjs().add(1, 'year').startOf('year').format('YYYY-MM-DD')
      end = dayjs().add(1, 'year').endOf('year').format('YYYY-MM-DD')
      break
    case '上半年':
      start = dayjs().startOf('year').format('YYYY-MM-DD')
      end = dayjs().endOf('year').subtract(6, 'month').format('YYYY-MM-DD')
      break
    case '下半年':
      start = dayjs().startOf('year').add(6, 'month').format('YYYY-MM-DD')
      end = dayjs().endOf('year').format('YYYY-MM-DD')
      break
    case '本季度':
      start = dayjs().startOf('quarter').format('YYYY-MM-DD')
      end = dayjs().endOf('quarter').format('YYYY-MM-DD')
      break
    case '上季度':
      start = dayjs().add(-1, 'quarter').startOf('quarter').format('YYYY-MM-DD')
      end = dayjs().add(-1, 'quarter').endOf('quarter').format('YYYY-MM-DD')
      break
    case '下季度':
      start = dayjs().add(1, 'quarter').startOf('quarter').format('YYYY-MM-DD')
      end = dayjs().add(1, 'quarter').endOf('quarter').format('YYYY-MM-DD')
      break
    case '本月':
      start = dayjs().startOf('month').format('YYYY-MM-DD')
      end = dayjs().endOf('month').format('YYYY-MM-DD')
      break
    case '上月':
      start = dayjs().add(-1, 'month').startOf('month').format('YYYY-MM-DD')
      end = dayjs().add(-1, 'month').endOf('month').format('YYYY-MM-DD')
      break
    case '下月':
      start = dayjs().add(1, 'month').startOf('month').format('YYYY-MM-DD')
      end = dayjs().add(1, 'month').endOf('month').format('YYYY-MM-DD')
      break
    case '本周':
      start = dayjs().startOf('week').add(1, 'day').format('YYYY-MM-DD')
      end = dayjs().endOf('week').add(1, 'day').format('YYYY-MM-DD')
      break
    case '上周':
      start = dayjs()
        .add(-1, 'week')
        .startOf('week')
        .add(1, 'day')
        .format('YYYY-MM-DD')
      end = dayjs()
        .add(-1, 'week')
        .endOf('week')
        .add(1, 'day')
        .format('YYYY-MM-DD')
      break
    case '下周':
      start = dayjs()
        .add(1, 'week')
        .startOf('week')
        .add(1, 'day')
        .format('YYYY-MM-DD')
      end = dayjs()
        .add(1, 'week')
        .endOf('week')
        .add(1, 'day')
        .format('YYYY-MM-DD')
      break
    case '今天':
      start = dayjs().format('YYYY-MM-DD')
      end = dayjs().format('YYYY-MM-DD')
      break
    case '昨天':
      start = dayjs().add(-1, 'day').format('YYYY-MM-DD')
      end = dayjs().add(-1, 'day').format('YYYY-MM-DD')
      break
    case '明天':
      start = dayjs().add(1, 'day').format('YYYY-MM-DD')
      end = dayjs().add(1, 'day').format('YYYY-MM-DD')
      break
    case '过去7天':
      start = dayjs().add(-7, 'day').format('YYYY-MM-DD')
      end = dayjs().format('YYYY-MM-DD')
      break
    case '过去30天':
      start = dayjs().add(-30, 'day').format('YYYY-MM-DD')
      end = dayjs().format('YYYY-MM-DD')
      break
    case '未来7天':
      start = dayjs().format('YYYY-MM-DD')
      end = dayjs().add(7, 'day').format('YYYY-MM-DD')
      break
    case '未来30天':
      start = dayjs().format('YYYY-MM-DD')
      end = dayjs().add(30, 'day').format('YYYY-MM-DD')
      break
    default:
  }
  return [start, end]
}

// 下拉选择框选项 分别为本周 上周 本月 上月等等

const options = [
  {
    value: '本周',
    label: '本周'
  },
  {
    value: '上周',
    label: '上周'
  },
  {
    value: '本月',
    label: '本月'
  },
  {
    value: '上月',
    label: '上月'
  },
  {
    value: '本季度',
    label: '本季度'
  },
  {
    value: '上季度',
    label: '上季度'
  },
  {
    value: '本年',
    label: '本年'
  },
  {
    value: '上年',
    label: '上年'
  }
]
// 父传子的方法
let props = defineProps({
  // 获取数据
  getData: {
    type: Function,
    required: true
  }
})

// 用户在下拉选择框选择的时间
let timePick = ref()

// 监听用户选择的时间
watch(timePick, () => {
  // 这里需要传入的是timePick.value 因为在定义getDate()这个函数的时候
  // 里面默认给的就是字符串形式
  chartData.value = props.getData(timePick.value)
  result.value = timeSpan()
  // 初始化图表
  initChart()
})
// 用来接收下拉框的选项变更时返回的开始时间和结束时间
let result = ref([])

// 横坐标时间计算的函数
function timeSetting() {
  console.log(result.value[0])
  let str = result.value[0]
  var dateList = []
  if (
    // 初始化或者本周，上周的时候显示七条数据
    timePick.value === '本周' ||
    timePick.value === '上周' ||
    timePick.value === undefined
  ) {
    // 循环遍历 未来七天或者过去七天的日期时间
    for (let i = 0; i < 7; i++) {
      let d1 = dayjs(str).add(i, 'day').format('MM-DD')
      dateList.push(d1)
    }
  } else if (timePick.value === '本月' || timePick.value === '上月') {
    dateList = ['第一周', '第二周', '第三周', '第四周']
  } else if (timePick.value === '本季度' || timePick.value === '上季度') {
    // dateList = ['第一周', '第二周', '第三周', '第四周']
    let start = dayjs(str).add(0, 'day').format('MM-DD').substring(0, 2)
    if (start === '01') {
      dateList = ['1月', '2月', '3月']
    } else if (start === '04') {
      dateList = ['4月', '5月', '6月']
    } else if (start === '07') {
      dateList = ['7月', '8月', '9月']
    } else if (start === '10') {
      dateList = ['10月', '11月', '12月']
    }
  } else if (timePick.value === '本年' || timePick.value === '上年') {
    dateList = ['第一季度', '第二季度', '第三季度', '第四季度']
  }

  return dateList
}

// 图表数据 (目前使用的是写死的数据,监听器检测到选择框变化时，这里的数据会去调用新数据)
let chartData = ref({
  // 合同个数
  contractsNum: [25, 43, 63, 58, 89, 100, 32],
  // 金额
  amount: [210000, 120000, 430000, 590000, 690000, 280000, 810000]
})
// 获取绑定的dom元素
let chartRef = ref()

// 挂载时显示图表
onMounted(() => {
  // 父组件是同级目录下的ParentData.vue
  chartData.value = props.getData()
  // 初始化图表
  initChart()
})

// 初始化图表
let initChart = () => {
  // 初始化图表
  let myEchart = echarts.init(chartRef.value)

  let option = {
    // 主标题设置
    title: {
      // 主标题文本
      text: '销售简报-新增数据统计',
      textStyle: {
        fontWeight: 'bolder',
        fontSize: 20
      }
    },
    // 图例组件
    legend: {
      show: true,
      top: 30,
      textStyle: {
        fontSize: 15
      }
    },
    // 修改坐标系显示大小
    grid: {
      top: '18%',
      left: '3%',
      right: '3%',
      bottom: 0,
      // height: 350,
      // width: 480,
      containLabel: true
    },
    tooltip: {
      show: true
    },
    // x轴
    xAxis: {
      type: 'category',
      // 刻度线指示器 用来显示实时数值
      axisPointer: {
        show: true
      },
      axisLabel: {
        showMaxLabel: true,
        showMinLabel: true,
        margin: 10,
        fontWeight: 'normal',
        fontSize: 15,
        align: 'center'
      },
      axisTick: {
        alignWithLabel: true
      },
      // 横坐标展示时间
      data: timeSetting()
    },
    // y轴
    yAxis: [
      // 左侧Y轴
      {
        type: 'value',
        // 最小时间间隔
        minInterval: 5,
        // 最大时间间隔
        maxInterval: 10,
        // 最小值
        min: 0,
        // 通过ceil函数来算得表中数据最大值向上十位取整的值作为刻度的最大值
        max: function formatRoundNum(num) {
          let integer = Math.ceil(num.max)
          let length = String(integer).length
          return (
            Math.ceil(integer / Math.pow(10, length - 1)) *
            Math.pow(10, length - 1)
          )
        },
        //
        axisTick: {
          show: true
        },
        axisPointer: {
          show: true
        },
        name: '个数',
        nameTextStyle: {
          fontSize: 15
        },
        axisLine: {
          show: true
        },
        // 刻度标签
        axisLabel: {
          show: true,
          // 单位以及刻度位置
          formatter: '{value} 个',
          align: 'center',
          margin: 50,
          showMaxLabel: true,
          showMinLabel: true,
          fontWeight: 'normal',
          fontSize: 15
        }
      },
      // 右侧Y轴
      {
        type: 'value',
        // 设置最小间隔
        minInterval: 5000,
        // 最大间隔
        maxInterval: 100000,
        min: 0,
        // 通过ceil函数来算得表中数据最大值向上十位取整的值作为刻度的最大值
        max: function formatRoundNum(num) {
          let integer = Math.ceil(num.max)
          // 这里需要把
          let length = String(integer).length
          return (
            Math.ceil(integer / Math.pow(10, length - 1)) *
            Math.pow(10, length - 1)
          )
        },

        // 标签指示器
        axisPointer: {
          show: true
        },
        name: '元(人民币)',
        nameTextStyle: {
          fontSize: 15
        },
        axisTick: {
          show: true
        },
        // 刻度标签
        axisLine: {
          show: true
        },
        axisLabel: {
          show: true,
          // 单位以及刻度位置
          formatter: '{value} 元',
          margin: 10,
          showMaxLabel: true,
          showMinLabel: true,
          fontWeight: 'normal',
          fontSize: 15
        }
      }
    ],
    // 系列
    series: [
      {
        name: '新增商机数',
        // bar 表示是柱状图
        type: 'bar',
        smooth: true,
        barWidth: '10%',
        itemStyle: {
          // 各个柱形图颜色
          color: function (params) {
            let colorList = [
              '#FFAA1D',
              '#FFAA1D',
              '#FFAA1D',
              '#FFAA1D',
              '#FFAA1D',
              '#FFAA1D',
              '#FFAA1D',
              '#FFAA1D'
            ]
            return colorList[params.dataIndex]
          }
        },
        yAxisIndex: 0,
        // 对应轴线的数据
        data: chartData.value.contractsNum
      },
      {
        name: '新增合同数',
        // bar 表示是柱状图
        type: 'bar',
        smooth: true,
        barWidth: '10%',
        itemStyle: {
          // 各个柱形图颜色
          color: function (params) {
            let colorList = [
              '#0000CD',
              '#0000CD',
              '#0000CD',
              '#0000CD',
              '#0000CD',
              '#0000CD',
              '#0000CD',
              '#0000CD'
            ]
            return colorList[params.dataIndex]
          }
        },
        yAxisIndex: 0,
        // 对应轴线的数据
        data: chartData.value.contractsNum
      },
      {
        name: '新增跟进记录数',
        // bar 表示是柱状图
        type: 'bar',
        smooth: true,
        barWidth: '10%',
        itemStyle: {
          // 各个柱形图颜色
          color: function (params) {
            let colorList = [
              '#E2062C',
              '#E2062C',
              '#E2062C',
              '#E2062C',
              '#E2062C',
              '#E2062C',
              '#E2062C',
              '#E2062C'
            ]
            return colorList[params.dataIndex]
          }
        },
        yAxisIndex: 0,
        // 对应轴线的数据
        data: chartData.value.contractsNum
      },
      {
        name: '新增联系人数',
        // bar 表示是柱状图
        type: 'bar',
        smooth: true,
        barWidth: '10%',
        itemStyle: {
          // 各个柱形图颜色, 每一行数据的颜色应该相同
          color: function (params) {
            let colorList = [
              '#39A78E',
              '#39A78E',
              '#39A78E',
              '#39A78E',
              '#39A78E',
              '#39A78E',
              '#39A78E'
            ]
            return colorList[params.dataIndex]
          }
        },
        yAxisIndex: 0,
        // 对应轴线的数据
        data: chartData.value.contractsNum
      },
      {
        name: '金额',
        // line 表示是折线图
        type: 'line',
        // color: '#B57EDC',
        yAxisIndex: 1,
        // 对应轴线的数据
        data: chartData.value.amount
      }
    ]
  }

  myEchart.setOption(option)
}
</script>

<style scoped>
.salesKit {
  width: 480;
  height: 500px;
}
/* 图表样式 */
.chart {
  margin-left: 2%;
  margin-right: 2%;
  width: 480;
  height: 500px;
}
.chartCheckBox {
  margin-left: 900px;
}
</style>
