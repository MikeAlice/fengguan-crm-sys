#include "stdafx.h"
#include "ContractGoodsDAO.h"
#include "ContractGoodsMapper.h"
#include <sstream>

/** 查询合同清单，需要 获取一个合同的商品名称、商品规格、价格、购买数量、总价以及备注
* 数据库 zocrm_sys
* 相关表：
*	sal_contract (sc) 销售合同表，可通过合同编号contract_no获取合同ID contract_id
*	sal_contract_list (scl) 销售合同明细表，可通过合同ID获取商品ID goods_id，商品名称goods_name，商品规格（SKU名称）sku_name，价格sale_price，购买数量num，总价goods_money，备注remarks；
* 查询语句：
*	SELECT 
*		scl.goods_name, scl.sku_name, scl.sale_price, scl.num, scl.goods_money, scl.remarks
*	FROM 
*		sal_contract_list AS scl
*	RIGHT JOIN
*		(SELECT contract_id FROM sal_contract WHERE contract_no = %s) AS sc
*	ON 
*		scl.contract_id = sc.contract_id
*/

uint64_t ContractGoodsDAO::count(const ContractGoodsQuery::Wrapper& query) {
	//cout << query->contract_no.getValue("") << "11313111"; // swagger中参数传不进来？Controller中参数应为QUERY，但设成了PATH，现在改过来了
	string sql;
	sql = "SELECT COUNT(*) FROM sal_contract_list AS scl RIGHT JOIN (SELECT contract_id FROM sal_contract WHERE contract_no = ?) AS sc ON scl.contract_id = sc.contract_id";
		// 写成多行的形式出现 ExecuteQuery Exception. MySQL_Prepared_Statement::setString: invalid 'parameterIndex' 的错误
		//"SELECT "
		//"COUNT(*) "
		//"FROM "
		//"sal_contract_list AS scl "
		//"RIGHT JOIN "
		//"(SELECT contract_id FROM sal_contract WHERE contract_no = '?') AS sc "
		//"ON "
		//"scl.contract_id = sc.contract_id ";
	return sqlSession->executeQueryNumerical(sql, "%s", query->contract_no.getValue(""));
}

// 分页查询数据
list<ContractGoodsDO> ContractGoodsDAO::selectWithPage(const ContractGoodsQuery::Wrapper& query) {
	string sql;
	sql = "SELECT scl.goods_name, scl.sku_name, scl.sale_price, scl.num, scl.goods_money, scl.remarks FROM sal_contract_list AS scl RIGHT JOIN (SELECT contract_id FROM sal_contract WHERE contract_no = ? ) AS sc ON scl.contract_id = sc.contract_id LIMIT ? , ? ";
	ContractGoodsMapper mapper;
	return sqlSession->executeQuery<ContractGoodsDO, ContractGoodsMapper>(sql, mapper, "%s%ull%ull", \
		query->contract_no.getValue(""), ((query->pageIndex - 1) * query->pageSize), query->pageSize);
}