<template>
  <div class="productbrand">
    <BaseDataList
      title="商品品牌"
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
              @click="addProductBrand"
              >添加</el-button
            >
          </div>
        </div>
      </template>
    </BaseDataList>
    <ProductBrandForm ref="productBrandFormRef"></ProductBrandForm>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import ProductBrandForm from '../components/FormCom/ProductBrandForm.vue'
const tableColumnAttribute = ref([
  {
    prop: 'brandName',
    label: '品牌名称'
  },
  {
    prop: 'brandPic',
    label: '品牌图片',
    usePic: true
  },
  {
    prop: 'brandInitial',
    label: '品牌首字母'
  },
  {
    prop: 'brandRecommend',
    label: '是否推荐',
    useSwitch: true
  },
  {
    prop: 'sort',
    label: '是否排序',
    sortable: true
  }
])
const handleDelete = () => {}
const handleEdit = () => {
  productBrandFormRef.value.visible = true
}
const productBrandFormRef = ref(null)
const tableData = [
  {
    brandName: '鸡蛋🥚',
    brandPic:
      'https://fuss10.elemecdn.com/e/5d/4a731a90594a4af544c0c25941171jpeg.jpeg',
    brandInitial: 'j',
    brandRecommend: true,
    sort: 99
  },
  {
    brandName: '鸡蛋🥚',
    brandPic:
      'https://fuss10.elemecdn.com/e/5d/4a731a90594a4af544c0c25941171jpeg.jpeg',
    brandInitial: 'j',
    brandRecommend: false,
    sort: 99
  },
  {
    brandName: '鸡蛋🥚',
    brandPic:
      'https://fuss10.elemecdn.com/e/5d/4a731a90594a4af544c0c25941171jpeg.jpeg',
    brandInitial: 'j',
    brandRecommend: true,
    sort: 99
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

const addProductBrand = () => {
  productBrandFormRef.value.visible = true
}
</script>

<style lang="scss" scoped>
.productbrand {
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
