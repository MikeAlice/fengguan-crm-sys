#pragma once
#ifndef _SERBICEDETAILDTO_H_
#define _SERBICEDETAILDTO_H_
#include "../../GlobalInclude.h"
#include "../ListDTO.h"
#include"ServiceBaseDTO.h"
#include"ServiceListDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

///*
// * ServiceDetail传输对象
// */
//class ServiceDetailDTO : public oatpp::DTO
//{
//	DTO_INIT(ServiceDetailDTO, ServiceBaseDTO);
//	
//	// 客户id
//	DTO_FIELD(Int32, customer_id);
//	DTO_FIELD_INFO(customer_id) {
//		info->description = ZH_WORDS_GETTER("service.field.customer_id");
//	}
//	// 客户名称
//	DTO_FIELD(String, customer_name);
//	DTO_FIELD_INFO(customer_name) {
//		info->description = ZH_WORDS_GETTER("service.field.customer_name");
//	}
//
//	// 联系人id
//	DTO_FIELD(Int32, linkman_id);
//	DTO_FIELD_INFO(linkman_id) {
//		info->description = ZH_WORDS_GETTER("service.field.linkman_id");
//	}
//	// 联系人姓名
//	DTO_FIELD(String, linkmain_name);
//	DTO_FIELD_INFO(linkmain_name) {
//		info->description = ZH_WORDS_GETTER("service.field.linkmain_name");
//	}
//	// 服务类型
//	DTO_FIELD(Int32, service_type);
//	DTO_FIELD_INFO(service_type) {
//		info->description = ZH_WORDS_GETTER("service.field.service_type");
//	}
//	// 服务方式
//	DTO_FIELD(Int32, service_model);
//	DTO_FIELD_INFO(service_model) {
//		info->description = ZH_WORDS_GETTER("service.field.service_model");
//	}
//	// 价格
//	DTO_FIELD(Int32, price);
//	DTO_FIELD_INFO(price) {
//		info->description = ZH_WORDS_GETTER("service.field.price");
//	}
//	// 状态 1=无需处理，2未处理，3=处理中，4处理完成
//	DTO_FIELD(Int32, status);
//	DTO_FIELD_INFO(status) {
//		info->description = ZH_WORDS_GETTER("service.field.service_status");
//	}
//	// 服务日期
//	DTO_FIELD(String, service_time);
//	DTO_FIELD_INFO(service_time) {
//		info->description = ZH_WORDS_GETTER("service.field.service_datetime");
//	}
//	// 时长
//	DTO_FIELD(String, tlen);
//	DTO_FIELD_INFO(tlen) {
//		info->description = ZH_WORDS_GETTER("service.field.tlen");
//	}
//	// 服务内容
//	DTO_FIELD(String, content);
//	DTO_FIELD_INFO(content) {
//		info->description = ZH_WORDS_GETTER("service.field.service_content");
//	}
//	//// 服务内容
//	//DTO_FIELD(String, service_content);
//	//DTO_FIELD_INFO(service_content) {
//	//	info->description = ZH_WORDS_GETTER("service.field.service_content");
//	//}
//	// 备注
//	DTO_FIELD(String, intro);
//	DTO_FIELD_INFO(intro) {
//		info->description = ZH_WORDS_GETTER("service.field.intro");
//	}
//	// 创建者id
//	DTO_FIELD(Int32, create_user_id);
//	DTO_FIELD_INFO(create_user_id) {
//		info->description = ZH_WORDS_GETTER("service.field.create_user_id");
//	}
//	// 创建时间
//	DTO_FIELD(String, service_create_time);
//	DTO_FIELD_INFO(service_create_time) {
//		info->description = ZH_WORDS_GETTER("service.field.service_create_time");
//	}
//};
///*
// * 服务记录分页传输对象
// * 负责人: 会跑的鱼
// */
//class ServiceNotePageDTO : public PageDTO<ServiceDetailDTO::Wrapper>
//{
//	DTO_INIT(ServiceNotePageDTO, PageDTO<ServiceDetailDTO::Wrapper>);
//	//服务记录分页
//	DTO_FIELD(String, service_note_page);
//	DTO_FIELD_INFO(service_note_page) {
//		info->description = ZH_WORDS_GETTER("service.field.service_note_page");
//	}
//};
///**
// * 服务记录表单数据项列表DTO————导出
// * 负责人: 会跑的鱼
// */
//class ServiceNoteListDTO : public ListDTO<ServiceDetailDTO::Wrapper>
//{
//	DTO_INIT(ServiceNoteListDTO, ListDTO<ServiceDetailDTO::Wrapper>);
//	//服务记录导出
//	DTO_FIELD(String, export_service_note);
//	DTO_FIELD_INFO(export_service_note) {
//		info->description = ZH_WORDS_GETTER("service.field.export_service_note");
//	}
//};


/*
	补充服务记录传输对象
	继承关系：base->detail
	负责人：淡水狗
	用途：查询服务记录
*/
class ServiceDetailDTO : public ServiceBaseDTO
{
	DTO_INIT(ServiceDetailDTO, ServiceBaseDTO);
	// 客户名称
	API_DTO_FIELD(String, customer_name, ZH_WORDS_GETTER("service.field.customer_name"), false, "");
	// 联系人姓名
	API_DTO_FIELD(String, linkman_id, ZH_WORDS_GETTER("service.field.linkman_id"), false, "dong dong");

};
/*
	修改服务记录传输对象
	继承关系：base->modify
	负责人：淡水狗
	用途：修改服务记录
*/
class ServiceModifyDTO : public ServiceBaseDTO
{
	DTO_INIT(ServiceModifyDTO, ServiceBaseDTO);
	// 服务记录id
	API_DTO_FIELD(UInt64, service_id, ZH_WORDS_GETTER("service.field.service_id"), true, 1)
};

/*
 * 服务记录分页传输对象
 * 负责人: 会跑的鱼
 */
class ServiceNotePageDTO : public PageDTO<ServiceListDTO::Wrapper>
{
	DTO_INIT(ServiceNotePageDTO, PageDTO<ServiceListDTO::Wrapper>);
	//服务记录分页
	DTO_FIELD(String, service_note_page);
	DTO_FIELD_INFO(service_note_page) {
		info->description = ZH_WORDS_GETTER("service.field.service_note_page");
	}
};
/**
 * 服务记录表单数据项列表DTO————导出
 * 负责人: 会跑的鱼
 */
class ServiceNoteListDTO : public ListDTO<ServiceDetailDTO::Wrapper>
{
	DTO_INIT(ServiceNoteListDTO, ListDTO<ServiceDetailDTO::Wrapper>);
	//服务记录导出
	DTO_FIELD(String, export_service_note);
	DTO_FIELD_INFO(export_service_note) {
		info->description = ZH_WORDS_GETTER("service.field.export_service_note");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SERBICEDTO_H_
