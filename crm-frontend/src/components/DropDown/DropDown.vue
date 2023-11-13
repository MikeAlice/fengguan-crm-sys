<template>
  <!-- // 此组件的输入框的数目不是动态的  只有两个输入框 -->
  <div class="drop_down">
    <el-dropdown trigger="click" ref="dropdownRef" @visible-change="clearValue">
      <el-button type="primary">
        <el-icon><icon-caret-bottom /></el-icon>
      </el-button>
      <template #dropdown>
        <el-form>
          <!-- 输入框1 -->
          <el-form-item v-if="opt.includes(0)">
            <div style="padding: 0 10px">
              <h4
                style="
                  font-weight: 700;
                  margin-bottom: 2px;
                  color: #909399;
                  height: 26px;
                "
              >
                {{ props.inputTitle1 }}
              </h4>
              <el-input
                v-model="inputVal1"
                :placeholder="'搜索' + props.inputTitle1"
                @input="emits('update:inputValue1', inputVal1)"
              />
            </div>
          </el-form-item>
          <!-- 输入框2 -->
          <el-form-item v-if="opt.includes(1)">
            <div style="padding: 0 10px">
              <h4
                style="
                  font-weight: 700;
                  margin-bottom: 2px;
                  color: #909399;
                  height: 26px;
                "
              >
                {{ props.inputTitle2 }}
              </h4>
              <el-input
                v-model="inputVal2"
                :placeholder="'搜索' + props.inputTitle2"
                @input="emits('update:inputValue2', inputVal2)"
              />
            </div>
          </el-form-item>
          <!-- 输入框3 -->
          <el-form-item v-if="opt.includes(2)">
            <div style="padding: 0 10px">
              <h4
                style="
                  font-weight: 700;
                  margin-bottom: 2px;
                  color: #909399;
                  height: 26px;
                "
              >
                {{ props.inputTitle3 }}
              </h4>
              <el-input
                v-model="inputVal3"
                :placeholder="'搜索' + props.inputTitle3"
                @input="emits('update:inputValue3', inputVal3)"
              />
            </div>
          </el-form-item>
          <!-- 搜索按钮 -->
          <el-form-item v-if="opt.includes(3)">
            <div
              style="
                padding: 10px;
                display: flex;
                justify-content: flex-end;
                width: 100%;
              "
            >
              <el-button type="primary" @click="search">搜索</el-button>
            </div>
          </el-form-item>
        </el-form>
      </template>
    </el-dropdown>
  </div>
</template>

<script setup>
// 此组件的输入框的数目不是动态的  只有两个输入框
import { ref, onMounted } from 'vue'

const props = defineProps({
  inputValue1: {
    type: String
  },
  inputValue2: {
    type: String
  },
  inputValue3: {
    type: String
  },
  inputTitle1: {
    type: String,
    default: 'value1默认值'
  },
  inputTitle2: {
    type: String,
    default: 'value2默认值'
  },
  inputTitle3: {
    type: String,
    default: 'value3默认值'
  },
  getDropDown: {
    type: Function,
    default: () => {
      return [0, 1, 3]
    }
  }
})

// 展示的下拉框数量
let opt = ref([])

onMounted(() => {
  opt.value = props.getDropDown()
})

const clearValue = () => {
  inputVal1.value = inputVal2.value = inputVal3.value = ''
}
const inputVal1 = ref('')
const inputVal2 = ref('')
const inputVal3 = ref('')
const dropdownRef = ref(null)

const emits = defineEmits(['handleSearch'])
// handleSearch  用于调用父组件的搜索函数
const search = () => {
  if (
    (!inputVal1.value && !inputVal2.value && !inputVal3.value) ||
    (!inputVal1.value && !inputVal2.value)
  ) {
    ElMessage.error('输入不能为空')
  } else {
    emits('handleSearch')
    // 调用搜索函数后 关闭下拉菜单
    dropdownRef.value.$el.click()
  }
}
defineExpose({ inputVal1, inputVal2, inputVal3 })
</script>

<style lang="scss" scoped>
:deep(.el-form-item) {
  margin-bottom: 0;
}
</style>
