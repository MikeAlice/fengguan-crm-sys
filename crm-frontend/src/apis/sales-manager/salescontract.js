import Request from '../request'
const BASEURL = ''

/**
 * @description: 获取销售合同数据列表
 * @param {*} data 请求参数:{name(String)}
 * @Author{*} seven(有问题找我)
 * @return {*}
 */
export const querySalesContractData = async (params) => {
  return await Request.requestJson(
    Request.GET,
    BASEURL + '/sales-contract/get-sales-contract-list',
    params
  )
}
/**
 * 获取销售合同唯一ID
 * @param {*} params 传递的参数
 * @returns
 */
export const getSalesContractIDListAPI = async (params) => {
  return await Request.requestForm(
    Request.GET,
    BASEURL + '/sales-contract/get-salesNo/' + params
  )
}

/**
 * 获取销售合同详情
 * @param {*} params
 * @returns
 */
export const getSalesContractDetailsAPI = async (params) => {
  return await Request.requestJson(
    Request.GET,
    BASEURL + '/sales-contract/get-sales-contract-detail-list',
    params
  )
}
/**
 * 获取销售合同查看清单的数据
 * @param {*} params
 * @returns
 */
export const getSalesContractListAPI = async (params) => {
  return await Request.requestJson(
    Request.GET,
    BASEURL + '/sales-contract/get-contract-goods',
    params
  )
}
/**
 * 添加销售合同
 * @param {} params
 * @returns
 */
export const addNewContractAPI = async (params) => {
  return await Request.requestJson(
    Request.POST,
    BASEURL + '/sales-contract/add-contract',
    params
  )
}

/**
 * 修改销售合同基本内容
 * @param {*} params
 * @returns
 */
export const updateSalesContractDataAPI = async (params) => {
  return await Request.requestForm(
    Request.POST,
    BASEURL + '/sales-contract/modify-basic-info',
    params
  )
}

/**
 * @description: 删除销售合同数据列表
 * @param {*} data
 *
 */
export const deleteSalesAPI = async (params) => {
  return await Request.requestJson(
    Request.DELETE,
    BASEURL + '/sales-contract/delete-contract/' + params
  )
}
/**
 * 修改交付状态
 * @param {*} params
 * @returns
 */
export const updateDeliverStatusAPI = async (params) => {
  return await Request.requestForm(
    Request.POST,
    BASEURL + '/sales-contract/modify-deliver-status',
    params
  )
}

/**
 * 录入明细
 * @param {*} params
 * @returns
 */
export const insertDetailsAPI = async (params) => {
  return await Request.requestForm(
    Request.POST,
    BASEURL + '/sales-contract/input-list',
    params
  )
}

export const deleteDetailsAPI = async (params) => {
  return await Request.requestJson(
    Request.DELETE,
    BASEURL + '/sales-contract/delete-contract-details/{list_id}',
    params
  )
}
/**
 * 上传文件  （原上传合同附件）
 * @param {} params
 * @returns
 */
export const importFileAPI = async (params) => {
  return await Request.requestForm(
    Request.POST,
    BASEURL + '/sales-contract/contractfile/upload',
    params
  )
}
/**
 * 生成出库单，
 * TODO 这里需要调用 库存管理->出库单->添加出库单 功能接口，出库单生成成功后再修改本单据相关数据
 * @param {*} params
 * @returns
 */
export const makeOrderListAPI = async (params) => {
  return await Request.requestForm(
    Request.POST,
    BASEURL + '/sales-contract/make-order',
    params
  )
}

/**
 * 导出销售合同
 * @param {} params
 * @returns
 */
export const exportContractAPI = async (params) => {
  return await Request.requestJson(
    Request.GET,
    BASEURL + '/sales-contract/ExportSales',
    params
  )
}
/**
 * 批量发短信（支持批量）
 * @param {*} params
 * @returns
 */
export const sendMailsAPI = async (params) => {
  return await Request.requestForm(
    Request.POST,
    BASEURL + '/sales-contract/sms',
    params
  )
}
/**
 * 批量发邮件（支持批量）
 * @param {*} params
 * @returns
 */
export const sendEMailsAPI = async (params) => {
  return await Request.requestForm(
    Request.POST,
    BASEURL + '/sales-contract/email',
    params
  )
}
