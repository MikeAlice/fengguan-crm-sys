import Request from '../request'
import useMessageInfo from '@/stores/system-page/messageInfo.js'

const messageInfo = useMessageInfo()

/**
 * 获取消息通知
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const queryMessageNotices = (success = () => {}, fail = () => {}) => {
  Request.requestForm(Request.GET, '/sysindex/query-message-notices')
    .then((response) => {
      messageInfo.setMessageInfo(response.data)
      let index = 0
      response.data.forEach((item) => {
        if (item.flag === 0) {
          index++
        }
      })
      messageInfo.setIndex(index)
      success(response)
    })
    .catch((error) => fail(error))
}

// 标记通知为已读
export const markAsRead = async (
  id,
  messageType,
  success = () => {},
  fail = () => {}
) => {
  Request.requestForm(Request.PUT, '/sysindex/mark-as-read', {
    id,
    messageType
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 根据商机预计销售额统计商机数量
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */

export const countBusinessMoney = async (
  firstData,
  secondData,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(Request.GET, '/sysindex/count-business-money', {
    firstData,
    secondData
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 统计商机数量
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */

export const countBusinessNumber = async (
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(Request.GET, '/sysindex/count-business-number')
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 根据商机销售状态分类统计商机数量
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */

export const countBusinessSalestage = async (
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(Request.GET, '/sysindex/count-business-salestage')
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 根据商机预计成功率统计商机数量
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */

export const countBusinessSuccessrate = async (
  firstData,
  secondData,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(
    Request.GET,
    '/sysindex/count-business-successrate',
    { firstData, secondData }
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 根据客户等级统计数量
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */

export const countCustomerGrade = async (
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(Request.GET, '/sysindex/count-customer-grade')
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 根据客户行业统计数量
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */

export const countCustomerIndustry = async (
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(Request.GET, '/sysindex/count-customer-industry')
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 统计客户数量
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */

export const countCustomerNumber = async (
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(Request.GET, '/sysindex/count-customer-number')
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 根据客户来源统计数量
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */

export const countCustomerSource = async (
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(Request.GET, '/sysindex/count-customer-source')
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}
