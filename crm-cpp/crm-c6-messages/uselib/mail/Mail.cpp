/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/23 11:00:20

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
#include "stdafx.h"
#include "Mail.h"
#include <iostream>
#include "Macros.h"
#include "NacosClient.h"
#include "ServerInfo.h"
#include "EmailSender.h"
uint64_t Mail::sendMail1(const MailDTO::Wrapper& dto)
{
	std::string email_subject = u8"节日祝福";
	std::string email_body1 = "<html><meta charset=\"UTF-8\"><body>"
		u8"<p>亲爱的用户<b>" + dto->recv_name.getValue({}) + u8"</b>您好。</p>"
		u8"<p>：<b>" + dto->mess.getValue({}) + u8"</b></p>"
		"</body></html>";

	ZO_CREATE_MAIL_SENDER(emailSender);
	emailSender.setCharset("utf-8");
	emailSender.addRecvEmailAddr(dto->mail.getValue({}), dto->recv_name.getValue({}));
	emailSender.setEmailContent(email_subject, email_body1);
	if (emailSender.send())
	{
		return 0;
	}
	else
		return 1;
}

uint64_t Mail::sendMail2(const MailDTO::Wrapper& dto)
{
	std::string email_subject = u8"新品推荐通知";
	std::string email_body1 = "<html><meta charset=\"UTF-8\"><body>"
		u8"<p>亲爱的用户<b>" + dto->recv_name.getValue({}) + u8"</b>您好。</p>"
		u8"<p><b>" + dto->mess.getValue({}) + u8"</b></p>"
		"</body></html>";

	ZO_CREATE_MAIL_SENDER(emailSender);
	emailSender.addRecvEmailAddr(dto->mail.getValue({}), dto->recv_name.getValue({}));
	emailSender.setEmailContent(email_subject, email_body1);
	if (emailSender.send())
		return 0;
	else
		return 1;
}

/**
 * 功能：执行合同到期邮件发送，成功返回0，失败返回1
 * 执行人：Detachment
**/
uint64_t Mail::sendMail3(const MailDTO::Wrapper& dto)
{
	std::string email_subject = u8"合同到期通知";
	std::string email_body1 = "<html><meta charset=\"UTF-8\"><body>"
		u8"<p>亲爱的用户<b>"+dto->recv_name.getValue({}) +u8"</b>您好。</p>"
		u8"<p>您的合同：<b>"+dto->contrast_name.getValue({}) +u8"</b>已过期。</p>"
		"</body></html>";

	ZO_CREATE_MAIL_SENDER(emailSender);
	emailSender.addRecvEmailAddr(dto->mail.getValue({}), dto->recv_name.getValue({}));
	emailSender.setEmailContent(email_subject, email_body1);
	if (emailSender.send())
		return 0;
	else
		return 1;
}

uint64_t Mail::sendMail4(const MailDTO::Wrapper& dto)
{
	std::string email_subject = u8"合同到期通知";
	std::string email_body1 = "<html><meta charset=\"UTF-8\"><body>"
		u8"<p>亲爱的用户<b>" + dto->recv_name.getValue({}) + u8"</b>您好。</p>"
		u8"<p>您的合同：<b>" + dto->contrast_name.getValue({}) + u8"</b>已过期。</p>"
		"</body></html>";

	ZO_CREATE_MAIL_SENDER(emailSender);
	emailSender.addRecvEmailAddr(dto->mail.getValue({}), dto->recv_name.getValue({}));
	emailSender.setEmailContent(email_subject, email_body1);
	if (emailSender.send())
		return 0;
	else
		return 1;
}

uint64_t Mail::sendMail5(const MailDTO::Wrapper& dto)
{
	std::string email_subject = u8"联系人预约提醒";
	std::string email_body1 = "<html><meta charset=\"UTF-8\"><body>"
		u8"<p>亲爱的用户<b>" + dto->recv_name.getValue({}) + u8"</b>您好。</p>"
		u8"<p>您预约的：<b>" + dto->mess.getValue({}) + u8"</b></p>"
		"</body></html>";

	ZO_CREATE_MAIL_SENDER(emailSender);
	emailSender.addRecvEmailAddr(dto->mail.getValue({}), dto->recv_name.getValue({}));
	emailSender.setEmailContent(email_subject, email_body1);
	if (emailSender.send())
		return 0;
	else
		return 1;
}

uint64_t Mail::sendMail6(const MailDTO::Wrapper& dto)
{
	std::string email_subject = u8"销售机会预约提醒";
	std::string email_body1 = "<html><meta charset=\"UTF-8\"><body>"
		u8"<p>亲爱的用户<b>" + dto->recv_name.getValue({}) + u8"</b>您好。</p>"
		u8"<p>您预约的：<b>" + dto->mess.getValue({}) + u8"</b>时间已到。</p>"
		"</body></html>";

	ZO_CREATE_MAIL_SENDER(emailSender);
	emailSender.addRecvEmailAddr(dto->mail.getValue({}), dto->recv_name.getValue({}));
	emailSender.setEmailContent(email_subject, email_body1);
	if (emailSender.send())
		return 0;
	else
		return 1;
}

uint64_t Mail::sendMail7(const MailDTO::Wrapper& dto)
{
	std::string email_subject = u8"跟踪记录预约提醒";
	std::string email_body1 = "<html><meta charset=\"UTF-8\"><body>"
		u8"<p>亲爱的用户<b>" + dto->recv_name.getValue({}) + u8"</b>您好。</p>"
		u8"<p>您预约的：<b>" + dto->mess.getValue({}) + u8"</b>时间已到</p>"
		"</body></html>";

	ZO_CREATE_MAIL_SENDER(emailSender);
	emailSender.addRecvEmailAddr(dto->mail.getValue({}), dto->recv_name.getValue({}));
	emailSender.setEmailContent(email_subject, email_body1);
	if (emailSender.send())
		return 0;
	else
		return 1;
}

uint64_t Mail::sendMail8(const MailDTO::Wrapper& dto)
{
	std::string email_subject = u8"供应商联系人预约提醒";
	std::string email_body1 = "<html><meta charset=\"UTF-8\"><body>"
		u8"<p>亲爱的用户<b>" + dto->recv_name.getValue({}) + u8"</b>您好。</p>"
		u8"<p>您预约的：<b>" + dto->mess.getValue({}) + u8"</b></p>"
		"</body></html>";

	ZO_CREATE_MAIL_SENDER(emailSender);
	emailSender.addRecvEmailAddr(dto->mail.getValue({}), dto->recv_name.getValue({}));
	emailSender.setEmailContent(email_subject, email_body1);
	if (emailSender.send())
		return 0;
	else
		return 1;
}
