#ifndef OUTD_STOCKDTO_H__
#define OUTD_STOCKDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Out_StockDTO传输对象
 */
 //Out_stock传输对象

class Out_stockDTO : public oatpp::DTO
{
	DTO_INIT(Out_stockDTO, DTO);

	// 商品ID
	DTO_FIELD(UInt64, goods_id);
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("out_stock.field.goods_id");
	}
	// SKU ID
	DTO_FIELD(UInt64, sku_id);
	DTO_FIELD_INFO(sku_id) {
		info->description = ZH_WORDS_GETTER("out_stock.field.sku_id");
	}
	// 商品名
	DTO_FIELD(String, goods_name);
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("out_stock.field.goods_name");
	}
	// SKU名
	DTO_FIELD(String, sku_name);
	DTO_FIELD_INFO(sku_name) {
		info->description = ZH_WORDS_GETTER("out_stock.field.sku_name");
	}
	// 数量
	DTO_FIELD(Int32, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("out_stock.field.number");
	}
	// 商品类型
	DTO_FIELD(String, category_name);
	DTO_FIELD_INFO(category_name) {
		info->description = ZH_WORDS_GETTER("out_stock.field.category_name");
	}
	// 仓库名称
	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("out_stock.field.store_name");
	}
	// 对应出库单
	DTO_FIELD(String, out_stock_order);
	DTO_FIELD_INFO(out_stock_order) {
		info->description = ZH_WORDS_GETTER("out_stock.field.out_stock_order");
	}
	// 出库时间
	DTO_FIELD(String, out_time);
	DTO_FIELD_INFO(out_time) {
		info->description = ZH_WORDS_GETTER("out_stock.field.out_time");
	}
	// 备注
	DTO_FIELD(String, remarks);
	DTO_FIELD_INFO(remarks) {
		info->description = ZH_WORDS_GETTER("out_stock.field.remarks");
	}
	// 供应商名称
	DTO_FIELD(String, supplier_name);
	DTO_FIELD_INFO(supplier_name) {
		info->description = ZH_WORDS_GETTER("out_stock.field.supplier_name");
	}

	//创建人
	DTO_FIELD(Int32, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("out_stock.field.create_user_id");
	}

	//创建时间
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("out_stock.field.create_time");
	}

	//状态
	DTO_FIELD(Int32, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("out_stock.field.status");
	}

	//对应出库单号
	DTO_FIELD(Int32, out_stock_id);
	DTO_FIELD_INFO(out_stock_id) {
		info->description = ZH_WORDS_GETTER("out_stock.field.out_stock_id");
	}
	//出库人员
	DTO_FIELD(String, out_stock_person);
	DTO_FIELD_INFO(out_stock_person) {
		info->description = ZH_WORDS_GETTER("out_stock.field.out_type");
	}
	//出库类型
	DTO_FIELD(String, out_type);
	DTO_FIELD_INFO(out_type) {
		info->description = ZH_WORDS_GETTER("out_stock.field. ctype");
	}
};

class Out_StockPageDTO : public PageDTO<Out_stockDTO::Wrapper>
{
	DTO_INIT(Out_StockPageDTO, PageDTO<Out_stockDTO::Wrapper>);

};
class AddOut_stock : public oatpp::DTO
{
	DTO_INIT(AddOut_stock, DTO);
	// 仓库名称
	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("out_stock.field.store_name");
	}
	// 数量
	DTO_FIELD(Int32, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("out_stock.field.number");
	}
	//状态
	DTO_FIELD(Int32, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("out_stock.field.status");
	}
	//出库人员
	DTO_FIELD(String, out_stock_person);
	DTO_FIELD_INFO(out_stock_person) {
		info->description = ZH_WORDS_GETTER("out_stock.field.out_type");
	}
	// 出库时间
	DTO_FIELD(String, out_time);
	DTO_FIELD_INFO(out_time) {
		info->description = ZH_WORDS_GETTER("out_stock.field.out_time");
	}
	//出库类型
	DTO_FIELD(String, out_type);
	DTO_FIELD_INFO(out_type) {
		info->description = ZH_WORDS_GETTER("out_stock.field. out_type");
	}
	//创建人
	DTO_FIELD(Int32, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("out_stock.field.create_user_id");
	}
	//创建时间
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("out_stock.field.create_time");
	}
};



#include OATPP_CODEGEN_END(DTO)
#endif // OUTD_STOCKDTO_H__