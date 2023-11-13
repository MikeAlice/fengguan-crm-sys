#pragma once
#ifndef OUTBOUNDDETAILSERVICE_H__
#define OUTBOUNDDETAILSERVICE_H__
#include "domain/query/outbounddetail/OutboundDetailQuery.h"
#include "domain/dto/outbounddetail/OutboundDetailsDTO.h"
#include "domain/vo/BaseJsonVO.h"
#include <vector>

/*
* ������ϸ��ط���ʵ��
*/
class OutboundDetailService
{
public:
	//��ȡ������ϸ���б�   �����ˣ��Ǹ����
	OutboundDetailPageDTO::Wrapper listAll(const OutboundDetailQuery::Wrapper& query);
	//����������ϸ����		�����ˣ��Ǹ����
	String exportData(const List<ExportOutboundDetailsDTO::Wrapper>& query);
	//����Excel�ļ���	�����ˣ��Ǹ����	
	std::string getExcelFileName();
};

#endif // OUTBOUNDDETAILSERVICE_H__