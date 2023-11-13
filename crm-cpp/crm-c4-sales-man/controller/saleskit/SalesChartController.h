#pragma once

#ifndef _SALESCHART_CONTROLLER_
#define _SALESCHART_CONTROLLER_

#include"domain/vo/BaseJsonVO.h"
#include"domain/dto/saleskit/SalesChartDTO.h"
#include"domain/vo/saleskit/SalesChartVO.h"
#include"domain/query/saleskit/SalesChartQuery.h"

#include"domain/dto/saleskit/NumberCountingDTO.h"
#include"domain/vo/saleskit/NumberCountingVO.h"
#include"domain/query/saleskit/NumberCountingQuery.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class SalesChartController :public oatpp::web::server::api::ApiController //1.�̳п�����
{
	//2.����������������
	API_ACCESS_DECLARE(SalesChartController);
	//3.����ӿ�
public:
	//�����ȡ���۰�ӿ�����
	ENDPOINT_INFO(querySalesChart) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sales-chart.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(SalesChartJsonVO);
		//�����������
		//API_DEF_ADD_QUERY_PARAMS(String, "date", ZH_WORDS_GETTER("count-num.field.time-slot"), ZH_WORDS_GETTER("time.this-week"), false);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "date_id", ZH_WORDS_GETTER("count-num.field.time-slot"), 1, false);
	}
	//eg: API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("sales-chart.query.summary"), querySalesChart, Uint64JsonVO::Wrapper);

	//�����ȡ���۰�ӿڴ���
	//�����ѯ�˵�
	/*
	ENDPOINT(API_M_GET, "/querySalesChart", querySalesChart, QUERIES(QueryParams, params)) {
		//������ѯ����
		API_HANDLER_QUERY_PARAM(query, SalesChartQuery, params);
		//��Ӧ���������ִ�к�����
		API_HANDLER_RESP_VO(execQuerySalesChart(query));
	}
	*/
	API_HANDLER_ENDPOINT(API_M_GET, "/crm-c4-sales-man/querySalesChart", querySalesChart, QUERY(UInt64, date_id), execQuerySalesChart(date_id));
	//API_HANDLER_ENDPOINT(API_M_DEL, "/querySalesChart", querySalesChart, BODY_DTO(SalesChartQuery::Wrapper, dto), execQuerySalesChart(dto));

	// ��������ͳ�ƽӿ�����
	ENDPOINT_INFO(queryNumberCounting) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("count-num.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(NumberCountingJsonVO);
		//�����������
		//API_DEF_ADD_QUERY_PARAMS(String, "date", ZH_WORDS_GETTER("count-num.field.time-slot"), ZH_WORDS_GETTER("time.this-week"), false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "date_id", ZH_WORDS_GETTER("count-num.field.time-slot"), 1, false);
	}

	//��������ͳ�Ʋ�ѯ�˵㣨����
	/*
	ENDPOINT(API_M_GET, "/queryNumberCounting", queryNumberCounting, QUERIES(QueryParams, params)) {
		//������ѯ����
		API_HANDLER_QUERY_PARAM(query, NumberCountingQuery, params);
		//��Ӧ���������ִ�к�����
		API_HANDLER_RESP_VO(execQueryNumberCounting(query));
	}
	*/

	API_HANDLER_ENDPOINT(API_M_GET, "/crm-c4-sales-man/queryNumberCounting", queryNumberCounting, QUERY(UInt64, date_id), execQueryNumberCounting(date_id));

private://����ӿں���
	// ��ѯ���۰�
	SalesChartJsonVO::Wrapper execQuerySalesChart(const UInt64& date_id);
	// ��ѯ����ͳ��
	NumberCountingJsonVO::Wrapper execQueryNumberCounting(const UInt64& date_id);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif //!_SALESCHART_CONTROLLER