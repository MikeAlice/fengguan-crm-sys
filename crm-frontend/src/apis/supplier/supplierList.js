import Request from '../request'

import useSupplierList from '@/stores/supplier/list/list'

const supplierList = useSupplierList()

/**
 * 获取供应商名称列表
 */
export const querySupplierName = async (
  name,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(
    Request.GET,
    '/supplier-manage/supplier/query-supplier-name',
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

// 过滤对象中值为null '' undefined 0 的值
export const delEmptyQueryNodes = (obj = {}) => {
  Object.keys(obj).forEach((key) => {
    let value = obj[key]
    value && typeof value === 'object' && delEmptyQueryNodes(value)
    ;(value === '' ||
      value === null ||
      value === undefined ||
      value.length === 0 ||
      Object.keys(value).length === 0) &&
      delete obj[key]
  })
  return obj
}

/**
 * 获取供应商列表
 */
export const getSupplier = async (
  pageIndex,
  pageSize,
  name,
  telephone,
  mobile,
  address,
  success = () => {},
  fail = () => {}
) => {
  let data = { name, telephone, mobile, address }
  const params = delEmptyQueryNodes(delEmptyQueryNodes(data))
  console.log(params)
  await Request.requestForm(
    Request.GET,
    '/supplier-manage/supplier/get-supplier',
    {
      pageIndex,
      pageSize,
      ...params
    }
  )
    .then((response) => {
      supplierList.pageTotal = response.data.total
      supplierList.setTableData(response.data.rows)
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 添加供应商
 * @param {*} params 供应商对象
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 */
export const addSupplier = async (
  params,
  success = () => {},
  fail = () => {}
) => {
  delete params['supplier_id']
  console.log(params)
  await Request.requestJson(
    Request.POST,
    '/supplier-manage/supplier/add-supplier',
    params
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 修改供应商
 * @param {*} params 供应商对象,含supplierId
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 */
export const modifySupplier = async (
  params,
  success = () => {},
  fail = () => {}
) => {
  const data = {
    supplierId: params.supplier_id,
    supplierName: params.name,
    ecoType: params.ecotype,
    trade: params.trade,
    address: params.address,
    linkman: params.linkman,
    telephone: params.tel,
    fax: params.fax,
    email: params.email,
    intro: params.intro
  }
  console.log(data)
  await Request.requestJson(
    Request.PUT,
    '/supplier-manage/supplier/modify-supplier',
    data
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 删除供应商，可批量
 * @param {*} params 供应商对象,含supplierId
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 */
export const removeSupplier = async (
  list = [],
  success = () => {},
  fail = () => {}
) => {
  const rows = []
  list.forEach((item) => {
    rows.push(item)
  })
  console.log(rows)
  await Request.requestJson(
    Request.DELETE,
    '/supplier-manage/supplier/remove-supplier',
    { rows }
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}
