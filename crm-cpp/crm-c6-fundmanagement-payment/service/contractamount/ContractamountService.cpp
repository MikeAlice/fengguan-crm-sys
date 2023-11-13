#include "stdafx.h"
#include "ContractamountService.h"
#include "../../dao/contractamount/ContractamountDAO.h"
ContractamountDTO::Wrapper ContractamountService::listAmount(const ContractamountQuery::Wrapper& query){
	// �������ض���
	auto amount = ContractamountDTO::createShared();
	ContractamountDAO dao;
	amount->total_money = dao.getTotal(query);
	amount->zero_money = dao.getZero(query);
	amount->paid_money = dao.getPaid(query);
	amount->invoice_money = dao.getInvoice(query);
	return amount;
}