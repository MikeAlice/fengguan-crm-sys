<template>
  <div class="ProductForm">
    <el-drawer v-model="visible" size="50%">
      <template #header>
        <h4>set title by slot</h4>
      </template>
      <template #default>
        <el-tabs
          v-model="activeName"
          class="demo-tabs"
          @tab-click="handleClick"
        >
          <el-tab-pane label="基本设置" name="first">
            <el-form :model="form" ref="formRef">
              <el-form-item label="商品名称" prop="typeName">
                <el-input
                  placeholder="请输入商品名称"
                  v-model="form.typeName"
                ></el-input>
              </el-form-item>
              <el-form-item label="商品分类" prop="typeName">
                <el-input
                  placeholder="请选择商品分类"
                  v-model="form.typeName"
                ></el-input>
              </el-form-item>
              <el-form-item label="商品品牌(需要修改)" prop="typeName">
                <el-input
                  placeholder="请输入商品"
                  v-model="form.typeName"
                ></el-input>
              </el-form-item>
              <el-form-item label="商品关键字" prop="typeName">
                <el-input
                  placeholder="请输入商品关键字"
                  v-model="form.typeName"
                ></el-input>
              </el-form-item>
              <el-form-item label="商品简介" prop="typeName">
                <el-input v-model="form.typeName" type="textarea"></el-input>
              </el-form-item>
              <h3>购买信息</h3>
              <el-form-item label="市场价格" prop="sort">
                <el-input-number
                  v-model="form.sort"
                  :min="0"
                  @change="handleChange"
                />
              </el-form-item>
              <el-form-item label="销售价格" prop="sort">
                <el-input-number
                  v-model="form.sort"
                  :min="0"
                  @change="handleChange"
                />
              </el-form-item>
              <el-form-item label="成本价格" prop="sort">
                <el-input-number
                  v-model="form.sort"
                  :min="0"
                  @change="handleChange"
                />
              </el-form-item>
              <el-form-item label="商品库存" prop="sort">
                <el-input-number
                  v-model="form.sort"
                  :min="0"
                  @change="handleChange"
                />
              </el-form-item>
              <el-form-item label="商品排序" prop="sort">
                <el-input-number
                  v-model="form.sort"
                  :min="0"
                  @change="handleChange"
                />
              </el-form-item>
              <el-form-item label="是否启用">
                <el-switch v-model="form.visible" />
              </el-form-item>
            </el-form>
          </el-tab-pane>
          <el-tab-pane label="商品详情" name="second">
            <Editor></Editor>
          </el-tab-pane>
          <el-tab-pane label="商品图片" name="third"
            ><el-upload
              class="avatar-uploader"
              :show-file-list="false"
              auto-upload="false"
            >
              <img v-if="imageUrl" :src="imageUrl" class="avatar" />
              <el-icon v-else class="avatar-uploader-icon"
                ><icon-plus></icon-plus
              ></el-icon> </el-upload
          ></el-tab-pane>
          <el-tab-pane label="商品规格" name="fourth">Task</el-tab-pane>
          <el-tab-pane label="商品属性" name="fourth">Task</el-tab-pane>
        </el-tabs>
      </template>
      <template #footer>
        <div style="flex: auto">
          <el-button @click="cancelClick">cancel</el-button>
          <el-button type="primary" @click="confirmClick">confirm</el-button>
        </div>
      </template>
    </el-drawer>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import Editor from '@/components/Editor/index.vue'
const visible = ref(true)
const form = ref({
  typeName: '',
  typeTag: '',
  intro: '',
  sort: 0,
  visible: false
})

const activeName = ref('first')

const handleClick = (tab, event) => {
  console.log(tab, event)
}
</script>

<style lang="scss" scoped>
.avatar-uploader {
  :deep() {
    .avatar {
      width: 120px;
      height: 120px;
      display: block;
    }

    .el-upload {
      border: 1px dashed var(--el-border-color);
      border-radius: 6px;
      cursor: pointer;
      position: relative;
      overflow: hidden;
      transition: var(--el-transition-duration-fast);
    }

    .el-upload:hover {
      border-color: var(--el-color-primary);
    }

    .el-icon.avatar-uploader-icon {
      font-size: 28px;
      color: #8c939d;
      width: 120px;
      height: 120px;
      text-align: center;
    }
  }
}
</style>
