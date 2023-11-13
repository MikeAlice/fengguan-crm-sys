#include "stdafx.h"
#include "SendmsemService.h"
#include "dao/sendmsem/SendmsemDAO.h"
#include "domain/dto/sendmsem/SendmsemDTO.h"
#include "sms/aliyun/AliSmsSender.h"

//获取客户信息
oatpp::List<InfoDTO::Wrapper> SendmsemService::getinfo(const oatpp::List<oatpp::Int64>& dto)
{
	// 构建返回对象
	auto sample = InfoDTO::createShared();
	oatpp::List<InfoDTO::Wrapper> res = { sample };
	res->pop_back();
	// 定义数据操作层
	SendmsemDAO dao;

	// 查询数据
	for (auto& id : *dto) {
		list<SendmsemDO> result = dao.selectByid(id);
		if (result.size() == 0)
			continue;
		SendmsemDO infodo = *(result.begin());
		//过滤没有预约的客户
		if (infodo.getTime().size() == 0)
			continue;
		//输入短信/邮件内容
		//
		//将DO转换成DTO 
		auto infodto = InfoDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(infodto, infodo, mess_type, Mess_type, recv_name, Recv_name, contrast_name, Contrast_name, mail, Mail, mess, Mess, phone, Phone);
		res->push_back(infodto);
	}

	return res;
}

//发送短信
bool SendmsemService::sendms(const oatpp::List<InfoDTO::Wrapper>& infos) {
	return true;
}

//发送邮件
bool SendmsemService::sendem(const oatpp::List<InfoDTO::Wrapper>& infos) {
	return true;
}