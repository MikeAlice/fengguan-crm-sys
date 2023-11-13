#pragma once
#ifndef INSTORAGEMAPPER_H_
#define INSTORAGEMAPPER_H_

#include "Mapper.h"
#include "domain/do/in_storage/InStorageDO.h"

class InStorageMapper :public Mapper<InStorageDO3> {
public:
	InStorageDO3 mapper(ResultSet* resultSet) const override
	{
		InStorageDO3 data;
		data.setNumber(resultSet->getString(1));
		data.setGoods_id(resultSet->getUInt64(2));
		return data;
	}
};

// ��ѯ������ϸ��mapper
class InStorageDetailsMapper :public Mapper<InStorageDO> {
public:
	InStorageDO mapper(ResultSet* resultSet) const override
	{
		InStorageDO data;
		// ����
		data.setId(resultSet->getUInt64(1));
		// �ֿ���
		data.setStore_id(resultSet->getUInt64(2));
		// ��ͬ���
		data.setContract_id(resultSet->getUInt64(3));
		// ����
		data.setTitle(resultSet->getString(4));
		// ���
		data.setMoney(resultSet->getDouble(5));
		// ����
		data.setNumber(resultSet->getUInt64(6));
		// ��ע
		data.setIntro(resultSet->getString(7));
		// ���״̬
		data.setSTatus(resultSet->getInt64(8));
		// �����
		data.setInto_user_name(resultSet->getString(9));
		// ���ʱ��
		data.setInto_time(resultSet->getString(10));
		// ������
		data.setCreate_user_name(resultSet->getString(11));
		// ����ʱ��
		data.setCreate_time(resultSet->getString(12));
		// �������
		data.setInto_type(resultSet->getString(13));
		return data;
	}
};


#endif // !INSTORAGEMAPPER_H_
