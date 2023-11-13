import Request from '../request'

const getParamsList = (pageParams) => {
  return Request.requestForm(
    Request.GET,
    '/systemmanagement/fly-sys-config/list',
    {
      ...pageParams
    }
  )
}

const updateParam = (data) => {
  return Request.requestJson(
    Request.PUT,
    '/systemmanagement/fly-sys-config/update',
    { data }
  )
}


export { getParamsList, updateParam }
