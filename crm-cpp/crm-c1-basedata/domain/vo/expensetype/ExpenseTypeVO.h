#pragma once
#ifndef _EXPENSETYPEVO_
#define _EXPENSETYPEVO_

#include "../../GlobalInclude.h"
#include "../../dto/expensetype/ExpenseTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ExpenseTypeJsonVO : public JsonVO<ExpenseTypeDTO::Wrapper> {
	DTO_INIT(ExpenseTypeJsonVO, JsonVO<ExpenseTypeDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ExpenseTypePageJsonVO : public JsonVO<ExpenseTypePageDTO::Wrapper> {
	DTO_INIT(ExpenseTypePageJsonVO, JsonVO<ExpenseTypePageDTO::Wrapper>);
};
/**
 * ����һ������֧�����ͽṹ����ʾJsonVO����������Ӧ��ǰ��
 */
class ExpenseTreeJsonVO : public JsonVO<oatpp::List< ExpenseTreeDTO::Wrapper>>
{
	DTO_INIT(ExpenseTreeJsonVO, JsonVO<List< ExpenseTreeDTO::Wrapper>>);
public:
	// �ڹ��캯����ʵ����data�б�
	ExpenseTreeJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPENSETYPEVO_