#ifndef _DICTCLASSIFY_SERVICE_
#define _DICTCLASSIFY_SERVICE_
#include <list>
#include "domain/vo/dictclassify/DictClassifyVO.h"
#include "domain/query/dictclassify/DictClassifyQuery.h"
#include "domain/dto/dictclassify/DictClassifyDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class DictClassifyService
{
public:

	oatpp::List<DictClassifyListDTO::Wrapper>  getlistAll(const DictClassifyListQuery::Wrapper& query);
	// ��ҳ��ѯ��������
	DictClassifyPageDTO::Wrapper listAll(const DictClassifyQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const DictClassifyDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const DictClassifyDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_DICTCLASSIFY_SERVICE_