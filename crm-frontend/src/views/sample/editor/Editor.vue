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
      @onChange="handleChange"
    />
  </div>
</template>

<script setup>
import '@wangeditor/editor/dist/css/style.css' // 引入 css
import { onBeforeUnmount, ref, shallowRef, onMounted } from 'vue'
import { Editor, Toolbar } from '@wangeditor/editor-for-vue'
import { ElMessage } from 'element-plus'
import { DomEditor } from '@wangeditor/editor'

// 编辑器实例，必须用 shallowRef
const editorRef = shallowRef()
const mode = 'default' // 或 'simple'
// 内容HTML
const valueHtml = ref(`<p>你好，富文本编辑器</p>`)

// 模拟ajax异步获取内容
onMounted(() => {
  setTimeout(() => {
    valueHtml.value = `<p>模拟异步设置内容</p>`
  }, 1500)
})
// 组件销毁时，也及时销毁编辑器
onBeforeUnmount(() => {
  const editor = editorRef.value
  if (editor == null) return
  editor.destroy()
})
// 组件相关配置
const toolbarConfig = {}

toolbarConfig.toolbarKeys = [
  // 菜单 key
  'headerSelect',

  // 分割线
  '|',

  // 菜单 key
  'bold',
  'italic',
  'color',
  'underline',
  'fontSize',
  'fontFamily',
  'lineHeight',
  'emotion',

  // 菜单组，包含多个菜单
  {
    key: 'group-more-style', // 必填，要以 group 开头
    title: '更多样式', // 必填
    iconSvg: '<svg>....</svg>', // 可选
    menuKeys: ['through', 'code', 'clearStyle'] // 下级菜单 key ，必填
  }
  // 继续配置其他菜单...
]
//要排除哪个，就写哪个
toolbarConfig.excludeKeys = [
  'group-more-style' // 排除菜单组，写菜单组 key 的值即可
]
//菜单插入的位置
// toolbarConfig.insertKeys = {
//   index: 2 // 插入的位置，基于当前的 toolbarKeys
// }

const editorConfig = {
  placeholder: '请输入内容...',
  MENU_CONF: {
    // 配置图片上传服务器
    uploadImage: {
      // 服务端地址
      server: 'http://localhost:8090/file/editor-upload-image',
      // 文件上传对应的表单名称，默认值：wangeditor-uploaded-image
      fieldName: 'file',
      // 单个文件上传失败
      onFailed(file, res) {
        ElMessage.error('图片上传失败')
      },
      // 上传错误，或者触发 timeout 超时
      onError(file, err, res) {
        ElMessage.error('图片上传失败')
      },
      // 自定义插入图片
      customInsert(res, insertFn) {
        // 服务端的返回结果
        if (res.code === 10000)
          insertFn(res.data.url, res.data.alt, res.data.href)
        else ElMessage.error('图片上传失败')
      }
    }
  }
}
// 编辑器创建回调
const handleCreated = (editor) => {
  editorRef.value = editor // 记录 editor 实例，重要！
  setTimeout(() => {
    console.log('111', DomEditor.getToolbar(editor).getConfig())
  })
}
// 编辑器内容发生变化
const handleChange = (editor) => {
  console.log(editor.getHtml())
  console.log(editor.getText())
}
</script>
