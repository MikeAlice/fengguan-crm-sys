#pragma once
#ifndef _PAYRECORDS_MAPPER_
#define _PAYRECORDS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/payrecords/PayrecordsDO.h"

class PayrecordsMapper : public Mapper<PayrecordsDO>
{
public:
	PayrecordsDO mapper(ResultSet* resultSet) const override
	{
		PayrecordsDO data;
		// 映射付款记录Id
		data.setRecord_id(resultSet->getUInt64(1));
		// 映射付款计划Id
		data.setPlan_id(resultSet->getUInt64(2));
		// 映射合同Id
		data.setContract_id(resultSet->getUInt64(3));
		// 映射采购合同名称
		data.setContract_name(resultSet->getString(4));
		// 映射供应商Id
		data.setSupplier_id(resultSet->getUInt64(5));
		// 映射供应商名称
		data.setSupplier_name(resultSet->getString(6));
		// 映射银行Id
		data.setBank_id(resultSet->getUInt64(7));
		// 映射付款日期
		data.setPay_date(resultSet->getString(8));
		// 映射金额
		data.setMoney(resultSet->getUInt64(9));
		// 映射去零
		data.setZero_money(resultSet->getUInt64(10));
		// 映射期次
		data.setStages(resultSet->getUInt64(11));
		// 映射备注
		data.setIntro(resultSet->getString(12));
		// 映射创建时间
		data.setCreate_time(resultSet->getString(13));
		// 映射创建人id
		data.setCreate_user_id(resultSet->getUInt64(14));
		return data;
	}

};

#endif // !_PAYRECORDSMAPPER_H_
