/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/10/26 16:10:25

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
#include "SMS.h"
#include "sms/aliyun/AliSmsSender.h"
#include <iostream>
uint64_t SMS::sendSMS1(const SMSDTO::Wrapper dto)
{
	AliSmsSender sender;
	// 注意：因为参数中有中文字符，所以要设置本文件文件编码格式为 utf8-bom格式，不然会发送短信失败
	std::shared_ptr<AliSmsResult> res = sender.sendSms(dto->phone.getValue({}), "crm1", "SMS_463599199", "{\"name\":\"" + dto->recv_name.getValue({}) + "\",\"str\":\"" + dto->mess.getValue({}) + "\"}");
	std::cout
		<< "code:  " << res->Code() << std::endl
		<< "msg:   " << res->Message() << std::endl
		<< "bizid: " << res->BizId() << std::endl
		<< "reqid: " << res->RequestId() << std::endl;
	if (res->Code() != "OK")
		return 1;
	return 0;
}

uint64_t SMS::sendSMS2(const SMSDTO::Wrapper dto)
{
	AliSmsSender sender;
	// 注意：因为参数中有中文字符，所以要设置本文件文件编码格式为 utf8-bom格式，不然会发送短信失败
	std::shared_ptr<AliSmsResult> res = sender.sendSms(dto->phone.getValue({}), "crm1", "SMS_463599199", "{\"name\":\"" + dto->recv_name.getValue({}) + "\",\"str\":\"" + dto->mess.getValue({}) + "\"}");
	std::cout
		<< "code:  " << res->Code() << std::endl
		<< "msg:   " << res->Message() << std::endl
		<< "bizid: " << res->BizId() << std::endl
		<< "reqid: " << res->RequestId() << std::endl;
	if (res->Code() != "OK")
		return 1;
	return 0;
}

uint64_t SMS::sendSMS3(const SMSDTO::Wrapper dto)
{
	AliSmsSender sender;
	// 注意：因为参数中有中文字符，所以要设置本文件文件编码格式为 utf8-bom格式，不然会发送短信失败
	std::shared_ptr<AliSmsResult> res = sender.sendSms(dto->phone.getValue({}), "crm1", "SMS_463599030", "{\"name\":\""+dto->recv_name.getValue({}) +"\",\"contrast\":\""+dto->contrast_name.getValue({}) +"\"}");
	std::cout
		<< "code:  " << res->Code() << std::endl
		<< "msg:   " << res->Message() << std::endl
		<< "bizid: " << res->BizId() << std::endl
		<< "reqid: " << res->RequestId() << std::endl;
	if (res->Code() != "OK")
		return 1;
	return 0;
}

uint64_t SMS::sendSMS4(const SMSDTO::Wrapper dto)
{
	AliSmsSender sender;
	// 注意：因为参数中有中文字符，所以要设置本文件文件编码格式为 utf8-bom格式，不然会发送短信失败
	std::shared_ptr<AliSmsResult> res = sender.sendSms(dto->phone.getValue({}), "crm1", "SMS_463599199", "{\"name\":\"" + dto->recv_name.getValue({}) + "\",\"str\":\"" + dto->mess.getValue({}) + "\"}");
	std::cout
		<< "code:  " << res->Code() << std::endl
		<< "msg:   " << res->Message() << std::endl
		<< "bizid: " << res->BizId() << std::endl
		<< "reqid: " << res->RequestId() << std::endl;
	if (res->Code() != "OK")
		return 1;
	return 0;
}

uint64_t SMS::sendSMS5(const SMSDTO::Wrapper dto)
{
	AliSmsSender sender;
	// 注意：因为参数中有中文字符，所以要设置本文件文件编码格式为 utf8-bom格式，不然会发送短信失败
	std::shared_ptr<AliSmsResult> res = sender.sendSms(dto->phone.getValue({}), "crm1", "SMS_463599199", "{\"name\":\"" + dto->recv_name.getValue({}) + "\",\"str\":\"" + dto->mess.getValue({}) + "\"}");
	std::cout
		<< "code:  " << res->Code() << std::endl
		<< "msg:   " << res->Message() << std::endl
		<< "bizid: " << res->BizId() << std::endl
		<< "reqid: " << res->RequestId() << std::endl;
	if (res->Code() != "OK")
		return 1;
	return 0;
}

uint64_t SMS::sendSMS6(const SMSDTO::Wrapper dto)
{
	AliSmsSender sender;
	// 注意：因为参数中有中文字符，所以要设置本文件文件编码格式为 utf8-bom格式，不然会发送短信失败
	std::shared_ptr<AliSmsResult> res = sender.sendSms(dto->phone.getValue({}), "crm1", "SMS_463599199", "{\"name\":\"" + dto->recv_name.getValue({}) + "\",\"str\":\"" + dto->mess.getValue({}) + "\"}");
	std::cout
		<< "code:  " << res->Code() << std::endl
		<< "msg:   " << res->Message() << std::endl
		<< "bizid: " << res->BizId() << std::endl
		<< "reqid: " << res->RequestId() << std::endl;
	if (res->Code() != "OK")
		return 1;
	return 0;
}

uint64_t SMS::sendSMS7(const SMSDTO::Wrapper dto)
{
	AliSmsSender sender;
	// 注意：因为参数中有中文字符，所以要设置本文件文件编码格式为 utf8-bom格式，不然会发送短信失败
	std::shared_ptr<AliSmsResult> res = sender.sendSms(dto->phone.getValue({}), "crm1", "SMS_463599199", "{\"name\":\"" + dto->recv_name.getValue({}) + "\",\"str\":\"" + dto->mess.getValue({}) + "\"}");
	std::cout
		<< "code:  " << res->Code() << std::endl
		<< "msg:   " << res->Message() << std::endl
		<< "bizid: " << res->BizId() << std::endl
		<< "reqid: " << res->RequestId() << std::endl;
	if (res->Code() != "OK")
		return 1;
	return 0;
}

uint64_t SMS::sendSMS8(const SMSDTO::Wrapper dto)
{
	AliSmsSender sender;
	// 注意：因为参数中有中文字符，所以要设置本文件文件编码格式为 utf8-bom格式，不然会发送短信失败
	std::shared_ptr<AliSmsResult> res = sender.sendSms(dto->phone.getValue({}), "crm1", "SMS_463599199", "{\"name\":\"" + dto->recv_name.getValue({}) + "\",\"str\":\"" + dto->mess.getValue({}) + "\"}");
	std::cout
		<< "code:  " << res->Code() << std::endl
		<< "msg:   " << res->Message() << std::endl
		<< "bizid: " << res->BizId() << std::endl
		<< "reqid: " << res->RequestId() << std::endl;
	if (res->Code() != "OK")
		return 1;
	return 0;
}