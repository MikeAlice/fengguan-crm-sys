#pragma once
#ifndef _BANKACCOUNT_VO_
#define _BANKACCOUNT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/bankaccount/BankAccountDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BankAccountJsonVO : public JsonVO<BankAccountDTO::Wrapper> {
	DTO_INIT(BankAccountJsonVO, JsonVO<BankAccountDTO::Wrapper>);
};
class BankAccountListJsonVO : public JsonVO<oatpp::List<BankAccountListDTO::Wrapper>>
{
	DTO_INIT(BankAccountListJsonVO, JsonVO<oatpp::List<BankAccountListDTO::Wrapper>>);
};
/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BankAccountPageJsonVO : public JsonVO<BankAccountPageDTO::Wrapper> {
	DTO_INIT(BankAccountPageJsonVO, JsonVO<BankAccountPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_BANKACCOUNT_VO_
