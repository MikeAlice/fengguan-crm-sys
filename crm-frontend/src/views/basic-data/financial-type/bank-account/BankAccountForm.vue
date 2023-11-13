<template>
  <div class="BankAccountForm">
    <el-drawer v-model="visible" @close="handleClear">
      <template #header>
        <h4>{{ props.title }}</h4>
      </template>
      <template #default>
        <el-form :model="form" :rules="rules" ref="formRef">
          <el-form-item label="银行名称" prop="name">
            <el-input
              placeholder="请输入银行名称"
              v-model="form.name"
            ></el-input>
          </el-form-item>
          <el-form-item label="开户户头" prop="holders">
            <el-input
              placeholder="请输入开户户头"
              v-model="form.holders"
            ></el-input>
          </el-form-item>
          <el-form-item label="开户账号" prop="card">
            <el-input
              placeholder="请输入开户账号"
              v-model.number="form.card"
            ></el-input>
          </el-form-item>
          <el-form-item label="开户网点" prop="address">
            <el-input
              placeholder="请输入开户网点"
              v-model="form.address"
            ></el-input>
          </el-form-item>
          <el-form-item label="排序序号" prop="sort">
            <el-input-number
              v-model="form.sort"
              :min="0"
              @change="handleChange"
            />
          </el-form-item>
          <el-form-item label="是否启用">
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
const visible = ref(false)
const form = ref({
  name: '',
  card: 0,
  holders: '',
  address: '',
  visible: true,
  sort: 0
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
  name: [{ required: true, message: '请输入银行名称', trigger: 'blur' }],
  card: [
    {
      required: true,
      message: '请输入银行卡号',
      trigger: 'blur'
    },
    {
      type: 'number',
      message: '请输入数字'
    }
  ],
  holders: [{ required: true, message: '请输入开户人', trigger: 'blur' }],
  address: [{ required: true, message: '请输入开户地址', trigger: 'blur' }],
  sort: [{ required: true, message: '', trigger: 'blur' }]
})

const handleClear = () => {
  if (props.title === '修改') {
    form.value = {
      name: '',
      card: 0,
      holders: '',
      address: '',
      visible: true,
      sort: 0
    }
  }
  visible.value = false
  formRef.value.clearValidate()
}

defineExpose({
  visible,
  form,
  formRef
})
</script>

<style lang="scss" scoped></style>
