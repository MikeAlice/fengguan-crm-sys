#ifndef _EXPENSETYPEDAO_
#define _EXPENSETYPEDAO_
#include "BaseDAO.h"
#include "../../domain/do/expensetype/ExpenseTypeDO.h"
#include "../../domain/query/expensetype/ExpenseTypeQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ExpenseTypeDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ExpenseTypeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ExpenseTypeDO> selectWithPage(const ExpenseTypeQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<ExpenseTypeDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const ExpenseTypeDO& iObj);
	// �޸�����
	int update(const ExpenseTypeDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
/**
 * ����֧���������ݿ����ʵ��
 */
class ExpenseDAO : public BaseDAO
{
public:

	//��ѯȫ��
	list<ExpenseDO> selectALL();
	//��ȡ���ƽṹ����ָ�����ڵ�Ͳ�ѯ��ȣ�
	list<ExpenseDO> selectTree(const ExpenseQuery::Wrapper& query);
};
#endif // !_EXPENSETYPEDAO_
