#pragma once
#ifndef _FININVOICERECE_CONTROLLER_H_
#define _FININVOICERECE_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/FinInvoiceReceDTO.h"
#include "ApiHelper.h"
//�����Ʊ��¼
#include OATPP_CODEGEN_BEGIN(ApiController)

class FinInvoiceReceController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(FinInvoiceReceController);
public:
	//�˵�����
	ENDPOINT_INFO(addFinInvoiceRece) {
		//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_invoice_rece.post.summary"));
		//����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/payment/invoice/post", addFinInvoiceRece, BODY_DTO(FinInvoiceReceDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execAddFinInvoiceRece(dto));
	}
private:
	Uint64JsonVO::Wrapper execAddFinInvoiceRece(const FinInvoiceReceDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)
#endif