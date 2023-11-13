/*
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-11-03 20:56:17
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-11-03 21:20:51
 * @FilePath: \zero-one-crmsys\crm-frontend\src\hooks\useTheme.js
 * @Description:
 *
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved.
 */
import { ref, watchEffect } from 'vue'

const activeThemeName = ref(localStorage.getItem('theme') || '')

/** 设置主题 */
const setTheme = () => {
  activeThemeName.value = activeThemeName.value === 'dark' ? '' : 'dark'
  localStorage.setItem('theme', activeThemeName.value)
}

/** 在 html 根元素上挂载 class */
const setHtmlRootClassName = (value) => {
  document.documentElement.className = value
}

/** 初始化 */
const initTheme = () => {
  // watchEffect 来收集副作用
  watchEffect(() => {
    const value = activeThemeName.value
    setHtmlRootClassName(value)
    localStorage.setItem('theme', value)
  })
}

/** 主题 hook */
export function useTheme() {
  return { activeThemeName, initTheme, setTheme }
}
