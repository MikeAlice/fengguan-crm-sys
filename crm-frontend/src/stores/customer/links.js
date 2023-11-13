import { defineStore } from 'pinia'
import { ref } from 'vue'

const useLinkContacts = defineStore('linkContacts', () => {
  let tableData = ref([
    {
      linkmanId: 1, //联系人ID
      cuntomerId: '123', //客户ID
      customerName: '456', //客户名称
      linkName: '成都零起飞科技', //联系人名称
      gender: 0, //联系人性别 1=男，0=女
      position: '联系人职位', //联系人职位
      tel: '联系人座机', //联系人座机
      mobile: '联系人手机', //联系人手机
      qicq: '联系人QQ', //联系人QQ
      email: '联系人邮箱', //联系人邮箱
      zipcode: '联系人邮政编码', //联系人邮政编码
      address: '联系人地址', //联系人地址
      intro: '联系人简介', //联系人简介
      create_user_id: 0, //联系人创建人ID
      create_time: '联系人创建时间' // 联系人创建时间
    }
  ])

  // 添加数据
  let addNewData = () => {
    console.log('新增一条数据')
  }

  // 修改数据
  let updateData = () => {
    console.log('修改一条数据')
  }

  return {
    tableData,
    addNewData,
    updateData
  }
})

export default useLinkContacts
