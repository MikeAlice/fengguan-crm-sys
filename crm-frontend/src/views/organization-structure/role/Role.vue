<template>
  <!-- 这里是角色管理 -->
  <BaseDataList
    title="角色管理"
    msg="这里是操作提示"
    ref="baseDataListRef"
    :table-column-attribute="sendData.tableColumnAttribute"
    :table-data="sendData.tableData"
    :page-sizes="sendData.pageSizes"
    :total="sendData.total"
    :useDropdownMenu="true"
    :dropdownMenuActionsInfo="dropdownMenuActionsInfo"
    @updateTableData="handleSizeChange"
    @updateSwitchState="handelSwitchChange"
  >
    <template #ico>
      <el-icon><Operation /></el-icon>
    </template>
    <template #treeMeau>
      <el-card class="tree-card">
        <template #header>
          <div class="card-header">
            <span>角色管理</span>
            <el-button class="button" @click="handelRefreshTree" text
              >刷新</el-button
            >
          </div>
        </template>
        <!-- 树形菜单标签结构 -->
        <el-tree
          :data="$RoleManage.roleTreeList"
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
        <el-button type="primary" @click="handelDelete"> 确认 </el-button>
      </span>
    </template>
  </el-dialog>
  <!-- 添加业务=> 抽屉 -->
  <el-drawer
    size="45%"
    v-model="addDrawer"
    title="添加角色"
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
          <!-- 树形选择 -->
          <el-tree-select
            v-model="selectValue"
            :data="$RoleManage.roleTreeList"
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
          <el-switch v-model="delivery" />
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
    title="修改角色"
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
          <!-- 树形选择 -->
          <el-tree-select
            v-model="selectValue"
            :data="$RoleManage.roleTreeList"
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
          <el-switch v-model="delivery" />
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
  <!-- 菜单权限业务 => 抽屉 -->
  <el-drawer
    size="50%"
    v-model="powerDrawer"
    title="菜单权限"
    direction="rtl"
    open-delay="100"
  >
    <el-tree
      :data="$RoleManage.roleMeauPower"
      v-model="$RoleManage.roleMeauPower.visible"
      show-checkbox
      node-key="id"
      empty-text="没有数据"
      :props="defaultProps"
      :expand-on-click-node="false"
      :render-content="renderContent"
    >
      <template #default="{ node }">
        <span>{{ node.label }}</span>
        <el-checkbox-group v-model="authForm.type" v-if="node.type">
          <el-checkbox :label="node.sysMethodVoList" name="type" />
          <el-checkbox :label="node.sysMethodVoList" name="type" />
          <el-checkbox :label="node.sysMethodVoList" name="type" />
        </el-checkbox-group>
      </template>
    </el-tree>
    <div class="drawerFooter">
      <el-button @click="powerDrawer = false">取消</el-button>
      <el-button type="primary" :loading="btnLoading" @click="handelPowerSubmit"
        >保存数据</el-button
      >
    </div>
  </el-drawer>
</template>

<script setup>
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import { Operation, Plus, Search } from '@element-plus/icons-vue'
import { onMounted, ref } from 'vue'
import {
  getRoleTree,
  addRoleListApi,
  editRoleListApi,
  deleteRoleListApi,
  getRolePowerApi
} from '../../../apis/organizationStructure/Roles.js'
// 导入 组织结构/角色管理 仓库
import useRoleManageStore from '../../../stores/organizationStructure/rolesManage'
const $RoleManage = useRoleManageStore()
onMounted(async () => {
  //获取角色名称结构树
  await getRoleTree(
    {
      depth: 0,
      pid: 0
    },
    (res) => {
      const { data } = res
      console.log('获取角色名称结构树', data)
      // 默认以第一个角色获取表格数据
      defaultRole.value = data[0]
      currentTreeOption.value = data[0]
      // 处理数据 id =>value name => label
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
      // console.log('矫正后的角色结构树:', newArr)
      // 把数据存到 组织结构/角色管理 仓库
      $RoleManage.setRoleTreeList(newArr)
      console.log('角色管理 仓库数据:', $RoleManage.roleTreeList)
    },
    (error) => {
      console.log(error)
    }
  )
  // 开启表格加载
  baseDataListRef.value.openLoading = true

  // console.log($page)
  const res = await $RoleManage.getTheRoleList({
    keyword: defaultRole.value.name,
    pageIndex: $page.value.currentPage,
    pageSize: $page.value.pageSize,
    pid: ''
  })
  baseDataListRef.value.openLoading = false

  const {
    _rawValue: { data }
  } = res
  console.log(res.value)
  // 重新渲染
  sendData.value.total = data.total
  sendData.value.tableData = data.rows
})

// 获取分页数据
const $page = ref()
setTimeout(() => {
  $page.value = baseDataListRef.value.paginationData
  console.log('当前分页器数据', $page.value)
})

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
    // 发请求
    console.log('树形菜单数据:', treeData)
    currentTreeOption.value = treeData
    // 基于当前菜单树的数据，重新渲染表格
    // 开启表格加载
    baseDataListRef.value.openLoading = true
    const res = await $RoleManage.getTheRoleList({
      // keyword: currentTreeOption.value.name,
      keyword: '',
      pageIndex: $page.value.currentPage,
      pageSize: $page.value.pageSize,
      pid: currentTreeOption.value.parentID
    })
    const {
      _rawValue: { data }
    } = res
    // console.log(data)
    // 重新渲染
    sendData.value.total = data.total
    sendData.value.tableData = data.rows
    baseDataListRef.value.openLoading = false
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
      label: '角色名称',
      sortable: false
    },
    {
      prop: 'intro',
      label: '角色描述',
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
      name: '主管',
      intro: '公司小领导',
      sort: '4',
      visible: ''
    },
    {
      name: '组员',
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
// 默认角色
const defaultRole = ref({})
// 当前树形菜单
const currentTreeOption = ref([])
/**
 * 分页器切换处理方法
 */
const handleSizeChange = async (pagesize, currentPage) => {
  // 收集数据
  // console.log(currentTreeOption.value)
  console.log('分页器数据', pagesize, currentPage)
  // 开启表格加载
  baseDataListRef.value.openLoading = true

  const res = await $RoleManage.getTheRoleList({
    keyword: currentTreeOption.value.name,
    pageIndex: currentPage,
    pageSize: pagesize,
    pid: ''
  })
  const {
    _rawValue: { data }
  } = res
  // console.log(data)
  // 重新渲染
  sendData.value.total = data.total
  sendData.value.tableData = data.rows
  baseDataListRef.value.openLoading = false
}

// 操作菜单的数据和处理函数
const dropdownMenuActionsInfo = ref([
  {
    command: '菜单权限',
    handleAction: async (row) => {
      powerDrawer.value = true
      console.log('菜单权限回调函数', row)
      await getRolePowerApi(
        {
          roleId: row.id
        },
        (res) => {
          const { data } = res
          console.log('获取菜单权限成功回调:', data)
          ElMessage({
            message: '数据渲染成功',
            type: 'success'
          })
          // 把菜单权限数据存到 角色仓库
          $RoleManage.setroleMeauPower(data)
        }
      )
    },
    actionName: '菜单权限'
  },
  {
    command: '修改',
    // row为当前行的数据
    handleAction: (row) => {
      editDrawer.value = true
      isShowSelect.value = true
      console.log('修改回调函数', row)
      // 数据回显
      // 启用按钮的回显
      if (row.visible === 1) {
        delivery.value = true
      } else {
        delivery.value = false
      }
      // 需要发请求获取没有的数据
      addForm.value.name = row.name
      addForm.value.desc = row.intro
      addForm.value.sort = row.sort
      // 父级下拉选择
      if (row.parentID === 0) {
        row.parentID = '已是最高权限，无父级'
      }
      selectValue.value = row.parentID
      editRow.value = row
    },
    actionName: '修改'
  },
  {
    command: '删除',
    // row为当前行的数据
    handleAction: (row) => {
      isDelete.value = true
      console.log('删除回调函数', row)
      delRoleId.value = row.id
    },
    actionName: '删除'
  }
])
/**
 * 删除业务
 */
// 删除消息提示
const isDelete = ref(false)
// 处理删除角色的方法
const delRoleId = ref()
const handelDelete = async () => {
  await deleteRoleListApi(
    {
      id: delRoleId.value
    },
    async (res) => {
      console.log('删除角色成功回调函数', res)
      ElMessage({
        message: '删除成功',
        type: 'success'
      })
      // 重新渲染菜单树和表格数据
      //获取角色名称结构树
      await getRoleTree(
        {
          depth: 0,
          pid: 0
        },
        (res) => {
          const { data } = res
          // 处理数据 id =>value name => label
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
          // console.log('矫正后的角色结构树:', newArr)
          // 把数据存到 组织结构/角色管理 仓库
          $RoleManage.setRoleTreeList(newArr)
          console.log('角色管理 仓库数据:', $RoleManage.roleTreeList)
        },
        (error) => {
          console.log(error)
        }
      )
      baseDataListRef.value.openLoading = true
      const result = await $RoleManage.getTheRoleList({
        // keyword: currentTreeOption.value.name,
        keyword: '',
        pageIndex: $page.value.currentPage,
        pageSize: $page.value.pageSize,
        pid: currentTreeOption.value.parentID
      })
      const {
        _rawValue: { data }
      } = result
      // console.log(data)
      // 重新渲染
      sendData.value.total = data.total
      sendData.value.tableData = data.rows
      baseDataListRef.value.openLoading = false
    }
  )
  isDelete.value = false
}
// 控制抽屉打开关闭的数据
const addDrawer = ref(false)
// 抽屉表单数据
const addForm = ref({
  name: '',
  region: '选择上级',
  // 排位序号
  sort: '',
  desc: ''
})
// 是否启用的按钮
const delivery = ref(true)
// 表单元素宽度
const labelWidth = ref('100px')
// ref绑定表单
const theAddForm = ref()
const editForm = ref()

//表单校验规则

const formRule = ref({
  // 部门名称
  name: [
    { required: true, message: '请输入名称', trigger: 'blur' },
    { min: 1, max: 10, message: '名称必须是1-10位的字符', trigger: 'blur' }
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
  delivery.value = false
}

/**
 * 刷新业务，点击刷新，刷新菜单树
 */
const handelRefreshTree = async () => {
  //获取角色名称结构树
  await getRoleTree(
    {
      depth: 0,
      pid: 0
    },
    (res) => {
      const { data } = res
      console.log('获取角色名称结构树', data)
      // 默认以第一个角色获取表格数据
      defaultRole.value = data[0]
      currentTreeOption.value = data[0]
      // 处理数据 id =>value name => label
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
      // console.log('矫正后的角色结构树:', newArr)
      // 把数据存到 组织结构/角色管理 仓库
      $RoleManage.setRoleTreeList(newArr)
      // console.log('角色管理 仓库数据:', $RoleManage.roleTreeList)
      ElMessage({
        message: '刷新成功',
        type: 'success'
      })
    },
    (error) => {
      console.log(error)
    }
  )
}

// 按钮提交加载的数据和方法
const btnLoading = ref(false)
const handelAddSubmit = async () => {
  // 添加表单的校验,通过了才能发送添加请求
  await theAddForm.value.validate()
  if (delivery.value === '') {
    ElMessage({
      message: '请选择是否启用',
      type: 'warning'
    })
    return false
  }
  if (delivery.value === true) {
    delivery.value = 1
  } else {
    delivery.value = 0
  }
  // 收集数据
  console.log(
    '名称:',
    addForm.value.name,
    '排序:',
    addForm.value.sort,
    '启用:',
    delivery.value,
    '介绍:',
    addForm.value.desc,
    '父级栏目:',
    selectValue.value
  )
  // 这里要处理添加接口的逻辑
  btnLoading.value = true
  await addRoleListApi(
    {
      intro: addForm.value.desc,
      name: addForm.value.name,
      parentID: selectValue.value,
      sort: addForm.value.sort,
      visible: delivery.value
    },
    async (res) => {
      console.log('新增角色:', res)
      ElMessage({
        message: '提交成功',
        type: 'success'
      })
      baseDataListRef.value.openLoading = true

      // 重新刷新角色结构树
      await getRoleTree(
        {
          depth: 0,
          pid: selectValue.value
        },
        (res) => {
          const { data } = res
          console.log('刷新角色名称结构树', data)
          // 处理数据 id =>value name => label
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
          // console.log('矫正后的角色结构树:', newArr)
          // 把数据存到 组织结构/角色管理 仓库
          $RoleManage.setRoleTreeList(newArr)
          console.log('角色管理 仓库数据:', $RoleManage.roleTreeList)
        },
        (error) => {
          console.log(error)
        }
      )

      // 重新获取数据 刷新
      const result = await $RoleManage.getTheRoleList({
        keyword: '',
        pageIndex: $page.value.currentPage,
        pageSize: $page.value.pageSize,
        pid: selectValue.value
      })
      const {
        _rawValue: { data }
      } = result
      // 重新渲染
      sendData.value.total = data.total
      sendData.value.tableData = data.rows
      baseDataListRef.value.openLoading = false
    },
    (error) => {
      console.log(error)
    }
  )
  baseDataListRef.value.openLoading = false

  btnLoading.value = false
  addDrawer.value = false
}

// 编辑业务
const editRow = ref()
// 操作 => 修改抽屉
// 保存数据 按钮
const handelEditSubmit = async () => {
  // 修改的表单校验,通过才能发送put更新数据请求
  await editForm.value.validate()
  console.log(editRow.value)
  await editRoleListApi(
    {
      id: editRow.value.id,
      intro: editRow.value.intro,
      name: editRow.value.name,
      parentID: editRow.value.parentID,
      sort: editRow.value.sort,
      visible: editRow.value.visible
    },
    async (res) => {
      console.log('修改角色的成功回调', res)
      ElMessage({
        message: '修改成功',
        type: 'success'
      })
      editDrawer.value = false
      // 重新获取数据 刷新
      baseDataListRef.value.openLoading = true
      const result = await $RoleManage.getTheRoleList({
        keyword: currentTreeOption.value.name,
        pageIndex: $page.value.currentPage,
        pageSize: $page.value.pageSize,
        pid: editRow.value.parentID
      })
      const {
        _rawValue: { data }
      } = result
      // 重新渲染
      sendData.value.total = data.total
      sendData.value.tableData = data.rows
      baseDataListRef.value.openLoading = false
    }
  )
  // 在这里处理更新修改的接口
  editDrawer.value = false
}

// 表格的按钮更改处理函数
const handelSwitchChange = async (state, row) => {
  console.log('按钮数据更新:', state, row)
  // 点击按钮需要切换启用状态
  const newVisible = ref()
  if (row.visible === 1) {
    newVisible.value = 0
  } else {
    newVisible.value = 1
  }
  baseDataListRef.value.openSwitchLoading = true
  await editRoleListApi(
    {
      id: row.id,
      intro: row.intro,
      name: row.name,
      parentID: row.parentID,
      sort: row.sort,
      visible: newVisible.value
    },
    async (res) => {
      console.log('修改角色的成功回调', res)
      ElMessage({
        message: '修改成功',
        type: 'success'
      })
      // 重新获取数据 刷新
      const result = await $RoleManage.getTheRoleList({
        keyword: currentTreeOption.value.name,
        pageIndex: $page.value.currentPage,
        pageSize: $page.value.pageSize,
        pid: ''
      })
      const {
        _rawValue: { data }
      } = result
      // 重新渲染
      sendData.value.total = data.total
      sendData.value.tableData = data.rows
    }
  )
  baseDataListRef.value.openSwitchLoading = false
  state = !state
}

// 控制编辑抽屉打开/关闭的数据
const editDrawer = ref(false)
// 控制父级下拉选择的显示隐藏
const isShowSelect = ref(true)

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
  // 开启表格加载
  baseDataListRef.value.openLoading = true
  const res = await $RoleManage.getTheRoleList({
    keyword: searchKey.value,
    pageIndex: $page.value.currentPage,
    pageSize: $page.value.pageSize,
    pid: ''
  })
  baseDataListRef.value.openLoading = false

  const {
    _rawValue: { data }
  } = res
  console.log(res.value)
  // 重新渲染
  sendData.value.total = data.total
  sendData.value.tableData = data.rows
  btnLoading.value = false
  ElMessage({
    message: '操作成功',
    type: 'success'
  })
}

// 菜单权限业务
// 控制权限抽屉打开关闭的数据
const powerDrawer = ref(false)
const authForm = ref({
  type: []
})
// 菜单权限抽屉=>保存数据按钮的方法
const handelPowerSubmit = () => {
  btnLoading.value = true
  // 这里模拟发送请求
  setTimeout(() => {
    ElMessage({
      message: '操作成功',
      type: 'success'
    })
    btnLoading.value = false
    powerDrawer.value = false
  }, 1000)
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
.emptyTable {
  min-width: 800px;
  min-height: 600px;
}
</style>
