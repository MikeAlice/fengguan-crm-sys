#pragma once

#ifndef _OUT_STOCK_MAPPER_
#define _OUT_STOCK_MAPPER_

#include "Mapper.h"
#include "../../domain/do/out_stock/Out_stockDO.h"

/**
 * 出库单数据表字段匹配映射
 */
class Out_stockMapper1 : public Mapper<Out_StockPagDO>
{
public:
	Out_StockPagDO mapper(ResultSet* resultSet) const override
	{
		Out_StockPagDO data;
		data.setOut_Stock_Id(resultSet->getInt(1));
		data.setStore_Name(resultSet->getString(2));
		data.setNumber(resultSet->getInt(3));
		data.setStatus(resultSet->getInt(4));
		data.setCreate_User_Id(resultSet->getInt(5));
		data.setCreate_Time(resultSet->getString(6));
		data.setOut_Type(resultSet->getString(7));
		data.setOut_Time(resultSet->getString(8));
		data.setOut_Stock_Person(resultSet->getString(9));
		data.setRemarks(resultSet->getString(10));
		//data.setSupplier_Name(resultSet->getString(11));

		return data;
	}
};
class Out_stockMapper2 : public Mapper<Out_StocDetailDO>
{
public:
	Out_StocDetailDO mapper(ResultSet* resultSet) const override
	{
		Out_StocDetailDO data;
		data.setOut_Stock_Id(resultSet->getInt(1));
		data.setStore_Name(resultSet->getString(2));
		data.setGoods_Id(resultSet->getUInt64(3));
		data.setGoods_Name(resultSet->getString(4));
		data.setSku_Id(resultSet->getUInt64(5));
		data.setSku_Name(resultSet->getString(6));
		data.setNumber(resultSet->getInt(7));
		data.setRemarks(resultSet->getString(8));
		data.setOut_Time(resultSet->getString(9));
		data.setCategory_Name(resultSet->getString(10));
		return data;
	}

};
#endif // !_OUT_STOCK_MAPPER_