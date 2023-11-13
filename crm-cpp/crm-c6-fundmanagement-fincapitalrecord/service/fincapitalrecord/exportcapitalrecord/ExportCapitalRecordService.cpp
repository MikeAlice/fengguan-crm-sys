#include "stdafx.h"
#include "ctime"
#include "ExportCapitalRecordService.h"
#include "CharsetConvertHepler.h"
#include "dao/fincapitalrecord/exportcapitalrecord/ExportCapitalRecordDAO.h"
#include "dao/fincapitalrecord/querycapitalrecord/QueryCapitalRecordDAO.h"
#include "uselib/excel/useExcel.h"
#include "uselib/fastdfs/useFastdfs.h"

std::string ExportCapitalRecordService::exportData(const oatpp::List<ExportCapitalRecordDTO::Wrapper>& dto)
{
	ExportCapitalRecordDAO dao;
	auto dtolist = dao.selectWithIdList(dto);

	// 添加标题行
	std::vector<std::vector<std::string>> data;
	data.insert(data.begin(), {
		CharsetConvertHepler::ansiToUtf8("单号") ,
		CharsetConvertHepler::ansiToUtf8("支出类型") ,
		CharsetConvertHepler::ansiToUtf8("金额") ,
		CharsetConvertHepler::ansiToUtf8("银行账号") ,
		CharsetConvertHepler::ansiToUtf8("产生日期") ,
		CharsetConvertHepler::ansiToUtf8("创建人") ,
		CharsetConvertHepler::ansiToUtf8("创建时间") ,
		CharsetConvertHepler::ansiToUtf8("备注") ,
		});

	// 添加数据行
	for (const auto& item : dtolist)
	{
		vector<string> row{};
		row.push_back(to_string(item.getRecordId()));
		row.push_back(item.getType());
		row.push_back(CharsetConvertHepler::ansiToUtf8(to_string(item.getMoney())));
		std::stringstream ss;
		ss  << item.getBankName()
			<< "\n\r"
			<< item.getBankCard();
		row.push_back(ss.str());
		row.push_back(item.getHappenDate());
		row.push_back(item.getCreateUser());
		row.push_back(item.getCreateTime());
		row.push_back(item.getIntro());

		data.push_back(row);
	}

	// 创建Excel并上传到Nacos
	std::string fileName = useExcel::createExcelFile(data);
	std::string downloadURL = useFastdfs::useDfsWithNacos(fileName);

	return downloadURL;
}


std::string ExportCapitalRecordService::getExcelFileName()
{
	std::string excelPrefix = "./public/excel/";
	auto now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//转为字符串
	std::stringstream ss;
	// 可以分别以不同的形式进行显示
	ss << std::put_time(std::localtime(&now_time), "%Y%m%d%H%M%S");
	return excelPrefix + ss.str() + ".xlsx";
}