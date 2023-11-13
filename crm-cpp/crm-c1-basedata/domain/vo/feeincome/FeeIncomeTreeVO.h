#pragma once
#ifndef _FeeIncomeTreeVO_H_
#define _FeeIncomeTreeVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/feeincome/FeeIncomeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个示例菜单显示JsonVO对象，用于响应给前端
 */
class FeeIncomeTreeJsonVO : public JsonVO<oatpp::List< FeeIncomeTreeDTO::Wrapper>>
{
	DTO_INIT(FeeIncomeTreeJsonVO, JsonVO<List< FeeIncomeTreeDTO::Wrapper>>);
public:
	// 在构造函数中实例化data列表
	FeeIncomeTreeJsonVO() {
		this->data = {};
	}
};
class FeeIncomeJsonVO : public JsonVO<FeeIncomeDTO::Wrapper> {
	DTO_INIT(FeeIncomeJsonVO, JsonVO<FeeIncomeDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class FeeIncomePageJsonVO : public JsonVO<FeeIncomePageDTO::Wrapper> {
	DTO_INIT(FeeIncomePageJsonVO, JsonVO<FeeIncomePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUVO_H_