<script setup>
import { onMounted, ref } from 'vue'
import { InfoFilled } from '@element-plus/icons-vue'
// 这是气泡提示框 create by 暮秋pro
// 更新时间：23/10/20
// 这个megObj是用来自定义按钮和消息内容的
// btn: 按钮内容
// mes: 消息内容
/**
 * 正确调用示例：
 * <PopMessage
      :megObj="{ btn: '增加', mes: '你确认要增加吗？' }"
      @confirm="console.log('父组件监听到子组件点了确认')"
    ></PopMessage>
 */
const props = defineProps({
  megObj: {
    required: true,
    type: Object
  }
})
const defaultObj = ref({
  btn: '删除',
  mes: '你确认要执行该操作吗？'
})
onMounted(() => {
  // 开发调试时使用
  if (typeof props.megObj === 'string') {
    console.log('气泡组件调用失败，记得加上:,不然传过来的是字符串')
  }
  if (props.megObj instanceof Object) {
    console.log('气泡组件调用成功', props.megObj)
  }
})
// 定义子传父方法
const emit = defineEmits(['confirm'])
</script>

<template>
  <el-popconfirm
    width="220"
    confirm-button-text="确认"
    cancel-button-text="取消"
    :icon="InfoFilled"
    icon-color="#626AEF"
    :title="props.megObj.mes || defaultObj.mes"
    @confirm="emit('confirm')"
  >
    <template #reference>
      <el-button type="danger" plain size="small">{{
        props.megObj.btn || defaultObj.btn
      }}</el-button>
    </template>
  </el-popconfirm>
</template>
