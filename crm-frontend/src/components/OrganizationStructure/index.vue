<!--
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-22 18:16:13
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-10-24 18:46:42
 * @FilePath: \zero-one-crmsys\crm-frontend\src\components\OrganizationStructure\index.vue
 * @Description: 
 * 
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved. 
-->
<!-- 该组件需要Table、Tree、分页、面包屑组件为子组件 -->
<template>
  <div class="container">
    <div class="app-container">
      <el-row>
        <!-- 左侧树形菜单 -->
        <el-col :span="6" class="left">
          <el-card>
            <div class="header">
              <div>
                <h1>树形菜单</h1>
              </div>
              <el-button>刷新</el-button>
            </div>

            <el-tree
              :data="treeData.treeArr"
              :defaultProps="treeData.defaultProps"
              @node-click="handleNodeClick"
            ></el-tree>
          </el-card>
        </el-col>
        <!-- 右侧表格 -->
        <el-col :span="1"></el-col>
        <el-col :span="17" class="right">
          <BaseDataList
            :useHeader="false"
            :table-column-attribute="sendData.tableColumnAttribute"
            :handle-delete="sendData.handleDelete"
            :handle-edit="sendData.handleEdit"
            :table-data="sendData.tableData"
            :page-sizes="sendData.pageSizes"
            :total="sendData.total"
            :usePagination="sendData.usePagination"
            @update-table-data="get"
            ref="baseDataListRef"
          >
            <!-- 插槽区 -->
            <template #menu>
              <div>
                插槽区
                <el-button>搜索</el-button>
                <el-button>刷新</el-button>
                <el-button @click="getRows">获取被勾选的列</el-button>
                <el-button @click="changeLoadAnimation">加载动画></el-button>
              </div>
            </template>
          </BaseDataList>
        </el-col>
      </el-row>
    </div>
  </div>
</template>

<script setup>
/*组件使用：
表格为冰雾的表格组件
接收两个props，sendData、treeData，分别对应表格区和树形区的数据

sendData里包含表格所有的数据，这里只需要注意:usePagination="sendData.usePagination"，可以指定是否需要分页组件，然后这里是默认不要header的

这里配置的函数也写了对应的注释

treeData里含有树形组件需要的树状数组dataArr和对el-tree的配置对象defaultProps
*/
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import { ref, reactive } from 'vue'
const props = defineProps({
  sendData: {
    type: Object,
    required: true
  },
  treeData: {
    type: Object,
    required: true
  }
})

const sendData = reactive(props.sendData)
const treeData = reactive(props.treeData)
const baseDataListRef = ref(null)

//获取被勾选的行的数据（组件暴露出来的rows）
const getRows = () => {
  console.log('rows', baseDataListRef.value.rows)
}
// 关闭表格加载动画
const changeLoadAnimation = () => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}
//树形组件点击事件
const handleNodeClick = (node) => {
  console.log('node', node)
}
</script>

<style scoped>
.left {
  height: 500px;
}

.right {
  height: 550px;
}

.header {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>
