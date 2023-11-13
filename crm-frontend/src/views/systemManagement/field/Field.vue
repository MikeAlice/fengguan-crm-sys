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
        @update-table-data="get"
        @updateSwitchState="handleSwitch"
        ref="baseDataListRef"
      >
        <template #treeMeau>
          <el-card class="tree-card">
            <div class="space-between">
              <div><h3>表单管理</h3></div>
            </div>
            <div v-for="item in $store.sendSideData" :key="item">
              <el-link type="primary" @click="handleLinkClick(item)">{{
                item
              }}</el-link>
            </div>
          </el-card>
        </template>
        <template #menu>
          <div class="space-between">
            <div>
              <el-button @click="handleAdd" type="primary">
                <el-icon><Plus /></el-icon>
                添加
              </el-button>
              <el-button type="danger" @click="handleBatchDelete"
                >批量删除</el-button
              >
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
    >
      <template #header>
        <h3>信息</h3>
      </template>
      <template #default>
        <div>
          <el-form v-model="editFormData">
            <el-form-item label="表单提示文字" prop="tishiwenzi"
              ><el-input v-model="editFormData.tishiwenzi"></el-input
            ></el-form-item>
            <el-form-item label="字段名称" prop="ziduanmingcheng"
              ><el-input
                v-model="editFormData.ziduanmingcheng"
                disabled
              ></el-input
            ></el-form-item>
            <el-form-item label="数据类型" prop="leixing">
              <el-select
                v-model="editFormData.leixing"
                class="m-2"
                placeholder="Select"
                size="large"
              >
                <el-option
                  v-for="item in sendSelectData"
                  :key="item"
                  :label="item"
                  :value="item"
                ></el-option>
              </el-select>
            </el-form-item>
            <el-form-item label="默认值" prop="morenzhi">
              <el-input
                v-model="editFormData.morenzhi"
                type="textarea"
              ></el-input>
            </el-form-item>
            <el-form-item label="最大值" prop="zuidazhi">
              <el-input v-model="editFormData.zuidazhi"></el-input>
            </el-form-item>
            <el-form-item label="是否启用" prop="shifouqiyong">
              <el-checkbox
                v-model="editFormData.shifouqiyong"
                size="large"
              ></el-checkbox>
            </el-form-item>
            <el-form-item label="是否验证">
              <el-checkbox
                v-model="editFormData.data.value"
                size="large"
              ></el-checkbox>
            </el-form-item>
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
        <h3>栏目添加</h3>
      </template>
      <template #default>
        <div>
          <el-form v-model="addFormData" ref="addDrawerRef">
            <el-form-item label="表单提示文字" prop="tishiwenzi"
              ><el-input v-model="addFormData.tishiwenzi"></el-input
            ></el-form-item>
            <el-form-item label="字段名称" prop="ziduanmingcheng"
              ><el-input v-model="addFormData.ziduanmingcheng"></el-input
            ></el-form-item>
            <el-form-item label="数据类型" prop="leixing">
              <el-select
                v-model="addFormData.leixing"
                class="m-2"
                placeholder="Select"
                size="large"
              >
                <el-option
                  v-for="item in sendSelectData"
                  :key="item"
                  :label="item"
                  :value="item"
                ></el-option>
              </el-select>
            </el-form-item>
            <el-form-item label="默认值" prop="morenzhi">
              <el-input
                v-model="addFormData.morenzhi"
                type="textarea"
              ></el-input>
            </el-form-item>
            <el-form-item label="最大值" prop="zuidazhi">
              <el-input v-model="addFormData.zuidazhi"></el-input>
            </el-form-item>
            <el-form-item label="是否启用" prop="shifouqiyong">
              <el-checkbox
                v-model="addFormData.shifouqiyong"
                size="large"
              ></el-checkbox>
            </el-form-item>
            <el-form-item label="是否验证">
              <el-checkbox
                v-model="addFormData.data.value"
                size="large"
              ></el-checkbox>
            </el-form-item>
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
import useSysField from '@/stores/sysManage/field.js'
import { Search, Plus } from '@element-plus/icons-vue'
import { ElMessage } from 'element-plus'
import { onMounted, ref, reactive } from 'vue'
const $store = useSysField()

onMounted(() => {
  $store.getTableData(1, 10)
})

const addFormData = reactive({
  tishiwenzi: '',
  ziduanmingcheng: '',
  leixing: '',
  morenzhi: '',
  zuidazhi: '',
  shifouqiyong: '',
  data: {
    value: '',
    tagType: 'success'
  }
})

const editFormData = ref({
  tishiwenzi: '',
  ziduanmingcheng: '',
  leixing: '',
  morenzhi: '',
  zuidazhi: '',
  shifouqiyong: '',
  data: {
    value: '',
    tagType: 'success'
  }
})

const searchData = ref('')

const sendData = reactive($store.sendData)
const sendSelectData = reactive($store.sendSelectData)
const showAddDrawer = ref(false)
const showEditDrawer = ref(false)

const addLinkData = ref('')
const addDrawerRef = ref()
const handleAdd = () => {
  if (!addLinkData.value) {
    ElMessage.error('请点击左侧需要操作的表单，再添加字段')
    return
  }
  showAddDrawer.value = true
}

const handleEdit = (row) => {
  showEditDrawer.value = true
  //发请求回填数据
  console.log('当前的row', row)
  //TODO - 根据后端字段决定
  editFormData.value = row
  editFormData.value.shifouqiyong === '是'
    ? (editFormData.value.shifouqiyong = true)
    : (editFormData.value.shifouqiyong = false)

  editFormData.value.data.value === '是'
    ? (editFormData.value.data.value = true)
    : (editFormData.value.data.value = false)
}

const handleDelete = (row) => {
  console.log('删除', row)
}

const handleBatchDelete = () => {
  console.log('批量删除')
}
const handleSearch = () => {
  console.log('搜索', searchData.value)
}

const saveAddData = () => {
  console.log(
    '带着data',
    addFormData,
    '和linkData',
    addLinkData.value,
    '发add请求'
  )
  showAddDrawer.value = false
  //解promise之后:
  ElMessage.success('添加成功')
  addDrawerRef.value.resetFields()
}

const saveEditData = () => {
  console.log('带着data', editFormData, '发edit请求')
  showEditDrawer.value = false
}
const handleClose = (done) => {
  console.log('关闭前的confirm')
  done()
}

const handleLinkClick = (link) => {
  console.log('handleLinkClick,带这个发请求', link)
  //把这个data存下来，add的时候带上
  addLinkData.value = link
  // $store.loadTableData()
}
const handleCancel = () => {
  showAddDrawer.value = false
  console.log('取消')
}

const handleSwitch = () => {
  console.log('发请求改变状态')
}

const get = (pageSize, currentPage) => {
  console.log('调用父组件的更新数据的函数')
  console.log('pageSize', pageSize)
  console.log('currentPage', currentPage)
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

.side {
  padding-bottom: 20px;
  border-bottom: 1px solid lightgrey;
}

.tree-card {
  min-width: 200px;
  min-height: 500px;
  width: 300px;
  height: 600px;
  margin-right: 50px;
}

:deep(.el-link__inner) {
  margin-left: 10px;
}
</style>
