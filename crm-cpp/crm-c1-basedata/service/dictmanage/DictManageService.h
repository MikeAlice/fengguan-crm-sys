#ifndef _DICTMANAGE_SERVICE_
#define _DICTMANAGE_SERVICE_
#include <list>
#include "domain/vo/dictmanage/DictVO.h"
#include "domain/query/dictmanage/DictQuery.h"
#include "domain/dto/dictmanage/DictDTO.h"

/**
 * ����ʵ��-�ֵ����
 */
class DictManageService
{
public:
	// ��ҳ��ѯ��������
	DictPageDTO::Wrapper listAll(const DictQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const DictDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const DictDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
	//��ȡ�����б�
	oatpp::List<DictTypeListDTO::Wrapper> getPage();
};

#endif // !_DICTMANAGE_SERVICE_
