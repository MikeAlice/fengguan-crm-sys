/*
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-19 22:12:32
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-10-19 22:31:43
 * @FilePath: \zero-one-crmsys\crm-frontend\src\main.js
 * @Description:
 *
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved.
 */
import { createApp } from 'vue'
import { createPinia } from 'pinia'
import ElementPlus from 'element-plus'
// import 'element-plus/theme-chalk/src/message.scss'
import 'element-plus/theme-chalk/dark/css-vars.css'
import App from './App.vue'
import router from './router'
import './assets/main.css'
import zhCn from 'element-plus/dist/locale/zh-cn.mjs'

const app = createApp(App)
// element plus语言改为中文
app.use(ElementPlus, {
  locale: zhCn
})
app.use(createPinia())
app.use(router)

app.mount('#app')

// 安装HTTP中间件
import installHttp from './plugins/http'
installHttp(router)

// 安装ElIcon
import installElIcon from './plugins/el-icon'
installElIcon(app)
