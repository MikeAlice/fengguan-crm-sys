/*
 * @Author: setti5 2283356040@qq.com
 * @Date: 2023-11-01 21:29:40
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2023-11-09 21:48:33
 * @FilePath: \zero-one-crmsys\crm-frontend\src\stores\person-homepage\notice.js
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  addNotice,
  getNotice,
  queryNotion,
  removeNotice,
  updateNotice
} from '@/apis/personal-homepage/notice.js'

// 公共接口，获取用户列表
import { getUserNameList } from '@/apis/publicInterface.js'
import { getDepartmentList } from '@/apis/publicInterface.js'

export const useNoticeStore = defineStore('notice', () => {
  const tableData = ref([])
  const total = ref()
  // 公共接口——获取成员列表
  const optionsUserName = ref()
  // 公共接口——获取部门列表
  const optionsDepartmentName = ref()
  const setOptionsDepartmentName = (dataList)=> {
    optionsDepartmentName.value = dataList
  }
  // 获取公告列表
  const getStoreList = async (params) => {
    console.log('getStoreList', params)
    await queryNotion(params)
    .then((res) => {
      tableData.value = res.data.rows.map((row) => {
        row.status = {
          value: row.status ? '已读' : "未读",
          tagType: row.status ? 'info' : 'danger'
        }
        total.value = res.data.total
        return row
      })
    })
    .catch((err) => {
      console.log('err', err)
    })
  }
  // 获取抽屉用户名下拉菜单
  const getOptionsUserName = ()=>{
  getUserNameList({}, (res) => {
      optionsUserName.value = res.data.map((row)=>{
        return {
          label:row.name,
          value:row.id
        }
      })
    })
  }
  // 获取抽屉部门名下拉菜单
  const getOptionsDepartName = async(paramsObj) => {
    const {
      deptName
    } = paramsObj
    await getDepartmentList({
      deptName
    }, (res) => {
      optionsDepartmentName.value = res.data.map((row)=>{
        return {
          label:row.name,
          value:row.id
        }
      })
    })
  }
  // 添加公告
  const addNoticeItem = async (params)=>{
    return await addNotice(params)
  }
  // 获取指定公告详情
  const getNoticeItem = async (params)=>{
    console.log('getNoticeItem', params)
    return await getNotice(params)
  }
  // 删除公告
  const removeNoticeItem = async (params)=>{
    console.log('removeNoticeItem', params)
    return await removeNotice(params)
  }
  // 标记已读公告（可批量标记）
  const updateNoticeItem = async (params)=>{
    console.log('updateNoticeItem', params)
    return await updateNotice(params)
  }

  return {
      tableData,
      total,
      getStoreList,
      getOptionsDepartName,
      optionsDepartmentName,
      getOptionsUserName,
      optionsUserName,
      addNoticeItem,
      getNoticeItem,
      removeNoticeItem,
      updateNoticeItem,
      setOptionsDepartmentName
  }
})

