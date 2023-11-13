import Request from './request'
import useCommonStore from '@/stores/common.js'

const commonStore = useCommonStore()

// 获取供应商名称列表
export const querySupplierNameList = async (
  keywords,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/query-supplier-name-list', {
    keywords
  })
    .then((response) => {
      let data = []
      if (response.data.rows) {
        response.data.rows.forEach((item) => {
          data.push({ value: item.supplierId, label: item.supplierName })
        })
        commonStore.setSupplierNameList(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取供应商联系人名称列表
export const queryLinkmanNameList = async (
  keywords,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/query-linkman-name-list', {
    keywords
  })
    .then((response) => {
      let data = []
      if (response.data.rows) {
        response.data.rows.forEach((item) => {
          data.push({ value: item.linkman_id, label: item.name })
        })
        commonStore.setLinkmanNameList(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取仓库名称列表
export const queryWarehouse = async (
  keywords,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/warehouse', {
    keywords
  })
    .then((response) => {
      let data = []
      if (response.data) {
        response.data.forEach((item) => {
          data.push({ value: item.storeId, label: item.name })
        })
        commonStore.setWarehouse(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取区域名称列表
export const queryArea = async (success = () => {}, fail = () => {}) => {
  Request.requestForm(Request.GET, '/common/area')
    .then((response) => {
      let data = []
      if (response.data) {
        response.data.forEach((item) => {
          data.push({ value: item.id, label: item.name })
        })
        commonStore.setArea(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取部门名称列表
export const queryDepartmentNameList = async (
  keywords,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/department-name-list', {
    keywords
  })
    .then((response) => {
      let data = []
      if (response.data) {
        response.data.forEach((item) => {
          data.push({ value: item.id, label: item.name })
        })
        commonStore.setDepartmentNameList(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取岗位名称列表
export const queryPositionNameList = async (
  keywords,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/position-name-list', {
    keywords
  })
    .then((response) => {
      let data = []
      if (response.data) {
        response.data.forEach((item) => {
          data.push({ value: item.id, label: item.name })
        })
        commonStore.setPositionNameList(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取角色名称列表
export const queryRoleNameList = async (
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/role-name-list')
    .then((response) => {
      let data = []
      if (response.data) {
        response.data.forEach((item) => {
          data.push({ value: item.id, label: item.name })
        })
        commonStore.setRoleNameList(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取系统用户名称列表
export const querySysUserNameList = async (
  keywords,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/sys-user-name-list', {
    keywords
  })
    .then((response) => {
      let data = []
      if (response.data) {
        response.data.forEach((item) => {
          data.push({ value: item.id, label: item.name })
        })
        commonStore.setSysUserNameList(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取客户名称列表
export const queryClientNameList = async (
  keywords,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/client-name-list', {
    keywords
  })
    .then((response) => {
      let data = []
      if (response.data) {
        response.data.forEach((item) => {
          data.push({ value: item.customer_id, label: item.name })
        })
        commonStore.setClientNameList(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取联系人名称列表
export const queryContactNameList = async (
  customer_id,
  name,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/query-contact-name', {
    customer_id,
    name
  })
    .then((response) => {
      let data = []
      if (response.data) {
        response.data.forEach((item) => {
          data.push({ value: item.linkman_id, label: item.linkman_name })
        })
        commonStore.setContactNameList(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取费用收入类型列表
export const queryCostIncomeTypeNameList = async (
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/cost-income-type-name-list')
    .then((response) => {
      if (response.data) {
        commonStore.setCostIncomeTypeNameList(response.data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取费用开支类型列表
export const queryCostExpenseTypeNameList = async (
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/cost-expense-type-name-list')
    .then((response) => {
      if (response.data) {
        commonStore.setCostExpenseTypeNameList(response.data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取银行账户列表
export const queryBankAccountList = async (
  keywords,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/bank-account-list', {
    keywords
  })
    .then((response) => {
      let data = []
      if (response.data) {
        response.data.forEach((item) => {
          data.push({
            value: item.bank_id,
            label: item.name,
            card: item.card
          })
        })
        commonStore.setBankAccountList(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取指定字典分类对应字典列表
export const queryDataDictNameList = async (
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/data-dict-name-list')
    .then((response) => {
      let data = []
      if (response.data) {
        response.data.forEach((item) => {
          data.push({
            value: item.id,
            label: item.type_name,
            type_tag: item.type_tag
          })
        })
        commonStore.setDataDictNameList(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取销售机会名称列表
export const querySaleOpportunityNameList = async (
  customer_id,
  name,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/sale-opportunity-name-list', {
    customer_id,
    name
  })
    .then((response) => {
      if (response.data.rows) {
        let data = []
        response.data.rows.forEach((item) => {
          data.push({
            value: item.chance_id,
            label: item.name
          })
        })
        commonStore.setSaleOpportunityNameList(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取销售合同名称列表
export const querySaleContractNameList = async (
  customer_id,
  name,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/sale-contract-name-list', {
    customer_id,
    name
  })
    .then((response) => {
      if (response.data.rows) {
        let data = []
        response.data.rows.forEach((item) => {
          data.push({
            value: item.contract_id,
            label: item.title
          })
        })
        commonStore.setSaleContractNameList(data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取商品分类名称列表
export const queryGoodsCategoryNameList = async (
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/common/goods-category-name-list')
    .then((response) => {
      if (response.data) {
        commonStore.setGoodsCategoryNameList(response.data)
      }
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}
