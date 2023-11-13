/*
 Copyright ruodi. All rights reserved.

 @Author: ruodi
 @Date: 2023/10/21
 @FileName:InventoryListController.h
 @version:1.0

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef INVENTORTLISTCONTROLLER_H__
#define INVENTORTLISTCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/inventorylist/InventoryListPageJsonVO.h"
#include "domain/query/inventorylist/InventoryListQuery.h"
#include "domain/dto/inventorylist/InventorylistDTO.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * inventorylist����������ȡ����б�
 */
class InventoryListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(InventoryListController);
	// 3 ����ӿ�
public:
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/inventory-manager/query-inventory-list", queryinventoryList, InventoryListPageQuery, execQueryInventoryList(query, authObject->getPayload()));
	// ��ҳ��ѯ���� �����ˣ�����
	ENDPOINT_INFO(queryinventoryList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("inventorylist.controller.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(InventoryListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "goods_id", ZH_WORDS_GETTER("inventorylist.field.goods_id"), 14, false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "sku_id", ZH_WORDS_GETTER("inventorylist.field.sku_id"), 28, false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("inventorylist.field.goods_name"), String(ZH_WORDS_GETTER("inventorylist.example.goods_name")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "sku_name", ZH_WORDS_GETTER("inventorylist.field.sku_name"), String(ZH_WORDS_GETTER("inventorylist.example.sku_name")), false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "number", ZH_WORDS_GETTER("inventorylist.field.number"), 5, false);
		API_DEF_ADD_QUERY_PARAMS(String, "category_name", ZH_WORDS_GETTER("inventorylist.field.category_name"), String(ZH_WORDS_GETTER("inventorylist.example.category_name")), false);
		API_DEF_ADD_QUERY_PARAMS(String, "store_name", ZH_WORDS_GETTER("inventorylist.field.store_name"), String(ZH_WORDS_GETTER("inventorylist.example.store_name")), false);

		API_DEF_ADD_QUERY_PARAMS(Float32, "sale_price", ZH_WORDS_GETTER("inventorylist.field.sale_price"), 88.88, false);
		API_DEF_ADD_QUERY_PARAMS(Float32, "cost_price", ZH_WORDS_GETTER("inventorylist.field.cost_price"), 66.66, false);
		API_DEF_ADD_QUERY_PARAMS(Float32, "anticipated_profit", ZH_WORDS_GETTER("inventorylist.field.anticipated_profit"), 99.98, false);
		API_DEF_ADD_QUERY_PARAMS(String, "Original_code", ZH_WORDS_GETTER("inventorylist.field.Original_code"), String(ZH_WORDS_GETTER("inventorylist.example.Original_code")), false);
		//�������� ����

	}

	// �������� �����ˣ�����
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/inventory-manager/export-inventory-list", exportInventoryList, BODY_DTO(List<ExportInventoryList::Wrapper>, dto), execExportInventoryList(dto, authObject->getPayload()));
	ENDPOINT_INFO(exportInventoryList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("inventorylist.controller.export.summary"));	//Ŀ¼��.controller.������.summary
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

	}
private:
	// �ڴ���Ӷ���
	InventoryListPageJsonVO::Wrapper execQueryInventoryList(const InventoryListPageQuery::Wrapper& inventorylistQuery, const PayloadDTO& payload);		// ��ҳ��ȡ����б� �����ˣ�����
	StringJsonVO::Wrapper execExportInventoryList(const List<ExportInventoryList::Wrapper>& inventorylistExport, const PayloadDTO& payload);		// ��������б�		�����ˣ�����
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // STORAGEDETAILSCONTROLLER_H__

