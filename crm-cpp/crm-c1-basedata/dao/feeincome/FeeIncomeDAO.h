#ifndef _FeeIncome_DAO_
#define _FeeIncome_DAO_
#include "BaseDAO.h"
#include "../../domain/do/feeincome/FeeIncomeDO.h"
#include "../../domain/query/feeincome/FeeIncomeQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class FeeIncomeDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const FeeIncomeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<FeeIncomeDO> selectWithPage(const FeeIncomeQuery::Wrapper& query);
	uint64_t insert(const FeeIncomeDO& iObj);
	// �޸�����
	int update(const FeeIncomeDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
	//��ѯȫ��
	list<FeeIncomeDO> selectALL();
	//��ȡ���ƽṹ����ָ�����ڵ�Ͳ�ѯ��ȣ�
	list<FeeIncomeDO> selectTree(const FeeIncomeQuery::Wrapper& query);
};
#endif // !_SAMPLE_DAO_
