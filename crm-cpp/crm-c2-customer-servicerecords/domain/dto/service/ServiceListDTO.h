#pragma once
#ifndef SERVICELISTDTO_H__
#define SERVICELISTDTO_H__
#include "../../GlobalInclude.h"
#include "../ListDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

///**
// * ServiceBase传输对象
// */
//class ServiceBaseDTO : public oatpp::DTO
//{
//	DTO_INIT(ServiceBaseDTO, DTO);
//	// 服务记录id
//	DTO_FIELD(UInt64, service_id);
//	DTO_FIELD_INFO(service_id) {
//		info->description = ZH_WORDS_GETTER("service.field.service_id");
//	}
//	// 服务记录id(批量)
//	DTO_FIELD(Vector<UInt64>, service_id_s);
//	DTO_FIELD_INFO(service_id_s) {
//		info->description = ZH_WORDS_GETTER("service.field.service_id_s");
//	}
//};

/*
	查询服务记录传输对象
	继承关系：无
	负责人：会跑的鱼
	用途：查询服务记录
*/
class ServiceListDTO : public oatpp::DTO
{
	DTO_INIT(ServiceListDTO, DTO);
	// 客户id
	API_DTO_FIELD(Int32, customer_id, ZH_WORDS_GETTER("service.field.customer_id"), false, 1);
	// 服务记录id
	API_DTO_FIELD(Int32, service_id, ZH_WORDS_GETTER("service.field.service_id"), false, 1);
	// 服务类型
	API_DTO_FIELD(Int32, services, ZH_WORDS_GETTER("service.field.services"), false, 1);
	// 服务方式
	API_DTO_FIELD(Int32, servicesmodel, ZH_WORDS_GETTER("service.field.servicesmodel"), false, 1);
	// 服务日期
	API_DTO_FIELD(String, service_time, ZH_WORDS_GETTER("service.field.service_time"), false, "2018-10-13 14:50:11");
	// 时长
	API_DTO_FIELD(String, tlen, ZH_WORDS_GETTER("service.field.tlen"), false, "60");
	// 服务内容
	API_DTO_FIELD(String, content, ZH_WORDS_GETTER("service.field.content"), false, "fix a computer");
	// 客户名称
	API_DTO_FIELD(String, customer_name, ZH_WORDS_GETTER("service.field.customer_name"), false, "");



};
#include OATPP_CODEGEN_END(DTO)
#endif // SERVICELISTDTO_H__