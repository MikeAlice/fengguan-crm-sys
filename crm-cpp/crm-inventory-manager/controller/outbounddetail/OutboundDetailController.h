#pragma once
#ifndef OUTBOUNDDETAILCONTROLLER_H__
#define OUTBOUNDDETAILCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/outbounddetail/OutboundDetailsPageJsonVO.h"
#include "domain/query/outbounddetail/OutboundDetailQuery.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * OutboundDetail������������������ϸ
 */
class OutboundDetailController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(OutboundDetailController);
	// 3 ����ӿ�
public:
	//��ҳ��ȡ������ϸ�б� �����ˣ��Ǹ����
	ENDPOINT_INFO(queryOutboundDetail) {
		//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("outbounddetail.controller.query.summary"));
		//����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(OutboundDetailQuery);
		//�����ҳ����
		API_DEF_ADD_PAGE_PARAMS();
		//�����ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String,"SKUname",ZH_WORDS_GETTER("outbounddetail.example.skuname"),"SKUname",false);
		API_DEF_ADD_QUERY_PARAMS(String,"supplierName",ZH_WORDS_GETTER("outbounddetail.example.supplierName"),"supplierName",false);
		API_DEF_ADD_QUERY_PARAMS(String,"contactAdd",ZH_WORDS_GETTER("outbounddetail.example.contactAdd"),"contactAdd",false);
	}

	//�����ҳ��ѯ�ӿ�
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET,"/inventory-manager/query-outbound-detail",
		queryOutboundDetail,OutboundDetailQuery,execQueryOutboundDetail(query,authObject->getPayload()));


	// ����������ϸ �����ˣ��Ǹ����
	ENDPOINT_INFO(exportOutboundDetails) {
	// ����ӿڱ���
	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("outbounddetail.controller.export.summary"));	//Ŀ¼��.controller.������.summary
	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	API_DEF_ADD_AUTH();
	// ������Ӧ������ʽ	
	API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/inventory-manager/export-outbound-details", 
		exportOutboundDetails, BODY_DTO(List<ExportOutboundDetailsDTO::Wrapper>, dto), execExportOutboundDetails(dto, authObject->getPayload()));

private:
	// �ڴ���Ӷ���
	OutboundDetailPageJsonVO::Wrapper execQueryOutboundDetail(const OutboundDetailQuery::Wrapper query,const PayloadDTO& payload);						//��ѯ������ϸ    �����ˣ��Ǹ����
	StringJsonVO::Wrapper execExportOutboundDetails(const List<ExportOutboundDetailsDTO::Wrapper> outboundDetailQuery, const PayloadDTO& payload);		// ���������ϸ	  �����ˣ��Ǹ����
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // OUTBOUNDDETAILCONTROLLER_H__
