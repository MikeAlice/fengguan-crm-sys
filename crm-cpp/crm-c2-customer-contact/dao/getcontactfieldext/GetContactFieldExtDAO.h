#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _GETCONTACTFIELDEXT_DAO_
#define _GETCONTACTFIELDEXT_DAO_
#include "BaseDAO.h"
#include "dao/getcontactfieldext/GetContactFieldExtMapper.h"

/**
 * �����ͻ����ݱ����ʵ��
 */
class GetContactFieldExtDAO : public BaseDAO
{
public:

	// �����ֶ�ֵ��ѯ�Ƿ�����
	uint64_t selectVisibleByName(string field_name);

};
#endif // !_GETCONTACTFIELDEXT_DAO_