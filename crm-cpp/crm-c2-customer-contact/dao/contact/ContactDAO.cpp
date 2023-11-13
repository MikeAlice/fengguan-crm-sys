#include "stdafx.h"
#include "ContactDAO.h"
#include <sstream>
#include "SqlSession.h"
#include "ExportContactMapper.h"

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->create_user_id) { \
	sql << " AND c1.create_user_id=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->create_user_id.getValue(0)); \
} \
if (query->owner_user_id) { \
	sql << " AND c1.owner_user_id=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->owner_user_id.getValue(0)); \
}

int ContactDAO::deleteById(uint64_t id) {
	string sql = "DELETE FROM `cst_linkman` WHERE `linkman_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}

int ContactDAO::update(const ContactDO& uObj) {
	string sql = "UPDATE `cst_linkman` SET  `customer_id`=?, `name`=?, `gender`=?, `postion`=?, `tel`=?"
		", `mobile`=? , `qicq`=? , `email`=? , `zipcode`=? , `address`=?, `intro`=? WHERE `linkman_id`=?";
	return sqlSession->executeUpdate(sql, "%ull%s%ull%s%s%s%s%s%s%s%s%ull", 
		uObj.getCustomer_id(), uObj.getLinkman_name(), uObj.getGender(), uObj.getPostion(), uObj.getTel(),
		uObj.getMobile(), uObj.getQicq(), uObj.getEmail(), uObj.getZipcode(), 
		uObj.getAddress(), uObj.getIntro(), uObj.getLinkman_id());
}

list<ContactDO> ContactDAO::selectAll(const ExportContactQuery::Wrapper& query)
{
	stringstream sql;
	/*std::cout << "query->owner_user_id:" << query->owner_user_id << std::endl;
	std::cout << "query->create_user_id:" << query->create_user_id << std::endl;*/
	sql << "SELECT c1.name customsname, c.name, c.gender, c.postion, \
				c.tel, c.mobile, c.qicq, c.email, c.zipcode, \
				c.address, c.intro, u1.name owername, c.create_time \
			FROM cst_linkman c \
			LEFT JOIN fly_sys_user u1 ON c.create_user_id = u1.id \
			LEFT JOIN cst_customer c1 ON c.customer_id = c1.customer_id \
			LEFT JOIN fly_sys_user u2 ON c1.owner_user_id = u2.id";
	SAMPLE_TERAM_PARSE(query, sql);
	//sql << "ORDER BY c.customer_id";
	ExportCustomerMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContactDO, ExportCustomerMapper>(sqlStr, mapper, params);
}

std::list<ContactDO> ContactDAO::selectAllById(uint64_t id)
{
	stringstream sql;
	/*std::cout << "query->owner_user_id:" << query->owner_user_id << std::endl;
	std::cout << "query->create_user_id:" << query->create_user_id << std::endl;*/
	sql << "SELECT c1.name customsname, c.name, c.gender, c.postion, \
				c.tel, c.mobile, c.qicq, c.email, c.zipcode, \
				c.address, c.intro, u1.name owername, c.create_time \
			FROM cst_linkman c \
			LEFT JOIN fly_sys_user u1 ON c.create_user_id = u1.id \
			LEFT JOIN cst_customer c1 ON c.customer_id = c1.customer_id";
	SqlParams params; 
		sql << " WHERE 1=1"; 
		if (id) {
			sql << " AND c.linkman_id=?"; 
			SQLPARAMS_PUSH(params, "ull", uint64_t, id); \
		}
	//sql << "ORDER BY c.customer_id";
	ExportCustomerMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContactDO, ExportCustomerMapper>(sqlStr, mapper, params);
}

uint64_t ContactDAO::insert(const ContactDO& iObj) {
	string sql = "INSERT INTO `cst_linkman` (`customer_id`, `name`, `gender`, `postion`, `tel`"
		", `mobile`, `qicq`, `email`, `zipcode`, `address`, `intro`, `create_user_id`, `create_time`)"
		"VALUES(? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? )";
	return sqlSession->executeInsert(sql, "%ull%s%ull%s%s%s%s%s%s%s%s%ull%s",
		iObj.getCustomer_id(), iObj.getLinkman_name(), iObj.getGender(), iObj.getPostion(), iObj.getTel(),
		iObj.getMobile(), iObj.getQicq(), iObj.getEmail(), iObj.getZipcode(),
		iObj.getAddress(), iObj.getIntro(), iObj.getCreate_user_id(), iObj.getCreate_time());
}



