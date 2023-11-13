#pragma once

#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/dto/contact/UpdateContactDTO.h"
#include "domain/dto/contact/AddContactDTO.h"
#include "domain/dto/contact/ExportContactDTO.h"
#include "domain/query/contact/ExportContactQuery.h"
#include "domain/vo/BaseJsonVO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ContactService
{
public:
	// ��ѯ��������
	list<ExportContactDTO::Wrapper> listContact(const ExportContactQuery::Wrapper& query);
	// ��������
	uint64_t saveContact(const AddContactDTO::Wrapper& dto, const PayloadDTO& playload);
	// �޸�����
	bool updateContact(const UpdateContactDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeContact(uint64_t id);
	// ���ͻ���Ϣ����ΪExcel�ļ��ϴ���FastDFS�ļ�������
	String uploadContact(list<ExportContactDTO::Wrapper>& dtolist);
};

#endif // !_SAMPLE_SERVICE_
