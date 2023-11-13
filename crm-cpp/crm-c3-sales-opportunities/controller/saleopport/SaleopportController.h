#ifndef SALEOPPORTController_H__
#define SALEOPPORTCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/saleopport/SaleopportDTO.h"
#include "domain/query/saleopport/SaleopportQuery.h"
#include "domain/vo/saleopportquery/SaleopportQueryPageJsonVO.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Saleopport������
 */
class SaleopportController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(SaleopportController);
	// 3 ����ӿ�
public:
	//��ȡ���ۻ����б�
	ENDPOINT_INFO(querySalOppList) {
		//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("opportunities.controller.querySalOppList"));
		//����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(SaleopportPageJsonVO);
		//�����ҳ����
		API_DEF_ADD_PAGE_PARAMS();
		//�����ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "find_date", ZH_WORDS_GETTER("opportunities.field.cst_chance.find_date"), "1900-1-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "bill_date", ZH_WORDS_GETTER("opportunities.field.cst_chance.bill_date"), "9999-9-9", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "salestage", ZH_WORDS_GETTER("opportunities.field.cst_chance.salestage"), 1, false);
	}
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/sales-opportunities/query-invoices",
		querySalOppList, SaleopportPageQuery, execQuerySalOppList(query, authObject->getPayload()));

private:
	// �ڴ���Ӷ���
	SaleopportPageJsonVO::Wrapper execQuerySalOppList(const SaleopportPageQuery::Wrapper query, const PayloadDTO& payload);			//��ȡ���ۻ���
	Uint64JsonVO::Wrapper execAddInvoices(const AddSaleopportDTO::Wrapper dto, const PayloadDTO& payload);//�������ۻ���   
};



// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // SALEOPPORTCONTROLLER_H__