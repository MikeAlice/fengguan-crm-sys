#ifndef OUTD_STOCKPAGEJSONVO_H__
#define OUTD_STOCKPAGEJSONVO_H__
#include "../../GlobalInclude.h"
#include "domain/dto/out_stock/Out_stockDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class Out_StockJsonVO : public JsonVO<Out_stockDTO::Wrapper> {
	DTO_INIT(Out_StockJsonVO, JsonVO<Out_stockDTO::Wrapper>);
};



/**
 * Out_StockPageJsonVO
 */
class Out_StockPageJsonVO : public JsonVO<Out_StockPageDTO::Wrapper>
{
	DTO_INIT(Out_StockPageJsonVO, JsonVO<Out_StockPageDTO::Wrapper>);

};
#include OATPP_CODEGEN_END(DTO)
#endif // OUTD_STOCKPAGEJSONVO_H__