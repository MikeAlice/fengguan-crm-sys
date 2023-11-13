#ifndef CUSTOMERSCONTROLLER_H__
#define CUSTOMERSCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/customer/DetailsCustomerDTO.h"	
#include "domain/dto/customer/ModifyCustomerDTO.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Customer����������ӿͻ����޸Ŀͻ�
 */
class CustomerController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CustomerController);
	// 3 ����ӿ�
public:
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addcustomers) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("customer.controller.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/customer-mycustomer/post-customers", addcustomers, BODY_DTO(DetailsCustomerDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddcustomers(dto, authObject->getPayload()));
	}
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("customer.controller.put.summary"), modifycustomer, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/customer-mycustomer/put-customers", modifycustomer, BODY_DTO(ModifyCustomerDTO::Wrapper, dto), execModifycustomer(dto));
private:
	// �ڴ���Ӷ���
	Uint64JsonVO::Wrapper execAddcustomers(const DetailsCustomerDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifycustomer(const ModifyCustomerDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // CUSTOMERSCONTROLLER_H__