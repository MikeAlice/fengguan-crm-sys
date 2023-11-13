#pragma once

#ifndef _OUTSTOCK_DAO_
#define _OUTSTOCK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/out_bound/Out_boundDO.h"
#include "../../domain/query/out_bound/Out_boundQuery.h"
#include "../../domain/dto/out_bound/Out_boundDTO.h"

/**
 * ���ⵥ���ݿ����ʵ��
 */
class Out_boundDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const Out_boundQuery::Wrapper& query);

	// ȷ�ϳ��⣨�޸ĳ���״̬�� �����ˣ�ǧ��
	uint64_t update(const Out_boundDO& uObj);
	// ɾ�����ⵥ��ͨ�����ⵥIDɾ�����ݣ� �����ˣ�ǧ��
	uint64_t removeData(const oatpp::List<DelOut_boundDTO::Wrapper>& dto);
};
#endif // !_OUTSTOCK_DAO_