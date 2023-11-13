#include "stdafx.h"
#include "ContractGoodsService.h"
#include "../../dao/getindex/ContractGoodsDAO.h"

// 原味的原味包
ContractGoodsPageDTO::Wrapper ContractGoodsService::listAll(const ContractGoodsQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = ContractGoodsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	ContractGoodsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) return pages;

	// 分页查询
	pages->total = count;
	pages->calcPages();
	list<ContractGoodsDO> result = dao.selectWithPage(query);

	// DO -> DTO
	for (ContractGoodsDO sub : result) {
		auto dto = ContractGoodsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, \
			goods_name, GoodsName, \
			sku_name, SkuName, \
			sale_price, SalePrice, \
			num, Num, \
			goods_money, GoodsMoney, \
			remarks, Remarks
		);
		pages->addData(dto);
	}

	return pages;
}
