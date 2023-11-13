<template>
  <div class="ProductMaintenace">
    <el-card class="box-card">
      <template #header>
        <div class="card-header">
          <el-icon><icon-message-box /></el-icon>
          <span style="font-size: 18px; margin-left: 4px">商品维护</span>
        </div>
      </template>
      <div class="content">
        <div class="top">
          <div class="left">
            <el-button type="primary" style="margin-right: 8px"
              >发布商品</el-button
            >
            <el-dropdown trigger="click">
              <el-button type="danger">
                批量操作
                <el-icon style="margin-left: 4px"
                  ><icon-caret-bottom
                /></el-icon>
              </el-button>
              <template #dropdown>
                <el-dropdown-menu>
                  <el-dropdown-item>推荐</el-dropdown-item>
                  <el-dropdown-item>取消推荐</el-dropdown-item>
                  <el-dropdown-item>上架</el-dropdown-item>
                  <el-dropdown-item>下架</el-dropdown-item>
                  <el-dropdown-item>删除</el-dropdown-item>
                </el-dropdown-menu>
              </template>
            </el-dropdown>
          </div>
          <div class="right">
            <!-- 下拉 -->
            <el-select
              v-model="value"
              class="m-2"
              placeholder="请选择"
              size="large"
              style="width: 125px; margin-right: 6px"
            >
              <el-option
                v-for="item in options"
                :key="item.value"
                :label="item.label"
                :value="item.value"
              />
            </el-select>
            <el-input
              v-model="inputValue"
              placeholder="输入商品名称"
              style="margin-right: 4px; width: 180px"
            />
            <DropDown
              v-model:input-value1="inputValue1"
              v-model:input-value2="inputValue2"
              v-model:input-value3="inputValue3"
              input-title1="店铺名称"
              input-title2="手机号"
              input-title3="联系地址"
              topInputTitle="供应商名称"
              bottomInputTitle="通信地址"
              :get-drop-down="() => [0, 1, 2, 3]"
              @handle-search="handleSearch"
            ></DropDown>
            <el-button
              type="primary"
              style="margin-left: 4px"
              @click="searchDetails"
            >
              <el-icon style="margin-right: 4px"><icon-search /></el-icon
              >搜索</el-button
            >
          </div>
        </div>
        <div class="bottom">
          <el-table :data="tableData" style="width: 100%">
            <el-table-column type="selection" />
            <el-table-column prop="goodsName" label="商品名称" width="300">
              <template #default="{ row }">
                <div class="pic_content">
                  <div class="left">
                    <el-image
                      style="width: 60px; height: 60px"
                      :src="row.goodsName.picUrl"
                      fit="fit"
                    />
                  </div>
                  <div class="right">
                    <span>时间：{{ row.goodsName.time }}</span>
                    <span>商家编码：{{ row.goodsName.code }}</span>
                  </div>
                </div>
              </template>
            </el-table-column>
            <el-table-column prop="price" label="价格" sortable />
            <el-table-column prop="totalInventory" label="总库存" sortable />
            <el-table-column prop="sale" label="销量" sortable />
            <el-table-column prop="sort" label="排序" sortable />
            <el-table-column label="操作"
              ><el-dropdown trigger="click">
                <el-button>
                  操作
                  <el-icon style="margin-left: 4px"
                    ><icon-caret-bottom
                  /></el-icon>
                </el-button>
                <template #dropdown>
                  <el-dropdown-menu>
                    <el-dropdown-item>推荐</el-dropdown-item>
                    <el-dropdown-item>取消推荐</el-dropdown-item>
                    <el-dropdown-item>上架</el-dropdown-item>
                    <el-dropdown-item>下架</el-dropdown-item>
                    <el-dropdown-item>修改</el-dropdown-item>
                    <el-dropdown-item>删除</el-dropdown-item>
                  </el-dropdown-menu>
                </template>
              </el-dropdown></el-table-column
            >
          </el-table>
          <div
            class="pagination"
            style="
              width: 100%;
              display: flex;
              justify-content: center;
              margin-top: 40px;
            "
          >
            <el-pagination
              v-model:current-page="currentPage4"
              v-model:page-size="pageSize4"
              :page-sizes="[100, 200, 300, 400]"
              layout="total, sizes, prev, pager, next, jumper"
              :total="400"
              @size-change="handleSizeChange"
              @current-change="handleCurrentChange"
            />
          </div>
        </div>
      </div>
    </el-card>
    <ProductForm></ProductForm>
  </div>
</template>

<script setup>
import DropDown from '@/components/DropDown/DropDown.vue'
import ProductForm from '../components/FormCom/ProductForm.vue'
import { ref } from 'vue'
const value = ref('出售中')

const options = [
  {
    value: 'Option1',
    label: '出售中'
  },
  {
    value: 'Option2',
    label: '已下架'
  },
  {
    value: 'Option3',
    label: '推荐'
  }
]

const tableData = [
  {
    goodsName: {
      code: 999,
      time: '2021-12-29',
      picUrl:
        'https://fuss10.elemecdn.com/e/5d/4a731a90594a4af544c0c25941171jpeg.jpeg'
    },
    price: 99,
    totalInventory: 100,
    sale: 99,
    sort: 80
  },
  {
    goodsName: {
      code: 999,
      time: '2021-12-29',
      picUrl:
        'https://fuss10.elemecdn.com/e/5d/4a731a90594a4af544c0c25941171jpeg.jpeg'
    },
    price: 99,
    totalInventory: 100,
    sale: 99,
    sort: 80
  },
  {
    goodsName: {
      code: 999,
      time: '2021-12-29',
      picUrl:
        'https://fuss10.elemecdn.com/e/5d/4a731a90594a4af544c0c25941171jpeg.jpeg'
    },
    price: 99,
    totalInventory: 100,
    sale: 99,
    sort: 80
  }
]
</script>

<style lang="scss" scoped>
.ProductMaintenace {
  .box-card {
    .card-header {
      display: flex;
      align-items: center;
    }
    .content {
      .top {
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
      .bottom {
        .pic_content {
          display: flex;
          align-items: center;
          .left {
            margin-right: 24px;
          }
          .right {
            display: flex;
            flex-direction: column-reverse;
          }
        }
      }
    }
  }
}
</style>
