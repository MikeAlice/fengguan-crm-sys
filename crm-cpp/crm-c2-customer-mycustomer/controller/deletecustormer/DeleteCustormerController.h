//2023年10月19日
//作者：狗皮电耗子
//内容：删除客户
#pragma once
#ifndef _DELETECUSTORMER_CONTRPLLER_
#define _DELETECUSTORMER_CONTRPLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/basecustomer/BaseCustormerListDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class DeleteCustormerController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(DeleteCustormerController);
public:
	ENDPOINT_INFO(deletecustormer) {
		// 定义删除客户标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("mycustormer.deletecustormer.summary"), Uint64JsonVO::Wrapper);
	}
	// 定义删除客户接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "customer-mycustomer/delete-custormer", deletecustormer, BODY_DTO(List<UInt64>, idArray), execRemoveCustormer(idArray));
private:
	Uint64JsonVO::Wrapper execRemoveCustormer(const List<UInt64> idArray);
};
#include OATPP_CODEGEN_END(ApiController)
#endif 
