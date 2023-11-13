#pragma once
#ifndef __SENDMSEMCONTROLLER_H__
#define __SENDMSEMCONTROLLER_H__
#include "domain/vo/BaseJsonVO.h"
#include "stdafx.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "ApiHelper.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

//定义前缀
#ifndef SC_PRFIX
#define SC_PRFIX(_app_) "/crm-c4-sales-man" _app_
#endif // !SC_PRFIX

/*
*发送短信邮件接口实现
*/

class SendmsemController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问接口
	API_ACCESS_DECLARE(SendmsemController);
public: //定义接口

	//发送短信
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("send.ms.summary"),addMs, BooleanJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, SC_PRFIX("/sendms"), addMs, BODY_DTO(List<oatpp::Int64>, dto), execSendMs(dto));
	//发送邮件
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("send.em.summary"), addEm, BooleanJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, SC_PRFIX("/sendem"), addEm, BODY_DTO(List<oatpp::Int64>, dto), execSendEm(dto));

private: //定义接口执行函数
	//执行发短信
	BooleanJsonVO::Wrapper execSendMs(const List<oatpp::Int64>& dto);
	//执行发邮件
	BooleanJsonVO::Wrapper execSendEm(const List<oatpp::Int64>& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif  //__SENDMSEMCONTROLLER_H__