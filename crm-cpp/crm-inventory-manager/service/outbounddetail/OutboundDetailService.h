#pragma once
#ifndef OUTBOUNDDETAILSERVICE_H__
#define OUTBOUNDDETAILSERVICE_H__
#include "domain/query/outbounddetail/OutboundDetailQuery.h"
#include "domain/dto/outbounddetail/OutboundDetailsDTO.h"
#include "domain/vo/BaseJsonVO.h"
#include <vector>

/*
* 出库明细相关服务实现
*/
class OutboundDetailService
{
public:
	//获取出库明细项列表   负责人：是个天才
	OutboundDetailPageDTO::Wrapper listAll(const OutboundDetailQuery::Wrapper& query);
	//导出出库明细数据		负责人：是个天才
	String exportData(const List<ExportOutboundDetailsDTO::Wrapper>& query);
	//生成Excel文件名	负责人：是个天才	
	std::string getExcelFileName();
};

#endif // OUTBOUNDDETAILSERVICE_H__