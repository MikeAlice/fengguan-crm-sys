<template>
  <div class="DictionaryEditForm">
    <el-drawer
      v-model="visible"
      @close="
        () => {
          if (props.title === '编辑分类') {
            form = {
              ...initForm
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
          <el-form-item label="调用标识" prop="typetag">
            <el-input
              placeholder="请输入调用标识"
              v-model="form.typetag"
              :disabled="props.title === '编辑分类'"
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
          <el-form-item label="简介" prop="intro">
            <el-input type="textarea" v-model="form.intro"></el-input>
          </el-form-item>
          <el-form-item
            label="下级层数设置"
            prop="seotitle"
            v-if="!(props.title === '编辑分类')"
          >
            <el-input-number v-model="form.seotitle" :min="0" />
          </el-form-item>
          <el-form-item
            label="层数提成比例"
            prop="keywords"
            v-if="!(props.title === '编辑分类')"
          >
            <el-input-number v-model="form.keywords" :min="0" />
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
const visible = ref(false)

const initForm = ref({
  typeName: '',
  typetag: '',
  intro: '',
  sort: 0,
  visible: false,
  seotitle: 0,
  keywords: 0
})

const form = ref({
  typeName: '',
  typetag: '',
  intro: '',
  sort: 0,
  visible: false,
  seotitle: 0,
  keywords: 0
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
  typetag: [{ required: true, message: '请输入调用标识', trigger: 'blur' }],
  typeName: [{ required: true, message: '请输入分类名称', trigger: 'blur' }],
  intro: [{ required: true, message: '请输入简介', trigger: 'blur' }],
  sort: [{ required: true, message: '请输入排序', trigger: 'change' }],
  seotitle: [
    { required: true, message: '请输入下级层数设置', trigger: 'change' }
  ],
  keywords: [
    { required: true, message: '请输入层数提成比例', trigger: 'change' }
  ]
})

defineExpose({
  visible,
  form,
  formRef
})
</script>

<style lang="scss" scoped></style>
