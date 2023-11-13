#pragma once
#include <chrono>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
class UseExcel
{
private:
	static std::string getExcelFileName();

public:
	static std::string createExcelFile(const std::vector<std::vector<std::string>>& data);
};

