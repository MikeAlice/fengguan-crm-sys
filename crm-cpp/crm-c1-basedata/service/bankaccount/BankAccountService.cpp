#include "stdafx.h"
#include "BankAccountService.h"
#include "../../dao/bankaccount/BankAccountDAO.h"
#include"uselib/excel/UseExcel.h"
#include"uselib/fastdfs/UseFastDFS.h"


//分页查询
BankAccountPageDTO::Wrapper BankAccountService::listAll(const BankAccountQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = BankAccountPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	BankAccountDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<BankAccountDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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

//获取下拉列表
oatpp::List<BankAccountListDTO::Wrapper> BankAccountService::getlistAll(const BankAccountListQuery::Wrapper& query)
{
	//定于返回结果
	auto ans = oatpp::List<BankAccountListDTO::Wrapper>::createShared();

	BankAccountDAO dao;
	auto reslist = dao.selectPage();
	if (query->name == nullptr) {
		//DO->DTO
		for (auto& name : reslist)
		{
			auto t = BankAccountListDTO::createShared();
			t->bank_id = name.getBank_id();
			t->name = name.getName();//解析数据
			t->card = name.getCard();
			ans->push_back(t);
			//List
		}
		//返回结果
		return ans;
	}
	auto res = dao.selectByName(query->name);//返回分类名称list --DO
	for (auto& name : res)
	{
		auto t = BankAccountListDTO::createShared();
		t->bank_id = name.getBank_id();
		t->name = name.getName();//解析数据
		t->card = name.getCard();
		ans->push_back(t);
		//List
	}
	//返回结果
	return ans;
}
uint64_t BankAccountService::saveData(const BankAccountDTO::Wrapper& dto)
{
	// 组装DO数据
	BankAccountDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Name, name, Card, card, Address,address,Holders, holders, Sort, sort, Visible, visible)
		// 执行数据添加
		BankAccountDAO dao;
	return dao.insert(data);
}

bool BankAccountService::updateData(const BankAccountDTO::Wrapper& dto)
{
	// 组装DO数据
	BankAccountDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Bank_id,bank_id, Name, name, Card, card, Address,address,Holders, holders, Sort, sort, Visible, visible)
		// 执行数据修改
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

	// 获取标题行
	vector<string> title = { u8"编号",u8"开户银行账号",u8"账号",u8"开户人",u8"开户地址" ,u8"排序号",u8"是否启用"};

	// 添加标题行
	vector<vector<std::string>> data{};
	data.push_back(title);

	// 添加数据行
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
	// 创建Excel并上传到Nacos
	string downloadURL = UseFastDFS::useDfsWithNacos(UseExcel::createExcelFile(data));

	return downloadURL;
}
