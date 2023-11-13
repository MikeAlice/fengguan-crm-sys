#include "stdafx.h"
#include "GetSalesNoService.h"

GetSalesContractNoDTO::Wrapper GetSalesNoService::getNo(const UInt64 contract_id)
{
	// 构建返回对象
	auto dto = GetSalesContractNoDTO::createShared();
	GetSalesNoDAO dao;
	//查询数据
	list<SalesContractDO> result = dao.selectById(contract_id);
	// 将DO转换成DTO
	dto->contract_no = result.front().getContract_no();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, result.front(), contract_no, Contract_no)
	return dto;
}
