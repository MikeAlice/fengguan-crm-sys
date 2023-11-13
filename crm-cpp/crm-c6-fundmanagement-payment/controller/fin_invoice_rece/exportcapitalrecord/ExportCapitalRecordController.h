#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/24
 @FileName: ExportCapitalRecordController
 @version: 1.0

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
#ifndef _EXPORT_CAPITAL_RECORD_CONTROLLER_H_
#define _EXPORT_CAPITAL_RECORD_CONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/dto/fin_invoice_rece/ExportCapitalRecordDTO.h"
#include "domain/query/export_fin_invoice_recefile/ExportCapitalRecordQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
class ExportCapitalRecordController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ExportCapitalRecordController);
public:// ����ӿ�
	// ���嵼�����ݽӿ�	�����ˣ�����
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/payment/capital/export", exportCaptalRecord, BODY_DTO(List<ExportCapitalRecordDTO::Wrapper>, dto), execExportCapitalRecord(dto, authObject->getPayload()));
	// ���嵼�����ݽӿ�����
	ENDPOINT_INFO(exportCaptalRecord) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("payment.controller.export"));
		//API_DEF_ADD_TITLE(u8"������Ʊ��¼");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("payment.field.record_id"), 1, true);
		/*API_DEF_ADD_QUERY_PARAMS(Int64, "type_id", ZH_WORDS_GETTER("payment.field.type_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Int64, "create_user_id", ZH_WORDS_GETTER("payment.field.create_user_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "bank_id", ZH_WORDS_GETTER("payment.field.bank_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Int64, "money", ZH_WORDS_GETTER("payment.field.money"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "intro", ZH_WORDS_GETTER("payment.field.intro"), "hello1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("payment.field.create_time"), "hello2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "happen_date", ZH_WORDS_GETTER("payment.field.happen_date"), "hello3", false);*/

	}
	//// ����ɾ���ļ��ӿ�	�����ˣ�����
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/financial-manager/fin-capital-record/delete-customer-file", deleteCapitalRecordFile, BODY_STRING(String, filePath), execDeleteCapitalRecordFile(filePath, authObject->getPayload()));
	//// ����ӿ�����
	//ENDPOINT_INFO(deleteCapitalRecordFile) {
	//	// ����ӿڱ���
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_capital_record.controller.deletefile"));
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
	//}
private:
	/**
	 * �����ˣ�����
	 * ���������������ݱ���ΪExcel�ļ����ϴ����ļ�������������·�����͵�ǰ��
	 * @param�� ExportCapitalRecordQuery::Wrapper   ɸѡ����
	 *			PayloadDTO&
	 *			@return�� StringJsonVO  �����ļ�·��
	 */
	StringJsonVO::Wrapper execExportCapitalRecord(const List<ExportCapitalRecordDTO::Wrapper>& dto, const PayloadDTO& payload);
	/*
	* �����ˣ� ����
	* �������������ļ��������ϵĵ����ͻ�Excel����ļ�ɾ��
	* @param�� filepath   Ҫɾ���ļ���·��
	* @return�� BooleanJsonVO  ����ִ�н��
	*/ 
	//BooleanJsonVO::Wrapper execDeleteCapitalRecordFile(String filePath, const PayloadDTO& playload);
};

#include OATPP_CODEGEN_END(ApiController)
#endif
