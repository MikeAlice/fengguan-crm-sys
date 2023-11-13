<!--
 * @Author: seven 1473008948@qq.com
 * @Date: 2023-10-26 21:58:11
 * @LastEditors: seven 1473008948@qq.com
 * @LastEditTime: 2023-10-31 12:55:00
 * @FilePath: \zero-one-crmsys\crm-frontend\src\views\sale\saleContract\SaleContract.vue
-->

<template>
  <BaseDataList
    class="card"
    :title="sendData.title"
    :msg="sendData.msg"
    :table-column-attribute="salesContractStore.tableColumnAttribute"
    :table-data="salesContractStore.tableData"
    :page-sizes="sendData.pageSizes"
    :total="salesContractStore.tableTotal"
    useDropdownMenu="true"
    :dropdownMenuActionsInfo="sendData.dropdownMenuActionsInfo"
    useOperateColumn="true"
    useCalculate="true"
    @selectFuckingChange="selectChange"
    @update-table-data="
      (pageSize, currentPage) =>
        getSalesContractList({
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
            @click="dialogVisible = true"
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
            des="有效期起始"
            :options="options"
          ></ChooseSelect>
          <ChooseSelect
            style="margin-right: 5px; width: 130px"
            :options="options"
            des="有效期结束"
          ></ChooseSelect>
          <el-input
            v-model="searchContractName"
            placeholder="输入主题关键字搜索"
            style="margin-right: 4px; width: 180px"
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
            :disabled="searchContractName ? false : true"
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

  <!-- 添加或修改销售合同信息 -->
  <el-drawer v-model="dialogVisible" :title="添加合同" size="50%">
    <el-form
      :model="newSaleContract"
      label-width="120px"
      label-position="right"
    >
      <el-form-item label="合同编号">
        <el-input
          v-model="newSaleContract.contract_no"
          placeholder="输入合同编号"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="主题">
        <el-input
          v-model="newSaleContract.title"
          placeholder="输入主题"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="客户名称">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择客户名称"
          v-model="customer_nameData"
          :options="options"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="客户联系人">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择客户联系人"
          v-model="linkman_nameData"
          :options="options"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="客户销售机会">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择客户销售机会"
          v-model="chance_nameData"
          :options="options"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="起始日期">
        <el-date-picker
          v-model="start_dateData"
          type="datetime"
          placeholder="选择合同生效开始时间"
        >
        </el-date-picker>
      </el-form-item>
      <el-form-item label="预计签订日期">
        <el-date-picker
          v-model="end_dateData"
          type="datetime"
          placeholder="选择合同生效结束时间"
        >
        </el-date-picker>
      </el-form-item>
      <el-form-item label="合同金额">
        <el-input v-model="newSaleContract.money" style="width: 500px" />
      </el-form-item>
      <el-form-item label="介绍">
        <el-input
          v-model="newSaleContract.intro"
          type="textarea"
          style="width: 650px"
        />
      </el-form-item>
      <el-form-item label="我方代表">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选我方代表"
          v-model="our_user_nameData"
          :options="options"
        ></ChooseSelect>
      </el-form-item>
    </el-form>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible = false">取消</el-button>
        <el-button type="primary" @click="saveData"> 添加 </el-button>
      </span>
    </template>
  </el-drawer>
  <!-- 录入明细的抽屉 -->
  <el-drawer v-model="dialogVisible1" title="录入明细" size="50%">
    <el-card style="width: 100%; height: auto; margin-top: 0">
      <div class="drawer2">
        <h3>合同标题：123123</h3>
        <h3>合同金额： 20232</h3>
        <h3>合同编号：22104582123</h3>
      </div>
      <div class="table_details">
        <el-table :data="details_data" table-layout="auto">
          <el-table-column
            label="商品名称/商品规格"
            prop="nameOrType"
          ></el-table-column>
          <el-table-column label="价格" prop="price"></el-table-column>
          <el-table-column label="数量" prop="numbers"></el-table-column>
          <el-table-column label="金额" prop="money"></el-table-column>
          <el-table-column label="备注" prop="info"></el-table-column>
          <el-table-column label="操作" fixed="right">
            <!-- 删除明细列表的数据  deleteData方法还需完善 -->
            <el-button type="primary" size="small" @click="deleteData"
              >删除</el-button
            >
          </el-table-column>
        </el-table>
      </div>
      <hr style="margin-top: 20px" />
      <div class="info">
        <el-button type="primary" :icon="Plus" @click="dialogVisible3 = true"
          >添加商品</el-button
        >
        <span>注意：只因你太美</span>
        <span>商品总金额：{{}}</span>
        <el-button type="primary" @click="saveDetailsData">保存数据</el-button>
      </div>
    </el-card>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible1 = false">取消</el-button>
        <el-button type="primary" @click="saveData"> 添加 </el-button>
      </span>
    </template>
  </el-drawer>
  <!-- 详情界面 -->
  <el-drawer v-model="dialogVisible2" title="合同详细" icon="Home" size="70%">
    <!-- :contract-money="salesContractStore.money"
      :zero-out-money="salesContractStore.zero_money"
      :due-money="salesContractStore.owe_money"
      :start-date="salesContractStore.start_date"
      :end-date="salesContractStore.end_date"
      :create-date="sendData.startDate"
      :our-represent="sendData.ourRepresent"
      :contract-title="salesContractStore.title"
      :contract-id="salesContractStore.contract_no"
      :tag-name="sendData.tagName"
      :tag-type="sendData.tagType"
      :first-table-data="sendData.firstTableData"
      :second-table-data="sendData.secondTableData"
      :third-table-data="sendData.thirdTableData"
      :fourth-table-data="sendData.fourthTableData"
      :purchaseContractUniqueField="sendData.purchaseContractUniqueField"
      :handle-add-attachment="sendData.handleAddAttachment" -->
    <ContractDetails
      :contract-id="item.contract_no"
      :contract-title="item.title"
      :contract-money="item.money"
      :zero-out-money="item.zero_money"
      :due-money="item.owe_money"
      :sellContractUniqueField="sellContractUniqueField"
      :start-date="item.start_date"
      :end-date="item.end_date"
      :create-date="item.create_date"
      :our-represent="item.our_represent"
    >
    </ContractDetails>
  </el-drawer>
  <!-- 添加商品 -->
  <el-drawer v-model="dialogVisible3" title="添加商品" size="80%">
    <AddGoods
      :sendData="sendGoodsData"
      :treeData="treeData"
      :addGoodsData="addGoodsData"
      ref="addGoodsRef"
    >
    </AddGoods>
  </el-drawer>
</template>

<script setup>
import ContractDetails from '@/components/DataList/ContractDetails.vue'
import BaseDataList from '@/components/DataList/BaseDataList.vue'
import BulkOPe from '@/components/BulkOpe/BulkOPe.vue'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'
import { ref, onMounted, reactive } from 'vue'
import DropDown from '@/components/DropDown/DropDown.vue'
import { SoldOut, Plus } from '@element-plus/icons-vue'
import { ElMessage } from 'element-plus'
import { useSalesContractStore } from '@/stores/salesmanager/SalesContract.js'
import AddGoods from '@/components/OrganizationStructure/AddGoods.vue'

//导入仓库
const salesContractStore = useSalesContractStore()

//添加商品的ref
const addGoodsRef = ref(null)

// 搜索的销售合同主题名称
const searchContractName = ref('')

// 搜索框的searchDetails方法还需完善
const searchDetails = async () => {
  console.log('搜索', searchContractName.value)
  // const res = await salesContractStore.tableData.
  // if (searchData.length === 0) {
  //   ElMessage({
  //     type: 'warning',
  //     message: '未找到相关数据，请重新输入合同主题'
  //   })
  // } else {
  //   salesContractStore.tableData = searchData
  // }
}

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

const sellContractUniqueField = ref({
  refundMoney: '',
  sellerNote: '',
  customerName: '',
  customerRepresent: ''
})

// 控制抽屉的显示与否
const dialogVisible = ref(false)

// const resetData = () => {
//   console.log('抽屉的值', dialogVisible.value)
//   dialogVisible.value = false
//   newSaleContract.value = salesContractStore.resetNewSalesContract.value
//   console.log('重置数据', newSaleContract.value)
// }

//添加销售合同

const customer_nameData = ref('')
const linkman_nameData = ref('')
const chance_nameData = ref('')
const our_user_nameData = ref('')
// 假设 el-date-picker 返回的日期数据存储在 dateData 中
const start_dateData = ref('')
const end_dateData = ref('')

//解析日期的方法
const parsedate = (date) => {
  // 使用日期对象的方法获取年、月、日、小时和分钟
  const dateData = new Date(date.value)
  const year = dateData.getFullYear()
  const month = String(dateData.getMonth() + 1).padStart(2, '0') // 月份从 0 开始，需要加1，并确保两位格式
  const day = String(dateData.getDate()).padStart(2, '0') // 日
  const hours = String(dateData.getHours()).padStart(2, '0')
  const minutes = String(dateData.getMinutes()).padStart(2, '0')
  // 组合成 "yyyy-mm-dd hh:mm" 格式的日期时间字符串
  const formattedDateTime = `${year}-${month}-${day} ${hours}:${minutes}`
  return formattedDateTime
}

// 新增销售合同的数据
let newSaleContract = ref({
  contract_no: '',
  title: '',
  customer_name: '',
  linkman_name: '',
  chance_name: '',
  start_date: '',
  end_date: '',
  money: 0,
  intro: '',
  our_user_name: ''
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

const addGoodsData = () => {
  addGoodsRef.value.baseDataListRef1.rows.forEach((row) => {
    const { goodsNameOrGoodsType, salePrice, inventory, costPrice } = row
    details_data.push({
      nameOrType: 'goodsNameOrGoodsType',
      price: salePrice,
      numbers: inventory,
      money: costPrice,
      info: '备注'
    })
  })
}
// 录入明细的抽屉显示控制
let dialogVisible1 = ref(false)

// 点击保存按钮后的回调函数用来保存数据
const saveData = async () => {
  newSaleContract.value.customer_name = customer_nameData.value.label
  newSaleContract.value.linkman_name = linkman_nameData.value.label
  newSaleContract.value.chance_name = chance_nameData.value.label
  newSaleContract.value.our_user_name = our_user_nameData.value.label
  newSaleContract.value.start_date = parsedate(start_dateData)
  newSaleContract.value.end_date = parsedate(end_dateData)
  console.log('修改或者新增的合同数据：', newSaleContract.value)
  // TODO这里应该添加表单校验 确保每一项都有数据

  const res = await salesContractStore
    .addNewContract(newSaleContract.value)
    .catch(() => {
      newSaleContract.value = salesContractStore.resetNewSalesContract.value
      ElMessage.error('添加失败')
    })
  if (res.code === 10000) {
    getSalesContractList(1, 5)
    ElMessage.success('添加成功')
    // 重置数据
    newSaleContract.value = salesContractStore.resetNewSalesContract.value
  }
  dialogVisible.value = false
}

const item = ref({})

// 数据传递
const sendData = {
  title: '销售合同',
  // 操作提示的内容
  msg: '多一眼看一眼就会爆炸12313123我哈哈哈',
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
      handleAction: async (row) => {
        alert('确认删除吗')
        console.log('id', row.contract_id)
        // TODO 获取当前行的id 这里需要使用获取id的接口
        const contractData = await salesContractStore
          .getSalesContractIDList(row.contract_id)
          .catch((err) => {
            console.log('获取销售合同唯一ID失败', err)
          })
        const contractNo = contractData.data.contract_no
        console.log('当前销售合同的编号：', contractNo)
        if (contractData.code === 10000) {
          const res = await salesContractStore
            .deleteSales(contractNo)
            .catch((err) => {
              console.log(err)
            })
          if (res.code === 10000) {
            getSalesContractList(1, 5)
            ElMessage.success('删除成功')
            console.log('删除成功', salesContractStore.tableData)
          }
        }
      },
      actionName: '删除'
    },
    {
      command: 'details',
      handleAction: (row) => {
        // console.log(row.deliver_status.value)
        if (row.deliver_status.value == '需要') {
          dialogVisible1.value = 'false'
          console.log('录入明细', row)
        } else {
          ElMessage.error(
            '当前交付状态为：' + row.deliver_status.value + ',无法录入明细'
          )
        }
      },
      actionName: '录入明细'
    },
    {
      command: 'showDetails',
      handleAction: (row) => {
        dialogVisible2.value = 'true'
        item.value = {
          ...row
        }
        sellContractUniqueField.value.refundMoney = item.value.deliver_money
        console.log('1', item)
        console.log('详细界面')
      },
      actionName: '详情'
    },
    {
      command: 'noDeliveryRequired',
      handleAction: (row) => {
        if (row.deliver_status.value == '需要') {
          row.deliver_status.value = '无需交付'
          ElMessage.success('修改交付状态成功')
        }

        console.log('无需交付', row)
        // 这里还需要根据当前状态判断是否需要交付
      },
      actionName: '无需交付'
    },
    {
      command: 'deliveryRequired',
      handleAction: (row) => {
        if (row.deliver_status.value == '无需交付') {
          row.deliver_status.value = '需要'
          ElMessage.success('开启交付成功')
        }
        console.log('开启交付', row)
        // 这里还需要根据当前状态判断是否需要交付
      },
      actionName: '开启交付'
    },
    {
      command: 'showList',
      handleAction: (row) => {
        console.log('查看清单', row)
        // 这里还需要根据当前状态判断是否需要交付
      },
      actionName: '查看清单'
    },
    {
      command: 'createOutboundOrder',
      handleAction: (row) => {
        if (row.deliver_status.value == '待出库') {
          ElMessage.success('生成出库单成功')
        } else {
          ElMessage.error(
            '当前交付状态为:' + row.deliver_status.value + ',无法生成出库单'
          )
        }

        console.log('生成出库单', row)

        // 这里还需要根据当前状态判断是否需要交付
      },
      actionName: '生成出库单'
    }
  ],
  // 分页数组
  pageSizes: [5, 10, 15],
  total: 100
}

//
const getSalesContractList = async (params) => {
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
  console.log('获取到的数据111', baseDataListRef.value)
  await salesContractStore.getTableData(params)
  baseDataListRef.value.openLoading = !baseDataListRef.value.openLoading
}
// 挂载时获得分页数据addTrackRecords
onMounted(() => {
  getSalesContractList(1, 5)
  console.log('分页列表数据', salesContractStore.getTableData)
})

// 录入明细的抽屉里的数据
const details_data = reactive([
  {
    nameOrType: '123',
    price: 2323,
    numbers: 123,
    money: 23032,
    info: '备注'
  }
])
// 处理录入明细里表格删除请求
const deleteData = (row) => {
  console.log('删除所选明细列表的数据', row)
}

// 处理录入明细抽屉的保存操作
const saveDetailsData = () => {
  ElMessage('保存录入明细成功')
}

// 处理添加商品的抽屉显示
let dialogVisible2 = ref(false)

// 添加商品的组合数据
const goodsNameOrGoodsType = {
  goodsName: '无双剑姬',
  goodsType: 'TheShy'
}
// 添加商品的假数据
let sendGoodsData = {
  tableColumnAttribute: [
    {
      prop: 'goodsNameOrGoodsType',
      label: '商品名称/商品规格',
      sortable: false
    },
    {
      prop: 'salePrice',
      label: '销售价格',
      sortable: true
    },
    {
      prop: 'marketPrice',
      label: '市场价格',
      sortable: true
    },
    {
      prop: 'costPrice',
      label: '成本价格',
      sortable: true
    },
    {
      prop: 'inventory',
      label: '库存',
      sortable: true
    },
    {
      prop: 'code',
      label: '商品编码'
    }
  ],
  tableData: [
    {
      goodsNameOrGoodsType: `商品名：${goodsNameOrGoodsType.goodsName} \n 商品类型：${goodsNameOrGoodsType.goodsType}`,
      salePrice: 230,
      marketPrice: 240,
      costPrice: 120,
      inventory: 10,
      code: '123123123'
    },
    {
      goodsNameOrGoodsType: `商品名：${goodsNameOrGoodsType.goodsName} \n 商品类型：${goodsNameOrGoodsType.goodsType}`,
      salePrice: 230,
      marketPrice: 240,
      costPrice: 120,
      inventory: 10,
      code: '123123123'
    },
    {
      goodsNameOrGoodsType: `商品名：${goodsNameOrGoodsType.goodsName} \n 商品类型：${goodsNameOrGoodsType.goodsType}`,
      salePrice: 230,
      marketPrice: 240,
      costPrice: 120,
      inventory: 10,
      code: '123123123'
    },
    {
      goodsNameOrGoodsType: `商品名：${goodsNameOrGoodsType.goodsName} \n 商品类型：${goodsNameOrGoodsType.goodsType}`,
      salePrice: 230,
      marketPrice: 240,
      costPrice: 120,
      inventory: 10,
      code: '123123123'
    }
  ],
  // 传入删除操作的函数就会显示删除按钮
  handleDelete: (row) => {
    console.log('删除', row)
  },
  handleEdit: (row) => {
    console.log('编辑', row)
  },
  pageSizes: [2, 10, 15, 200],
  total: 100,
  usePagination: true
}

const treeData = {
  treeArr: [
    {
      label: 'Level one 1',
      children: [
        {
          label: 'Level two 1-1',
          children: [
            {
              label: 'Level three 1-1-1'
            }
          ]
        }
      ]
    },
    {
      label: 'Level one 2',
      children: [
        {
          label: 'Level two 2-1',
          children: [
            {
              label: 'Level three 2-1-1'
            }
          ]
        },
        {
          label: 'Level two 2-2',
          children: [
            {
              label: 'Level three 2-2-1'
            }
          ]
        }
      ]
    },
    {
      label: 'Level one 3',
      children: [
        {
          label: 'Level two 3-1',
          children: [
            {
              label: 'Level three 3-1-1'
            }
          ]
        },
        {
          label: 'Level two 3-2',
          children: [
            {
              label: 'Level three 3-2-1'
            }
          ]
        }
      ]
    }
  ],

  defaultProps: {
    children: 'children',
    label: 'label'
  }
}

// 处理请求提交的方法 修改数据
const handleCommand = (command, row) => {
  const item = sendData.dropdownMenuActionsInfo.find((item) => {
    return item.command === command
  })
  item.handleAction(row)
}

// 录入明细界面点击添加商品控制抽屉显示与否
let dialogVisible3 = ref(false)

const baseDataListRef = ref()
//分页器组件点击调用get
const paginationData = ref({
  currentPage: 1,
  pageSize: sendData.pageSizes ? sendData.pageSizes[0] : 5
})

const getRows = () => {
  // 获取组件暴露出来的rows
  console.log('rows', baseDataListRef.value.rows)
}
// 处理选择的行是否发生变化
// const handleSelectionChange = (newRows) => {
//   baseDataListRef.value.rows = newRows
// }
// 开启/关闭表格加载动画 这里要刷新数据的，每次刷新数据要获取表格数据
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
