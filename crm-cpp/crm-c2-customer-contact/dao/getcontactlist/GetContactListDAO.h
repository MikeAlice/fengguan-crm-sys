#pragma once
/*
* ������: �Ͼ�
*/
#ifndef _GETCUSTOMER_DAO_
#define _GETCUSTOMER_DAO_
#include "BaseDAO.h"
#include "domain/query/contact/ListContactQuery.h"
#include "domain/do/contact/ListContactDO.h"

/**
 * ��ȡ��ϵ�˷�ҳ�б����ݿ����ʵ��
 */
class GetContactListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ListContactQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ListContactDO> selectWithPage(const ListContactQuery::Wrapper& query);
};
#endif // !_GETCUSTOMER_DAO_
