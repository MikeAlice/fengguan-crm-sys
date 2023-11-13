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
#include "stdafx.h"
#include <iostream>
#include "UseExcel.h"
#include <sstream>
#include "SimpleDateTimeFormat.h"
#include "CharsetConvertHepler.h"

std::string UseExcel::saveToExcel(const std::vector<std::vector<std::string>>& data, const std::string& sheet)
{
	// 定义保存数据位置和页签名称
	std::stringstream ss;
	ss << "./public/excel/";
	ss << SimpleDateTimeFormat::format("%Y%m%d_%H%M%S");
	ss << ".xlsx";
	// 注意：文件件名称和文件路径不能出现中文
	std::string fileName = ss.str();
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要转换编码
	std::string sheetName = CharsetConvertHepler::ansiToUtf8(sheet);

	// 保存到文件
	excel.writeVectorToFile(fileName, sheetName, data);
	return fileName;
}

std::vector<std::vector<std::string>> UseExcel::readFromExcel(const std::string& fileName, const std::string& sheetName)
{
	// 读取Excel文件
	auto readData = excel.readIntoVector(fileName, sheetName);
	return readData;
}

