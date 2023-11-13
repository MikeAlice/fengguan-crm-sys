#pragma once
#pragma once
#ifndef EXPENDITURESMAPPER_H__
#define EXPENDITURESMAPPER_H__

#include "Mapper.h"
#include "../../domain/do/outbounddetail/OutboundDetailDO.h"


/*
	 ’æ›◊÷∂Œ∆•≈‰”≥…‰
*/
class OutboundDetailMapper : public Mapper<OutboundDetailDO>
{
public:
	OutboundDetailDO mapper(ResultSet* resultSet) const override {
		OutboundDetailDO data;
		data.setSkuid(resultSet->getInt(1));
		data.setSkuname(resultSet->getString(2));
		data.setGoodsName(resultSet->getString(3));
		data.setGoodsId(resultSet->getInt(4));
		data.setNumber(resultSet->getInt(5));
		data.setCommodityType(resultSet->getString(6));
		data.setStorehouse(resultSet->getString(7));
		data.setStockOut(resultSet->getInt64(8));
		data.setStockOutTime(resultSet->getString(9));
		data.setNote(resultSet->getString(10));
		//data.setSupplierName(resultSet->getString(10));
		//data.setContactAdd(resultSet->getString(11));
		return data;
	}
};


#endif // EXPENDITURESMAPPER_H__
