/*
 * @Author: BINGWU
 * @Date: 2023-11-05 16:59:46
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-05 18:02:08
 * @FilePath: \crm-frontend\src\utils\downloadfile.js
 * @Describe: 下载文件用的函数
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
import axios from 'axios'

export default (url, fileName = '默认') => {
  axios
    .get(url, { responseType: 'blob' })
    .then((response) => {
      const blob = response.data
      const url = window.URL.createObjectURL(blob)
      const a = document.createElement('a')
      a.style.display = 'none'
      a.href = url
      a.download = fileName // 设置下载属性为空字符串，浏览器会使用默认文件名
      document.body.appendChild(a)
      a.click()
      window.URL.revokeObjectURL(url)
    })
    .catch((error) => {
      console.error('文件下载失败:', error)
    })
}
