#include "stdafx.h"
#include "CollectionRecordDAO.h"
#include"CollectionRecordDAO.h"
#include"CollectionRecordMapper.h"
#include<sstream>

#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->customer_name) { \
	sql << " AND `customer_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->customer_name.getValue("")); \
} \
if (query->start_time) { \
	sql << " AND start_time=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->start_time.getValue("")); \
} \
if (query->end_time) { \
	sql << " AND end_time=?"; \
	SQLPARAMS_PUSH(params, "s", string, query->end_time.getValue("")); \
} \


uint64_t CollectionRecordDAO::count(const CollectionRecordQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT COUNT(*) FROM fin_rece_record";
    SqlParams params; sql << " WHERE 1=1"; if (query->customer_name) {
        sql << " AND `customer_name`=?"; params.emplace_back(SqlParam("s", std::make_shared<std::string>(query->customer_name.getValue(""))));
    } if (query->start_time) {
        sql << " AND start_time=?"; params.emplace_back(SqlParam("s", std::make_shared<std::string>(query->start_time.getValue(""))));
    } if (query->end_time) {
        sql << " AND end_time=?"; params.emplace_back(SqlParam("s", std::make_shared<string>(query->end_time.getValue(""))));
    };
    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<CollectionRecordDO> CollectionRecordDAO::selectWithPage(const CollectionRecordQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT * FROM fin_rece_record";
    SAMPLE_TERAM_PARSE(query, sql);
    sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
    CollectionRecordMapper mapper;
    string sqlStr = sql.str();
    return sqlSession->executeQuery<CollectionRecordDO, CollectionRecordMapper>(sqlStr, mapper, params);
}

uint64_t CollectionRecordDAO::insert(const CollectionRecordDO& iObj)
{
    string sql = "INSERT INTO `fin_rece_record` (`record_id`, `customer_id`, `customer_name`,\
        `contract_id`, `contract_name`, `bank_id`  \
        `money`, `zero_money`, `stages` \
        `plan_id`, `back_date`,  \
        `bus_type`, `create_user_id`, `create_time`) \
        VALUES (?, ?, ?)";
    return sqlSession->executeInsert(sql, "%s%s%i", iObj.getrecord_id(), iObj.getcustomer_id(), 
        iObj.getcontract_id(), iObj.getcontract_name(),
        iObj.getbank_id(), iObj.getmoney(),
        iObj.getzero_money(), iObj.getstages(),
        iObj.getplan_id(), iObj.getback_date(),
        iObj.getbus_type(), iObj.getcreate_user_id(),
        iObj.getcreate_time());
}

int CollectionRecordDAO::deleteById(uint64_t id)
{
    string sql = "DELETE FROM `fin_rece_record` WHERE `id`=?";
    return sqlSession->executeUpdate(sql, "%ull", id);
}

list<CollectionRecordDO> CollectionRecordDAO::selectById(const DelCollectionRecordDTO::Wrapper& exportdto)
{
    string sql = "SELECT * FROM fin_rece_record WHERE `name` LIKE CONCAT('%',?,'%')";
    CollectionRecordMapper mapper;
    list<CollectionRecordDO> result;
    for (auto record_p = exportdto->record_id->begin(); record_p != exportdto->record_id->end(); record_p++) {
        auto list = sqlSession->executeQuery<CollectionRecordDO, CollectionRecordMapper>(sql, mapper, "%s", *record_p);
        result.push_back(*list.begin());
    }
    return result;
   
}
