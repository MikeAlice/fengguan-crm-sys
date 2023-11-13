<!--
 * @Author: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @Date: 2023-10-28 14:38:07
 * @LastEditors: 暮秋pro oncwnuDcKAa9aHtUN1_rnIGw84kY@git.weixin.qq.com
 * @LastEditTime: 2023-11-08 20:10:03
 * @FilePath: \zero-one-crmsys\crm-frontend\src\views\fund\injectionExtraction\InjectionExtraction.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<template>
  <!-- <div>资金注入抽取</div> -->
  <BaseDataList
    title="资金注入抽取"
    msg="这里是操作提示"
    ref="baseDataListRef"
    :table-column-attribute="sendData.tableColumnAttribute"
    :table-data="sendData.tableData"
    :page-sizes="sendData.pageSizes"
    :total="sendData.total"
    :dropdownMenuActionsInfo="dropdownMenuActionsInfo"
    :handleDelete="handleDelete"
    @updateTableData="handleSizeChange"
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
          <BulkOPe
            :excelData="excel"
            :getOpt="() => [0]"
            path="/file/upload"
            baseURL="http://localhost:8090"
          >
            <template #excel> </template>
            <template #file> </template>
            <template #print> </template>
          </BulkOPe>
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
            inputTitle1="搜索金额"
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
  </BaseDataList>
  <el-dialog v-model="isDelete" title="温馨提示" width="30%">
    <span>你确认要删除吗?</span>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="isDelete = false">取消</el-button>
        <el-button type="primary" @click="handelDeleteSample"> 确认 </el-button>
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
        <el-form-item label="操作类型" :label-width="labelWidth">
          <!-- 调用选择框组件 -->
          <ChooseSelect
            ref="addSelectType"
            :options="optionType"
            des="选择操作类型"
          ></ChooseSelect>
        </el-form-item>
        <el-form-item label="银行账户" :label-width="labelWidth">
          <!-- 调用选择框组件 -->
          <ChooseSelect
            ref="bankSelect"
            :options="fundInjection.bankSelectList"
            des="选择银行账户"
          ></ChooseSelect>
        </el-form-item>
        <el-form-item label="金额" :label-width="labelWidth" prop="money">
          <el-input v-model="addForm.money" autocomplete="off" />
        </el-form-item>
        <el-form-item label="产生日期" :label-width="labelWidth">
          <el-date-picker
            v-model="dateSelect"
            type="date"
            placeholder="请选择一个日期"
            :size="size"
            @change="handelDateChange"
          />
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
import BulkOPe from '@/components/BulkOpe/BulkOPe.vue'
import DropDown from '@/components/DropDown/DropDown.vue'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'
import { onMounted, ref } from 'vue'
import { CreditCard, Plus, Search } from '@element-plus/icons-vue'
import { getBankaccountlist } from '../../../apis/publicInterface'
import {
  addFundInjectionApi,
  deleteFundInjectionApi
} from '../../../apis/fund/InjectionExtraction/InjectionExtraction'
// 导入 资金管理/资金抽取注入 仓库
import useFundInjectionStore from '@/stores/fundManagement/fundInjection.js'
const fundInjection = useFundInjectionStore()

// 获取分页数据
const $page = ref()
setTimeout(() => {
  $page.value = baseDataListRef.value.paginationData
  console.log('当前分页器数据', $page.value)
})
console.log('当前分页器数据', $page)
onMounted(async () => {
  // console.log('仓库的数据', fundInjection.bankSelectList)

  //获取数据列表 (分页+条件)
  const result = await fundInjection.getFundStoreApi({
    pageIndex: baseDataListRef.value.paginationData.currentPage,
    pageSize: baseDataListRef.value.paginationData.pageSize
  })
  const { data } = result.value
  console.log('获取结构', data)

  // 矫正标签数据
  let rows = data.rows
  console.log(rows)
  const newRows = rows.map((item) => {
    let obj = { value: '', tagType: '' }
    for (let key in item) {
      if (key === 'type') {
        if (item[key] === '') {
          item[key] = '资金抽取'
        }
        if (item[key] === '资金注入') {
          obj.tagType = 'success'
        } else {
          obj.tagType = 'primary'
        }
        obj.value = item[key]

        item[key] = obj
      }
    }
    return item
  })
  // console.log('矫正后的数据:', newRows)
  // 矫正银行账号
  const theNewRows = newRows.map((item) => {
    item.newBank = `${item.bank}\n${item.bank_id}`
    return item
  })
  // 渲染表格
  sendData.value.total = data.total
  sendData.value.tableData = theNewRows

  /**
   * 获取银行账户列表数据(下拉列表)
   */
  await getBankaccountlist(
    (res) => {
      const { data } = res
      console.log('获取银行账户列表数据', res)
      // 数据存到 资金管理/资金抽取注入 仓库
      // 矫正数据
      const newArr = data.map((item) => {
        // 修改字段 id=>value name=>label
        const obj = { value: '', label: '', card: '' }
        obj.value = item.bank_id
        obj.label = item.name
        obj.card = item.card
        return obj
      })
      console.log(newArr)
      fundInjection.setBankSelectList(newArr)
    },
    (error) => {
      console.log(error)
    }
  )
})

// ref数据绑定BaseDataList这个组件
const baseDataListRef = ref(null)
// 表格数据传递
const sendData = ref({
  tableColumnAttribute: [
    {
      prop: 'record_id',
      label: '单号',
      sortable: false
    },
    {
      prop: 'type',
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
      prop: 'newBank',
      label: '银行账号'
    },
    {
      prop: 'happen_date',
      label: '产生日期'
    },
    {
      prop: 'create_user',
      label: '创建人'
    },
    {
      prop: 'create_time',
      label: '创建时间'
    },
    {
      prop: 'intro',
      label: '备注'
    }
  ],
  tableData: [
    {
      record_id: 1231241347126,
      type: { value: '资金抽取', tagType: 'success' },
      money: 346231,
      newBank: 18747368743,
      happen_date: '2023/10-24',
      create_user: '小王同学',
      create_time: '2023/10/31',
      intro: ''
    }
  ],
  handleEdit: (row) => {
    console.log('编辑', row)
  },
  // 分页数组
  pageSizes: [5, 10, 15],
  total: 100
})

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
    label: '资金抽取'
  },
  {
    value: 'option2',
    label: '资金注入'
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
const handelDateChange = (selectedDate) => {
  console.log(selectedDate)
  const year = selectedDate.getFullYear()
  const month = String(selectedDate.getMonth() + 1).padStart(2, '0')
  const day = String(selectedDate.getDate()).padStart(2, '0')
  formattedDate.value = `${year}-${month}-${day}`
}
// 选中的日期数据
const formattedDate = ref()
const handelAddFn = () => {
  // 置空表单数据
  let obj = addForm.value
  for (let key in obj) {
    obj[key] = ''
  }
  setTimeout(() => {
    addSelectType.value.reset()
    bankSelect.value.reset()
    dateSelect.value = ''
    // formattedDate.value = ''
  })
  addDrawer.value = true
}
// ref绑定表单
const theAddForm = ref()
// ref 绑定操作类型下拉菜单
const addSelectType = ref()
// ref 绑定银行账户下拉菜单
const bankSelect = ref()

// 按钮提交加载的数据和方法
const btnLoading = ref(false)

const handelAddSubmit = async () => {
  // 添加表单的校验
  await theAddForm.value.validate()

  // 空值校验-操作类型
  if (addSelectType.value.selectValue === '') {
    ElMessage({
      message: '请选择操作类型',
      type: 'info'
    })
    return false
  }
  // 空值校验-银行账户
  if (bankSelect.value.selectValue === '') {
    ElMessage({
      message: '请选择银行账户',
      type: 'info'
    })
    return false
  }
  // 空值校验-日期
  if (!formattedDate.value) {
    ElMessage({
      message: '请选择日期',
      type: 'info'
    })
    return false
  }

  // 收集数据
  console.log('表格数据:', addForm.value)
  console.log('操作类型:', addSelectType.value.selectValue)
  console.log('银行账户:', bankSelect.value.selectValue)
  console.log('日期选择器:', formattedDate.value)
  // 矫正数据 操作类型 资金注入=>1 资金抽取 => -1
  const queryType = ref()
  if (addSelectType.value.selectValue.label === '资金注入') {
    queryType.value = 1
  } else {
    queryType.value = -1
  }

  btnLoading.value = true
  await addFundInjectionApi(
    {
      type_id: queryType.value,
      bank_id: bankSelect.value.selectValue.value,
      create_user_id: 0,
      money: addForm.value.money,
      happen_date: formattedDate.value,
      intro: addForm.value.desc
    },
    (res) => {
      console.log('添加成功回调', res)
      ElMessage({
        message: '添加成功',
        type: 'success'
      })
    }
  )
  btnLoading.value = false
  addDrawer.value = false
}

// 要删除的单号记录
let delData = ref()
// 删除的业务
const handleDelete = (row) => {
  console.log(row, '删除业务')
  // 置空删除的单号数组
  delData.value = row.bank_id
  isDelete.value = true
}
// 确认删除方法
const handelDeleteSample = async () => {
  console.log('要删除的单号记录', delData.value)
  // 调用删除请求
  await deleteFundInjectionApi(
    {
      record_id: delData.value
    },
    (res) => {
      console.log('删除成功回调函数:', res)
      ElMessage({
        message: '删除成功',
        type: 'success'
      })
    }
  )
  isDelete.value = false
}
// 删除消息提示
const isDelete = ref(false)

/**
 * 分页器数据改变处理函数
 */
const handleSizeChange = async (pagesize, currentPage) => {
  console.log('条数:', pagesize, '当前页', currentPage)
  // 开启表格加载

  baseDataListRef.value.openLoading = true
  //获取数据列表 (分页+条件)
  const result = await fundInjection.getFundStoreApi({
    pageIndex: currentPage,
    pageSize: pagesize
  })
  const { data } = result.value
  // 矫正标签数据
  let rows = data.rows
  console.log(rows)
  const newRows = rows.map((item) => {
    let obj = { value: '', tagType: '' }
    for (let key in item) {
      if (key === 'type') {
        if (item[key] === '') {
          item[key] = '资金抽取'
        }
        if (item[key] === '资金注入') {
          obj.tagType = 'success'
        } else {
          obj.tagType = 'primary'
        }
        obj.value = item[key]

        item[key] = obj
      }
    }
    return item
  })

  // 渲染表格
  sendData.value.total = data.total
  sendData.value.tableData = newRows
  baseDataListRef.value.openLoading = false
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
// 表格里的内容换行用
:deep(.el-table .cell) {
  white-space: pre-wrap;
}
</style>
