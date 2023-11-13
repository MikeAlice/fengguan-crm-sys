#pragma once
#ifndef _ADDSALESCONTRACTMAPPER_H_
#define _ADDSALESCONTRACTMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/contractindex/AddSalesContractDO.h"

/**
* 原味的原味包
* 查询语句片段
*	sql << "SELECT cc.customer_id, cl.linkman_id, cch.chance_id, cch.userID FROM "
* 客户名称	customer_id		1
* 联系人	linkman_id		2
* 销售机会	chance_id		3
* 我方代表	our_user_id		4
*/
class AddSalesContractTempMapper : public Mapper<AddSalesContractTempDO> {
public:
	AddSalesContractTempDO mapper(ResultSet* resultSet) const override {
		AddSalesContractTempDO data;
		data.setCustomerID(resultSet->getUInt64(1));
		data.setLinkmanID(resultSet->getUInt64(2));
		data.setChanceID(resultSet->getUInt64(3));
		data.setOurUserID(resultSet->getUInt64(4));
		return data;
	}
};


#endif