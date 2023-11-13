import Request from '@/apis/request'
import useRecords from '@/stores/fund/records/records'

const records = useRecords()

// 获取流水记录列表
export const queryFlowredords = async (
  pageIndex,
  pageSize,
  bank_id,
  success = () => {},
  fail = () => {}
) => {
  await Request.requestForm(
    Request.GET,
    '/financial-manager/query-flowrecord',
    {
      pageIndex,
      pageSize,
      bank_id
    }
  )
    .then((response) => {
      records.total = response.data.total
      records.setTableData(response.data.rows)
      records.setTotalIncome(response.data.total_income)
      records.setTotalExpenditure(response.data.total_expenditure)
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}

// 导出流水记录
export const exportFlowrecords = async (
  list = [],
  success = () => {},
  fail = () => {}
) => {
  let data = []
  list.forEach((item) => {
    data.push({ bank_id: item })
  })
  await Request.requestJson(
    Request.POST,
    '​/financial-manager​/export-flowrecord',
    data
  )
    .then((response) => {
      window.location.href = response.data
      success(response)
    })
    .catch((error) => {
      fail(error)
    })
}
