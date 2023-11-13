<!--
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-30 21:35:22
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-07 20:48:04
 * @FilePath: \zero-one-crmsys\crm-frontend\src\components\chooseSelect\ChooseSelect.vue
 * @Description: 
 * 
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved. 
-->
<script setup>
// 这是下拉选择框 create by 暮秋pro
// 更新时间：23/10/19
import { ref } from 'vue'
import { Search } from '@element-plus/icons-vue'

const selectValue = ref('')
const input1 = ref()
/**
 * 使用示例:
 * const options = ref([
  {
    value: 'Option1',
    label: '选项1'
  },
  {
    value: 'Option2',
    label: '选项2'
  },
  {
    value: 'Option3',
    label: '选项3'
  }
])
        <!-- 下拉选择框 -->
        <ChooseSelect
          :options="options"
          des="请选择你要查找的内容"
        ></ChooseSelect>
 */

// 从父组件接收的数据
// options: 数组选项
// des: 选择框选择文本
const props = defineProps({
  options: {
    type: Array
  },
  des: {
    type: String,
    default: '请选择'
  },
  disabled: {
    type: Boolean,
    default: false
  }
})

// 定义子传父方法
const emit = defineEmits(['update:cid'])

const reset = () => {
  selectValue.value = ''
}
const setVal = (val) => {
  selectValue.value = val
}
// 微调  冰雾
defineExpose({
  selectValue,
  reset,
  setVal
})
</script>

<template>
  <el-select
    v-model="selectValue"
    class="m-2"
    :placeholder="props.des"
    size="default"
    style="width: 150px"
    clearable
    @change="emit('update:cid', selectValue)"
    :disabled="props.disabled"
  >
    <!-- 搜索框 -->
    <el-input
      v-model="input1"
      class="w-50 m-2 search"
      size="default"
      placeholder="请输入"
      :suffix-icon="Search"
    />
    <el-option
      v-for="item in props.options"
      :key="item.label"
      :label="item.label"
      :value="item"
    >
    </el-option>
  </el-select>
</template>

<style scoped>
.search {
  width: 100%;
  padding: 5% 5%;
}
</style>
