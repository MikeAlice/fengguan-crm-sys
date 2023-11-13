#pragma once
#ifndef OUTBOUNDDAO_H__
#define OUTBOUNDDAO_H__

#include "BaseDAO.h"
#include "domain/query/outbounddetail/OutboundDetailQuery.h"
#include "domain/do/outbounddetail/OutboundDetailDO.h"
#include "domain/dto/outbounddetail/OutboundDetailsDTO.h"


/*
	操作出库明细相关数据库
*/
class OutboundDetailDAO :public BaseDAO {
public:
	//统计数据条数
	uint64_t count(const OutboundDetailQuery::Wrapper& query);
	//分页查询数据
	list<OutboundDetailDO> selectWithPage(const OutboundDetailQuery::Wrapper& query);
	//导出数据
	list<OutboundDetailDO> selectWithId(const oatpp::List<ExportOutboundDetailsDTO::Wrapper>& exportt);
};


#endif // OUTBOUNDDAO_H__
