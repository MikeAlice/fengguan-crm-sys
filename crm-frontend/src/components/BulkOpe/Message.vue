<template>
  <el-dialog v-model="dialogVisible" :title="props.title" width="40%">
    <el-form>
      <el-form-item label="消息标题">
        <el-select v-model="value" class="m-2" placeholder="请选择消息标题">
          <el-option
            v-for="item in options"
            :key="item.value"
            :label="item.label"
            :value="item.value"
          />
        </el-select>
      </el-form-item>
      <el-form-item label="简单描述">
        <el-input
          v-model="desc"
          maxlength="50"
          show-word-limit
          type="textarea"
        />
      </el-form-item>
    </el-form>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible = false">取消</el-button>
        <el-button type="primary" @click="send"> {{ props.title }} </el-button>
      </span>
    </template>
  </el-dialog>
</template>

<script setup>
import { ref } from 'vue'
const props = defineProps({
  choose: {
    type: Array,
    required: true
  },
  title: {
    type: String,
    required: true
  },
  send: {
    type: Function,
    required: true,
    default: () => {}
  }
})
// 简单描述
let desc = ref('')
// 控制dialog是否显示
let dialogVisible = ref(false)

const options = [
  {
    value: 1,
    label: '节日祝福'
  },
  {
    value: 2,
    label: '新品推荐'
  },
  {
    value: 3,
    label: '预约提醒'
  }
]

// 消息标题
const value = ref('')

const showDialog = () => {
  dialogVisible.value = true
}

// 店家发送按钮的回调
const send = () => {
  props.send(value.value, desc.value)
  ;(value.value = ''), (desc.value = ''), (dialogVisible.value = false)
}

defineExpose({ showDialog })
</script>

<style scoped>
.dialog-footer {
  display: flex;
  justify-content: space-around;
}
</style>
