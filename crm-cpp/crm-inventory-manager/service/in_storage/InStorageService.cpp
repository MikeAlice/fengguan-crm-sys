#include "stdafx.h"
#include "InStorageService.h"

bool InStorageService::updateIsStorage(const ModifyByIDStorageDTO::Wrapper& dto)
{
	// ��ѯ����������
	InStorageDAO dao;
	//����idȷ�����
	InStorageDO2 data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Into_user_id, into_user_id);
	if (dao.updateById(data))
		return true;
	return false;
}


bool InStorageService::selectByQuery(const InStorageQuery::Wrapper& query)
{
	return false;
}

InStoragePageDTO::Wrapper InStorageService::listAll(const InStorageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = InStoragePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	InStorageDAO dao;
	uint64_t count = dao.countInStorageList(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<InStorageDO> result = dao.selectWithPage(query);

	// ��DOת����DTO
	for (InStorageDO sub : result)
	{
		auto dto = InStorageDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, contract_id, Contract_id, title, Title, store_id, Store_id, intro, Intro, status, STatus, number, Number, money, Money, into_user, Into_user_name, into_time, Into_time, create_user, Create_user_name, create_time, Create_time, into_type, Into_type)

			pages->addData(dto);
	}
	return pages;
}

InStorageDTO::Wrapper InStorageService::listOne(uint64_t id)
{
	auto dto = InStorageDTO::createShared();

	// ����id���Ҷ�Ӧ��do
	InStorageDAO dao;
	auto query = InStorageQuery::createShared();
	query->pageIndex = 1;
	query->pageSize = 1;
	query->id = id;
	uint64_t count = dao.countInStorageList(query);
	if (count <= 0)
	{
		return dto;
	}

	auto result = dao.selectById(id);

	// ����dto���ض���
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, result, id, Id, contract_id, Contract_id, title, Title, store_id, Store_id, intro, Intro, status, STatus, number, Number, money, Money, into_user, Into_user_name, into_time, Into_time, create_user, Create_user_name, create_time, Create_time, into_type, Into_type)

		return dto;
}

uint64_t InStorageService::saveData(const AddInStorageDTO::Wrapper& dto)
{
	// ��װDO����
	InStorageDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Contract_id, contract_id, Title, title, Store_id, store_id, Create_user_id, create_user_id, Intro, intro, Number, number, Money, money, Into_type, into_type)
		// ִ���������
		InStorageDAO dao;
	return dao.insert(data);
}



bool InStorageService::removeData(uint64_t id)
{
    InStorageDAO dao;
    auto t = dao.deleteById(id);
    return t==1;
}
