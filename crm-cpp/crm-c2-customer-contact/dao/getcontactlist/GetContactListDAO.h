#pragma once
/*
* 负责人: 老菌
*/
#ifndef _GETCUSTOMER_DAO_
#define _GETCUSTOMER_DAO_
#include "BaseDAO.h"
#include "domain/query/contact/ListContactQuery.h"
#include "domain/do/contact/ListContactDO.h"

/**
 * 获取联系人分页列表数据库操作实现
 */
class GetContactListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ListContactQuery::Wrapper& query);
	// 分页查询数据
	list<ListContactDO> selectWithPage(const ListContactQuery::Wrapper& query);
};
#endif // !_GETCUSTOMER_DAO_
