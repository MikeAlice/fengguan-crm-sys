//2023年10月27日
//狗皮电耗子
//获取基础客户信息的DTO
#pragma once
#ifndef _GETCUSTORMER_CONTROLLER_
#define _GETCUSTORMER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/custormer/CustormerDTO.h"
#include "domain/vo/CuatormerJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GetCustormerInfoController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(GetCustormerInfoController);
public:
	// 定义查询所有用户信息接口端点描述
	ENDPOINT_INFO(getcustomerinfo) {
		// 定义接口通用信息
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("mycustormer.getcustormerinfo.summary"), CustomerJsonVO::Wrapper);
	}
	// 定义查询所有用户信息接口端点处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/customer-mycustomer/get-base-custormer-info", getcustomerinfo, CustormerDTO, execQueryCustormerInfo());
private:
	CustomerJsonVO::Wrapper execQueryCustormerInfo();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GETCUSTORMER_CONTROLLER_
