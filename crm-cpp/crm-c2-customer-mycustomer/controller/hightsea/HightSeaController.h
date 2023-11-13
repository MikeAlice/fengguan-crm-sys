//ʱ�䣺2023��10��19��
//���ߣ���Ƥ�����
//���ݣ�Ͷ�빫���ӿ�
#pragma once
#ifndef _HIGHTSEACONTROLLER_
#define _HIGHTSEACONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include <domain/dto/basecustomer/BaseCustomerDTO.h>

#include OATPP_CODEGEN_BEGIN(ApiController) 

class HightSeaController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(HightSeaController);
public:
	ENDPOINT_INFO(investhightsea) {
		// ����Ͷ�빫���ӿ�����
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("mycustormer.hightsea.summary"), Uint64JsonVO::Wrapper);
	}
	// ����Ͷ�빫���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/customer-mycustomer/inves-hightsea", investhightsea, BODY_DTO(List<UInt64>, idArray), execInvestHightSea(idArray));

private:
	Uint64JsonVO::Wrapper execInvestHightSea(const List<UInt64> idArray);
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !_HIGHTSEACONTROLLER_
