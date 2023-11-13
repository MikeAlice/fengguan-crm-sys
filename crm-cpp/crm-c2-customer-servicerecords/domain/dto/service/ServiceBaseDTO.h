#pragma once
#ifndef SERVICEBASEDTO_H__
#define SERVICEBASEDTO_H__
#include "../../GlobalInclude.h"

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
	基础服务记录传输对象
	继承关系：无
	负责人：淡水狗
	用途：添加服务记录
*/
class ServiceBaseDTO : public oatpp::DTO
{
	DTO_INIT(ServiceBaseDTO, DTO);
	// 客户id
	API_DTO_FIELD(Int32, customer_id, ZH_WORDS_GETTER("service.field.customer_id"), false, 1);
	// 联系人idlinkman_id linkman_name
	API_DTO_FIELD(Int32, linkman_id, ZH_WORDS_GETTER("service.field.linkman_id"), false, 1);
	// 服务类型service_type 
	API_DTO_FIELD(Int32, services, ZH_WORDS_GETTER("service.field.services"), false, 1);
	// 服务方式servicesmodel
	API_DTO_FIELD(Int32, servicesmodel, ZH_WORDS_GETTER("service.field.servicesmodel"), false, 1);
	// 价格
	API_DTO_FIELD(Int32, price, ZH_WORDS_GETTER("service.field.price"), false, 1);
	// 状态 1=无需处理，2未处理，3=处理中，4处理完成
	API_DTO_FIELD(Int32, status, ZH_WORDS_GETTER("service.field.status"), false, 1);
	// 服务日期
	API_DTO_FIELD(String, service_time, ZH_WORDS_GETTER("service.field.service_time"), false, "2018-10-13 14:50:11");
	// 时长
	API_DTO_FIELD(String, tlen, ZH_WORDS_GETTER("service.field.tlen"), false, "60");
	// 服务内容
	API_DTO_FIELD(String, content, ZH_WORDS_GETTER("service.field.content"), false, "fix a computer");
	// 备注
	API_DTO_FIELD(String, intro, ZH_WORDS_GETTER("service.field.intro"), false, "phone call");
	// 创建者id
	//API_DTO_FIELD(Int32, create_user_id, ZH_WORDS_GETTER("service.field.create_user_id"), false, 1);
	// 创建时间
	//API_DTO_FIELD(String, service_create_time, ZH_WORDS_GETTER("service.field.service_create_time"), false, "2018-10-13 14:50:11");

};
/*
	ID列表服务记录传输对象
	继承关系：无
	负责人：淡水狗
	用途：删除服务记录（批量）
*/
class ServiceIdListDTO : public oatpp::DTO
{
	DTO_INIT(ServiceIdListDTO, DTO);

	// 服务记录id(批量)
	API_DTO_FIELD(Vector<UInt64>, service_id_s, ZH_WORDS_GETTER("service.field.service_id_s"), true, { 1 })


};
#include OATPP_CODEGEN_END(DTO)
#endif // SERVICEBASEDTO_H__