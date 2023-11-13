<template>
  <template v-for="item in menuList" :key="item.href">
    <!-- 没有子路由 -->
    <template v-if="!item.children">
      <el-menu-item :index="item.href" :key="item.href">
        <el-icon>
          <component :is="item.icon"></component>
        </el-icon>
        <template #title>
          <span>{{ item.text }}</span>
        </template>
      </el-menu-item>
    </template>
    <!-- 只有一个子路由 -->
    <template v-if="item.children && item.children.length == 1">
      <el-menu-item :index="item.children[0].href" :key="item.children[0].href">
        <el-icon>
          <component :is="item.children[0].icon"></component>
        </el-icon>
        <template #title>
          <span>{{ item.children[0].text }}</span>
        </template>
      </el-menu-item>
    </template>
    <!-- 有多个子路由 -->
    <el-sub-menu
      v-if="item.children && item.children.length > 1"
      :index="item.href"
      :key="item.href"
    >
      <template #title>
        <el-icon>
          <component :is="item.icon"></component>
        </el-icon>
        <span>{{ item.text }}</span>
      </template>
      <Menus :menuList="item.children"></Menus>
    </el-sub-menu>
  </template>
</template>

<script setup>
// 获取父组件传递过来的全部路由数组
defineProps(['menuList'])
</script>
<script>
export default {
  name: 'Menus'
}
</script>

<style scoped></style>
