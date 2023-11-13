#include "stdafx.h"
#include "SalesOpportunityService.h"
#include "dao/salesopportunity/SalesOpportunityDAO.h"

bool SalesOpportunityService::updateData(const UpdateSalesOpDTO::Wrapper& dto)
{
	// 定义一个DO对象
    SalesOpportunityDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ChanceId, chance_id, CustomerId, customer_id, LinkmanId, linkman_id, FindDate, find_date, BillDate, bill_date, Salestage, salestage, Money, money, SuccessRate, success_rate, UserId, userID, Name, name, Intro, intro, Status, status, CreateUserId, create_user_id, CreateTime, create_time);
    // 执行数据修改
    SalesOpportunityDAO dao;
    return dao.update(data) == 1;
}

bool SalesOpportunityService::deleteData(uint64_t id)
{
    SalesOpportunityDAO dao;
    return dao.deleteById(id) == 1;
}

bool SalesOpportunityService::insertData(const InsertSalesOpDTO::Wrapper& dto)
{
    // 定义一个DO对象
    SalesOpportunityDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ChanceId, chance_id, CustomerId, customer_id, LinkmanId, linkman_id, FindDate, find_date, BillDate, bill_date, Salestage, salestage, Money, money, SuccessRate, success_rate, UserId, userID, Name, name, Intro, intro, Status, status, CreateUserId, create_user_id, CreateTime, create_time);
    // 执行数据修改
    SalesOpportunityDAO dao;
    return dao.insert(data);
}

