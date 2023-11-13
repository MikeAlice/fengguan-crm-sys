<template>
  <el-row class="tac">
    <el-col :span="6">
      <h5 class="mb-2">侧边栏主菜单/logo</h5>
      <el-menu 
        active-text-color="#ffd04b"
        background-color="#545c64"
        class="el-menu-vertical-demo"
        :default-active="2"
        text-color="#fff"
        @open="handleOpen"
        @close="handleClose"
        
        unique-opened="true"
        router
      >
        <!-- 一级菜单 -->
        <el-menu-item index="0">
          <el-icon><icon-menu /></el-icon>
          <span>首页</span>
        </el-menu-item>
        <el-sub-menu index="1">
          <template #title>
            <el-icon><location /></el-icon>
            <span>Navigator One</span>
          </template>
          <!-- 二级菜单 -->
            <el-menu-item index="1-1">item one</el-menu-item>
            <el-menu-item index="1-2">item two</el-menu-item>
          <el-sub-menu index="1-3">
            <template #title>item three</template>
            <!-- 三级菜单 -->
            <el-menu-item index="1-3-1">item one</el-menu-item>
            <el-menu-item index="1-3-2">item two</el-menu-item>
          </el-sub-menu>
          <el-sub-menu index="1-4">
            <template #title>item four</template>
            <el-menu-item index="1-4-1">item one</el-menu-item>
            <el-menu-item index="1-4-2">item two</el-menu-item>
          </el-sub-menu>
        </el-sub-menu>
        <el-sub-menu index="2">
          <template #title>
            <el-icon><icon-menu /></el-icon>
            <router-link to="/sample/file">Navigator Two</router-link>
            <!-- <span>Navigator two</span>原代码 -->
          </template>
            <el-menu-item index="2-1">item one</el-menu-item>
            <el-menu-item index="2-2">item two</el-menu-item>
          <el-sub-menu index="2-3">
            <template #title>item three</template>
            <el-menu-item index="2-3-1">
              <router-link to="/sample/newsCenter">item one</router-link>
            </el-menu-item>
            <el-menu-item index="2-3-2">item two</el-menu-item>
          </el-sub-menu>
          <el-sub-menu index="2-4">
            <template #title>item four</template>
            <el-menu-item index="2-4-1">item one</el-menu-item>
            <el-menu-item index="2-4-2">item two</el-menu-item>
          </el-sub-menu>
        </el-sub-menu>
        <el-sub-menu index="3">
          <template #title>
            <el-icon><document /></el-icon>
            <span>Navigator Three</span>
          </template>
            <el-menu-item index="3-1">item one</el-menu-item>
            <el-menu-item index="3-2">item two</el-menu-item>
          <el-sub-menu index="3-3">
            <template #title>item three</template>
            <el-menu-item index="3-3-1">item one</el-menu-item>
            <el-menu-item index="3-3-2">item two</el-menu-item>
          </el-sub-menu>
          <el-sub-menu index="3-4">
            <template #title>item four</template>
            <el-menu-item index="3-4-1">item one</el-menu-item>
            <el-menu-item index="3-4-2">item two</el-menu-item>
          </el-sub-menu>
        </el-sub-menu>
        <el-sub-menu index="4">
          <template #title>
            <el-icon><setting /></el-icon>
            <span>Navigator Four</span>>
          </template>
            <el-menu-item index="4-1">item one</el-menu-item>
            <el-menu-item index="4-2">item two</el-menu-item>
        </el-sub-menu>
      </el-menu>
    </el-col>
  </el-row>
</template>


<script lang="ts" setup>

import {
  Document,
  Menu as IconMenu,
  Location,
  Setting,
} from '@element-plus/icons-vue'
const handleOpen = (key: string, keyPath: string[]) => {
  console.log(key, keyPath)
}
const handleClose = (key: string, keyPath: string[]) => {
  console.log(key, keyPath)
}

</script>


<style scoped>
</style>