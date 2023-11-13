<template>
  <el-dropdown>
    <el-button type="primary">
      批量操作<el-icon class="el-icon--right"><arrow-down /></el-icon>
    </el-button>
    <template #dropdown>
      <el-dropdown-menu>
        <el-dropdown-item @click="openExcle" v-if="opt.includes(0)"
          >批量导出</el-dropdown-item
        >
        <el-dropdown-item @click="openFileUpload" v-if="opt.includes(1)"
          >批量导入</el-dropdown-item
        >
        <el-dropdown-item @click="openPrint" v-if="opt.includes(2)"
          >打印表格</el-dropdown-item
        >
        <el-dropdown-item @click="openMsg" v-if="opt.includes(3)"
          >批量发短信</el-dropdown-item
        >
        <el-dropdown-item @click="openEmail" v-if="opt.includes(4)"
          >批量发邮件</el-dropdown-item
        >
        <el-dropdown-item @click="openDelete" v-if="opt.includes(5)"
          >批量删除</el-dropdown-item
        >
      </el-dropdown-menu>
    </template>
  </el-dropdown>
  <!-- 批量导出 -->
  <Excel :exportExcel="props.exportExcel" ref="excel">
    <slot name="excel"></slot>
  </Excel>
  <FileUpload
    ref="file"
    :action="props.action"
    :handle-change="props.handleChange"
    :importExcel="props.importExcel"
  >
    <slot name="file"></slot>
  </FileUpload>
  <!-- 批量发送短信 -->
  <Message ref="message" title="发送短信" :send="props.msgSend"> </Message>
  <!-- 批量发送邮件 -->
  <Message ref="email" title="发送邮件" :send="props.emailSend"> </Message>
  <!-- 删除确认 -->
  <el-dialog
    v-model="confirmDelete"
    title="删除"
    width="30%"
    :before-close="(deleteId = null)"
  >
    <span style="color: red; margin-left: 33%; font-size: 24px"
      >是否确认删除</span
    >
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="confirmDelete = false">取消</el-button>
        <el-button type="danger" @click="confirmsDelete"> 确定 </el-button>
      </span>
    </template>
  </el-dialog>
</template>

<script setup>
import { ArrowDown } from '@element-plus/icons-vue'
import { ref, onMounted } from 'vue'
import Excel from '@/components/BulkOpe/Excel.vue'
import FileUpload from '@/components/BulkOpe/FileUpload.vue'
import Message from '@/components/BulkOpe/Message.vue'

const props = defineProps({
  // 定义该批量操作需要几个功能，0为批量导出，1为批量导入，2为批量发短信，3为批量发邮件，4为批量删除
  getOpt: {
    type: Function,
    default: () => {
      return [0, 1, 2, 3, 4]
    }
  },
  // 弹窗点击导出按钮的回调，用于向后端发送导出请求，获取下载链接
  exportExcel: {
    type: Function,
    default: () => {}
  },
  // 导入弹窗，上传文件的全路径
  action: {
    type: String,
    default: '/'
  },
  baseURL: {
    type: String,
    default: '/'
  },
  // 点击导入按钮回调，FileUpload组件会传过来一个fileList数组，存放的是文件对象，对象格式{name: '', url: ''}
  importExcel: {
    type: Function,
    default: (fileList) => {
      console.log(fileList)
    }
  },
  // 弹窗发送消息按钮回到，改函数必须传入参数必须定义title（消息标题）、desc（简单描述）
  // 点击按钮，这两个值会由Message组件传递过来，该函数内部只需要调接口就行，接口所需数据即为title和desc
  msgSend: {
    type: Function,
    default: (title, desc) => {
      console.log(title, desc)
    }
  },
  // 弹窗发送邮件按钮回到，改函数必须传入参数必须定义title（消息标题）、desc（简单描述）
  // 点击按钮，这两个值会由Message组件传递过来，该函数内部只需要调接口就行，接口所需数据即为title和desc
  emailSend: {
    type: Function,
    default: (title, desc) => {
      console.log(title, desc)
    }
  },
  // 弹窗批量删除操作回调
  confirmsDelete: {
    type: Function,
    default: () => {}
  },
  // 微调冰雾
  handleChange: {
    type: Function
  }
})

const excel = ref()

const file = ref()

const message = ref()

const email = ref()

const confirmDelete = ref(false)

let opt = ref([])

onMounted(() => {
  opt.value = props.getOpt()
})

// 打开导出弹窗
const openExcle = () => {
  excel.value.showDialog()
}
// 打开导入弹窗
const openFileUpload = () => {
  file.value.showDialog()
}
// 打开发送邮件或者发送短信弹窗
const openMsg = () => {
  message.value.showDialog()
}
// 打开发送邮件或者发送短信弹窗
const openEmail = () => {
  email.value.showDialog()
}
// 打开批量删除按钮的弹窗
const openDelete = () => {
  confirmDelete.value = true
}
const confirmsDelete = () => {
  props.confirmsDelete()
  confirmDelete.value = false
}
</script>

<style lang="scss" scoped>
.example-showcase .el-dropdown-link {
  cursor: pointer;
  color: var(--el-color-primary);
  display: flex;
  align-items: center;
}
.dialog-footer {
  display: flex;
  justify-content: space-around;
}
</style>
