<template>
  <div class="RegionalForm">
    <el-drawer v-model="visible" @close="handleClear">
      <template #header>
        <h4>{{ props.title }}</h4>
      </template>
      <template #default>
        <el-form :model="form" :rules="rules" ref="formRef">
          <el-form-item label="品牌名称" prop="typeName">
            <el-input
              placeholder="请输入品牌名称"
              v-model="form.areaName"
            ></el-input>
          </el-form-item>
          <el-form-item label="品牌首字母" prop="typeName">
            <el-input
              placeholder="请输入品牌首字母"
              v-model="form.areaName"
            ></el-input>
          </el-form-item>
          <el-form-item label="品牌图片" prop="typeName">
            <el-upload
              class="avatar-uploader"
              :show-file-list="false"
              auto-upload="false"
            >
              <img v-if="imageUrl" :src="imageUrl" class="avatar" />
              <el-icon v-else class="avatar-uploader-icon"
                ><icon-plus></icon-plus
              ></el-icon>
            </el-upload>
          </el-form-item>
          <el-form-item label="排序" prop="sort">
            <el-input-number
              v-model="form.sort"
              :min="0"
              @change="handleChange"
            />
          </el-form-item>
          <el-form-item label="是否推荐">
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
const chooseSelectRef = ref(null)
const form = ref({
  areaName: '',
  sort: 0,
  visible: false,
  areaInfo: ''
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
  // typeName: [{ required: true, message: '请输入分类名称', trigger: 'blur' }],
  // sort: [{ required: true, message: '', trigger: 'blur' }]
})

const handleClear = () => {
  if (props.title === '修改') {
    form.value = {
      areaName: '',
      sort: 0,
      visible: false,
      areaInfo: ''
    }
    // typeTag = ''
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

<style lang="scss" scoped>
.avatar-uploader {
  :deep() {
    .avatar {
      width: 120px;
      height: 120px;
      display: block;
    }

    .el-upload {
      border: 1px dashed var(--el-border-color);
      border-radius: 6px;
      cursor: pointer;
      position: relative;
      overflow: hidden;
      transition: var(--el-transition-duration-fast);
    }

    .el-upload:hover {
      border-color: var(--el-color-primary);
    }

    .el-icon.avatar-uploader-icon {
      font-size: 28px;
      color: #8c939d;
      width: 120px;
      height: 120px;
      text-align: center;
    }
  }
}
</style>
