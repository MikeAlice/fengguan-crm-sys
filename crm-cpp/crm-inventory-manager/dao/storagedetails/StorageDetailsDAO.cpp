#include "stdafx.h"
#include "StorageDetailsDAO.h"
#include "StorageDetailsMapper.h"
namespace sqlHelpers {
	/*
	* 描述：添加IN后的()
	* 示例：在"SELECT xxx FROM xxx WHERE xxx IN "的后面
	*		添加(1,2,3,4)
	* 参数：sql语句、dto对象
	* 注意：list_id！
	*/
	template<typename T>
	void insertIdList(stringstream& sql, T& dto)
	{
		sql << "(";
		for (auto i = dto->begin(); i != dto->end(); i++)
		{
			if (i != dto->begin())	sql << ",";
			sql << (*i)->list_id.getValue({});
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

	// Type Judge
	/*template<typename, typename> struct is_same : public false_type {};
	template<typename _Tp> struct is_same<_Tp, _Tp> : public true_type {};
	template<typename QueryT,typename... Args>
	void SQL_splicing(const QueryT& query,stringstream& sql,Args&&...args)
	{
		if constexpr (is_same<std::string, Args>::value)
		{

		}
		else if(is_same<std::string, Args>::value)

	}*/
}
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->goods_id) { \
	sql << " AND sil.goods_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->goods_id.getValue(0)); \
} \
if (query->sku_id) { \
	sql << " AND sil.sku_id=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->sku_id.getValue(0)); \
} \
if (query->goods_name) { \
	sql << " AND sil.goods_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->goods_name.getValue("")); \
}\
if (query->sku_name) { \
	sql << " AND sil.sku_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sku_name.getValue("")); \
}\
if (query->number) { \
	sql << " AND sil.number=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->number.getValue(0)); \
}\
if (query->category_name) { \
	sql << " AND fgc.category_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->category_name.getValue("")); \
}\
if (query->store_name) { \
	sql << " AND ss.name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->store_name.getValue("")); \
}\
if (query->into_intro) { \
	sql << " AND si.intro=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->into_intro.getValue("")); \
}\
if (query->into_time) { \
	sql << " AND sil.into_time=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->into_time.getValue("")); \
}\
if (query->remarks) { \
	sql << " AND sil.remarks=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->remarks.getValue("")); \
}\
if (query->supplier_name) { \
	sql << " AND susu.name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->supplier_name.getValue("")); \
}


std::list<StorageDetailsDO> StorageDetailsDAO::selectWithPage(const StorageDetailsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT sil.goods_id,sil.sku_id,sil.goods_name,sil.sku_name,sil.number,fgc.category_name,ss.name,si.intro,sil.into_time,sil.remarks,susu.name "
		"FROM stock_into_list sil "
		"LEFT JOIN fly_goods fg ON sil.goods_id=fg.goods_id "
		"LEFT JOIN fly_goods_category fgc ON fg.category_id=fgc.category_id "
		"LEFT JOIN stock_store ss ON sil.store_id=ss.store_id "
		"LEFT JOIN stock_into si ON sil.into_id=si.into_id "
		"LEFT JOIN sup_supplier susu ON fg.supplier_id=susu.supplier_id ";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	StorageDetailsMapper mapper;
	string sqlStr = sql.str();
	cout << sqlStr;
	return sqlSession->executeQuery<StorageDetailsDO, StorageDetailsMapper>(sqlStr, mapper, params);
}

uint64_t StorageDetailsDAO::count(const StorageDetailsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) "
		"FROM stock_into_list sil "
		"LEFT JOIN fly_goods fg ON sil.goods_id=fg.goods_id "
		"LEFT JOIN fly_goods_category fgc ON fg.category_id=fgc.category_id "
		"LEFT JOIN stock_store ss ON sil.store_id=ss.store_id "
		"LEFT JOIN stock_into si ON sil.into_id=si.into_id "
		"LEFT JOIN sup_supplier susu ON fg.supplier_id=susu.supplier_id ";
	SAMPLE_TERAM_PARSE(query, sql);
	StorageDetailsMapper mapper;
	string sqlStr = sql.str();
	cout << sqlStr;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<StorageDetailsDO> StorageDetailsDAO::selectWithIdList(const oatpp::List<ExportStorageDetailsDTO::Wrapper>& dto)
{
	stringstream sql;
	sql << "SELECT sil.goods_id,sil.sku_id,sil.goods_name,sil.sku_name,sil.number,fgc.category_name,ss.name,si.intro,sil.into_time,sil.remarks,susu.name "
		"FROM stock_into_list sil "
		"LEFT JOIN fly_goods fg ON sil.goods_id=fg.goods_id "
		"LEFT JOIN fly_goods_category fgc ON fg.category_id=fgc.category_id "
		"LEFT JOIN stock_store ss ON sil.store_id=ss.store_id "
		"LEFT JOIN stock_into si ON sil.into_id=si.into_id "
		"LEFT JOIN sup_supplier susu ON fg.supplier_id=susu.supplier_id "
		"WHERE list_id IN ";
	sqlHelpers::insertIdList(sql, dto);
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	StorageDetailsMapper mapper;
	return sqlSession->executeQuery<StorageDetailsDO, StorageDetailsMapper>(sqlStr, mapper);
}
