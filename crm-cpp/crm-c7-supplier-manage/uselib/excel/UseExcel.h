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
 * Excel组件库使用包装类
 * 负责人: Andrew
 */
class UseExcel
{
private:
	ExcelComponent excel; // Excel 组件
public:
	/*template <typename T>
	std::vector<std::vector<std::string>> constructData(const std::list<std::string>& header, const std::list<T>& data);*/

	/**
	 * 保存到Excel文件
	 * @param data: 需要保存的数据
	 * @param sheet: 保存到Excel的数据表名, 默认为'数据表1'
	 * @return std::string: 返回保存的文件名
	 */
	std::string saveToExcel(const std::vector<std::vector<std::string>>& data, const std::string& sheet = "数据表1");
	/**
	 * 从Excel文件中读取
	 * @param fileName: 读取的文件名
	 * @param sheet: 读取的Excel的数据表名, 默认为'数据表1'
	 * @return std::vector<std::vector<std::string>>: 返回读取的数据向量
	 */
	std::vector<std::vector<std::string>> readFromExcel(const std::string& fileName, const std::string& sheetName);
};

#endif // !_USEEXCEL_H_