#pragma once
#ifndef _CONTRACTGOODSQUERY_H_
#define _CONTRACTGOODSQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// 原味的原味包
class ContractGoodsQuery : public PageQuery {
	DTO_INIT(ContractGoodsQuery, PageQuery);
	// 获取合同清单只需要提供合同编号
	DTO_FIELD(String, contract_no);
	DTO_FIELD_INFO(contract_no) {
		info->description = ZH_WORDS_GETTER("contractindex.field.contract_no");
	}

//	// 查询条数，放在这里方便修改
//	DTO_FIELD(UInt64, pageSize) = 10; 
//	DTO_FIELD_INFO(pageSize) {
//#ifndef LINUX
//		info->description = u8"每页数据条数";
//#else
//		info->description = "curr page size";
//#endif
//	}

};

#include OATPP_CODEGEN_END(DTO)

#endif