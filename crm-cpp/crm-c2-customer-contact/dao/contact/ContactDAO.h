#pragma 
#ifndef _CONTACT_DAO_
#define _CONTACT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/contact/ContactDO.h"
#include "domain/query/contact/ExportContactQuery.h"
#include "domain/dto/contact/ExportContactDTO.h"

/**
 * 示例表数据库操作实现
 */
class ContactDAO : public BaseDAO
{
public:
	// 查询数据
	list<ContactDO> selectAll(const ExportContactQuery::Wrapper& query);
	// 查询数据
	list<ContactDO> selectAllById(uint64_t id);
	// 插入数据
	uint64_t insert(const ContactDO& iObj);
	// 修改数据
	int update(const ContactDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_CONTACT_DAO_
