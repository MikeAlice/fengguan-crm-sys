#include "stdafx.h"
#include "BankAccountService.h"
#include "../../dao/bankaccount/BankAccountDAO.h"
#include"uselib/excel/UseExcel.h"
#include"uselib/fastdfs/UseFastDFS.h"


//��ҳ��ѯ
BankAccountPageDTO::Wrapper BankAccountService::listAll(const BankAccountQuery::Wrapper& query)
{
	// �������ض���
	auto pages = BankAccountPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������
	BankAccountDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<BankAccountDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (BankAccountDO sub : result)
	{
		auto dto = BankAccountDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,bank_id,Bank_Id, name, Name, card, Card, holders, Holders, sort, Sort, visible, Visible)
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,bank_id,Bank_id,name, Name, card, Card,address,Address, holders, Holders, sort, Sort, visible, Visible)
			pages->addData(dto);

	}
	return pages;
}

//��ȡ�����б�
oatpp::List<BankAccountListDTO::Wrapper> BankAccountService::getlistAll(const BankAccountListQuery::Wrapper& query)
{
	//���ڷ��ؽ��
	auto ans = oatpp::List<BankAccountListDTO::Wrapper>::createShared();

	BankAccountDAO dao;
	auto reslist = dao.selectPage();
	if (query->name == nullptr) {
		//DO->DTO
		for (auto& name : reslist)
		{
			auto t = BankAccountListDTO::createShared();
			t->bank_id = name.getBank_id();
			t->name = name.getName();//��������
			t->card = name.getCard();
			ans->push_back(t);
			//List
		}
		//���ؽ��
		return ans;
	}
	auto res = dao.selectByName(query->name);//���ط�������list --DO
	for (auto& name : res)
	{
		auto t = BankAccountListDTO::createShared();
		t->bank_id = name.getBank_id();
		t->name = name.getName();//��������
		t->card = name.getCard();
		ans->push_back(t);
		//List
	}
	//���ؽ��
	return ans;
}
uint64_t BankAccountService::saveData(const BankAccountDTO::Wrapper& dto)
{
	// ��װDO����
	BankAccountDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Name, name, Card, card, Address,address,Holders, holders, Sort, sort, Visible, visible)
		// ִ���������
		BankAccountDAO dao;
	return dao.insert(data);
}

bool BankAccountService::updateData(const BankAccountDTO::Wrapper& dto)
{
	// ��װDO����
	BankAccountDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Bank_id,bank_id, Name, name, Card, card, Address,address,Holders, holders, Sort, sort, Visible, visible)
		// ִ�������޸�
		BankAccountDAO dao;
	return dao.update(data) == 1;
}

bool BankAccountService::removeData(uint64_t id)
{
	BankAccountDAO dao;
	return dao.deleteById(id) == 1;
}
string BankAccountService::exportData(const oatpp::List<BankAccountExportDTO::Wrapper>& dto)
{
	BankAccountDAO dao;
	list<BankAccountDO> DOList = dao.selectexport(dto);

	// ��ȡ������
	vector<string> title = { u8"���",u8"���������˺�",u8"�˺�",u8"������",u8"������ַ" ,u8"�����",u8"�Ƿ�����"};

	// ��ӱ�����
	vector<vector<std::string>> data{};
	data.push_back(title);

	// ���������
	for (const auto& i : DOList)
	{
		vector<string> row;
		row.push_back(to_string(i.getBank_id()));
		row.push_back(i.getName());
		row.push_back(to_string(i.getCard()));
		row.push_back(i.getHolders());
		row.push_back(i.getAddress());
		row.push_back(to_string(i.getSort()));
		row.push_back(to_string(i.getVisible()));
		data.push_back(row);
	}
	// ����Excel���ϴ���Nacos
	string downloadURL = UseFastDFS::useDfsWithNacos(UseExcel::createExcelFile(data));

	return downloadURL;
}
