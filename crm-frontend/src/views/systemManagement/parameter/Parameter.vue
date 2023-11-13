<!--
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-27 14:52:16
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-10-29 12:52:34
 * @FilePath: \zero-one-crmsys\crm-frontend\src\views\systemManagement\parameter\Parameter.vue
 * @Description: 
 * 
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved. 
-->
<template>
  <div class="container">
    <div class="app-container">
      <el-card>
        <div class="space-between">
          <h3>系统参数</h3>
          <div>设置</div>
        </div>
        <div class="card-box">
          <el-form :model="formData">
            <el-form-item label="系统域名"
              ><el-input v-model="formData.yuming"></el-input
            ></el-form-item>
            <el-form-item label="系统标题"
              ><el-input v-model="formData.biaoti"></el-input
            ></el-form-item>
            <el-form-item label="系统名称"
              ><el-input v-model="formData.xitongmingcheng"></el-input
            ></el-form-item>
            <el-form-item label="系统版权"
              ><el-input type="textarea" v-model="formData.banquan"></el-input
            ></el-form-item>
            <el-form-item label="公司名称"
              ><el-input v-model="formData.mingcheng"> </el-input
            ></el-form-item>
            <el-form-item label="公司简介">
              {{ formData.jianjie }}
              <Editor></Editor>
            </el-form-item>
            <el-form-item label="联系电话"
              ><el-input v-model="formData.dianhua"></el-input
            ></el-form-item>
            <el-form-item label="联系地址"
              ><el-input v-model="formData.dizhi"></el-input
            ></el-form-item>
            <div class="space-between">
              <el-button type="primary" @click="saveData">保存数据</el-button>
              <el-button type="primary" @click="handleCancel">取消</el-button>
            </div>
          </el-form>
        </div>
      </el-card>
    </div>
  </div>
</template>

<script setup>
import Editor from '@/components/Editor/index.vue'
import useSysParams from '@/stores/sysManage/params'
import { onMounted, reactive } from 'vue'
import { ElMessage } from 'element-plus'
const $store = useSysParams()

let formData = reactive({})

onMounted(() => {
  //发请求，初始化数据
  $store.init()
  //回填,深拷贝
  formData = reactive({ ...$store.getSysParams() })
})

const saveData = () => {
  console.log('saveData')
  $store.setSysParams(formData)
  ElMessage.success('保存成功')
}

const handleCancel = () => {
  console.log('cancel', formData, $store.formData)
}
</script>

<style lang="scss" scoped>
.space-between {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
</style>
