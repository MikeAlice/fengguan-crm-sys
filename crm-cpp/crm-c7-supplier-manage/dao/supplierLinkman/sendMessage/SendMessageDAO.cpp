#include "stdafx.h"
#include "SendMessageDAO.h"
#include "dao/mapper/SendMessageMapper.h"

std::list<SendMessageDO> SendMessageDAO::getNameAndPhone(const SendMessageDTO::Wrapper& dto)
{
	stringstream sql;
	sql<<	"SELECT name,mobile FROM `sup_linkman` WHERE 1=1 AND ";
	SqlParams params;
	int size = 0;
	for (auto i : *(dto->supplier_list)) {
		sql << "linkman_id=? OR ";
		SQLPARAMS_PUSH(params, "i", std::uint64_t, *i);
		size++;
	}
	sql << "1=0";
	SendMessageMapper mapper;
	string sqlStr = sql.str();
	std::list<SendMessageDO> sml = sqlSession->executeQuery<SendMessageDO, SendMessageMapper>(sqlStr, mapper, params);

	//如果size不相等，说明有些非法ID
	if (sml.size() != size)throw exception();
	return sml;
}
