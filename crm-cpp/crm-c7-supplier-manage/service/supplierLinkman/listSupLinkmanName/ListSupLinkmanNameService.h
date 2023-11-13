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
	//��ȡ��Ӧ����ϵ�������б�
	LinkmanNameListDTO::Wrapper listAll(const LinkmanNameQuery::Wrapper& query);
};


#endif