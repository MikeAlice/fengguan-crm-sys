#include "stdafx.h"
#include "SendmsemMapper.h"
#include "../../domain/do/sendmsem/SendmsemDO.h"
#include "SendmsemDAO.h"

list<SendmsemDO> SendmsemDAO::selectByid(int id) {
	string sql = "select A.name,tel,next_time,email FROM `cst_trace` as A left join `cst_linkman` as B on A.customer_id=B.customer_id WHERE A.`customer_id`=?";
	SendmsemMapper mapper;
	auto res=sqlSession->executeQuery<SendmsemDO,SendmsemMapper>(sql,mapper,"%i",id);
	return res;
}