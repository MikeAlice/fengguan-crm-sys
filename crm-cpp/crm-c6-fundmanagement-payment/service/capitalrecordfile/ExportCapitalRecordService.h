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
	* �����ˣ�����
	* ���ܣ�
	* @param const ExportCapitalRecordQuery::Wrapper&  ������ѯ����
	* @return list<ListCapitalRecordDTO::Wrapper>  ������Ϣ��DTO����
	*/
	list<ListCapitalRecordDTO::Wrapper> listAll(const ExportCapitalRecordQuery::Wrapper& query);

	/*
	* �����ˣ�����
	* ���ܣ�����Ϣ����ΪExcel�ļ��ϴ���FastDFS�ļ�������
	* @param list<ListCapitalRecordDTO::Wrapper>&  ������Ϣ��DTO����
	* @return string  �ϴ��ļ���·����Ϊ�����ʾ�ϴ�ʧ��
	*/
	string uploadExportFile(list<ListCapitalRecordDTO::Wrapper>& dto);

	/*
	* �����ˣ� ����
	* �������������ļ��������ϵĵ����ļ�ɾ��
	* @param�� filepath   Ҫɾ���ļ���·��
	* @return�� Boolean  ����ִ�н��
	*/
	bool deleteExportFile(string filePath);
};

#endif