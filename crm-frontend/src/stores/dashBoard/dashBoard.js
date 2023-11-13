import { defineStore } from 'pinia'
import { ref } from 'vue'

const useDashBoard = defineStore('dashBoard', () => {
  // 系统公告表格数据
  const announcement = ref([
    // {
    //   id: 11,
    //   title: '下班',
    //   content: '七点半，01烧烤店集合',
    //   status: 0
    // }
  ])
  // 设置announcement的数据
  const setAnnouncement = (data = []) => {
    announcement.value = data
  }

  return {
    announcement,
    setAnnouncement
  }
})

export default useDashBoard
