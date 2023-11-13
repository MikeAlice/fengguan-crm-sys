<!--
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-29 16:46:05
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-10-29 22:25:54
 * @FilePath: \zero-one-crmsys\crm-frontend\src\components\Tree\Tree.vue
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
            :data="data"
            :props="defaultProps"
            node-key="id"
            @node-click="handleNodeClick"
            :expand-on-click-node="false"
            default-expand-all
          >
            <!-- 插槽内容 -->
            <template #default="{ node, data }">
              <el-row type="flex" justify="space-between" style="width: 100%">
                <span>{{ node.label }}</span>
                <span>
                  <a @click="append(data)"> 增加 </a>
                  <a style="margin-left: 8px" @click="edit(data)">编辑</a>
                  <a style="margin-left: 8px" @click="remove(node, data)">
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
      :before-close="handleClose"
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
          <el-button @click="cancel">取消</el-button>
          <el-button type="primary" @click="submit">确认</el-button>
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
  }
})

console.log('props.whichComponent', props.whichComponent)
//抽屉的显示状态
const showDrawer = ref(false)

//抽屉的状态：增加/编辑
const isEdit = ref(false)

//现在使用的id，要保存一份，增加的时候作为pid，编辑的时候就是id
const curId = ref('')
const handleNodeClick = (data) => {
  //这里可以拿到点击时的node数据
  //   console.log(data)
}

//这里默认传过来的data就是树形的，如果不是还需要联系后端协调，处理扁平数组为树形的函数网上也很容易搜到
const data = ref(...[props.data])

const defaultProps = {
  children: 'children',
  label: 'label'
}

const append = (data) => {
  //改变状态
  isEdit.value = false
  showDrawer.value = true

  //拿到id,这里的id拿来作为新增的数据的父级id
  curId.value = data.id
  //拿到id就为止了，剩下的逻辑在抽屉里的确认时处理
  console.log('append-data', data)
}
const edit = (data) => {
  //改变状态
  isEdit.value = true
  showDrawer.value = true

  //拿到id,这里的id就是编辑的数据用的id
  curId.value = data.id
  //拿到id就为止了，剩下的逻辑在抽屉里的确认时处理
  console.log('edit-data', data)
}
const submit = () => {
  //关闭抽屉
  showDrawer.value = false
  //根据状态发请求
  isEdit.value ? console.log('发edit请求') : console.log('发add请求')
}

const cancel = () => {
  console.log('cancel')
}
//后续再加confirm
//TODO - 功能确实实现了，但是有报错
//Uncaught TypeError: data.value is not iterable
//ts就没有，不知道哪的问题
const remove = (node, data) => {
  const parent = node.parent
  const children = parent.data.children || parent.data
  const index = children.findIndex((d) => d.id === data.id)
  children.splice(index, 1)
  data.value = [...data.value]
}

const handleClose = (done) => {
  //取消的钩子函数
  //后续在这里加confim
  done()
}

defineExpose({
  isEdit
})
</script>

<style scoped></style>
