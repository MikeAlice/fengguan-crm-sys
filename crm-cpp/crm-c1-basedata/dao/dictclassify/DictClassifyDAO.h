#ifndef _DICTCLASSIFY_DAO_
#define _DICTCLASSIFY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dictclassify/DictClassifyDO.h"
#include "../../domain/query/dictclassify/DictClassifyQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class DictClassifyDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const DictClassifyQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<DictClassifyDO> selectWithPage(const DictClassifyQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<DictClassifyDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const DictClassifyDO& iObj);
	// �޸�����
	int update(const DictClassifyDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
	////��ȡ�����б�
	list<DictClassifyListDO> selectPage();
};
#endif // !_DICTCLASSIFY_DAO_
