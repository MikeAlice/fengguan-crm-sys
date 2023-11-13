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
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ExportCapitalRecordController);
public:// 定义接口
	// 定义导出数据接口	负责人：超能
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/payment/capital/export", exportCaptalRecord, BODY_DTO(List<ExportCapitalRecordDTO::Wrapper>, dto), execExportCapitalRecord(dto, authObject->getPayload()));
	// 定义导出数据接口描述
	ENDPOINT_INFO(exportCaptalRecord) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("payment.controller.export"));
		//API_DEF_ADD_TITLE(u8"导出收票记录");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("payment.field.record_id"), 1, true);
		/*API_DEF_ADD_QUERY_PARAMS(Int64, "type_id", ZH_WORDS_GETTER("payment.field.type_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Int64, "create_user_id", ZH_WORDS_GETTER("payment.field.create_user_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "bank_id", ZH_WORDS_GETTER("payment.field.bank_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(Int64, "money", ZH_WORDS_GETTER("payment.field.money"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "intro", ZH_WORDS_GETTER("payment.field.intro"), "hello1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("payment.field.create_time"), "hello2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "happen_date", ZH_WORDS_GETTER("payment.field.happen_date"), "hello3", false);*/

	}
	//// 定义删除文件接口	负责人：超能
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/financial-manager/fin-capital-record/delete-customer-file", deleteCapitalRecordFile, BODY_STRING(String, filePath), execDeleteCapitalRecordFile(filePath, authObject->getPayload()));
	//// 定义接口描述
	//ENDPOINT_INFO(deleteCapitalRecordFile) {
	//	// 定义接口标题
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_capital_record.controller.deletefile"));
	//	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	//	API_DEF_ADD_AUTH();
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
	//}
private:
	/**
	 * 负责人：超能
	 * 功能描述：将数据保存为Excel文件，上传到文件服务器，并将路径发送到前端
	 * @param： ExportCapitalRecordQuery::Wrapper   筛选条件
	 *			PayloadDTO&
	 *			@return： StringJsonVO  返回文件路径
	 */
	StringJsonVO::Wrapper execExportCapitalRecord(const List<ExportCapitalRecordDTO::Wrapper>& dto, const PayloadDTO& payload);
	/*
	* 负责人： 超能
	* 功能描述：将文件服务器上的导出客户Excel表格文件删除
	* @param： filepath   要删除文件的路径
	* @return： BooleanJsonVO  返回执行结果
	*/ 
	//BooleanJsonVO::Wrapper execDeleteCapitalRecordFile(String filePath, const PayloadDTO& playload);
};

#include OATPP_CODEGEN_END(ApiController)
#endif
