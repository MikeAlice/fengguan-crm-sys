#pragma once

#ifndef FLOWRECORDSERVICE_H__
#define FLOWRECORDSERVICE_H__
#include <list>
#include "domain/vo/flowrecord/FlowrecordPageJsonVO.h"
#include "domain/query/flowrecord/FlowrecordQuery.h"
#include "domain/dto/flowrecord/FlowrecordDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 * 负责人：智商局局长
 */
class FlowrecordService
{
public:
	// 分页查询所有数据
	FlowrecordPageDTO::Wrapper listAll(const FlowrecordPageQuery::Wrapper& query);
	// 将查询到的数据导出为文件
	std::string exportData(const oatpp::List<FlowrecordExportDTO::Wrapper>& dto);
};

#endif // !_SAMPLE_SERVICE_

