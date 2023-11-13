#include "stdafx.h"
#include "FinInvoiceReceService.h"
#include "../../dao/FinInvoiceRece/FinInvoiceReceDAO.h"

uint64_t FinInvoiceReceService::saveData(const FinInvoiceReceDTO::Wrapper& dto)
{
    FinInvoiceReceDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Contract_id, contract_id, Supplier_id, supplier_id,
        Contract_name, contract_name, Supplier_name, supplier_name, Money, money,
        Rece_date, rece_date, Stages, stages, Name, name, Invoice_no, invoice_no,
        Intro, intro, Create_time, create_time, Create_user_id, create_user_id);
    FinInvoiceReceDAO dao;
    return dao.insert(data);
}
