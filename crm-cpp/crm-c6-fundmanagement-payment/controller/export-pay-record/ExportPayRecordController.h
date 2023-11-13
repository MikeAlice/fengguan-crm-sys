#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: kuzuzu
 @Date: 2023/10/27 14:03:54

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
#ifndef _EXPORTPAYRECORDCONTROLLER_H_
#define _EXPORTPAYRECORDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
//#include "domain/query/pay-record/ExportPayRecordQuery.h"
//#include "domain/dto/sample/SampleDTO.h"
//#include "domain/vo/sample/SampleVO.h"
#include "ApiHelper.h"
#include "domain/dto/export-pay-record/ExportPayRecordDTO.h"
#include "service/export-pay-record/ExportPayRecordService.h"
#include "Macros.h"
#include "ServerInfo.h"
//#include "../../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
//#include "Macros.h"
//#include "ServerInfo.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

/***
 * ���������¼������
 ***/
class ExportPayRecordController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ExportPayRecordController);
public:
	// 3 ����ӿ�
	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(exportPayRecord) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_pay_record.export.summary"));
		//API_DEF_ADD_TITLE(u8"������Ʊ��¼");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// // ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//// �����ҳ��ѯ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "record_id", ZH_WORDS_GETTER("fin_pay_record.field.record_id"), "", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "pay_date", ZH_WORDS_GETTER("fin_pay_record.field.pay_date"), "2023-10-1", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("fin_pay_record.field.create_time"), "2023-10-1", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("fin_pay_record.field.contract_name"), u8"���һ��", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("fin_pay_record.field.supplier_name"), u8"�Ϻ��˴�", false);
		//API_DEF_ADD_QUERY_PARAMS(UInt64, "money", ZH_WORDS_GETTER("fin_pay_record.field.money"), 200, false);
	}
	// 3.2 ���嵼���ӿڴ���
	// �˵�(����ʽ�������ַ������������ѯ����)
	ENDPOINT(API_M_POST, "/payment/pay-record/export", exportPayRecord, BODY_DTO(List<ExportPayRecordDTO::Wrapper>, dto) )
	{
	//	// ������ѯ����ΪQuery����ģ��
 	//	// �����������ExportPayRecordQuery
	//	/* ����query(���������������ͣ��������� / ����)
	//	   ��ǰ�˴����ı�����QueryParamsװ��ExportPayRecordQuery���� */
	//	API_HANDLER_QUERY_PARAM(query, ExportPayRecordQuery, params);
	//	// ����ִ�к�����Ӧ���
	//	// �����ļ����ص�ַ
		API_HANDLER_RESP_VO(execExportPayRecord(dto));
	}
private:
	// ����ӿ�ִ�к���
	// 3.3 ��ʾ��������
	StringJsonVO::Wrapper execExportPayRecord(const List<ExportPayRecordDTO::Wrapper>& dto) {
		// ���巵�����ݶ���
		auto jvo = StringJsonVO::createShared();
		// �����ǿ�У��
		if (dto->size() == 0)
		{
			jvo->init({}, RS_PARAMS_INVALID);
			return jvo;
		}
		
		//browser �� controller �� service �� dao �� sql
		// ����һ��Service
		ExportPayRecordService service;
		// ִ��
		std::string expUrl = service.exportPayRecord(dto);
		// �ж�ִ�н��serviceRet�������ط�������
		if (expUrl=="")
			jvo->fail(String("export fail"));
		else
			jvo->success(expUrl);
		return jvo;
	}

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPORTPAYRECORDCONTROLLER_H_
//class ExportPayRecordController
//{
//};

