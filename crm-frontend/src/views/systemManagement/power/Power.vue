<template>
  <div class="container">
    <div class="app-container">
      <BaseDataList
        :table-column-attribute="sendData.tableColumnAttribute"
        :table-data="sendData.tableData"
        :handle-delete="handleDelete"
        :handle-edit="handleEdit"
        :use-pagination="sendData.usePagination"
        :page-sizes="sendData.pageSizes"
        :total="sendData.total"
        :use-header="sendData.useHeader"
        :title="sendData.title"
        @update-table-data="updateTableData"
        ref="baseDataListRef"
      >
        <template #treeMeau>
          <el-card class="tree-card">
            <div class="space-between">
              <div><h3>权限管理</h3></div>
              <el-button @click="handleRefresh">
                <el-icon>
                  <Refresh />
                </el-icon>
              </el-button>
            </div>
            <el-tree
              :data="sendTreeData"
              @node-click="handleNodeClick"
            ></el-tree>
          </el-card>
        </template>
        <template #menu>
          <div class="space-between">
            <div>
              <el-button @click="handleRefresh">
                <el-icon>
                  <Refresh />
                </el-icon>
                刷新
              </el-button>
              <el-button @click="handleAdd">
                <el-icon><Plus /></el-icon>
                添加
              </el-button>
            </div>
            <div class="search">
              <el-input v-model="searchData" placeholder="搜索"></el-input>
              <el-button
                type="primary"
                :icon="Search"
                style="margin-left: 10px; padding-left: 10px"
                @click="handleSearch"
              >
                搜索
              </el-button>
            </div>
          </div>
        </template>

        <template #empty>
          <el-empty class="emptyTable" description="没有数据"></el-empty>
        </template>
      </BaseDataList>
    </div>
    <el-drawer
      v-model="showEditDrawer"
      direction="rtl"
      :before-close="handleClose"
      ref="editDrawerRef"
    >
      <template #header>
        <h3>信息</h3>
      </template>
      <template #default>
        <div>
          <el-form v-model="editFormData">
            <el-form-item label="权限名称" prop="name"
              ><el-input v-model="editFormData.name"></el-input
            ></el-form-item>
            <el-form-item label="权限描述" prop="value"
              ><el-input v-model="editFormData.value"></el-input
            ></el-form-item>
          </el-form>
        </div>
      </template>
      <template #footer>
        <div class="space-between">
          <el-button @click="handleCancel">取消</el-button>
          <el-button type="primary" @click="saveEditData">保存数据</el-button>
        </div>
      </template>
    </el-drawer>
    <el-drawer
      v-model="showAddDrawer"
      direction="rtl"
      :before-close="handleClose"
    >
      <template #header>
        <h3>添加权限</h3>
      </template>
      <template #default>
        <div>
          <el-form
            v-model="addFormData"
            ref="addDrawerRef"
            :model="addFormData"
          >
            <el-form-item label="权限名称" prop="name"
              ><el-input v-model="addFormData.name"></el-input
            ></el-form-item>
            <el-form-item label="权限描述" prop="value"
              ><el-input v-model="addFormData.value"></el-input
            ></el-form-item>
          </el-form>
        </div>
      </template>
      <template #footer>
        <div class="space-between">
          <el-button @click="handleCancel">取消</el-button>
          <el-button type="primary" @click="saveAddData">保存数据</el-button>
        </div>
      </template>
    </el-drawer>
  </div>
</template>

<script setup>
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import useSysPower from '@/stores/sysManage/power.js'
import { Refresh, Search, Plus } from '@element-plus/icons-vue'
import { onMounted, ref, reactive } from 'vue'

const $store = useSysPower()

onMounted(() => {
  $store.getPowerList({ pageIndex: 1, pageSize: 10 })
})
const addFormData = reactive({
  name: '',
  value: ''
})

const editFormData = ref({
  name: '',
  value: ''
})

const sendData = reactive($store.sendData)
const sendTreeData = $store.sendTreeData
const showAddDrawer = ref(false)
const showEditDrawer = ref(false)

const addDrawerRef = ref()
const editDrawerRef = ref()
const handleAdd = () => {
  showAddDrawer.value = true
}

const handleEdit = (row) => {
  showEditDrawer.value = true
  //发请求回填数据
  console.log('当前的row', row)
  editFormData.value = row
}

const handleDelete = async (row) => {
  console.log('删除', row)
  const res = await $store.deletePower(row.id)
  console.log('res-in-delete', res)
  $store.getPowerList({
    pageIndex: $store.pageParams.pageIndex,
    pageSize: $store.pageParams.pageSize
  })
}

const handleSearch = () => {
  console.log('搜索', searchData.value)
}

const handleRefresh = () => {
  console.log('发请求刷新页面')
  // $store.loadTableData()
}
const saveAddData = async () => {
  const res = await $store.addPower(addFormData)

  if (res.code !== 10000) {
    ElMessage.error('失败message', res.message)
    return
  } else {
    ElMessage.success('添加成功')
    showAddDrawer.value = false
    $store.getPowerList({
      pageIndex: 1,
      pageSize: $store.pageParams.pageSize
    })
    addDrawerRef.value.resetFields()
  }
}

const saveEditData = () => {
  const res = $store.updatePower(editFormData.value)

  if (res.code !== 10000) {
    ElMessage.error('失败message', res.message)
    return
  } else {
    ElMessage.success('添加成功')
    showEditDrawer.value = false
    $store.getPowerList({
      pageIndex: 1,
      pageSize: $store.pageParams.pageSize
    })
    editDrawerRef.value.resetFields()
  }
}
const handleClose = (done) => {
  console.log('关闭前的confirm')
  done()
}

const handleNodeClick = (data) => {
  console.log('带着data的id发请求reload列表', data.id)
  // $store.loadTableData()
}
const handleCancel = () => {
  showAddDrawer.value = false
  console.log('取消')
}
const updateTableData = (pageSize, pageIndex) => {
  $store.pageParams = [pageSize, pageIndex]
  $store.getPowerList({ pageIndex, pageSize })
}
</script>

<style lang="scss" scoped>
.space-between {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 0 10px 20px;
}

.search {
  display: flex;
  align-items: center;
}

.tree-card {
  min-width: 200px;
  min-height: 500px;
  width: 300px;
  height: 600px;
  margin-right: 50px;
}
</style>
