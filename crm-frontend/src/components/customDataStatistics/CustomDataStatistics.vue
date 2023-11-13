<template>
  <div class="box">
    <el-select v-model="time" class="select" placeholder="请选择时间">
      <el-option
        v-for="item in options"
        :key="item.value"
        :label="item.label"
        :value="item.value"
      />
    </el-select>
    <div class="charts" ref="charts"></div>
  </div>
</template>

<script setup>
import { ref, onMounted, watch } from 'vue'
import * as echarts from 'echarts'
/**
 * 组件使用：
 *    <CustomDataStatistics :getData="getData"></CustomDataStatistics>
 * 传入数据父向子传递)：
 *    // time表示时间范围，根据时间范围向后端发送请求获取相应的数据，time默认为1
 *    const getData = (time = 1) = {
 *      // data数据样式
 *      let data = {
 *        title: '', //图表标题
 *        x: ['我的客户', '下属客户', '公海客户'] //x轴参数，默认为['我的客户', '下属客户', '公海客户']
 *        contractsNumber: [] // 合同数
 *        amount: [] //总金额数
 *      }
 *      // 网络请求获取数据
 *      // 将数据存到pinia
 *      // 从pinia里面拿到数据
 *      return data
 *    }
 *  传出数据(子向父传递)：无
 */

let props = defineProps({
  // 获取图表所需数据
  getData: {
    type: Function,
    require: true,
    default: (time = 1) => {
      console.log(time)
    }
  }
})

// 图表数据
let data = ref({
  title: '数据统计',
  x: ['我的客户', '下属客户', '公海客户'],
  amount: [0, 0, 0]
})

let charts = ref()

onMounted(() => {
  data.value = props.getData()
  initData()
})

// 初始化数据列表
let initData = () => {
  let mychart = echarts.init(charts.value)
  //设置配置项
  let option = {
    title: {
      text: data.value.title,
      show: true
    },
    tooltip: {
      trigger: 'axis',
      axisPointer: { type: 'cross' }
    },
    xAxis: {
      type: 'category',
      axisTick: {
        alignWithLabel: true
      },
      data: data.value.x
    },
    yAxis: [
      {
        type: 'value',
        name: '合同个数',
        position: 'left',
        minInterval: 1,
        axisLabel: {
          formatter: '{value} 个'
        }
      }
    ],
    series: [
      {
        name: '合同数',
        type: 'bar',
        yAxisIndex: 0,
        data: data.value.amount,
        barWidth: 30,
        itemStyle: {
          normal: {
            //这里是重点
            color: function (params) {
              //注意，如果颜色太少的话，后面颜色不会自动循环，最好多定义几个颜色
              let colorList = [
                '#CD9786',
                '#AE7681',
                '#C8CDE1',
                '#B89D74',
                '#D1E8F2',
                '#DAC9BD',
                '#C67D6E'
              ]
              return colorList[params.dataIndex]
            }
          }
        }
      }
    ]
  }
  mychart.setOption(option)
}

let time = ref('销售状态')

// 下拉框选项
const options = [
  {
    value: 1,
    label: '销售状态'
  },
  {
    value: 2,
    label: '商机总数'
  }
]

// 监听数据变化，重绘图表
watch(data, () => {
  initData()
})
// 监听时间变化
watch(time, () => {
  // 选择的时间变化，根据时间重新获取数据
  data.value = props.getData(time.value)
})
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
    width: 700px;
    height: 400px;
  }
}
</style>
