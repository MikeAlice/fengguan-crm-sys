#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _ExportTrackingRecords_CONTROLLER_
#define _ExportTrackingRecords_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/dto/records/recordDTO.h"
#include "domain/vo/recordsfile/FileVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * 示例控制器，演示基础接口的使用
 */
class DeleteRecordsController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DeleteRecordsController);
	// 3 定义接口
public:
	// 定义跟踪记录删除接口描述
	ENDPOINT_INFO(recordDelete) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("trace.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("record.field.id"), 1, true);
	}
	// 定义跟踪记录删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/crm-c4-sales-man/record/{id}", recordDelete, PATH(UInt64, id), execRecordDelete(id));

	// 定义一个跟踪记录列表文件下载接口
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("trace.download.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "recordsfilename", ZH_WORDS_GETTER("file.field.filename"), "file/test.xls", true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/crm-c4-sales-man/recordsfile/download", downloadFile, QUERY(String, recordsfilename)) {
		return execDownloadFile(recordsfilename);
	}
private:
	// 执行跟踪记录删除处理
	Uint64JsonVO::Wrapper execRecordDelete(const UInt64& id);
	// 执行跟踪记录文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
