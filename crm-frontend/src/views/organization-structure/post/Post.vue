<template>
  <!-- 这里是岗位管理 -->
  <BaseDataList
    title="岗位管理"
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
            <el-button class="button" @click="handelRefresh" text
              >刷新</el-button
            >
          </div>
        </template>
        <!-- 树形菜单标签结构 -->
        <el-tree
          :data="postManageStore.postTreeMeau"
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
          <el-button
            type="primary"
            :loading="btnLoading"
            :icon="Search"
            @click="handelSearch"
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
        <el-button type="primary" @click="handelTheDel"> 确认 </el-button>
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
        <el-form-item label="名称" :label-width="labelWidth" prop="name">
          <el-input v-model="addForm.name" autocomplete="off" />
        </el-form-item>
        <el-form-item label="父级栏目" :label-width="labelWidth">
          <el-tree-select
            v-model="selectValue"
            :data="postManageStore.postTreeMeau"
            check-strictly
            :render-after-expand="false"
            clearable
            :props="defaultProps"
            :highlight-current="true"
            @change="handelSelect"
          />
        </el-form-item>
        <el-form-item label="排序" :label-width="labelWidth" prop="sort">
          <el-input v-model="addForm.sort" autocomplete="off" />
        </el-form-item>
        <el-form-item label="启用" :label-width="labelWidth">
          <el-switch v-model="addDelivery" />
        </el-form-item>
        <el-form-item label="介绍" :label-width="labelWidth">
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
        <el-form-item label="名称" :label-width="labelWidth" prop="name">
          <el-input v-model="addForm.name" autocomplete="off" />
        </el-form-item>
        <el-form-item label="父级" :label-width="labelWidth">
          <el-tree-select
            v-model="selectValue"
            :data="postManageStore.postTreeMeau"
            check-strictly
            :render-after-expand="false"
            clearable
            :props="defaultProps"
            :highlight-current="true"
            @change="handelSelect"
          />
        </el-form-item>
        <el-form-item label="排序" :label-width="labelWidth" prop="sort">
          <el-input v-model="addForm.sort" autocomplete="off" />
        </el-form-item>
        <el-form-item label="启用" :label-width="labelWidth">
          <el-switch v-model="addDelivery" />
        </el-form-item>
        <el-form-item label="介绍" :label-width="labelWidth">
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
// import ChooseSelect from '@/components/chooseSelect/chooseSelect.vue'
import { Operation, Plus, Search } from '@element-plus/icons-vue'
// import { ElMessage } from 'element-plus'
import { ref, onMounted } from 'vue'
import {
  getPostTree,
  getPostListApi,
  addPostListApi,
  deletePostListApi
} from '../../../apis/organizationStructure/postManagement'
// 导入 组织结构/岗位管理 仓库
import usePostManageStore from '../../../stores/organizationStructure/postManagement'
const postManageStore = usePostManageStore()

// 获取分页数据
const $page = ref()
setTimeout(() => {
  $page.value = baseDataListRef.value.paginationData
  console.log('当前分页器数据', $page.value)
})
onMounted(async () => {
  // 获取菜单树
  await getPostTree(
    {
      depth: 0,
      pid: 0
    },
    (res) => {
      const { data } = res
      console.log('获取岗位名称结构树成功回调:', data)
      defaultDep.value = data[0]
      currentTreeOption.value = data[0]
      ElMessage({
        message: '获取成功',
        type: 'success'
      })
      // 把数据存到 组织结构/岗位管理 仓库
      postManageStore.setPostTreeMeau(data)
    }
  )
  // 获取岗位列表(分页+条件)
  baseDataListRef.value.openLoading = true
  await getPostListApi(
    {
      keyword: '',
      pageIndex: $page.value.currentPage,
      pageSize: $page.value.pageSize,
      pid: ''
    },
    (res) => {
      const { data } = res
      console.log('获取岗位列表(分页+条件):', data)
      // 渲染数据 => 数据存到仓库
      postManageStore.setPostListTable(data.rows)
      sendData.value.tableData = data.rows
      sendData.value.total = data.total
      baseDataListRef.value.openLoading = false
    }
  )
})

/**
 * 刷新菜单树
 */
const defaultDep = ref({})
// 刷新部门名称结构树
const handelRefresh = async () => {
  await getPostTree(
    {
      depth: 0,
      pid: 0
    },
    (res) => {
      const { data } = res
      console.log('刷新部门名称结构树', data)
      // 把数据存到 组织结构/岗位管理 仓库
      postManageStore.setPostTreeMeau(data)
      ElMessage({
        message: '刷新成功',
        type: 'success'
      })
    },
    (error) => {
      if (error) {
        console.log(error)
      }
    }
  )
}
// 当前的树选项
const currentTreeOption = ref()

/**
 * 分页器更新函数
 * @param {*} pagesize
 * @param {*} currentPage
 */
const handleSizeChange = async (pagesize, currentPage) => {
  console.log('条数:', pagesize, '当前页', currentPage)
  // 开启表格加载效果
  baseDataListRef.value.openLoading = true
  // 分页器改变,需要发请求重新获取数据并渲染
  await getPostListApi(
    {
      deptId: currentTreeOption.value.id,
      name: '',
      pageIndex: currentPage,
      pageSize: pagesize
    },
    (res) => {
      const { data } = res
      console.log('分页器改变请求的数据', data)
      // 更新分页器数据
      sendData.value.total = data.total
      // 重新渲染
      // console.log('要改的数组', sendData.value.tableData)
      sendData.value.tableData = data.rows
      baseDataListRef.value.openLoading = false
    }
  )
}

// 树形选择绑定值
const selectValue = ref('')
// 更新选中值
const handelSelect = (value) => {
  selectValue.value = value
}

const defaultProps = ref({
  children: 'nodes',
  label: 'name',
  value: 'id'
})

// 点击树节点的事件
// 防抖处理
const isPass = ref(true)
const handleNodeClick = async (treeData) => {
  // 节流阀为true，就发请求
  if (isPass.value === true) {
    // 关闭阀门
    isPass.value = false
    // 收集数据发请求
    currentTreeOption.value = treeData
    console.log('当前部门:', currentTreeOption.value)
    console.log('当前id:', currentTreeOption.value.id)
    baseDataListRef.value.openLoading = true
    await getPostListApi(
      {
        pid: currentTreeOption.value.id,
        pageIndex: $page.value.currentPage,
        pageSize: $page.value.pageSize
      },
      (res) => {
        const { data } = res
        console.log('点树形菜单请求得到的数据', data)
        // 渲染
        sendData.value.tableData = data.rows
        sendData.value.total = data.total
        baseDataListRef.value.openLoading = false
      },
      (error) => {
        baseDataListRef.value.openLoading = false
        if (error) {
          console.log(error)
        }
      }
    )
    // 开启阀门
    isPass.value = true
  } else {
    ElMessage({
      message: '请求频率过高,不予处理',
      type: 'warning'
    })
  }
}

// ref数据绑定BaseDataList这个组件
const baseDataListRef = ref(null)
// 表格数据传递
const sendData = ref({
  tableColumnAttribute: [
    {
      prop: 'name',
      label: '职务名称',
      sortable: false
    },
    {
      prop: 'intro',
      label: '职务描述',
      sortable: true
    },
    {
      prop: 'sort',
      label: '排序',
      sortable: true
    },
    {
      prop: 'visible',
      label: '启用',
      useSwitch: true
    }
  ],
  tableData: [
    {
      name: '总经理',
      intro: '公司小领导',
      sort: '4',
      visible: ''
    },
    {
      name: '财务总监',
      intro: '',
      sort: '6',
      visible: ''
    }
  ],
  handleEdit: (row) => {
    console.log('编辑', row)
  },
  // 分页数组
  pageSizes: [5, 10, 15],
  total: 100
})
// 操作菜单的数据和处理函数
const dropdownMenuActionsInfo = ref([
  {
    command: '修改',
    // row为当前行的数据
    handleAction: (row) => {
      editDrawer.value = true
      console.log('修改回调函数', row)
      // 需要发请求获取没有的数据
      addForm.value.name = row.Department
      addForm.value.desc = row.DepartmentDes
      addForm.value.sort = row.sort
      console.log(row.Department)
    },
    actionName: '修改'
  },
  {
    command: '删除',
    // row为当前行的数据
    handleAction: (row) => {
      isDelete.value = true
      console.log('删除回调函数', row)
      DelPostId.value = row.id
    },
    actionName: '删除'
  }
])

/**
 * 删除业务
 */
// 需要删除的岗位id
const DelPostId = ref()
// 删除消息提示
const isDelete = ref(false)
const handelTheDel = async () => {
  console.log('要删除的岗位id:', DelPostId.value)
  await deletePostListApi(
    {
      positionId: DelPostId.value
    },
    async (res) => {
      console.log('删除成功回调:', res)
      ElMessage({
        message: '删除成功',
        type: 'success'
      })
      //刷新岗位树
      // 获取菜单树
      await getPostTree(
        {
          depth: 0,
          pid: 0
        },
        (res) => {
          const { data } = res
          ElMessage({
            message: '已刷新数据',
            type: 'success'
          })
          // 把数据存到 组织结构/岗位管理 仓库
          postManageStore.setPostTreeMeau(data)
        }
      )
      // 获取岗位列表(分页+条件)
      baseDataListRef.value.openLoading = true
      await getPostListApi(
        {
          keyword: '',
          pageIndex: $page.value.currentPage,
          pageSize: $page.value.pageSize,
          pid: ''
        },
        (res) => {
          const { data } = res
          sendData.value.tableData = data.rows
          sendData.value.total = data.total
          baseDataListRef.value.openLoading = false
          isDelete.value = false
        }
      )
    }
  )
}

// 控制抽屉打开关闭的数据
const addDrawer = ref(false)
// 抽屉表单数据
const addForm = ref({
  name: '',
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
//表单校验规则
const formRule = ref({
  // 部门名称
  name: [
    { required: true, message: '请输入部门名称', trigger: 'blur' },
    { min: 1, max: 10, message: '用户名必须是1-10位的字符', trigger: 'blur' }
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
  addDelivery.value = false
  selectValue.value = ''
  addDrawer.value = true
}

const addDelivery = ref(false)

// 按钮提交加载的数据和方法
const btnLoading = ref(false)
const handelAddSubmit = async () => {
  // 添加表单的校验,通过了才能发送添加请求
  await theAddForm.value.validate()

  // 判断是否选中父级
  if (selectValue.value === '') {
    ElMessage('请选择父级栏目')
    return false
  }

  //收集数据
  console.log(
    '添加表单数据',
    addForm.value,
    '是否启用',
    addDelivery.value,
    '父级栏目:',
    selectValue.value
  )
  // 矫正数据 启用=>1 2=> 禁用
  if (addDelivery.value === true) {
    addDelivery.value = 1
  } else {
    addDelivery.value = 2
  }
  btnLoading.value = true
  await addPostListApi(
    {
      intro: addForm.value.desc,
      name: addForm.value.name,
      parentID: selectValue.value,
      sort: addForm.value.sort,
      visible: addDelivery.value
    },
    async (res) => {
      console.log('新增岗位成功回调:', res)
      ElMessage({
        message: '添加成功',
        type: 'success'
      })
      // 刷新菜单树
      await getPostTree(
        {
          depth: 0,
          pid: 0
        },
        (res) => {
          const { data } = res
          // 把数据存到 组织结构/岗位管理 仓库
          postManageStore.setPostTreeMeau(data)
          ElMessage({
            message: '数据已刷新',
            type: 'success'
          })
        },
        (error) => {
          if (error) {
            console.log(error)
          }
        }
      )
      // 刷新表格的数据
      baseDataListRef.value.openLoading = true
      await getPostListApi(
        {
          keyword: '',
          pageIndex: $page.value.currentPage,
          pageSize: $page.value.pageSize,
          pid: selectValue.value
        },
        (res) => {
          const { data } = res
          console.log('获取岗位列表(分页+条件):', data)
          // 渲染数据 => 数据存到仓库
          postManageStore.setPostListTable(data.rows)
          sendData.value.tableData = data.rows
          sendData.value.total = data.total
          baseDataListRef.value.openLoading = false
        }
      )
    }
  )
  btnLoading.value = false
  addDrawer.value = false
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
const handelSearch = async () => {
  if (searchKey.value === '') {
    ElMessage('搜索关键词不能为空')
    return false
  }
  btnLoading.value = true
  // 开启表格加载效果
  baseDataListRef.value.openLoading = true
  // 分页器改变,需要发请求重新获取数据并渲染
  await getPostListApi(
    {
      deptId: currentTreeOption.value.id,
      keyword: searchKey.value,
      pageIndex: $page.value.currentPage,
      pageSize: $page.value.pageSize
    },
    (res) => {
      const { data } = res
      console.log('搜索请求的数据', data)
      // 更新分页器数据
      sendData.value.total = data.total
      // 重新渲染
      // console.log('要改的数组', sendData.value.tableData)
      sendData.value.tableData = data.rows
      baseDataListRef.value.openLoading = false
      btnLoading.value = false
      ElMessage({
        message: '搜索成功',
        type: 'success'
      })
    },
    (error) => {
      if (error) {
        console.log(error)
      }
    }
  )
  // 置空搜索框
  searchKey.value = ''
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
