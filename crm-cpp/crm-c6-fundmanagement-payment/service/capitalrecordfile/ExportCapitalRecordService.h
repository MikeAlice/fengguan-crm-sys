#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2023/10/25
 @FileName: ExportCapitalRecordService
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
#ifndef _EXPORT_CAPITAL_RECORD_SERVICE_
#define _EXPORT_CAPITAL_RECORD_SERVICE_
#include <list>
#include <ctime>
#include "domain/query/capitalRecordFile/ExportCapitalRecordQuery.h"
#include "domain/do/finCapitalRecord/FinCapitalRecordDO.h"
#include "domain/dto/finCapitalRecord/ListCapitalRecordDTO.h"

class ExportCapitalRecordService
{
public:
	/*
	* 负责人：超能
	* 功能：
	* @param const ExportCapitalRecordQuery::Wrapper&  导出查询条件
	* @return list<ListCapitalRecordDTO::Wrapper>  导出信息的DTO集合
	*/
	list<ListCapitalRecordDTO::Wrapper> listAll(const ExportCapitalRecordQuery::Wrapper& query);

	/*
	* 负责人：超能
	* 功能：将信息保存为Excel文件上传到FastDFS文件服务器
	* @param list<ListCapitalRecordDTO::Wrapper>&  导出信息的DTO集合
	* @return string  上传文件的路径，为空则表示上传失败
	*/
	string uploadExportFile(list<ListCapitalRecordDTO::Wrapper>& dto);

	/*
	* 负责人： 超能
	* 功能描述：将文件服务器上的导出文件删除
	* @param： filepath   要删除文件的路径
	* @return： Boolean  返回执行结果
	*/
	bool deleteExportFile(string filePath);
};

#endif