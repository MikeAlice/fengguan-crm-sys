#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _GETCONTACTFIELD_SERVICE_
#define _GETCONTACTFIELD_SERVICE_
#include <list>
#include "dao/getcontactfieldext/GetContactFieldExtDAO.h"
#include "domain/dto/contactfield/ContactFieldDTO.h"


/**
 * �����ļ�����ʵ��
 */
class GetContactFieldService
{
public:
	/*
	* �����ˣ��Ͼ�
	* ���ܣ���ȡ�����ϵ�������ֶ�
	*/

	ContactFieldDTO::Wrapper getContactField();
};

#endif // !_GETCONTACTFIELD_SERVICE_