<!--
 * @Author: BINGWU
 * @Date: 2023-10-30 18:29:35
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2023-11-05 23:27:55
 * @FilePath: \crm-frontend\src\views\basic-data\warehouse\WarehouseFrom.vue
 * @Describe: 
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
-->
<template>
  <div class="WarehouseFrom">
    <el-drawer
      v-model="visible"
      @close="
        () => {
          if (props.title === '修改') {
            form = {
              name: '',
              visible: true,
              sort: 0,
              intro: ''
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
          <el-form-item label="仓库名称" prop="name">
            <el-input
              placeholder="请输入仓库名称"
              v-model="form.name"
            ></el-input>
          </el-form-item>
          <el-form-item label="排位序号" prop="sort">
            <el-input-number
              v-model="form.sort"
              :min="0"
              @change="handleChange"
            />
          </el-form-item>
          <el-form-item label="是否启用">
            <el-switch v-model="form.visible" />
          </el-form-item>
          <el-form-item label="简介" prop="intro">
            <el-input type="textarea" v-model="form.intro"></el-input>
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

const form = ref({
  name: '',
  visible: true,
  sort: 0,
  intro: ''
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
  name: [{ required: true, message: '请输入分类名称', trigger: 'blur' }],
  intro: [{ required: true, message: '请输入简介', trigger: 'blur' }],
  sort: [{ required: true, message: '', trigger: 'change' }]
})

defineExpose({
  visible,
  form,
  formRef
})
</script>

<style lang="scss" scoped></style>
