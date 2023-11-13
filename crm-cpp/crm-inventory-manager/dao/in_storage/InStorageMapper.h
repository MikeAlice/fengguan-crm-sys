#pragma once
#ifndef INSTORAGEMAPPER_H_
#define INSTORAGEMAPPER_H_

#include "Mapper.h"
#include "domain/do/in_storage/InStorageDO.h"

class InStorageMapper :public Mapper<InStorageDO3> {
public:
	InStorageDO3 mapper(ResultSet* resultSet) const override
	{
		InStorageDO3 data;
		data.setNumber(resultSet->getString(1));
		data.setGoods_id(resultSet->getUInt64(2));
		return data;
	}
};

// 查询入库表明细的mapper
class InStorageDetailsMapper :public Mapper<InStorageDO> {
public:
	InStorageDO mapper(ResultSet* resultSet) const override
	{
		InStorageDO data;
		// 单号
		data.setId(resultSet->getUInt64(1));
		// 仓库编号
		data.setStore_id(resultSet->getUInt64(2));
		// 合同编号
		data.setContract_id(resultSet->getUInt64(3));
		// 主题
		data.setTitle(resultSet->getString(4));
		// 金额
		data.setMoney(resultSet->getDouble(5));
		// 数量
		data.setNumber(resultSet->getUInt64(6));
		// 备注
		data.setIntro(resultSet->getString(7));
		// 入库状态
		data.setSTatus(resultSet->getInt64(8));
		// 入库人
		data.setInto_user_name(resultSet->getString(9));
		// 入库时间
		data.setInto_time(resultSet->getString(10));
		// 创建人
		data.setCreate_user_name(resultSet->getString(11));
		// 创建时间
		data.setCreate_time(resultSet->getString(12));
		// 入库类型
		data.setInto_type(resultSet->getString(13));
		return data;
	}
};


#endif // !INSTORAGEMAPPER_H_
