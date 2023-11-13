#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/27 10:25:47

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
#ifndef _MESSAGEDTO_H_
#define _MESSAGEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 功能：邮件发送DTO
 * 执行人：Detachment
**/
class MailDTO : public oatpp::DTO
{
	DTO_INIT(MailDTO, DTO);
	/**
	 * 消息类型
	 * 1：节日祝福信息
	 * 2：新品推荐信息
	 * 3：合同到期信息
	 * 4：联系人预约提醒信息 
	 * 5：服务记录预约提醒信息
	 * 6：销售机会预约提醒信息 
	 * 7：跟踪记录预约提醒信息
	 * 8：供应商联系人预约提醒信息
	 **/   
	API_DTO_FIELD(UInt64, mess_type, ZH_WORDS_GETTER("message.field.mess_type"), true, 1)
	// 收件人姓名
	API_DTO_FIELD(String, recv_name, ZH_WORDS_GETTER("message.field.recv_name"), true, "123")
	// 合同名称
	API_DTO_FIELD(String, contrast_name, ZH_WORDS_GETTER("message.field.con_name"), false, "")
	// 客户邮箱
	API_DTO_FIELD(String, mail, ZH_WORDS_GETTER("message.field.mail"), true, "123")
	// 扩展信息
	API_DTO_FIELD(String, mess, ZH_WORDS_GETTER("message.field.mess"),true,"123")
};
/**
 * 功能：短信发送DTO
 * 执行人：Detachment
**/
class SMSDTO : public oatpp::DTO
{
	DTO_INIT(SMSDTO, DTO);
	// 消息类型
	API_DTO_FIELD(UInt64, mess_type, ZH_WORDS_GETTER("message.field.mess_type"), true, 1)
	// 收件人姓名
	API_DTO_FIELD(String, recv_name, ZH_WORDS_GETTER("message.field.recv_name"), true, "123")
	// 合同名称
	API_DTO_FIELD(String, contrast_name, ZH_WORDS_GETTER("message.field.con_name"), false, "")
	// 客户电话
	API_DTO_FIELD(String, phone, ZH_WORDS_GETTER("message.field.phone"), true, "123")
	// 扩展信息
	API_DTO_FIELD(String, mess, ZH_WORDS_GETTER("message.field.mess"), true, "123")
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MESSAGEDTO_H_