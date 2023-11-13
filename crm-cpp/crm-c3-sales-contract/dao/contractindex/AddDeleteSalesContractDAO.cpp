#include "stdafx.h"
#include "AddDeleteSalesContractDAO.h"
#include "AddSalesContractMapper.h"
#include <sstream>

// 原味的原味包
uint64_t SalesContractDAO::insert(const AddSalesContractDO& iObj)
{
	// 首先确定各种id
	stringstream sql;
	sql << "SELECT cc.customer_id, cl.linkman_id, cch.chance_id, cch.userID FROM "
		<< "(SELECT customer_id, linkman FROM cst_customer WHERE name=?) AS cc "
		<< "INNER JOIN "
		<< "(SELECT linkman_id, customer_id, name FROM cst_linkman WHERE name=?) AS cl "
		<< "ON cc.linkman=cl.name AND cc.customer_id=cl.customer_id "
		<< "INNER JOIN "
		<< "(SELECT chance_id, customer_id, linkman_id, userID FROM cst_chance WHERE name=?) AS cch "
		<< "ON cch.customer_id=cc.customer_id AND cch.linkman_id=cl.linkman_id "
		<< "INNER JOIN "
		<< "fly_sys_user AS fsu ON cch.userID=fsu.id AND fsu.name=?";
	string sqlStr = sql.str();
	AddSalesContractTempMapper mapper;
	list<AddSalesContractTempDO> temp = sqlSession->executeQuery<AddSalesContractTempDO, AddSalesContractTempMapper>(sqlStr, mapper, "%s%s%s%s", \
		iObj.getCustomerName(), iObj.getLinkmanName(), iObj.getChanceName(), iObj.getOurUserName());

	// 原则上说，查询结果只能有一条
	if (temp.size() != 1) {
		cout << "weicd" << endl;
		return 0; // 未查询到ID或查询ID不唯一，插入失败
	}
	auto tempDo = temp.begin();

	stringstream insertSql;
	//insertSql << "INSERT INTO `sal_contract` "
	//	<< "(`contract_id`, `title`, `contract_no`, `customer_id`, `linkman_id`, `chance_id`, `website_id`, "
	//	<< "`start_date`, `end_date`, `our_user_id`, `money`, `goods_money`, `zero_money`, `back_money`, "
	//	<< "`owe_money`, `deliver_money`, `invoice_money`, `intro`, `status`, `back_status`, `deliver_status`, "
	//	<< "`invoice_status`, `renew_status`, `create_user_id`, `create_time`) "
	//	<< "VALUES "
	//	<< "(1, '天河项目订单', '2106021686', 1, 1, 0, 0, "
	//	<< "'2021-06-02', '2023-01-01', 1, 2000.00, 0.00, 0.00, 0.00, "
	//	<< "2000.00, 0.00, 0.00, '', 2, 1, 5, "
	//	<< "1, 1, 1, '2021-06-02 16:37:58')";
	insertSql << "INSERT INTO `sal_contract` "
		<< "(`title`, `contract_no`, `customer_id`, `linkman_id`, `chance_id`, "
		<< "`start_date`, `end_date`, `our_user_id`, `money`, "
		<< "`intro`, "
		<< "`create_time`) "
		<< "VALUES "
		<< "(?, ?, ?, ?, ?, "
		<< "?, ?, ?, ?, "
		<< "?, "
		<< "NOW())";
	const char* fmt = "%s%s%ull%ull%ull"
		"%s%s%ull%d"
		"%s";

	return sqlSession->executeInsert(insertSql.str(), fmt, iObj.getTitle(), iObj.getContractNo(), tempDo->getCustomerID(), tempDo->getLinkmanID(), \
		tempDo->getChanceID(), iObj.getStartDate(), iObj.getEndDate(), tempDo->getOurUserID(), iObj.getMoney(), iObj.getIntro());
}


// 原味的原味包
int SalesContractDAO::deleteByNo(string no)
{
	string sql = "DELETE FROM `sal_contract` WHERE `contract_no`=?";
	return sqlSession->executeUpdate(sql, "%s", no);
}