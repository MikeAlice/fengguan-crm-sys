#include "stdafx.h"
#include "SmsEmailServer.h"
#include"dao/c3-gugu/SmsMailDAO.h"
#include"domain/query/c3-gugu/SmsEmailQuery.h"
#include"domain/dto/c3-gugu/SmsMailDTO.h"
#include"service/c3-gugu/declarative/SmsEmailApiClient.h"
#include"controller/ApiDeclarativeServicesHelper.h"
bool SmsEmailService::sendSms(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload)
{
    //�ȴ���һ��DAO����
    SmsEmailDAO dao;
    //Ҫƴװ��DTO
    auto lsdto = oatpp::List<SmsDTO::Wrapper>::createShared();
    auto nulldto = SmsDTO::createShared();
    //��ѯ����,ƴ��DTO
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
    //ʹ������ʽ�����Ͷ���
    // �����ͻ��˶���
    API_CLIENT_CREATE(ac, om, SmsEmailApiClient, "sendSms-api");
    // ����ƾ֤
    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();

    if (ac->sendSms(lsdto))
    {
        return true;
    }
    return false;
}

bool SmsEmailService::sendEmail(const SmsEmailQuery::Wrapper& qdto, const PayloadDTO& payload)
{
    //�ȴ���һ��DAO����
    SmsEmailDAO dao;
    //Ҫƴװ��DTO
    auto lsdto = oatpp::List<MailDTO::Wrapper>::createShared();
    auto nulldto = MailDTO::createShared();
    //��ѯ����,ƴ��DTO
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
    //ʹ������ʽ�������ʼ�
    // �����ͻ��˶���
    API_CLIENT_CREATE(ac, om, SmsEmailApiClient, "sendEmail-api");
    // ����ƾ֤
    std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
    // ���ز�ѯ���
    if (ac->sendEmail(lsdto))
    {
        return true;
    }
    return false;
}

