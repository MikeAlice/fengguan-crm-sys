#include "stdafx.h"
#include "GetSalesNoService.h"

GetSalesContractNoDTO::Wrapper GetSalesNoService::getNo(const UInt64 contract_id)
{
	// �������ض���
	auto dto = GetSalesContractNoDTO::createShared();
	GetSalesNoDAO dao;
	//��ѯ����
	list<SalesContractDO> result = dao.selectById(contract_id);
	// ��DOת����DTO
	dto->contract_no = result.front().getContract_no();
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, result.front(), contract_no, Contract_no)
	return dto;
}
