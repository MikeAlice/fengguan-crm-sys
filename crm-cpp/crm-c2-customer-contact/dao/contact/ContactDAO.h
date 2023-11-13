#pragma 
#ifndef _CONTACT_DAO_
#define _CONTACT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/contact/ContactDO.h"
#include "domain/query/contact/ExportContactQuery.h"
#include "domain/dto/contact/ExportContactDTO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ContactDAO : public BaseDAO
{
public:
	// ��ѯ����
	list<ContactDO> selectAll(const ExportContactQuery::Wrapper& query);
	// ��ѯ����
	list<ContactDO> selectAllById(uint64_t id);
	// ��������
	uint64_t insert(const ContactDO& iObj);
	// �޸�����
	int update(const ContactDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_CONTACT_DAO_
