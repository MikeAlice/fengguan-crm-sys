<template>
  <div class="IncomeType">
    <Tree
      :data="incomeTypeStore.treeData"
      @append="handleAdd"
      @remove="handleRemove"
      @submit="handleSubmit"
      @edit="handleEdit"
      ref="treeRef"
    >
      <template #header>
        <div class="content">
          <div class="left">
            <el-icon style="margin-right: 6px"><icon-message-box /></el-icon
            ><span style="font-size: 18px">费用收入类型</span>
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
        <el-form :model="data" ref="formRef">
          <el-form-item label="分类名称" prop="typeName"
            ><el-input v-model="data.name"></el-input
          ></el-form-item>
          <el-form-item label="父级栏目" prop="parentid">
            <el-tree-select
              v-model="data.parentid"
              :data="incomeTypeStore.treeData"
              :render-after-expand="false"
            />
          </el-form-item>

          <el-form-item label="排位序号" prop="sort"
            ><el-input v-model="data.sort"></el-input
          ></el-form-item>

          <el-form-item label="是否启用" prop="visible"
            ><el-switch v-model="data.visible"
          /></el-form-item>

          <el-form-item label="描述" prop="intro"
            ><el-input v-model="data.intro" type="textarea"></el-input
          ></el-form-item>
        </el-form>
      </template>
    </Tree>
  </div>
</template>

<script setup>
import Tree from '@/components/Tree/Tree.vue'
import { ref, onMounted } from 'vue'
import { useIncomeTypeStore } from '@/stores/basic-data/financial-type/incometype'
const incomeTypeStore = useIncomeTypeStore()
const treeRef = ref(null)
let loading = null
const openLoading = () => {
  loading = ElLoading.service({
    lock: true,
    text: 'Loading',
    background: 'rgba(0, 0, 0, 0.7)'
  })
}
const formRef = ref(null)
const treeId = ref('')
const data = ref({
  name: '',
  parentid: '',
  sort: '',
  visible: true,
  intro: ''
})

const getTreeData = async () => {
  await incomeTypeStore.queryAllFeeincomeItem()
}
const addTreeData = async (params) => {
  return await incomeTypeStore.addFeeincomeItem(params)
}
const modifyTreeData = async (params) => {
  return await incomeTypeStore.modifyFeeincomeItem(params)
}

const deleteTreeData = async (params) => {
  return await incomeTypeStore.deleteeeincomeItem(params)
}
const handleAdd = () => {
  data.value = {
    name: '',
    parentid: '',
    sort: '',
    visible: true,
    intro: ''
  }
  treeRef.value.isEdit = false
  treeRef.value.showDrawer = true
}

const handleRemove = async (node) => {
  await deleteTreeData({ id: node.id })
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

const handleEdit = (node) => {
  treeId.value = node.id
  treeRef.value.isEdit = true
  treeRef.value.showDrawer = true
  node.visible = node.visible ? true : false
  node.parentid = node.parentid ? node.parentid : ''
  data.value = {
    ...node
  }
}

const handleSubmit = () => {
  formRef.value.validate(async (vaild) => {
    if (vaild) {
      const { name, parentid, sort, visible, intro } = data.value
      console.log('daaa', data.value)
      const params = { name, parentid, sort, visible, intro }
      params.visible = params.visible ? 1 : 0
      params.parentid = params.parentid ? params.parentid : 0
      if (treeRef.value.isEdit) {
        params
        await modifyTreeData({
          ...params,
          id: treeId.value
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
        await addTreeData({
          ...params,
          id: treeId.value
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

onMounted(async () => {
  await getTreeData()
})
</script>

<style lang="scss" scoped>
.IncomeType {
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
