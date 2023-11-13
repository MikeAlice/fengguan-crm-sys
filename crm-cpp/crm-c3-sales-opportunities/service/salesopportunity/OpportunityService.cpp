#include "stdafx.h"
#include "OpportunityService.h"
#include "dao/salesopportunity/exportSalOpp/ExportSalOppDAO.h"
#include "domain/do/Sales/Cst_chanceDO.h"
#include <vector>
#include "CharsetConvertHepler.h"
#include "uselib/excel/UseExcel.h"
#include "uselib/fastdfs/UseFastDfs.h"

std::string listExportSalOppService::exportSalOpportunity(const OpportunityQuery::Wrapper& query)
{
	// ����DAO, ��ѯ���ݿ�
	ExportSalOppDAO dao;
	// ��ȡ��ͷ
	std::list<std::string> fields = dao.selectField("cst_chance");
	// ��ȡ��������
	std::list<Cst_chanceDO> res = dao.selectAll(query);

	// ������������
	std::vector<std::vector<std::string>> data;
	// ������ͷ
	std::vector<std::string> header;
	for (std::string item : fields) header.push_back(item);
	data.push_back(header);
	// �������
	for (Cst_chanceDO item : res)
	{
		std::vector<std::string> row;

		row.push_back(to_string(item.getChance_id()));
		row.push_back(to_string(item.getCustomer_id()));
		row.push_back(item.getLinkman_id());
		row.push_back(item.getFind_date());
		row.push_back(item.getBill_date());
		row.push_back(to_string(item.getSalestage()));
		row.push_back(to_string(item.getMoney()));
		row.push_back(to_string(item.getSuccess_rate()));
		row.push_back(to_string(item.getUserID()));
		row.push_back(item.getName());
		row.push_back(item.getIntro());
		row.push_back(to_string(item.getStatus()));
		row.push_back(to_string(item.getCreate_user_id()));
		row.push_back(item.getCreate_time());

		data.push_back(row);
	}

	// ����Excel���д��Excel�ļ�, ��ȡ�ļ�����·��
	UseExcel excel;
	std::string fileName = excel.saveToExcel(data);

	// ����FastDFS����ϴ��ļ����ļ�������, ��ȡ��������
	UseFastdfs dfs;
	std::string downloadUrl = dfs.uploadFile(fileName);

	return downloadUrl;
}