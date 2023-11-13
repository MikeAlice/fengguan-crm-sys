<template>
  <el-dialog v-model="dialogVisible" title="批量导出" width="40%">
    <el-form>
      <el-form-item label="创建人">
        <ChooseSelect
          :options="createUser"
          des="选择创建人"
          ref="op1"
          @update:cid="setValue1()"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="归属人">
        <ChooseSelect
          :options="belongUser"
          des="选择归属人"
          ref="op2"
          @update:cid="setValue2()"
        ></ChooseSelect>
      </el-form-item>
    </el-form>
    <slot></slot>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible = false">取消</el-button>
        <el-button type="primary" @click="exportFile">导出</el-button>
      </span>
    </template>
  </el-dialog>
</template>

<script setup>
import { ref } from 'vue'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'
// import { utils, writeFileXLSX } from 'xlsx'

const props = defineProps({
  exportExcel: {
    type: Function,
    required: true
  }
  // // 表名
  // tableName: {
  //   type: String,
  //   required: true
  // },
  // //文件名
  // excelName: {
  //   type: String,
  //   required: true
  // }
})

// 创建人
const op1 = ref()
const value1 = ref('')
// 归属人
const op2 = ref()
const value2 = ref('')
let createUser = ref([
  {
    value: 1,
    label: 'test'
  },
  {
    value: 2,
    label: '管理员'
  },
  {
    value: 3,
    label: 'cw'
  }
])
let belongUser = ref([
  {
    value: 1,
    label: 'test'
  },
  {
    value: 2,
    label: '管理员'
  },
  {
    value: 3,
    label: 'cw'
  }
])
// 设置创建人的值
const setValue1 = () => {
  value1.value = op1.value.selectValue.value
}
// 设置归属人的值
const setValue2 = () => {
  value2.value = op2.value.selectValue.value
}
// 控制dialog是否显示
let dialogVisible = ref(false)

/* get state data and export to XLSX */
const exportFile = () => {
  // // 1.创建工作表
  // // 将json数据转化为sheet单元格
  // const ws = utils.json_to_sheet(rows.value)
  // // 2.创建工作书
  // // 用于加工工作簿
  // const wb = utils.book_new()
  // // 3。创建工作簿
  // // 将ws里的json数据放入工作薄里  命名为Data
  // utils.book_append_sheet(wb, ws, props.tableName) //'Data'
  // // 导出xlsx数据表文件
  // writeFileXLSX(wb, props.excelName) //'SheetJSVueAoO.xlsx'
  props.exportExcel(value1.value, value2.value)
  dialogVisible.value = false
  op1.value.reset()
  op2.value.reset()
}

const showDialog = () => {
  dialogVisible.value = true
}

defineExpose({ showDialog })
</script>

<style lang="scss" scoped>
.btn {
  display: block;
  margin-left: 45%;
  margin-top: 25px;
}
.dialog-footer {
  display: flex;
  justify-content: space-around;
}
</style>
