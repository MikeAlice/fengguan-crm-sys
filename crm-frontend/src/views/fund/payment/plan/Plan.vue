<!--
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-10-28 14:38:07
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-06 10:56:57
 * @FilePath: \zero-one-crmsys\crm-frontend\src\views\fund\injectionExtraction\InjectionExtraction.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <!-- <div>付款计划更新更新</div> -->
  <BaseDataList
    title="付款计划"
    msg="这里是操作提示"
    ref="baseDataListRef"
    :table-column-attribute="sendData.tableColumnAttribute"
    :table-data="sendData.tableData"
    :page-sizes="sendData.pageSizes"
    :total="sendData.total"
    :useDropdownMenu="true"
    :dropdownMenuActionsInfo="dropdownMenuActionsInfo"
  >
    <template #ico>
      <el-icon>
        <CreditCard />
      </el-icon>
    </template>
    <template #menu>
      <div class="meau">
        <!-- 这里是表格头部的控件 -->
        <div class="left">
          <el-button @click="handelAddFn">
            <el-icon type="success" circle>
              <el-icon> <Plus /> </el-icon
            ></el-icon>
            添加
          </el-button>
          <!-- 下拉选择框 -->
          <BulkOPe :excelData="getRows" :getOpt="() => [3, 4]">
            <template #excel>
              <div>
                下拉选择：<ChooseSelect @update:cid="changecid"></ChooseSelect>
              </div>
            </template>
          </BulkOPe>
          <el-button type="danger" icon="IconDelete">批量删除</el-button>
        </div>
        <!-- 全部/已付/未付 -->
        <!-- <el-menu
          :default-active="activeIndex"
          class="el-menu-demo"
          mode="horizontal"
          @select="handelMeauSelect"
        >
          <el-menu-item index="1"> 全部</el-menu-item>
          <el-menu-item index="2"> 已付</el-menu-item>
          <el-menu-item index="3"> 未付</el-menu-item>
        </el-menu> -->

        <div class="search">
          <div class="btnWrap">
            <el-button
              v-for="button in buttons"
              :key="button.text"
              :type="button.type"
              text
              @click="handelBtnSearch(button)"
              >{{ button.text }}</el-button
            >
          </div>
          <ChooseSelect :options="optionsSec" des="产生日期所有"></ChooseSelect>
          <ChooseSelect :options="optionsThi" des="创建日期所有"></ChooseSelect>
          <el-input
            placeholder="请输入关键字搜索"
            v-model="searchKey"
            style="width: 150px"
          ></el-input>
          <DropDown
            :inputValue1="tel"
            inputTitle1="供应商名称"
            :inputValue2="tel1"
            inputTitle2="搜索金额"
            :getDropDown="
              () => {
                return [0, 1, 3]
              }
            "
            @handleSearch="handleSearch"
          ></DropDown>
          <el-button type="primary" :icon="Search" @click="handelSearch"
            >搜索</el-button
          >
        </div>
      </div>
    </template>
  </BaseDataList>
  <el-dialog v-model="isDelete" title="温馨提示" width="30%">
    <span>你确认要删除吗?</span>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="isDelete = false">取消</el-button>
        <el-button type="primary" @click="isDelete = false"> 确认 </el-button>
      </span>
    </template>
  </el-dialog>
  <!-- 添加业务=> 抽屉 -->
  <el-drawer
    size="45%"
    v-model="addDrawer"
    title="添加付款计划"
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
        <el-form-item label="供应商名称" :label-width="labelWidth">
          <!-- 调用选择框组件 -->
          <ChooseSelect
            :options="supplierSelect"
            des="请选择供应商"
          ></ChooseSelect>
        </el-form-item>
        <el-form-item label="采购订单" :label-width="labelWidth">
          <!-- 调用选择框组件 -->
          <ChooseSelect
            :options="PurOrder"
            des="请选择供应商采购订单"
          ></ChooseSelect>
        </el-form-item>
        <el-form-item label="总金额" :label-width="labelWidth">
          <el-input v-model="addForm.TotalAmount" disabled placeholder="" />
        </el-form-item>
        <el-form-item label="去零金额" :label-width="labelWidth">
          <el-input v-model="addForm.ZeroAmount" disabled placeholder="" />
        </el-form-item>
        <el-form-item label="已付金额" :label-width="labelWidth">
          <el-input v-model="addForm.amountPaid" disabled placeholder="" />
        </el-form-item>
        <el-form-item label="已收发票金额" :label-width="labelWidth">
          <el-input v-model="addForm.invoiceAmount" disabled placeholder="" />
        </el-form-item>
        <el-form-item label="计划付款日期" :label-width="labelWidth">
          <el-date-picker
            v-model="addForm.PlanPaymentDate"
            type="date"
            placeholder="选择计划付款日期"
            :size="size"
          />
        </el-form-item>
        <el-form-item label="期次" :label-width="labelWidth" prop="period">
          <el-input v-model="addForm.period" autocomplete="off" />
        </el-form-item>
        <el-form-item label="金额" :label-width="labelWidth" prop="amount">
          <el-input v-model="addForm.amount" autocomplete="off" />
        </el-form-item>
      </el-form>
      <div class="drawerFooter">
        <el-button @click="addDrawer = false">取消</el-button>
        <el-button type="primary" :loading="btnLoading" @click="handelAddSubmit"
          >保存数据</el-button
        >
      </div>
    </div>
  </el-drawer>
  <!-- 付款业务 => 抽屉 -->
  <el-drawer
    size="45%"
    v-model="payDrawer"
    title="确认付款"
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
        <el-form-item label="供应商名称" :label-width="labelWidth">
          <!-- 调用选择框组件 -->
          <ChooseSelect
            ref="PaySupplierSelect"
            :options="supplierSelect"
            des="请选择供应商"
            @update:cid="handelSupplierSelect"
          ></ChooseSelect>
        </el-form-item>
        <el-form-item label="采购订单" :label-width="labelWidth">
          <!-- 调用选择框组件 -->
          <ChooseSelect
            :options="PurOrder"
            des="请选择供应商采购订单"
          ></ChooseSelect>
        </el-form-item>
        <el-form-item label="总金额" :label-width="labelWidth">
          <el-input v-model="payForm.TotalAmount" disabled placeholder="" />
        </el-form-item>
        <el-form-item label="去零金额" :label-width="labelWidth">
          <el-input v-model="payForm.ZeroAmount" disabled placeholder="" />
        </el-form-item>
        <el-form-item label="已付金额" :label-width="labelWidth">
          <el-input v-model="payForm.amountPaid" disabled placeholder="" />
        </el-form-item>
        <el-form-item label="已收发票金额" :label-width="labelWidth">
          <el-input v-model="payForm.invoiceAmount" disabled placeholder="" />
        </el-form-item>
        <el-form-item label="付款日期" :label-width="labelWidth">
          <el-date-picker
            v-model="payForm.PlanPaymentDate"
            type="date"
            placeholder="选择计划付款日期"
            :size="size"
          />
        </el-form-item>
        <el-form-item label="期次" :label-width="labelWidth">
          <el-input v-model="payForm.period" disabled autocomplete="off" />
        </el-form-item>
        <el-form-item label="付款金额" :label-width="labelWidth">
          <el-input v-model="payForm.amount" disabled autocomplete="off" />
        </el-form-item>
        <el-form-item label="付款账户" :label-width="labelWidth">
          <ChooseSelect
            :options="fundInjection.bankSelectList"
            des="选择付款账户"
          ></ChooseSelect>
        </el-form-item>
      </el-form>
      <div class="drawerFooter">
        <el-button @click="payDrawer = false">取消</el-button>
        <el-button type="primary" :loading="btnLoading" @click="handelPaySubmit"
          >保存数据</el-button
        >
      </div>
    </div>
  </el-drawer>
  <!-- 修改业务 => 抽屉 -->
  <el-drawer
    size="45%"
    v-model="editDrawer"
    title="确认修改"
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
        <el-form-item label="供应商名称" :label-width="labelWidth">
          <!-- 调用选择框组件 -->
          <ChooseSelect
            ref="EditSupplierSelect"
            :options="supplierSelect"
            des="请选择供应商"
            @update:cid="handelSupplierSelect"
          ></ChooseSelect>
        </el-form-item>
        <el-form-item label="采购订单" :label-width="labelWidth">
          <!-- 调用选择框组件 -->
          <ChooseSelect
            :options="PurOrder"
            des="请选择供应商采购订单"
          ></ChooseSelect>
        </el-form-item>
        <el-form-item label="总金额" :label-width="labelWidth">
          <el-input v-model="payForm.TotalAmount" disabled placeholder="" />
        </el-form-item>
        <el-form-item label="去零金额" :label-width="labelWidth">
          <el-input v-model="payForm.ZeroAmount" disabled placeholder="" />
        </el-form-item>
        <el-form-item label="已付金额" :label-width="labelWidth">
          <el-input v-model="payForm.amountPaid" disabled placeholder="" />
        </el-form-item>
        <el-form-item label="已收发票金额" :label-width="labelWidth">
          <el-input v-model="payForm.invoiceAmount" disabled placeholder="" />
        </el-form-item>
        <el-form-item label="付款日期" :label-width="labelWidth">
          <el-date-picker
            v-model="payForm.PlanPaymentDate"
            type="date"
            placeholder="选择计划付款日期"
            :size="size"
          />
        </el-form-item>
        <el-form-item label="期次" :label-width="labelWidth" prop="period">
          <el-input v-model="payForm.period" autocomplete="off" />
        </el-form-item>
        <el-form-item label="金额" :label-width="labelWidth" prop="amount">
          <el-input v-model="payForm.amount" autocomplete="off" />
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
import BaseDataList from '../components/BaseTable.vue'
import BulkOPe from '@/components/BulkOpe/BulkOPe.vue'
import DropDown from '@/components/DropDown/DropDown.vue'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'
import { onMounted, ref } from 'vue'
import { CreditCard, Plus, Search } from '@element-plus/icons-vue'
// 导入公共接口 => 获取银行下拉菜单接口方法
// import { getBankAccountList } from '@/apis/publicInterface.js'
// 导入 资金管理/资金抽取注入 仓库
import useFundInjectionStore from '@/stores/fundManagement/fundInjection.js'
const fundInjection = useFundInjectionStore()
onMounted(() => {
  // getBankAccountList()
  console.log('仓库的数据', fundInjection.bankSelectList)
})
// ref数据绑定BaseDataList这个组件
const baseDataListRef = ref(null)
// 表格数据传递
const sendData = {
  tableColumnAttribute: [
    {
      prop: 'supplierName',
      label: '供应商名称',
      sortable: true
    },
    {
      prop: 'procurementCon',
      label: '采购合同'
    },
    {
      prop: 'schTime',
      label: '计划时间',
      sortable: true
    },
    {
      prop: 'period',
      label: '期次'
    },
    {
      prop: 'amount',
      label: '金额'
    },
    {
      prop: 'founder',
      label: '创建人'
    },
    {
      prop: 'createTime',
      label: '创建时间'
    },
    {
      prop: 'isPay',
      label: '是否付款',
      useTag: true
    }
  ],
  tableData: [
    {
      supplierName: '山西太原',
      procurementCon: '合同1',
      schTime: '2023/10-24',
      period: 1,
      amount: '2121',
      founder: '小王',
      createTime: '2023/10-24',
      isPay: { value: '已付款', tagType: 'success' }
    },
    {
      supplierName: '山西太原',
      procurementCon: '合同2',
      schTime: '2023/10-24',
      period: 2,
      amount: '2121',
      founder: '小李',
      createTime: '2023/10-24',
      isPay: { value: '未付款', tagType: 'warning' }
    },
    {
      supplierName: '山西太原',
      procurementCon: '合同1',
      schTime: '2023/10-24',
      period: 1,
      amount: '2121',
      founder: '小王',
      createTime: '2023/10-24',
      isPay: { value: '已付款', tagType: 'success' }
    },
    {
      supplierName: '山西太原',
      procurementCon: '合同1',
      schTime: '2023/10-24',
      period: 1,
      amount: '2121',
      founder: '小王',
      createTime: '2023/10-24',
      isPay: { value: '已付款', tagType: 'success' }
    },
    {
      supplierName: '山西太原',
      procurementCon: '合同2',
      schTime: '2023/10-24',
      period: 2,
      amount: '2121',
      founder: '小李',
      createTime: '2023/10-24',
      isPay: { value: '未付款', tagType: 'warning' }
    }
  ],
  handleEdit: (row) => {
    console.log('编辑', row)
  },
  // 分页数组
  pageSizes: [5, 10, 15],
  total: 100
}

// 操作菜单的数据和处理函数
const dropdownMenuActionsInfo = ref([
  {
    command: '付款',
    handleAction: (row) => {
      console.log('付款回调函数', row)
      if (row.isPay.value === '已付款') {
        ElMessage({
          message: '没有权限执行此操作',
          type: 'warning'
        })
        return false
      }
      // 回显数据
      payForm.value.TotalAmount = row.amount
      payForm.value.period = row.period
      setTimeout(() => {
        PaySupplierSelect.value.setSelect(row.supplierName)
        // console.log(PaySupplierSelect.value)
      })
      payDrawer.value = true
    },
    actionName: '付款'
  },
  {
    command: '修改',
    // row为当前行的数据
    handleAction: (row) => {
      // editDrawer.value = true
      console.log('修改回调函数', row)
      if (row.isPay.value === '已付款') {
        ElMessage({
          message: '没有权限执行此操作',
          type: 'warning'
        })
        return false
      }
      // 回显数据
      payForm.value.TotalAmount = row.amount
      payForm.value.period = row.period
      setTimeout(() => {
        EditSupplierSelect.value.setSelect(row.supplierName)
      })
      editDrawer.value = true
      // 需要发请求获取没有的数据
    },
    actionName: '修改'
  },
  {
    command: '删除',
    // row为当前行的数据
    handleAction: (row) => {
      isDelete.value = true
      console.log('删除回调函数', row)
    },
    actionName: '删除'
  }
])

// 搜索业务
// 三个下拉选择框的数据
// const optionsFir = ref([
//   {
//     value: 'Option1',
//     label: '所有回款账户'
//   },
//   {
//     value: 'Option2',
//     label: '工商银行982731237861283'
//   },
//   {
//     value: 'Option3',
//     label: '农业银行982731237861283'
//   }
// ])
const optionsSec = ref([
  {
    value: 'Option1',
    label: '产生日期所有'
  },
  {
    value: 'Option2',
    label: '最近三天'
  },
  {
    value: 'Option3',
    label: '最近一周'
  },
  {
    value: 'Option3',
    label: '最近半月'
  },
  {
    value: 'Option3',
    label: '最近一月'
  },
  {
    value: 'Option3',
    label: '最近三月'
  },
  {
    value: 'Option3',
    label: '最近六月'
  }
])
const optionsThi = ref([
  {
    value: 'Option1',
    label: '产生日期所有'
  },
  {
    value: 'Option2',
    label: '最近三天'
  },
  {
    value: 'Option3',
    label: '最近一周'
  },
  {
    value: 'Option3',
    label: '最近半月'
  },
  {
    value: 'Option3',
    label: '最近一月'
  },
  {
    value: 'Option3',
    label: '最近三月'
  },
  {
    value: 'Option3',
    label: '最近六月'
  }
])
// 菜单筛选 => 全部/已付/未付
// const activeIndex = ref('1')
const buttons = ref([
  { type: 'primary', text: '全部' },
  { type: '', text: '已付' },
  { type: '', text: '未付' }
])
// 处理按钮的搜索
const handelBtnSearch = (btnObj) => {
  // 给当前的标签添加选中样式效果
  buttons.value.forEach((item) => {
    // console.log(item)
    item.type = ''
  })
  btnObj.type = 'primary'
  console.log(btnObj)
  // 在这里处理按钮切换的搜索请求
}

// 输入框绑定的数据
const searchKey = ref('')
// 搜索方法
const handelSearch = () => {
  if (searchKey.value === '') {
    ElMessage('搜索关键词不能为空')
    return false
  }
  // btnLoading.value = true
  setTimeout(() => {
    // btnLoading.value = false
    ElMessage({
      message: '搜索执行!调接口发请求',
      type: 'success'
    })
  }, 1000)
}
const handleSearch = () => {
  // 后期处理这个搜索方法
}

// 添加业务
const addDrawer = ref(false)
// 抽屉表单数据
const addForm = ref({
  // 总金额
  TotalAmount: '',
  // 去零金额
  ZeroAmount: '',
  //已付金额
  amountPaid: '',
  // 已收发票金额
  invoiceAmount: '',
  // 计划付款日期
  PlanPaymentDate: '',
  // 期次
  period: '',
  // 金额
  amount: ''
})
// 供应商名称
const supplierSelect = [
  {
    value: 'option1',
    label: '山西太原'
  },
  {
    value: 'option2',
    label: '上海八达'
  },
  {
    value: 'option3',
    label: '成都零起飞网络'
  },
  {
    value: 'option4',
    label: '起飞网络'
  },
  {
    value: 'option5',
    label: '黑鲨网络'
  }
]
// 采购订单的数据
const PurOrder = ref([
  {
    value: 'option1',
    label: 'xi3'
  }
])
//表单校验规则
const formRule = ref({
  // 金额
  amount: [
    { required: true, message: '请输入金额', trigger: 'blur' },
    {
      pattern: /^[0-9]+(\.[0-9]{1,2})?$/,
      message: '小数点后1到2位数字且不能包含汉字',
      trigger: 'blur'
    }
  ],
  // 期次
  period: [
    { required: true, message: '请输入期次', trigger: 'blur' },
    {
      pattern: /^[0-9]+$/,
      message: '输入格式必须是数字',
      trigger: 'blur'
    }
  ]
})
// 日期选择器的数据
// const dateSelect = ref('')
const handelAddFn = () => {
  addDrawer.value = true
}
// ref绑定表单
const theAddForm = ref()
// 按钮提交加载的数据和方法
const btnLoading = ref(false)
const handelAddSubmit = async () => {
  // 添加表单的校验,通过了才能发送添加请求
  await theAddForm.value.validate()
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

// 删除消息提示
const isDelete = ref(false)

/**
 * 付款业务
 */
const payDrawer = ref(false)
const handelPaySubmit = () => {
  // 这里需要校验表格数据是否都选中了
  btnLoading.value = true
  // 付款方法,发请求
  setTimeout(() => {
    ElMessage({
      message: '付款成功',
      type: 'success'
    })
    btnLoading.value = false
    payDrawer.value = false
  }, 1000)
}
// 供应商名称下拉选择组件
const PaySupplierSelect = ref()
const handelSupplierSelect = (selValue) => {
  console.log(selValue.label)
}
const payForm = ref({
  // 总金额
  TotalAmount: '',
  // 去零金额
  ZeroAmount: '',
  //已付金额
  amountPaid: '',
  // 已收发票金额
  invoiceAmount: '',
  // 计划付款日期
  PlanPaymentDate: '',
  // 期次
  period: '',
  // 金额
  amount: ''
})

/**
 * 修改业务
 */
const editDrawer = ref(false)
const EditSupplierSelect = ref()
const handelEditSubmit = () => {
  // 这里需要校验表格数据是否都选中了
  btnLoading.value = true
  // 付款方法,发请求
  setTimeout(() => {
    ElMessage({
      message: '付款成功',
      type: 'success'
    })
    btnLoading.value = false
    editDrawer.value = false
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

button {
  margin: 0 6px;
}
</style>
