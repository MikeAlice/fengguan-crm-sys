#include "stdafx.h"
#include "useExcel.h"
#include <sstream>
#include <chrono>
#include <iomanip>
#include "ExcelComponent.h"

std::string useExcel::getExcelFileName()
{
	std::string excelPrefix = "./public/excel/";
	auto now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//转为字符串
	std::stringstream ss;
	// 可以分别以不同的形式进行显示
	ss << std::put_time(std::localtime(&now_time), "%Y%m%d%H%M%S");
	return excelPrefix + ss.str() + ".xlsx";
}

std::string useExcel::createExcelFile(const std::vector<std::vector<std::string>>& data)
{
	// 创建excel
	std::string excelFile = getExcelFileName();
	std::string sheetName{ u8"数据表1" };
	ExcelComponent excel;
	excel.writeVectorToFile(excelFile, sheetName, data);
	return excelFile;
}

