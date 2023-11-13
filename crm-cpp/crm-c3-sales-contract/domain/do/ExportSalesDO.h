#pragma once

#ifndef _EXPORT_SALES_DO_
#define _EXPORT_SALES_DO_
#include "DoInclude.h"
class ExportSalesDO
{
    // Title
    CC_SYNTHESIZE(string, title, Title);
    // Contract ID
    CC_SYNTHESIZE(string, contract_id, ContractId);
    // Customer ID
    CC_SYNTHESIZE(string, customer_id, CustomerId);
    // Name
  //  CC_SYNTHESIZE(string, name, Name);
    // Money
    CC_SYNTHESIZE(int64_t, money, Money);
    // Zero Money
    CC_SYNTHESIZE(int64_t, zero_money, ZeroMoney);
    // Back Money
    CC_SYNTHESIZE(int64_t, back_money, BackMoney);
    // Owe Money
    CC_SYNTHESIZE(int64_t, owe_money, OweMoney);
    // Back Status
    CC_SYNTHESIZE(string, back_status, BackStatus);
    // Invoice Money
    CC_SYNTHESIZE(int64_t, invoice_money, InvoiceMoney);
    // Invoice Status
    CC_SYNTHESIZE(string, invoice_status, InvoiceStatus);
    // Start Date
    CC_SYNTHESIZE(string, start_date, StartDate);
    // End Date
    CC_SYNTHESIZE(string, end_date, EndDate);
    // Deliver Money
    CC_SYNTHESIZE(int64_t, deliver_money, DeliverMoney);
    // Status
    CC_SYNTHESIZE(string, status, Status);
    // Deliver Status
    CC_SYNTHESIZE(string, deliver_status, DeliverStatus);
    // Content
   // CC_SYNTHESIZE(string, content, Content);
    // Contract No
    CC_SYNTHESIZE(string, contract_no, ContractNo);
    // Linkman ID
    CC_SYNTHESIZE(string, linkman_id, LinkmanId);
    // Chance ID
    CC_SYNTHESIZE(string, chance_id, ChanceId);
    // Website ID
    CC_SYNTHESIZE(string, website_id, WebsiteId);
    // Our User ID
    CC_SYNTHESIZE(string, our_user_id, OurUserId);
    // Intro
    CC_SYNTHESIZE(string, intro, Intro);
    // Renew Status
    CC_SYNTHESIZE(string, renew_status, RenewStatus);
    // Create User ID
    CC_SYNTHESIZE(string, create_user_id, CreateUserId);
    // Create Time
    CC_SYNTHESIZE(string, create_time, CreateTime);
    // Goods Money
    CC_SYNTHESIZE(int64_t, goods_money, GoodsMoney);

public:
    ExportSalesDO() {
        title = "";
        contract_id = "";
        customer_id = "";
       // name = "";
        money = 0;
        zero_money = 0;
        back_money = 0;
        owe_money = 0;
        back_status = "";
        invoice_money = 0;
        invoice_status = "";
        start_date = "";
        end_date = "";
        deliver_money = 0;
        status = "";
        deliver_status = "";
      //  content = "";
        contract_no = "";
        linkman_id = "";
        chance_id = "";
        website_id = "";
        our_user_id = "";
        intro = "";
        renew_status = "";
        create_user_id = "";
        create_time = "";
        goods_money = 0;
    }
};
#endif

