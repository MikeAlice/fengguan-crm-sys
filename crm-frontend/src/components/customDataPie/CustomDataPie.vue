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
 *    <CustomDataPie :getDatas="getDatas"></CustomDataPie>
 * 传入数据父向子传递)：
 *    // time表示时间范围，根据时间范围向后端发送请求获取相应的数据，time默认为1
 *    const getDatas = (time = 1) = {
 *      // data数据样式
 *      let data = {
 *        title: '', //图表标题
 *        ustomers: ['甲', '乙', '丙', '丁', '其他'], //x轴参数，为具体客户
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
  customers: ['甲', '乙', '丙', '丁', '其他'],
  amount: [18, 25, 20, 26, 17]
})

let charts = ref()

onMounted(() => {
  data.value = props.getData(1)
  initData()
})

// 初始化数据列表
let initData = () => {
  let mychart = echarts.init(charts.value)
  //设置配置项
  let option = {
    title: {
      text: data.value.title,
      left: 'center'
    },
    legend: {
      orient: 'vertical',
      x: 'left',
      data: data.value.customers
    },
    series: [
      {
        type: 'pie',
        radius: '60%', //大小
        center: ['50%', '50%'],
        avoidLabelOverlap: false,
        label: {
          show: false,
          position: 'center'
        },
        labelLine: {
          show: false
        },
        emphasis: {
          label: {
            show: true,
            fontSize: '18',
            fontWeight: 'bold'
          }
        },
        data: [
          { value: data.value.amount[0], name: data.value.customers[0] },
          { value: data.value.amount[1], name: data.value.customers[1] },
          { value: data.value.amount[2], name: data.value.customers[2] },
          { value: data.value.amount[3], name: data.value.customers[3] },
          { value: data.value.amount[4], name: data.value.customers[4] }
        ],
        itemStyle: {
          normal: {
            label: {
              show: true,
              formatter: '{b}:{c}'
            },
            labelLine: {
              show: true,
              smooth: 0.2,
              length: 10,
              length2: 20
            },
            color: function (colors) {
              var colorList = [
                '#97BFC4',
                '#DAC9BD',
                '#C67D6E',
                '#93708C',
                '#BFCFE9',
                '#F2BB9F',
                '#EA9761',
                '#BE6377',
                '#E0D0C9',
                '#936260',
                '#A48398'
              ]
              return colorList[colors.dataIndex]
            }
          }
        }
      },
      {
        type: 'pie',
        radius: '60%', //大小
        center: ['50%', '50%'],
        avoidLabelOverlap: false,
        label: {
          show: false,
          position: 'center'
        },
        labelLine: {
          show: false
        },
        emphasis: {
          label: {
            show: true,
            fontSize: '16',
            fontWeight: 'bold'
          }
        },
        data: [
          { value: data.value.amount[0], name: data.value.customers[0] },
          { value: data.value.amount[1], name: data.value.customers[1] },
          { value: data.value.amount[2], name: data.value.customers[2] },
          { value: data.value.amount[3], name: data.value.customers[3] },
          { value: data.value.amount[4], name: data.value.customers[4] }
        ],
        itemStyle: {
          normal: {
            label: {
              show: true,
              position: 'inner',
              formatter: '{d}%'
            },
            labelLine: {
              show: true,
              smooth: 0.2,
              length: 10,
              length2: 20
            },
            color: function (colors) {
              var colorList = [
                '#97BFC4',
                '#DAC9BD',
                '#C67D6E',
                '#93708C',
                '#BFCFE9',
                '#F2BB9F',
                '#EA9761',
                '#BE6377',
                '#E0D0C9',
                '#936260',
                '#A48398'
              ]
              return colorList[colors.dataIndex]
            }
          }
        }
      }
    ]
  }
  mychart.setOption(option)
}

const time = ref('客户等级')

// 下拉框选项
const options = [
  {
    value: 1,
    label: '客户等级'
  },
  {
    value: 2,
    label: '客户行业'
  },
  {
    value: 3,
    label: '客户来源'
  },
  {
    value: 4,
    label: '我的客户总数'
  }
]

// 数据改变，重绘图表
watch(data, () => {
  // 初始化图表
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
    margin-top: 10%;
    width: 600px;
    height: 400px;
  }
}
</style>
