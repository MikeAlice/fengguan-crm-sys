#include"stdafx.h"
#include"SalesChartDAO.h"
#include"SalesChartMapper.h"
#include "SalesChartDAO.h"
#include <sstream>

//定义条件解析宏，减少重复代码
/*
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}
*/

// 统计数据条数 
uint64_t  SalesChartDAO::count()
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sal_contract";
	//SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr,"%ull");
}

// 依据输入的时间id date_id 来查询销售金额排行榜数据  
std::list<SalesChartDO> SalesChartDAO::selectWithAmount(const UInt64 date_id)
{
	string time ="";
	switch (date_id)
	{
	case 1: //本周
		time = "this-week";
		break;
	case 2: //上周
		time = "last-week";
		break;
	case 3: //这个月
		time = "this-month";
		break;
	case 4: //上个月
		time = "last-month";
		break;
	case 5: //这个季度
		time = "this-quarter";
		break;
	case 6: // 上个季度
		time = "last-quarter";
		break;
	case 7: // 今年
		time = "this-year";
		break;
	case 8: // 去年
		time = "last-year";
		break;
	default:
		break;
	}

	string sql = "SELECT h.name name, SUM(s.money) amount FROM sal_contract s JOIN hrm_staff h ON s.our_user_id = h.staff_no\
				WHERE s.start_date < ? GROUP BY name ORDER BY amount DESC LIMIT 1, 10";
	SalesChartMapper mapper;
	return sqlSession->executeQuery<SalesChartDO, SalesChartMapper>(sql, mapper, "%s", time);
}

// 依据输入的时间id date_id 来查询订单总数排行榜数据
std::list<SalesChartDO> SalesChartDAO::selectWithTotal(const UInt64 date_id)
{
	string time = "";
	switch (date_id)
	{
	case 1: //本周
		time = "this-week";
		break;
	case 2: //上周
		time = "last-week";
		break;
	case 3: //这个月
		time = "this-month";
		break;
	case 4: //上个月
		time = "last-month";
		break;
	case 5: //这个季度
		time = "this-quarter";
		break;
	case 6: // 上个季度
		time = "last-quarter";
		break;
	case 7: // 今年
		time = "this-year";
		break;
	case 8: // 去年
		time = "last-year";
		break;
	default:
		break;
	}

	string sql = "SELECT h.name name, COUNT(s.our_user_id) total FROM sal_contract s JOIN hrm_staff h ON s.our_user_id = h.staff_no \
				WHERE s.start_date < ? GROUP BY total ORDER BY amount DESC LIMIT 1, 10";
	SalesChartMapper mapper;
	return sqlSession->executeQuery<SalesChartDO, SalesChartMapper>(sql, mapper, "%s", time);
}

// 依据输入时间查询数量统计数据
list<NumberCountingDO> NumberCountingDAO:: selectByDate(const int date_id)
{
	string time = "";
	switch (date_id)
	{
	case 1: //本周
		time = "this-week";
		break;
	case 2: //上周
		time = "last-week";
		break;
	case 3: //这个月
		time = "this-month";
		break;
	case 4: //上个月
		time = "last-month";
		break;
	case 5: //这个季度
		time = "this-quarter";
		break;
	case 6: // 上个季度
		time = "last-quarter";
		break;
	case 7: // 今年
		time = "this-year";
		break;
	case 8: // 去年
		time = "last-year";
		break;
	default:
		break;
	}

	string sql = "SELECT COUNT(cst_chance.find_date) ,COUNT(sal_contract.contract_no),COUNT(cst_trace.trace_id),  \
		COUNT(cst_linkman.linkman_id), SUM(fin_flow_record.balance), SUM(fin_rece_record.money)  \
		FROM cst_chance cst_chance, sal_contract sal_contract, cst_trace cst_trace, cst_linkman cst_linkman, \
		fin_flow_record fin_flow_record, fin_rece_record fin_rece_record  \
		WHERE cst_chance.create_time > ? AND sal_contract.create_time > ? AND  \
		cst_trace.create_time > ? AND cst_linkman.create_time > ? AND  \
		fin_flow_record.create_time > ? AND fin_rece_record.create_time > ?";
	
	NumberCountingMapper mapper;
	return sqlSession->executeQuery<NumberCountingDO, NumberCountingMapper>(sql, mapper, "%s", time);
}
