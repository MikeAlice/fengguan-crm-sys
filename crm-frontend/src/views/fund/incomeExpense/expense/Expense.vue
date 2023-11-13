<!--
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-10-28 14:38:07
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-06 10:54:09
 * @FilePath: \zero-one-crmsys\crm-frontend\src\views\fund\injectionExtraction\InjectionExtraction.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <!-- <div>费用支出单</div> -->
  <BaseDataList
    title="费用支出单"
    msg="这里是操作提示"
    ref="baseDataListRef"
    :table-column-attribute="sendData.tableColumnAttribute"
    :table-data="sendData.tableData"
    :page-sizes="sendData.pageSizes"
    :total="sendData.total"
    :dropdownMenuActionsInfo="dropdownMenuActionsInfo"
    :handleDelete="handleDelete"
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
          <el-button type="danger" icon="IconDelete">批量删除</el-button>
        </div>
        <div class="search">
          <ChooseSelect
            :options="fundInjection.bankSelectList"
            des="所有回款账户"
          ></ChooseSelect>
          <ChooseSelect :options="optionsSec" des="产生日期所有"></ChooseSelect>
          <ChooseSelect :options="optionsThi" des="创建日期所有"></ChooseSelect>
          <el-input
            placeholder="请输入关键字搜索"
            v-model="searchKey"
            style="width: 150px"
          ></el-input>
          <DropDown
            :inputValue1="tel"
            inputTitle1="金额"
            :getDropDown="
              () => {
                return [0, 3]
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
    <template #statistics>
      <p>
        金额合计:
        <span class="money">{{ 75600.0 }} 元</span>
      </p>
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
    title="添加资金注入抽取"
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
        <el-form-item label="选择分类" :label-width="labelWidth">
          <!-- 调用选择框组件 -->
          <ChooseSelect :options="optionType" des="请选择分类"></ChooseSelect>
        </el-form-item>
        <el-form-item label="产生日期" :label-width="labelWidth">
          <el-date-picker
            v-model="dateSelect"
            type="date"
            placeholder="请选择一个日期"
            :size="size"
          />
        </el-form-item>
        <el-form-item label="金额" :label-width="labelWidth" prop="money">
          <el-input v-model="addForm.money" autocomplete="off" />
        </el-form-item>
        <el-form-item label="付款账户" :label-width="labelWidth">
          <!-- 调用选择框组件 -->
          <ChooseSelect
            :options="fundInjection.bankSelectList"
            des="选择银行账户"
          ></ChooseSelect>
        </el-form-item>
        <el-form-item label="备注" :label-width="labelWidth">
          <el-input v-model="addForm.desc" type="textarea" />
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
</template>

<script setup>
import BaseDataList from '@/components/DataList/BaseDataList.vue'
// import BulkOPe from '@/components/BulkOPe/BulkOPe.vue'
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
      prop: 'oddNum',
      label: '单号',
      sortable: false
    },
    {
      prop: 'ExpenseType',
      label: '支出类型',
      sortable: true,
      useTag: true
    },
    {
      prop: 'money',
      label: '金额',
      sortable: true
    },
    {
      prop: 'BankAccount',
      label: '银行账号'
    },
    {
      prop: 'generateDate',
      label: '产生日期'
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
      prop: 'notes',
      label: '备注'
    }
  ],
  tableData: [
    {
      oddNum: 1231241347126,
      ExpenseType: { value: '资金抽取', tagType: 'success' },
      money: 346231,
      BankAccount: 18747368743,
      generateDate: '2023/10-24',
      founder: '小王同学',
      createTime: '2023/10/31',
      notes: ''
    },
    {
      oddNum: 1231241347126,
      ExpenseType: { value: '资金注入', tagType: 'primary' },
      money: 346231,
      BankAccount: 18747368743,
      generateDate: '2023/10-24',
      founder: '小王同学',
      createTime: '2023/10/31',
      notes: ''
    },
    {
      oddNum: 1231241347126,
      ExpenseType: { value: '资金注入', tagType: 'primary' },
      money: 346231,
      BankAccount: 18747368743,
      generateDate: '2023/10-24',
      founder: '小王同学',
      createTime: '2023/10/31',
      notes: ''
    },
    {
      oddNum: 1231241347126,
      ExpenseType: { value: '资金抽取', tagType: 'success' },
      money: 346231,
      BankAccount: 18747368743,
      generateDate: '2023/10-24',
      founder: '小王同学',
      createTime: '2023/10/31',
      notes: ''
    },
    {
      oddNum: 1231241347126,
      ExpenseType: { value: '资金抽取', tagType: 'success' },
      money: 346231,
      BankAccount: 18747368743,
      generateDate: '2023/10-24',
      founder: '小王同学',
      createTime: '2023/10/31',
      notes: ''
    }
  ],
  handleEdit: (row) => {
    console.log('编辑', row)
  },
  // 分页数组
  pageSizes: [5, 10, 15],
  total: 100
}

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
  money: '',
  date: '',
  desc: ''
})
const optionType = [
  {
    value: 'option1',
    label: '管理费用'
  },
  {
    value: 'option2',
    label: '日常开支'
  },
  {
    value: 'option3',
    label: '办公司开支'
  },
  {
    value: 'option4',
    label: '营业费用'
  }
]
//表单校验规则
const formRule = ref({
  // 金额
  money: [
    { required: true, message: '请输入金额', trigger: 'blur' },
    {
      pattern: /^[0-9]+(\.[0-9]{1,2})?$/,
      message: '小数点后1到2位数字且不能包含汉字',
      trigger: 'blur'
    }
  ]
})
// 日期选择器的数据
const dateSelect = ref('')
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

// 删除的业务
const handleDelete = (row) => {
  console.log(row, '删除业务')
  isDelete.value = true
}
// 删除消息提示
const isDelete = ref(false)
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
.money {
  color: red;
}
</style>
