#pragma once
#ifndef _TRACECONTROLLER_H_
#define _TRACECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/trace/AddTraceDTO.h"
#include "domain/dto/trace/ModifyTraceDTO.h"
#include "domain/dto/trace/GetTraceDTO.h"
#include "domain/dto/trace/TraceDTO.h"
#include "domain/dto/trace/ListTraceDTO.h"
#include "domain/vo/trace/GetPageVO.h"
#include "domain/query/trace/TraceQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

#ifndef TRA_PRFIX
#define TRA_PRFIX(_app_) "/crm-c4-sales-man" _app_
#endif 

//���Ӹ��ټ�¼�ӿ�ʵ��
class TraceController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(TraceController);

public:
	// ����ӿ�
	//���Ӹ��ټ�¼
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("trace.add-trace.summary"), addTrace, BooleanJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, TRA_PRFIX("/add-trace"), addTrace, BODY_DTO(AddTraceDTO::Wrapper, dto), execAddTrace(dto, authObject->getPayload()));
	//�޸ĸ��ټ�¼
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("trace.modify-trace.summary"), modifyTrace, BooleanJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, TRA_PRFIX("/modify-trace"), modifyTrace, BODY_DTO(ModifyTraceDTO::Wrapper, dto), execModifyTrace(dto, authObject->getPayload()));

	//��ȡ���ټ�¼
	//�����ѯ�ӿ�����
	ENDPOINT_INFO(queryGet) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("trace.get-trace.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(TracePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "AC", ZH_WORDS_GETTER("trace.field.AC"), "liming", false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "CS", ZH_WORDS_GETTER("trace.field.CS"), 12, false);
		API_DEF_ADD_QUERY_PARAMS(String, "CContent", ZH_WORDS_GETTER("trace.field.CContent"), "GOOD", false);

		/*
		��һ��id�ֶ�(����������������)
		API_DEF_ADD_QUERY_PARAMS(String, "NT", ZH_WORDS_GETTER("trace.field.NT"), "2024.10.23", false);
		*/
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, TRA_PRFIX("/get"), queryGet, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, TraceQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryGet(userQuery, authObject->getPayload()));
	}

	// ������ټ�¼ɾ���ӿ�����
	ENDPOINT_INFO(traceDelete) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("trace.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "trace_id", ZH_WORDS_GETTER("trace.field.trace_id"), 1, true);
	}
	// ������ټ�¼ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/crm-c4-sales-man/delete-trace/{trace_id}", traceDelete, PATH(UInt64, trace_id), execTraceDelete(trace_id));

	// ������ټ�¼����ɾ���ӿ�����
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("trace.delete.list"), traceListDelete, Uint64JsonVO::Wrapper);
	// ������ټ�¼ɾ���ӿڴ���
	API_HANDLER_ENDPOINT(API_M_DEL, "/crm-c4-sales-man/delete-tracelist", traceListDelete, BODY_DTO(ListTraceDTO::Wrapper,dto), execListTraceDelete(dto));

	// ����һ�����ټ�¼�б��ļ����ؽӿ�
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("tracefile.download.summary"));
		//API_DEF_ADD_COMMON("tracefile-download", Void);
	}
	// ����˵�
	ENDPOINT(API_M_GET, TRA_PRFIX("/downloadfile-trace"), downloadFile) {
		return execDownloadFile();
	}

private: // ����ӿ�ִ�к���
	//���Ӹ��ټ�¼
	BooleanJsonVO::Wrapper execAddTrace(const AddTraceDTO::Wrapper& dto, const PayloadDTO& payload);
	//�޸ĸ��ټ�¼
	BooleanJsonVO::Wrapper execModifyTrace(const ModifyTraceDTO::Wrapper& dto, const PayloadDTO& payload);
	//��ҳ
	TracePageJsonVO::Wrapper execQueryGet(const TraceQuery::Wrapper& query, const PayloadDTO& payload);

	//ִ�и��ټ�¼ɾ������
	Uint64JsonVO::Wrapper execTraceDelete(const UInt64& trace_id);
	//ִ���������ټ�¼ɾ������
	Uint64JsonVO::Wrapper execListTraceDelete(const ListTraceDTO::Wrapper& dto);
	// ִ�и��ټ�¼�ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadFile();
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_TRACECONTROLLER_H_