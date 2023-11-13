#include "stdafx.h"
#include "SmsEmailServer.h"
#include"dao/c3-gugu/SmsMailDAO.h"
#include"domain/query/c3-gugu/SmsEmailQuery.h"
#include"domain/dto/c3-gugu/SmsMailDTO.h"
#include"service/c3-gugu/declarative/SmsEmailApiClient.h"
#include"controller/ApiDeclarativeServicesHelper.h"
bool SmsEmailService::sendSms(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload)
{
    //先创建一个DAO对象
    SmsEmailDAO dao;
    //要拼装的DTO
    auto lsdto = oatpp::List<SmsDTO::Wrapper>::createShared();
    auto nulldto = SmsDTO::createShared();
    //查询数据,拼接DTO
    for (int i = 0; i < qdto->chance_id->size(); i++)
    {
        auto result = dao.queryMobile(qdto->chance_id[i]);
        for (SmsDO sub : result)
        {
            lsdto->push_back(nulldto);
            lsdto->front()->recv_name = sub.getRecv_Name(); lsdto->front()->chance_name = sub.getChance_Name();
            lsdto->front()->phone = sub.getPhone(); lsdto->front()->mess = qdto->mess;
            lsdto->front()->mess_type = qdto->mess_type;
        }
    }
    //使用声明式服务发送短信
    // 创建客户端对象
    API_CLIENT_CREATE(ac, om, SmsEmailApiClient, "sendSms-api");
    // 构建凭证
    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();

    if (ac->sendSms(lsdto))
    {
        return true;
    }
    return false;
}

bool SmsEmailService::sendEmail(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload)
{
    //先创建一个DAO对象
    SmsEmailDAO dao;
    //要拼装的DTO
    auto lsdto = oatpp::List<MailDTO::Wrapper>::createShared();
    auto nulldto = MailDTO::createShared();
    //查询数据,拼接DTO
    for (int i = 0; i < qdto->chance_id->size(); i++)
    {
        auto result = dao.queryEmail(qdto->chance_id[i]);
        for (EmailDO sub : result)
        {
            lsdto->push_back(nulldto);
            lsdto->front()->recv_name = sub.getRecv_Name(); lsdto->front()->chance_name = sub.getChance_Name();
            lsdto->front()->mail = sub.getMail(); lsdto->front()->mess = qdto->mess;
            lsdto->front()->mess_type = qdto->mess_type;
        }
    }
    //使用声明式服务发送邮件
    // 创建客户端对象
    API_CLIENT_CREATE(ac, om, SmsEmailApiClient, "sendEmail-api");
    // 构建凭证
    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
    // 返回查询结果
    if (ac->sendEmail(lsdto))
    {
        return true;
    }
    return false;
}

