#ifndef _FeeIncomeTreeMapper_H_
#define _FeeIncomeTreeMapper_H_

#include "tree/TreeNodeMapper.h"
#include "domain/do/expensetype/ExpenseTypeDO.h"
#include "domain/dto/expensetype/ExpenseTypeDTO.h"

/**
 * �����������ͽṹ�������ֶ�ƥ��ʵ��
 */
class ExpenseTreeMapper : public TreeNodeMapper<ExpenseDO>
{
public:
	shared_ptr<TreeNode> objectMapper(ExpenseDO* source) const override
	{
		// ����������ݶ���
		auto res = make_shared<ExpenseTreeDTO>();
		// ����㼶�ṹ����ӳ��
		if (source->getId())
			res->_id(std::to_string(source->getId()));
		if (source->getParentid())
			res->_pid(std::to_string(source->getParentid()));
		// ��չ����ӳ��
		res->id = source->getId();
		res->parentid = source->getParentid();
		res->name = source->getName();
		res->sort = source->getSort();
		res->visible = source->getVisible();
		res->intro = source->getIntro();
		return res;
	}

};

#endif // !_TREEMENUMAPPER_H_