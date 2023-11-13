#include "stdafx.h"
#include "FeeIncomeService.h"
#include "dao/feeincome/FeeIncomeDAO.h"
#include "FeeIncomeTreeMapper.h"
#include "domain/vo/feeincome/FeeIncomeTreeVO.h"
#include "tree/TreeUtil.h"
#include <queue>

FeeIncomeTreeJsonVO::Wrapper FeeIncomeService::listTree(const FeeIncomeQuery::Wrapper& query)
{
	// �������ض���
	auto vo = FeeIncomeTreeJsonVO::createShared();
	FeeIncomeDAO dao;
	//ִ�в�ѯ
	list<FeeIncomeDO> result = dao.selectTree(query);

	/*�������Ƚ���ѯ�����Ķ���ڵ��parentid���0����ת���ɸ��ڵ�, Ŀ����Ϊ���������listToTree�����Ļ��ƣ�
		���ѯ���parentidΪ  16 16 16 19 19
		������λ��16 16 16�ȱ��0
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

	// ת��Ϊ���νṹ��res��ʵ�ʴ����ɭ�ֵ����и��ڵ�
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<FeeIncomeDO>(result,FeeIncomeTreeMapper() );

	// �����ڵ�洢���б���
	for (auto one : res)
	{
		//std::cout << one.get()->_id()<<'\n';
		auto true_data = FeeIncomeTreeDTO::Wrapper(dynamic_pointer_cast<FeeIncomeTreeDTO>(one), FeeIncomeTreeDTO::Wrapper::Class::getType());
		//����ȷ��parentid�Ļ���
		true_data->parentid = true_pid;
		vo->data->push_back(true_data);
	}
	return vo;
	
	
}
// ��ҳ��ѯ��������
FeeIncomePageDTO::Wrapper FeeIncomeService::listAll(const FeeIncomeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = FeeIncomePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	FeeIncomeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<FeeIncomeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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
	// ��װDO����
	FeeIncomeDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Id, id, Name, name, Parentid, parentid, Sort, sort, Visible, visible, Intro, intro)
		// ִ���������
		FeeIncomeDAO dao;
	return dao.insert(data);
}

bool FeeIncomeService::updateData(const FeeIncomeDTO::Wrapper& dto)
{
	// ��װDO����
	FeeIncomeDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Name, name, Parentid, parentid, Sort, sort, Visible, visible, Intro, intro)
		// ִ�������޸�
		FeeIncomeDAO dao;
	return dao.update(data) == 1;
}

bool FeeIncomeService::removeData(uint64_t id)
{
	FeeIncomeDAO dao;
	return dao.deleteById(id) == 1;
}


