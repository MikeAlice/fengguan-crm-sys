<template>
  <el-card>
    <!-- 头部 -->
    <header>
      <h3>
        <slot name="ico"></slot>
        <div style="margin-left: 8px">出库单</div>
      </h3>
    </header>
    <!-- 操作搜索栏 -->
    <section class="menu">
      <div class="left">
        <el-popconfirm
          :title="`你确定要删除这些选择的出库单吗?`"
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
          placeholder="输入主题"
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
                <el-form-item class="el-form-items">
                  <div style="padding: 0 10px">
                    <h4
                      style="
                        font-weight: 700;
                        margin-bottom: 2px;
                        color: #909399;
                        height: 26px;
                      "
                    >
                      仓库编号
                    </h4>
                    <el-input v-model="name" placeholder="搜索仓库编号" />
                  </div>
                </el-form-item>
                <!-- 输入框2 -->
                <el-form-item class="el-form-items">
                  <div style="padding: 0 10px">
                    <h4
                      style="
                        font-weight: 700;
                        margin-bottom: 2px;
                        color: #909399;
                        height: 26px;
                      "
                    >
                      入库状态
                    </h4>
                    <el-input v-model="address" placeholder="搜索入库状态" />
                  </div>
                </el-form-item>
                <!-- 搜索按钮 -->
                <el-form-item class="el-form-items">
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
      :data="storageDetailsStore.tableData"
      @selection-change="selectChange"
    >
      <el-table-column type="selection" width="55" />
      <el-table-column label="商品id" prop="goods_id"></el-table-column>
      <el-table-column label="SKUID" prop="sku_id"></el-table-column>
      <el-table-column label="商品名" prop="goods_name"></el-table-column>
      <el-table-column label="SKU名" prop="sku_name"></el-table-column>
      <el-table-column label="数量" prop="number"></el-table-column>
      <el-table-column label="商品类型" prop="category_name"></el-table-column>
      <el-table-column label="仓库名称" prop="store_name"></el-table-column>
      <el-table-column
        label="对应出库单"
        prop="out_stock_order"
      ></el-table-column>
      <el-table-column label="出库时间" prop="out_time"></el-table-column>
      <el-table-column label="备注" prop="remarks"></el-table-column>
      <el-table-column
        label="供应商名称"
        prop="supplier_name"
      ></el-table-column>
      <el-table-column label="创建人" prop="create_user_id"></el-table-column>
      <el-table-column label="创建时间" prop="create_time"></el-table-column>
      <el-table-column label="操作" fixed="right">
        <template #default="{ row }">
          <el-dropdown>
            <el-button type="primary">
              操作<el-icon class="el-icon--right"><arrow-down /></el-icon>
            </el-button>
            <template #dropdown>
              <el-dropdown-menu>
                <el-dropdown-item @click="modify(row)">入库</el-dropdown-item>
                <el-dropdown-item @click="Deletes(row)">删除</el-dropdown-item>
              </el-dropdown-menu>
            </template>
          </el-dropdown>
        </template>
      </el-table-column>
    </el-table>
    <!-- 分页器 -->
    <el-pagination
      v-model:current-page="currentPage"
      v-model:page-size="pageSize"
      :page-sizes="[5, 10, 20, 50]"
      :total="storageDetailsStore.totalTable"
      layout="prev, pager, next, jumper, ->, total, sizes"
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
    />
  </el-card>
  <!-- 入库确认 -->
  <el-dialog v-model="confirmStorage" title="入库确认" width="30%">
    <span style="color: red; margin-left: 33%; font-size: 24px"
      >是否确认入库</span
    >
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="confirmStorage = false">取消</el-button>
        <el-button type="success" @click="confirmSto"> 确定 </el-button>
      </span>
    </template>
  </el-dialog>
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
import { ref, onMounted } from 'vue'
import useOutStorageDetails from '@/stores/inventory/notice.js'
import { ArrowDown } from '@element-plus/icons-vue'
import {
  queryOutStock,
  deleteOutstock,
  confirmOutstock
} from '@/apis/inventory-manager/index.js'

// 初始化数据
const initLinks = (currentPage, pageSize, title, store_id, status) => {
  queryOutStock(currentPage, pageSize, title, store_id, status, (response) => {
    storageDetailsStore.totalTable = response.data.total
    storageDetailsStore.setTableData(response.data.rows)
  })
}
onMounted(() => {
  initLinks(currentPage.value, pageSize.value)
})
// 入库单store仓库
const storageDetailsStore = useOutStorageDetails()
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
    data.push(item.contract_id)
  })
  deleteOutstock(
    data,
    () => {
      ElMessage.success('删除成功')
      selectIdArr.value = []
      // 删除后重新请求数据
      initLinks(currentPage.value, pageSize.value)
    },
    () => {
      ElMessage.error('删除失败')
    }
  )
}

/**
 * 出库
 */
const confirmStorage = ref(false)
const storage = ref()
const modify = (row) => {
  storage.value = row.contract_id
  confirmStorage.value = false
}
const confirmSto = () => {
  confirmStorage.value = false
  confirmOutstock(
    [storage.value],
    () => {
      ElMessage.success('出库成功')
      // 删除后重新请求数据
      initLinks(currentPage.value, pageSize.value)
    },
    () => {
      ElMessage.error('出库失败')
    }
  )
}

/**
 * 搜索
 */
let content = ref('')
let name = ref('')
let address = ref('')
const searchDetails = () => {
  initLinks(
    currentPage.value,
    pageSize.value,
    content.value,
    name.value,
    address.value
  )
  content.value = ''
}
const dropdownRef = ref(null)
const clearValue = () => {
  name.value = address.value = ''
}
// 下拉框搜索按钮回调
const search = () => {
  if (name.value === '' && address.value === '') {
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
let confirmDelete = ref(false)
let deleteId = ref()
// 删除按钮回调
const Deletes = (row) => {
  deleteId.value = row.contract_id
  confirmDelete.value = true
}
const Confirms = () => {
  confirmDelete.value = false
  deleteOutstock(
    [deleteId.value],
    () => {
      ElMessage.success('删除成功')
      // 删除后重新请求数据
      initLinks(currentPage.value, pageSize.value)
    },
    () => {
      ElMessage.error('删除失败')
    }
  )
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
:deep(.el-form-items) {
  margin-bottom: 0;
}
</style>
