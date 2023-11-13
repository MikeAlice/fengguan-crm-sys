#pragma once
#ifndef _BANKACCOUNT_VO_
#define _BANKACCOUNT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/bankaccount/BankAccountDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class BankAccountJsonVO : public JsonVO<BankAccountDTO::Wrapper> {
	DTO_INIT(BankAccountJsonVO, JsonVO<BankAccountDTO::Wrapper>);
};
class BankAccountListJsonVO : public JsonVO<oatpp::List<BankAccountListDTO::Wrapper>>
{
	DTO_INIT(BankAccountListJsonVO, JsonVO<oatpp::List<BankAccountListDTO::Wrapper>>);
};
/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class BankAccountPageJsonVO : public JsonVO<BankAccountPageDTO::Wrapper> {
	DTO_INIT(BankAccountPageJsonVO, JsonVO<BankAccountPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_BANKACCOUNT_VO_
