<template>
  <div class="password">
    <el-card>
      <template #header>
        <div class="card-header">
          <span>修改密码</span>
        </div>
      </template>
      <div class="card-body">
        <el-form
          :model="form"
          label-width="120px"
          style="margin: 18px 40px"
          ref="ruleFormRef"
          :rules="rules"
          class="demo-ruleForm"
        >
          <el-form-item label="旧密码" prop="oldPassword">
            <el-input
              v-model="form.oldPassword"
              placeholder="请输入之前登录密码"
              style="width: 30%"
              clearable
            />
          </el-form-item>
          <el-form-item label="新密码" prop="newPassword">
            <el-input
              v-model="form.newPassword"
              placeholder="请输入新的登录密码"
              style="width: 30%"
              clearable
            />
          </el-form-item>
          <el-form-item label="密码确认" prop="confirmPassword">
            <el-input
              v-model="form.confirmPassword"
              placeholder="请再次输入新的登录密码"
              style="width: 50%"
              clearable
            />
          </el-form-item>
          <el-form-item style="margin-top: 44px">
            <el-button type="primary" @click="submitForm">保存密码</el-button>
            <el-button type="info" @click="resetForm">重置</el-button>
          </el-form-item>
        </el-form>
      </div>
    </el-card>
  </div>
</template>

<script setup>
import { ref } from 'vue'
// import { userUpdatePasswordService } from '@/api/user'
// import { useUserStore } from '@/stores'
// import { useRouter } from 'vue-router'

const ruleFormRef = ref()
const form = ref({
  oldPassword: '', //旧密码
  newPassword: '', //新密码
  confirmPassword: '' //再次确认新密码
})

const checkDifferent = (rule, value, callback) => {
  // 校验新密码和原密码不能一样
  if (value === form.value.old_pwd) {
    callback(new Error('新密码不能与原密码一样'))
  } else {
    callback()
  }
}
const checkSameAsNewPwd = (rule, value, callback) => {
  // 校验确认密码必须和新密码一样
  if (value !== form.value.new_pwd) {
    callback(new Error('确认密码必须和新密码一样'))
  } else {
    callback()
  }
}

//表单校验规则
const rules = {
  oldPassword: [
    { required: true, message: '请输入原密码', trigger: 'blur' },
    { min: 6, max: 15, message: '原密码长度在6-15位之间', trigger: 'blur' }
  ],
  newPassword: [
    { required: true, message: '请输入新密码', trigger: 'blur' },
    { min: 6, max: 15, message: '新密码长度在6-15位之间', trigger: 'blur' },
    { validator: checkDifferent, trigger: 'blur' }
  ],
  confirmPassword: [
    { required: true, message: '请再次输入新密码', trigger: 'blur' },
    { min: 6, max: 15, message: '确认密码长度在6-15位之间', trigger: 'blur' },
    { validator: checkSameAsNewPwd, trigger: 'blur' }
  ]
}

// const userStore = useUserStore()
// const router = useRouter()

//提交按钮的反馈逻辑
const submitForm = async () => {
  await ruleFormRef.value.validate()
  await userUpdatePasswordService(form.value)
  ElMessage.success('密码修改成功')
  
  // 密码修改成功后，退出重新登录
  // 清空本地存储的 token 和 个人信息
  // userStore.setToken('')
  // userStore.setUser({})

  // 拦截登录
  // router.push('/login')
}

const resetForm = () => {
  ruleFormRef.value.resetFields()
}
</script>

<style lang="scss" scoped></style>
