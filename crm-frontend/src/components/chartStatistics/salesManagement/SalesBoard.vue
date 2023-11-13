<template>
  <!-- 销售管理的div标签 -->
  <div class="salesBoard">
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
    <!-- 下面几项为测试数组 -->
    <!-- <div>
      <p>{{ a }}</p>
      <p>{{ b }}</p>
      <p>{{ c }}</p>
    </div> -->
    <div class="chartBox" ref="chartBox"></div>
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
  // console.log(result.value)
  // 初始化图表
  initChart()
})
// 用来接收下拉框的选项变更时返回的开始时间和结束时间
let result = ref([])

// 图表数据 (目前使用的是写死的数据,监听器检测到选择框变化时，这里的数据会去调用新数据)
let chartData = ref({
  // 合同个数
  data: [100000, 90000, 79000, 69000, 60000, 50000, 46000, 40000, 34000, 30000]
})

// 用来获取排序后的数组数据  测试中
// let sortData = reactive(chartData.value)
// 获取绑定的dom元素
let chartBox = ref()

// 挂载时显示图表
onMounted(() => {
  // 表格数据重新赋值
  chartData.value = props.getData()
  // 初始化图表
  initChart()
})

// 初始化图表
let initChart = () => {
  // 初始化图表
  let myEchart = echarts.init(chartBox.value)

  let option = {
    // 主标题设置
    title: {
      // 主标题文本
      text: '销售榜',
      textStyle: {
        fontWeight: 'bolder',
        fontSize: 20
      }
    },
    // 图例组件
    legend: {
      show: true,
      top: '3%',
      textStyle: {
        fontSize: 15
      }
    },
    // 修改坐标系显示大小
    grid: {
      top: '18%',
      left: '1%',
      bottom: 0,

      containLabel: true
    },
    tooltip: {
      show: true
    },
    // x轴
    xAxis: {
      name: '销售金额/元',
      nameTextStyle: {
        fontSize: 15
      },
      type: 'value',
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
      // 刻度线指示器 用来显示实时数值
      axisPointer: {
        show: true
      },
      axisLabel: {
        showMaxLabel: true,
        showMinLabel: true,
        margin: 8,
        fontWeight: 'normal',
        fontSize: 15,
        align: 'center'
      },
      // 坐标轴标签
      axisLine: {
        show: true
      },
      axisTick: {
        alignWithLabel: true,
        show: true
      }
      // 横坐标展示时间
    },
    // y轴
    yAxis: [
      {
        type: 'category',
        //
        axisTick: {
          show: true
        },
        axisPointer: {
          show: true
        },
        name: '销售员',
        nameTextStyle: {
          fontSize: 15
        },
        axisLine: {
          show: true
        },
        // 刻度标签
        axisLabel: {
          show: true,
          align: 'center',
          margin: 60,
          fontSize: 15
        },
        data: chartData.value.salesman
      }
    ],
    // 系列
    series: [
      {
        name: '销售金额',
        // bar 表示是柱状图
        type: 'bar',
        smooth: true,

        itemStyle: {
          // 各个柱形图颜色
          color: '#FFAA1D'
        },

        // 对应轴线的数据
        data: chartData.value.data.sort(function (a, b) {
          return a - b
        })
      }
    ]
  }

  myEchart.setOption(option)
}
</script>

<style scoped>
.salesBoard {
  width: 1200px;
  height: 600px;
}
/* 图表样式 */
.chartBox {
  margin-left: 2%;
  width: 1000px;
  height: 500px;
}
.chartCheckBox {
  margin-left: 900px;
  margin-right: 0;
}
</style>
