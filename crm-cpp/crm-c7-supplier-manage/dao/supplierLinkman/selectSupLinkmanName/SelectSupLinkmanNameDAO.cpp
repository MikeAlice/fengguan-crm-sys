#include "stdafx.h"
#include <sstream>
#include "SelectSupLinkmanNameDAO.h"
#include "dao/mapper/SelectSupLinkmanNameMapper.h"





list<SupplierLinkmanDO> SelectSupLinkmanNameDAO::selectSupplierName(const LinkmanNameQuery::Wrapper& query) {

	string sql = "SELECT linkman_id,name FROM sup_linkman WHERE `name` LIKE CONCAT('%',?,'%')";
	
	SelectSupLinkmanNameMapper mapper;
	return sqlSession->executeQuery<SupplierLinkmanDO, SelectSupLinkmanNameMapper>(sql, mapper, "%s", query->keywords.getValue(""));
}
