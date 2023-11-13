#pragma once

#ifndef _GETCOLLECTIONPLANLISTDTO_H_
#define _GETCOLLECTIONPLANLISTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ## 获取回款计划列表传输对象
 */
class GetCollectionPlanListDTO : public oatpp::DTO
{
	DTO_INIT(GetCollectionPlanListDTO, DTO);
	// 客户名字--customer_name--varchar
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("collectionplans.field.name"));
	// 销售合同--contract_name
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("collectionplans.field.contract_name"));
	// 计划回款日期
	API_DTO_FIELD_DEFAULT(String, backdate, ZH_WORDS_GETTER("collectionplans.field.backdate"));
	// 期次--int
	API_DTO_FIELD_DEFAULT(Int32, stages, ZH_WORDS_GETTER("collectionplans.field.stages"));
	// 金额--int
	API_DTO_FIELD_DEFAULT(Int32, money, ZH_WORDS_GETTER("collectionplans.field.money"));
	// 创建人id
	API_DTO_FIELD_DEFAULT(Int32, create_user_id, ZH_WORDS_GETTER("collectionplans.field.create_user_id"));
	// 创建时间--varchar
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("collectionplans.field.createdate"));
	// 是否回款--varchar
	API_DTO_FIELD_DEFAULT(String, ifpay, ZH_WORDS_GETTER("collectionplans.field.ifpay"));
	
};
/**
 * 示例分页传输对象
 */
class GetCollectionPlanListPageDTO : public PageDTO<GetCollectionPlanListDTO::Wrapper>
{
	DTO_INIT(GetCollectionPlanListPageDTO, PageDTO<GetCollectionPlanListDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_GETCOLLECTIONPLANLISTDTO_H_