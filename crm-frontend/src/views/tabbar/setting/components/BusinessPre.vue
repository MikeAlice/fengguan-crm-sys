<template>
  <el-card class="box-card" style="height: 240px; margin-bottom: 20px">
    <el-row :gutter="20" style="margin-bottom: 20px">
      <el-col :span="6"
        ><span style="font-size: 18px; color: #333"
          >第一个销售金额：</span
        ></el-col
      >
      <el-col :span="6"
        ><el-input-number
          v-model="mins"
          :min="1"
          :max="maxs"
          @change="handleChange"
      /></el-col>
      <el-col :span="6"
        ><span style="font-size: 18px; color: #333"
          >第二个销售金额：</span
        ></el-col
      >
      <el-col :span="6"
        ><el-input-number v-model="maxs" :min="1" @change="handleChange"
      /></el-col>
    </el-row>
    <h3 style="margin-bottom: 20px">根据商机预计销售统计商机数量</h3>
    <el-row :gutter="20">
      <el-col :span="8" v-for="i in messageInfo.countMoney" :key="i">
        <el-statistic :title="i.statisticsName" :value="i.statisticsNumber" />
      </el-col>
    </el-row>
  </el-card>
  <el-card class="box-card" style="height: 240px">
    <el-row :gutter="20" style="margin-bottom: 20px">
      <el-col :span="6"
        ><span style="font-size: 18px; color: #333"
          >第一个销售成功率：</span
        ></el-col
      >
      <el-col :span="6"
        ><el-input-number
          v-model="min1"
          :min="1"
          :max="max1"
          @change="handleChange1"
      /></el-col>
      <el-col :span="6"
        ><span style="font-size: 18px; color: #333"
          >第二个销售成功率：</span
        ></el-col
      >
      <el-col :span="6"
        ><el-input-number v-model="max1" :min="1" @change="handleChange1"
      /></el-col>
    </el-row>
    <h3 style="margin-bottom: 20px">根据商机预计成功率统计商机数量</h3>
    <el-row :gutter="20">
      <el-col :span="8" v-for="i in messageInfo.countSucc" :key="i">
        <el-statistic :title="i.statisticsName" :value="i.statisticsNumber" />
      </el-col>
    </el-row>
  </el-card>
</template>

<script setup>
import { ref } from 'vue'
import {
  countBusinessMoney,
  countBusinessSuccessrate
} from '@/apis/systemPage/index.js'
import useMessageInfo from '@/stores/system-page/messageInfo.js'

const messageInfo = useMessageInfo()
const mins = ref(1)
const maxs = ref(1)
const min1 = ref(1)
const max1 = ref(1)

const handleChange = () => {
  countBusinessMoney(mins.value, maxs.value, (response) => {
    messageInfo.setCountMoney(response.data)
  })
}

const handleChange1 = () => {
  countBusinessSuccessrate(mins.value, maxs.value, (response) => {
    messageInfo.setCountSucc(response.data)
  })
}
</script>

<style lang="scss" scoped></style>
