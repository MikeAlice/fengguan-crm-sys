#pragma once
#ifndef _FeeIncomeTreeVO_H_
#define _FeeIncomeTreeVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/feeincome/FeeIncomeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class FeeIncomeTreeJsonVO : public JsonVO<oatpp::List< FeeIncomeTreeDTO::Wrapper>>
{
	DTO_INIT(FeeIncomeTreeJsonVO, JsonVO<List< FeeIncomeTreeDTO::Wrapper>>);
public:
	// �ڹ��캯����ʵ����data�б�
	FeeIncomeTreeJsonVO() {
		this->data = {};
	}
};
class FeeIncomeJsonVO : public JsonVO<FeeIncomeDTO::Wrapper> {
	DTO_INIT(FeeIncomeJsonVO, JsonVO<FeeIncomeDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class FeeIncomePageJsonVO : public JsonVO<FeeIncomePageDTO::Wrapper> {
	DTO_INIT(FeeIncomePageJsonVO, JsonVO<FeeIncomePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_MENUVO_H_