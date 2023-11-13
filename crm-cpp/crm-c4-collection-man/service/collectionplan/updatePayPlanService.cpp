#include "stdafx.h"
#include "updatePayPlanService.h"
#include "../../dao/collectionplan/updatePayPlanDAO.h"


// 修改回款计划
bool updatePayPlanService::updateData(const updatePayPlanDTO::Wrapper& dto)
{
	// 组装DO数据
	updatePayPlanDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ClientName, clientName, ClientNameId, clientNameId, SaleContract, saleContract, SaleContractId, saleContractId, NoZeroAmount, noZeroAmount,
		BackAmount, backAmount, InvoiceAmount, invoiceAmount, PlanBackDate, planBackDate, Period, period, PlanBackAmount, planBackAmount, Id, id)
		// 执行数据修改
		updatePayPlanDAO dao;
	return dao.update(data) == 1;
}

// 确认回款计划
bool updateConfirmPlanService::updateData(const updateConfirmPlanDTO::Wrapper& dto)
{
	// 组装DO数据
	updateConfirmPlanDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ClientName, clientName, ClientNameId, clientNameId, SaleContract, saleContract, SaleContractId, saleContractId, TotalAmount, totalAmount,
		NoZeroAmount, noZeroAmount, HavePayAmount, havePayAmount, InvoiceAmount, invoiceAmount, PlanBackDate, planBackDate,
		Period, period, PayAmount, payAmount, PayAccount, payAccount, Id, id)
		// 执行数据修改
		updateConfirmPlanDAO dao;
	return dao.update(data) == 1;
}