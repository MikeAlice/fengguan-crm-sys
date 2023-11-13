import Request from '@/apis/request'
//通过id获取单条票据
const getCollectionBill = (id) => {
  return Request.requestJson(Request.GET, '/payback-manage/select-amountinfo', {
    amountid: id
  })
}

//导出开票记录
//2023/11/2,拿到的是一个id
const exportCollectionBills = (idList) => {
  return Request.requestJson(
    Request.GET,
    '/collection-man/BillingRecords',
    idList
  )
}

//删除开票记录,支持批量
//但是目前只允许传一个id
const deleteCollectionBills = (id) => {
  return Request.requestJson(
    Request.DELETE,
    '/collection-man/BillingRecords',
    id
  )
}
export { getCollectionBill, exportCollectionBills, deleteCollectionBills }
