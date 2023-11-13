<template>
  <el-card>
    <!-- 头部 -->
    <header>
      <h3>
        <slot name="ico"></slot>
        <div style="margin-left: 8px">供应商列表</div>
      </h3>
    </header>
    <!-- 操作搜索栏 -->
    <section class="menu">
      <div class="left">
        <el-button
          type="primary"
          icon="IconPlus"
          @click="addorupdate.addMyClinet()"
          >添加</el-button
        >
        <el-popconfirm
          :title="`你确定要删除这些选择的客户吗?`"
          width="260px"
          @confirm="deleteByQuery"
        >
          <template #reference>
            <el-button
              type="danger"
              icon="IconDelete"
              style="margin-right: 10px"
              :disabled="selectIdArr.length ? false : true"
              >批量删除</el-button
            >
          </template>
        </el-popconfirm>
      </div>
      <div class="right" style="display: flex">
        <el-input
          v-model="content"
          placeholder="输入供应商名称关键字"
          style="margin-right: 4px; width: 200px"
        />
        <div class="drop_down">
          <el-dropdown
            trigger="click"
            ref="dropdownRef"
            @visible-change="clearValue"
          >
            <el-button type="primary">
              <el-icon><icon-caret-bottom /></el-icon>
            </el-button>
            <template #dropdown>
              <el-form>
                <!-- 输入框1 -->
                <el-form-item>
                  <div style="padding: 0 10px">
                    <h4
                      style="
                        font-weight: 700;
                        margin-bottom: 2px;
                        color: #909399;
                        height: 26px;
                      "
                    >
                      电话
                    </h4>
                    <el-input v-model="tel" placeholder="搜索电话" />
                  </div>
                </el-form-item>
                <!-- 输入框2 -->
                <el-form-item>
                  <div style="padding: 0 10px">
                    <h4
                      style="
                        font-weight: 700;
                        margin-bottom: 2px;
                        color: #909399;
                        height: 26px;
                      "
                    >
                      通讯地址
                    </h4>
                    <el-input v-model="address" placeholder="搜索通信地址" />
                  </div>
                </el-form-item>
                <!-- 搜索按钮 -->
                <el-form-item>
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
        <el-button
          type="primary"
          style="margin-left: 4px"
          @click="searchDetails"
          :disabled="content ? false : true"
          icon="IconSearch"
        >
          搜索</el-button
        >
      </div>
    </section>
    <!-- 表格部分 -->
    <el-table
      style="width: 100%; margin-bottom: 20px"
      table-layout="auto"
      :data="supplierList.tableData"
      @selection-change="selectChange"
    >
      <el-table-column type="selection" width="55" />
      <el-table-column
        label="供应商名称"
        prop="name"
        sortable
      ></el-table-column>
      <el-table-column label="经济类型" prop="ecitype"></el-table-column>
      <el-table-column label="行业类型" prop="trade"></el-table-column>
      <el-table-column label="联系人" prop="linkman_name"></el-table-column>
      <el-table-column label="电话号码" prop="tel"></el-table-column>
      <el-table-column label="传真" prop="fax"></el-table-column>
      <el-table-column label="邮箱" prop="email"></el-table-column>
      <el-table-column label="介绍" prop="intro"></el-table-column>
      <el-table-column label="操作" fixed="right">
        <template #default="{ row }">
          <el-dropdown>
            <el-button type="primary">
              操作<el-icon class="el-icon--right"><arrow-down /></el-icon>
            </el-button>
            <template #dropdown>
              <el-dropdown-menu>
                <el-dropdown-item @click="addcontact.addContact(row)">
                  添加联系人
                </el-dropdown-item>
                <el-dropdown-item @click="addorupdate.modify(row)">
                  修改
                </el-dropdown-item>
                <el-dropdown-item @click="Deletes(row)">删除</el-dropdown-item>
              </el-dropdown-menu>
            </template>
          </el-dropdown>
        </template>
      </el-table-column>
      <template #empty>
        <el-empty description="没有数据"></el-empty>
      </template>
    </el-table>
    <!-- 分页器 -->
    <el-pagination
      v-model:current-page="currentPage"
      v-model:page-size="pageSize"
      :page-sizes="[5, 10, 20, 50]"
      :total="supplierList.pageTotal"
      layout="prev, pager, next, jumper, ->, total, sizes"
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
    />
  </el-card>
  <!-- 添加或修改客户信息 -->
  <AddOrUpdateSupplier ref="addorupdate"></AddOrUpdateSupplier>
  <!-- 添加联系人 -->
  <AddContact ref="addcontact"></AddContact>
  <!-- 删除确认 -->
  <el-dialog v-model="confirmDelete" title="删除" width="30%">
    <span style="color: red; margin-left: 33%; font-size: 24px"
      >是否确认删除</span
    >
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="confirmDelete = false">取消</el-button>
        <el-button type="danger" @click="Confirms"> 确定 </el-button>
      </span>
    </template>
  </el-dialog>
</template>

<script setup>
import { ref, onMounted, provide } from 'vue'
import { ArrowDown } from '@element-plus/icons-vue'

import useSupplierList from '@/stores/supplier/list/list.js'
import { getSupplier, removeSupplier } from '@/apis/supplier/supplierList.js'
import AddOrUpdateSupplier from './components/AddOrUpdateSupplier.vue'
import AddContact from './components/AddContact.vue'

const addorupdate = ref()

const addcontact = ref()

const supplierList = useSupplierList()

// 初始化数据
const initLinks = async (
  currentPage,
  pageSize,
  name,
  telephone,
  mombile,
  address
) => {
  await getSupplier(currentPage, pageSize, name, telephone, mombile, address)
}
onMounted(() => {
  initLinks(currentPage.value, pageSize.value)
})

const inits = () => {
  initLinks(currentPage.value, pageSize.value)
}

provide('inits', inits)

// 当前页数
const currentPage = ref(1)
// 每页数据
const pageSize = ref(5)
const handleSizeChange = (val) => {
  pageSize.value = val
  initLinks(currentPage.value, pageSize.value)
}
const handleCurrentChange = (val) => {
  currentPage.value = val
  initLinks(currentPage.value, pageSize.value)
}

/**
 * 批量删除
 */
// 存储批量删除的客户的id
let selectIdArr = ref([])
// table复选框勾选时触发的事件
const selectChange = (value) => {
  selectIdArr.value = value
}
// 批量删除按钮
const deleteByQuery = () => {
  let data = []
  selectIdArr.value.forEach((item) => {
    data.push(item.supplier_id)
  })
  removeSupplier(
    data,
    () => {
      ElMessage.success('删除成功')
      inits()
    },
    () => {
      ElMessage.error('删除失败')
    }
  )
  // 删除后重新请求数据
  initLinks(currentPage.value, pageSize.value)
}

/**
 * 搜索
 */
const content = ref('')
const tel = ref('')
const address = ref('')
const searchDetails = () => {
  initLinks(
    currentPage.value,
    pageSize.value,
    content.value,
    tel.value,
    address.value,
    () => {
      ElMessage.success('搜索成功')
    },
    () => {
      ElMessage.error('搜索出错')
    }
  )
  content.value = ''
}
const dropdownRef = ref(null)
const clearValue = () => {
  tel.value = address.value = ''
}
const search = () => {
  if (!tel.value && !address.value) {
    ElMessage.error('输入不能为空')
  } else {
    searchDetails()
    // 调用搜索函数后 关闭下拉菜单
    dropdownRef.value.$el.click()
  }
}

/**
 * 删除
 */
const confirmDelete = ref(false)
const deleteId = ref()
// 删除按钮回调
const Deletes = (row) => {
  deleteId.value = row.supplier_id
  confirmDelete.value = true
}
const Confirms = async () => {
  await removeSupplier(
    [deleteId.value],
    () => {
      ElMessage.success('删除成功')
      deleteId.value = ''
      inits()
    },
    () => {
      ElMessage.error('删除失败')
    }
  )
  confirmDelete.value = false
}
</script>

<style lang="scss" scoped>
header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 20px;
}
.menu {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 10px;
}
.dialog-footer {
  display: flex;
  justify-content: space-around;
}
:deep(.el-form-item) {
  margin-bottom: 0;
}
</style>
