<template>
  <el-drawer v-model="dialogVisible4" title="添加销售机会" size="50%">
    <el-form
      :model="myclient.opportunityInfo"
      label-width="120px"
      label-position="right"
    >
      <el-form-item label="主题">
        <el-input
          v-model="myclient.opportunityInfo.theme"
          style="width: 650px"
        />
      </el-form-item>
      <el-form-item label="客户名称">
        <el-input v-model="customerName" style="width: 500px" disabled />
      </el-form-item>
      <el-form-item label="客户联系人">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择客户联系人"
          :options="select.contacts"
          @update:cid="customerGetContacts()"
          ref="customerContacts1"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="当前阶段">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择当前阶段"
          :options="select.stage"
          @update:cid="customerGetStage()"
          ref="customerStage1"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="发现日期">
        <el-col :span="11">
          <el-date-picker
            v-model="myclient.opportunityInfo.data"
            type="date"
            placeholder="选择发现日期"
          />
        </el-col>
      </el-form-item>
      <el-form-item label="预签订日期">
        <el-col :span="11">
          <el-date-picker
            v-model="myclient.opportunityInfo.preData"
            type="date"
            placeholder="选择预签订日期"
          />
        </el-col>
      </el-form-item>
      <el-form-item label="金额(元)">
        <el-input
          v-model="myclient.opportunityInfo.price"
          placeholder="预定签单金额"
        />
      </el-form-item>
      <el-form-item label="介绍">
        <el-input
          v-model="myclient.opportunityInfo.intro"
          type="textarea"
          style="width: 650px"
        />
      </el-form-item>
    </el-form>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible4 = false">取消</el-button>
        <el-button type="primary" @click="saveOpportunity"> 添加 </el-button>
      </span>
    </template>
  </el-drawer>
</template>

<script setup>
import { ref } from 'vue'
import useSeasClient from '@/stores/customer/seasclient.js'
import useSelect from '@/stores/customer/select.js'
import { getCustomerConcats, getCustomerStage } from '@/apis/customer/index.js'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'

// 我的客户store仓库
const myclient = useSeasClient()
// 下拉列表仓库
const select = useSelect()

/**
 * 添加销售机会
 */
// 控制添加销售机会抽屉的显示和隐藏
let dialogVisible4 = ref(false)
const customerContacts1 = ref()
const customerStage1 = ref()
// 获取客户联系人下拉列表
const customerGetContacts = async () => {
  await getCustomerConcats()
  myclient.opportunityInfo.contact = customerContacts1.value.selectValue.label
}
// 获取当前阶段下拉列表
const customerGetStage = async () => {
  await getCustomerStage()
  myclient.opportunityInfo.stage = customerStage1.value.selectValue.label
}
const customerName = ref()
// 添加销售机会按钮回调
const addOpportunity = async (row) => {
  await getCustomerConcats()
  await getCustomerStage()
  dialogVisible4.value = true
  myclient.opportunityInfo.id = row.custoemr_id
  customerName.value = row.name
}
// 根据已保存的数据，发送请求
const saveOpportunity = () => {
  dialogVisible4.value = false
  myclient.opportunityReset()
  select.resetData()
  ElMessage.success('添加成功')
}
defineExpose({
  addOpportunity
})
</script>

<style lang="scss" scoped></style>
