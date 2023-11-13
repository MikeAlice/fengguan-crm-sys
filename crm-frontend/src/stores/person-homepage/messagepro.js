/*
 * @Author: setti5 2283356040@qq.com
 * @Date: 2023-11-08 23:03:14
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2023-11-08 23:29:21
 * @FilePath: \zero-one-crmsys\crm-frontend\src\stores\person-homepage\messagepro.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  queryMessage,
  queryMessageId,
  deleteMassage,
  markReadMessage,
  publishMessage
} from '@/apis/personal-homepage/message.js'
export const useMessageStore = defineStore('message', () => {
  const tableData = ref([])
  const total = ref()
  // 根据分页条件获取消息列表
  const getMessageList = async (params) => {
    console.log('getMessageList', params)
    await queryMessage(params)
      .then((res) => {
        tableData.value = res.data.rows.map((row) => {
          row.status = {
            value: row.flag ? '已处理' : '未处理',
            tagType: row.flag ? 'danger' : 'info'
          }
          return row
        })
        total.value = res.data.total
      })
      .catch((err) => {
        console.log('err', err)
      })
  }

  const getMessageIdList = async (params) => {
    return await queryMessageId(params)
  }
  const deleteMessageItem = async (params) => {
    return await deleteMassage(params)
  }
  const markMessageItem = async (params) => {
    return await markReadMessage(params)
  }
  const publishMessageItem = async (params) => {
    return await publishMessage(params)
  }

  return {
    tableData,
    total,
    getMessageList,
    getMessageIdList,
    deleteMessageItem,
    markMessageItem,
    publishMessageItem
  }
})
