/*
 * @Author: BINGWU
 * @Date: 2023-11-04 14:05:55
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-04 14:07:33
 * @FilePath: \crm-frontend\src\apis\basic-data\product\productspecification.js
 * @Describe: 商品规格模块的api
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
import Request from '@/apis/request.js'
const baseUrl = ''
/**
 * @description: 增加商品规格
 * @param {Object} params
 * @return {Promise}
 */
export const addSpec = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/j4Commodity/commoditySpec/add-spec',
    params
  )
}
