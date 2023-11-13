#ifndef OUT_BOUNDDTO_H__
#define OUT_BOUNDDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//Out_bound传输对象
class Out_boundDTO : public oatpp::DTO
{
	DTO_INIT(Out_boundDTO, DTO);

	// 商品ID
	DTO_FIELD(UInt64, goods_id);
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("out_bound.field.goods_id");
	}
	// SKU ID
	DTO_FIELD(UInt64, sku_id);
	DTO_FIELD_INFO(sku_id) {
		info->description = ZH_WORDS_GETTER("out_bound.field.sku_id");
	}
	// 商品名
	DTO_FIELD(String, goods_name);
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("out_bound.field.goods_name");
	}
	// SKU名
	DTO_FIELD(String, sku_name);
	DTO_FIELD_INFO(sku_name) {
		info->description = ZH_WORDS_GETTER("out_bound.field.sku_name");
	}
	// 数量
	DTO_FIELD(Int32, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("out_bound.field.number");
	}
	// 商品类型
	DTO_FIELD(String, category_name);
	DTO_FIELD_INFO(category_name) {
		info->description = ZH_WORDS_GETTER("out_bound.field.category_name");
	}
	// 仓库名称
	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("out_bound.field.store_name");
	}
	// 对应出库单
	DTO_FIELD(Int32, out_bound_order);
	DTO_FIELD_INFO(out_bound_order) {
		info->description = ZH_WORDS_GETTER("out_bound.field.out_bound_order");
	}
	// 出库时间
	DTO_FIELD(String, out_time);
	DTO_FIELD_INFO(out_time) {
		info->description = ZH_WORDS_GETTER("out_bound.field.out_time");
	}
	// 备注
	DTO_FIELD(String, remarks);
	DTO_FIELD_INFO(remarks) {
		info->description = ZH_WORDS_GETTER("out_bound.field.remarks");
	}
	// 供应商名称
	DTO_FIELD(String, supplier_name);
	DTO_FIELD_INFO(supplier_name) {
		info->description = ZH_WORDS_GETTER("out_bound.field.supplier_name");
	}

	//创建人
	DTO_FIELD(Int16, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("out_bound.field.create_user_id");
	}

	//创建时间
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("out_bound.field.create_time");
	}

	//状态
	DTO_FIELD(Int16, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("out_bound.field.status");
	}

	//对应出库单号
	DTO_FIELD(Int16, out_bound_id);
	DTO_FIELD_INFO(out_bound_id) {
		info->description = ZH_WORDS_GETTER("out_bound.field.out_bound_id");
	}
	//出库人员
	DTO_FIELD(String, out_bound_person);
	DTO_FIELD_INFO(out_bound_person) {
		info->description = ZH_WORDS_GETTER("out_bound.field.out_type");
	}
	//出库类型
	DTO_FIELD(String, out_type);
	DTO_FIELD_INFO(out_type) {
		info->description = ZH_WORDS_GETTER("out_bound.field. ctype");
	}
};

//ConfOut_bound传输对象,用于确认出库
class ConfOut_boundDTO : public oatpp::DTO
{
	DTO_INIT(ConfOut_boundDTO, DTO);
	// 出库单id
	DTO_FIELD(Int64, out_id);
	DTO_FIELD_INFO(out_id) {
		info->description = ZH_WORDS_GETTER("confout_bound.field.out_id");
	}

	//状态
	DTO_FIELD(Int16, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("confout_bound.field.status");
	}

	// 数量
	DTO_FIELD(Int32, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("confout_bound.field.number");
	}

	//出库人
	DTO_FIELD(Int16, out_user_id);
	DTO_FIELD_INFO(out_user_id) {
		info->description = ZH_WORDS_GETTER("confout_bound.field.out_user_id");
	}
};

//DelOut_bound传输对象,用于删除出库单
class DelOut_boundDTO : public oatpp::DTO
{
	DTO_INIT(DelOut_boundDTO, DTO);
	// 出库单id
	DTO_FIELD(Int64, out_id);
	DTO_FIELD_INFO(out_id) {
		info->description = ZH_WORDS_GETTER("delout_bound.field.out_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // OUTD_STOCKDTO_H__