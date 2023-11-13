#include "stdafx.h"
#include "FinInvoiceReceDAO.h"

uint64_t FinInvoiceReceDAO::insert(const FinInvoiceReceDO& iObj)
{
    string sql = "INSERT INTO `fin_invoice_rece` (`contract_id`, `supplier_id`, `contract_name`, `supplier_name`, `money`, "
        "`rece_date`, `stages`, `name`, `invoice_no`, `intro`, `create_time`, `create_user_id`) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    return sqlSession->executeInsert(sql, "%i%i%s%s%i%s%i%s%s%s%s%i", iObj.getContract_id(), iObj.getSupplier_id(),
        iObj.getContract_name(), iObj.getSupplier_name(), iObj.getMoney(), iObj.getRece_date(), iObj.getStages(),
        iObj.getName(), iObj.getInvoice_no(), iObj.getIntro(), iObj.getCreate_time(), iObj.getCreate_user_id());
}
