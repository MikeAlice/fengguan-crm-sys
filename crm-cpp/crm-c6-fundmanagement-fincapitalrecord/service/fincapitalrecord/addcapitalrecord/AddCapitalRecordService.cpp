#include "stdafx.h"
#include "AddCapitalRecordService.h"
#include "dao/fincapitalrecord/addcapitalrecord/AddCapitalRecordDAO.h"

uint64_t AddCapitalRecordService::saveData(const AddCapitalRecordDTO::Wrapper& dto)
{
	// 组装数据
	AddCapitalRecordDO data;
	//组装DO对象数据
	data.setTypeId(dto->type_id.getValue(0));
	data.setBankId(dto->bank_id.getValue(0));
	data.setCreateUserId(dto->create_user_id.getValue(0));
	data.setMoney(dto->money.getValue(0));
	data.setHappenDate(dto->happen_date.getValue(""));
	data.setIntro(dto->intro.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		TypeId, type_id, BankId, bank_id, CreateUserId, create_user_id, Money, money, HappenDate, happen_date, Intro, intro)
		// 执行数据添加
		AddCapitalRecordDAO dao;
	return dao.insert(data);
}