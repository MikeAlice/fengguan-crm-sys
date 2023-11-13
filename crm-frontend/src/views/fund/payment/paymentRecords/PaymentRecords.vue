<!--
 * @Author: seven 1473008948@qq.com
 * @Date: 2023-10-26 21:58:11
 * @LastEditors: seven 1473008948@qq.com
 * @LastEditTime: 2023-11-03 15:01:16
 * @FilePath: \zero-one-crmsys\crm-frontend\src\views\fund\payment\paymentRecords\PaymentRecords.vue
-->

<template>
  <BaseDataList
    class="card"
    :title="sendData.title"
    :msg="sendData.msg"
    :table-column-attribute="tableColumnAttribute"
    :table-data="paymentRecordsStore.tableData"
    :page-sizes="sendData.pageSizes"
    :total="paymentRecordsStore.tableTotal"
    useDropdownMenu="true"
    :dropdownMenuActionsInfo="sendData.dropdownMenuActionsInfo"
    useOperateColumn="true"
    useCalculate="true"
    :totalMoney="paymentRecordsStore.money"
    :totalBackMoney="paymentRecordsStore.back_money"
    :totalOweMoney="paymentRecordsStore.owe_money"
    @selectFuckingChange="selectChange"
    @update-table-data="
      (pageSize, currentPage) =>
        getPaymentRecordsList({
          pageSize,
          pageIndex: currentPage
        })
    "
    ref="baseDataListRef"
    @command="(command) => handleCommand(command, row)"
  >
    <template #menu>
      <!-- 表格上面一行 -->
      <div class="menu">
        <div class="left">
          <el-button
            type="primary"
            :icon="Plus"
            style="margin: 0; width: 90px"
            @click="addData"
            >添加数据</el-button
          >
          <el-button @click="changeLoadAnimation">刷新</el-button>
          <!-- 下拉选择框 -->
          <BulkOPe :getOpt="() => [0, 2, 3, 4]">
            <template #excel>
              <div>
                下拉选择：<ChooseSelect @update:cid="changecid"></ChooseSelect>
              </div>
            </template>
          </BulkOPe>
          <!-- <el-button :disabled="selectArr.length ? false: true" @click="deleteData" type="waring" color="#FF3800"
            >批量删除</el-button
          > -->
          <el-popconfirm
            :title="`你确定要删除这些选择的客户吗?`"
            width="240px"
            @confirm="deleteByQuery"
          >
            <template #reference>
              <el-button
                type="danger"
                icon="IconDelete"
                style="margin-right: 10px"
                :disabled="isDisabled"
                >批量删除</el-button
              >
            </template>
          </el-popconfirm>
        </div>
        <div class="right">
          <ChooseSelect
            style="margin-right: 5px; width: 130px"
            des="付款日期所有"
            :options="options"
          ></ChooseSelect>
          <ChooseSelect
            style="margin-right: 5px; width: 130px"
            :options="options"
            des="创建日期所有"
          ></ChooseSelect>
          <el-input
            v-model="searchContractTitle"
            placeholder="搜索请输入合同标题"
            style="margin-right: 4px; width: 180px"
          />
          <!-- 搜索功能还需完善 -->
          <DropDown
            :getDropDown="() => [0, 1, 3]"
            v-model:inputVal1="inputValue1"
            v-model:inputVal2="inputValue2"
            inputTitle1="供应商名称"
            inputTitle2="金额"
            @handle-search="handleSearch"
          ></DropDown>
          <el-button
            type="primary"
            style="margin-left: 4px"
            @click="searchDetails"
            :disabled="searchContractTitle ? false : true"
          >
            <el-icon style="margin-right: 4px"><icon-search /></el-icon>搜索
          </el-button>
        </div>
      </div>
    </template>
    <!-- 分页 -->
    <template>
      <el-pagination
        v-model:current-page="paginationData.currentPage"
        v-model:page-size="paginationData.pageSize"
        :page-sizes="sendData.pageSizes"
        layout="prev, pager, next, jumper, ->, total, sizes"
        :total="sendData.total"
        @size-change="handleSizeChange"
        @current-change="handleCurrentChange"
        style="margin-top: 30px"
      />
    </template>
    <!-- 插槽显示图标 -->
    <template #ico>
      <el-icon><SoldOut /></el-icon>
    </template>
  </BaseDataList>
  <!-- 添加或修改付款记录 -->
  <el-drawer
    v-model="dialogVisible"
    :title="paymentRecordsData.id === '' ? '添加付款记录' : '修改付款记录'"
    size="50%"
  >
    <el-form
      :model="paymentRecordsData"
      label-width="120px"
      label-position="right"
    >
      <el-form-item label="供应商名称">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择供应商名称"
          :options="options"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="采购订单">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择采购订单"
          :options="options"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="总金额">
        <el-input value="0" style="width: 500px" />
      </el-form-item>
      <el-form-item label="去零金额">
        <el-input value="0" style="width: 500px" />
      </el-form-item>
      <el-form-item label="已付金额">
        <el-input value="0" style="width: 500px" />
      </el-form-item>
      <el-form-item label="已收发票金额">
        <el-input value="0" style="width: 500px" />
      </el-form-item>
      <el-form-item label="付款日期">
        <el-date-picker
          v-model="paymentRecordsData.start_date"
          type="datetime"
          placeholder="选择合同生效开始时间"
        >
        </el-date-picker>
      </el-form-item>
      <el-form-item label="期次">
        <el-input
          v-model="paymentRecordsData.intro"
          placeholder="请输入付款期次"
          style="width: 650px"
        />
      </el-form-item>
      <el-form-item label="付款金额">
        <el-input value="0" style="width: 500px" />
      </el-form-item>
      <el-form-item label="去零金额">
        <el-input value="0" style="width: 500px" />
      </el-form-item>
      <el-form-item label="尚欠金额">
        <el-input value="0" style="width: 500px" />
      </el-form-item>
      <el-form-item label="付款账户">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择付款账户"
          :options="options"
        ></ChooseSelect>
      </el-form-item>
    </el-form>
    <template #footer>
      <span class="dialog-footer">
        <el-button type="primary" @click="saveData"> 保存 </el-button>
      </span>
    </template>
  </el-drawer>
</template>

<script setup>
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import BulkOPe from '@/components/BulkOpe/BulkOPe.vue'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'
import { ref, onMounted } from 'vue'
import DropDown from '@/components/DropDown/DropDown.vue'
import { SoldOut, Plus } from '@element-plus/icons-vue'
import { ElMessage } from 'element-plus'
import { usePaymentRecordsStore } from '@/stores/fund/paymentrecords/paymentRecords.js'

// 搜索框的searchDetails方法还需完善

// 批量删除所选列表
// let selectArr = ref([])

const isDisabled = ref(true)
// // table表勾选时触发的事件
const selectChange = (length) => {
  if (length === 0) {
    isDisabled.value = true
  } else {
    isDisabled.value = false
  }
}
// 删除成功的回调
const deleteByQuery = () => {
  ElMessage.success('删除成功')
  isDisabled.value = !isDisabled.value
}

// 付款日期所有的选项
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
// 控制抽屉的显示与否
let dialogVisible = ref(false)

//添加付款记录
// 新增付款记录
let paymentRecordsData = ref({
  id: '',
  contract_no: 0,
  title: '',
  start_date: '',
  end_date: '',
  money: 0,
  intro: ''
})

// 添加或者修改后的重置数据
// const resetData = ref({
//   id: '',
//   contract_no: 0,
//   title: '',
//   start_date: '',
//   end_date: '',
//   money: 0,
//   intro: ''
// })

// 添加按钮的回调函数
let addData = () => {
  dialogVisible.value = true
}

// 点击保存按钮后的回调函数用来保存数据
// 这里需要供应商列表的接口来获取数据
const saveData = () => {
  // paymentRecordsData.value.contract_no = 0
  // paymentRecordsData.value.happen_date = ''
  // paymentRecordsData.value.end_date = ''
  // paymentRecordsData.value.money = 0
  // paymentRecordsData.value.intro = ''
  dialogVisible.value = false
  // 这里还需要对表单数据进行判断的 还需完善
  if (paymentRecordsData.value.id === '') {
    console.log('新增数据成功')
    ElMessage.success('添加成功')
  }
  // 还需完善
  // ElMessage.success('修改成功')
  // console.log('修改或者新增的合同数据：', paymentRecordsData.value)
  // paymentRecordsData.value = resetData.value
}

// 搜索的销售合同标题
const searchContractTitle = ref('')

// 搜索框的searchDetails方法还需完善
const searchDetails = () => {
  console.log('搜索', searchContractTitle.value)
  const searchData = paymentRecordsStore.tableData.filter((item) => {
    return item.title === searchContractTitle.value
  })
  if (searchData.length === 0) {
    ElMessage({
      type: 'warning',
      message: '未找到相关数据，请重新输入合同主题'
    })
  } else {
    paymentRecordsStore.tableData = searchData
  }
}

// 付款记录列表项
const tableColumnAttribute = [
  {
    prop: 'supplier_name',
    label: '供应商名称',
    sortable: true
  },
  {
    prop: 'procurement_contract',
    label: '采购合同'
  },
  {
    prop: 'payment_date',
    label: '付款时间'
  },
  {
    prop: 'period',
    label: '期次'
  },
  {
    prop: 'money',
    label: '金额'
  },
  {
    prop: 'zero_money',
    label: '去零'
  },
  {
    prop: 'create_man',
    label: '创建人'
  },
  {
    prop: 'create_date',
    label: '创建时间'
  },
  {
    prop: 'intro',
    label: '备注'
  }
]

// 数据传递
const sendData = {
  title: '付款记录',
  // 操作提示的内容
  msg: '付款记录的操作说明',
  dropdownMenuActionsInfo: [
    // 操作列表的删除操作 还需完善
    {
      command: 'delete',
      // row为当前行的数据
      handleAction: (row) => {
        alert('确认删除吗')
        // 获取当前行的id
        const id = row.id
        console.log('删除当前行数据', id)
        paymentRecordsStore.tableData = paymentRecordsStore.tableData.filter(
          (item) => {
            return item.id !== id
          }
        )
        console.log(paymentRecordsStore.tableData)
      },
      actionName: '删除'
    }
  ],
  // 分页数组
  pageSizes: [5, 10, 15],
  total: 100
}

// 引入获取销售合同的仓库
const paymentRecordsStore = usePaymentRecordsStore()

//
const getPaymentRecordsList = async (params) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await paymentRecordsStore.getTableData(params)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}
// 挂载时获得分页数据
onMounted(() => {
  // const bb = JSON.parse(JSON.stringify(Data))
  // console.log('bb', bb)
  const params = {
    pageIndex: 1,
    pageSize: 5
  }
  getPaymentRecordsList(params)
})

// 处理请求提交的方法 修改数据
const handleCommand = (command, row) => {
  const item = sendData.dropdownMenuActionsInfo.find((item) => {
    return item.command === command
  })
  item.handleAction(row)
}

const baseDataListRef = ref()
//分页器组件点击调用get
const paginationData = ref({
  currentPage: 1,
  pageSize: sendData.pageSizes ? sendData.pageSizes[0] : 5
})

// 处理选择的行是否发生变化
// const handleSelectionChange = (newRows) => {
//   baseDataListRef.value.rows = newRows
// }
// 开启/关闭表格加载动画
const changeLoadAnimation = () => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  setTimeout(() => {
    baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  }, 500)
}

// const excel = () => {
//   console.log('s', baseDataListRef.value.rows)
// }
</script>

<style lang="scss" scoped>
.main {
  width: 100%;
}

.card {
  width: 100%;
  height: 100%;
}

button {
  margin-left: 5px;
  margin-right: 5px;
}

.menu {
  display: flex;
  align-items: center;
  justify-content: space-between;
  margin-bottom: 10px;

  .left {
    height: 40px;
  }
  .right {
    height: 40px;
    display: flex;
    align-items: center;
  }
}

.dialog-footer {
  display: flex;
  justify-content: space-around;
}

#getCol {
  margin-left: 10px;
  margin-right: 10px;
}
.drawer2 {
  display: flex;
  justify-content: space-between;
}
.title {
  margin-top: 20px;
  display: flex;
  justify-content: space-between;
}

.info {
  display: flex;
  margin-top: 10%;
  justify-content: space-around;
}

// 表格里的内容换行用
:deep(.el-table .cell) {
  white-space: pre-wrap;
}
</style>
