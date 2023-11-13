<template>
  <!-- 顶部左侧静态 -->
  <el-icon style="margin-right: 10px" @click="changeIcon">
    <el-tooltip
      class="box-item"
      effect="light"
      :content="layOutSettingStore.fold ? '展开菜单' : '折叠菜单'"
      placement="bottom"
    >
      <component :is="layOutSettingStore.fold ? Fold : Expand"></component>
    </el-tooltip>
  </el-icon>
  <!-- 左侧面包屑 -->
  <el-breadcrumb :separator-icon="ArrowRight">
    <el-breadcrumb-item
      v-for="(item, index) in $route.matched"
      :key="index"
      v-show="item.meta.title"
      :to="item.path"
    >
      <el-icon style="margin: 0 5px">
        <component :is="item.meta.icon"></component>
      </el-icon>
      {{ item.meta.title }}
    </el-breadcrumb-item>
  </el-breadcrumb>
</template>

<script setup>
import { useRoute } from 'vue-router'
import useLayOutSettingStore from '@/stores/setting.js'
import { ArrowRight } from '@element-plus/icons-vue'
import { Expand, Fold } from '@element-plus/icons-vue'

// 获取路由对象
let $route = useRoute()
const layOutSettingStore = useLayOutSettingStore()

const changeIcon = () => {
  layOutSettingStore.fold = !layOutSettingStore.fold
}
</script>

<style lang="scss" scoped></style>
