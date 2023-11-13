#pragma once
#ifndef INSTORAGESERVICE_H__
#define INSTORAGESERVICE_H__
#include <list>
#include "domain/vo/in_storage/InStorageJsonVO.h"
#include "domain/query/in_storage/InStorageQuery.h"
#include "domain/dto/in_storage/InStorageDTO.h"
#include "dao/in_storage/InStorageDAO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class InStorageService
{
public:
	//�Ƿ����
	bool updateIsStorage(const ModifyByIDStorageDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
	//ͨ��id��ѯ�����Ƿ������
	bool selectByQuery(const InStorageQuery::Wrapper& query);
	// ��ҳ��ѯ��������
	InStoragePageDTO::Wrapper listAll(const InStorageQuery::Wrapper& query);
	// ��ѯ��������
	InStorageDTO::Wrapper listOne(uint64_t id);
	// ��������
	uint64_t saveData(const AddInStorageDTO::Wrapper& dto);
};

#endif // !INSTORAGESERVICE_H__