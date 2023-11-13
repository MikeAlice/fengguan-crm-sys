#pragma once
#ifndef OUTBOUNDDETAILSDTO_H__
#define OUTBOUNDDETAILSDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * OutboundDetail传输对象
 */
class OutboundDetailDTO : public oatpp::DTO
{
	DTO_INIT(OutboundDetailDTO, DTO);
		// id
	DTO_FIELD(UInt32,id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.id");
	}

	//SKU编号 
	DTO_FIELD(Int32, SKUID);
	DTO_FIELD_INFO(SKUID) {
		info->description = ZH_WORDS_GETTER("outboundDetail.field.SKUID");
	}

	// SKU名称 
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

class OutboundDetailPageDTO : public PageDTO<OutboundDetailDTO::Wrapper>
{
	DTO_INIT(OutboundDetailPageDTO, PageDTO<OutboundDetailDTO::Wrapper>);
};


class ExportOutboundDetailsDTO : public oatpp::DTO
{
	DTO_INIT(ExportOutboundDetailsDTO,DTO);
	// 订单项ID
	DTO_FIELD(UInt64, list_id);
	DTO_FIELD_INFO(list_id) {
		info->description = ZH_WORDS_GETTER("outbounddetails.field.list_id");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // OUTBOUNDDEETAILSDTO_H__
