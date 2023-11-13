#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _GETCONTACTLIST_SERVICE_
#define _GETCONTACTLIST_SERVICE_
#include <list>
#include "domain/query/contact/ListContactQuery.h"
#include "domain/dto/contact/ListContactDTO.h"
#include "dao/getcontactlist/GetContactListDAO.h"


/**
 * ��ȡ��ϵ�˷�ҳ�б�����ʵ��
 */
class GetContactListService
{
public:
	// ��ҳ��ѯ��������
	ListContactPageDTO::Wrapper getContactList(const ListContactQuery::Wrapper& query);

};

#endif // !_GETCONTACTLIST_SERVICE_
