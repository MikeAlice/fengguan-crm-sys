<template>
  <el-drawer v-model="dialogVisible3" title="添加服务记录" size="50%">
    <el-form
      :model="myclient.serviceInfo"
      label-width="120px"
      label-position="right"
    >
      <el-form-item label="服务类型">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择服务类型"
          :options="select.serviceType"
          @update:cid="serviceGettype()"
          ref="serviceType"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="服务方式">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择服务方式"
          :options="select.serviceWay"
          @update:cid="serviceGetWay()"
          ref="serviceWay"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="服务时间">
        <el-col :span="11">
          <el-date-picker
            v-model="myclient.serviceInfo.service_time"
            type="date"
            placeholder="服务日期"
          />
        </el-col>
      </el-form-item>
      <el-form-item label="花费时间(分钟)">
        <el-input-number v-model="myclient.serviceInfo.tlen" min="0" />
      </el-form-item>
      <el-form-item label="服务内容">
        <el-input
          v-model="myclient.serviceInfo.content"
          type="textarea"
          style="width: 650px"
        />
      </el-form-item>
      <el-form-item label="客户名称">
        <el-input
          v-model="myclient.serviceInfo.customer_name"
          style="width: 500px"
          disabled
        />
      </el-form-item>
    </el-form>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible3 = false">取消</el-button>
        <el-button type="primary" @click="saveService"> 添加 </el-button>
      </span>
    </template>
  </el-drawer>
</template>

<script setup>
import { ref } from 'vue'
import useSeasClient from '@/stores/customer/seasclient.js'
import useSelect from '@/stores/customer/select.js'
import {
  getCustomerServiceType,
  getCustomerServiceWay,
  addService
} from '@/apis/customer/index.js'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'
import { ElMessage } from 'element-plus'

// 我的客户store仓库
const myclient = useSeasClient()
// 下拉列表仓库
const select = useSelect()
/**
 * 添加服务记录
 */
// 控制添加服务记录抽屉的显示和隐藏
let dialogVisible3 = ref(false)
const serviceWay = ref()
const serviceType = ref()
// 获取服务类型下拉列表
const serviceGettype = async () => {
  await getCustomerServiceType()
  myclient.serviceInfo.services = serviceType.value.selectValue.label
}
// 获取服务方式下拉列表
const serviceGetWay = async () => {
  await getCustomerServiceWay()
  myclient.serviceInfo.servicesmodel = serviceWay.value.selectValue.label
}
// 添加服务记录按钮回调
const addServices = async (row) => {
  await getCustomerServiceType()
  await getCustomerServiceWay()
  dialogVisible3.value = true
  myclient.serviceInfo.customer_id = row.customer_id
  myclient.serviceInfo.customer_name = row.name
}
// 保存数据，发送请求
const saveService = () => {
  addService(
    myclient.serviceInfo,
    () => {
      ElMessage.success('添加成功')
    },
    () => {
      ElMessage.error('添加失败')
    }
  )
  dialogVisible3.value = false
  myclient.serviceReset()
  select.resetData()
}
defineExpose({
  addServices
})
</script>

<style lang="scss" scoped></style>
