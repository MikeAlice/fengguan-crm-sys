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
 * ����������Ϣʵ��
 */
class ExportServiceNoteService
{
public:


	/*
* �����ˣ����ܵ���
* ���ܣ�����������ѯ�����¼��Ϣ
* @param const ExportServiceNoteQuery::Wrapper&  ���������¼��ѯ����
* @return list<ListServiceNoteDTO::Wrapper>  ���������¼��DTO����
*/
	list<ServiceDetailDTO::Wrapper> listAll(const ExportServiceNoteQuery::Wrapper& query);

	/*
	* �����ˣ����ܵ���
	* ���ܣ��������¼��Ϣ����ΪExcel�ļ��ϴ���FastDFS�ļ�������
	* @param list<ListServiceNoteDTO::Wrapper>&  ���������¼��Ϣ��DTO����
	* @return string  �ϴ��ļ���·����Ϊ�����ʾ�ϴ�ʧ��
	*/
	String uploadExportFile(list<ServiceDetailDTO::Wrapper>& dto);


};

#endif // !_EXPORTSERVICENOTE_SERVICE_