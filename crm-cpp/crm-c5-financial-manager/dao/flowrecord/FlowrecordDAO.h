#pragma once
#ifndef FLOWRECORDDAO_H__
#define FLOWRECORDDAO_H__
#include "BaseDAO.h"
#include "../../domain/do/flowrecord/FlowrecordDO.h"
#include "../../domain/dto/flowrecord/FlowrecordDTO.h"
#include "../../domain/query/flowrecord/FlowrecordQuery.h"

/**
 * 示例表数据库操作实现
 */
class FlowrecordDAO : public BaseDAO
{
public:
	std::string column_list = "id,balance,pay_money,rece_money,bank_id,bus_id,bus_type,intro,create_time,create_user_id";
	// 统计数据条数
	uint64_t count(const FlowrecordPageQuery::Wrapper& query);
	// 分页查询输出总计
	double count_total_pay(const FlowrecordPageQuery::Wrapper& query);
	// 分页查询收入总计
	double count_total_rece(const FlowrecordPageQuery::Wrapper& query);
	// 分页查询数据
	list<FlowrecordDO> selectWithPage(const FlowrecordPageQuery::Wrapper& query);
	//// 通过银行账号查询数据
	//list<FlowrecordDO> selectByBankid(const string& bank_id);
	//// 通过创建时间查询数据
	//list<FlowrecordDO> selectByCreatetime(const string& create_time);
	//// 通过创建人查询数据
	//list<FlowrecordDO> selectByCreateuser(const string& create_user);
	// 导出数据
	std::list<FlowrecordDO> select2export(const oatpp::List<FlowrecordExportDTO::Wrapper>& dto);

};
#endif // !_SAMPLE_DAO_
