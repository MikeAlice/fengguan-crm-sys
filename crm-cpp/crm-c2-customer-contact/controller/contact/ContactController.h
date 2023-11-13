#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _CONTACT_CONTROLLER_
#define _CONTACT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/contact/NameContactDTO.h"
#include "domain/dto/contact/ListContactDTO.h"
#include "domain/vo/contact/NameContactVO.h"
#include "domain/vo/contact/ListContactVO.h"
#include "domain/vo/contactfield/ContactFieldVO.h"
#include "ApiHelper.h"
#include "domain/dto/contact/DeleteContactDTO.h"
#include "domain/query/contact/ExportContactQuery.h"
#include "domain/query/contact/ListContactQuery.h"
#include "domain/query/contact/ListContectNameQuery.h"
#include "domain/dto/contact/AddContactDTO.h"
#include "domain/dto/contact/UpdateContactDTO.h"
#include "domain/dto/contact/ExportContactDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 联系人控制器，控制我的客户下的一系列接口
 */
class ContactController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ContactController);
	// 3 定义接口
public:
	// 定义获取联系人名称列表接口	负责人：淡水狗
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/customer-contact/query-contact-name", queryContactName, BODY_DTO(NameContactDTO::Wrapper, dto), execQueryContactName(dto, authObject->getPayload()));
	ENDPOINT_INFO(queryContactName) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contact.controller.query-contact-name"));	//目录名.controller.方法名.summary
		// 定义响应参数格式
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(NameContactJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt32, "customer_id", ZH_WORDS_GETTER("contact.field.customer_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("contact.field.name"), u8"张三", false);

	}
	ENDPOINT(API_M_GET, "/customer-contact/query-contact-name", queryContactName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(customerQuery, ListContactNameQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryContactName(customerQuery, authObject->getPayload()));
	}
	// 定义获取联系人列表接口	负责人：Darb
	ENDPOINT(API_M_GET, "/customer-contact/query-contact-list", queryContactList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 定义获取联系人列表接口描述
		API_HANDLER_QUERY_PARAM(customerQuery, ListContactQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryContactList(customerQuery, authObject->getPayload()));
	}
	// 定义获取联系人列表接口描述
	ENDPOINT_INFO(queryContactList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contact.controller.query-contact-list"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_PAGE_PARAMS();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ListContactPageJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "key", ZH_WORDS_GETTER("contact.controller.query-contact-key"), u8"张三", false);
		API_DEF_ADD_QUERY_PARAMS(String, "customer_name", ZH_WORDS_GETTER("customer.field.name"), u8"成都电子信息有限公司", false);
		API_DEF_ADD_QUERY_PARAMS(String, "address", ZH_WORDS_GETTER("contact.field.address"), u8"成都XX街道", false);
	}



	// 定义获取联系人表单数据项接口	负责人：Darb
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/customer-contact/get-contact-field", getContactField, BODY_DTO(ListContactDTO::Wrapper, dto), execGetContactField(dto, authObject->getPayload()));
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/customer-contact/get-contact-field", getContactField, execGetContactField());
	// 定义获取联系人表单数据项接口描述
	ENDPOINT_INFO(getContactField) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contact.controller.get-contact-field"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ContactFieldJsonVO);
	}



	// 定义添加联系人接口	负责人：老王
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/customer-contact/add-contact", addContact, BODY_DTO(AddContactDTO::Wrapper, dto), execAddContact(dto, authObject->getPayload()));
	// 定义添加联系人接口描述
	ENDPOINT_INFO(addContact) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contact.controller.addContact.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
		//// 定义客户ID查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(UInt32, "customer_id", ZH_WORDS_GETTER("contact.field.customer_id"), 1, false);
		//// 定义联系人名称查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("contact.field.name"), ZH_WORDS_GETTER("test.contact.name"), false);
		//// 定义联系人性别查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(UInt32, "gender", ZH_WORDS_GETTER("contact.field.gender"), 1, false);
		//// 定义联系人职位查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "postion", ZH_WORDS_GETTER("contact.field.postion"), , false);
		//// 定义联系人座机查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "tel", ZH_WORDS_GETTER("contact.field.tel"), , false);
		//// 定义联系人手机查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "mobile", ZH_WORDS_GETTER("contact.field.mobile"), , false);
		//// 定义联系人QQ查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "qicq", ZH_WORDS_GETTER("contact.field.qicq"), , false);
		//// 定义联系人邮箱查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "email", ZH_WORDS_GETTER("contact.field.email"), , false);
		//// 定义联系人邮政编码查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "zipcode", ZH_WORDS_GETTER("contact.field.zipcode"), , false);
		//// 定义联系人地址查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "address", ZH_WORDS_GETTER("contact.field.address"), , false);
		//// 定义联系人简介查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "intro", ZH_WORDS_GETTER("contact.field.intro"), , false);
	}

	// 定义修改联系人接口	负责人：老王
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/customer-contact/modify-contact", modifyContact, BODY_DTO(UpdateContactDTO::Wrapper, dto), execModifyContact(dto));
	// 定义修改联系人接口描述
	ENDPOINT_INFO(modifyContact) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contact.controller.modifyContact.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
		//// 定义客户ID查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(UInt32, "customer_id", ZH_WORDS_GETTER("contact.field.customer_id"), 1, false);
		//// 定义联系人名称查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("contact.field.name"), ZH_WORDS_GETTER("test.contact.name"), false);
		//// 定义联系人性别查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(UInt32, "gender", ZH_WORDS_GETTER("contact.field.gender"), 1, false);
		//// 定义联系人职位查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "postion", ZH_WORDS_GETTER("contact.field.postion"), , false);
		//// 定义联系人座机查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "tel", ZH_WORDS_GETTER("contact.field.tel"), , false);
		//// 定义联系人手机查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "mobile", ZH_WORDS_GETTER("contact.field.mobile"), , false);
		//// 定义联系人QQ查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "qicq", ZH_WORDS_GETTER("contact.field.qicq"), , false);
		//// 定义联系人邮箱查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "email", ZH_WORDS_GETTER("contact.field.email"), , false);
		//// 定义联系人邮政编码查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "zipcode", ZH_WORDS_GETTER("contact.field.zipcode"), , false);
		//// 定义联系人地址查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "address", ZH_WORDS_GETTER("contact.field.address"), , false);
		//// 定义联系人简介查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "intro", ZH_WORDS_GETTER("contact.field.intro"), , false);
		//// 定义联系人ID查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(UInt32, "linkman_id", ZH_WORDS_GETTER("contact.field.linkman_id"), 1, true);
	}

	// 定义删除联系人接口	负责人：老王
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/customer-contact/remove-contact", removeContact, BODY_DTO(DeleteContactDTO::Wrapper, dto), execRemoveContact(dto));
	// 定义删除联系人接口描述
	ENDPOINT_INFO(removeContact) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contact.controller.removeContact.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
	}

	// 定义导出联系人接口	负责人：老王
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/customer-contact/query-contact-file", queryContactFile, ExportContactQuery, execQueryContactFile(query));
	// 定义导出联系人接口描述
	ENDPOINT_INFO(queryContactFile) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("contact.controller.queryContactFile.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义归属人ID查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt32, "owner_user_id", ZH_WORDS_GETTER("contact.field.owner_user_id"), 1, false);
		// 定义联系人创建人ID查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt32, "create_user_id", ZH_WORDS_GETTER("contact.field.create_user_id"), 1, false);
	}


private:
	/*负责人：Darb
	* 功能描述：获取所有的联系人名称
	* @param： 无
	* @return： NameContactPageJsonVO  分页形式的NameContactDTO
	*/
	NameContactJsonVO::Wrapper execQueryContactName(ListContactNameQuery::Wrapper query, const PayloadDTO& playload);

	/*负责人：Darb
	* 功能描述：查询联系人列表
	* @param： ListContactDTO
	* @return： ListContactPageJsonVO  分页形式的ListContactDTO
	*/
	ListContactPageJsonVO::Wrapper execQueryContactList(ListContactQuery::Wrapper query, const PayloadDTO& playload);

	/*负责人：Darb
	* 功能描述：获取联系人表单数据项
	* @param： 无
	* @return： ListContactJsonVO
	*/
	ContactFieldJsonVO::Wrapper execGetContactField();

	/*负责人：老王
	* 功能描述：删除联系人
	* @param： DeleteContactDTO PayloadDTO&
	* @return： BooleanJsonVO 是否删除成功
	*/
	StringJsonVO::Wrapper execRemoveContact(DeleteContactDTO::Wrapper dto);

	/*负责人：老王
	* 功能描述：导出联系人
	* @param： ExportContactDTO PayloadDTO&
	* @return： BooleanJsonVO 是否删除成功
	*/
	StringJsonVO::Wrapper execQueryContactFile(ExportContactQuery::Wrapper query);

	/*负责人：老王
	* 功能描述：添加联系人
	* @param： AddAndUpdateContactDTO PayloadDTO&
	* @return： BooleanJsonVO 是否删除成功
	*/
	StringJsonVO::Wrapper execAddContact(AddContactDTO::Wrapper dto, const PayloadDTO& playload);

	/*负责人：老王
	* 功能描述：添加联系人
	* @param： AddAndUpdateContactDTO PayloadDTO&
	* @return： BooleanJsonVO 是否删除成功
	*/
	StringJsonVO::Wrapper execModifyContact(UpdateContactDTO::Wrapper dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CUSTOMER_CONTROLLER_