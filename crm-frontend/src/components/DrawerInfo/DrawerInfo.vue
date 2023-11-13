<script setup>
// import { ref, toRef } from 'vue'

/**
 * visible：控制抽屉的显示与隐藏
 * title：抽屉的标题。
 * formComponent：自定义的表单组件
 * rules：表单的校验规则。
 */
/**
 * 父组件中快速调用：
 * // 这是控制抽屉打开关闭的数据
 * const drawer = ref(false)
 * const form = ref({
 * name: ''
})
 *     <DrawerInfo
      :visible="drawer"
      :update:visible="(drawer = false)"
      title="标题"
    >
      <template #default>
        <el-form :model="form" label-width="120px">
          <el-form-item label="属性名">
            <el-input v-model="form.name" placeholder="请输入" />
          </el-form-item>
        </el-form>
      </template>
    </DrawerInfo>
    <el-button type="primary" style="margin-left: 16px" @click="drawer = true">
      open
    </el-button>
 */
// 父传子需要接收的数据
const props = defineProps({
  visible: {
    type: Boolean,
    required: true
  },
  title: {
    type: String,
    default: '编辑'
  },
  customFormRef: {
    type: Object,
    default: null
  }
})
const emit = defineEmits(['update:visible', 'update:submit'])
</script>

<template>
  <el-drawer
    :model-value="props.visible"
    :title="props.title"
    size="40%"
    open-delay="100"
    close-delay="100"
    @close="emit('update:visible', false)"
  >
    <slot></slot>
    <el-button @click="emit('update:submit')" type="primary">提交</el-button>
  </el-drawer>
</template>
