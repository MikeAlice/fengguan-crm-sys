#include "stdafx.h"
#include "InStorageDAO.h"



#define INSTORAGE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND a.into_id=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->id.getValue(0)); \
} \
if (query->contract_id) { \
	sql << " AND a.contract_id=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->contract_id.getValue(0)); \
} \
if (query->title) { \
	sql << " AND a.title=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->title.getValue("")); \
} \
if (query->store_id) { \
	sql << " AND a.store_id=?"; \
	SQLPARAMS_PUSH(params, "ull", uint64_t, query->store_id.getValue(0)); \
} \
if (query->status) { \
	sql << " AND a.status=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->status.getValue(0)); \
} \

bool InStorageDAO::updateById(const InStorageDO2 & uObj)
{
	//执行确认入库，把stock_into里的status改成1
	string sql = "UPDATE stock_into SET `status`=1,`into_user_id`=?,`into_time`=NOW() WHERE `into_id`=?";
	auto t = sqlSession->executeUpdate(sql, "%s%ull", uObj.getInto_user_id(), uObj.getId());
	//没有改，说明已经入库了
	if (t <= 0)
		return false;
	//确认入库后要查这一批货中每种商品的id和数量，要改变库存清单表的stock(库存)
	string sql2 = "SELECT number,goods_id FROM stock_into_list WHERE into_id=" + to_string(uObj.getId());
	InStorageMapper mapper;
	auto t2 = sqlSession->executeQuery<InStorageDO3, InStorageMapper>(sql2, mapper);
	//获取每种商品的id和数量后，循环依次更改库存清单stock
	for (auto it : t2) {
		string sql3 = "UPDATE stock_goods_sku SET stock=stock+" + it.getNumber() + " WHERE goods_id=" + to_string(it.getGoods_id());
		auto t3 = sqlSession->executeUpdate(sql3);
	}
	return true;
}

// 根据id查询对应的入库单
InStorageDO InStorageDAO::selectById(uint64_t id) {
	string sql = "SELECT a.into_id,a.store_id,a.contract_id,a.title,a.money,a.number,a.intro,a.status,b.name,a.into_time,c.name,a.create_time,a.into_type FROM stock_into a LEFT JOIN fly_sys_user b ON a.into_user_id = b.id LEFT JOIN fly_sys_user c ON a.create_user_id = c.id WHERE a.into_id =" + to_string(id);
	InStorageDetailsMapper mapper;
	auto tmp = sqlSession->executeQuery<InStorageDO, InStorageDetailsMapper>(sql, mapper);
	//id唯一，返回查询的第一个
	InStorageDO ret;
	if (tmp.size() != 0)
		ret = *tmp.begin();
	return ret;
}

uint64_t InStorageDAO::countInStorageList(const InStorageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `stock_into` a ";
	INSTORAGE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<InStorageDO> InStorageDAO::selectWithPage(const InStorageQuery::Wrapper& query)
{
	stringstream sql;
	// 多表查询，通过stock_into表的id在fly_sys_user表查询对应的用户名
	sql << "SELECT a.into_id,a.store_id,a.contract_id,a.title,a.money,a.number,a.intro,a.status,b.name,a.into_time,c.name,a.create_time,a.into_type FROM stock_into a LEFT JOIN fly_sys_user b ON a.into_user_id = b.id LEFT JOIN fly_sys_user c ON a.create_user_id = c.id ";
	INSTORAGE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	InStorageDetailsMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<InStorageDO, InStorageDetailsMapper>(sqlStr, mapper, params);
}

uint64_t InStorageDAO::insert(const InStorageDO& iObj)
{
	/*  入库单生成时未入库
		status:   -1
		into_time:  "1000-01-01 00:00:00"
		into_user_id:  0
		创建时间为当前时间
		create_time:  NOW()
	*/
	string sql = "INSERT INTO `stock_into` (`store_id`, `contract_id`, `title`,	`money`, `number`, `intro`, `status`, `into_user_id`,`into_time`, `into_type`, `create_user_id`, `create_time`) VALUES (?, ?, ?, ?, ?, ?, -1, 0, \"1000-01-01 00:00:00\", ?, ?, NOW())";
	return sqlSession->executeInsert(sql, "%ull%ull%s%d%ull%s%s%ull", iObj.getStore_id(), iObj.getContract_id(), iObj.getTitle(), iObj.getMoney(), iObj.getNumber(), iObj.getIntro(), iObj.getInto_type(), iObj.getCreate_user_id());
}

int InStorageDAO::update(const InStorageDO& uObj)
{
    return 0;
}

int InStorageDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `stock_into` WHERE `into_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}
