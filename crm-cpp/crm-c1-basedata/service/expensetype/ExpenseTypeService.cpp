#include "stdafx.h"
#include "ExpenseTypeService.h"
#include "../../dao/expensetype/ExpenseTypeDAO.h"
#include"ExpenseTreeMapper.h"
#include"tree/TreeUtil.h"
ExpenseTypePageDTO::Wrapper ExpenseTypeService::listAll(const ExpenseTypeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ExpenseTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ExpenseTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ExpenseTypeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ExpenseTypeDO sub : result)
	{
		auto dto = ExpenseTypeDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, parentID, ParentID, sort, Sort, visible, Visible, intro, Intro)
			pages->addData(dto);

	}
	return pages;
}
//ExpenseTypePageDTO::Wrapper ExpenseTypeService::listAll(const ExpenseTypeQuery::Wrapper& query)
//{
//	// 构建返回对象
//	auto pages = ExpenseTypePageDTO::createShared();
//	pages->pageIndex = query->pageIndex;
//	pages->pageSize = query->pageSize;
//
//	// 查询数据总条数
//	ExpenseTypeDAO dao;
//	uint64_t count = dao.count(query);
//	if (count <= 0)
//	{
//		return pages;
//	}
//
//	// 分页查询数据
//	pages->total = count;
//	pages->calcPages();
//	list<ExpenseTypeDO> result = dao.selectWithPage(query);
//	// 将DO转换成DTO
//	for (ExpenseTypeDO sub : result)
//	{
//		auto dto = ExpenseTypeDTO::createShared();
//		// 		dto->id = sub.getId();
//		// 		dto->name = sub.getName();
//		// 		dto->sex = sub.getSex();
//		// 		dto->age = sub.getAge();
//		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,bank_id,Bank_Id, name, Name, card, Card, holders, Holders, sort, Sort, visible, Visible)
//		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, parentID, ParentID, sort, Sort,visible, Visible, intro, Intro)
//			pages->addData(dto);
//
//	}
//	return pages;
//}

uint64_t ExpenseTypeService::saveData(const ExpenseTypeDTO::Wrapper& dto)
{
	// 组装DO数据
	ExpenseTypeDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Name, name, ParentID, parentID, Sort, sort, Visible, visible, Intro, intro)
		// 执行数据添加
		ExpenseTypeDAO dao;
	return dao.insert(data);
}

bool ExpenseTypeService::updateData(const ExpenseTypeDTO::Wrapper& dto)
{
	// 组装DO数据
	ExpenseTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Name, name, ParentID, parentID, Sort, sort, Visible, visible, Intro, intro);
	// 执行数据修改
		ExpenseTypeDAO dao;
	return dao.update(data) == 1;
}

bool ExpenseTypeService::removeData(uint64_t id)
{
	ExpenseTypeDAO dao;
	return dao.deleteById(id) == 1;
}
ExpenseTreeJsonVO::Wrapper ExpenseService::listTree(const ExpenseQuery::Wrapper& query)
{
	// 构建返回对象
	auto vo = ExpenseTreeJsonVO::createShared();
	ExpenseDAO dao;
	//执行查询
	list<ExpenseDO> result = dao.selectTree(query);

	/*这里是先将查询出来的顶层节点的parentid变成0（即转换成根节点, 目的是为了配合下面listToTree函数的机制）
		如查询结果parentid为  16 16 16 19 19
		下面这段会把16 16 16先变成0
	*/
	int64_t pre_pid;
	int64_t true_pid = 0;
	std::cout << result.size() << '\n';
	if (!result.empty())
	{
		pre_pid = result.front().getParentid();
		true_pid = result.front().getParentid();
	}
	for (auto it = result.begin(); it != result.end(); it++)
	{

		if (it->getParentid() == pre_pid)
		{
			it->setParentid(0);
		}
		else break;

	}

	// 转换为树形结构，res里实际存放了森林的所有根节点
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<ExpenseDO>(result, ExpenseTreeMapper());

	// 将根节点存储到列表中
	for (auto one : res)
	{
		//std::cout << one.get()->_id()<<'\n';
		auto true_data = ExpenseTreeDTO::Wrapper(dynamic_pointer_cast<ExpenseTreeDTO>(one), ExpenseTreeDTO::Wrapper::Class::getType());
		//把正确的parentid改回来
		true_data->parentid = true_pid;
		vo->data->push_back(true_data);
	}
	return vo;


}

