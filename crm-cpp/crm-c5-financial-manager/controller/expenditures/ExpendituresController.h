/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/19
 @FileName:ExpendituresController
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

#ifndef EXPENDITURESCONTROLLER_H__
#define EXPENDITURESCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/expenditures/ExpendituresDTO.h"
#include "domain/query/expenditures/ExpendituresQuery.h"
#include "domain/vo/expendituresquery/ExpendituresQueryPageJsonVO.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Expenditures����������������֧����
 * �����ˣ��������Ǹ����
 */
class ExpendituresController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ExpendituresController);
	// 3 ����ӿ�
public:
	// ɾ�����ݣ�֧������ɾ���� �����ˣ�����
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/financial-manager/delete-expenditures-invoices", deleteInvoices, BODY_DTO(List<DelExpendituresDTO::Wrapper>, dto), execDeleteInvoices(dto, authObject->getPayload()));
	ENDPOINT_INFO(deleteInvoices) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expenditures.controller.delete.summary"));	//Ŀ¼��.controller.������.summary
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	// �������� �����ˣ�����
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/financial-manager/export-expenditures-invoices", exportInvoices, BODY_DTO(List<ExportExpenditures::Wrapper>, dto), execExportInvoices(dto, authObject->getPayload()));
	ENDPOINT_INFO(exportInvoices) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expenditures.controller.export.summary"));	//Ŀ¼��.controller.������.summary
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		/*
		// �������������
		info->queryParams.add<String>("type").description = ZH_WORDS_GETTER("expenditures.field.type");
		info->queryParams["type"].addExample("default", String(ZH_WORDS_GETTER("expenditures.example.type")));
		info->queryParams["type"].required = false;

		info->queryParams.add<String>("money").description = ZH_WORDS_GETTER("expenditures.field.money");
		info->queryParams["money"].addExample("default", String("100"));
		info->queryParams["money"].required = false;

		info->queryParams.add<String>("bank").description = ZH_WORDS_GETTER("expenditures.field.bank");
		info->queryParams["bank"].addExample("default", String(ZH_WORDS_GETTER("expenditures.example.bank")));
		info->queryParams["bank"].required = false;

		info->queryParams.add<String>("latest_happen_date").description = ZH_WORDS_GETTER("expenditures.field.latest_happen_date");
		info->queryParams["latest_happen_date"].addExample("default", String("30"));
		info->queryParams["latest_happen_date"].required = false;
		
		info->queryParams.add<String>("latest_create_time").description = ZH_WORDS_GETTER("expenditures.field.latest_create_time");
		info->queryParams["latest_create_time"].addExample("default", String("30"));
		info->queryParams["latest_create_time"].required = false;

		info->queryParams.add<String>("create_user").description = ZH_WORDS_GETTER("expenditures.field.create_user");
		info->queryParams["create_user"].addExample("default", String(ZH_WORDS_GETTER("expenditures.example.create_user")));
		info->queryParams["create_user"].required = false;

		info->queryParams.add<String>("intro").description = ZH_WORDS_GETTER("expenditures.field.intro");
		info->queryParams["intro"].addExample("default", String(ZH_WORDS_GETTER("expenditures.example.intro")));
		info->queryParams["intro"].required = false;
		*/
	}

	//�������� �����ˣ��Ǹ����
	ENDPOINT_INFO(addInvoices) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expenditures.controller.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/financial-manager/add-expenditures-invoices", addInvoices,
		BODY_DTO(AddExpendituresDTO::Wrapper, dto), execAddInvoices(dto, authObject->getPayload()));

	//��ȡ�����б� �����ˣ��Ǹ����
	ENDPOINT_INFO(queryInvoices) {
	//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expenditures.controller.query.summary"));
		//����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpendituresPageJsonVO);
		//�����ҳ����
		API_DEF_ADD_PAGE_PARAMS();
		//�����ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String,"bank",ZH_WORDS_GETTER("expenditures.field.bank"),"bank", false);
		API_DEF_ADD_QUERY_PARAMS(Int32,"latest_happen_date",ZH_WORDS_GETTER("expenditures.field.latest_happen_date"),30,false);
		API_DEF_ADD_QUERY_PARAMS(Int32,"latest_create_time",ZH_WORDS_GETTER("expenditures.field.latest_create_time"),30,false);
		API_DEF_ADD_QUERY_PARAMS(Int32,"money",ZH_WORDS_GETTER("expenditures.field.money"),0,false);
		API_DEF_ADD_QUERY_PARAMS(String,"intro",ZH_WORDS_GETTER("expenditures.field.intro"),"intro", false);
	}
	
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "financial-manager/query-invoices",
		queryInvoices, ExpendituresPageQuery, execQueryInvoices(query));
private:
	// �ڴ���Ӷ���
	Uint64JsonVO::Wrapper execDeleteInvoices(const List<DelExpendituresDTO::Wrapper>& dto, const PayloadDTO& payload);	//ɾ�����ݣ�֧������ɾ����  �����ˣ�����
	StringJsonVO::Wrapper execExportInvoices(const List<ExportExpenditures::Wrapper>& dto, const PayloadDTO& payload);	//��������					�����ˣ�����
	ExpendituresPageJsonVO::Wrapper execQueryInvoices(const ExpendituresPageQuery::Wrapper query);			//��ȡ�����б� �����ˣ��Ǹ����
	Uint64JsonVO::Wrapper execAddInvoices(const AddExpendituresDTO::Wrapper dto, const PayloadDTO& payload);//��������	   �����ˣ��Ǹ����
};



// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // EXPENDITURESCONTROLLER_H__