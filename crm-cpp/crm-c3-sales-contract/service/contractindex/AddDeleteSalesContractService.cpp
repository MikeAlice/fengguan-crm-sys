#include "stdafx.h"
#include "AddDeleteSalesContractService.h"

// 原味的原味包
uint64_t SalesContractService::saveData(const AddSalesContractDTO::Wrapper& dto) {
	// 组装DO数据
	AddSalesContractDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		ContractNo, contract_no,
		Title, title,
		CustomerName, customer_name,
		LinkmanName, linkman_name,
		ChanceName, chance_name,
		StartDate, start_date,
		EndDate, end_date,
		Money, money,
		Intro, intro,
		OurUserName, our_user_name
	);
	// 执行数据添加
	SalesContractDAO dao;
	return dao.insert(data);
}

// 原味的原味包
bool SalesContractService::removeData(const std::string& contract_no) {
	SalesContractDAO dao;
	return dao.deleteByNo(contract_no) == 1;
}