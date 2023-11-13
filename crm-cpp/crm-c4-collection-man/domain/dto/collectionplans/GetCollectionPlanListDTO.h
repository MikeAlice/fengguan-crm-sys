#pragma once

#ifndef _GETCOLLECTIONPLANLISTDTO_H_
#define _GETCOLLECTIONPLANLISTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ## ��ȡ�ؿ�ƻ��б������
 */
class GetCollectionPlanListDTO : public oatpp::DTO
{
	DTO_INIT(GetCollectionPlanListDTO, DTO);
	// �ͻ�����--customer_name--varchar
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("collectionplans.field.name"));
	// ���ۺ�ͬ--contract_name
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("collectionplans.field.contract_name"));
	// �ƻ��ؿ�����
	API_DTO_FIELD_DEFAULT(String, backdate, ZH_WORDS_GETTER("collectionplans.field.backdate"));
	// �ڴ�--int
	API_DTO_FIELD_DEFAULT(Int32, stages, ZH_WORDS_GETTER("collectionplans.field.stages"));
	// ���--int
	API_DTO_FIELD_DEFAULT(Int32, money, ZH_WORDS_GETTER("collectionplans.field.money"));
	// ������id
	API_DTO_FIELD_DEFAULT(Int32, create_user_id, ZH_WORDS_GETTER("collectionplans.field.create_user_id"));
	// ����ʱ��--varchar
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("collectionplans.field.createdate"));
	// �Ƿ�ؿ�--varchar
	API_DTO_FIELD_DEFAULT(String, ifpay, ZH_WORDS_GETTER("collectionplans.field.ifpay"));
	
};
/**
 * ʾ����ҳ�������
 */
class GetCollectionPlanListPageDTO : public PageDTO<GetCollectionPlanListDTO::Wrapper>
{
	DTO_INIT(GetCollectionPlanListPageDTO, PageDTO<GetCollectionPlanListDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_GETCOLLECTIONPLANLISTDTO_H_