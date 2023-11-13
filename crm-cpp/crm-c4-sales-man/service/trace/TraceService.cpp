#include "stdafx.h"
#include "TraceService.h"
#include "../../dao/gettrace/TraceDAO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"

//��ҳ��ѯ
TracePageDTO::Wrapper TraceService::listAll(const TraceQuery::Wrapper& query)
{
	// �������ض���
	auto pages = TracePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������
	TraceDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<AllDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (AllDO sub : result)
	{
		auto dto = GetTraceDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, AC, CName, FT, Ctime, AC_id, CusId, CContent, Icontent, CS_id, Stage, NT, Ntime, FM, ConName, CS, NName)
			pages->addData(dto);
		//  ����DTOǰ�ߺ���DO�ĺ���
	}
	return pages;

}

//�������ݣ�����
bool TraceService::saveData(const AddTraceDTO::Wrapper& dto)
{
	// ��װDO����
	AllDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CusId, customer_id, Linkid, linkman_id, Chanceid, SOid, Stage, CStageid, Smode, FMethodid, Ctime, FTime, Icontent, CContent, Ntime, FTime);
	//��DO������DTOǰ��
	// ִ���������
	TraceDAO dao;
	return dao.insert(data);
}

//�޸�����
bool TraceService::updateData(const ModifyTraceDTO::Wrapper& dto)
{
	// ��װDO����
	AllDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Trace_id, trace_id, CusId, customer_id, Linkid, linkman_id, Chanceid, SOid, Stage, CStageid, Smode, FMethodid, Ctime, FTime, Icontent, CContent, Ntime, FTime);
	//��DO������DTOǰ��
	// ִ�������޸�
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
		// TODO�� Ӧ�ô�������
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
	//����excel
	ExcelComponent excel;
	std::string fileName = URIUtil::urlDecode("./public/excel/traceFile.xlsx");
	cout << fileName << endl;
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("���ݱ�1");
	excel.writeVectorToFile(fileName, sheetName, data);

	//�ϴ���fastdfs
	FastDfsClient client("8.130.45.222");
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;

	std::string urlPrefix = "http://8.130.45.222:8888/";

	std::string downloadUrl = urlPrefix + fieldName;
	std::cout << downloadUrl << std::endl;

	return downloadUrl;
}
