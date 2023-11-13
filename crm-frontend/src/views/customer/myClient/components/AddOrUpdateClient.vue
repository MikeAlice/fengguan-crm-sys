<template>
  <!-- 添加或修改客户信息 -->
  <el-drawer
    v-model="dialogVisible"
    :title="
      myclient.customerInfo.customer_id === '' ? '添加客户信息' : '修改客户信息'
    "
    size="50%"
    @close="close"
  >
    <el-form
      :model="myclient.customerInfo"
      label-width="120px"
      label-position="right"
      :rules="rules"
    >
      <el-form-item label="客户名称" prop="name">
        <el-input
          v-model="myclient.customerInfo.name"
          placeholder="请输入客户名称"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="客户来源" prop="belong">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择客户来源"
          :options="select.belong"
          @update:cid="customerGetBelong"
          ref="belong"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="客户等级" prop="level">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择客户等级"
          :options="select.level"
          @update:cid="customerGetLevel"
          ref="level"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="客户行业" prop="induty">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择客户行业"
          :options="select.industy"
          @update:cid="customerGetIndusty"
          ref="industry"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="联系手机" prop="mobile">
        <el-input v-model="myclient.customerInfo.tel" style="width: 500px" />
      </el-form-item>
      <el-form-item label="联系电话">
        <el-input v-model="myclient.customerInfo.mobile" style="width: 500px" />
      </el-form-item>
      <el-form-item label="联系地址">
        <el-input
          v-model="myclient.customerInfo.address"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="客户介绍">
        <el-input
          v-model="myclient.customerInfo.intro"
          type="textarea"
          style="width: 650px"
        />
      </el-form-item>
      <el-form-item label="客户需求" prop="needs">
        <el-input v-model="myclient.customerInfo.needs" style="width: 500px" />
      </el-form-item>
      <el-form-item label="公海客户" v-if="!flag">
        <el-checkbox-group v-model="myclient.customerInfo.seaCustomer">
          <el-checkbox
            name="type"
            @click="
              myclient.customerInfo.seaCustomer =
                !myclient.customerInfo.seaCustomer
            "
        /></el-checkbox-group>
      </el-form-item>
    </el-form>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible = false">取消</el-button>
        <el-button type="primary" @click="save"> 确定 </el-button>
      </span>
    </template>
  </el-drawer>
</template>

<script setup>
import { ref, inject } from 'vue'
import useMyClient from '@/stores/customer/myclient.js'
import useSelect from '@/stores/customer/select.js'
import {
  getCustomerBelong,
  getCustomerLevel,
  getCustomerIndusty,
  postCustomer,
  putCustomer,
  queryCustomerDetails
} from '@/apis/customer/index.js'

import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'

// 我的客户store仓库
const myclient = useMyClient()
// 下拉列表仓库
const select = useSelect()

/**
 * 添加
 */
// 控制添加或修改客户信息对话框的显示与隐藏
let dialogVisible = ref(false)
const belong = ref()
const level = ref()
const industry = ref()
// 获取客户归属的值
const customerGetBelong = async () => {
  await getCustomerBelong()
  myclient.customerInfo.source = belong.value.selectValue.label
}
// 获取客户等级的值
const customerGetLevel = async () => {
  await getCustomerLevel()
  myclient.customerInfo.grade = level.value.selectValue.label
}
//获取客户行业的值
const customerGetIndusty = async () => {
  await getCustomerIndusty()
  myclient.customerInfo.industry = industry.value.selectValue.label
}
const getSelect = async () => {
  await getCustomerBelong()
  await getCustomerLevel()
  await getCustomerIndusty()
}
// 点击添加按钮的回调
const addMyClinet = () => {
  getSelect()
  dialogVisible.value = true
}
const inits = inject('inits')
// 添加或修改客户按钮确定回调
const save = () => {
  dialogVisible.value = false
  if (myclient.customerInfo.customer_id === '') {
    postCustomer(
      myclient.customerInfo,
      () => {
        ElMessage.success('添加成功')
        inits()
      },
      () => {
        ElMessage.error('添加失败')
      }
    )
  } else {
    putCustomer(
      myclient.customerInfo,
      () => {
        ElMessage.success('修改成功')
        inits()
      },
      () => {
        ElMessage.error('修改失败')
      }
    )
  }
  myclient.customerReset()
  select.resetData()
  belong.value.reset()
  level.value.reset()
  industry.value.reset()
}
/**
 * 修改
 */
// 修改按钮回调
const modify = (row) => {
  flag.value = true
  getSelect()
  queryCustomerDetails(
    row.customer_id,
    (response) => {
      myclient.customerInfo = {
        customer_id: row.customer_id,
        ...response.data
      }
      belong.value.setVal(myclient.customerInfo.source)
      level.value.setVal(myclient.customerInfo.grade)
      industry.value.setVal(myclient.customerInfo.industry)
    },
    () => {
      ElMessage.error('获取数据失败')
    }
  )
  myclient.customerInfo.customer_id = row.customer_id
  dialogVisible.value = true
}

const flag = ref(false)
const close = () => {
  if (flag.value) {
    myclient.customerReset()
    belong.value.reset()
    level.value.reset()
    industry.value.reset()
    flag.value = false
  }
}

const rules = ref({
  name: [{ required: true, message: '姓名不能为空', trigger: 'blur' }],
  belong: [{ required: true, message: '客户来源不能为空', trigger: 'blur' }],
  level: [{ required: true, message: '客户等级不能为空', trigger: 'blur' }],
  induty: [{ required: true, message: '客户行业不能为空', trigger: 'blur' }],
  mobile: [{ required: true, message: '手机号不能为空', trigger: 'blur' }],
  needs: [{ required: true, message: '邮箱不能为空', trigger: 'blur' }]
})

defineExpose({
  addMyClinet,
  modify
})
</script>

<style lang="scss" scoped>
.dialog-footer {
  display: flex;
  justify-content: space-around;
}
</style>
