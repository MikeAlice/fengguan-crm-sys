#pragma once
#ifndef _PAYRECORDS_DAO_
#define _PAYRECORDS_DAO_

#include "BaseDAO.h"
#include "domain/query/payrecords/PayrecordsQuery.h"
#include "domain/do/payrecords/PayrecordsDO.h"

class PayrecordsDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const PayrecordsQuery::Wrapper& query);
	// 分页查询数据
	list<PayrecordsDO> selectWithPage(const PayrecordsQuery::Wrapper& query);
	// 通过付款时间查询数据
	list<PayrecordsDO> selectByPay_date(const string& pay_date);
	// 通过创建时间查询数据
	list<PayrecordsDO> selectByCreate_time(const string& create_time);
	// 通过采购合同名称查询数据
	list<PayrecordsDO> selectByContract_name(const string& contract_name);
	// 通过供应商名称查询数据
	list<PayrecordsDO> selectBySupplier_name(const string& supplier_name);
	// 通过付款金额查询数据
	list<PayrecordsDO> selectByMoney(const uint64_t money);
};

#endif // !_PAYRECORDS_H_