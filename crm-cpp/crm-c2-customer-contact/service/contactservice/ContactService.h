#pragma once
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/contact/ListContactVO.h"
#include "domain/query/contact/ContactQuery.h"
#include "domain/dto/contact/ListContactDTO.h"

/**
 * 
 */
class ContactService
{
public:
	// 分页查询所有数据
	ListContactDTO::Wrapper listAll(const ContactQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_

