#include "stdafx.h"
#include "TraceService.h"
#include "../../dao/gettrace/TraceDAO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"

//分页查询
TracePageDTO::Wrapper TraceService::listAll(const TraceQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = TracePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	TraceDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<AllDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (AllDO sub : result)
	{
		auto dto = GetTraceDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, AC, CName, FT, Ctime, AC_id, CusId, CContent, Icontent, CS_id, Stage, NT, Ntime, FM, ConName, CS, NName)
			pages->addData(dto);
		//  先填DTO前者后填DO的后者
	}
	return pages;

}

//增加数据（请求）
bool TraceService::saveData(const AddTraceDTO::Wrapper& dto)
{
	// 组装DO数据
	AllDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CusId, customer_id, Linkid, linkman_id, Chanceid, SOid, Stage, CStageid, Smode, FMethodid, Ctime, FTime, Icontent, CContent, Ntime, FTime);
	//先DO后者再DTO前者
	// 执行数据添加
	TraceDAO dao;
	return dao.insert(data);
}

//修改数据
bool TraceService::updateData(const ModifyTraceDTO::Wrapper& dto)
{
	// 组装DO数据
	AllDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Trace_id, trace_id, CusId, customer_id, Linkid, linkman_id, Chanceid, SOid, Stage, CStageid, Smode, FMethodid, Ctime, FTime, Icontent, CContent, Ntime, FTime);
	//先DO后者再DTO前者
	// 执行数据修改
	TraceDAO dao;
	return dao.update(data) == 1;
}

bool TraceService::removeData(uint64_t trace_id)
{
	TraceDAO dao;
	return dao.deleteById(trace_id) == 1;
}

oatpp::String TraceService::exportTracefile()
{
	TraceDAO dao;
	auto tracelist = dao.seletctAll();
	vector<vector<string> >data;
	for (auto tmp : tracelist) {
		vector<string> row;
		row.push_back(tmp.getCreatetime());
		row.push_back(tmp.getCtime());
		row.push_back(tmp.getIcontent());
		row.push_back(tmp.getName());
		row.push_back(tmp.getNtime());
		row.push_back(tmp.getNtitle());
		// TODO： 应该存中文字
		//row.push_back(tmp.getSmode());
		row.push_back(to_string(tmp.getChanceid()));
		row.push_back(to_string(tmp.getTrace_id()));
		row.push_back(to_string(tmp.getCreateid()));
		row.push_back(to_string(tmp.getCusId()));
		row.push_back(to_string(tmp.getLinkid()));
		row.push_back(to_string(tmp.getStage()));
		row.push_back(to_string(tmp.getStatus()));
		data.push_back(row);
	}
	//生成excel
	ExcelComponent excel;
	std::string fileName = URIUtil::urlDecode("./public/excel/traceFile.xlsx");
	cout << fileName << endl;
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("数据表1");
	excel.writeVectorToFile(fileName, sheetName, data);

	//上传到fastdfs
	FastDfsClient client("8.130.45.222");
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;

	std::string urlPrefix = "http://8.130.45.222:8888/";

	std::string downloadUrl = urlPrefix + fieldName;
	std::cout << downloadUrl << std::endl;

	return downloadUrl;
}
