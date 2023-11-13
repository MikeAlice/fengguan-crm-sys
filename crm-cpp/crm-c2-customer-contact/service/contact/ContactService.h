#pragma once

#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/dto/contact/UpdateContactDTO.h"
#include "domain/dto/contact/AddContactDTO.h"
#include "domain/dto/contact/ExportContactDTO.h"
#include "domain/query/contact/ExportContactQuery.h"
#include "domain/vo/BaseJsonVO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ContactService
{
public:
	// 查询所有数据
	list<ExportContactDTO::Wrapper> listContact(const ExportContactQuery::Wrapper& query);
	// 保存数据
	uint64_t saveContact(const AddContactDTO::Wrapper& dto, const PayloadDTO& playload);
	// 修改数据
	bool updateContact(const UpdateContactDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeContact(uint64_t id);
	// 将客户信息保存为Excel文件上传到FastDFS文件服务器
	String uploadContact(list<ExportContactDTO::Wrapper>& dtolist);
};

#endif // !_SAMPLE_SERVICE_
