#pragma once
#ifndef FLOWRECORDDAO_H__
#define FLOWRECORDDAO_H__
#include "BaseDAO.h"
#include "../../domain/do/flowrecord/FlowrecordDO.h"
#include "../../domain/dto/flowrecord/FlowrecordDTO.h"
#include "../../domain/query/flowrecord/FlowrecordQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class FlowrecordDAO : public BaseDAO
{
public:
	std::string column_list = "id,balance,pay_money,rece_money,bank_id,bus_id,bus_type,intro,create_time,create_user_id";
	// ͳ����������
	uint64_t count(const FlowrecordPageQuery::Wrapper& query);
	// ��ҳ��ѯ����ܼ�
	double count_total_pay(const FlowrecordPageQuery::Wrapper& query);
	// ��ҳ��ѯ�����ܼ�
	double count_total_rece(const FlowrecordPageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<FlowrecordDO> selectWithPage(const FlowrecordPageQuery::Wrapper& query);
	//// ͨ�������˺Ų�ѯ����
	//list<FlowrecordDO> selectByBankid(const string& bank_id);
	//// ͨ������ʱ���ѯ����
	//list<FlowrecordDO> selectByCreatetime(const string& create_time);
	//// ͨ�������˲�ѯ����
	//list<FlowrecordDO> selectByCreateuser(const string& create_user);
	// ��������
	std::list<FlowrecordDO> select2export(const oatpp::List<FlowrecordExportDTO::Wrapper>& dto);

};
#endif // !_SAMPLE_DAO_
