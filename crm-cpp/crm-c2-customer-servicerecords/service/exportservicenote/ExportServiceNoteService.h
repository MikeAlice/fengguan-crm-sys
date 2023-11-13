#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huipaodeyu
 @Date: 2023/10/25 10:36:07

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
#ifndef _EXPORTSERVICENOTE_SERVICE_
#define _EXPORTSERVICENOTE_SERVICE_
#include <list>
#include<time.h>
#include "domain/dto/service/ServiceBaseDTO.h"
#include "domain/dto/service/ServiceDetailDTO.h"
#include "domain/query/exportservicenote/ExportServiceNoteQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include"dao/exportservicenote/ExportServiceNoteDAO.h"
#include"domain/do/service/ServiceDO.h"
/**
 * 导出服务信息实现
 */
class ExportServiceNoteService
{
public:


	/*
* 负责人：会跑的鱼
* 功能：根据条件查询服务记录信息
* @param const ExportServiceNoteQuery::Wrapper&  导出服务记录查询条件
* @return list<ListServiceNoteDTO::Wrapper>  导出服务记录的DTO集合
*/
	list<ServiceDetailDTO::Wrapper> listAll(const ExportServiceNoteQuery::Wrapper& query);

	/*
	* 负责人：会跑的鱼
	* 功能：将服务记录信息保存为Excel文件上传到FastDFS文件服务器
	* @param list<ListServiceNoteDTO::Wrapper>&  导出服务记录信息的DTO集合
	* @return string  上传文件的路径，为空则表示上传失败
	*/
	String uploadExportFile(list<ServiceDetailDTO::Wrapper>& dto);


};

#endif // !_EXPORTSERVICENOTE_SERVICE_