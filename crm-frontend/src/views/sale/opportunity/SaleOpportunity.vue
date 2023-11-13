<!--
 * @Author: seven 1473008948@qq.com
 * @Date: 2023-10-26 21:58:11
 * @LastEditors: seven 1473008948@qq.com
 * @LastEditTime: 2023-10-30 21:06:21
 * @FilePath: \zero-one-crmsys\crm-frontend\src\views\sale\opportunity\SaleOpportunity.vue
-->

<template>
  <BaseDataList
    class="card"
    :title="sendData.title"
    :msg="sendData.msg"
    :table-column-attribute="tableColumnAttribute"
    :table-data="salesOpportunityStore.tableData"
    :page-sizes="salesOpportunityStore.pageSize"
    :total="sendData.total"
    useDropdownMenu="true"
    :dropdownMenuActionsInfo="sendData.dropdownMenuActionsInfo"
    useOperateColumn="true"
    @update-table-data="
      (pageSize, currentPage) =>
        getSalesOpportunityList({
          pageSize,
          pageIndex: currentPage
        })
    "
    @selectFuckingChange="selectChange"
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
          <BulkOPe :excelData="getRows" :getOpt="() => [0, 2, 3, 4]">
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
            des="最近联系时间"
            :options="options"
          ></ChooseSelect>
          <ChooseSelect
            style="margin-right: 5px; width: 130px"
            :options="options"
            des="下次联系时间"
          ></ChooseSelect>
          <ChooseSelect
            style="margin-right: 5px; width: 150px"
            :options="options"
            des="请选择沟通阶段"
          ></ChooseSelect>
          <el-input
            v-model="searchOpportunityName"
            placeholder="输入商品机会名称"
            style="margin-right: 4px; width: 140px"
          />
          <!-- 搜索功能还需完善 -->
          <DropDown
            :getDropDown="() => [0, 1, 3]"
            v-model:inputVal1="inputValue1"
            v-model:inputVal2="inputValue2"
            inputTitle1="客户名称"
            inputTitle2="备注内容"
            @handle-search="handleSearch"
          ></DropDown>
          <el-button
            type="primary"
            style="margin-left: 4px"
            @click="searchDetails"
            :disabled="searchOpportunityName ? false : true"
          >
            <el-icon style="margin-right: 4px"><icon-search /></el-icon>搜索
          </el-button>
        </div>
      </div>
    </template>
    <!-- 插槽显示图标 -->
    <template #ico>
      <el-icon><SoldOut /></el-icon>
    </template>
  </BaseDataList>

  <!-- 添加或修改销售机会信息 -->
  <el-drawer
    v-model="dialogVisible"
    :title="saleOppData.id === '' ? '添加销售机会' : '修改销售机会'"
    size="50%"
  >
    <el-form :model="saleOppData" label-width="120px" label-position="right">
      <el-form-item label="主题">
        <el-input
          v-model="saleOppData.sale_name"
          placeholder="输入销售机会主题"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="客户名称">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择客户名称"
          :options="options"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="客户联系人">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择客户联系人"
          :options="options"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="当前阶段">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择当前阶段"
          :options="options"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="发现日期">
        <el-date-picker
          v-model="saleOppData.happen_date"
          type="datetime"
          placeholder="选择服务时间"
        >
        </el-date-picker>
      </el-form-item>
      <el-form-item label="预计签订日期">
        <el-date-picker
          v-model="saleOppData.end_date"
          type="datetime"
          placeholder="选择预计签订日期"
        >
        </el-date-picker>
      </el-form-item>
      <el-form-item label="金额">
        <el-input v-model="saleOppData.money" style="width: 500px" />
      </el-form-item>
      <el-form-item label="需求">
        <el-input
          v-model="saleOppData.intro"
          type="textarea"
          style="width: 650px"
        />
      </el-form-item>
    </el-form>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible = false">取消</el-button>
        <el-button type="primary" @click="saveData"> 添加 </el-button>
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
import { useSalesOpportunityStore } from '@/stores/salesmanager/salesopportunity.js'

// 导入销售机会列表的仓库
const salesOpportunityStore = useSalesOpportunityStore()

// 搜索的销售合同主题名称
const searchOpportunityName = ref('')

// 搜索框的searchDetails方法还需完善
const searchDetails = () => {
  console.log('搜索', searchOpportunityName.value)
  const searchData = salesOpportunityStore.tableData.filter((item) => {
    return item.opportunity_title === searchOpportunityName.value
  })
  if (searchData.length === 0) {
    // 设置搜索框为空
    searchOpportunityName.value = ''
    ElMessage({
      type: 'warning',
      message: '未找到相关数据，请重新输入合同主题'
    })
  } else {
    salesOpportunityStore.tableData = searchData
  }
}

const getSalesOpportunityList = async (params) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  await salesOpportunityStore.getTableData(params)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}
// 挂载时获得分页数据
onMounted(() => {
  // const params = {
  //   pageIndex: 1,
  //   pageSize: 5
  // }
  getSalesOpportunityList(1, 5)
})

// 批量删除所选列表
const selectArr = ref([])

const isDisabled = ref(true)
// // table表勾选时触发的事件
const selectChange = (length) => {
  if (length === 0) {
    // 改变按钮的状态
    isDisabled.value = true
  } else {
    selectArr.value = baseDataListRef.value.rows
    // salesOpportunityStore.tableData =
    //       salesOpportunityStore.tableData.filter((item) => {
    //         return item.chance_id !== selectArr.value.chance_id
    //       })
    console.log(selectArr.value)
    isDisabled.value = false
  }
}

// 删除成功的回调
const deleteByQuery = () => {
  ElMessage.success('删除成功')
}

// 最近联系时间的选项
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

//添加销售机会
// 新增销售机会的数据
const saleOppData = ref({
  id: '',
  sale_name: '',
  happen_date: '',
  end_date: '',
  money: '',
  intro: ''
})
// 添加按钮的回调函数
let addData = () => {
  dialogVisible.value = true
}

// 点击保存按钮后的回调函数用来保存数据
const saveData = () => {
  saleOppData.value.id = ''
  saleOppData.value.happen_date = ''
  saleOppData.value.end_date = ''
  saleOppData.value.money = ''
  saleOppData.value.intro = ''
  dialogVisible.value = false
  // 这里还需要对表单数据进行判断的 还需完善
  ElMessage.success('添加成功')
}

// 表格列表项
const tableColumnAttribute = [
  {
    prop: 'titleAndCreateDate',
    label: '销售机会主题',
    sortable: false
  },
  {
    prop: 'customer_nameAndLinkman_id',
    label: '客户姓名',
    sortable: false
  },
  {
    prop: 'find_date',
    label: '发现日期'
  },
  {
    prop: 'bill_date',
    label: '预计签单日期'
  },
  {
    prop: 'money',
    label: '金额'
  },
  {
    prop: 'sales_stage',
    label: '当前阶段'
  },
  {
    prop: 'intro',
    label: '需求'
  }
]

// 数据传递
const sendData = {
  title: '销售机会',
  msg: '多一眼看一眼就会爆炸',
  dropdownMenuActionsInfo: [
    {
      command: 'update',
      // row为当前行的数据
      handleAction: (row) => {
        dialogVisible.value = 'true'

        console.log('修改当前行的数据', row)
      },
      actionName: '修改'
    },

    // 操作列表的删除操作 还需完善
    {
      command: 'delete',
      // row为当前行的数据
      handleAction: (row) => {
        alert('确认删除吗')
        // 获取当前行的id 这里需要使用获取id的接口
        const chance_id = row.chance_id
        console.log('删除当前行数据', chance_id)
        salesOpportunityStore.tableData =
          salesOpportunityStore.tableData.filter((item) => {
            return item.chance_id !== chance_id
          })
        console.log(salesOpportunityStore.tableData)
      },
      actionName: '删除'
    }
  ],

  // 分页数组
  pageSizes: [5, 10, 15],
  total: 100
}

// 处理请求提交的方法 修改数据
const handleCommand = (command, row) => {
  const item = sendData.dropdownMenuActionsInfo.find((item) => {
    return item.command === command
  })
  item.handleAction(row)
}

const baseDataListRef = ref()

const getRows = () => {
  // 获取组件暴露出来的rows
  console.log('rows', baseDataListRef.value.rows)
}
// 开启/关闭表格加载动画
const changeLoadAnimation = () => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  setTimeout(() => {
    baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  }, 500)
}
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
</style>
