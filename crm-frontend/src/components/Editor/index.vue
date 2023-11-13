<!--
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-22 19:38:36
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-10-22 20:08:37
 * @FilePath: \zero-one-crmsys\crm-frontend\src\components\Editor\index.vue
 * @Description: 
 * 
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved. 
-->
<template>
  <div style="border: 1px solid #ccc">
    <Toolbar
      style="border-bottom: 1px solid #ccc"
      :editor="editorRef"
      :defaultConfig="toolbarConfig"
      :mode="mode"
    />
    <Editor
      style="height: 500px; overflow-y: hidden"
      v-model="valueHtml"
      :defaultConfig="editorConfig"
      :mode="mode"
      @onCreated="handleCreated"
    />
  </div>
</template>

<script>
import COS from 'cos-js-sdk-v5' //引入腾讯云

//创建对象，这里用的我的腾讯cos密钥
const cos = new COS({
  SecretId: 'AKID9B3f2Vr23vlbMJygHg8X0Lh3Pm3FWnvy',
  SecretKey: '70gGmDTlvxLWYUZZTJK8rPEzgG9uW3Y1'
})

import '@wangeditor/editor/dist/css/style.css' // 引入 css

import { onBeforeUnmount, ref, shallowRef, onMounted } from 'vue'
import { Editor, Toolbar } from '@wangeditor/editor-for-vue'

export default {
  components: { Editor, Toolbar },
  setup() {
    // 编辑器实例，必须用 shallowRef
    const editorRef = shallowRef()

    // 内容 HTML
    const valueHtml = ref('<p>hello</p>')

    // 模拟 ajax 异步获取内容
    onMounted(() => {
      setTimeout(() => {
        valueHtml.value = '<p>模拟 Ajax 异步设置内容</p>'
      }, 1500)
    })

    const toolbarConfig = {}
    const editorConfig = { placeholder: '请输入内容...', MENU_CONF: {} }
    editorConfig.MENU_CONF['uploadImage'] = {
      // 自定义上传
      /**
       * @param {File} file 文件
       * @param {Function} insertFn 插入到富文本框里的回调,三个参数分别为url-alt-href
       */
      async customUpload(file, insertFn) {
        // file 即选中的文件
        // 自己实现上传，并得到图片 url alt href
        // 最后插入图片
        console.log('file', file)
        console.log('insertFn', insertFn)

        cos.putObject(
          {
            Bucket: 'sayoriqwq-1321815773' /* 填入您自己的存储桶，必须字段 */,
            Region: 'ap-nanjing' /* 存储桶所在地域，例如ap-beijing，必须字段 */,
            Key: file.name /* 存储在桶里的对象键（例如1.jpg，a/b/test.txt），必须字段 */,
            StorageClass: 'STANDARD',
            Body: file
          },
          (err, data) => {
            console.log('成功上传回调', err || data)
            if (data.statusCode === 200) {
              insertFn(`https:${data.Location}`, '', '')
            }
          }
        )
      }
    }

    // 组件销毁时，也及时销毁编辑器
    onBeforeUnmount(() => {
      const editor = editorRef.value
      if (editor == null) return
      editor.destroy()
    })

    const handleCreated = (editor) => {
      editorRef.value = editor // 记录 editor 实例，重要！
    }

    return {
      editorRef,
      valueHtml,
      mode: 'default', // 或 'simple'
      toolbarConfig,
      editorConfig,
      handleCreated
    }
  }
}
</script>
