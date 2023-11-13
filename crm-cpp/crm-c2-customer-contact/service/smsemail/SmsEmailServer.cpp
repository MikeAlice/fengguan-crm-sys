#include "stdafx.h"
#include "SmsEmailServer.h"
#include"dao/smsemail/SmsEmailDAO.h"
#include"domain/query/smsemail/SmsEmailQuery.h"
#include"domain/dto/smsemail/EmailDTO.h"
#include"domain/dto/smsemail/SmsDTO.h"
#include"service/smsemail/declarative/SmsEmailApiClient.h"
#include"controller/ApiDeclarativeServicesHelper.h"
bool SmsEmailService::sendSms(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload)
{
    //先创建一个DAO对象
    SmsEmailDAO dao;
    //要拼装的DTO
    auto lsdto=oatpp::List<SmsDTO::Wrapper>::createShared();
    auto nulldto = SmsDTO::createShared();
    //查询数据,拼接DTO
    for (int i = 0; i < qdto->linkman_id->size(); i++)
    {
        auto result = dao.queryMobile(qdto->linkman_id[i]);
        for (SmsDO sub : result)
        {
            lsdto->push_back(nulldto);
            ZO_STAR_DOMAIN_DO_TO_DTO(lsdto->front(), sub, recv_name, Name, phone, Mobile);
            lsdto->front()->mess = qdto->content;
            lsdto->front()->mess_type = qdto->ctype;
            lsdto->front()->contrast_name = "";
        }
    }
    if (lsdto->empty())
    {
        return false;
    }
    //使用声明式服务发送短信
    // 创建客户端对象
    API_CLIENT_CREATE(ac, om, SmsEmailApiClient, "smsemail-api");
    // 构建凭证
    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
    // 返回查询结果
    if (ac->sendSmss(lsdto))
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
    auto lsdto = oatpp::List<EmailDTO::Wrapper>::createShared();
    auto nulldto = EmailDTO::createShared();
    //查询数据,拼接DTO
    for (int i = 0; i < qdto->linkman_id->size(); i++)
    {
        auto result = dao.queryEmail(qdto->linkman_id[i]);
        for (EmailDO sub : result)
        {
            lsdto->push_back(nulldto);
            ZO_STAR_DOMAIN_DO_TO_DTO(lsdto->front(), sub, recv_name, Name, mail, Email);
            lsdto->front()->mess = qdto->content;
            lsdto->front()->mess_type = qdto->ctype;
            lsdto->front()->contrast_name = "";
        }
    }
    if (lsdto->empty())
    {
        return false;
    }
    //使用声明式服务发送邮件
    // 创建客户端对象
    API_CLIENT_CREATE(ac, om, SmsEmailApiClient, "smsemail-api");
    // 构建凭证
    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
    // 返回查询结果
    if (ac->sendEmail(lsdto))
    {
        return true;
    }
    return false;
}

