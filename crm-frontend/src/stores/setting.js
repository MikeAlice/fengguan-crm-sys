// 小仓库:layout组件相关配置仓库
import { defineStore } from 'pinia'
const useLayOutSettingStore = defineStore('SettingStore', {
  state: () => {
    return {
      fold: false, //控制菜单栏折叠
      refsh: false // 控制刷新效果
    }
  }
})

export default useLayOutSettingStore
