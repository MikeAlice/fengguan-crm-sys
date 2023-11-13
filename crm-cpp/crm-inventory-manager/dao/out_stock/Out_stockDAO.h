#pragma once

#ifndef _OUTSTOCK_DAO_
#define _OUTSTOCK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/out_stock/Out_stockDO.h"
#include "../../domain/query/out_stock/Out_StockQuery.h"
#include "../../domain/dto/out_stock/Out_stockDTO.h"

/**
 * ���ⵥ���ݿ����ʵ��
 */
class Out_stockDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t counts(const Out_StockQuery::Wrapper& query);

	// ��ҳ��ѯ���ⵥ�б� �����ˣ�С��
	list<Out_StockPagDO> selectWithPage(const Out_StockQuery::Wrapper& query);

	// ͨ��id��ѯ������ϸ �����ˣ�С��
	list<Out_StocDetailDO> selectById(const string& id);

	// ��ӳ��ⵥ �����ˣ�С��
	uint64_t insert(const AddOut_StockDO& iObj);

};

#endif // !_OUTSTOCK_DAO_