/*
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-29 10:44:32
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-10-29 12:02:05
 * @FilePath: \zero-one-crmsys\crm-frontend\src\stores\sysManage\params.js
 * @Description:
 *
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved.
 */
import { defineStore } from 'pinia'

const useSysParams = defineStore('sysParams', {
  state: () => ({ formData: {} }),

  actions: {
    getSysParams() {
      return this.formData
    },
    //通过调用此函数改变store数据
    setSysParams(params) {
      console.log('params-in-pinia', params)
      this.formData = params
    },
    //未来在这里发请求
    init() {
      this.formData = {
        yuming: 'www.sayoriqwq.site',
        biaoti: '系统标题',
        xitongmingcheng: '01crm',
        banquan: '网站版信息',
        mingcheng: '01',
        //这里存放富文本内容
        jianjie: {
          //暂时不知道后端返回啥东西回来
          text: '文字内容',
          img: 'url'
        },
        dianhua: '13182748274',
        dizhi: '成都市高新区'
      }
      console.log('formData-in-pinia', this.formData)
    }
  }
})

export default useSysParams
