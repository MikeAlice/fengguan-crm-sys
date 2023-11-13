#include "stdafx.h"
#include "ExportCapitalRecordDAO.h"
#include <sstream>
#include "domain/dto/fin_invoice_rece/ExportCapitalRecordDTO.h"

#define FINCAPREC_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->type_id) { \
	sql << " AND `type_id`= ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->type_id.getValue(0)); \
} \
if (query->create_user_id) { \
	sql << " AND `create_user_id` = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->create_user_id.getValue(0)); \
} \
if (query->bank_id) { \
	sql << " AND `bank_id` = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->bank_id.getValue(0)); \
} \
if (query->money) { \
	sql << " AND `money` = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->money.getValue(0)); \
} \
if (query->intro) { \
	sql << " AND `intro` = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->intro.getValue("")); \
} \
if (query->create_time) { \
	sql << " AND `create_time` = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->create_time.getValue("")); \
} \
if (query->happen_date) { \
	sql << " AND `happen_date` = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->happen_date.getValue("")); \
} \


namespace sqlHelpers {
	/*
	* ���������IN���()
	* ʾ������"SELECT xxx FROM xxx WHERE xxx IN "�ĺ���
	*		���(1,2,3,4)
	* ������sql��䡢dto����
	* ע�⣺record_id��
	*/
	template<typename T>
	void insertIdList(stringstream& sql, T& dto)
	{
		sql << "(";
		//����dto�����list�����Ԫ��
		for (auto i = dto->begin(); i != dto->end(); i++)
		{
			if (i != dto->begin())	sql << ",";
			sql << (*i)->record_id.getValue({});
		}
		sql << ")";
	}
}

list<FinCapitalRecordDO> ExportCapitalRecordDAO::selectAll(const oatpp::List<ExportCapitalRecordDTO::Wrapper>&dto)
{
	stringstream sql;
	sql << "SELECT record_id, type_id, create_user_id, bank_id,\
				money, intro, create_time, happen_date\
			FROM fin_capital_record";
	//FINCAPREC_TERAM_PARSE(query, sql);
	ExportCapitalRecordMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<FinCapitalRecordDO, ExportCapitalRecordMapper>(sqlStr, mapper);
}

//list<FinCapitalRecordDO>�ķ���ֵ
list<FinCapitalRecordDO> ExportCapitalRecordDAO::selectWithIdList(const oatpp::List<ExportCapitalRecordDTO::Wrapper>& dto)
{
	stringstream sql;
	sql << "SELECT record_id,contract_id,supplier_id,contract_name,supplier_name,money,rece_date,stages,name,invoice_no,intro,create_time,create_user_id FROM fin_invoice_rece WHERE record_id IN";//���record_id==18��19��ֵ
	sqlHelpers::insertIdList(sql, dto);//��sql������ƴװ
	string sqlStr = sql.str();
	//std::cout << sqlStr << std::endl;
	ExportCapitalRecordMapper mapper;//ִ��sql��䣬��סlist���Ż����ݵ�service��
	return sqlSession->executeQuery<FinCapitalRecordDO, ExportCapitalRecordMapper>(sqlStr, mapper);
}
