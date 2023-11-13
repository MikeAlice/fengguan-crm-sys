#ifndef _FeeIncomeTreeMapper_H_
#define _FeeIncomeTreeMapper_H_

#include "tree/TreeNodeMapper.h"
#include "domain/do/feeincome/FeeIncomeDO.h"
#include "domain/dto/feeincome/FeeIncomeDTO.h"

/**
 * 费用收入类型结构树数据字段匹配实现
 */
class FeeIncomeTreeMapper : public TreeNodeMapper<FeeIncomeDO>
{
public:
	shared_ptr<TreeNode> objectMapper(FeeIncomeDO* source) const override
	{
		// 创建结果数据对象
		auto res = make_shared<FeeIncomeTreeDTO>();
		// 计算层级结构属性映射
		if (source->getId())
			res->_id(std::to_string(source->getId()));
		if(source->getParentid())
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