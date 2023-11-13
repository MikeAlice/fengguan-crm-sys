<template>
  <!-- <div>部门管理</div> -->
  <BaseDataList
    title="部门管理"
    msg="这里是操作提示"
    ref="baseDataListRef"
    :table-column-attribute="sendData.tableColumnAttribute"
    :table-data="sendData.tableData"
    :page-sizes="sendData.pageSizes"
    :total="sendData.total"
    :useDropdownMenu="true"
    :dropdownMenuActionsInfo="dropdownMenuActionsInfo"
    @updateTableData="handleSizeChange"
  >
    <template #ico>
      <el-icon><Operation /></el-icon>
    </template>
    <template #treeMeau>
      <el-card class="tree-card">
        <template #header>
          <div class="card-header">
            <span>部门管理</span>
            <el-button @click="handelRefresh" class="button" text
              >刷新</el-button
            >
          </div>
        </template>
        <!-- 树形菜单标签结构 -->
        <el-tree
          :data="departmentManage.DepartmentTree"
          :props="defaultProps"
          highlight-current="true"
          default-expand-all="true"
          draggable
          empty-text="树形菜单内容为空"
          @node-click="handleNodeClick"
        />
      </el-card>
    </template>
    <template #menu>
      <div class="meau">
        <!-- 这里是表格头部的控件 -->
        <el-button @click="handelAddFn">
          <el-icon type="success" circle>
            <el-icon><Plus /></el-icon
          ></el-icon>
          添加
        </el-button>
        <div class="search">
          <el-input
            placeholder="请输入关键字搜索"
            v-model="searchKey"
          ></el-input>
          <el-button type="primary" :icon="Search" @click="handelSearch"
            >搜索</el-button
          >
        </div>
      </div>
    </template>
  </BaseDataList>
  <!-- 删除确认消息提示框 -->
  <el-dialog v-model="isDelete" title="温馨提示" width="30%">
    <span>你确认要删除吗?</span>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="isDelete = false">取消</el-button>
        <el-button type="primary" @click="handelDelete"> 确认 </el-button>
      </span>
    </template>
  </el-dialog>
  <!-- 添加业务=> 抽屉 -->
  <el-drawer
    size="45%"
    v-model="addDrawer"
    title="添加部门"
    direction="rtl"
    open-delay="100"
  >
    <div class="demo-drawer__content">
      <el-form
        ref="theAddForm"
        :model="addForm"
        label-width="120px"
        :rules="formRule"
      >
        <el-form-item label="部门名称" :label-width="labelWidth" prop="name">
          <el-input v-model="addForm.name" autocomplete="off" />
        </el-form-item>
        <el-form-item label="部门电话" :label-width="labelWidth" prop="phone">
          <el-input v-model="addForm.phone" autocomplete="off" />
        </el-form-item>
        <el-form-item label="部门传真" :label-width="labelWidth" prop="fax">
          <el-input v-model="addForm.fax" autocomplete="off" />
        </el-form-item>
        <el-form-item label="父级栏目" :label-width="labelWidth">
          <!-- 调用选择框组件 -->
          <ChooseSelect
            ref="addSelect"
            :options="departmentManage.departmentSelect"
            des="选择上级"
            :propsRule="defaultProps"
          ></ChooseSelect>
        </el-form-item>
        <el-form-item label="排位序号" :label-width="labelWidth" prop="sort">
          <el-input v-model="addForm.sort" autocomplete="off" />
        </el-form-item>
        <el-form-item label="是否启用" :label-width="labelWidth">
          <el-switch v-model="addDelivery" />
        </el-form-item>
        <el-form-item label="部门介绍" :label-width="labelWidth">
          <el-input v-model="addForm.desc" type="textarea" />
        </el-form-item>
      </el-form>
      <div class="drawerFooter">
        <el-button @click="addDrawer = false">取消</el-button>
        <el-button type="primary" :loading="btnLoading" @click="handelAddSubmit"
          >提交</el-button
        >
      </div>
    </div>
  </el-drawer>
  <!-- 修改业务 => 抽屉 -->
  <el-drawer
    size="45%"
    v-model="editDrawer"
    title="修改部门"
    direction="rtl"
    open-delay="100"
  >
    <div class="demo-drawer__content">
      <el-form
        ref="editForm"
        :model="addForm"
        label-width="120px"
        :rules="formRule"
      >
        <el-form-item label="部门名称" :label-width="labelWidth" prop="name">
          <el-input v-model="addForm.name" autocomplete="off" />
        </el-form-item>
        <el-form-item label="部门电话" :label-width="labelWidth" prop="phone">
          <el-input v-model="addForm.phone" autocomplete="off" />
        </el-form-item>
        <el-form-item label="部门传真" :label-width="labelWidth" prop="fax">
          <el-input v-model="addForm.fax" autocomplete="off" />
        </el-form-item>
        <el-form-item label="父级栏目" :label-width="labelWidth">
          <!-- <el-select v-model="addForm.region" placeholder="请选择上级">
            <el-option label="Area1" value="shanghai" />
            <el-option label="Area2" value="beijing" />
          </el-select> -->
          <!-- 调用选择框组件 -->
          <ChooseSelect
            :options="departmentManage.departmentSelect"
            des="选择上级"
          ></ChooseSelect>
        </el-form-item>
        <el-form-item label="排位序号" :label-width="labelWidth" prop="sort">
          <el-input v-model="addForm.sort" autocomplete="off" />
        </el-form-item>
        <el-form-item label="是否启用" :label-width="labelWidth">
          <el-switch v-model="addForm.delivery" />
        </el-form-item>
        <el-form-item label="部门介绍" :label-width="labelWidth">
          <el-input v-model="addForm.desc" type="textarea" />
        </el-form-item>
      </el-form>
      <div class="drawerFooter">
        <el-button @click="editDrawer = false">取消</el-button>
        <el-button
          type="primary"
          :loading="btnLoading"
          @click="handelEditSubmit"
          >保存数据</el-button
        >
      </div>
    </div>
  </el-drawer>
</template>

<script setup>
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'
import { Operation, Plus, Search } from '@element-plus/icons-vue'
import { getDepartmentList } from '@/apis/publicInterface.js'
import {
  getDepartmentTree,
  addDepartmentApi,
  deleteDepartmentApi
} from '@/apis/organizationStructure/department.js'
import useDepartmentManageStore from '@/stores/organizationStructure/departmentManage.js'
const departmentManage = useDepartmentManageStore()
import { ref, onMounted } from 'vue'

onMounted(async () => {
  // 获取部门名称结构树
  await getDepartmentTree(
    {
      depth: 0,
      pid: 0
    },
    (res) => {
      const { data } = res
      // console.log('获取部门名称结构树', res)
      // 存到 组织管理/部门管理仓库
      departmentManage.setDepartmentTree(data)
      // console.log('仓库的数据:', departmentManage.DepartmentTree)
    },
    (error) => {
      console.log(error)
    }
  )

  // 获取部门列表
  // 开启表格加载
  baseDataListRef.value.openLoading = true
  const result = await departmentManage.getDepartmentList({
    keywords: '',
    pageIndex: $page.value.currentPage,
    pageSize: $page.value.pageSize,
    pid: ''
  })
  // console.log(result.value)
  const { data } = result.value
  console.log(data)
  // 渲染当前的表格数据
  sendData.value.tableData = data.rows
  sendData.value.total = data.total
  baseDataListRef.value.openLoading = false

  // 获取部门名称列表数据(用于输入表单下拉列表)
  await getDepartmentList(
    {
      deptName: ''
    },
    (res) => {
      const { data } = res
      console.log('部门名称下拉菜单:', data)
      // 矫正数据
      const newArr = data.map((item) => {
        for (let key in item) {
          if (key === 'id') {
            item.value = item[key]
          }
          if (key === 'name') {
            item.label = item[key]
          }
        }
        return item
      })
      // 存到组织管理/部门管理仓库
      departmentManage.setDepartmentSelect(newArr)
      console.log('仓库的数据:', departmentManage.departmentSelect)
    }
  )
})

// 树形菜单渲染规则
const defaultProps = ref({
  children: 'nodes',
  label: 'name',
  value: 'id'
})
// 树形菜单刷新业务
const handelRefresh = async () => {
  await getDepartmentTree(
    {
      depth: 0,
      pid: 0
    },
    (res) => {
      const { data } = res
      console.log('刷新成功的回调函数', res)
      ElMessage({
        message: '刷新成功',
        type: 'success'
      })
      // 重新渲染
      departmentManage.setDepartmentTree(data)
    },
    (error) => {
      console.log(error)
      ElMessage({
        message: '操作失败',
        type: 'warning'
      })
    }
  )
}

// 获取分页器数据
const $page = ref()
setTimeout(() => {
  $page.value = baseDataListRef.value.paginationData
  console.log('当前分页器数据', $page.value)
})

// 点击树节点的事件
const handleNodeClick = async (row) => {
  console.log('树形菜单数据:', row)
  if (row.parentID === 0) {
    row.parentID = ''
  }
  // 获取部门列表
  baseDataListRef.value.openLoading = true
  const result = await departmentManage.getDepartmentList({
    keywords: '',
    pageIndex: $page.value.currentPage,
    pageSize: $page.value.pageSize,
    pid: row.parentID
  })
  const { data } = result.value
  // console.log(data)
  // 渲染当前的表格数据
  sendData.value.tableData = data.rows
  sendData.value.total = data.total
  baseDataListRef.value.openLoading = false
}
/**
 * 分页器条数或者当前页改变
 */
const handleSizeChange = async (pagesize, currentPage) => {
  // 基于当前部门发送请求，重新渲染页面
  // 获取部门列表
  baseDataListRef.value.openLoading = true
  const result = await departmentManage.getDepartmentList({
    keywords: '',
    pageIndex: currentPage,
    pageSize: pagesize,
    pid: ''
  })

  const { data } = result.value
  console.log(data)
  // 渲染当前的表格数据
  sendData.value.tableData = data.rows
  sendData.value.total = data.total
  baseDataListRef.value.openLoading = false
}

// ref数据绑定BaseDataList这个组件
const baseDataListRef = ref(null)
// 表格数据传递
const sendData = ref({
  tableColumnAttribute: [
    {
      prop: 'name',
      label: '部门名称',
      sortable: false
    },
    {
      prop: 'intro',
      label: '部门描述',
      sortable: true
    },
    {
      prop: 'sort',
      label: '排序',
      sortable: true
    },
    {
      prop: 'Enable',
      label: '启用',
      useSwitch: true
    }
  ],
  tableData: [
    {
      name: '商务部',
      intro: '商务洽谈的部门',
      sort: '4',
      Enable: ''
    },
    {
      name: '零起飞工作室',
      intro: '吃苦耐劳部门',
      sort: '6',
      Enable: ''
    }
  ],
  handleEdit: (row) => {
    console.log('编辑', row)
  },
  // 分页数组
  pageSizes: [5, 10, 15],
  total: 100
})

/**
 * 定义递归方法,用于遍历数组的每个子节点
 */
// 递归函数用于遍历包含对象的数组
// function traverseArray(arr) {
//   arr.forEach((item) => {
//     console.log('当前节点：', item)
//     if (item.nodes !== []) {
//       console.log('处理子节点：', item.nodes)
//       traverseArray(item.nodes) // 递归调用遍历子节点
//     }
//     if (item.subNodes) {
//       console.log('处理子节点的子节点：', item.subNodes)
//       traverseArray(item.subNodes) // 递归调用遍历子节点的子节点
//     }
//   })
// }

// 操作菜单的数据和处理函数
const dropdownMenuActionsInfo = ref([
  {
    command: '修改',
    // row为当前行的数据
    handleAction: async (row) => {
      editDrawer.value = true
      console.log('修改回调函数', row)
      addForm.value.name = row.name
      addForm.value.desc = row.intro
      addForm.value.sort = row.sort
      // 发送 获取部门名称结构树请求,拿没有的数据
      // 获取部门名称结构树
      await getDepartmentTree(
        {
          depth: 0,
          pid: row.parentID
        },
        (res) => {
          const { data } = res
          console.log('修改业务拿数据', data)
          // 根据部门id,拿到需要的那一条对象数据 row.id
          let editObj = data.filter((item) => {
            return item.id === row.id
          })
          console.log('符合条件的项', editObj)
          // console.log(editObj.tel)
          // 进行数据回显
          addForm.value.phone = editObj[0].tel
          addForm.value.fax = editObj[0].fax
        },
        (error) => {
          console.log(error)
        }
      )
    },
    actionName: '修改'
  },
  {
    command: '删除',
    // row为当前行的数据
    handleAction: (row) => {
      isDelete.value = true
      console.log('删除回调函数', row)
      delDepId.value = row.id
    },
    actionName: '删除'
  }
])

// 删除消息提示
const isDelete = ref(false)
// 删除部门的id
const delDepId = ref()
// 删除的处理方法
const handelDelete = async () => [
  await deleteDepartmentApi(
    {
      id: delDepId.value
    },
    async (res) => {
      console.log('删除成功回调:', res)
      isDelete.value = false
      ElMessage({
        message: '删除成功',
        type: 'success'
      })
      // 重新渲染表格
      // 获取部门列表
      baseDataListRef.value.openLoading = true
      const result = await departmentManage.getDepartmentList({
        keywords: '',
        pageIndex: $page.value.currentPage,
        pageSize: $page.value.pageSize,
        pid: ''
      })
      // console.log(result.value)
      const { data } = result.value
      console.log(data)
      // 渲染当前的表格数据
      sendData.value.tableData = data.rows
      sendData.value.total = data.total
      baseDataListRef.value.openLoading = false
    }
  )
]

// 控制抽屉打开关闭的数据
const addDrawer = ref(false)
// 抽屉表单数据
const addForm = ref({
  name: '',
  phone: '',
  fax: '',
  region: '选择上级',
  // 排位序号
  sort: '',
  delivery: false,
  desc: ''
})
// 表单元素宽度
const labelWidth = ref('100px')
// ref绑定表单
const theAddForm = ref()
const editForm = ref()

// 表单校验规则
const formRule = ref({
  // 部门名称
  name: [
    { required: true, message: '请输入部门名称', trigger: 'blur' },
    { min: 1, max: 10, message: '用户名必须是1-10位的字符', trigger: 'blur' }
  ],
  // 部门电话
  phone: [
    { required: true, message: '请输入部门电话', trigger: 'blur' },
    {
      pattern: /^1[3-9]\d{9}$/,
      message: '请输入正确的电话格式',
      trigger: 'blur'
    }
  ],
  // 部门传真
  //国际区号+区号 示例: +86-1234-567890
  fax: [
    { required: true, message: '请输入部门传真', trigger: 'blur' },
    {
      pattern: /^\+?\d{1,3}-?\d{1,4}-?\d{4,}$/,
      message: '请输入正确的传真格式',
      trigger: 'blur'
    }
  ],
  // 父级栏目需要用数据判断用户是否选中
  // 排位序号
  sort: [
    { required: true, message: '请输入排位序号', trigger: 'blur' },
    {
      pattern: /^\d+$/,
      message: '输入格式是任意长度数字',
      trigger: 'blur'
    }
  ]
})

// 点击添加打开抽屉,置空数据

const handelAddFn = () => {
  // 置空表单数据
  let obj = addForm.value
  for (let key in obj) {
    obj[key] = ''
  }
  addDrawer.value = true
}

// 定义添加的启用绑定数据
const addDelivery = ref(false)
// 添加下拉选择的ref
const addSelect = ref()

// 按钮提交加载的数据和方法
const btnLoading = ref(false)
const handelAddSubmit = async () => {
  // 添加表单的校验,通过了才能发送添加请求
  await theAddForm.value.validate()
  // 收集数据
  console.log(
    addForm.value,
    '是否启用:',
    addDelivery.value,
    '父级id:',
    addSelect.value.selectValue.id
  )
  if (addDelivery.value === true) {
    addDelivery.value = 1
  } else {
    addDelivery.value = 0
  }

  // 处理添加请求
  await addDepartmentApi(
    {
      fax: addForm.value.fax,
      intro: addForm.value.desc,
      name: addForm.value.name,
      // 部门id后续继续处理
      parentID: addSelect.value.selectValue.id,
      sort: addForm.value.sort,
      tel: addForm.value.phone,
      visible: addDelivery.value
    },
    async (res) => {
      console.log('添加部门成功回调函数:', res)
      // 重新渲染 表格
      baseDataListRef.value.openLoading = true
      const result = await departmentManage.getDepartmentList({
        keywords: '',
        pageIndex: $page.value.currentPage,
        pageSize: $page.value.pageSize,
        pid: addSelect.value.selectValue.id
      })
      // console.log(result.value)
      const { data } = result.value
      // console.log(data)
      // 渲染当前的表格数据
      sendData.value.tableData = data.rows
      sendData.value.total = data.total
      baseDataListRef.value.openLoading = false

      // 重新渲染部门菜单树
      // 获取部门名称结构树
      await getDepartmentTree(
        {
          depth: 0,
          pid: 0
        },
        (res) => {
          const { data } = res
          // console.log('获取部门名称结构树', res)
          // 存到 组织管理/部门管理仓库
          departmentManage.setDepartmentTree(data)
          // console.log('仓库的数据:', departmentManage.DepartmentTree)
        },
        (error) => {
          console.log(error)
        }
      )
    }
  )

  // 这里要处理添加接口的逻辑
  btnLoading.value = true
  setTimeout(() => {
    ElMessage({
      message: '提交成功',
      type: 'success'
    })
    btnLoading.value = false
    addDrawer.value = false
  }, 1000)
}

// 编辑业务
// 操作 => 修改抽屉
// 保存数据 按钮
const handelEditSubmit = async () => {
  // 修改的表单校验,通过才能发送put更新数据请求
  await editForm.value.validate()
  // 在这里处理更新修改的接口
  setTimeout(() => {
    ElMessage({
      message: '修改成功',
      type: 'success'
    })
    editDrawer.value = false
  }, 1000)
}
// 控制编辑抽屉打开/关闭的数据
const editDrawer = ref(false)

// 搜索业务
// 输入框绑定的数据
const searchKey = ref('')
// 搜索方法
// 加入节流处理
const isPass = ref(true)
const handelSearch = async () => {
  if (searchKey.value === '') {
    ElMessage('搜索关键词不能为空')
    return false
  }
  if (isPass.value === true) {
    // 关闭节流阀
    isPass.value = false

    // 发送渲染请求，需要传入搜索关键字
    btnLoading.value = true
    // 获取部门列表
    baseDataListRef.value.openLoading = true
    const result = await departmentManage.getDepartmentList({
      keywords: searchKey.value,
      pageIndex: $page.value.currentPage,
      pageSize: $page.value.pageSize,
      pid: ''
    })
    const { data } = result.value
    console.log(data)
    // 渲染当前的表格数据
    sendData.value.tableData = data.rows
    sendData.value.total = data.total
    baseDataListRef.value.openLoading = false
    btnLoading.value = false

    // 开启节流阀
    isPass.value = true
  }
  if (isPass.value === false) {
    ElMessage({
      message: '请求频率过高，不予处理',
      type: 'warning'
    })
  }
}
</script>

<style lang="scss" scoped>
.tree-card {
  min-width: 200px;
  min-height: 500px;
  width: 300px;
  height: 600px;
  margin-right: 50px;
}
.card-header {
  display: flex;
  align-items: center;
  justify-content: space-between;
}
// 表格菜单头样式
.meau {
  display: flex;
  justify-content: space-between;
  margin-bottom: 20px;
}
.search {
  display: flex;
}
// 抽屉底部按钮样式
.drawerFooter {
  // width: 100%;
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 20px;
}
.drawerFooter button {
  margin: 0 40px;
}
</style>
