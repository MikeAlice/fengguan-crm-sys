<!--
 * @Author: seven 1473008948@qq.com
 * @Date: 2023-11-02 15:01:19
 * @LastEditors: seven 1473008948@qq.com
 * @LastEditTime: 2023-11-02 15:01:36
 * @FilePath: \zero-one-crmsys\crm-frontend\src\components\OrganizationStructure\AddGoods.vue
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
            ref="baseDataListRef1"
          >
            <!-- 插槽区 -->
            <template #menu>
              <!-- 表格上面一行 -->
              <div class="menu">
                <div class="leftMenu">
                  <el-button
                    type="primary"
                    :icon="Plus"
                    style="margin: 0; width: 90px"
                    @click="props.addGoodsData"
                    >添加选择商品</el-button
                  >
                  <el-button @click="changeLoadAnimation">刷新</el-button>
                </div>
                <div class="rightMenu">
                  <el-input
                    v-model="searchGoodsName"
                    placeholder="输入商品名称关键字搜索"
                    style="margin-right: 4px; width: 180px"
                  />
                  <!-- 搜索功能还需完善 -->
                  <DropDown
                    :getDropDown="() => [0, 1, 3]"
                    v-model:inputVal1="inputValue1"
                    v-model:inputVal2="inputValue2"
                    inputTitle1="商品编码"
                    inputTitle2="商品SKU名称"
                    @handle-search="handleSearch"
                  ></DropDown>
                  <el-button
                    type="primary"
                    style="margin-left: 4px"
                    @click="changeLoadAnimation"
                  >
                    <el-icon style="margin-right: 4px"><icon-search /></el-icon
                    >搜索
                  </el-button>
                </div>
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
import DropDown from '@/components/DropDown/DropDown.vue'

import { ref, reactive } from 'vue'
const props = defineProps({
  sendData: {
    type: Object,
    required: true
  },
  treeData: {
    type: Object,
    required: true
  },
  addGoodsData: {
    type: Function
  }
})

const sendData = reactive(props.sendData)
const treeData = reactive(props.treeData)

const baseDataListRef1 = ref(null)

//获取被勾选的行的数据（组件暴露出来的rows）
const getRows = () => {
  console.log('rows', baseDataListRef.value.rows)
}
// 关闭表格加载动画
const changeLoadAnimation = () => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  setTimeout(() => {
    baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  }, 500)
}

const rows = ref([])
//树形组件点击事件
const handleNodeClick = (node) => {
  console.log('node', node)
}
// const addData = () => {
//   console.log('addData', baseDataListRef1.value.rows)
//   rows.value = baseDataListRef1.value.rows
// }

defineExpose({
  rows,
  baseDataListRef1
})
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

.leftMenu {
  height: 40px;
}
.rightMenu {
  height: 40px;
  display: flex;
  align-items: center;
}

.menu {
  display: flex;
  align-items: center;
  justify-content: space-between;
  margin-bottom: 10px;
}
</style>
