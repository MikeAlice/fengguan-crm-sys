#pragma once
#include <vector>
#include <string>
#include <sstream>
using std::vector;
using std::string;
class useExcel
{
private:
	static std::string getExcelFileName();

public:
	static std::string createExcelFile(const vector<vector<string>>& data);
};

