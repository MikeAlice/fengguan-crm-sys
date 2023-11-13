#pragma once
#ifndef _EXPORTSERVICENOTE_H_
#define _EXPORTSERVICENOTE_H_
#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include "../../dto/ListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 导出服务记录Query
 * 负责人: 会跑的鱼
 */
class ExportServiceNoteQuery :public oatpp::DTO
{
	DTO_INIT(ExportServiceNoteQuery, DTO);

	////服务记录id
	//API_DTO_FIELD_DEFAULT(Int32, service_id, ZH_WORDS_GETTER("service.field.service_id"));
	//客户id
	API_DTO_FIELD_DEFAULT(Int32, customer_id, ZH_WORDS_GETTER("service.field.customer_id"));
	// 客户ID列表
	API_DTO_FIELD_DEFAULT(List<Int32>, service_id_list, ZH_WORDS_GETTER("service.field.service_id_list"));
	////客户名称
	////API_DTO_FIELD_DEFAULT(String, customer_name, ZH_WORDS_GETTER("service.field.customer_name"));
	////服务类型
	//API_DTO_FIELD_DEFAULT(Int32, services, ZH_WORDS_GETTER("service.field.services"));
	//
	////服务方式
	//API_DTO_FIELD_DEFAULT(Int32, servicesmodel, ZH_WORDS_GETTER("service.field.servicesmodel"));
	//
	////服务时间
	//API_DTO_FIELD_DEFAULT(String, service_time, ZH_WORDS_GETTER("service.field.service_time"));
	//
	////花费时间
	//API_DTO_FIELD_DEFAULT(String, tlen, ZH_WORDS_GETTER("service.field.tlen"));
	//
	////服务内容
	//API_DTO_FIELD_DEFAULT(String, content, ZH_WORDS_GETTER("service.field.content"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTSERVICENOTE_H_
