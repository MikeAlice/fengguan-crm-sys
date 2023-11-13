#pragma once

#ifndef OUT_STOCKSERVICE_H_
#define OUT_STOCKSERVICE_H_

#include "domain/dto/out_stock/Out_stockDTO.h"
#include"domain/query/out_stock/Out_StockQuery.h"
#include"domain/vo/out_stock/Out_StockPageJsonVO.h"
/**
 * ���ⵥ����ʵ��
 */
class Out_stockService
{
public:
	// ��ҳ��ѯ�����б�		�����ˣ�С��
	Out_StockPageDTO::Wrapper listAll(const Out_StockQuery::Wrapper& query);
	//��ѯ������ϸ			�����ˣ�С��
	Out_stockDTO::Wrapper queryone(const string& id);
	// ��ӳ��ⵥ			�����ˣ�С��
	bool addData(const AddOut_stock::Wrapper& dto);

};

#endif // !OUT_STOCKSERVICE_H_