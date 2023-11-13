<template>
  <el-dialog v-model="dialogVisible" title="文件上传" width="40%">
    <el-upload
      v-model:file-list="fileList"
      class="upload-demo"
      :action="props.action"
      multiple
      :on-preview="handlePreview"
      :on-remove="handleRemove"
      :on-change="props.handleChange"
      :before-remove="beforeRemove"
      :limit="3"
      :on-exceed="handleExceed"
    >
      <el-button type="primary">点击上传文件</el-button>
      <template #tip>
        <div class="el-upload__tip">请上传excel格式的文件</div>
      </template>
    </el-upload>
    <slot></slot>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible = false">取消</el-button>
        <el-button type="primary" @click="importExcel">导入</el-button>
      </span>
    </template>
  </el-dialog>
</template>

<script setup>
// import Request from '@/apis/request'
// import { ElMessage } from 'element-plus'
import { ref } from 'vue'

const props = defineProps({
  // https://run.mocky.io/v3/9d059bf9-4660-45f2-925d-ce80ad6c4d15
  action: {
    type: String,
    required: true
  },
  importExcel: {
    type: Function,
    required: true
  },
  // 微调冰雾
  handleChange: {
    type: Function
  }
})
// 显示已上传文件，格式{name: '', url: ''}
const fileList = ref([])
// // 使用FormData的方式上传文件
// function uploadUseFormData(params) {
//   // 执行文件上传
//   Request.postFile(
//     props.path, //'/file/upload'
//     {
//       nickname: '小米',
//       age: 18,
//       file: params.file
//     },
//     { baseURL: props.baseURL } //'http://localhost:8090'
//   )
//     .then((res) => {
//       console.log(res)
//       ElMessage.success('上传成功')
//     })
//     .catch((res) => {
//       console.log(res)
//       ElMessage.error('上传失败')
//     })
// }

// // 使用Stream方式上传
// function uploadUseStream(params) {
//   // 执行文件上传
//   Request.postFileStream(
//     props.StreamPath, //'/user/modify-user?nickname=莉莉丝&age=10'
//     params.file,
//     (res) => {
//       console.log(res)
//       ElMessage.success('上传成功')
//     },
//     (err) => {
//       console.log(err)
//       ElMessage.error('上传失败')
//     },
//     { baseURL: props.baseURL }
//   )
// }

// 控制dialog是否显示
let dialogVisible = ref(false)

const importExcel = () => {
  props.importExcel(fileList)
  fileList.value = []
  dialogVisible.value = false
}

const showDialog = () => {
  dialogVisible.value = true
}

defineExpose({ showDialog })
</script>

<style scoped>
.wrap-space {
  padding: 5px;
}
.dialog-footer {
  display: flex;
  justify-content: space-around;
}
</style>
