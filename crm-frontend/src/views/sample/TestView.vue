<template>
  <div style="color: red">测试BaseDataList组件</div>
  <!-- 测试 -->
  <BaseDataList
    :msg="sendData.msg"
    :table-column-attribute="sendData.tableColumnAttribute"
    :use-dropdown-menu="sendData.useDropdownMenu"
    :handle-delete="sendData.handleDelete"
    :handle-edit="sendData.handleEdit"
    :table-data="sendData.tableData"
    :dropdown-menu-actions-info="sendData.dropdownMenuActionsInfo"
    :page-sizes="sendData.pageSizes"
    :total="sendData.total"
    :use-pagination="sendData.usePagination"
    :use-header="sendData.useHeader"
    :use-select-column="sendData.useSelectColumn"
    :use-operate-column="sendData.useOperateColumn"
    @update-table-data="get"
    @update-switch-state="get1"
    ref="baseDataListRef"
  >
    <!-- 图标插槽 -->
    <template #ico>
      <el-icon style="margin-right: 4px"><icon-refresh /></el-icon>
    </template>
    <template #menu>
      <div>
        插槽区
        <el-button @click="getRows"
          >获取被勾选的列/////off或者open表格加载动画</el-button
        >
      </div>
    </template>
  </BaseDataList>
</template>

<script setup>
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import { ref, onMounted } from 'vue'

// 测试数据传递

const sendData = {
  msg: '一些操作说明',
  tableColumnAttribute: [
    // prop属性和label属性必选
    // sortable可选
    // useTag可选
    {
      prop: 'sex',
      label: '性别',
      // 是否使用排序
      sortable: true
    },
    {
      prop: 'age',
      label: '年龄',
      sortable: true
    },
    {
      prop: 'hoby',
      label: '爱好'
    },
    // tag列
    {
      prop: 'data',
      label: 'tag列',
      // 该列数据是否使用tag
      useTag: true
    },
    // 开关列
    {
      prop: 'isUse',
      label: '开关列',
      // 该列数据是否使用switch开关
      useSwitch: true
    },
    // 图片列
    {
      prop: 'picture',
      label: '图片列',
      // 该列数据是否使用图片
      usePic: true
    }
  ],
  tableData: [
    {
      sex: '男',
      age: 19,
      hoby: '唱歌',
      // tagType 对应的五种类型
      // success
      // danger
      // info
      // warning
      // el => 对应主题色
      data: {
        // value 和 tagType字段不能改变
        value: '已入库',
        tagType: 'success'
      },
      isUse: true,
      picture:
        'https://fuss10.elemecdn.com/e/5d/4a731a90594a4af544c0c25941171jpeg.jpeg'
    },
    {
      sex: '女',
      age: 21,
      hoby: 'rap',
      data: {
        value: '未入库',
        tagType: 'danger'
      },
      isUse: true,
      picture:
        'https://fuss10.elemecdn.com/e/5d/4a731a90594a4af544c0c25941171jpeg.jpeg'
    },
    {
      sex: '男',
      age: 22,
      hoby: '篮球',
      data: {
        value: 'Info状态',
        tagType: 'info'
      },
      isUse: true,
      picture:
        'https://fuss10.elemecdn.com/e/5d/4a731a90594a4af544c0c25941171jpeg.jpeg'
    },
    {
      sex: '男',
      age: 22,
      hoby: '篮球',
      data: {
        value: 'warning状态',
        tagType: 'warning'
      },
      isUse: true,
      picture:
        'https://fuss10.elemecdn.com/e/5d/4a731a90594a4af544c0c25941171jpeg.jpeg'
    },
    {
      sex: '男',
      age: 22,
      hoby: '篮球',
      data: {
        value: '主题色',
        tagType: 'el'
      },
      isUse: false,
      picture:
        'https://fuss10.elemecdn.com/e/5d/4a731a90594a4af544c0c25941171jpeg.jpeg'
    }
  ],
  // 传入删除操作的函数就会显示删除按钮
  handleDelete: (row) => {
    console.log('删除', row)
  },
  handleEdit: (row) => {
    console.log('编辑', row)
  },
  // 是否使用下拉菜单
  useDropdownMenu: true,
  // 下拉菜单
  // 更改command  handleAtion  actionName的属性值
  dropdownMenuActionsInfo: [
    {
      command: 'delete',
      // row为当前行的数据
      handleAction: (row) => {
        console.log('删除的回调函数', row)
      },
      actionName: '删除'
    },
    {
      command: 'edit',
      handleAction: (row) => {
        console.log('修改的回调函数', row)
      },
      actionName: '修改'
    },
    {
      command: 'add',
      handleAction: (row) => {
        console.log('添加的回调函数', row)
      },
      actionName: '添加'
    }
  ],
  pageSizes: [2, 10, 15, 200],
  // total 表格的总数据量     total传入数据 和 usePagination为true 才能显示分页
  total: 100,
  // 是否使用分页
  usePagination: false,
  // 是否使用el-card的header
  useHeader: true,
  // 是否使用使用多选列
  useSelectColumn: true,
  // 是否使用操作列
  useOperateColumn: true
}
const baseDataListRef = ref(null)
const get = (pageSize, currentPage) => {
  console.log('调用父组件的更新数据的函数')
  console.log('pageSize', pageSize)
  console.log('currentPage', currentPage)
}
const get1 = (state, row) => {
  console.log('调用后端的接口发请求修改开关的state后才能真正改变开关的状态')
  console.log('开关的状态已被修改，为：', state)
  console.log('当前行的数据', row)
  // 开启loading
  baseDataListRef.value.openSwitchLoading =
    !baseDataListRef.value.openSwitchLoading
  // 关闭loading  模拟异步请求
  setTimeout(() => {
    baseDataListRef.value.openSwitchLoading =
      !baseDataListRef.value.openSwitchLoading
  }, 1000)
}
const getRows = () => {
  // 获取组件暴露出来的rows
  console.log('rows', baseDataListRef.value.rows)
  // 关闭表格加载动画
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}
onMounted(() => {})
</script>

<style lang="scss" scoped></style>
