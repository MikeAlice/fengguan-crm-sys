// import Request from '../request'
import useDashBoard from '@/stores/dashBoard/dashBoard.js'

const dashBoard = useDashBoard()

/**
 * 获取系统通知的数据
 * @param {*} currentPage 当前页数
 * @param {*} pageSize 返回数据条数
 * @param {*} content 查询所用的内容
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getSystemAnnouncement = (
  currentPage,
  pageSize,
  content,
  success = () => {},
  fail = () => {}
) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve({ currentPage, pageSize, content })
    }, 0)
  })
    .then(() => {
      let data = [
        {
          id: '1', //id
          title: '明天在家一起开会了哟', //公告标题
          content: '明天在家一起开会了哟，不要忘了', //发布内容
          createman: 'aa', //发布人
          createTime: '2019-03-09 22:45:06', //发布时间
          state: '已查看', //状态
          receiver: 'bb' //接收人
        },
        {
          id: '1', //id
          title: '明天在家一起开会了哟', //公告标题
          content: '明天在家一起开会了哟，不要忘了', //发布内容
          createman: 'aa', //发布人
          createTime: '2019-03-09 22:45:06', //发布时间
          state: '已查看', //状态
          receiver: 'bb' //接收人
        },
        {
          id: '1', //id
          title: '明天在家一起开会了哟', //公告标题
          content: '明天在家一起开会了哟，不要忘了', //发布内容
          createman: 'aa', //发布人
          createTime: '2019-03-09 22:45:06', //发布时间
          state: '已查看', //状态
          receiver: 'bb' //接收人
        }
      ]
      if (data) {
        dashBoard.setAnnouncement(data)
        success()
        return
      }
      fail()
    })
    .catch(() => {
      fail()
    })
}

/**
 * 获取通知对象的数据
 * @param {*} content 查询所用的内容
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getDepartment = (content, success = () => {}, fail = () => {}) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(content)
    }, 0)
  })
    .then(() => {
      let data = [
        {
          value: 'Option1',
          label: '零起飞工作室'
        },
        {
          value: 'Option2',
          label: '商务部'
        },
        {
          value: 'Option3',
          label: '行政部'
        },
        {
          value: 'Option4',
          label: '技术部'
        },
        {
          value: 'Option5',
          label: 'yuki部'
        },
        {
          value: 'Option6',
          label: '财务部'
        }
      ]
      if (data) {
        dashBoard.setDepartment(data)
        success()
        return
      }
      fail()
    })
    .catch(() => {
      fail()
    })
}

/**
 * 获取指定对象的数据
 * @param {*} content 查询所用的内容
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getPerson = (content, success = () => {}, fail = () => {}) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve(content)
    }, 0)
  })
    .then(() => {
      let data = [
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
      if (data) {
        dashBoard.setPerson(data)
        success()
        return
      }
      fail()
    })
    .catch(() => {
      fail()
    })
}

/**
 * 获取提醒消息的数据
 * @param {*} currentPage 当前页数
 * @param {*} pageSize 返回数据条数
 * @param {*} content 查询所用的内容
 * @param {*} success 成功的回调
 * @param {*} fail 失败的回调
 * @returns
 */
export const getMessage = (
  currentPage,
  pageSize,
  content,
  success = () => {},
  fail = () => {}
) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve({ currentPage, pageSize, content })
    }, 0)
  })
    .then(() => {
      let data = [
        {
          id: '1', //消息id
          msgType: '客户预约联系', //消息类型
          content: '联系客户成都零起飞科技', //提醒内容
          msgTime: '	2023-10-06 11:55:39', //提醒时间
          createTime: '2023-10-27 14:53:55', //创建时间
          state: '已查看' //状态
        },
        {
          id: '2', //消息id
          msgType: '客户预约联系', //消息类型
          content: '联系客户成都零起飞科技', //提醒内容
          msgTime: '	2023-10-06 11:55:39', //提醒时间
          createTime: '2023-10-27 14:53:55', //创建时间
          state: '已查看' //状态
        },
        {
          id: '3', //消息id
          msgType: '客户预约联系', //消息类型
          content: '联系客户成都零起飞科技', //提醒内容
          msgTime: '	2023-10-06 11:55:39', //提醒时间
          createTime: '2023-10-27 14:53:55', //创建时间
          state: '已查看' //状态
        }
      ]
      if (data) {
        dashBoard.setMessage(data)
        success()
        return
      }
      fail()
    })
    .catch(() => {
      fail()
    })
}
