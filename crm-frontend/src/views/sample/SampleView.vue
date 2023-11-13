<template>
  <div>
    <el-header>
      <div class="header-nav">示例效果演示页</div>
    </el-header>
    <el-container>
      <el-aside>
        <div class="menu-wrap">
          <el-scrollbar max-height="95vh">
            <el-menu
              default-active="/sample/file"
              active-text-color="#409EFF"
              text-color="#fff"
              background-color="#545c64"
              unique-opened
              router
            >
              <el-menu-item
                v-for="(menu, index) in menus"
                :key="index"
                :index="menu.path"
              >
                <el-icon>
                  <icon-menu />
                </el-icon>
                <span>{{ menu.text }}</span>
              </el-menu-item>
            </el-menu>
          </el-scrollbar>
        </div>
      </el-aside>
      <el-main>
        <router-view />
      </el-main>
    </el-container>
  </div>
</template>

<style lang="scss" scoped>
.el-header {
  background-color: #5d6672;
  height: 5vh;
  display: flex;
  justify-content: space-between;
  padding: 0;
  .header-nav {
    line-height: 5vh;
    width: 100%;
    color: #f8f8f8;
    text-align: center;
  }
}
.el-aside {
  background-color: #545c64;
  height: 95vh;
  width: 221px;
  .menu-wrap {
    width: 220px;
  }
}
.el-menu {
  border: 0;
}
.el-main {
  padding: 20px;
  background-color: #edecec;
  overflow: scroll;
  height: 95vh;
}
</style>

<script setup>
import { reactive } from 'vue'
// 演示菜单数据，添加新的演示在这里不从数据即可 path代表路由地址 text代表提示文本
const menus = reactive([
  {
    path: '/sample/file',
    text: '文件上传'
  },
  {
    path: '/sample/excel',
    text: 'Excel演示'
  },
  {
    path: '/sample/print',
    text: '打印演示'
  },
  {
    path: '/sample/editor',
    text: '富文本框演示'
  },
  {
    path: '/sample/test',
    text: '测试专用1'
  },
  {
    path: '/sample/test1',
    text: '测试专用2'
  },
  {
    path: '/sample/test2',
    text: '测试专用3'
  },
  { path: '/sample/chartDemo', text: '销售图表演示(临时)' },
  {
    path: '/sample/organizationStructure',
    text: '组织结构演示'
  },
  {
    path: '/sample/newsCenter',
    text: '新闻中心演示'
  },
  // treemenu测试界面，以后会删除
  {
    path: '/sample/treemenu',
    text: 'treemenu演示界面'
  },
  {
    path: '/sample/customChartTest',
    text: '测试客户数据展示'
  },
  {
    path: '/sample/bulkOpe',
    text: '测试批量操作'
  }
])
</script>
