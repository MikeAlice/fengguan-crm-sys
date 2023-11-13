#ifndef OUT_STOCKCONTROLLER_H__
#define OUT_STOCKCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/out_stock/Out_StockPageJsonVO.h"
#include "domain/query/out_stock/Out_StockQuery.h"
#include "domain/dto/out_stock/Out_stockDTO.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Out_Stock������������������ϸ
 */
class Out_StockController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(Out_StockController);
	// 3 ����ӿ�
public:
	// ��ҳ��ѯ�����б� �����ˣ�С��
	ENDPOINT_INFO(queryOut_Stock) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("out_stock.controller.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Out_StockPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(Int32, "out_stock_id", ZH_WORDS_GETTER("out_stock.field.out_stock_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "number", ZH_WORDS_GETTER("out_stock.field.number"), 5, false);
		API_DEF_ADD_QUERY_PARAMS(String, "out_time", ZH_WORDS_GETTER("out_stock.field.out_time"), String(ZH_WORDS_GETTER("out_stock.example.out_time")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "remarks", ZH_WORDS_GETTER("out_stock.field.remarks"), String(ZH_WORDS_GETTER("out_stock.example.remarks")), false);
		//API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("out_stock.field.supplier_name"), String(ZH_WORDS_GETTER("out_stock.example.supplier_name")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "out_stock_person", ZH_WORDS_GETTER("out_stock.field.out_stock_person"), String(ZH_WORDS_GETTER("out_stock.example.out_stock_person")), false);
		API_DEF_ADD_QUERY_PARAMS(Int32, "status", ZH_WORDS_GETTER("out_stock.field.status"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "out_type", ZH_WORDS_GETTER("out_stock.field.out_type"), String(ZH_WORDS_GETTER("out_stock.example.out_type")), false);	
	}
	ENDPOINT(API_M_GET, "inventory-manager/query-out-stock", queryOut_Stock, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, Out_StockQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryOut_Stock(userQuery, authObject->getPayload()));
	}

	//��ӳ��ⵥ �����ˣ�С��
	ENDPOINT_INFO(addOutStock) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("out_stock.controller.get.summary1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/inventory-manager/add-out_stock", addOutStock, BODY_DTO(AddOut_stock::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddOutStock(dto));
	}
	
	//��ȡ���ⵥ��ϸ �����ˣ�С��
	ENDPOINT_INFO(queryOut_StockDetails) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("out_stock.controller.get.summary2"), Out_StockJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("out_stock.field.id"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/inventory-manager/out-stock-details", queryOut_StockDetails, QUERY(String, id), execQueryOut_StockDetails(id, authObject->getPayload()));

private:
	// �ڴ���Ӷ���
	Out_StockPageJsonVO::Wrapper execQueryOut_Stock(const Out_StockQuery::Wrapper& query, const PayloadDTO& payload); // ��ҳ��ѯ���ⵥ�б� ������:С��
	Uint64JsonVO::Wrapper execAddOutStock(const AddOut_stock::Wrapper& dto);//��ӳ��ⵥ �����ˣ�С��
	Out_StockJsonVO::Wrapper execQueryOut_StockDetails(const String& id, const PayloadDTO& payload); //��ȡ���ⵥ��ϸ �����ˣ�С��
	
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif //OUT_STOCKCONTROLLER_H__
