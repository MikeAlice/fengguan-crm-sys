/*
 * @Author: BINGWU
 * @Date: 2023-11-04 13:58:34
 * @LastEditors: BINGWU HuJiaCheng2003@163.com
 * @LastEditTime: 2023-11-04 14:01:20
 * @FilePath: \crm-frontend\src\apis\basic-data\product\ProductSKU.js
 * @Describe:商品SKU模块的api
 * @Mark: ૮(˶ᵔ ᵕ ᵔ˶)ა
 */
import Request from '@/apis/request.js'
const baseUrl = ''
/**
 * @description:删除sku
 * @param {Object} params
 * @return {Promise}
 */
export const delSku = async (params) => {
  return await Request.requestJson(
    Request.POST,
    baseUrl + '/j4Commodity/commoditySku/del-sku',

    params
  )
}
