#include "stdafx.h"
#include "AddCapitalRecordDAO.h"
#include "AddCapitalRecordMapper.h"

#define FINCAPREC_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->type) { \
	sql << " AND `type`= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->type.getValue("")); \
} \
if (query->bank) { \
	sql << " AND `bank` = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->bank.getValue("")); \
} \
if (query->money) { \
	sql << " AND `money` = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->money.getValue(0)); \
} \
if (query->happen_date) { \
	sql << " AND `happen_date` = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->happen_date.getValue("")); \
} \
if (query->intro) { \
	sql << " AND intro LIKE ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->intro.getValue("") + "%"); \
}


uint64_t AddCapitalRecordDAO::insert(const AddCapitalRecordDO& iObj)
{
	// 根据系统时间创建create_time
	std::time_t now = std::time(0); // 获取日历时间
	std::tm* timeinfo = localtime(&now); // 转换为本地时间的tm结构体
	std::stringstream ss; // 创建一个字符串流对象
	ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S"); // 将tm结构体格式化为字符串流
	std::string create_time = ss.str(); // 从字符串流中获取字符串

	string sql = "INSERT INTO `fin_capital_record` (`type_id`,`create_user_id`, `bank_id`, `money`,`happen_date`, `create_time`,`intro`) VALUES (?, ?, ?, ?, ?, ?, ?)";

	//std::cout <<"insert_type_id:"<< iObj.getTypeId() << std::endl;
	if(iObj.getTypeId() == 1)
	{
		std::string bus_type = u8"资金注入";
		std::string sql = "INSERT INTO `fin_flow_record` (`rece_money`, `bank_id`, `bus_id`, `bus_type`, `intro`, `create_time`) VALUES(?, ?, ?, ?, ?, ?)";
		sqlSession->executeInsert(sql, "%i%i%i%s%s%dt",
			iObj.getMoney(), iObj.getBankId(), iObj.getTypeId(),
			bus_type, iObj.getIntro(), create_time
		);
	}else if(iObj.getTypeId() == -1)
	{
		std::string bus_type = u8"资金抽取";
		std::string sql = "INSERT INTO `fin_flow_record` (`pay_money`, `bank_id`, `bus_id`, `bus_type`, `intro`, `create_time`) VALUES(?, ?, ?, ?, ?, ?)";
		sqlSession->executeInsert(sql, "%i%i%i%s%s%dt",
			iObj.getMoney(), iObj.getBankId(), iObj.getTypeId(),
			bus_type, iObj.getIntro(), create_time
		);
	}
	return sqlSession->executeInsert(sql, "%i%i%i%i%dt%dt%s",
		iObj.getTypeId(), iObj.getCreateUserId(), iObj.getBankId(), iObj.getMoney(),
		iObj.getHappenDate(), create_time, iObj.getIntro()
	);
}
