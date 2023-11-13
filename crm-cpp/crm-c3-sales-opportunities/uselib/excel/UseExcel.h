#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/25 23:17:52

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
#ifndef _USEEXCEL_H_
#define _USEEXCEL_H_

#include <vector>
#include <string>
#include "ExcelComponent.h"

/**
 * Excel�����ʹ�ð�װ��
 * ������: Andrew
 */
class UseExcel
{
private:
	ExcelComponent excel; // Excel ���
public:
	/*template <typename T>
	std::vector<std::vector<std::string>> constructData(const std::list<std::string>& header, const std::list<T>& data);*/

	/**
	 * ���浽Excel�ļ�
	 * @param data: ��Ҫ���������
	 * @param sheet: ���浽Excel�����ݱ���, Ĭ��Ϊ'���ݱ�1'
	 * @return std::string: ���ر�����ļ���
	 */
	std::string saveToExcel(const std::vector<std::vector<std::string>>& data, const std::string& sheet = "���ݱ�1");
	/**
	 * ��Excel�ļ��ж�ȡ
	 * @param fileName: ��ȡ���ļ���
	 * @param sheet: ��ȡ��Excel�����ݱ���, Ĭ��Ϊ'���ݱ�1'
	 * @return std::vector<std::vector<std::string>>: ���ض�ȡ����������
	 */
	std::vector<std::vector<std::string>> readFromExcel(const std::string& fileName, const std::string& sheetName);
};

#endif // !_USEEXCEL_H_