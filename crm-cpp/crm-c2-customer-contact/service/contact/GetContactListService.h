#pragma once
/*
* 负责人：老菌
*/
#ifndef _GETCONTACTLIST_SERVICE_
#define _GETCONTACTLIST_SERVICE_
#include <list>
#include "domain/query/contact/ListContactQuery.h"
#include "domain/dto/contact/ListContactDTO.h"
#include "dao/getcontactlist/GetContactListDAO.h"


/**
 * 获取联系人分页列表服务层实现
 */
class GetContactListService
{
public:
	// 分页查询所有数据
	ListContactPageDTO::Wrapper getContactList(const ListContactQuery::Wrapper& query);

};

#endif // !_GETCONTACTLIST_SERVICE_
