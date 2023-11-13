/*
 * @Author: BINGWU
 * @Date: 2023-10-28 22:16:05
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-09 22:45:56
 * @FilePath: \crm-frontend\src\apis\publicInterface.js
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
import Request from './request'
import useSelect from '@/stores/customer/select.js'

const select = useSelect()

/**
 * 获取客户名称下拉列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */

export const getCustomerName = async (
  name,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(
    Request.GET,
    '/customer-mycustomer/get-customername',
    {
      name
    }
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 获取联系人名称列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const queryContactName = (
  param,
  success = () => {},
  fail = () => {}
) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(param)
    }, 0)
  })
    .then(() => {
      let name = [
        {
          value: 'Option1',
          label: '成都零起飞科技'
        },
        {
          value: 'Option2',
          label: '01'
        },
        {
          value: 'Option3',
          label: 'asd'
        }
      ]
      if (name) {
        select.setName(name)
        success()
        return
      }
      fail()
    })
    .catch((err) => {
      fail(err)
    })
}

/**
 * @description: 获取字典分类下拉列表
 * @param {*} params // name 分类名称
 * @param {*} success
 * @param {*} fail
 * @return {*}
 */
export const getDictclassifylist = async (params, success, fail) => {
  await Request.requestJson(
    Request.GET,
    '/data-dictionary/dictclassify/get-dictclassifylist',
    {
      params
    }
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}
// // 导入 资金管理/资金注入抽取 仓库
// import useFundInjectionStore from '@/stores/fundManagement/fundInjection.js'
// const fundInjection = useFundInjectionStore()
// /**
//  * 获取银行账户列表数据(用于输入表单下拉列表)
//  * @param {*} success 成功的回调
//  * @param {*} fail 失败的回调
//  * @returns
//  */
// export const getBankAccountList = (
//   param,
//   success = () => {},
//   fail = () => {}
// ) => {
//   return new Promise((resolve) => {
//     setTimeout(() => {
//       resolve(param)
//     }, 0)
//   })
//     .then(() => {
//       let bankSelectList = [
//         {
//           value: 'Option1',
//           label: '所有回款账户'
//         },
//         {
//           value: 'Option2',
//           label: '工商银行982731237861283'
//         },
//         {
//           value: 'Option3',
//           label: '农业银行982731237861283'
//         }
//       ]
//       if (bankSelectList) {
//         // fundInjection是仓库名,把这个数据存到仓库
//         fundInjection.setBankSelectList(bankSelectList)
//         success()
//         return true
//       }
//       fail()
//     })
//     .catch((err) => {
//       fail(err)
//     })
// }

/**
 * @description: 获取部门名称列表数据(用于输入表单下拉列表)
 * @param {*} params 请求参数: { deptName:部门名称 }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */

/**
 * @description: 获取系统用户名称列表数据
 * @param {*} params 请求参数:{name(String)}
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const getUserNameList = async (params, success, fail) => {
  await Request.requestJson(
    Request.GET,
    '/orgstructure/user/user/get-userName-list',

    params
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      // console.log('12313', response)
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/*
 * 获取供应商名称列表
 * @param {*} name 名称关键字
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 */
export const querySupplierName = (
  name,
  success = () => {},
  fail = () => {}
) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(name)
    }, 0)
  })
    .then(() => {
      success()
    })
    .catch(() => {
      fail()
    })
}
/**
 * @description: 获取区域下拉列表
 * @param {Object} params
 * @param {Function} success
 * @param {Function} fail
 * @return {void}
 */
export const selectArea = async (params, success, fail) => {
  await Request.requestJson(Request.GET, '/j3-area/select-area', params)
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 获取供应商联系人名称下拉列表
 * @param {*} name 名称关键字
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 */
export const queryNamePullList = (
  keywords,
  success = () => {},
  fail = () => {}
) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(keywords)
    }, 0)
  })
    .then(() => {
      success()
    })
    .catch(() => {
      fail()
    })
}
/*
 * @description: 查询费用收入下拉列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @return {*}
 */
export const queryAllFeeincome = async (success, fail) => {
  await Request.requestJson(Request.GET, '/feeincome/query-all-feeincome')
    .then(async (response) => {
      await success(response)
    })
    .catch(async (error) => {
      await fail(error)
    })
}
/**
 * @description: 查询费用开支下拉列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @return {*}
 */
export const queryAllExpensetype = async (success, fail) => {
  await Request.requestJson(Request.GET, 'url')
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// /**
//  * @description: 获取银行账号下拉列表数据
//  * @param {*} success 成功的回调
//  * @param {*} fail 失败的回调
//  * @return {*}
//  */
// export const getBankaccountlist = async (success, fail) => {
//   await Request.requestJson(Request.GET, 'url')
//     .then((response) => {
//       success(response)
//     })
//     .catch((error) => {
//       fail(error)
//     })
// }

/**
 * @description: 查询仓库（分页或仓库名）
 * @param {*} params
 * {
 *   name: string 仓库名称
 *   pageSize: number 页面容量
 *   pageIndex: number 页码
 *   keyWord: string 关键词
 * }
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @return {*}
 */
export const queryStore = async (params, success, fail) => {
  await Request.requestJson(Request.GET, 'url', {
    params
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * @description: 获取岗位名称列表数据
 * @param {*} params 请求参数:
 * {
 *  positionName(岗位名称)
 * }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const querySalesOpportunityNameList = async (params) => {
  return await Request.requestJson(
    Request.GET,
    '/orgstructure/position/position/query-name-all',

    params
  )
}

/**
 * @description: 获取角色名称列表数据(用于输入表单下拉列表)
 * @param {*} params 请求参数: 没有参数
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const getRoleNameList = async (params, success, fail) => {
  await Request.requestForm(
    Request.GET,
    '/orgstructure/role/role/query-name-all',
    {
      params
    }
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * @description: 获取部门名称列表数据(用于输入表单下拉列表)
 * @param {*} params 请求参数: { deptName:部门名称 }
 * @param {*} success 成功回调
 * @param {*} fail 失败回调
 * @Author{*} 暮秋(有问题找我)
 * @return {*}
 */
export const getDepartmentList = async (params, success) => {
  await Request.requestForm(
    Request.GET,
    'http://101.34.252.80:10110/orgstructure/dept/dept/list-name-all',
    {
      ...params
    }
  )
    .then((response) => {
      // 请求返回的数据就是response,在成功回调函数可以拿到
      success(response)
    })
    .catch((error) => {
      console.log(error)
      ElMessage({
        message: '操作失败',
        type: 'warning'
      })
    })
}

/**
 * @description: 获取银行账号下拉列表数据
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @return {*}
 */
export const getBankaccountlist = async (success, fail) => {
  await Request.requestJson(
    Request.GET,
    '/financial-management/bankaccount/get-bankaccountlist'
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}
