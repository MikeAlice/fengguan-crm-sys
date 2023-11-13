<template>
  <div class="DictionaryManageForm">
    <el-drawer v-model="visible" @close="handleClear">
      <template #header>
        <h4>{{ props.title }}</h4>
      </template>
      <template #default>
        <el-form :model="form" :rules="rules" ref="formRef">
          <el-form-item label="名称" prop="name">
            <el-input placeholder="请输入名称" v-model="form.name"></el-input>
          </el-form-item>
          <el-form-item label="分类字典">
            <ChooseSelect
              :options="props.options"
              ref="chooseSelectRef"
            ></ChooseSelect>
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
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'
const visible = ref(false)
const chooseSelectRef = ref(null)
const form = ref({
  name: '',
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
  },
  options: {
    type: Array
  }
})

const formRef = ref(null)

const rules = ref({
  name: [{ required: true, message: '请输入字典名称', trigger: 'blur' }],
  sort: [{ required: true, message: '', trigger: 'blur' }]
})

const handleClear = () => {
  if (props.title === '字典修改') {
    form.value = {
      name: '',
      sort: 0,
      visible: false
    }
    setTimeout(() => {
      chooseSelectRef.value.selectValue = ''
    })
  }
  visible.value = false
  formRef.value.clearValidate()
}

defineExpose({
  visible,
  form,
  formRef,
  chooseSelectRef
})
</script>

<style lang="scss" scoped></style>
