<template>
  <el-tabs v-model="activeName" class="demo-tabs" @tab-click="handleClick">
    <el-tab-pane label="系统公告" name="first">
      <div class="bottoms">
        <el-row class="infinite-list" style="overflow: auto">
          <el-col
            v-for="i in dashBoard.announcement"
            :key="i"
            class="infinite-list-item"
          >
            <el-card>
              <el-descriptions :title="i.title">
                <el-descriptions-item :label="i.content"></el-descriptions-item>
              </el-descriptions>
            </el-card>
          </el-col>
        </el-row>
      </div>
    </el-tab-pane>
    <el-tab-pane label="我的客户" name="second">
      <ClientStatistics></ClientStatistics>
    </el-tab-pane>
    <el-tab-pane label="我的商机" name="third">
      <BusinessStatistics></BusinessStatistics>
    </el-tab-pane>
    <el-tab-pane label="商机预测" name="forth">
      <BusinessPre></BusinessPre>
    </el-tab-pane>
  </el-tabs>
</template>

<script setup>
import { ref } from 'vue'
import BusinessStatistics from './BusinessStatistics.vue'
import ClientStatistics from './ClientStatistics.vue'
import BusinessPre from './BusinessPre.vue'
import useDashBoard from '@/stores/dashBoard/dashBoard.js'
const dashBoard = useDashBoard()
const activeName = ref('first')
</script>

<style lang="scss" scoped>
.infinite-list {
  height: 380px;
  padding: 0;
  margin: 0;
  list-style: none;
}
.infinite-list .infinite-list-item {
  margin-bottom: 10px;
}
.infinite-list .infinite-list-item + .list-item {
  margin-top: 10px;
}
</style>
