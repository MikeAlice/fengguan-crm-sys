/*
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-19 22:28:55
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-10-19 22:30:05
 * @FilePath: \zero-one-crmsys\crm-frontend\.eslintrc.cjs
 * @Description: 
 * 
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved. 
 */
/* eslint-env node */
require('@rushstack/eslint-patch/modern-module-resolution')

module.exports = {
  root: true,
  extends: [
    'plugin:vue/vue3-essential',
    'eslint:recommended',
    '@vue/eslint-config-prettier/skip-formatting'
  ],
  parserOptions: {
    ecmaVersion: 'latest'
  },

  // eslint的配置规则  配置代码规范
  // 安装eslint插件
  rules: {
    'prettier/prettier': [
      'warn',
      {
        singleQuote: true, // 单引号
        semi: false, // 无分号
        printWidth: 80, // 每行宽度至多80字符
        trailingComma: 'none', // 不加对象|数组最后逗号
        endOfLine: 'auto' // 换行符号不限制（win mac 不一致）
      }
    ],
    'vue/multi-word-component-names': [
      'warn',
      {
        ignores: ['index'] // vue组件名称多单词组成（忽略index.vue）
      }
    ],
    'vue/no-setup-props-destructure': ['off'], // 关闭 props 解构的校验
    // 💡 添加未定义变量错误提示，create-vue@3.6.3 关闭
    'no-undef': 'error'
  },
  // 配置全局变量名，使其未声明也不会报错
  globals: {
    ElMessage: 'readonly',
    ElMessageBox: 'readonly',
    ElLoading: 'readonly'
  },
  env: {
    'vue/setup-compiler-macros': true,
    node: true
  }
}
