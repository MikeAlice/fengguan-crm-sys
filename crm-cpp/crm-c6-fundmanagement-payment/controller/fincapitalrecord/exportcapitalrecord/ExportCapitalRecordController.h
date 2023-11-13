//#pragma once
//#pragma once
//
//#ifndef _EXPORT_CAPITAL_RECORD_CONTROLLER_H_
//#define _EXPORT_CAPITAL_RECORD_CONTROLLER_H_
//#include "domain/vo/BaseJsonVO.h"
//#include "ApiHelper.h"
//#include "Macros.h"
//#include "ServerInfo.h"
//#include "domain/query/capitalRecordFile/ExportCapitalRecordQuery.h"
//
//#include OATPP_CODEGEN_BEGIN(ApiController)
//class ExportCapitalRecordController : public oatpp::web::server::api::ApiController
//{
//	// ����������������
//	API_ACCESS_DECLARE(ExportCapitalRecordController);
//public:// ����ӿ�
//	// ���嵼�����ݽӿ�	�����ˣ�����
//	ENDPOINT(API_M_GET, "/payment/invoice/export", queryCaptalRecordFile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
//		// ������ѯ����ΪQuery����ģ��
//		API_HANDLER_QUERY_PARAM(capitalRecordQuery, ExportCapitalRecordQuery, queryParams);
//		// ����ִ�к�����Ӧ���
//		API_HANDLER_RESP_VO(execExportCapitalRecord(capitalRecordQuery, authObject->getPayload()));
//	}
//	// ���嵼�����ݽӿ�����
//	ENDPOINT_INFO(queryCaptalRecordFile) {
//		// ����ӿڱ���
//		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_capital_record.controller.export"));
//		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
//		API_DEF_ADD_AUTH();
//		// ������Ӧ������ʽ
//		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
//		// ����������ѯ��������
//		/*API_DEF_ADD_QUERY_PARAMS(Int64, "record_id", ZH_WORDS_GETTER("fin_capital_record.field.record_id"), 1, false);
//		API_DEF_ADD_QUERY_PARAMS(Int64, "type_id", ZH_WORDS_GETTER("fin_capital_record.field.type_id"), 1, false);
//		API_DEF_ADD_QUERY_PARAMS(Int64, "create_user_id", ZH_WORDS_GETTER("fin_capital_record.field.create_user_id"), 1, false);
//		API_DEF_ADD_QUERY_PARAMS(UInt64, "bank_id", ZH_WORDS_GETTER("fin_capital_record.field.bank_id"), 1, false);
//		API_DEF_ADD_QUERY_PARAMS(Int64, "money", ZH_WORDS_GETTER("fin_capital_record.field.money"), 1, false);
//		*/API_DEF_ADD_QUERY_PARAMS(String, "intro", ZH_WORDS_GETTER("fin_capital_record.field.intro"), "hello1", false);
//		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("fin_capital_record.field.create_time"), "hello2", false);
//		API_DEF_ADD_QUERY_PARAMS(String, "happen_date", ZH_WORDS_GETTER("fin_capital_record.field.happen_date"), "hello3", false);
//
//	}
//	// ���嵼��ͻ��ӿ�	�����ˣ�����
//	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/payment/capital/delete", deleteCapitalRecordFile, BODY_STRING(String, filePath), execDeleteCapitalRecordFile(filePath, authObject->getPayload()));
//	// ���嵼��ͻ��ӿ�����
//	ENDPOINT_INFO(deleteCapitalRecordFile) {
//		// ����ӿڱ���
//		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_capital_record.controller.deletefile"));
//		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
//		API_DEF_ADD_AUTH();
//		// ������Ӧ������ʽ
//		API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
//	}
//private:
//	/**
//	 * �����ˣ�����
//	 * ���������������ݱ���ΪExcel�ļ����ϴ����ļ�������������·�����͵�ǰ��
//	 * @param�� ExportCapitalRecordQuery::Wrapper   ɸѡ����
//	 *			PayloadDTO&
//	 *			@return�� StringJsonVO  �����ļ�·��
//	 */
//	StringJsonVO::Wrapper execExportCapitalRecord(ExportCapitalRecordQuery::Wrapper query, const PayloadDTO& playload);
//	/*
//	* �����ˣ� ����
//	* �������������ļ��������ϵĵ����ͻ�Excel����ļ�ɾ��
//	* @param�� filepath   Ҫɾ���ļ���·��
//	* @return�� BooleanJsonVO  ����ִ�н��
//	*/
//	BooleanJsonVO::Wrapper execDeleteCapitalRecordFile(String filePath, const PayloadDTO& playload);
//};
//
//#include OATPP_CODEGEN_END(ApiController)
//#endif
