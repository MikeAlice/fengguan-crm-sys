<template>
  <el-drawer v-model="dialogVisible1" title="添加联系人" size="50%">
    <el-form
      :model="myclient.contactInfo"
      label-width="120px"
      label-position="right"
      :rules="rules"
    >
      <el-form-item label="姓名" prop="name">
        <el-input
          v-model="myclient.contactInfo.linkman_name"
          placeholder="请输入联系人姓名"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="性别" prop="gender">
        <el-radio-group v-model="myclient.contactInfo.gender">
          <el-radio label="男" />
          <el-radio label="女" />
        </el-radio-group>
      </el-form-item>
      <el-form-item label="手机" prop="mobile">
        <el-input
          v-model="myclient.contactInfo.mobile"
          placeholder="请输入联系人手机"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="职位">
        <el-input
          v-model="myclient.contactInfo.postion"
          placeholder="请输入联系人职位"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="电话">
        <el-input
          v-model="myclient.contactInfo.tel"
          placeholder="请输入联系人电话"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="QQ">
        <el-input
          v-model="myclient.contactInfo.qicq"
          placeholder="请输入联系人QQ"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="邮箱" prop="email">
        <el-input
          v-model="myclient.contactInfo.email"
          placeholder="请输入联系人邮箱"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="地址">
        <el-input
          v-model="myclient.contactInfo.address"
          placeholder="请输入联系人地址"
          style="width: 500px"
        />
      </el-form-item>
      <el-form-item label="客户名称">
        <el-input
          v-model="myclient.contactInfo.customerName"
          style="width: 500px"
          disabled
        />
      </el-form-item>
    </el-form>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible1 = false">取消</el-button>
        <el-button type="primary" @click="saveContact"> 添加 </el-button>
      </span>
    </template>
  </el-drawer>
</template>

<script setup>
import { ref } from 'vue'
import useSeasClient from '@/stores/customer/seasclient.js'
import useSelect from '@/stores/customer/select.js'
import { addNewContact } from '@/apis/customer/index.js'

// 我的客户store仓库
const myclient = useSeasClient()
// 下拉列表仓库
const select = useSelect()

/**
 * 添加联系人
 */
// 控制添加联系人抽屉的显示和隐藏
let dialogVisible1 = ref(false)
// 添加联系人按钮回调，打开抽屉
const addContact = (row) => {
  // 根据传入id获取数据
  dialogVisible1.value = true
  myclient.contactInfo.customer_id = row.customer_id
  myclient.contactInfo.customerName = row.name
}
// 添加联系人保存数据按钮回调
const saveContact = async () => {
  addNewContact(
    myclient.contactInfo,
    () => {
      ElMessage.success('添加成功')
    },
    () => {
      ElMessage.error('添加失败')
    }
  )
  dialogVisible1.value = false
  myclient.contactReset()
  select.resetData()
  //   initCustomer()
}

const rules = ref({
  name: [{ required: true, message: '姓名不能为空', trigger: 'blur' }],
  gender: [{ required: true, message: '性别不能为空', trigger: 'blur' }],
  mobile: [{ required: true, message: '手机号不能为空', trigger: 'blur' }],
  email: [{ required: true, message: '邮箱不能为空', trigger: 'blur' }]
})
defineExpose({
  addContact
})
</script>

<style lang="scss" scoped>
.dialog-footer {
  display: flex;
  justify-content: space-around;
}
</style>
