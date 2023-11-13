#pragma once
/*
* 会跑的鱼
*/
#ifndef _SERVICE_QUERY_
#define _SERVICE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 服务记录分页查询对象
 */
class ServiceQuery : public PageQuery
{
	DTO_INIT(ServiceQuery, PageQuery);

	// 客户id
	DTO_FIELD(Int32, customer_id);
	DTO_FIELD_INFO(customer_id) {
		info->description = ZH_WORDS_GETTER("service.field.customer_id");
	}
	
	// 客户名称
	DTO_FIELD(String, customer_name);
	DTO_FIELD_INFO(customer_name) {
		info->description = ZH_WORDS_GETTER("service.field.customer_name");
	}
	//服务类型
	DTO_FIELD(Int32, services);
	DTO_FIELD_INFO(services) {
		info->description = ZH_WORDS_GETTER("service.field.services");
	}
	//服务方式
	DTO_FIELD(Int32, servicesmodel);
	DTO_FIELD_INFO(servicesmodel) {
		info->description = ZH_WORDS_GETTER("service.field.servicesmodel");
	}
	//服务时间
	DTO_FIELD(String, service_time);
	DTO_FIELD_INFO(service_time) {
		info->description = ZH_WORDS_GETTER("service.field.service_time");
	}
	//花费时间
	DTO_FIELD(String, tlen);
	DTO_FIELD_INFO(tlen) {
		info->description = ZH_WORDS_GETTER("service.field.tlen");
	}
	//服务内容
	DTO_FIELD(String, content);
	DTO_FIELD_INFO(content) {
		info->description = ZH_WORDS_GETTER("service.field.content");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SERVICE_QUERY_
