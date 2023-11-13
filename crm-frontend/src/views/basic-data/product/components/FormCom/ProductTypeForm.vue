<template>
  <div class="ProductTypeForm">
    <el-drawer
      v-model="visible"
      @close="
        () => {
          if (props.title === '编辑分类') {
            form = {
              typeName: '',
              typeTag: '',
              intro: '',
              sort: 0,
              visible: false
            }
          }
          visible = false
          formRef.clearValidate()
        }
      "
    >
      <template #header>
        <h4>{{ props.title }}</h4>
      </template>
      <template #default>
        <el-form :model="form" :rules="rules" ref="formRef">
          <el-form-item label="分类名称" prop="typeName">
            <el-input
              placeholder="请输入分类名称"
              v-model="form.typeName"
            ></el-input>
          </el-form-item>
          <el-form-item label="排序" prop="sort">
            <el-input-number
              v-model="form.sort"
              :min="0"
              @change="handleChange"
            />
          </el-form-item>
          <el-form-item label="启用">
            <el-switch v-model="form.visible" />
          </el-form-item>
        </el-form>
      </template>
      <template #footer>
        <div style="flex: auto">
          <el-button @click="visible = false">取消</el-button>
          <el-button type="primary" @click="props.handleSubmit">提交</el-button>
        </div>
      </template>
    </el-drawer>
  </div>
</template>

<script setup>
import { ref } from 'vue'
const visible = ref(true)

const form = ref({
  typeName: '',
  typeTag: '',
  intro: '',
  sort: 0,
  visible: false
})

const props = defineProps({
  handleSubmit: {
    type: Function,
    default: () => {
      console.log('sumbit')
    }
  },
  title: {
    type: String,
    default: '标题的默认值'
  }
})

const formRef = ref(null)

const rules = ref({
  typeName: [{ required: true, message: '请输入分类名称', trigger: 'blur' }],
  typeTag: [{ required: true, message: '请输入调用标识', trigger: 'blur' }],
  intro: [{ required: true, message: '请输入简介', trigger: 'blur' }],
  sort: [{ required: true, message: '', trigger: 'blur' }]
})

defineExpose({
  visible,
  form,
  formRef
})
</script>

<style lang="scss" scoped></style>
