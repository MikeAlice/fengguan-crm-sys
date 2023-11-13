<template>
  <el-card>
    <!-- 头部 -->
    <header>
      <h3>
        <slot name="ico"></slot>
        <div style="margin-left: 8px">联系人</div>
      </h3>
    </header>
    <!-- 操作搜索栏 -->
    <section class="menu">
      <div class="left">
        <el-button type="primary" icon="IconPlus" @click="addMyClinet"
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
        <BulkOPe
          :getOpt="() => [0, 3, 4]"
          :exportExcel="exportExcel"
          :msgSend="msgSend"
          :emailSend="emailSend"
        >
        </BulkOPe>
      </div>
      <div class="right" style="display: flex">
        <el-input
          v-model="content"
          placeholder="输入姓名"
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
                      客户名称
                    </h4>
                    <el-input v-model="name" placeholder="搜索客户名称" />
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
                      通讯地址
                    </h4>
                    <el-input v-model="address" placeholder="搜索通信地址" />
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
      :data="myclient.linksTableData"
      @selection-change="selectChange"
    >
      <el-table-column type="selection" width="55" />
      <el-table-column
        label="客户名称"
        prop="customer_name"
        sortable
      ></el-table-column>
      <el-table-column label="联系人" prop="link_name"></el-table-column>
      <el-table-column label="性别" prop="gender">
        <template #default="{ row }">
          {{ row.gender === 0 ? '女' : '男' }}
        </template>
      </el-table-column>
      <el-table-column label="职位" prop="position"></el-table-column>
      <el-table-column label="手机" prop="mobile"></el-table-column>
      <el-table-column label="座机" prop="tel"></el-table-column>
      <el-table-column label="QQ" prop="qicq"></el-table-column>
      <el-table-column label="操作" fixed="right">
        <template #default="{ row }">
          <el-dropdown>
            <el-button type="primary">
              操作<el-icon class="el-icon--right"><arrow-down /></el-icon>
            </el-button>
            <template #dropdown>
              <el-dropdown-menu>
                <el-dropdown-item @click="modify(row)">修改</el-dropdown-item>
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
      :total="myclient.total1"
      layout="prev, pager, next, jumper, ->, total, sizes"
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
    />
  </el-card>
  <!-- 添加或修改客户信息 -->
  <el-drawer
    v-model="dialogVisible"
    :title="!flag ? '添加联系人' : '修改联系人'"
    size="50%"
    @close="close"
    :rules="rules"
  >
    <el-form :model="tempLinkData" label-width="120px" label-position="right">
      <el-form-item label="姓名" prop="name">
        <el-input
          v-model="tempLinkData.link_name"
          placeholder="请输入姓名"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="性别" prop="gender">
        <el-radio-group v-model="tempLinkData.gender">
          <el-radio label="男" />
          <el-radio label="女" />
        </el-radio-group>
      </el-form-item>
      <el-form-item label="座机">
        <el-input
          v-model="tempLinkData.tel"
          placeholder="请输入座机"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="职位">
        <el-input
          v-model="tempLinkData.postion"
          placeholder="请输入职位"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="手机号" prop="mobile">
        <el-input
          v-model="tempLinkData.mobile"
          placeholder="请输入手机号"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="邮箱" prop="email">
        <el-input
          v-model="tempLinkData.email"
          placeholder="请输入邮箱"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="通信地址">
        <el-input
          v-model="tempLinkData.address"
          placeholder="请输入通信地址"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="客户名称" prop="customerName">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择客户名称"
          :options="select.name"
          @update:cid="contractGetName"
          ref="customerName"
        ></ChooseSelect>
      </el-form-item>
    </el-form>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible = false">取消</el-button>
        <el-button type="primary" @click="save"> 添加 </el-button>
      </span>
    </template>
  </el-drawer>
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
import useMyClient from '@/stores/customer/myclient.js'
import useSelect from '@/stores/customer/select.js'
import { getCustomerName } from '@/apis/publicInterface.js'
import BulkOPe from '@/components/BulkOpe/BulkOPe.vue'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'
import { ArrowDown } from '@element-plus/icons-vue'
import {
  queryContactList,
  queryContactFile,
  addNewContact,
  modifyContact,
  removeContact,
  sendsms,
  sendEmail
} from '@/apis/customer/index.js'

// 初始化数据
const initLinks = async (
  currentPage,
  pageSize,
  customerName,
  linkName,
  address
) => {
  await queryContactList(
    currentPage,
    pageSize,
    customerName,
    linkName,
    address,
    (response) => {
      myclient.total1 = response.data.total
      myclient.linksTableData = response.data.rows
    }
  )
}
onMounted(() => {
  initLinks(currentPage.value, pageSize.value)
})
// 我的客户store仓库
const myclient = useMyClient()
// 下拉列表仓库
const select = useSelect()
// 控制添加或修改客户信息对话框的显示与隐藏
let dialogVisible = ref(false)
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

// 导出文件按钮回调
const exportExcel = async (value1, value2) => {
  await queryContactFile(
    value1,
    value2,
    () => {
      ElMessage.success('导出成功')
    },
    () => {
      ElMessage.error('导出失败')
    }
  )
}
// 发送消息按钮回调
const msgSend = (title, desc) => {
  let data = []
  selectIdArr.value.forEach((item) => {
    data.push(item.linkman_id)
  })
  sendsms(
    data,
    title,
    desc,
    () => {
      ElMessage.success('短信发送成功')
    },
    () => {
      ElMessage.error('短信发送失败')
    }
  )
}
// 发送邮件按钮回调
const emailSend = (title, desc) => {
  let data = []
  selectIdArr.value.forEach((item) => {
    data.push(item.linkman_id)
  })
  sendEmail(
    data,
    title,
    desc,
    () => {
      ElMessage.success('邮件发送成功')
    },
    () => {
      ElMessage.error('邮件发送失败')
    }
  )
}

let tempLinkData = ref({
  linkman_id: -1, //联系人ID
  customer_id: '', //客户ID
  customerName: '', //客户名称
  linkman_name: '', //联系人名称
  gender: 0, //联系人性别 1=男，0=女
  postion: '', //联系人职位
  tel: '', //联系人座机
  mobile: '', //联系人手机
  qicq: '', //联系人QQ
  email: '', //联系人邮箱
  zipcode: '', //联系人邮政编码
  address: '', //联系人地址
  intro: '' //联系人简介
})

const tempLinkDataReset = () => {
  tempLinkData.value = {
    linkman_id: -1, //联系人ID
    customer_id: '', //客户ID
    customerName: '', //客户名称
    linkman_name: '', //联系人名称
    gender: 0, //联系人性别 1=男，0=女
    postion: '', //联系人职位
    tel: '', //联系人座机
    mobile: '', //联系人手机
    qicq: '', //联系人QQ
    email: '', //联系人邮箱
    zipcode: '', //联系人邮政编码
    address: '', //联系人地址
    intro: '' //联系人简介
  }
}
const customerName = ref()
const contractGetName = () => {
  getCustomerName('', (response) => {
    let data = []
    response.data.rows.forEach((item) => {
      data.push({ value: item.customer_id, label: item.name })
    })
    select.setName(data)
  })
  tempLinkData.value.customer_id = customerName.value.selectValue.value
  tempLinkData.value.customerName = customerName.value.selectValue.label
}
// 点击添加按钮的回调
const addMyClinet = () => {
  getCustomerName(
    '',
    (response) => {
      let data = []
      response.data.forEach((item) => {
        data.push({ value: item.customer_id, label: item.name })
      })
      select.setName(data)
    },
    (error) => {
      console.log('error', error)
    }
  )
  dialogVisible.value = true
  flag.value = false
}
// 添加按钮确定回调
const save = () => {
  if (tempLinkData.value.linkman_id === -1) {
    addNewContact(
      tempLinkData.value,
      () => {
        ElMessage.success('添加成功')
        initLinks(currentPage.value, pageSize.value)
        customerName.value.reset()
      },
      () => {
        ElMessage.error('添加失败')
      }
    )
  } else {
    modifyContact(
      tempLinkData.value,
      () => {
        ElMessage.success('修改成功')
        initLinks(currentPage.value, pageSize.value)
        customerName.value.reset()
      },
      () => {
        ElMessage.error('修改失败')
      }
    )
  }

  tempLinkDataReset()
  select.resetData()
  dialogVisible.value = false
}
const flag = ref(false)
const close = () => {
  if (flag.value) {
    myclient.customerReset()
    flag.value = false
  }
}
// 修改按钮回调
const modify = (row) => {
  getCustomerName(
    '',
    (response) => {
      let data = []
      response.data.forEach((item) => {
        data.push({ value: item.customer_id, label: item.name })
      })
      select.setName(data)
    },
    (error) => {
      console.log('error', error)
    }
  )
  const item = myclient.linksTableData.find((item) => {
    return item.linkman_id === row.linkman_id
  })
  tempLinkData.value = item
  // customerName.value.setVal(item.customer_name)
  dialogVisible.value = true
  flag.value = true
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
    data.push(item.linkman_id)
  })
  removeContact(
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
  console.log(row)
  deleteId.value = row.linkman_id
  confirmDelete.value = true
}
const Confirms = async () => {
  confirmDelete.value = false
  await removeContact(
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

const rules = ref({
  name: [{ required: true, message: '姓名不能为空', trigger: 'blur' }],
  gender: [{ required: true, message: '性别不能为空', trigger: 'blur' }],
  mobile: [{ required: true, message: '手机号不能为空', trigger: 'blur' }],
  email: [{ required: true, message: '邮箱不能为空', trigger: 'blur' }],
  customerName: [
    { required: true, message: '客户名称不能为空', trigger: 'blur' }
  ]
})
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
