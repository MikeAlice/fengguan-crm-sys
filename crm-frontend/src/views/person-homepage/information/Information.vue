<template>
  <el-card class="information">
    <template #header>
      <div class="card-header">
        <span>编辑资料</span>
      </div>
    </template>

    <page-container style="display: flex; margin: 26px 44px">
      <div class="left" style="width: 50%">
        <el-form
          :model="form"
          label-width="120px"
          ref="ruleFormRef"
          :rules="rules"
          class="demo-ruleForm"
          :size="formSize"
          status-icon
        >
          <el-form-item label="地址" prop="address">
            <el-input v-model="form.address" style="width: 350px" clearable />
          </el-form-item>

          <el-form-item label="电子邮箱" prop="email">
            <el-input v-model="form.email" style="width: 200px" clearable />
          </el-form-item>

          <el-form-item label="性别" prop="gender">
            <el-radio-group v-model="form.gender">
              <el-radio label="男" />
              <el-radio label="女" />
            </el-radio-group>
          </el-form-item>

          <el-form-item label="身份" prop="identity">
            <el-input v-model="form.identity" style="width: 200px" clearable />
          </el-form-item>

          <el-form-item label="简介" prop="intro">
            <el-input
              v-model="form.intro"
              type="textarea"
              :rows="4"
              placeholder="请输入内容"
            />
          </el-form-item>
          <el-form-item label="固定电话" prop="mobile">
            <el-input v-model="form.mobile" style="width: 200px" clearable />
          </el-form-item>
          <el-form-item label="姓名" prop="name">
            <el-input v-model="form.name" style="width: 120px" clearable />
          </el-form-item>
          <el-form-item label="QQ" prop="qicq">
            <el-input v-model="form.qicq" style="width: 200px" clearable />
          </el-form-item>
          <el-form-item label="电话号码" prop="tel">
            <el-input v-model="form.tel" style="width: 200px" clearable />
          </el-form-item>
          <el-form-item label="邮政编码" prop="zipcode">
            <el-input v-model="form.zipcode" style="width: 120px" clearable />
          </el-form-item>
        </el-form>
      </div>
      <div class="right" style="margin-left: 120px; margin-top: 26px">
        <el-upload
          style="
            border: 1px solid rgb(202, 200, 200);
            border-radius: 2%;
            text-align: center;
            justify-content: center;
            align-items: center;
            height: 180px;
            width: 180px;
          "
          ref="uploadRef"
          auto-upload="false"
          class="avatar-uploader"
          :show-file-list="false"
          :on-change="onSelectFile"
         
        >
          <img v-if="imgUrl" :src="imgUrl" class="avatar"   />
          <el-icon v-else class="avatar-uploader-icon" 
            ><icon-Plus
          /></el-icon>
        </el-upload>
        <br />
        <el-button
          style="font-size: small; width: 88px;"
          type="primary"
          @click="uploadRef.$el.querySelector('input').click()"
          ><el-icon> <icon-Plus /></el-icon> 选择图片</el-button
        >
        <el-button
          style="font-size: small; width: 88px;"
          type="success"
          @click="onUpdateAvatar"
          ><el-icon> <icon-Upload /></el-icon>上传头像</el-button
        >
      </div>
    </page-container>

    <div class="card-body"></div>
    <!-- 底部按钮 -->
    <el-form-item style="margin-left: 150px">
      <el-button type="primary" @click="submitForm">保存修改</el-button>
      <!-- 重置还差逻辑，并且需要id表单里的data -->
      <el-button type="info" @click="resetForm">重置</el-button>
    </el-form-item>
  </el-card>
</template>

<script setup>
import { ref } from 'vue'
// 假设引入store的数据，初始化imgUrl的值
// import { useUserStore } from '@/stores'
//引入用户头像更新的接口
// import { userUpdateAvatarService } from '@/apis/user'
// const userStore = useUserStore()
// const imgUrl = ref('userStore.user.user_pic')
const imgUrl = ref()
const uploadRef = ref()
const onSelectFile = (uploadFile) => {
  // 基于filereader读取图片做预览
  const reader = new FileReader()
  reader.readAsDataURL(uploadFile.raw)
  reader.onload = () => {
    imgUrl.value = reader.result
    console.log(imgUrl.value)
  }
}
const onUpdateAvatar = async () => {
  // 发送更新头像请求
  await userUpdateAvatarService(imgUrl.value)
  // userStore重新渲染
  await userStore.getUser()
  ElMessage.success('头像已保存')
}

// 提交表单验证逻辑
const ruleFormRef = ref()
// import { userUpdateInformationService } from '@/api/user'
// import { useUserStore } from '@/stores'
// import { useRouter } from 'vue-router'

const form = ref({
  address: '',
  email: '',
  gender: '',
  identity: '',
  intro: '',
  mobile: '',
  name: '',
  qicq: '',
  tel: '',
  zipcode: ''
})

//校验规则
// const rules = {
//   address: [{ trigger: 'blur' }],
//   email: [{ trigger: 'blur' }],
//   gender: [{ trigger: 'blur'} ],
//   identity: [{ trigger: 'blur'  } ],
//   intro: [{ trigger: 'blur'  } ],
//   mobile: [{  trigger: 'blur'  } ],
//   name: [{ trigger: 'blur'   } ],
//   qicq: [{ trigger: 'blur'  }  ],
//   zipcode: [{ trigger: 'blur'  }  ]
// }

//提交按钮的反馈逻辑
const submitForm = () => {
  // ruleFormRef.value.validate()
  // userUpdateInformationService(form.value)
  ElMessage.success('修改成功')
}

const resetForm = () => {
  ruleFormRef.value.resetFields()
}

//两次密码需要相同的校验
</script>

<style lang="scss" scoped>
.el-row {
  margin-bottom: 20px;
}
.el-row:last-child {
  margin-bottom: 0;
}

.grid-content {
  border-radius: 4px;
  min-height: 36px;
}
.avatar-uploader .el-upload {
  border: 1px dashed var(--el-border-color);
  border-radius: 6px;
  cursor: pointer;
  position: relative;
  overflow: hidden;
  transition: var(--el-transition-duration-fast);
}

.avatar-uploader .el-upload:hover {
  border-color: var(--el-color-primary);
}

.el-icon.avatar-uploader-icon {
  font-size: 28px;
  color: #8c939d;
  width: 178px;
  height: 178px;
  text-align: center;
}
</style>
