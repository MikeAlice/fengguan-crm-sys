#pragma once
#ifndef OUTBOUNDDAO_H__
#define OUTBOUNDDAO_H__

#include "BaseDAO.h"
#include "domain/query/outbounddetail/OutboundDetailQuery.h"
#include "domain/do/outbounddetail/OutboundDetailDO.h"
#include "domain/dto/outbounddetail/OutboundDetailsDTO.h"


/*
	����������ϸ������ݿ�
*/
class OutboundDetailDAO :public BaseDAO {
public:
	//ͳ����������
	uint64_t count(const OutboundDetailQuery::Wrapper& query);
	//��ҳ��ѯ����
	list<OutboundDetailDO> selectWithPage(const OutboundDetailQuery::Wrapper& query);
	//��������
	list<OutboundDetailDO> selectWithId(const oatpp::List<ExportOutboundDetailsDTO::Wrapper>& exportt);
};


#endif // OUTBOUNDDAO_H__
