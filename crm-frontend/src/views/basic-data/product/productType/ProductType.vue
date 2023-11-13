<template>
  <div class="product-type">
    <BaseDataList
      title="商品类型"
      :table-column-attribute="tableColumnAttribute"
      :table-data="productTypeStore.tableData"
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
        <el-button type="primary" @click="handleAdd">添加</el-button>
      </template>
    </BaseDataList>
    <ProductTypeForm></ProductTypeForm>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import ProductTypeForm from '../components/FormCom/ProductTypeForm.vue'
import { useProductTypeStore } from '@/stores/basic-data/product/producttype'
const productTypeStore = useProductTypeStore()
const tableColumnAttribute = ref([
  {
    prop: 'attrName',
    label: '类型名称'
  },
  {
    prop: 'detailedTypeInfoDTOList',
    label: '属性标签'
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
const handleEdit = () => {}
const getTableData = async (params) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await productTypeStore.findSimpleTypeItem(params)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}
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

onMounted(async () => {
  await getTableData({ pageSize: 5, pageIndex: 1 })
})
</script>

<style lang="scss" scoped>
.product-type {
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
