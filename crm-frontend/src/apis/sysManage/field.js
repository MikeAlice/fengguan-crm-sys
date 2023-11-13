import Request from '@/request'

const getFieldById = (id) => {
  return Request.requestForm(Request.GET, '/CstPlus/gettype', {
    fieldExtId: id
  })
}

const updateField = (data) => {
  return Request.requestJson(Request.PUT, '/CstPlus/update', data)
}

//这里只可以传pageParams
const getFieldList = (pageParams) => {
  return Request.requestForm(
    Request.GET,
    '/systemmanagement/cst-field-ext-plus/list-page',
    { ...pageParams }
  )
}
//支持传其他参数
const getFieldListCanSearch = (pageParams, searchData) => {
  return Request.requestForm(
    Request.GET,
    '/systemmanagement/cst-field-ext/list',
    { ...pageParams, ...searchData }
  )
}
const addField = (data) => {
  return Request.requestJson(
    Request.POST,
    '/systemmanagement/cst-field-ext/add',
    data
  )
}

const deleteFieldById = (id) => {
  return Request.requestForm(
    Request.DELETE,
    '/systemmanagement/cst-field-ext/remove-by-id',
    id
  )
}
//批量
const deleteField = (extIds) => {
  return Request.requestForm(
    Request.DELETE,
    '/systemmanagement/cst-field-ext/remove-by-ids',
    extIds
  )
}
export {
  getFieldById,
  updateField,
  getFieldList,
  addField,
  getFieldListCanSearch,
  deleteFieldById,
  deleteField
}
