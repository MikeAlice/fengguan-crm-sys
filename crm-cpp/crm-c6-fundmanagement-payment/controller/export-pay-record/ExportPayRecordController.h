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
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

/***
 * 导出付款记录控制器
 ***/
class ExportPayRecordController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ExportPayRecordController);
public:
	// 3 定义接口
	// 3.1 定义导出接口描述
	ENDPOINT_INFO(exportPayRecord) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_pay_record.export.summary"));
		//API_DEF_ADD_TITLE(u8"导出收票记录");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// // 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "record_id", ZH_WORDS_GETTER("fin_pay_record.field.record_id"), "", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "pay_date", ZH_WORDS_GETTER("fin_pay_record.field.pay_date"), "2023-10-1", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("fin_pay_record.field.create_time"), "2023-10-1", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "contract_name", ZH_WORDS_GETTER("fin_pay_record.field.contract_name"), u8"天河一期", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "supplier_name", ZH_WORDS_GETTER("fin_pay_record.field.supplier_name"), u8"上海八达", false);
		//API_DEF_ADD_QUERY_PARAMS(UInt64, "money", ZH_WORDS_GETTER("fin_pay_record.field.money"), 200, false);
	}
	// 3.2 定义导出接口处理
	// 端点(请求方式，请求地址，方法名，查询参数)
	ENDPOINT(API_M_POST, "/payment/pay-record/export", exportPayRecord, BODY_DTO(List<ExportPayRecordDTO::Wrapper>, dto) )
	{
	//	// 解析查询参数为Query领域模型
 	//	// 将参数处理成ExportPayRecordQuery
	//	/* 解析query(参数名，参数类型，解析对象 / 参数)
	//	   将前端传来的表单参数QueryParams装入ExportPayRecordQuery对象 */
	//	API_HANDLER_QUERY_PARAM(query, ExportPayRecordQuery, params);
	//	// 呼叫执行函数响应结果
	//	// 返回文件下载地址
		API_HANDLER_RESP_VO(execExportPayRecord(dto));
	}
private:
	// 定义接口执行函数
	// 3.3 演示导出数据
	StringJsonVO::Wrapper execExportPayRecord(const List<ExportPayRecordDTO::Wrapper>& dto) {
		// 定义返回数据对象
		auto jvo = StringJsonVO::createShared();
		// 参数非空校验
		if (dto->size() == 0)
		{
			jvo->init({}, RS_PARAMS_INVALID);
			return jvo;
		}
		
		//browser → controller → service → dao → sql
		// 定义一个Service
		ExportPayRecordService service;
		// 执行
		std::string expUrl = service.exportPayRecord(dto);
		// 判断执行结果serviceRet，并返回返回数据
		if (expUrl=="")
			jvo->fail(String("export fail"));
		else
			jvo->success(expUrl);
		return jvo;
	}

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPORTPAYRECORDCONTROLLER_H_
//class ExportPayRecordController
//{
//};

