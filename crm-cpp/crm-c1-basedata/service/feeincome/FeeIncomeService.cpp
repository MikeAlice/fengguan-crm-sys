#include "stdafx.h"
#include "FeeIncomeService.h"
#include "dao/feeincome/FeeIncomeDAO.h"
#include "FeeIncomeTreeMapper.h"
#include "domain/vo/feeincome/FeeIncomeTreeVO.h"
#include "tree/TreeUtil.h"
#include <queue>

FeeIncomeTreeJsonVO::Wrapper FeeIncomeService::listTree(const FeeIncomeQuery::Wrapper& query)
{
	// 构建返回对象
	auto vo = FeeIncomeTreeJsonVO::createShared();
	FeeIncomeDAO dao;
	//执行查询
	list<FeeIncomeDO> result = dao.selectTree(query);

	/*这里是先将查询出来的顶层节点的parentid变成0（即转换成根节点, 目的是为了配合下面listToTree函数的机制）
		如查询结果parentid为  16 16 16 19 19
		下面这段会把16 16 16先变成0
	*/
	int64_t pre_pid;
	int64_t true_pid = 0;
	std::cout << result.size()<<'\n';
	if (!result.empty())
	{
		pre_pid = result.front().getParentid();
		true_pid = result.front().getParentid();
	}
	for (auto it = result.begin();it!=result.end();it++)
	{

		if (it->getParentid() == pre_pid)
		{
			it->setParentid(0);
		}
		else break;

	}

	// 转换为树形结构，res里实际存放了森林的所有根节点
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<FeeIncomeDO>(result,FeeIncomeTreeMapper() );

	// 将根节点存储到列表中
	for (auto one : res)
	{
		//std::cout << one.get()->_id()<<'\n';
		auto true_data = FeeIncomeTreeDTO::Wrapper(dynamic_pointer_cast<FeeIncomeTreeDTO>(one), FeeIncomeTreeDTO::Wrapper::Class::getType());
		//把正确的parentid改回来
		true_data->parentid = true_pid;
		vo->data->push_back(true_data);
	}
	return vo;
	
	
}
// 分页查询所有数据
FeeIncomePageDTO::Wrapper FeeIncomeService::listAll(const FeeIncomeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = FeeIncomePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	FeeIncomeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<FeeIncomeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (FeeIncomeDO sub : result)
	{
		auto dto = FeeIncomeDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, parentid, Parentid, sort, Sort, visible, Visible, intro, Intro)
			pages->addData(dto);
	}
	return pages;
}


uint64_t FeeIncomeService::saveData(const FeeIncomeDTO::Wrapper& dto)
{
	// 组装DO数据
	FeeIncomeDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Id, id, Name, name, Parentid, parentid, Sort, sort, Visible, visible, Intro, intro)
		// 执行数据添加
		FeeIncomeDAO dao;
	return dao.insert(data);
}

bool FeeIncomeService::updateData(const FeeIncomeDTO::Wrapper& dto)
{
	// 组装DO数据
	FeeIncomeDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Name, name, Parentid, parentid, Sort, sort, Visible, visible, Intro, intro)
		// 执行数据修改
		FeeIncomeDAO dao;
	return dao.update(data) == 1;
}

bool FeeIncomeService::removeData(uint64_t id)
{
	FeeIncomeDAO dao;
	return dao.deleteById(id) == 1;
}


