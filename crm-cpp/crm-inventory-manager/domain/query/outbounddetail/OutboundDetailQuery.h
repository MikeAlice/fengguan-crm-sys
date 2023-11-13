#pragma once
#ifndef OUTBOUNDDETAILQUERY__H__
#define OUTBOUNDDETAILQUERY__H__
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * OutboundDetail传输对象
 */
class OutboundDetailQuery : public PageQuery
{
	DTO_INIT(OutboundDetailQuery, PageQuery);
	// id
	DTO_FIELD(UInt32,id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.id");
	}

	// 商品编号 
	DTO_FIELD(Int32, SKUID);
	DTO_FIELD_INFO(SKUID) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.SKUID");
	}

	// 商品名称 
	DTO_FIELD(String, SKUname);
	DTO_FIELD_INFO(SKUname) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.SKUname");
	}	
	
	// 商品名称
	DTO_FIELD(String, goodsName);
	DTO_FIELD_INFO(goodsName) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.goodsName");
	}

	// 商品编号
	DTO_FIELD(Int32, goodsId);
	DTO_FIELD_INFO(goodsId) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.goodsId");
	}


	//数量 
	DTO_FIELD(Int64, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.number");
	}
	
	//  商品类型
	DTO_FIELD(String, commodityType);
	DTO_FIELD_INFO(commodityType) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.commodityType");
	}

	// 仓库名称
	DTO_FIELD(String, storehouse);
	DTO_FIELD_INFO(storehouse) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.storehouse");
	}

	// 出库单
	DTO_FIELD(Int64, stockOut);
	DTO_FIELD_INFO(stockOut) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.stockOut");
	}

	// 出库时间
	DTO_FIELD(String, stockOutTime);
	DTO_FIELD_INFO(stockOutTime) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.stockOutTime");
	}

	// 备注
	DTO_FIELD(String, note);
	DTO_FIELD_INFO(note) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.note");
	}

	// 供应商名称
	DTO_FIELD(String,supplierName);
	DTO_FIELD_INFO(supplierName) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.suppliername");
	}

	// 通信地址
	DTO_FIELD(String, contactAdd);
	DTO_FIELD_INFO(contactAdd) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.contactAdd");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // OUTOFWAREHOUSEDTO_H__
