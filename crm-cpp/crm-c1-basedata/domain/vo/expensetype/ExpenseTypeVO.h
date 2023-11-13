#pragma once
#ifndef _EXPENSETYPEVO_
#define _EXPENSETYPEVO_

#include "../../GlobalInclude.h"
#include "../../dto/expensetype/ExpenseTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ExpenseTypeJsonVO : public JsonVO<ExpenseTypeDTO::Wrapper> {
	DTO_INIT(ExpenseTypeJsonVO, JsonVO<ExpenseTypeDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ExpenseTypePageJsonVO : public JsonVO<ExpenseTypePageDTO::Wrapper> {
	DTO_INIT(ExpenseTypePageJsonVO, JsonVO<ExpenseTypePageDTO::Wrapper>);
};
/**
 * 定义一个费用支出类型结构树显示JsonVO对象，用于响应给前端
 */
class ExpenseTreeJsonVO : public JsonVO<oatpp::List< ExpenseTreeDTO::Wrapper>>
{
	DTO_INIT(ExpenseTreeJsonVO, JsonVO<List< ExpenseTreeDTO::Wrapper>>);
public:
	// 在构造函数中实例化data列表
	ExpenseTreeJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPENSETYPEVO_