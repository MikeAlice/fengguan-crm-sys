import Request from '../request'

import useSupplierLinkman from '@/stores/supplier/linkman/linkman'

const supplierLinkman = useSupplierLinkman()

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
 * 获取供应商联系人名称列表
 */
export const queryNamePullList = async (
  keywords,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(keywords)
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 *  获取供应商联系人列表
 */
export const getSupplier = async (
  pageIndex,
  pageSize,
  keywords,
  supplier_name,
  address,
  success = () => {},
  fail = () => {}
) => {
  let data = { keywords, supplier_name, address }
  const params = delEmptyQueryNodes(delEmptyQueryNodes(data))
  await Request.requestForm(
    Request.GET,
    '/supplier-manage/supplier-linkman/query-linkman-page',
    {
      pageIndex,
      pageSize,
      ...params
    }
  )
    .then((response) => {
      supplierLinkman.pageTotal = response.data.total
      supplierLinkman.setTableData(response.data.rows)
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 添加供应商联系人
 * @param {*} params 供应商联系人对象
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 */
export const addlinkman = async (
  params,
  success = () => {},
  fail = () => {}
) => {
  delete params['linkman_id']
  params['gender'] = params['gender'] === '男' ? 1 : 0
  await Request.requestJson(
    Request.POST,
    '/supplier-manage/supplier-linkman/add-linkman',
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
 * 修改供应商联系人
 * @param {*} params 供应商联系人对象,含supplierId
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 */
export const modifylinkman = async (
  params,
  success = () => {},
  fail = () => {}
) => {
  params['gender'] = params['gender'] === '男' ? 1 : 0
  const data = {
    linkman_id: params.linkman_id,
    name: params.supplier_name,
    gender: params.gender,
    tel: params.tel,
    position: params.position,
    mobile: params.mobile,
    email: params.email,
    qicq: params.qicq,
    address: params.address,
    supplier_id: params.supplier_id
  }
  await Request.requestJson(
    Request.PUT,
    '/supplier-manage/supplier-linkman/modify-link-man',
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
 * 删除供应商联系人，可批量
 * @param {*} params 供应商联系人对象,含supplierId
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 */
export const removelinkman = async (
  list = [],
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(
    Request.DELETE,
    '/supplier-manage/supplier-linkman/remove-linkman',
    {
      rows: list
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
 * 批量发短信
 * @param {*} supplierList 收件人列表
 * @param {*} supMessage 短信内容
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const sendMessage = async (
  supplier_list = [],
  type,
  message,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(
    Request.POST,
    '/supplier-manage/supplier-linkman/send-message',
    {
      supplier_list,
      type,
      message
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
 * 批量发邮件
 * @param {*} supplierList 收件人列表
 * @param {*} emailMsg 邮件内容
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const sendEmail = async (
  id_list = [],
  type,
  mess,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(
    Request.POST,
    '/supplier-manage/supplier-linkman/send-email',
    {
      id_list,
      type,
      mess
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
 * 导出供应商联系人
 * @param {*} params 供应商联系人对象,含supplierId
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 */
export const exportlinkman = async (
  keywords,
  supplier_name,
  address,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(
    Request.GET,
    '/supplier-manage/supplier-linkman/export-linkman',
    {
      keywords,
      supplier_name,
      address
    }
  )
    .then((response) => {
      window.location.href = response.data
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}
