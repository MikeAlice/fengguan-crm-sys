#pragma once

#ifndef OUT_BOUNDSERVICE_H_
#define OUT_BOUNDSERVICE_H_

#include "domain/dto/out_bound/Out_boundDTO.h"
/**
 * ���ⵥ����ʵ��
 */
class Out_boundService
{
public:
	// ȷ�ϳ��⣨�޸ĳ���״̬�� �����ˣ�ǧ��
	uint64_t updateData(const ConfOut_boundDTO::Wrapper& dto);
	// ɾ�����ⵥ��ͨ�����ⵥIDɾ�����ݣ� �����ˣ�ǧ��
	uint64_t removeData(const oatpp::List<DelOut_boundDTO::Wrapper>& dto);
};

#endif // !OUT_BOUNDSERVICE_H_