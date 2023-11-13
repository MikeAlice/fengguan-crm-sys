<template>
  <!-- <div>我的客户</div> -->
  <el-card>
    <!-- 头部 -->
    <header>
      <h3>
        <slot name="ico"></slot>
        <div style="margin-left: 8px">下属客户</div>
      </h3>
    </header>
    <!-- 操作搜索栏 -->
    <section class="menu">
      <div class="left">
        <el-button
          type="primary"
          icon="IconPlus"
          @click="addOrUpdateClient.addMyClinet()"
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
              :disabled="selectIdArr.length ? false : true"
              >批量删除</el-button
            >
          </template>
        </el-popconfirm>
        <el-button
          type="primary"
          style="margin-right: 10px"
          :disabled="selectIdArr.length ? false : true"
          @click="invesHightsea"
          >批量投入公海</el-button
        >
        <BulkOPe
          :getOpt="() => [0, 1]"
          :exportExcel="exportExcel"
          :action="action"
          :baseURL="baseURL"
          :importExcel="importExcel"
          :handle-change="handleChange"
        >
        </BulkOPe>
      </div>
      <div class="right" style="display: flex">
        <ChooseSelect
          style="margin-right: 10px"
          des="最近联系时间"
          :options="options"
          ref="coonTime"
          @update:cid="getCoonTime"
        ></ChooseSelect>
        <ChooseSelect
          style="margin-right: 10px"
          :options="options"
          des="下次联系时间"
          ref="nextTime"
          @update:cid="getNextTime"
        ></ChooseSelect>
        <el-input
          v-model="name"
          placeholder="输入客户名称关键词"
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
                      座机
                    </h4>
                    <el-input v-model="tel" placeholder="搜索座机" />
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
                      手机号
                    </h4>
                    <el-input v-model="mobile" placeholder="搜索手机号" />
                  </div>
                </el-form-item>
                <!-- 输入框3 -->
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
                      通讯地址
                    </h4>
                    <el-input v-model="address" placeholder="搜索通讯地址" />
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
      :data="myclient.tableData"
      @selection-change="selectChange"
    >
      <el-table-column type="selection" width="55" />
      <el-table-column label="客户名称" prop="name" sortable></el-table-column>
      <el-table-column label="归属于" prop="owner_user_id"></el-table-column>
      <el-table-column
        label="上次联系"
        prop="coon_time"
        sortable
      ></el-table-column>
      <el-table-column label="联系内容" prop="coon_body"></el-table-column>
      <el-table-column
        label="下次联系"
        prop="next_time"
        sortable
      ></el-table-column>
      <el-table-column label="操作" fixed="right">
        <template #default="{ row }">
          <el-dropdown>
            <el-button type="primary">
              操作<el-icon class="el-icon--right"><arrow-down /></el-icon>
            </el-button>
            <template #dropdown>
              <el-dropdown-menu>
                <el-dropdown-item @click="addContacts.addContact(row)"
                  >添加联系人</el-dropdown-item
                >
                <el-dropdown-item @click="communicate.addCommunicate(row)"
                  >添加沟通记录</el-dropdown-item
                >
                <el-dropdown-item divided @click="service.addServices(row)"
                  >添加服务记录</el-dropdown-item
                >
                <el-dropdown-item @click="opportunity.addOpportunity(row)"
                  >添加销售机会</el-dropdown-item
                >
                <el-dropdown-item divided @click="contract.addContract(row)"
                  >添加合同</el-dropdown-item
                >
                <el-dropdown-item divided @click="addOrUpdateClient.modify(row)"
                  >修改</el-dropdown-item
                >
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
      :total="myclient.total"
      layout="prev, pager, next, jumper, ->, total, sizes"
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
    />
  </el-card>
  <!-- 添加或修改客户信息 -->
  <AddOrUpdateClient ref="addOrUpdateClient"></AddOrUpdateClient>
  <!-- 添加联系人 -->
  <AddContact ref="addContacts"></AddContact>
  <!-- 添加沟通记录 -->
  <Communicate ref="communicate"></Communicate>
  <!-- 添加服务记录 -->
  <Service ref="service"></Service>
  <!-- 添加销售机会 -->
  <Opportunity ref="opportunity"></Opportunity>
  <!-- 添加合同 -->
  <Contract ref="contract"></Contract>
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
import useMyClient from '@/stores/customer/myclient.js'
import {
  getCustomer,
  deleteCustomer,
  invesHightSea,
  exportCustomer,
  uploadCustomerFile,
  importCustomer
} from '@/apis/customer/index.js'
import BulkOPe from '@/components/BulkOpe/BulkOPe.vue'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'
import { ArrowDown } from '@element-plus/icons-vue'
import AddOrUpdateClient from './components/AddOrUpdateClient.vue'
import AddContact from './components/AddContact.vue'
import Communicate from './components/Communicate.vue'
import Service from './components/Service.vue'
import Opportunity from './components/Opportunity.vue'
import Contract from './components/Contract.vue'

// 添加或修改客户的组件实例
const addOrUpdateClient = ref()

// 添加联系人的组件实例
const addContacts = ref()

// 添加沟通记录的组件实例
const communicate = ref()

// 添加服务记录的组件实例
const service = ref()

// 添加销售记录的组件实例
const opportunity = ref()

// 添加合同的组件实例
const contract = ref()

// 初始化数据
const initCustomer = async (
  currentPage,
  pageSize,
  coonTime,
  nextTime,
  name,
  mobile,
  tel,
  address
) => {
  getCustomer(
    currentPage,
    pageSize,
    coonTime,
    nextTime,
    name,
    mobile,
    tel,
    address,
    (response) => {
      myclient.total = response.data.total
      myclient.gettableData(response.data.rows)
    },
    () => {
      myclient.gettableData([])
    }
  )
}
onMounted(() => {
  initCustomer(currentPage.value, pageSize.value)
})

const inits = () => {
  initCustomer(currentPage.value, pageSize.value)
}

provide('inits', inits)
// 我的客户store仓库
const myclient = useMyClient()
// 当前页数
let currentPage = ref(1)
// 每页数据
let pageSize = ref(5)
const handleSizeChange = (val) => {
  pageSize.value = val
  initCustomer(currentPage.value, pageSize.value)
}
const handleCurrentChange = (val) => {
  currentPage.value = val
  initCustomer(currentPage.value, pageSize.value)
}
// 导出文件的按钮回调
const exportExcel = (value1, value2) => {
  let data = []
  selectIdArr.value.forEach((item) => {
    data.push(item.customer_id)
  })
  exportCustomer(
    data,
    value1,
    value2,
    () => {
      ElMessage.success('导出成功')
      initCustomer(currentPage.value, pageSize.value)
    },
    () => {
      ElMessage.error('导出失败')
    }
  )
}

// 导入文件-文件上传的全地址
const action = ref(
  'http://8.130.17.229:8090/customer-mycustomer/upload-customer-file'
)

const excelFile = ref(null)

const handleChange = (file) => {
  console.log(file)
  excelFile.value = file
  // uploadCustomerFile(
  //   excelFile.value.raw,
  //   () => {
  //     ElMessage.success('文件上传成功')
  //   },
  //   () => {
  //     ElMessage.error('文件上传失败')
  //   }
  // )
}

//导入文件的按钮回调
const importExcel = async () => {
  await importCustomer(
    excelFile.value.raw,
    () => {
      ElMessage.success('导入成功')
    },
    () => {
      ElMessage.error('导入失败')
    }
  )
}

// 最近联系时间的选项
const options = ref([
  {
    value: 'Option1',
    label: '最近三天'
  },
  {
    value: 'Option2',
    label: '最近一周'
  },
  {
    value: 'Option3',
    label: '最近半月'
  },
  {
    value: 'Option4',
    label: '最近一月'
  },
  {
    value: 'Option5',
    label: '最近三月'
  },
  {
    value: 'Option6',
    label: '最近六月'
  },
  {
    value: 'Option7',
    label: '最近一年'
  }
])

/**
 * 搜索
 */
// 最近联系人时间
const coonTime = ref()
const getCoonTime = () => {
  coon.value = coonTime.value.selectValue.label
}
// 下次联系时间
const nextTime = ref()
const getNextTime = () => {
  nexts.value = nextTime.value.selectValue.label
}
const name = ref('')
const coon = ref('')
const nexts = ref('')
const searchDetails = () => {
  initCustomer(
    currentPage.value,
    pageSize.value,
    coon.value,
    nexts.value,
    name.value,
    mobile.value,
    tel.value,
    address.value
  )
  coonTime.value.reset()
  nextTime.value.reset()
  coon.value = ''
  nexts.value = ''
  name.value = ''
}
const tel = ref('')
const mobile = ref('')
const address = ref('')

const dropdownRef = ref(null)
const clearValue = () => {
  tel.value = address.value = mobile.value = ''
}
// 下拉框搜索按钮回调
const search = () => {
  if (tel.value !== '' && mobile.value !== '' && address.value !== '') {
    ElMessage.error('输入不能为空')
  } else {
    searchDetails()
    // 调用搜索函数后 关闭下拉菜单
    dropdownRef.value.$el.click()
  }
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
    data.push(item.customer_id)
  })
  deleteCustomer(
    data,
    () => {
      ElMessage.success('批量删除成功')
      selectIdArr.value = []
    },
    () => {
      ElMessage.error('批量删除失败')
    }
  )
  // 删除后重新请求数据
  initCustomer(currentPage.value, pageSize.value)
}

/**
 * 批量投入公海
 */
const invesHightsea = async () => {
  let data = []
  selectIdArr.value.forEach((item) => {
    data.push(item.customer_id)
  })
  invesHightSea(
    data,
    () => {
      ElMessage.success('批量投入成功')
      selectIdArr.value = []
    },
    () => {
      ElMessage.error('批量投入失败')
    }
  )
  initCustomer(currentPage.value, pageSize.value)
}

/**
 * 删除
 */
let confirmDelete = ref(false)
let deleteId = ref()
// 删除按钮回调
const Deletes = (row) => {
  deleteId.value = row.customer_id
  confirmDelete.value = true
}
// 确定删除
const Confirms = () => {
  deleteCustomer(
    [deleteId.value],
    () => {
      ElMessage.success('删除成功')
    },
    () => {
      ElMessage.error('删除失败')
    }
  )
  confirmDelete.value = false
  initCustomer(currentPage.value, pageSize.value)
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
.padding-bottom-5 {
  padding-bottom: 5px;
}
:deep(.el-form-items) {
  margin-bottom: 0;
}
</style>
