<template>
  <h1 style="color: red">使用sheetjs(只考虑一个xlxs文件的情况)</h1>
  <el-button @click="exportFile" type="primary">导出数据为XLSX</el-button>
  <hr />
  <el-upload
    :on-change="handleChange"
    :auto-upload="false"
    style="margin-top: 80px"
  >
    <el-button type="primary">选择一个xlsx文件</el-button>
  </el-upload>
  <el-button @click="importFile" type="primary"
    >把xlsx文件导入为json数据</el-button
  >
</template>

<script setup>
// 把数组对象数据转化为xlsx文件的时候用
import { utils, writeFileXLSX } from 'xlsx'
// 把xslx文件转化为json数据的时候用
import XLSX from 'xlsx'
import { ref } from 'vue'
// 自定义excel导出函数
function exportFile() {
  // 准备一个数组对象
  const arr = [
    {
      goodsIdAndSkuId: '商品：abc\n' + ' SKU：888',
      goodsNameAndSkuNmae: '商品名：abc\n' + ' SKU名：888',
      number: '888',
      categoryName: '车型库',
      storeName: 'hhhh',
      intoIntro: '2022-1-2',
      intoTime: '2021-9-9',
      remarks: '哇哇哇哇'
    },
    {
      goodsIdAndSkuId: 'abc',
      goodsNameAndSkuNmae: '哇哈哈哈',
      number: '888',
      categoryName: '车型库',
      storeName: 'hhhh',
      intoIntro: '2022-1-2',
      intoTime: '2021-9-9',
      remarks: '哇哇哇哇'
    }
  ]
  // utils.json_to_sheet(参数) 参数为数组对象
  const ws = utils.json_to_sheet(arr)
  const wb = utils.book_new()
  // utils.book_append_sheet(参数1, 参数2, 参数3)
  // 参数1 为 utils.json_to_sheet(arr) 返回的对象
  // 参数2 为 utils.book_new() 返回的对象
  // 参数3 为 工作表的名称
  utils.book_append_sheet(wb, ws, 'Data')
  // writeFileXLSX(参数1, 参数2)
  // 参数1 为 utils.book_new() 返回的对象
  // 参数2 为 导出的excel的文件名  后缀为xlsx  例如: 'abc.xlsx'  '好看的.xlsx'
  writeFileXLSX(wb, '好看的.xlsx')
}
const file = ref(null)
// 选择文件后调用的函数
const handleChange = (newFile) => {
  // 获取到文件
  file.value = newFile.raw
}
// 自定义excel文件导入函数
const importFile = async () => {
  // 创建fileReader对象
  const reader = new FileReader()
  // 读取文件属性
  reader.readAsBinaryString(file.value)
  reader.onload = (re) => {
    // 获取到二进制的文件
    const data = re.target.result
    // 解析二进制的xlsx文件
    const excelData = XLSX.read(data, {
      type: 'binary'
    })
    // 下标0 表示 拿到excel文件里的第一张表
    // wsname 为表名
    const wsname = excelData.SheetNames[0]
    console.log('wsname', wsname)
    const content = XLSX.utils.sheet_to_json(excelData.Sheets[wsname])
    console.log(content)
  }
}
</script>

<style lang="scss" scoped></style>
