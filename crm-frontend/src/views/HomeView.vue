<template>
  <el-container class="sec-container">
    <!-- 侧边栏菜单 -->
    <div class="menu-wrap" :class="{ fold: fold }">
      <el-scrollbar class="scrollbar" max-height="100vh">
        <el-menu
          default-active="/home"
          class="el-menu-vertical-demo"
          active-text-color="#409EFF"
          text-color="#fff"
          background-color="#001529"
          unique-opened
          router
          :collapse="fold ? true : false"
        >
          <!-- 首页 -->
          <el-menu-item index="/home">
            <el-tooltip
              class="box-item"
              effect="light"
              content="首页"
              placement="right"
            >
              <el-icon v-if="fold">
                <icon-menu />
              </el-icon>
            </el-tooltip>
            <el-icon v-if="!fold">
              <icon-menu />
            </el-icon>
            <span>首页</span>
          </el-menu-item>
          <!-- 多级菜单 -->
          <Menu :menu-list="$store.menus"></Menu>
        </el-menu>
      </el-scrollbar>
    </div>
    <el-container>
      <!-- 导航栏 -->
      <div class="header-nav" :class="{ fold: fold }">
        <div class="flex">
          <div class="left">
            <BreadCrumb></BreadCrumb>
          </div>
          <div class="right">
            <Setting></Setting>
          </div>
        </div>
      </div>
      <div class="main" :class="{ fold: fold }">
        <!-- 布局路由 -->
        <router-view v-if="flag" />
      </div>
    </el-container>
  </el-container>
</template>

<style lang="scss" scoped>
// 左侧菜单宽度
$base-menu-width: 260px; // 220px
// 左侧菜单背景颜色
$base-menu-background: #001529;
$base-menu-min-width: 75px;
// 左侧菜单logo高度设置
$base-menu-logo-height: 50px;
// 顶部导航高度
$base-tabbar-height: 50px;

.sec-container {
  width: 100%;
  height: 100vh;
  .menu-wrap {
    width: $base-menu-width;
    height: 100vh;
    background-color: $base-menu-background;
    color: white;
    transition: all 0.3s;
    white-space: nowrap;
    .scrollbar {
      width: 100%;
      height: calc(100vh - $base-menu-logo-height);
      .el-menu {
        border: 0;
      }
      .el-menu-item-group .el-menu-item {
        text-indent: 1.5em;
      }
    }
    &.fold {
      width: $base-menu-min-width;
    }
  }

  .header-nav {
    position: fixed;
    width: calc(100% - $base-menu-width);
    height: $base-tabbar-height;
    top: 0;
    left: $base-menu-width;
    transition: all 0.3s;
    .flex {
      width: 100%;
      height: 100%;
      display: flex;
      justify-content: space-between;
      .left {
        display: flex;
        align-items: center;
        margin-left: 20px;
      }
      .right {
        display: flex;
        align-items: center;
      }
    }

    &.fold {
      width: calc(100vw - $base-menu-min-width);
      left: $base-menu-min-width;
    }
  }
  .main {
    position: absolute;
    top: $base-tabbar-height;
    width: 100%;
    height: calc(100vh - $base-tabbar-height);
    // background: green;
    padding: 20px;
    overflow: auto;
    transition: all 0.3s;
    &.fold {
      width: calc(100vw - $base-menu-min-width);
    }
  }
}
</style>

<script setup>
import { ref, watch, nextTick, onMounted } from 'vue'
import { userStore } from '@/stores/user'
import useLayOutSettingStore from '@/stores/setting.js'
import Setting from './tabbar/setting/Setting.vue'
import { queryMessageNotices } from '@/apis/systemPage/index.js'
import BreadCrumb from './tabbar/bread-crumb/BreadCrumb.vue'
import Menu from './menu/Menu.vue'
import useMessageInfo from '@/stores/system-page/messageInfo.js'
import {
  countCustomerGrade,
  countCustomerIndustry,
  countCustomerNumber,
  countCustomerSource,
  countBusinessSalestage,
  countBusinessNumber
} from '@/apis/systemPage/index.js'

const messageInfo = useMessageInfo()
const $store = userStore()
const layOutSettingStore = useLayOutSettingStore()

// 控制当前组件是否销毁重建
let flag = ref(true)
// 监听仓库内部数据是否发生变化，变化说明用户点击了刷新按钮
watch(
  () => layOutSettingStore.refsh,
  () => {
    flag.value = false
    nextTick(() => {
      flag.value = true
    })
  }
)
let fold = ref(false)
watch(
  () => layOutSettingStore.fold,
  () => {
    fold.value = layOutSettingStore.fold
  }
)
onMounted(async () => {
  $store.loadMenus()

  queryMessageNotices()
  countCustomerGrade((response) => {
    messageInfo.setLevel(response.data)
  })
  countCustomerIndustry((response) => {
    messageInfo.setIndustry(response.data)
  })
  countCustomerNumber((response) => {
    messageInfo.setCustomerNum(response.data)
  })
  countCustomerSource((response) => {
    messageInfo.setBelong(response.data)
  })
  countBusinessSalestage((response) => {
    messageInfo.setStates(response.data)
  })
  countBusinessNumber((response) => {
    messageInfo.setBusNum(response.data)
  })
})
</script>
