import Request from '../request'
import useSelect from '@/stores/customer/select.js'
import useMyClient from '@/stores/customer/myclient.js'

const select = useSelect()
const myclient = useMyClient()
/**
 * 获取客户联系人下拉列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getCustomerConcats = (
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
      let contacts = [
        {
          value: 'Option1',
          label: 'asdas'
        },
        {
          value: 'Option2',
          label: '张三'
        },
        {
          value: 'Option3',
          label: '李四'
        }
      ]
      if (contacts) {
        select.setContacts(contacts)
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
 * 获取客户归属下拉列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getCustomerBelong = (
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
      let belong = [
        {
          value: 'Option1',
          label: '网络'
        },
        {
          value: 'Option2',
          label: '客户介绍'
        },
        {
          value: 'Option3',
          label: '主动开发'
        }
      ]
      if (belong) {
        select.setBelong(belong)
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
 * 获取客户等级下拉列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getCustomerLevel = (
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
      let level = [
        {
          value: 'Option1',
          label: '普通客户'
        },
        {
          value: 'Option2',
          label: '一般客户'
        },
        {
          value: 'Option3',
          label: '重点客户'
        }
      ]
      if (level) {
        select.setLevel(level)
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
 * 获取客户行业列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getCustomerIndusty = (
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
      let industy = [
        {
          value: 'Option1',
          label: '互联网行业'
        },
        {
          value: 'Option2',
          label: '服务行业'
        },
        {
          value: 'Option3',
          label: '原材料行业'
        }
      ]
      if (industy) {
        select.setIndusty(industy)
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
 * 获取客户销售机会下拉列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getCustomerOpportnity = (
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
      let opportnity = [
        {
          value: 'Option1',
          label: '普通机会'
        },
        {
          value: 'Option2',
          label: '一般机会'
        },
        {
          value: 'Option3',
          label: '重点机会'
        }
      ]
      if (opportnity) {
        select.setOpportnity(opportnity)
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
 * 获取当前阶段下拉列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getCustomerStage = (
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
      let stage = [
        {
          value: 'Option1',
          label: '初期沟通'
        },
        {
          value: 'Option2',
          label: '立项评估'
        },
        {
          value: 'Option3',
          label: '需求分析'
        },
        {
          value: 'Option4',
          label: '方案制定'
        },
        {
          value: 'Option5',
          label: '商务谈判'
        },
        {
          value: 'Option6',
          label: '合同签订'
        },
        {
          value: 'Option7',
          label: '失单'
        }
      ]
      if (stage) {
        select.setStage(stage)
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
 * 获取沟通方式下拉列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getCustomerWay = (param, success = () => {}, fail = () => {}) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(param)
    }, 0)
  })
    .then(() => {
      let way = [
        {
          value: 'Option1',
          label: '电话'
        },
        {
          value: 'Option2',
          label: '上门'
        },
        {
          value: 'Option3',
          label: '邮寄'
        },
        {
          value: 'Option4',
          label: '网络'
        }
      ]
      if (way) {
        select.setWay(way)
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
 * 获取服务类型下拉列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getCustomerServiceType = (
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
      let serviceType = [
        {
          value: 'Option1',
          label: '投诉'
        },
        {
          value: 'Option2',
          label: '培训'
        },
        {
          value: 'Option3',
          label: '升级'
        },
        {
          value: 'Option4',
          label: '维护'
        }
      ]
      if (serviceType) {
        select.setServiceType(serviceType)
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
 * 获取服务方式下拉列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getCustomerServiceWay = (
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
      let serviceWay = [
        {
          value: 'Option1',
          label: '电话'
        },
        {
          value: 'Option2',
          label: 'QQ'
        },
        {
          value: 'Option3',
          label: '现场'
        },
        {
          value: 'Option4',
          label: '网络'
        }
      ]
      if (serviceWay) {
        select.setServiceWay(serviceWay)
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
 * 获取我方代表下拉列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getCustomerRepresent = (
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
      let represent = [
        {
          value: 'Option1',
          label: 'test'
        },
        {
          value: 'Option2',
          label: '管理员'
        },
        {
          value: 'Option3',
          label: 'cw'
        }
      ]
      if (represent) {
        select.setRepresent(represent)
        success()
        return
      }
      fail()
    })
    .catch((err) => {
      fail(err)
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
 * 获取客户列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getCustomer = async (
  pageIndex,
  pageSize,
  coon_Time,
  next_Time,
  name,
  mobile,
  tel,
  address,
  success = () => {},
  fail = () => {}
) => {
  let data = { coon_Time, next_Time, name, mobile, tel, address }
  const params = delEmptyQueryNodes(delEmptyQueryNodes(data))
  await Request.requestForm(Request.GET, '/customer-mycustomer/get-customer', {
    pageIndex,
    pageSize,
    ...params
  })
    .then((response) => {
      success(response)
    })
    .catch((err) => {
      fail(err)
    })
}

/**
 * 获取客户详细信息
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const queryCustomerDetails = async (
  customer_id,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(
    Request.GET,
    '/customer-mycustomer/query-customer-details',
    {
      customer_id
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
 * 获取客户基础信息表单数据项
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getBaseCustomerInfo = (success = () => {}, fail = () => {}) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve()
    }, 0)
  })
    .then(() => {
      let data = []
      if (data) {
        myclient.gettableData(data)
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
 * 添加新的客户
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const postCustomer = async (
  param,
  success = () => {},
  fail = () => {}
) => {
  delete param['customer_id']
  param['seaCustomer'] = param['seaCustomer'] ? 0 : 1
  delete param['seaCustomer']
  await Request.requestJson(
    Request.POST,
    '/customer-mycustomer/post-customers',
    param
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 修改客户基础信息
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const putCustomer = async (
  param,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(Request.PUT, '/customer-mycustomer/put-customers', {
    ...param
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 删除客户，可批量
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const deleteCustomer = async (
  list = [],
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(
    Request.DELETE,
    '/customer-mycustomer/delete-custormer',
    list
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 批量投入公海
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const invesHightSea = async (
  list = [],
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(
    Request.PUT,
    '/customer-mycustomer/inves-hightsea',
    list
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 导出客户
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const exportCustomer = async (
  customer_id_list,
  create_user_id,
  owner_user_id,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(
    Request.POST,
    '/customer-mycustomer/export-customer',
    {
      customer_id_list,
      create_user_id,
      owner_user_id
    }
  )
    .then(async (response) => {
      window.location.href = response.data
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 上传导入文件
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const uploadCustomerFile = async (
  success = () => {},
  fail = () => {}
) => {
  await Request.postFile('/customer-mycustomer/upload-customer-file')
    .then(async (response) => {
      window.location.href = response.data
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 导入客户
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const importCustomer = (str, success = () => {}, fail = () => {}) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(str)
    }, 0)
  })
    .then(() => {
      let data = []
      if (data) {
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
 * 接收客户
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const receiveCustomer = (
  list = [],
  success = () => {},
  fail = () => {}
) => {
  Request.requestJson(
    Request.PUT,
    '/crm-c2-customer-mycustomer/receive-custormer',
    list
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 获取联系人名称
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const queryContactName = async (
  name,
  success = () => {},
  fail = () => {}
) => {
  let data = {}
  if (name !== '') {
    data[name] = name
  }
  await Request.requestForm(
    Request.GET,
    '/customer-contact/query-contact-name',
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
 * 获取联系人列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const queryContactList = async (
  pageIndex,
  pageSize,
  key,
  customer_name,
  address,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(
    Request.GET,
    '/customer-contact/query-contact-list',
    {
      pageIndex,
      pageSize,
      key,
      customer_name,
      address
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
 * 获取联系人表单数据项
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getContactField = (success = () => {}, fail = () => {}) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve()
    }, 0)
  })
    .then(() => {
      let data = []
      if (data) {
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
 * 添加联系人
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const addNewContact = async (
  param,
  success = () => {},
  fail = () => {}
) => {
  param['gender'] === '男' ? (param['gender'] = 1) : (param['gender'] = 0)
  delete param['linkman_id']
  delete param['customerName']
  delete param['qq']
  console.log(param)
  await Request.requestJson(
    Request.POST,
    '/customer-contact/add-contact',
    param
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 修改联系人
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const modifyContact = async (
  param,
  success = () => {},
  fail = () => {}
) => {
  param['gender'] === '男' ? (param['gender'] = 1) : (param['gender'] = 0)
  delete param['customerName']
  await Request.requestJson(
    Request.PUT,
    '/customer-contact/modify-contact',
    param
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 删除联系人
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const removeContact = async (
  list = [],
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(
    Request.DELETE,
    '/customer-contact/remove-contact',
    {
      linkman_id: list
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
 * 导出联系人
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const queryContactFile = async (
  owner_user_id,
  create_user_id,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(
    Request.GET,
    '/customer-contact/query-contact-file',
    {
      owner_user_id,
      create_user_id
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
 * 发送短信
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const sendsms = async (
  linkman_id = [],
  ctype,
  content,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(Request.POST, '/customer-contact/send-sms', {
    linkman_id,
    ctype,
    content
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 发送邮件
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const sendEmail = async (
  linkman_id = [],
  ctype,
  content,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(Request.POST, '/customer-contact/send-email', {
    linkman_id,
    ctype,
    content
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 获取服务记录列表
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const queryServiceNote = async (
  pageIndex,
  pageSize,
  customer_name,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(
    Request.GET,
    '/customer-servicerecords/service-note',
    {
      pageIndex,
      pageSize,
      customer_name
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
 * 添加服务记录
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const addService = async (
  param,
  success = () => {},
  fail = () => {}
) => {
  delete param['service_id']
  delete param['customer_name']
  delete param['linkman_name']
  await Request.requestJson(
    Request.POST,
    '/customer-servicerecords/add-service',
    { ...param }
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 修改服务记录
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const modifyService = async (
  param,
  success = () => {},
  fail = () => {}
) => {
  console.log(param)
  await Request.requestJson(
    Request.PUT,
    '/customer-servicerecords/modify-service',
    { ...param }
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 删除服务记录，批量
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const removeService = async (
  list,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(
    Request.DELETE,
    '/customer-servicerecords/remove-service',
    {
      service_id_s: list
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
 * 导出服务记录
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const exportService = async (
  customer_id,
  service_id_list = [],
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(
    Request.POST,
    '/customer-servicerecords/export-servicenote',
    {
      customer_id,
      service_id_list
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

/**
 * 发送短信
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const sendsmsService = async (
  customer_id,
  ctype,
  message,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(Request.POST, '/customer-servicerecords/send-sms', {
    customer_id,
    ctype,
    message
  })
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

/**
 * 发送邮件
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const sendEmailService = async (
  customer_id,
  ctype,
  content,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestJson(
    Request.POST,
    '/customer-servicerecords/send-email',
    {
      customer_id,
      ctype,
      content
    }
  )
    .then((response) => {
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}
