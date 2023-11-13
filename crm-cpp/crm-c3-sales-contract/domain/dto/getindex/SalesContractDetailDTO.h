#pragma once
#ifndef _SALESCONTRACTDETAILDTO_H_
#define _SALESCONTRACTDETAILDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//定义销售合同对象
class SalesContractDetailDTO : public oatpp::DTO
{
	DTO_INIT(SalesContractDetailDTO, DTO);
	//销售合同ID
	API_DTO_FIELD_DEFAULT(Int64, contract_id, ZH_WORDS_GETTER("SalesContract.field.contract_id"));
	//订单主题
	API_DTO_FIELD_DEFAULT(String, title, ZH_WORDS_GETTER("SalesContract.field.title"));
	//合同编号
	API_DTO_FIELD_DEFAULT(String, contract_no, ZH_WORDS_GETTER("SalesContract.field.contract_no"));
	//客户ID
	API_DTO_FIELD_DEFAULT(Int64, customer_id, ZH_WORDS_GETTER("SalesContract.field.customer_id"));
	//联系人ID
	API_DTO_FIELD_DEFAULT(Int64, linkman_id, ZH_WORDS_GETTER("SalesContract.field.linkman_id"));
	//销售机会
	API_DTO_FIELD_DEFAULT(Int64, chance_id, ZH_WORDS_GETTER("SalesContract.field.chance_id"));
	//关联网站
	API_DTO_FIELD_DEFAULT(Int64, website_id, ZH_WORDS_GETTER("SalesContract.field.website_id"));
	//开始时间
	API_DTO_FIELD_DEFAULT(String, start_date, ZH_WORDS_GETTER("SalesContract.field.start_date"));
	//结束时间
	API_DTO_FIELD_DEFAULT(String, end_date, ZH_WORDS_GETTER("SalesContract.field.end_date"));
	//我方联系人
	API_DTO_FIELD_DEFAULT(Int64, our_user_id, ZH_WORDS_GETTER("SalesContract.field.our_user_id"));
	//合同金额
	API_DTO_FIELD_DEFAULT(Float32, money, ZH_WORDS_GETTER("SalesContract.field.money"));
	//商品金额
	API_DTO_FIELD_DEFAULT(Float32, goods_money, ZH_WORDS_GETTER("SalesContract.field.goods_money"));
	//去零金额
	API_DTO_FIELD_DEFAULT(Float32, zero_money, ZH_WORDS_GETTER("SalesContract.field.zero_money"));
	//回款金额
	API_DTO_FIELD_DEFAULT(Float32, back_money, ZH_WORDS_GETTER("SalesContract.field.back_money"));
	//欠款金额
	API_DTO_FIELD_DEFAULT(Float32, owe_money, ZH_WORDS_GETTER("SalesContract.field.owe_money"));
	//交付金额
	API_DTO_FIELD_DEFAULT(Float32, deliver_money, ZH_WORDS_GETTER("SalesContract.field.deliver_money"));
	//开票金额
	API_DTO_FIELD_DEFAULT(Float32, invoice_money, ZH_WORDS_GETTER("SalesContract.field.invoice_money"));
	//订单介绍
	API_DTO_FIELD_DEFAULT(Any, intro, ZH_WORDS_GETTER("SalesContract.field.intro"));
	//订单状态 1=临时单，2=执行，3=完成，4=撤消
	API_DTO_FIELD_DEFAULT(Int8, status, ZH_WORDS_GETTER("SalesContract.field.status"));
	//回款状态，1=未付，2=部分，3=全部
	API_DTO_FIELD_DEFAULT(Int8, back_status, ZH_WORDS_GETTER("SalesContract.field.back_status"));
	//交付状态，-1=不需要，1=需要，2=录入明细，3=待出库，4=部分，5=全部
	API_DTO_FIELD_DEFAULT(Int8, deliver_status, ZH_WORDS_GETTER("SalesContract.field.deliver_status"));
	//开票状态， 0=不需要，1=需要，2=部分，3=全部
	API_DTO_FIELD_DEFAULT(Int8, invoice_status, ZH_WORDS_GETTER("SalesContract.field.invoice_status"));
	//订单类型，1=新增加，2=续费
	API_DTO_FIELD_DEFAULT(Int8, renew_status, ZH_WORDS_GETTER("SalesContract.field.renew_status"));
	//创建者
	API_DTO_FIELD_DEFAULT(Int64, create_user_id, ZH_WORDS_GETTER("SalesContract.field.create_user_id"));
	//创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("SalesContract.field.create_time"));
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_SALESCONTRACTDETAILDTO
