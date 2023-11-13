#pragma once
#ifndef _PAYRECORDS_MAPPER_
#define _PAYRECORDS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/payrecords/PayrecordsDO.h"

class PayrecordsMapper : public Mapper<PayrecordsDO>
{
public:
	PayrecordsDO mapper(ResultSet* resultSet) const override
	{
		PayrecordsDO data;
		// ӳ�丶���¼Id
		data.setRecord_id(resultSet->getUInt64(1));
		// ӳ�丶��ƻ�Id
		data.setPlan_id(resultSet->getUInt64(2));
		// ӳ���ͬId
		data.setContract_id(resultSet->getUInt64(3));
		// ӳ��ɹ���ͬ����
		data.setContract_name(resultSet->getString(4));
		// ӳ�乩Ӧ��Id
		data.setSupplier_id(resultSet->getUInt64(5));
		// ӳ�乩Ӧ������
		data.setSupplier_name(resultSet->getString(6));
		// ӳ������Id
		data.setBank_id(resultSet->getUInt64(7));
		// ӳ�丶������
		data.setPay_date(resultSet->getString(8));
		// ӳ����
		data.setMoney(resultSet->getUInt64(9));
		// ӳ��ȥ��
		data.setZero_money(resultSet->getUInt64(10));
		// ӳ���ڴ�
		data.setStages(resultSet->getUInt64(11));
		// ӳ�䱸ע
		data.setIntro(resultSet->getString(12));
		// ӳ�䴴��ʱ��
		data.setCreate_time(resultSet->getString(13));
		// ӳ�䴴����id
		data.setCreate_user_id(resultSet->getUInt64(14));
		return data;
	}

};

#endif // !_PAYRECORDSMAPPER_H_
