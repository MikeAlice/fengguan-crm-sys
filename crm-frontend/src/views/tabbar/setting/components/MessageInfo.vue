<template>
  <div>
    <el-button type="primary" @click="handlePlay('audio')">提示音</el-button>
    <audio id="audio" src="../../../../public/message.mp3" hidden></audio>
    <el-card
      shadow="hover"
      v-for="item in messageInfo.messageInfo"
      :key="item.id"
    >
      <div style="display: flex; justify-content: space-between">
        <span class="title" :class="item.flag === 1 ? 'read' : ''">
          {{ item.msgTitle }}
        </span>
        <el-tooltip
          class="box-item"
          effect="dark"
          content="标记为已读"
          placement="bottom"
          v-if="item.flag !== 1"
        >
          <el-button
            small="small"
            icon="IconCheck"
            circle
            @click="signRead(item)"
            v-if="item.flag !== 1"
          ></el-button>
        </el-tooltip>
      </div>
      <div class="content" :class="item.flag === 1 ? 'read' : ''">
        {{ item.remindTime }}
      </div>
    </el-card>
  </div>
</template>

<script setup>
import { onMounted } from 'vue'
import { queryMessageNotices, markAsRead } from '@/apis/systemPage/index.js'

import useMessageInfo from '@/stores/system-page/messageInfo.js'
import { ElMessage } from 'element-plus'

const messageInfo = useMessageInfo()

// 初始化数据
const getMessageInfo = () => {
  queryMessageNotices()
}
// 触发提示音
const handlePlay = (id) => {
  document.getElementById(id).play()
}
// 挂载时加载数据
onMounted(() => {
  getMessageInfo()
  setInterval(async () => {
    getMessageInfo()
    const flag = messageInfo.messageInfo.find((item) => {
      return item.flag === 1
    })
    if (!flag) {
      // handlePlay('audio')
    }
  }, 10000)
})

// 标记为已读
const signRead = (item) => {
  markAsRead(
    item.id,
    0,
    (response) => {
      getMessageInfo()
      ElMessage.success(response.data)
    },
    (error) => {
      ElMessage.error(error)
    }
  )
}
</script>

<style lang="scss" scoped>
.el-card {
  width: 400px;
  margin-bottom: 10px;
}
.title {
  color: #000;
  font-size: 18px;
}
.read {
  color: #999 !important;
}
.content {
  margin-top: 10px;
  color: #333;
}
</style>
