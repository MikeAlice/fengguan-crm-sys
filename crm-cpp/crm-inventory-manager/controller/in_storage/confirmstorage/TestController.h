#pragma once
#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_
#include "domain/vo/JsonVO.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
class TestController :public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(TestController);
public://����ӿ�
	//������Բ�ѯ�˿�����
	ENDPOINT_INFO(queryTest) {
		//��������
		info->summary = "query test1";
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//�����������
		API_DEF_ADD_PAGE_PARAMS();
	}
	//������Բ�ѯ�˿�
	ENDPOINT(API_M_GET, "/test", queryTest, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(query, PageQuery, params);
		//��Ӧ���
		API_HANDLER_RESP_VO(execQueryTest(query));
	}
private://����ӿ�ִ�к���  
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query) {
		auto result = StringJsonVO::createShared();
		result->success(String("query test"));
		return result;
	}
		
	
};
#include OATPP_CODEGEN_END(ApiController)
#endif // !1

