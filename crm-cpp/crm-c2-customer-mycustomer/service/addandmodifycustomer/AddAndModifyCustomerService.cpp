#include "stdafx.h"
#include "AddAndModifyCustomerService.h"
#include "../../dao/addandmodifycustomer/AddAndModifyCustomerDAO.h"
#include <SimpleDateTimeFormat.h>

uint64_t AddAndModifyCustomerService::saveData(const DetailsCustomerDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	CustomerDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Source, source, Grade, grade,
		Industry, industry, Mobile, mobile, Tel, tel, Address, address,
		Intro, intro, Needs, needs, Owner_User_Id, owner_user_id)
		data.setCreate_User_Id(atoi(payload.getId().c_str()));
		data.setCreate_Time(SimpleDateTimeFormat::format());
		// 执行数据添加
		AddAndModifyCustomerDAO dao;
		return dao.insert(data);
}

bool AddAndModifyCustomerService::updateData(const ModifyCustomerDTO::Wrapper& dto)
{
	// 组装DO数据
	CustomerDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Source, source, Grade, grade,
		Industry, industry, Mobile, mobile, Tel, tel, Address, address,
		Intro, intro, Needs, needs, Customer_Id,customer_id)
		// 执行数据修改
		AddAndModifyCustomerDAO dao;
	return dao.update(data) == 1;
}