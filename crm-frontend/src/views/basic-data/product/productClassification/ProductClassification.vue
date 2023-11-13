<template>
  <div class="ProductClassification">
    <Tree
      :data="productClassificationStore.treeData"
      @append="handleAdd"
      @remove="handleRemove"
      @submit="handleSubmit"
      @edit="handleEdit"
      @cancel="handleCancel"
      @close="handleClose"
      :handle-close="handleClose"
      ref="treeRef"
    >
      <template #header>
        <div class="content">
          <div class="left">
            <el-icon style="margin-right: 6px"><icon-message-box /></el-icon
            ><span style="font-size: 18px">商品分类</span>
          </div>
          <div class="right">
            <el-button
              type="primary"
              @click="
                () => {
                  treeRef.isEdit = false
                  treeRef.showDrawer = true
                }
              "
              >添加</el-button
            >
          </div>
        </div>
      </template>
      <template #form1>
        <el-form :model="data" :rules="rules" ref="formRef">
          <el-form-item label="分类名称" prop="name"
            ><el-input v-model="data.name"></el-input
          ></el-form-item>
          <el-form-item label="分类简称" prop="shortName"
            ><el-input v-model="data.shortName"></el-input
          ></el-form-item>
          <el-form-item label="上级分类" prop="parentId">
            <el-tree-select
              v-model="data.parentId"
              :data="productClassificationStore.treeData"
              :render-after-expand="false"
              check-strictly
            />
          </el-form-item>

          <el-form-item label="排序" prop="sortIndex">
            <el-input-number v-model="data.sortIndex" :min="1"
          /></el-form-item>

          <el-form-item label="是否启用" prop="visible"
            ><el-switch v-model="data.visible"
          /></el-form-item>

          <el-form-item label="关键字" prop="keywords"
            ><el-input v-model="data.keywords"></el-input
          ></el-form-item>

          <el-form-item label="描述" prop="description"
            ><el-input v-model="data.description" type="textarea"></el-input
          ></el-form-item>
        </el-form>
      </template>
    </Tree>
  </div>
</template>

<script setup>
import Tree from '@/components/Tree/Tree.vue'
import { ref, onMounted } from 'vue'
import { useProductClassificationStore } from '@/stores/basic-data/product/productclassification'
const productClassificationStore = useProductClassificationStore()
const treeRef = ref(null)
const data = ref({
  name: '',
  shortName: '',
  parentId: '',
  sortIndex: '',
  visible: true,
  keywords: '',
  description: ''
})
const goodsCategoryId = ref(0)
let loading = null
const formRef = ref(null)
const openLoading = () => {
  loading = ElLoading.service({
    lock: true,
    text: 'Loading',
    background: 'rgba(0, 0, 0, 0.7)'
  })
}

const rules = ref({
  name: [{ required: true, message: '请输入分类名称', trigger: 'blur' }],
  shortName: [{ required: true, message: '请输入分类简称', trigger: 'blur' }],
  description: [{ required: true, message: '请输入描述', trigger: 'blur' }],
  sortIndex: [{ required: true, message: '请输入排序', trigger: 'change' }],
  keywords: [{ required: true, message: '请输入关键字', trigger: 'blur' }]
})

const getTreeData = async () => {
  openLoading()
  await productClassificationStore.listGoodsCategoryNameTreeItem()
  loading.close()
}
const getTreeDataDetail = async (params) => {
  return await productClassificationStore.getGoodsCategoryItem(params)
}

const addTreeData = async (params) => {
  return await productClassificationStore.addGoodsCategoryItem(params)
}

const deleteTreeData = async (params) => {
  return await productClassificationStore.removeGoodsCategoryItem(params)
}

const modifyTreeData = async (params) => {
  return await productClassificationStore.modifyGoodsCategoryItem(params)
}

const handleAdd = () => {
  data.value = {
    name: '',
    shortName: '',
    parentId: '',
    sortIndex: '',
    visible: true,
    keywords: '',
    description: ''
  }
  treeRef.value.isEdit = false
  treeRef.value.showDrawer = true
}

const handleRemove = async (node) => {
  await deleteTreeData({ goodsCategoryId: node.id })
    .then((res) => {
      ElMessage({
        type: 'success',
        message: res.message
      })
    })
    .catch((err) => {
      ElMessage.error(err.data.message)
    })
  await getTreeData()
}

const handleEdit = async (node) => {
  openLoading()
  goodsCategoryId.value = node.id
  await getTreeDataDetail({
    goodsCategoryId: node.id
  }).then((res) => {
    if (res.data.parentId === 0) {
      res.data.parentId = ''
    }
    data.value = {
      ...res.data
    }
    loading.close()
  })
  treeRef.value.isEdit = true
  treeRef.value.showDrawer = true
}

const handleSubmit = async () => {
  formRef.value.validate(async (vaild) => {
    if (vaild) {
      const params = {
        ...data.value
      }
      if (treeRef.value.isEdit) {
        // 有点瑕疵，后面再说
        await modifyTreeData({
          ...params,
          goodsCategoryId: goodsCategoryId.value
        })
          .then((res) => {
            ElMessage({
              type: 'success',
              message: res.message
            })
          })
          .catch((err) => {
            ElMessage.error(err.data.message)
          })
      } else {
        params.parentId = params.parentId ? params.parentId : 0
        await addTreeData(params)
          .then((res) => {
            ElMessage({
              type: 'success',
              message: res.message
            })
          })
          .catch((err) => {
            ElMessage.error(err.data.message)
          })
      }
      await getTreeData()
      data.value = {
        name: '',
        shortName: '',
        parentId: '',
        sortIndex: '',
        visible: true,
        keywords: '',
        description: ''
      }
      treeRef.value.showDrawer = false
    }
  })
}

const handleCancel = () => {
  treeRef.value.showDrawer = false
}
const handleClose = () => {
  if (treeRef.value.isEdit) {
    data.value = {
      name: '',
      shortName: '',
      parentId: '',
      sortIndex: '',
      visible: true,
      keywords: '',
      description: ''
    }
  }
}

onMounted(async () => {
  await getTreeData()
})
</script>

<style lang="scss" scoped>
.ProductClassification {
  .content {
    width: 100%;
    display: flex;
    justify-content: space-between;
    align-items: center;
    margin-bottom: 10px;
    .left {
      display: flex;
      align-items: center;
    }
  }
}
</style>
