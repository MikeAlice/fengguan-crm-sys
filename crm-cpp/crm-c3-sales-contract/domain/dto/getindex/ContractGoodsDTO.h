// 原味的原味包
// 合同清单，即合同中包含的所有商品的列表
#pragma once
#ifndef _CONTRACTGOODSTDTO_
#define _CONTRACTGOODSTDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 合同清单中的单个商品对象
 *
 * 商品名称goods_name/商品规格sku_name，销售价格sale_price，购买数量num，小计goods_money，备注comments
 */
class ContractGoodsDTO : public oatpp::DTO
{
	DTO_INIT(ContractGoodsDTO, DTO);

	//DTO_FIELD(UInt64, goods_id);
	//DTO_FIELD_INFO(goods_id) {
	//	info->description = ZH_WORDS_GETTER("getindex.field.goods_id");
	//}
	DTO_FIELD(String, goods_name);
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("getindex.field.goods_name");
	}
	DTO_FIELD(String, sku_name);
	DTO_FIELD_INFO(sku_name) {
		info->description = ZH_WORDS_GETTER("getindex.field.sku_name");
	}
	DTO_FIELD(Float64, sale_price);
	DTO_FIELD_INFO(sale_price) {
		info->description = ZH_WORDS_GETTER("getindex.field.sale_price");
	}
	DTO_FIELD(Int64, num);
	DTO_FIELD_INFO(num) {
		info->description = ZH_WORDS_GETTER("getindex.field.num");
	}
	DTO_FIELD(Float64, goods_money);
	DTO_FIELD_INFO(goods_money) {
		info->description = ZH_WORDS_GETTER("getindex.field.goods_money");
	}
	DTO_FIELD(String, remarks);
	DTO_FIELD_INFO(remarks) {
		info->description = ZH_WORDS_GETTER("getindex.field.remarks");
	}
};

/**
 * 商品分页传输对象
 */
class ContractGoodsPageDTO : public PageDTO<ContractGoodsDTO::Wrapper>
{
	DTO_INIT(ContractGoodsPageDTO, PageDTO<ContractGoodsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 

