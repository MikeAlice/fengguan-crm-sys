#include "stdafx.h"
#include "InvoiceService.h"
#include <SimpleDateTimeFormat.h>
#include "../../dao/invoice/InvoiceDAO.h"

InvoicePageDTO::Wrapper InvoiceService::listAll(const InvoiceQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = InvoicePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	InvoiceDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<InvoiceDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (InvoiceDO sub : result)
	{
		auto dto = InvoiceDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		//record_id, Record_id,contract_id, Contract_id, contract_name, Contract_name, customer_id, Customer_id,customer_name, Customer_name,money,Money,pay_date,Pay_date,stages,Stages,invoice_no,Invoice_no,name,Name,bus_type,Bus_type,intro,Intro,create_time,Create_time,create_user_id,Create_user_id)
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, contract_name, Contract_name,customer_name, Customer_name,money,Money,pay_date,Pay_date,stages,Stages,invoice_no,Invoice_no,name,Name,intro,Intro,create_user_id,Create_user_id)
			pages->addData(dto);

	}
	return pages;
}

uint64_t InvoiceService::saveData(const InvoiceAddDTO::Wrapper& dto,uint64_t id)
{
	// 组装DO数据
	InvoiceDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	//Record_id, record_id, Contract_name, contract_name, Customer_id, customer_id, Customer_name, customer_name,Money,money, Pay_date, pay_date,Stages,stages, Invoice_no, invoice_no,Name,name,Bus_type,bus_type,Intro,intro,Create_time,create_time,Create_user_id,create_user_id)
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Contract_id, contract_id, Contract_name, contract_name, Customer_id, customer_id, Customer_name, customer_name, Money, money, Pay_date, pay_date, Stages, stages, Invoice_no, invoice_no, Name, name)
	data.setBus_type("sal_contract");
	data.setIntro("");

	data.setCreate_time(SimpleDateTimeFormat::format("%Y-%m-%d"));
	data.setCreate_user_id(id);
		// 执行数据添加
		InvoiceDAO dao;
	return dao.insert(data);
}

