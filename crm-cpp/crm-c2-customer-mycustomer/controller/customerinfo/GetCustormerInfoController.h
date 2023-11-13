//2023��10��27��
//��Ƥ�����
//��ȡ�����ͻ���Ϣ��DTO
#pragma once
#ifndef _GETCUSTORMER_CONTROLLER_
#define _GETCUSTORMER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/custormer/CustormerDTO.h"
#include "domain/vo/CuatormerJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GetCustormerInfoController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(GetCustormerInfoController);
public:
	// �����ѯ�����û���Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(getcustomerinfo) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("mycustormer.getcustormerinfo.summary"), CustomerJsonVO::Wrapper);
	}
	// �����ѯ�����û���Ϣ�ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/customer-mycustomer/get-base-custormer-info", getcustomerinfo, CustormerDTO, execQueryCustormerInfo());
private:
	CustomerJsonVO::Wrapper execQueryCustormerInfo();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GETCUSTORMER_CONTROLLER_
