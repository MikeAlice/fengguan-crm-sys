#pragma once

#ifndef _GET_SUPLINKMANNAME_SERVER_
#define _GET_SUPLINKMANNAME_SERVER_

#include <list>
#include "domain/dto/supplierLinkman/LinkmanNameDTO.h"
#include "domain/query/supplierLinkman/LinkmanNameQuery.h"

class ListSupLinkmanNameService
{
	const std::string redis_title = "sup_linkman_name_list";
public:
	//获取供应商联系人名称列表
	LinkmanNameListDTO::Wrapper listAll(const LinkmanNameQuery::Wrapper& query);
};


#endif