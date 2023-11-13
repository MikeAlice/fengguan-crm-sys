import { defineStore } from 'pinia'

export const useTicketsRecord = defineStore('ticketRecord', {
  state: () => ({
    //从另外一个store里拿这几个数据
    //供应商名单列表
    supplierNameList: ['sayoriqwq', 'sayori'],
    //合同金额信息
    contractAmountInfo: {
      zongjine: '123',
      qulingjine: '123',
      yifujine: '12',
      yishoufapiaojine: '1'
    },
    //采购合同列表数据
    saleContractList: ['合同1', '合同2'],
    sendData: {
      tableColumnAttribute: [
        {
          prop: 'supplier_name',
          label: '供应商'
        },
        {
          prop: 'contract_name',
          label: '合同单号'
        },
        {
          prop: 'name',
          label: '发票内容'
        },
        {
          prop: 'invoie_no',
          label: '发票编号'
        },
        {
          prop: 'money',
          label: '金额'
        },
        {
          prop: 'rece_date',
          label: '收票时间'
        },
        {
          prop: 'stages',
          label: '期次'
        },
        {
          prop: 'create_user',
          label: '创建人'
        },
        {
          prop: 'intro',
          label: '备注'
        }
      ],
      tableData: [],
      useHeader: false,
      usePagination: true,
      pageSizes: [2, 4, 6, 10],
      total: 10
    }
  }),
  getters: {},
  actions: {
    async getTicketsList() {
      setTimeout(() => {
        const data = [
          {
            supplier_name: 'sayoriqwq',
            contract_name: '合同1',
            name: '发票内容：收',
            invoice_no: 1,
            money: 999,
            rece_date: '2020-01-01 00:00:00',
            stages: '1',
            create_user: 'sayori',
            intro: '备注'
          },
          {
            supplier_name: 'sayori',
            contract_name: '合同2',
            name: '发票内容：收',
            invoice_no: 1,
            money: 999,
            rece_date: '2020-01-01 00:00:00',
            stages: '1',
            create_user: 'sayori',
            intro: '备注'
          },
          {
            supplier_name: 'sayoriqwq',
            contract_name: '合同1',
            name: '发票内容：收',
            invoice_no: 1,
            money: 999,
            rece_date: '2020-01-01 00:00:00',
            stages: '1',
            create_user: 'sayori',
            intro: '备注'
          }
        ]
        this.sendData.tableData = data
      }, 0)
    }
  }
})
