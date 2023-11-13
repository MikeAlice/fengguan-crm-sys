#pragma once
#ifndef __SENDMSEMCONTROLLER_H__
#define __SENDMSEMCONTROLLER_H__
#include "domain/vo/BaseJsonVO.h"
#include "stdafx.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "ApiHelper.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

//����ǰ׺
#ifndef SC_PRFIX
#define SC_PRFIX(_app_) "/crm-c4-sales-man" _app_
#endif // !SC_PRFIX

/*
*���Ͷ����ʼ��ӿ�ʵ��
*/

class SendmsemController : public oatpp::web::server::api::ApiController
{
	//������������ʽӿ�
	API_ACCESS_DECLARE(SendmsemController);
public: //����ӿ�

	//���Ͷ���
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("send.ms.summary"),addMs, BooleanJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, SC_PRFIX("/sendms"), addMs, BODY_DTO(List<oatpp::Int64>, dto), execSendMs(dto));
	//�����ʼ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("send.em.summary"), addEm, BooleanJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, SC_PRFIX("/sendem"), addEm, BODY_DTO(List<oatpp::Int64>, dto), execSendEm(dto));

private: //����ӿ�ִ�к���
	//ִ�з�����
	BooleanJsonVO::Wrapper execSendMs(const List<oatpp::Int64>& dto);
	//ִ�з��ʼ�
	BooleanJsonVO::Wrapper execSendEm(const List<oatpp::Int64>& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif  //__SENDMSEMCONTROLLER_H__