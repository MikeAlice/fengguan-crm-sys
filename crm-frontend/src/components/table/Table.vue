<script setup>
import { ElMessage } from 'element-plus'
import { onMounted } from 'vue'

/**
 * dataArr:这是从后端接口拿到的数组对象
 * isSelect: 这是是否给表格添加多选框
 * 组件用法:template #default 这是插槽用法
 *          tableData: 表格父传子数据(数组对象)
 * <Table :dataArr="tableData" :isSelect="true">
      <template #default>
        <el-table-column label="操作">
          <template #default>
            <el-button size="small">编辑</el-button>
            <!-- <el-button
              size="small"
              type="danger"
              @click="handleDelete(scope.$index, scope.row)"
              >删除</el-button
            > -->
            <PopMessage
              :megObj="{ btn: '删除', mes: '你确认要删除吗？' }"
              @confirm="console.log('父组件监听到子组件点了确认')"
            ></PopMessage>
          </template>
        </el-table-column>
      </template>
      <template #footer> <p>这里可以合计表格数据</p> </template>
    </Table>
 */
const props = defineProps({
  dataArr: {
    type: Array,
    required: true
  },
  isSelect: {
    type: Boolean,
    default: false
  },
  isLoading: {
    type: Boolean,
    default: false
  }
})
onMounted(() => {
  if (!props.dataArr) {
    ElMessage.error('表格数据渲染失败')
  }
  console.log('表格父传子拿到的数组:', props.dataArr)
})
// 准备选中表格行数据
const handelSelect = (selection, row) => {
  console.log('表格行数据', row)
  emit('update:select', selection, row)
}
// 定义子传父的方法
// update:select => 用户点了选中框
const emit = defineEmits(['update:select'])
</script>
<template>
  <el-table
    :data="dataArr"
    style="width: 100% hight: 100%;"
    stripe
    height="100%"
    v-loading="props.isLoading"
    @select="handelSelect"
  >
    <el-table-column v-if="props.isSelect" type="selection" width="55" />

    <el-table-column
      v-for="(value, key) in props.dataArr[0]"
      :key="key"
      :prop="key"
      :label="key"
      width="180"
    />
    <slot></slot>

    <template #empty>
      <el-empty description="没有数据"></el-empty>
    </template>
  </el-table>
  <slot name="footer"></slot>
</template>
