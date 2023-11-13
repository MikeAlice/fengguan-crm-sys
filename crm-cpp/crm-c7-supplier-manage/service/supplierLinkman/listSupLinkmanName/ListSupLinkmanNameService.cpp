#include "stdafx.h"
#include "Macros.h"
#include "ListSupLinkmanNameService.h"
#include "domain/dto/supplierLinkman/LinkmanNameDTO.h"
#include "domain/do/supplierLinkman/SupplierLinkmanDO.h"
#include "dao/supplierLinkman/selectSupLinkmanName/SelectSupLinkmanNameDAO.h"

LinkmanNameListDTO::Wrapper ListSupLinkmanNameService::listAll(const LinkmanNameQuery::Wrapper& query) {
	// 构建返回对象
	auto datas = LinkmanNameListDTO::createShared();

	SelectSupLinkmanNameDAO dao;
	list<SupplierLinkmanDO> result = dao.selectSupplierName(query);

	// 将DO转换成DTO
	for (SupplierLinkmanDO sub : result)
	{
		auto dto = LinkmanNameDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, linkman_id, LinkmanId, name, Name)
		datas->addItem(dto);
	}

	return datas;
}