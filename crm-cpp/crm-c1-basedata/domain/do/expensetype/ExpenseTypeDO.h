#pragma once
#ifndef _EXPENSETYPE_DO_
#define _EXPENSETYPE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ExpenseTypeDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ��������
	CC_SYNTHESIZE(string, name, Name);
	// ������Ŀ
	CC_SYNTHESIZE(uint64_t, parentID, ParentID);
	// ��λ���
	CC_SYNTHESIZE(int, sort, Sort);
	// �Ƿ�����
	CC_SYNTHESIZE(int, visible, Visible);
	// ����
	CC_SYNTHESIZE(string, intro, Intro);
public:
	ExpenseTypeDO() {
		id = 0;
		name = "";
		sort = 0;
		visible = 1;
		intro = "";
	}
};
/**
 * ����֧���������ݿ�ʵ����
 */
class ExpenseDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ��������
	CC_SYNTHESIZE(string, name, Name);
	// ����ID
	CC_SYNTHESIZE(uint64_t, parentid, Parentid);
	// ��λ���
	CC_SYNTHESIZE(int, sort, Sort);
	// �Ƿ�����
	CC_SYNTHESIZE(int, visible, Visible);
	//���
	CC_SYNTHESIZE(string, intro, Intro);

public:
	ExpenseDO() {
		id = 0;
		name = "";
		parentid = 0;
		sort = 0;
		visible = 1;
		intro = "";
	}
};
#endif // !_EXPENSETYPE_DO_
