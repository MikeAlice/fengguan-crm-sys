// 这里是 组织结构/用户管理 仓库
import { defineStore } from 'pinia'
import { ref } from 'vue'
// 导入api方法
import { editUserApi } from '../../apis/organizationStructure/user'
const useUserManageStore = defineStore('userManage', () => {
  // 定义用户名称列表数据
  const userNameList = ref([])
  // 获取用户名称列表数据
  const setUserNameList = (dataList) => {
    userNameList.value = dataList
  }
  // 封装修改用户的api请求
  const EditUserApi = async (queryObj) => {
    const {
      queryObj: {
        account,
        deptID,
        email,
        gender,
        intro,
        mobile,
        name,
        password,
        positionID,
        qicq,
        roleID
      }
    } = queryObj
    await editUserApi(
      {
        account,
        deptID,
        email,
        gender,
        intro,
        mobile,
        name,
        password,
        positionID,
        qicq,
        roleID
      },
      (res) => {
        console.log('修改用户的成功回调', res)
        ElMessage({
          message: '修改成功',
          type: 'success'
        })
      },
      (error) => [console.log('修改用户失败回调', error)]
    )
  }
  return {
    userNameList,
    setUserNameList,
    EditUserApi
  }
})
export default useUserManageStore
