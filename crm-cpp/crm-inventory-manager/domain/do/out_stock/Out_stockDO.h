#pragma once
#ifndef _OUT_STOCK_DO_
#define _OUT_STOCK_DO_
#include "../DoInclude.h"

/**
 * 出库单数据库实体类
 */
class Out_stockDO
{
	// 出库单id
	CC_SYNTHESIZE(uint16_t, out_id, Out_id);
	// 仓库编号
	CC_SYNTHESIZE(uint16_t, store_id, Store_id);
	// 销售合同编号
	CC_SYNTHESIZE(uint16_t, contract_id, Contract_id);
	// 订单主题
	CC_SYNTHESIZE(string, title, Title);
	// 金额
	CC_SYNTHESIZE(double, money, Money);
	// 数量
	CC_SYNTHESIZE(uint16_t, number, Number);
	// 订单介绍
	CC_SYNTHESIZE(string, intro, Intro);
	// 出库状态：1=已出库，0=未出库
	CC_SYNTHESIZE(uint16_t, status, Status);
	// 出库管理员
	CC_SYNTHESIZE(uint16_t, out_user_id, Out_user_id);
	// 出库时间
	CC_SYNTHESIZE(string, out_time, Out_time);
	// 出库类型
	CC_SYNTHESIZE(string, out_type, Out_type);
	// 创建人
	CC_SYNTHESIZE(uint16_t, create_user_id, Create_user_id);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);


public:
	Out_stockDO() {
		out_id = 0;
		store_id = 0;
		contract_id = 0;
		title = "";
		money = 0.00;
		number = 0;
		intro = "";
		status = -1;
		out_user_id = 0;
		out_time = "";
		out_type = "";
		create_user_id = 0;
		create_time = "";
	}
};
/**
 * 查询分页出库列表
 */
class Out_StockPagDO
{
	//对应出库单号
	CC_SYNTHESIZE(int32_t, out_stock_id, Out_Stock_Id);
	//出库数量
	CC_SYNTHESIZE(int32_t, number, Number);
	//出库状态
	CC_SYNTHESIZE(int32_t, status, Status);
	//出库时间
	CC_SYNTHESIZE(string, out_time, Out_Time);
	//仓库名称
	CC_SYNTHESIZE(string, store_name, Store_Name);
	// 备注
	CC_SYNTHESIZE(string, remarks, Remarks);
	// 供应商
	CC_SYNTHESIZE(string, supplier_name, Supplier_Name);
	// 出库人员
	CC_SYNTHESIZE(string, out_stock_person, Out_Stock_Person);
	//创建人
	CC_SYNTHESIZE(int32_t, create_user_id, Create_User_Id);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_Time);
	//出库类型
	CC_SYNTHESIZE(string, out_type, Out_Type);
	//对应出库单
	CC_SYNTHESIZE(string, out_stock_order, Out_Stock_Order);

public:
	Out_StockPagDO() {
		out_stock_id = 0;
		number = 0;
		status = 0;
		out_time = "";
		remarks = "";
		supplier_name = "";
		out_stock_person = "";
		out_type = "";
		create_user_id = 0;
		create_time = "";
		out_stock_order = "";
	}
};
/**
 * 查询出库单明细
 */
class Out_StocDetailDO {
	//对应出库单号
	CC_SYNTHESIZE(int32_t, out_stock_id, Out_Stock_Id);
	//仓库名称
	CC_SYNTHESIZE(string, store_name, Store_Name);
	//商品编号
	CC_SYNTHESIZE(uint64_t, goods_id, Goods_Id);
	//SKUID
	CC_SYNTHESIZE(uint64_t, sku_id, Sku_Id);
	//商品名称
	CC_SYNTHESIZE(string, goods_name, Goods_Name);
	//SKU名称
	CC_SYNTHESIZE(string, sku_name, Sku_Name);
	//出库数量
	CC_SYNTHESIZE(int32_t, number, Number);
	//出库时间
	CC_SYNTHESIZE(string, out_time, Out_Time);
	//商品类型
	CC_SYNTHESIZE(string, category_name, Category_Name);
	//对应出库单
	CC_SYNTHESIZE(string, out_stock_order, Out_Stock_Order);
	// 备注
	CC_SYNTHESIZE(string, remarks, Remarks);
	// 供应商
	CC_SYNTHESIZE(string, supplier_name, Supplier_Name);
public:
	Out_StocDetailDO() {
		out_stock_id = 0;
		store_name = "";
		goods_id = 0;
		sku_id = 0;
		goods_name = "";
		sku_name = "";
		category_name = "";
		out_stock_order = "";
		number = 0;
		out_time = "";
		remarks = "";
		supplier_name = "";
	}

};
/**
 * 添加出库单
 */
class AddOut_StockDO
{
	//出库数量
	CC_SYNTHESIZE(int32_t, number, Number);
	//出库状态
	CC_SYNTHESIZE(int32_t, status, Status);
	//出库时间
	CC_SYNTHESIZE(string, out_time, Out_Time);
	//仓库名称
	CC_SYNTHESIZE(string, store_name, Store_Name);
	// 备注
	//CC_SYNTHESIZE(string, remarks, Remarks);
	// 供应商
	//CC_SYNTHESIZE(string, supplier_name, Supplier_Name);
	// 出库人员
	CC_SYNTHESIZE(string, out_stock_person, Out_Stock_Person);
	//创建人
	CC_SYNTHESIZE(int32_t, create_user_id, Create_User_Id);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_Time);
	//出库类型
	CC_SYNTHESIZE(string, out_type, Out_Type);
	//对应出库单
	//CC_SYNTHESIZE(string, out_stock_order, Out_Stock_Order);
public:
	AddOut_StockDO() {
		number = 0;
		status = 0;
		out_time = "";
		//remarks = "";
		//supplier_name = "";
		out_stock_person = "";
		out_type = "";
		create_user_id = 0;
		create_time = "";
		//out_stock_order = "";
	}

};
#endif // !_OUT_STOCK_DO_