#pragma once
/*
* �����ˣ��Ͼ�
*/
#include "stdafx.h"
#ifndef _FIELDEXT_DO_
#define _FIELDEXT_DO_
#include "../DoInclude.h"

/**
 * ��չ�ֶ�ʵ���� ��Ӧ�ֶ���չ��
 */
class FieldExtDO
{
	// �Ƿ������ֶ�   1��ʾ����,2��ʾ����
	CC_SYNTHESIZE(int32_t, visible, Visible);


public:
	FieldExtDO() {
		visible = 0;
	}
};
#endif // !_CUSTOMEREXT_DO_
