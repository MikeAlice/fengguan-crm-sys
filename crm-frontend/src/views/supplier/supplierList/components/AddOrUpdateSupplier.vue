<template>
  <el-drawer
    v-model="dialogVisible"
    :title="!flag ? '添加供应商' : '修改供应商'"
    @close="close"
    size="50%"
  >
    <el-form
      :model="supplierList.addOrUpdateSupplier"
      label-width="120px"
      label-position="right"
      :rules="rules"
    >
      <el-form-item label="供应商名称" prop="name">
        <el-input
          v-model="supplierList.addOrUpdateSupplier.name"
          placeholder="请输入供应商名称"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="经济类型" prop="ecotype">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择经济类型"
          :options="select.name"
          @update:cid="getEcoType"
          ref="ecoType"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="行业类型" prop="trade">
        <ChooseSelect
          style="margin-right: 10px; width: 250px"
          des="请选择行业类型"
          :options="select.name"
          @update:cid="getIndType"
          ref="indType"
        ></ChooseSelect>
      </el-form-item>
      <el-form-item label="联系人" prop="linkman_name">
        <el-input
          v-model="supplierList.addOrUpdateSupplier.linkman_name"
          placeholder="请输入联系人"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="电话" prop="tel">
        <el-input
          v-model="supplierList.addOrUpdateSupplier.tel"
          placeholder="请输入电话"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="传真">
        <el-input
          v-model="supplierList.addOrUpdateSupplier.fax"
          placeholder="请输入传真"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="邮箱" prop="email">
        <el-input
          v-model="supplierList.addOrUpdateSupplier.email"
          placeholder="请输入邮箱"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="地址">
        <el-input
          v-model="supplierList.addOrUpdateSupplier.address"
          placeholder="请输入地址"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="介绍">
        <el-input
          v-model="supplierList.addOrUpdateSupplier.intro"
          type="textarea"
          style="width: 500px"
        />
      </el-form-item>
    </el-form>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible = false">取消</el-button>
        <el-button type="primary" @click="save"> 添加 </el-button>
      </span>
    </template>
  </el-drawer>
</template>

<script setup>
import { ref, inject } from 'vue'
import useSelect from '@/stores/customer/select.js'
import { getCustomerName } from '@/apis/publicInterface.js'
import ChooseSelect from '@/components/chooseSelect/ChooseSelect.vue'

import useSupplierList from '@/stores/supplier/list/list.js'
import { addSupplier, modifySupplier } from '@/apis/supplier/supplierList.js'

const supplierList = useSupplierList()

const inits = inject('inits')

// 控制添加或修改客户信息对话框的显示与隐藏
let dialogVisible = ref(false)
// 下拉列表仓库
const select = useSelect()

const ecoType = ref()
const indType = ref()
const getEcoType = async () => {
  await getCustomerName()
  supplierList.addOrUpdateSupplier.ecotype = ecoType.value.selectValue.value
}
const getIndType = async () => {
  await getCustomerName()
  supplierList.addOrUpdateSupplier.trade = indType.value.selectValue.value
}
// 点击添加按钮的回调
const addMyClinet = () => {
  dialogVisible.value = true
}
// 添加按钮确定回调
const save = async () => {
  if (!flag.value) {
    await addSupplier(
      supplierList.addOrUpdateSupplier,
      () => {
        inits()
        ElMessage.success('添加成功')
      },
      () => {
        ElMessage.error('添加失败')
      }
    )
  } else {
    await modifySupplier(
      supplierList.addOrUpdateSupplier,
      () => {
        ElMessage.success('修改成功')
      },
      () => {
        ElMessage.error('修改失败')
      }
    )
  }
  supplierList.addOrUpdateSupplierReset()
  ecoType.value.reset()
  indType.value.reset()
  select.resetData()
  dialogVisible.value = false
  flag.value = false
}
const flag = ref(false)
const close = () => {
  if (flag.value) {
    supplierList.addOrUpdateSupplierReset()
    flag.value = false
  }
}
// 修改按钮回调
const modify = (row) => {
  const item = supplierList.tableData.find((item) => {
    return item.supplier_id === row.supplier_id
  })
  supplierList.addOrUpdateSupplier = item
  dialogVisible.value = true
  flag.value = true
}
const rules = {
  name: [{ required: true, message: '供应商名称不能为空', trigger: 'blur' }],
  linkman_name: [
    { required: true, message: '联系人不能为空', trigger: 'blur' }
  ],
  email: [{ required: true, message: '邮箱不能为空', trigger: 'blur' }],
  tel: [{ required: true, message: '电话不能为空', trigger: 'blur' }],
  ecotype: [{ required: true, message: '经济类型不能为空', trigger: 'blur' }],
  trade: [{ required: true, message: '行业类型不能为空', trigger: 'blur' }]
}

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
