<template>
  <el-drawer v-model="dialogVisible6" title="客户详情" size="70%">
    <el-space wrap>
      <el-card class="box-card" style="width: 1000px">
        <template #header>
          <div class="card-header">
            <span>{{ detailInfo.name }}</span>
          </div>
        </template>
        <!-- 显示数据 -->
        <el-row :gutter="20">
          <el-col :span="12" class="padding-bottom-5"
            ><span style="color: #666">客户代表：&nbsp;</span
            >{{ detailInfo.represent }}</el-col
          >
          <el-col :span="12" class="padding-bottom-5"
            ><span style="color: #666">客户来源：&nbsp;</span
            >{{ detailInfo.belong }}</el-col
          >
          <el-col :span="12" class="padding-bottom-5"
            ><span style="color: #666">客户等级：&nbsp;</span
            >{{ detailInfo.level }}</el-col
          >
          <el-col :span="12" class="padding-bottom-5"
            ><span style="color: #666">客户行业：&nbsp;</span
            >{{ detailInfo.industry }}</el-col
          >
          <el-col :span="12" class="padding-bottom-5"
            ><span style="color: #666">联系电话：&nbsp;</span
            >{{ detailInfo.tel }}</el-col
          >
          <el-col :span="12" class="padding-bottom-5"
            ><span style="color: #666">联系手机：&nbsp;</span
            >{{ detailInfo.mobile }}</el-col
          >
          <el-col :span="12" class="padding-bottom-5"
            ><span style="color: #666">联系地址：&nbsp;</span
            >{{ detailInfo.address }}</el-col
          >
          <el-col :span="12" class="padding-bottom-5"
            ><span style="color: #666">客户介绍：&nbsp;</span
            >{{ detailInfo.intro }}</el-col
          >
          <el-col :span="12" class="padding-bottom-5"
            ><span style="color: #666">客户需求：&nbsp;</span
            >{{ detailInfo.demand }}</el-col
          >
        </el-row>
      </el-card>
      <el-card class="box-card" style="width: 1000px">
        <el-tabs
          v-model="activeName"
          type="card"
          class="demo-tabs"
          @tab-click="handleClick"
        >
          <el-tab-pane label="跟踪记录" name="track">
            <Table :dataArr="trackData"></Table>
            <el-button type="primary" style="margin-top: 10px"
              >添加跟踪记录</el-button
            >
          </el-tab-pane>
          <el-tab-pane label="联系人" name="contact"
            ><Table :dataArr="trackData"></Table
          ></el-tab-pane>
          <el-tab-pane label="销售机会" name="opportunity"
            ><Table :dataArr="trackData"></Table
          ></el-tab-pane>
          <el-tab-pane label="产品报价" name="price"
            ><Table :dataArr="trackData"></Table
          ></el-tab-pane>
          <el-tab-pane label="服务记录" name="service"
            ><Table :dataArr="trackData"></Table
          ></el-tab-pane>
          <el-tab-pane label="销售合同" name="contract"
            ><Table :dataArr="trackData"></Table
          ></el-tab-pane>
        </el-tabs>
      </el-card>
    </el-space>
    <template #footer>
      <span class="dialog-footer">
        <el-button @click="dialogVisible6 = false">取消</el-button>
        <el-button type="primary" @click="saveDetail"> 修改 </el-button>
      </span>
    </template>
  </el-drawer>
</template>

<script setup>
import { ref } from 'vue'
import Table from '@/components/table/Table.vue'

/**
 * 详情
 */
// 控制查看详情抽屉的显示和隐藏
let dialogVisible6 = ref(false)
let detailInfo = ref({
  id: 1,
  name: '成都零起飞科技',
  createTime: '2023-02-11 14:50:14', //创建时间
  represent: '01', //客户代表
  belong: '中国', //客户来源
  level: '重点客户', //客户等级
  industry: '互联网企业', //客户行业,
  tel: '112', //联系电话
  mobile: '145', //联系手机,
  address: '联系地址', //联系地址
  intro: '客户介绍', //客户介绍
  demand: '客户需求' //客户需求
})
// 详情标签页
const activeName = ref('track')
// 跟踪记录数据
let trackData = ref([
  {
    跟踪记录主题: '',
    最近联系时间: '',
    沟通内容: '',
    下次联系时间: '',
    沟通方式: '',
    当前阶段: ''
  }
])
// 详情按钮回调
const detail = (row) => {
  detailInfo.value.id = row.id
  dialogVisible6.value = true
}
// 根据已保存的数据，发送请求
const saveDetail = () => {
  dialogVisible6.value = false
}
defineExpose({
  detail
})
</script>

<style lang="scss" scoped></style>
