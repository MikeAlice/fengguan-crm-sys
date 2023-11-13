#include "stdafx.h"
#include "ExpendituresDAO.h"
#include "ExpendituresMapper.h"

namespace sqlHelpers {
	/*
	* 描述：添加IN后的()
	* 示例：在"SELECT xxx FROM xxx WHERE xxx IN "的后面
	*		添加(1,2,3,4)
	* 参数：sql语句、dto对象
	* 注意：record_id！
	*/
	template<typename T>
	void insertIdList(stringstream& sql, T& dto)
	{
		sql << "(";
		for (auto i = dto->begin(); i != dto->end(); i++)
		{
			if (i != dto->begin())	sql << ",";
			sql << (*i)->record_id.getValue({});
		}
		sql << ")";
	}
	/*
	* In C++20:
	* #define insertIdList(sql, dto, varname) \
	* []<typename T>(stringstream &sql, T &dto){ \
	* sql << "("; \
	*	for (auto i = dto->begin(); i != dto->end(); i++) \
	*	{ \
	*		if (i != dto->begin())	sql << ","; \
	*		sql << (*i)->varname.getValue({}); \
	*	} \
	*	sql << ")"; \
	* }()
	*/
}

#define EXPENDITURES_TREAM_PARSE(query,sql)\
SqlParams params;\
sql<<"WHERE 1=1";\
if(query->bank){\
	sql<<" AND fba.name=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->bank.getValue(""));\
}\
if(query->intro){\
	sql<<" AND fer.intro=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->intro.getValue(""));\
}\
if(query->money){\
	sql<<" AND fer.money=?";\
	SQLPARAMS_PUSH(params,"i",int,query->money.getValue(0));\
}\
if(query->latest_happen_date){\
	sql<<" AND TIMESTAMPDIFF(DAY,fer.happen_date,NOW())<=?";\
	SQLPARAMS_PUSH(params,"i",int,query->latest_happen_date.getValue(0));\
}\
if(query->latest_create_time){\
	sql<<" AND TIMESTAMPDIFF(DAY,fer.create_time,NOW())<=?";\
	SQLPARAMS_PUSH(params,"i",int,query->latest_create_time.getValue(0));\
}\


std::list<ExpendituresDO> ExpendituresDAO::selectWithIdList(const oatpp::List<ExportExpenditures::Wrapper>& dto)
{
	stringstream sql;
	sql << "SELECT fer.record_id,fet.name,fer.money,fba.name,fer.happen_date,fsu.name,fer.create_time,fer.intro "
			"FROM fin_expenses_record fer "
			"LEFT JOIN fin_expenses_type fet ON fer.type_id=fet.id "
			"LEFT JOIN fin_bank_account fba ON fer.bank_id=fba.bank_id "
			"LEFT JOIN fly_sys_user fsu ON fer.create_user_id=fsu.id "
			"WHERE record_id IN ";
	sqlHelpers::insertIdList(sql, dto);
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	ExpendituresMapper mapper;
	return sqlSession->executeQuery<ExpendituresDO, ExpendituresMapper>(sqlStr, mapper);
}

uint64_t ExpendituresDAO::removeData(const oatpp::List<DelExpendituresDTO::Wrapper>& dto)
{
	stringstream sql;
	sql << "DELETE FROM fin_expenses_record fer "
		"WHERE record_id IN ";
	sqlHelpers::insertIdList(sql, dto);
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	return sqlSession->executeUpdate(sqlStr);
}

uint64_t ExpendituresDAO::count(const ExpendituresPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT count(*) "
		"FROM fin_expenses_record fer "
		"LEFT JOIN fin_expenses_type fet ON fer.type_id=fet.id "
		"LEFT JOIN fin_bank_account fba ON fer.bank_id=fba.bank_id "
		"LEFT JOIN fly_sys_user fsu ON fer.create_user_id=fsu.id ";
		EXPENDITURES_TREAM_PARSE(query, sql);
			string sqlStr = sql.str();
		return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ExpendituresDO> ExpendituresDAO::selectWithPage(const ExpendituresPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT fer.record_id,fet.name,fer.money,fba.name,fer.happen_date,fsu.name,fer.create_time,fer.intro "
		"FROM fin_expenses_record fer "
		"LEFT JOIN fin_expenses_type fet ON fer.type_id=fet.id "
		"LEFT JOIN fin_bank_account fba ON fer.bank_id=fba.bank_id "
		"LEFT JOIN fly_sys_user fsu ON fer.create_user_id=fsu.id ";
		EXPENDITURES_TREAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ExpendituresMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ExpendituresDO, ExpendituresMapper>(sqlStr, mapper, params);
}

uint64_t ExpendituresDAO::insert(const ExpendituresAddDO& in)
{
	string sql = "INSERT INTO `fin_expenses_record` (`type_id`,`create_user_id`,`bank_id`,`money`,`intro`,`create_time`,`happen_date`) VALUES(?,?,?,?,?,?,?)";
	return sqlSession->executeInsert(sql, "%i%i%i%i%s%dt%dt",in.getType(),in.getCreateUser(),in.getBank(),in.getMoney(),in.getIntro(),in.getCreateTime(),in.getHappenDate());
}
