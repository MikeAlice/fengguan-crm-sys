#pragma once

#ifndef _DICT_DO_
#define _DICT_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����-�ֵ����
 */
class DictDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// �ֵ�����
	CC_SYNTHESIZE(string, name, Name);
	// ��������
	CC_SYNTHESIZE(string, typetag, Typetag);
	// ����
	CC_SYNTHESIZE(int, sort, Sort);
	// �Ƿ�����
	CC_SYNTHESIZE(int, visible, Visible);
public:
	DictDO() {
		id = 0;
		name = "";
		typetag = "";
		sort = 1;
		visible = 0;
	}
};

#endif // !_DICT_DO_