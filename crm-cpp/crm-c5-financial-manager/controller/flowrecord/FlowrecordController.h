#ifndef FLOWRECORDCONTROLLER_H__
#define FLOWRECORDCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/flowrecord/FlowrecordDTO.h"
#include "domain/vo/flowrecord/FlowrecordPageJsonVO.h"
#include "domain/query/flowrecord/FlowrecordQuery.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Flowrecord��������������ˮ��¼
 * �����ˣ����̾־ֳ�
 */
class FlowrecordController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(FlowrecordController);
	// 3 ����ӿ�
public:
	// ��ҳ��ѯ��ˮ��¼ �����ˣ����̾־ֳ�
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/financial-manager/query-flowrecord", queryFlowrecord, FlowrecordPageQuery, execQueryFlowrecord(query, authObject->getPayload()));
	
	ENDPOINT_INFO(queryFlowrecord) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("flowrecord.controller.query.summary"));	//Ŀ¼��.controller.������.summary
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(FlowrecordPageJsonVO);
		//�����ҳ����
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "bank_id", ZH_WORDS_GETTER("flowrecord.field.bank_id"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(Float64, "income", ZH_WORDS_GETTER("flowrecord.field.income"), , false);
		//API_DEF_ADD_QUERY_PARAMS(Float64, "expenditure", ZH_WORDS_GETTER("flowrecord.field.expenditure"),, false);
		//API_DEF_ADD_QUERY_PARAMS(Float64, "surplus", ZH_WORDS_GETTER("flowrecord.field.surplus"), , false);
		//API_DEF_ADD_QUERY_PARAMS(String, "type", ZH_WORDS_GETTER("flowrecord.field.type"),u8"", false);
		API_DEF_ADD_QUERY_PARAMS(String, "connect_id", ZH_WORDS_GETTER("flowrecord.field.connect_id"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "create_user", ZH_WORDS_GETTER("flowrecord.field.create_user"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("flowrecord.field.create_time"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(Int32, "total_income", ZH_WORDS_GETTER("flowrecord.field.total_income"), 100, false);
		//API_DEF_ADD_QUERY_PARAMS(Int32, "total_expenditure", ZH_WORDS_GETTER("flowrecord.field.total_expenditure"), 100, false);
	}

	//������ˮ��¼ �����ˣ����̾־ֳ�
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/financial-manager/export-flowrecord",exportFlowrecord, BODY_DTO(List<FlowrecordExportDTO::Wrapper>, dto), execExportFlowrecord(dto, authObject->getPayload()));
	//API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/financial-manager/query-flowrecord", exportFlowrecord, FlowrecordPageQuery, execExportFlowrecord(query, authObject->getPayload()));
	
	ENDPOINT_INFO(exportFlowrecord) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("flowrecord.controller.export.summary"));	//Ŀ¼��.controller.������.summary
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
	}

private:
	// �ڴ���Ӷ���

	FlowrecordPageJsonVO::Wrapper execQueryFlowrecord(const FlowrecordPageQuery::Wrapper& query, const PayloadDTO& payload); // ��ȡ��ˮ��¼ �����ˣ����̾־ֳ�
	StringJsonVO::Wrapper execExportFlowrecord(const List<FlowrecordExportDTO::Wrapper>& dto, const PayloadDTO& payload);  // ������ˮ��¼ �����ˣ����̾־ֳ�
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif 