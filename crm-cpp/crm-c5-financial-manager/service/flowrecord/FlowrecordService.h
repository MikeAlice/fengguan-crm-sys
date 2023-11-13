#pragma once

#ifndef FLOWRECORDSERVICE_H__
#define FLOWRECORDSERVICE_H__
#include <list>
#include "domain/vo/flowrecord/FlowrecordPageJsonVO.h"
#include "domain/query/flowrecord/FlowrecordQuery.h"
#include "domain/dto/flowrecord/FlowrecordDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 * �����ˣ����̾־ֳ�
 */
class FlowrecordService
{
public:
	// ��ҳ��ѯ��������
	FlowrecordPageDTO::Wrapper listAll(const FlowrecordPageQuery::Wrapper& query);
	// ����ѯ�������ݵ���Ϊ�ļ�
	std::string exportData(const oatpp::List<FlowrecordExportDTO::Wrapper>& dto);
};

#endif // !_SAMPLE_SERVICE_

