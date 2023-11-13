#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/feeincome/FeeIncomeTreeVO.h"
#include "domain/query/feeincome/FeeIncomeQuery.h"
#include "domain/dto/feeincome/FeeIncomeDTO.h"


/**
 * �����������ͷ���ʵ��
 */
class FeeIncomeService
{
public:
	// ��ҳ��ѯ��������
	FeeIncomePageDTO::Wrapper listAll(const FeeIncomeQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const FeeIncomeDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const FeeIncomeDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
	//��ѯ�ṹ��
	FeeIncomeTreeJsonVO::Wrapper listTree(const FeeIncomeQuery::Wrapper& query);

};

#endif // !_SAMPLE_SERVICE_

