#pragma once
#ifndef _EXPORT_CAPITAL_RECORD_QUERY_
#define _EXPORT_CAPITAL_RECORD_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 导出数据对象
*/

//CREATE TABLE `fin_invoice_rece` (
//	`record_id` int(16) unsigned NOT NULL AUTO_INCREMENT,
//	`contract_id` int(16) NOT NULL DEFAULT '0' COMMENT '关联采购号',
//	`supplier_id` int(16) NOT NULL DEFAULT '0' COMMENT '供应商号',
//	`contract_name` varchar(256) NOT NULL DEFAULT '',
//	`supplier_name` varchar(256) NOT NULL DEFAULT '',
//	`money` int(16) NOT NULL DEFAULT '0',
//	`rece_date` date DEFAULT NULL COMMENT '收票时间',
//	`stages` int(11) NOT NULL DEFAULT '0',
//	`name` varchar(256) NOT NULL DEFAULT '' COMMENT '发票内容',
//	`invoice_no` varchar(256) NOT NULL DEFAULT '0' COMMENT '发票编号',
//	`intro` text,
//	`create_time` datetime DEFAULT NULL,
//	`create_user_id` int(11) NOT NULL DEFAULT '0',
//	PRIMARY KEY(`record_id`)
//	) ENGINE = InnoDB  DEFAULT CHARSET = utf8 COMMENT = '收票记录';
class ExportCapitalRecordQuery : public PageQuery
{
	DTO_INIT(ExportCapitalRecordQuery, PageQuery);
	//供应商名称supplier_name、创建时间create_time、合同标题contract_name、发票内容name、发票编号invoice_no、发票金额money、收票时间rece_date、期次stages、创建人create_user_id、备注intro、
	// 供应商名称supplier_name
	API_DTO_FIELD_DEFAULT(String, supplier_name, ZH_WORDS_GETTER("fin_invoice_rece.field.supplier_name"));
	// 创建时间create_time
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("fin_invoice_rece.field.create_time"));
	//合同标题contract_name
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("fin_invoice_rece.field.contract_name"));
	// 发票内容name
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("fin_invoice_rece.field.name"));
	// 发票编号invoice_no
	API_DTO_FIELD_DEFAULT(Int64, invoice_no, ZH_WORDS_GETTER("fin_invoice_rece.field.invoice_no"));
	// 发票金额money
	API_DTO_FIELD_DEFAULT(Int64, money, ZH_WORDS_GETTER("fin_invoice_rece.field.money"));
	// 收票时间rece_date
	API_DTO_FIELD_DEFAULT(String, rece_date, ZH_WORDS_GETTER("fin_invoice_rece.field.rece_date"));
	// 期次stages
	API_DTO_FIELD_DEFAULT(Int64, stages, ZH_WORDS_GETTER("fin_invoice_rece.field.stages"));
	// 创建人create_user_id
	API_DTO_FIELD_DEFAULT(Int64, create_user_id, ZH_WORDS_GETTER("fin_invoice_rece.field.create_user_id"));
	// 备注intro
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("fin_invoice_rece.field.intro"));
	
public:

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORT_CAPITAL_RECORD_QUERY_

