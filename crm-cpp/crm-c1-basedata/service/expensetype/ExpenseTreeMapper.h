#ifndef _FeeIncomeTreeMapper_H_
#define _FeeIncomeTreeMapper_H_

#include "tree/TreeNodeMapper.h"
#include "domain/do/expensetype/ExpenseTypeDO.h"
#include "domain/dto/expensetype/ExpenseTypeDTO.h"

/**
 * 费用收入类型结构树数据字段匹配实现
 */
class ExpenseTreeMapper : public TreeNodeMapper<ExpenseDO>
{
public:
	shared_ptr<TreeNode> objectMapper(ExpenseDO* source) const override
	{
		// 创建结果数据对象
		auto res = make_shared<ExpenseTreeDTO>();
		// 计算层级结构属性映射
		if (source->getId())
			res->_id(std::to_string(source->getId()));
		if (source->getParentid())
			res->_pid(std::to_string(source->getParentid()));
		// 扩展属性映射
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