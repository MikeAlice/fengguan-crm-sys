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
#include "domain/dto/fincapitalrecord/ExportCapitalRecordDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
class ExportCapitalRecordController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ExportCapitalRecordController);
public:// 定义接口
	// 定义导出数据接口	负责人：超能
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/fin_capital_record/export-data", exportCapitalRecord, BODY_DTO(List<ExportCapitalRecordDTO::Wrapper>, dto), execExportCapitalRecord(dto, authObject->getPayload()));
	// 定义导出数据接口描述
	ENDPOINT_INFO(exportCapitalRecord) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("fin_capital_record.controller.export.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	
private:
	// 将数据保存为Excel文件，上传到文件服务器，并将路径发送到前端	负责人：超能
	StringJsonVO::Wrapper execExportCapitalRecord(const List<ExportCapitalRecordDTO::Wrapper>& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)
#endif
