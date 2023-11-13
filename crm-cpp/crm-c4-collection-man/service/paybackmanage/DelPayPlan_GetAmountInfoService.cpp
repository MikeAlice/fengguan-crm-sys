#include "stdafx.h"
#include "DelPayPlan_GetAmountInfoService.h"
#include <dao/paybackmanage/DelPayPlan_GetAmountInfoDAO.h>



SelectAmountInfoDTO::Wrapper DelPayPlan_GetAmountInfoService::queryOne(const UInt64& amountid, int& tmp)
{
	auto dto = SelectAmountInfoDTO::createShared();
	// 查询数据总条数
	DelPayPlan_GetAmountInfoDAO dao;
	uint64_t count = dao.count(amountid);
	if (count <= 0)
	{
		tmp = 0;
		return dto;
	}
	PaybackInfoDO sub = dao.selectOne(amountid);
	// 将DO转换成DTO
	// 总金额
	//dto->totalamount = sub.getTamo();
	//// 去零金额
	//dto->zeroamount = sub.getZamo();
	//// 已经回款金额
	//dto->refundedamount = sub.getRamo();
	//// 已开发票金额
	//dto->invoicedamount = sub.getIamo();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, totalamount, Tamo, zeroamount, Zamo, refundedamount, Ramo, invoicedamount, Iamo);

	return dto;

}

bool DelPayPlan_GetAmountInfoService::removeData(uint64_t id)
{
	DelPayPlan_GetAmountInfoDAO dao;
	return dao.deleteById(id) == 1;
}
