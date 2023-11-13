<template>
  <el-drawer v-model="dialogVisible5" title="添加合同" size="50%">
    <el-form
      :model="myclient.contractInfo"
      label-width="120px"
      label-position="right"
    >
      <el-form-item label="合同编号">
        <el-input
          v-model="myclient.contractInfo.id"
          style="width: 650px"
          disabled
        />
      </el-form-item>
      <el-form-item label="标题">
        <el-input v-model="myclient.contractInfo.title" style="width: 650px" />
      </el-form-item>
      <el-form-item label="客户名称">
        <el-input v-model="customerName" style="width: 500px" disabled />
      </el-form-item>
      <el-form-item label="客户联系人">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择客户联系人"
          :options="select.contacts"
          @update:cid="contractGetContacts()"
          ref="customerContacts2"
          :disabled="myclient.contractInfo.name ? false : true"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="客户销售机会">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择客户销售机会"
          :options="select.opportnity"
          @update:cid="contractGetOpportunity()"
          ref="customerOpportunity1"
          :disabled="myclient.contractInfo.name ? false : true"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="起始日期">
        <el-col :span="11">
          <el-date-picker
            v-model="myclient.contractInfo.data"
            type="date"
            placeholder="选择起始日期"
          />
        </el-col>
      </el-form-item>
      <el-form-item label="结束日期">
        <el-col :span="11">
          <el-date-picker
            v-model="myclient.contractInfo.endData"
            type="date"
            placeholder="选择结束日期"
          />
        </el-col>
      </el-form-item>
      <el-form-item label="合同金额(元)">
        <el-input
          v-model="myclient.contractInfo.price"
          placeholder="预定签单金额"
        />
      </el-form-item>
      <el-form-item label="介绍">
        <el-input
          v-model="myclient.contractInfo.intro"
          type="textarea"
          style="width: 650px"
        />
      </el-form-item>
      <el-form-item label="我方代表">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择我方代表"
          :options="select.represent"
          @update:cid="contractGetRepresent()"
          ref="myRepresent"
        ></ChooseSelect>
      </el-form-item>
    </el-form>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible5 = false">取消</el-button>
        <el-button type="primary" @click="saveContract"> 添加 </el-button>
      </span>
    </template>
  </el-drawer>
</template>

<script setup>
import { ref } from 'vue'
import useMyClient from '@/stores/customer/myclient.js'
import useSelect from '@/stores/customer/select.js'
import {
  getCustomerConcats,
  getCustomerOpportnity,
  getCustomerRepresent
} from '@/apis/customer/index.js'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'

// 我的客户store仓库
const myclient = useMyClient()
// 下拉列表仓库
const select = useSelect()

/**
 * 添加合同
 */
// 控制添加合同抽屉的显示和隐藏
let dialogVisible5 = ref(false)
const customerContacts2 = ref()
const customerOpportunity1 = ref()
const myRepresent = ref()
// 获取客户联系人下拉列表
const contractGetContacts = async () => {
  await getCustomerConcats()
  myclient.contractInfo.contact = customerContacts2.value.selectValue.label
}
// 获取客户销售机会下拉列表
const contractGetOpportunity = async () => {
  await getCustomerOpportnity()
  myclient.contractInfo.opportnity =
    customerOpportunity1.value.selectValue.label
}
// 获取我方代表下拉列表
const contractGetRepresent = async () => {
  await getCustomerRepresent()
  myclient.contractInfo.represent = myRepresent.value.selectValue.label
}
const customerName = ref()
// 添加合同按钮回调
const addContract = async (row) => {
  await getCustomerConcats()
  await getCustomerOpportnity()
  await getCustomerRepresent()
  dialogVisible5.value = true
  myclient.contractInfo.id = row.id
  customerName.value
}
// 根据已保存的数据，发送请求
const saveContract = () => {
  dialogVisible5.value = false

  myclient.contractReset()
  select.resetData()
  ElMessage.success('添加成功')
}

defineExpose({
  addContract
})
</script>

<style lang="scss" scoped></style>
