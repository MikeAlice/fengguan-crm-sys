<!--
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-29 16:46:05
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-08 18:58:12
 * @FilePath: \crm-frontend\src\components\Tree\Tree.vue
 * @Description: 
 * 
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved. 
-->

<template>
  <div class="container">
    <div class="app-container">
      <el-card>
        <!-- header -->
        <el-row><slot name="header"></slot></el-row>
        <!-- body -->
        <div class="body">
          <el-tree
            :data="props.data"
            :props="defaultProps"
            node-key="id"
            :expand-on-click-node="false"
            default-expand-all
          >
            <!-- 插槽内容 -->
            <template #default="{ node, data }">
              <el-row type="flex" justify="space-between" style="width: 100%">
                <span>{{ node.label }}</span>
                <span>
                  <a @click="emits('append', data)" style="color: #409eff">
                    增加
                  </a>
                  <a
                    style="margin-left: 8px; color: #909399"
                    @click="emits('edit', data)"
                    >编辑</a
                  >
                  <a
                    v-if="node.childNodes.length === 0"
                    style="margin-left: 8px; color: #f56c6c"
                    @click="emits('remove', data)"
                  >
                    删除
                  </a>
                </span>
              </el-row>
            </template>
          </el-tree>
        </div>
      </el-card>
    </div>
    <!-- 这里需要在关闭的时候销毁所有data，否则会因为编辑/新增的状态问题导致回传bug -->
    <!-- 性能不是很好，可以更精确的删除但是太麻烦了 -->
    <el-drawer
      v-model="showDrawer"
      direction="rtl"
      :destroy-on-close="true"
      @close="props.handleClose"
    >
      <template #header>
        <h4>{{ isEdit ? '编辑' : '新增' }}</h4>
      </template>
      <template #default>
        <div>
          <!-- form表单通过slot传递 -->
          <slot name="form1"></slot>
        </div>
      </template>
      <template #footer>
        <div style="display: flex; justify-content: space-between">
          <el-button @click="emits('cancel')">取消</el-button>
          <el-button
            type="primary"
            @click="
              () => {
                emits('submit')
              }
            "
            >确认</el-button
          >
        </div>
      </template>
    </el-drawer>
  </div>
</template>
<script setup>
import { ref } from 'vue'

const props = defineProps({
  data: {
    type: Array,
    required: true
  },
  handleClose: {
    type: Function
  }
})

//抽屉的显示状态
const showDrawer = ref(false)
//抽屉的状态：增加/编辑
const isEdit = ref(false)

const defaultProps = {
  children: 'children',
  label: 'label'
}
const emits = defineEmits(
  ['append'],
  ['submit'],
  ['remove'],
  ['edit'],
  ['cancel']
)

defineExpose({
  isEdit,
  showDrawer
})
</script>

<style scoped></style>
