#pragma once
#pragma once
#ifndef INVENTORYLISTMAPPER_H__
#define INVENTORYLISTMAPPER_H__

#include "Mapper.h"
#include "domain/do/inventorylist/InventoryListDO.h"


/*
	
*/
class InventoryListMapper : public Mapper<InventoryListDO>
{
public:
	InventoryListDO mapper(ResultSet* resultset) const override {
		InventoryListDO data;		
		data.setGoods_id(resultset->getInt(1));
		data.setSku_id(resultset->getInt(2));
		data.setGoods_name(resultset->getString(3));
		data.setSku_name(resultset->getString(4));
		data.setNumber(resultset->getInt(5));
		data.setCategory_name(resultset->getString(6));
		data.setStore_name(resultset->getString(7));
		data.setSale_price(resultset->getInt(8));
		data.setCost_price(resultset->getInt(9));
		data.setCost_amount(resultset->getInt(10));
		data.setAnticipated_profit(resultset->getInt(11));
		data.setOriginal_code(resultset->getString(12));
		return data;
	}
};  

#endif // EXPENDITURESMAPPER_H__