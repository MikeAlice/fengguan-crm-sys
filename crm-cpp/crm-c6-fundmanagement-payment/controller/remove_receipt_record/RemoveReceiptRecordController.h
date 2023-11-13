#pragma once
/*
 @Author: linglan
 @Date: 2023/10/25 20:28:11

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
#ifndef _REMOVERECEIPTRECORDCONTROLLER_H_
#define _REMOVERECEIPTRECORDCONTROLLER_H_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "Macros.h"
#include "domain/vo/remove_receipt_record/ReceiptRecordJsonVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

//删除收票记录（可批量） 负责人：灵岚
class RemoveReceiptRecordController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(RemoveReceiptRecordController);
public:// 定义接口
	//定义端点描述
	ENDPOINT_INFO(removeReceiptRecord)
	{
		// 该端点的描述信息
		info->summary = u8"删除收票记录（可批量）";
		//添加安全验证
		API_DEF_ADD_AUTH();

		// 定义其他查询参数描述(请求)
		// 收票记录编号
		//info->pathParams.add<List<UInt64>>("record_id").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "receiptRecord.field.record_id"); info->pathParams["record_id"].addExample("default", List<UInt64>({ 1,2,3 })); info->pathParams["record_id"].required = true;
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ReceiptRecordJsonVO);//PaymentPlanPageJsonVO为返回值，与executeQueryTest返回值类型一致
	}

	// 定义定义删除接口端点处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/payment/receipt-record/{record_id}", removeReceiptRecord, BODY_DTO(ReceiptRecordDTO::Wrapper, record_id), execRemoveReceiptRecord(record_id));

private: // 定义接口执行函数

	// 查询所有
	ReceiptRecordJsonVO::Wrapper execRemoveReceiptRecord(const ReceiptRecordDTO::Wrapper& recordIds);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_REMOVERECEIPTRECORDCONTROLLER_H_