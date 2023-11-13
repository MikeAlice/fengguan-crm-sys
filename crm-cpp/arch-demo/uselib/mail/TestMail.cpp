/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/24 20:50:24

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
#include <iostream>
#include "TestMail.h"
#include "Macros.h"
#include "NacosClient.h"
#include "ServerInfo.h"
#include "EmailSender.h"

void TestMail::test()
{
	std::string email_subject = u8"测试主题";
	std::string email_body1 = "<html><meta charset=\"UTF-8\"><body>"
		u8"<p>我是<b>中文</b></p>"
		u8"<p><font color=red>我是红色的中文</font></p>"
		"</body></html>";
	std::string email_body2 = u8"我是中文，文字消息内容。";

	ZO_CREATE_MAIL_SENDER(emailSender);
	emailSender.addRecvEmailAddr("2069682479@qq.com", "awei");
	emailSender.setEmailContent(email_subject, email_body1);
	emailSender.addAttachment("/home/file/1.zip");
	if (emailSender.send())
		std::cout << "mail send ok" << std::endl;
	else
		std::cout << "mail send fail" << std::endl;
}
