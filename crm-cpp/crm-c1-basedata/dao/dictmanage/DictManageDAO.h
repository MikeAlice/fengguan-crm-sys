
#ifndef _DICTMANAGE_DAO_
#define _DICTMANAGE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dictmanage/DictDO.h"
#include "../../domain/do/dictmanage/DictTypeDO.h"
#include "../../domain/query/dictmanage/DictQuery.h"

/**
 * ���ݿ����ʵ��-�ֵ����
 */
class DictDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const DictQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<DictDO> selectWithPage(const DictQuery::Wrapper& query);
	// ��������
	uint64_t insert(const DictDO& iObj);
	// �޸�����
	int update(const DictDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
	//��ѯ��������
	list<DictTypeDO> selectPage();
};
#endif // !_DICTMANAGE_DAO_
