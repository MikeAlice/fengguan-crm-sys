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

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class DeleteRecordsController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeleteRecordsController);
	// 3 ����ӿ�
public:
	// ������ټ�¼ɾ���ӿ�����
	ENDPOINT_INFO(recordDelete) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("trace.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("record.field.id"), 1, true);
	}
	// ������ټ�¼ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/crm-c4-sales-man/record/{id}", recordDelete, PATH(UInt64, id), execRecordDelete(id));

	// ����һ�����ټ�¼�б��ļ����ؽӿ�
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("trace.download.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "recordsfilename", ZH_WORDS_GETTER("file.field.filename"), "file/test.xls", true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/crm-c4-sales-man/recordsfile/download", downloadFile, QUERY(String, recordsfilename)) {
		return execDownloadFile(recordsfilename);
	}
private:
	// ִ�и��ټ�¼ɾ������
	Uint64JsonVO::Wrapper execRecordDelete(const UInt64& id);
	// ִ�и��ټ�¼�ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
