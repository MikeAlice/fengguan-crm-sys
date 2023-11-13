#include "stdafx.h"
#include "OutboundDAO.h"
#include "OutboundDetailMapper.h"
#include<sstream>

//入库单明细表->商品表->供应商
//条件解析宏
#define OUTBOUNDDETAIL_TREAM_PARSE(query,sql)\
SqlParams params;\
sql<<"WHERE 1=1 ";\
if(query->SKUname){\
	sql<<" AND a.sku_name=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->SKUname.getValue(""));\
}\
if(query->supplierName){\
	sql<<" AND = b.name=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->supplierName.getValue(""));\
}\
if(query->contactAdd){\
	sql<<" AND =b.address";\
	SQLPARAMS_PUSH(params,"s",std::string,query->contactAdd.getValue(""));\
}\

uint64_t OutboundDetailDAO::count(const OutboundDetailQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT count(*)"
		"FROM stock_out_list a "
		"LEFT JOIN pos_contract b on a.contract_id=b.contract_id "
		"LEFT JOIN sup_supplier c ON b.supplier_id = c.supplier_id "
		"LEFT JOIN fly_goods d ON a.goods_id = d.goods_id "
		"LEFT JOIN fly_goods_category e ON d.category_id = e.category_id "
		"LEFT JOIN stock_store f ON a.store_id = f.store_id ";
	OUTBOUNDDETAIL_TREAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<OutboundDetailDO> OutboundDetailDAO::selectWithPage(const OutboundDetailQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT a.sku_id,a.goods_id,a.sku_name,d.goods_name,a.number,e.category_name,f.name,a.out_id,a.out_time,a.remarks "
		"FROM stock_out_list a "
		"LEFT JOIN pos_contract b on a.contract_id=b.contract_id "
		"LEFT JOIN sup_supplier c ON b.supplier_id = c.supplier_id "
		"LEFT JOIN fly_goods d ON a.goods_id = d.goods_id "
		"LEFT JOIN fly_goods_category e ON d.category_id = e.category_id "
		"LEFT JOIN stock_store f ON a.store_id = f.store_id ";
	OUTBOUNDDETAIL_TREAM_PARSE(query, sql);
	sql << "LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	OutboundDetailMapper mapper;
	string  sqlStr = sql.str();
	return sqlSession->executeQuery<OutboundDetailDO, OutboundDetailMapper>(sqlStr, mapper, params);
}

std::list<OutboundDetailDO> OutboundDetailDAO::selectWithId(const oatpp::List<ExportOutboundDetailsDTO::Wrapper>& exportt)
{
	stringstream sql;
	sql << "SELECT a.sku_id,a.goods_id,a.sku_name,d.goods_name,a.number,e.category_name,f.name,a.out_id,a.out_time,a.remarks "
		"FROM stock_out_list a "
		"LEFT JOIN pos_contract b on a.contract_id=b.contract_id "
		"LEFT JOIN sup_supplier c ON b.supplier_id = c.supplier_id "
		"LEFT JOIN fly_goods d ON a.goods_id = d.goods_id "
		"LEFT JOIN fly_goods_category e ON d.category_id = e.category_id "
		"LEFT JOIN stock_store f ON a.store_id = f.store_id IN(";
	for (auto i = exportt->begin(); i != exportt->end(); i++) {
		if (i != exportt->begin()) sql << ",";
		sql << (*i)->list_id.getValue({});
	}
	sql << ")";
	string sqlStr = sql.str();
	//std::cout << sql.str() << std::endl << std::endl;
	OutboundDetailMapper mapper;
	return sqlSession->executeQuery<OutboundDetailDO, OutboundDetailMapper>(sqlStr, mapper);
}

