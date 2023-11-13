/*
 * @Author: BINGWU
 * @Date: 2023-10-26 20:52:05
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-06 17:35:13
 * @FilePath: \crm-frontend\src\apis\inventory-manager\index.js
 * @Describe:
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
import Request from '../request'

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

//查询入库明细
export const queryInventoryList = async (
  params,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(
    Request.GET,
    '/inventory-manager/query-storage-details',
    params
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 导出入库明细
export const exportStorageDetails = async (
  list_id = [],
  success = () => {},
  fail = () => {}
) => {
  let data = []
  list_id.forEach((item) => {
    data.push({ list_id: item })
  })
  Request.requestJson(
    Request.POST,
    '/inventory-manager/export-storage-details',
    data
  )
    .then((response) => {
      window.location.href = response.data
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 确认入库
export const modifyConfirmStorage = async (
  id,
  into_user_id,
  success = () => {},
  fail = () => {}
) => {
  Request.requestJson(Request.PUT, '/inventory-manager/modify-ConfirmStorage', {
    id,
    into_user_id
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 删除入库单
export const deleteStorage = async (
  id = [],
  success = () => {},
  fail = () => {}
) => {
  let data = []
  id.forEach((item) => {
    data.push({ id: item })
  })
  Request.requestJson(Request.DELETE, '/inventory-manager/delete-storage', data)
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取出库明细列表
export const queryOutboundDetail = async (
  pageIndex,
  pageSize,
  SKUname,
  success = () => {},
  fail = () => {}
) => {
  Request.requestJson(
    Request.POST,
    '/inventory-manager/query-outbound-detail',
    {
      pageIndex,
      pageSize,
      SKUname
    }
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 导出出库明细
export const exportOutboundDetail = async (
  list_id = [],
  success = () => {},
  fail = () => {}
) => {
  let data = []
  list_id.forEach((item) => {
    item.push({ list_id: item })
  })
  Request.requestJson(
    Request.POST,
    '/inventory-manager/export-outbound-details',
    data
  )
    .then((response) => {
      window.location.href = response.data
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取入库单列表
export const queryInstorage = async (
  pageIndex,
  pageSize,
  title,
  store_id,
  status,
  success = () => {},
  fail = () => {}
) => {
  let data = { title, store_id, status }
  const params = delEmptyQueryNodes(delEmptyQueryNodes(data))
  Request.requestForm(Request.GET, '/inventory-manager/query-instorage', {
    pageIndex,
    pageSize,
    ...params
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 查询入库明细
export const queryInstorageDetail = async (
  id,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(
    Request.GET,
    '/inventory-manager/query-instorage_details',
    {
      id
    }
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 添加入库单
export const addInstorage = async (
  params,
  success = () => {},
  fail = () => {}
) => {
  Request.requestJson(Request.POST, '/inventory-manager/add-instorage', {
    ...params
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取库存列表
export const queryInVentoryList = async (
  pageIndex,
  pageSize,
  goods_name,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/inventory-manager/query-inventory-list', {
    pageIndex,
    pageSize,
    goods_name
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 导出库存列表信息
export const exportInventoryList = async (
  goods_id = [],
  success = () => {},
  fail = () => {}
) => {
  let data = []
  goods_id.forEach((item) => {
    item.push({ goods_id: item })
  })
  Request.requestJson(
    Request.POST,
    '/inventory-manager/export-inventory-list',
    data
  )
    .then((response) => {
      window.location.href = response.data
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 确认出库
export const confirmOutstock = async (
  params,
  success = () => {},
  fail = () => {}
) => {
  Request.requestJson(
    Request.PUT,
    '/inventory-manager/confirm-outstock',
    params
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 删除出库
export const deleteOutstock = async (
  out_id = [],
  success = () => {},
  fail = () => {}
) => {
  let data = []
  out_id.forEach((item) => {
    data.push({ out_id: item })
  })
  Request.requestJson(
    Request.DELETE,
    '/inventory-manager/delete-outstock',
    data
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取出库单列表项
export const queryOutStock = async (
  pageIndex,
  pageSize,
  remarks,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/inventory-manager/query-out-stock', {
    pageIndex,
    pageSize,
    remarks
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 添加出库单
export const addOutStock = async (
  params,
  success = () => {},
  fail = () => {}
) => {
  Request.requestJson(Request.POST, '​/inventory-manager​/add-out_stock', {
    ...params
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 获取出库明细
export const outStockDetails = async (
  id,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.GET, '/inventory-manager/out-stock-details', {
    id
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}
