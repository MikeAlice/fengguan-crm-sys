<template>
  <div class="productspecification">
    <BaseDataList
      title="商品规格"
      :table-column-attribute="tableColumnAttribute"
      :table-data="tableData"
      :handle-delete="handleDelete"
      :handle-edit="handleEdit"
      :total="888"
      :page-sizes="[5, 10, 15]"
      @update-switch-state="handSwitchState"
      ref="baseDataListRef"
    >
      <template #ico
        ><el-icon><icon-message-box /></el-icon
      ></template>
      <template #menu>
        <div class="menu">
          <div class="left">
            <el-button
              type="primary"
              style="margin-right: 8px"
              @click="addSpecifications"
              >添加</el-button
            >
          </div>
        </div>
      </template>
    </BaseDataList>
    <ProductSpecificationFrom
      ref="productSpecificationFromRef"
      :title="title"
      :handle-submit="submit"
    ></ProductSpecificationFrom>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import ProductSpecificationFrom from '../components/FormCom/ProductSpecificationFrom.vue'
import BaseDataList from '@/components/DataList/BaseDataList.vue'
const productSpecificationFromRef = ref(null)
const title = ref('')
const tableColumnAttribute = ref([
  {
    prop: 'specificationsName',
    label: '商品规格'
  },
  {
    prop: 'specificationsValue',
    label: '规格值'
  },

  {
    prop: 'visible',
    label: '是否启用',
    useSwitch: true
  },
  {
    prop: 'sort',
    label: '排序',
    sortable: true
  }
])
const handleDelete = () => {}
const handleEdit = (row) => {
  title.value = '修改'
  productSpecificationFromRef.value.visible = true
  productSpecificationFromRef.value.form = {
    ...row
  }
}

const tableData = [
  {
    specificationsName: '鸡蛋🥚',
    specificationsValue: '鸡',
    visible: true,
    sort: 99
  },
  {
    specificationsName: '鸡蛋🥚',
    specificationsValue: '鸡',
    visible: true,
    sort: 98
  },
  {
    specificationsName: '鸡蛋🥚',
    specificationsValue: '鸡',
    visible: true,
    sort: 91
  }
]
const baseDataListRef = ref(null)
const handSwitchState = (state, row) => {
  console.log('调用后端的接口发请求修改开关的state后才能真正改变开关的状态')
  console.log('开关的状态已被修改，为：', state)
  console.log('当前行的数据', row)
  // 开启loading
  baseDataListRef.value.openSwitchLoading =
    !baseDataListRef.value.openSwitchLoading
  // 关闭loading  模拟异步请求
  setTimeout(() => {
    baseDataListRef.value.openSwitchLoading =
      !baseDataListRef.value.openSwitchLoading
  }, 1000)
}

const submit = () => {
  productSpecificationFromRef.value.form = {
    specificationsName: '',
    specificationsValue: '',
    visible: true,
    sort: 0
  }
  productSpecificationFromRef.value.visible = false
}

const addSpecifications = () => {
  title.value = '添加'
  productSpecificationFromRef.value.visible = true
}
</script>

<style lang="scss" scoped>
.productspecification {
  width: 100%;
  height: 100%;
  .menu {
    display: flex;
    align-items: center;
    justify-content: space-between;
    margin-bottom: 10px;
    .left {
      height: 40px;
    }
  }
}
</style>
