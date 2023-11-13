<template>
  <div class="base_data_list">
    <el-card class="box-card">
      <template #header v-if="props?.useHeader">
        <div class="card-header">
          <h3 style="display: flex; align-items: center">
            <slot name="ico"></slot>
            <div style="margin-left: 8px">{{ props.title }}</div>
          </h3>
          <el-button
            class="button"
            @click="operatingInstructionDialogVisible = true"
          >
            <el-icon style="margin-right: 4px"> <icon-question /></el-icon
            >操作说明</el-button
          >
        </div>
      </template>
      <div class="main">
        <!-- 树形菜单插槽 -->
        <slot name="treeMeau"></slot>
        <div class="theTable">
          <!-- 表格的menu操作菜单 -->
          <slot name="menu"></slot>
          <!-- 表格 -->
          <el-table
            :data="props?.tableData"
            style="width: 100%"
            @selection-change="handleSelectionChange"
            v-loading="openLoading"
            table-layout="auto"
          >
            <!-- 带有多选功能的列 -->
            <el-table-column
              type="selection"
              v-if="props.useSelectColumn"
              width="55"
            />
            <el-table-column
              v-for="item in props?.tableColumnAttribute"
              :prop="item.prop"
              :label="item.label"
              :key="item"
              :sortable="item?.sortable"
              class-name="class-name"
            >
              <!-- 表格的列内容如果使用tag -->
              <template #default="{ row }" v-if="item.useTag">
                <el-tag :type="row[item.prop].tagType">{{
                  row[item.prop].value
                }}</el-tag>
              </template>
              <!-- 表格列使用switch开关 -->
              <template #default="{ row }" v-else-if="item.useSwitch">
                <el-switch
                  :model-value="row[item.prop] ? true : false"
                  inline-prompt
                  active-text="是"
                  inactive-text="否"
                  size="large"
                  :loading="openSwitchLoading"
                  @change="(state) => emits('updateSwitchState', state, row)"
                />
              </template>
              <!-- 表格数据包含图片 -->
              <template #default="{ row }" v-else-if="item.usePic">
                <el-image
                  style="width: 60px; height: 60px"
                  :src="row[item.prop]"
                  fit="fit"
                />
              </template>
            </el-table-column>
            <el-table-column
              label="操作"
              v-if="!props?.useDropdownMenu && props.useOperateColumn"
              fixed="right"
            >
              <!-- 带图标的按钮操作 -->
              <template #default="{ row }">
                <!-- 条件渲染按钮 -->
                <template v-if="props.handleEdit">
                  <el-tooltip content="编辑" placement="top">
                    <el-button
                      plain
                      circle
                      type="primary"
                      @click="props.handleEdit(row)"
                    >
                      <el-icon> <icon-edit /></el-icon>
                    </el-button> </el-tooltip
                ></template>
                <!-- 条件渲染按钮 -->
                <template v-if="props.handleDelete">
                  <el-tooltip content="删除" placement="top"
                    ><el-button
                      plain
                      circle
                      type="danger"
                      @click="props.handleDelete(row)"
                    >
                      <el-icon>
                        <icon-delete
                      /></el-icon> </el-button></el-tooltip
                ></template>
              </template>
            </el-table-column>
            <el-table-column
              label="操作"
              v-else-if="props.useDropdownMenu && props.useOperateColumn"
              fixed="right"
            >
              <!-- 下拉菜单的按钮操作 -->
              <template #default="{ row }">
                <el-dropdown
                  trigger="click"
                  @command="(command) => handleCommand(command, row)"
                >
                  <el-button>
                    操作
                    <el-icon style="margin-left: 4px"
                      ><icon-caret-bottom
                    /></el-icon>
                  </el-button>
                  <template #dropdown>
                    <el-dropdown-menu>
                      <el-dropdown-item
                        v-for="(item, index) in props?.dropdownMenuActionsInfo"
                        :key="index"
                        :command="item.command"
                        >{{ item.actionName }}</el-dropdown-item
                      >
                    </el-dropdown-menu>
                  </template>
                </el-dropdown></template
              >
            </el-table-column>
            <!-- 表格没有数据的样式 -->
            <template #empty>
              <el-empty class="emptyTable" description="没有数据"></el-empty>
            </template>
          </el-table>
        </div>
      </div>
      <template v-if="props?.useCalculate">
        <div>
          合同金额统计：￥{{
            totalMoney
          }}
          回款金额统计：￥{{}} 欠款金额统计：￥{{}}
        </div>
      </template>
      <slot name="statistics"></slot>

      <!-- 分页 -->
      <template v-if="props?.usePagination">
        <el-pagination
          v-model:current-page="paginationData.currentPage"
          v-model:page-size="paginationData.pageSize"
          :page-sizes="props.pageSizes"
          layout="prev, pager, next, jumper, ->, total, sizes"
          :total="props.total"
          @size-change="handleSizeChange"
          @current-change="handleCurrentChange"
          style="margin-top: 30px"
        />
      </template>

      <!-- 操作说明的会话框 -->
      <el-dialog
        v-model="operatingInstructionDialogVisible"
        title="操作说明"
        width="50%"
      >
        <span>{{ props.msg }}</span>
      </el-dialog>
    </el-card>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import { useSalesContractStore } from '@/stores/salesmanager/SalesContract.js'

// 导入销售合同列表的仓库
const useSalesContractStore1 = useSalesContractStore()

const props = defineProps({
  // 标题
  title: {
    type: String,
    require: 'true',
    default: '标题的默认值'
  },
  // 操作说明的提示
  msg: {
    type: String,
    require: true,
    default: '操作提示的默认值'
  },
  // 表格的列属性
  tableColumnAttribute: {
    type: Array,
    require: true
  },
  // 是否使用下拉菜单的按钮
  useDropdownMenu: {
    type: Boolean,
    default: false
  },
  // 下拉菜单
  dropdownMenuActionsInfo: {
    type: Array,
    default: () => {
      return [
        {
          command: '操作1',
          // row为当前行的数据
          handleAction: (row) => {
            console.log('操作1回调函数', row)
          },
          actionName: '操作1的名称'
        },
        {
          command: '操作2',
          // row为当前行的数据
          handleAction: (row) => {
            console.log('操作2回调函数', row)
          },
          actionName: '操作2的名称'
        },
        {
          command: '操作3',
          // row为当前行的数据
          handleAction: (row) => {
            console.log('操作3回调函数', row)
          },
          actionName: '操作3的名称'
        }
      ]
    }
  },
  // 不启用下拉菜单的时候的编辑和删除按钮的回调函数
  handleDelete: Function,
  handleEdit: Function,
  // 表格数据
  tableData: Array,
  // 表格每页的数据容量
  pageSizes: {
    type: Array,
    default: () => {
      return [5, 10, 15, 20]
    }
  },
  // 表格的数据数量
  total: {
    type: Number,
    require: true
  },
  // 是否使用分页器
  usePagination: {
    type: Boolean,
    default: true
  },
  //是否使用表格最下面的计算总金额
  useCalculate: {
    type: Boolean,
    default: false
  },
  // 是否使用el-card的header
  useHeader: {
    type: Boolean,
    default: true
  },
  // 是否使用使用多选列
  useSelectColumn: {
    type: Boolean,
    default: true
  },
  // 是否使用操作列
  useOperateColumn: {
    type: Boolean,
    default: true
  }
})

const paginationData = ref({
  currentPage: 1,
  pageSize: props.pageSizes ? props.pageSizes[0] : 5
})

// const tableDataList = ref(useSalesContractStore1.tableData)

// let MoneyList = ref([])
// // let totalMoney = ref(0)
// // 计算合同总金额
// let totalMoney = computed(() => {
//   // MoneyList.value = useSalesContractStore1.tableData
//   // console.log('moneyList', MoneyList.value[0].money)
//   // console.log(useSalesContractStore1.tableData)
//   // 循环遍历得到tableData中的所有money值
//   // for (let i = 0; i < 5; i++) {
//   //   totalMoney.value += MoneyList.value[i].money
//   // }
//   // return totalMoney.value
// })
// let totalBackMoney = ref(0)
// let totalOweMoney = ref(0)

const rows = ref([])

// 表格的loading
const openLoading = ref(false)
// 开关的loading
const openSwitchLoading = ref(false)
// 是否显示操作说明的dialog
const operatingInstructionDialogVisible = ref(false)

const handleCommand = (command, row) => {
  const item = props.dropdownMenuActionsInfo.find((item) => {
    return item.command === command
  })
  item.handleAction(row)
}
const handleSelectionChange = (newRows) => {
  rows.value = newRows
}
// 调用父组件更新表格数据的函数
//  updateSwitchState 调用父组件的修改开关状态的函数
const emits = defineEmits(['updateTableData'], ['updateSwitchState'])

const handleSizeChange = (pageSize) => {
  // 当前页的数据容量改变，重置页码为1
  paginationData.value.pageSize = pageSize
  paginationData.value.currentPage = 1
  // 传入当前页面容量大小和当前页码
  emits('updateTableData', pageSize, paginationData.value.currentPage)
}

const handleCurrentChange = (currentPage) => {
  paginationData.value.currentPage = currentPage
  // 传入当前页码容量大小和当前页码
  emits('updateTableData', paginationData.value.pageSize, currentPage)
}

defineExpose({
  // 暴露出被选中的row
  rows,
  // 暴露出表格的加载
  openLoading,
  // 暴露出分页数据
  paginationData,
  // 开关的loading
  openSwitchLoading
})

const getSalesContractList = async (params) => {
  await useSalesContractStore1.getTableData(params)
}
// 挂载时获得分页数据
onMounted(() => {
  // const bb = JSON.parse(JSON.stringify(Data))
  // console.log('bb', bb)
  const params = {
    pageIndex: 1,
    pageSize: 5
  }
  getSalesContractList(params)
})
</script>

<style lang="scss" scoped>
.base_data_list {
  .box-card {
    .card-header {
      display: flex;
      justify-content: space-between;
      align-items: center;
    }
  }
}
.class-name {
  font-size: 18px;
}

:deep(.el-pagination) {
  justify-content: center;
}
.main {
  display: flex;
}
.theTable {
  width: 100%;
  padding: 20px;
  padding-top: 0;
}
.emptyTable {
  min-width: 800px;
  min-height: 600px;
}
:deep(.el-pagination__rightwrapper) {
  flex: 0;
}
</style>
