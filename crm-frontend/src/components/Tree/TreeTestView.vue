<!--
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-29 16:46:05
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-10-30 21:37:01
 * @FilePath: \zero-one-crmsys\crm-frontend\src\components\Tree\TreeTestView.vue
 * @Description: 
 * 
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved. 
-->

<template>
  <div>
    <TreeDemo :data="treeData" ref="treeDemoRef">
      <template #header>header</template>
      <!-- 这里真的很尬，为了区分状态反而传了两个插槽，我明天优化一下这里 -->
      <template #form1>
        <el-form :model="treeDemoRef.isEdit ? data1 : data2">
          <el-form-item label="名字" prop="name"
            ><el-input v-model="name"></el-input
          ></el-form-item>
          <el-form-item label="年龄" prop="age"
            ><el-input v-model="age"></el-input
          ></el-form-item>
          <el-form-item label="性别" prop="sex"
            ><el-input v-model="sex" type="textarea"></el-input
          ></el-form-item>
        </el-form>
      </template>
    </TreeDemo>
  </div>
</template>

<script setup>
import TreeDemo from './TreeDemo.vue'
import { ref, computed } from 'vue'
const treeDemoRef = ref(null)
const data1 = {
  name: 'sayoriqwq',
  age: 18,
  sex: 'male'
}

const data2 = {
  name: '',
  age: '',
  sex: ''
}

const name = computed(() => {
  return treeDemoRef.value.isEdit ? data1.name : data2.name
})

const age = computed(() => {
  return treeDemoRef.value.isEdit ? data1.age : data2.age
})

const sex = computed(() => {
  return treeDemoRef.value.isEdit ? data1.sex : data2.sex
})

const treeData = [
  {
    id: 1,
    label: 'Level one 1',
    children: [
      {
        id: 4,
        label: 'Level two 1-1',
        children: [
          {
            id: 9,
            label: 'Level three 1-1-1'
          },
          {
            id: 10,
            label: 'Level three 1-1-2'
          }
        ]
      }
    ]
  },
  {
    id: 2,
    label: 'Level one 2',
    children: [
      {
        id: 5,
        label: 'Level two 2-1'
      },
      {
        id: 6,
        label: 'Level two 2-2'
      }
    ]
  },
  {
    id: 3,
    label: 'Level one 3',
    children: [
      {
        id: 7,
        label: 'Level two 3-1'
      },
      {
        id: 8,
        label: 'Level two 3-2'
      }
    ]
  }
]
</script>
