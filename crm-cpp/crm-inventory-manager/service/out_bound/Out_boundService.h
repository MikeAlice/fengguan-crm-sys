#pragma once

#ifndef OUT_BOUNDSERVICE_H_
#define OUT_BOUNDSERVICE_H_

#include "domain/dto/out_bound/Out_boundDTO.h"
/**
 * 出库单服务实现
 */
class Out_boundService
{
public:
	// 确认出库（修改出库状态） 负责人：千亿
	uint64_t updateData(const ConfOut_boundDTO::Wrapper& dto);
	// 删除出库单（通过出库单ID删除数据） 负责人：千亿
	uint64_t removeData(const oatpp::List<DelOut_boundDTO::Wrapper>& dto);
};

#endif // !OUT_BOUNDSERVICE_H_