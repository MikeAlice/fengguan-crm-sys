#pragma once
/*
* 负责人：老菌
*/
#ifndef _GETCONTACTFIELD_SERVICE_
#define _GETCONTACTFIELD_SERVICE_
#include <list>
#include "dao/getcontactfieldext/GetContactFieldExtDAO.h"
#include "domain/dto/contactfield/ContactFieldDTO.h"


/**
 * 导出文件服务实现
 */
class GetContactFieldService
{
public:
	/*
	* 负责人：老菌
	* 功能：获取添加联系人所需字段
	*/

	ContactFieldDTO::Wrapper getContactField();
};

#endif // !_GETCONTACTFIELD_SERVICE_