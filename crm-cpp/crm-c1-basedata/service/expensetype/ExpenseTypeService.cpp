#include "stdafx.h"
#include "ExpenseTypeService.h"
#include "../../dao/expensetype/ExpenseTypeDAO.h"
#include"ExpenseTreeMapper.h"
#include"tree/TreeUtil.h"
ExpenseTypePageDTO::Wrapper ExpenseTypeService::listAll(const ExpenseTypeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ExpenseTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ExpenseTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ExpenseTypeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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
//	// �������ض���
//	auto pages = ExpenseTypePageDTO::createShared();
//	pages->pageIndex = query->pageIndex;
//	pages->pageSize = query->pageSize;
//
//	// ��ѯ����������
//	ExpenseTypeDAO dao;
//	uint64_t count = dao.count(query);
//	if (count <= 0)
//	{
//		return pages;
//	}
//
//	// ��ҳ��ѯ����
//	pages->total = count;
//	pages->calcPages();
//	list<ExpenseTypeDO> result = dao.selectWithPage(query);
//	// ��DOת����DTO
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
	// ��װDO����
	ExpenseTypeDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Name, name, ParentID, parentID, Sort, sort, Visible, visible, Intro, intro)
		// ִ���������
		ExpenseTypeDAO dao;
	return dao.insert(data);
}

bool ExpenseTypeService::updateData(const ExpenseTypeDTO::Wrapper& dto)
{
	// ��װDO����
	ExpenseTypeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Name, name, ParentID, parentID, Sort, sort, Visible, visible, Intro, intro);
	// ִ�������޸�
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
	// �������ض���
	auto vo = ExpenseTreeJsonVO::createShared();
	ExpenseDAO dao;
	//ִ�в�ѯ
	list<ExpenseDO> result = dao.selectTree(query);

	/*�������Ƚ���ѯ�����Ķ���ڵ��parentid���0����ת���ɸ��ڵ�, Ŀ����Ϊ���������listToTree�����Ļ��ƣ�
		���ѯ���parentidΪ  16 16 16 19 19
		������λ��16 16 16�ȱ��0
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

	// ת��Ϊ���νṹ��res��ʵ�ʴ����ɭ�ֵ����и��ڵ�
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<ExpenseDO>(result, ExpenseTreeMapper());

	// �����ڵ�洢���б���
	for (auto one : res)
	{
		//std::cout << one.get()->_id()<<'\n';
		auto true_data = ExpenseTreeDTO::Wrapper(dynamic_pointer_cast<ExpenseTreeDTO>(one), ExpenseTreeDTO::Wrapper::Class::getType());
		//����ȷ��parentid�Ļ���
		true_data->parentid = true_pid;
		vo->data->push_back(true_data);
	}
	return vo;


}

