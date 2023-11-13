#pragma once
#ifndef INSTORAGEDAO_H_
#define INSTORAGEDAO_H_

#include "BaseDAO.h"
#include "domain/query/in_storage/InStorageQuery.h"
#include "domain/do/in_storage/InStorageDO.h"
#include "dao/in_storage/InStorageMapper.h"
class InStorageDAO :public BaseDAO {
public:
	//ͨ��id��ѯ�����Ƿ������
	bool updateById(const InStorageDO2& uObj);
	//ͨ��id��ѯ��Ӧ��������ϸ
	InStorageDO selectById(uint64_t id);
	// ͳ�Ʒ���Ҫ�����ⵥ����
	uint64_t countInStorageList(const InStorageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<InStorageDO> selectWithPage(const InStorageQuery::Wrapper& query);
	// ��������
	uint64_t insert(const InStorageDO& iObj);
	// �޸�����
	int update(const InStorageDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};


#endif // !INSTORAGEDAO_H_
