#pragma once
#ifndef _EXPORT_CAPITAL_RECORD_QUERY_
#define _EXPORT_CAPITAL_RECORD_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������ݶ���
*/

//CREATE TABLE `fin_invoice_rece` (
//	`record_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
//	`contract_id` int(16) NOT NULL DEFAULT '0' COMMENT '�����ɹ���',
//	`supplier_id` int(16) NOT NULL DEFAULT '0' COMMENT '��Ӧ�̺�',
//	`contract_name` varchar(256) NOT NULL DEFAULT '',
//	`supplier_name` varchar(256) NOT NULL DEFAULT '',
//	`money` int(16) NOT NULL DEFAULT '0',
//	`rece_date` date DEFAULT NULL COMMENT '��Ʊʱ��',
//	`stages` int(11) NOT NULL DEFAULT '0',
//	`name` varchar(256) NOT NULL DEFAULT '' COMMENT '��Ʊ����',
//	`invoice_no` varchar(256) NOT NULL DEFAULT '0' COMMENT '��Ʊ���',
//	`intro` text,
//	`create_time` datetime DEFAULT NULL,
//	`create_user_id` int(11) NOT NULL DEFAULT '0',
//	PRIMARY KEY(`record_id`)
//	) ENGINE = InnoDB  DEFAULT CHARSET = utf8 COMMENT = '��Ʊ��¼';
class ExportCapitalRecordQuery : public PageQuery
{
	DTO_INIT(ExportCapitalRecordQuery, PageQuery);
	//��Ӧ������supplier_name������ʱ��create_time����ͬ����contract_name����Ʊ����name����Ʊ���invoice_no����Ʊ���money����Ʊʱ��rece_date���ڴ�stages��������create_user_id����עintro��
	// ��Ӧ������supplier_name
	API_DTO_FIELD_DEFAULT(String, supplier_name, ZH_WORDS_GETTER("fin_invoice_rece.field.supplier_name"));
	// ����ʱ��create_time
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("fin_invoice_rece.field.create_time"));
	//��ͬ����contract_name
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("fin_invoice_rece.field.contract_name"));
	// ��Ʊ����name
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("fin_invoice_rece.field.name"));
	// ��Ʊ���invoice_no
	API_DTO_FIELD_DEFAULT(Int64, invoice_no, ZH_WORDS_GETTER("fin_invoice_rece.field.invoice_no"));
	// ��Ʊ���money
	API_DTO_FIELD_DEFAULT(Int64, money, ZH_WORDS_GETTER("fin_invoice_rece.field.money"));
	// ��Ʊʱ��rece_date
	API_DTO_FIELD_DEFAULT(String, rece_date, ZH_WORDS_GETTER("fin_invoice_rece.field.rece_date"));
	// �ڴ�stages
	API_DTO_FIELD_DEFAULT(Int64, stages, ZH_WORDS_GETTER("fin_invoice_rece.field.stages"));
	// ������create_user_id
	API_DTO_FIELD_DEFAULT(Int64, create_user_id, ZH_WORDS_GETTER("fin_invoice_rece.field.create_user_id"));
	// ��עintro
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("fin_invoice_rece.field.intro"));
	
public:

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORT_CAPITAL_RECORD_QUERY_

