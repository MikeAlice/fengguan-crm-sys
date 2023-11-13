#pragma once

#include "stdafx.h"
#include "Mapper.h"
#include "domain/do/ExportSalesDO.h"


class ExportSalesMapper : public Mapper<ExportSalesDO> {
    std::list<std::string> ext_fields;
public:
    ExportSalesMapper(const std::list<std::string>& fields = {})
    {
        ext_fields = fields;
    }
    ExportSalesDO mapper(ResultSet* rs) const override {
        ExportSalesDO dto;
        dto.setTitle(rs->getString("title"));
        dto.setContractId(rs->getString("contract_id"));
        dto.setCustomerId(rs->getString("customer_id"));
      //  dto.setName(rs->getString("name"));
        dto.setMoney(rs->getInt64("money"));
        dto.setZeroMoney(rs->getInt64("zero_money"));
        dto.setBackMoney(rs->getInt64("back_money"));
        dto.setOweMoney(rs->getInt64("owe_money"));
        dto.setBackStatus(rs->getString("back_status"));
        dto.setInvoiceMoney(rs->getInt64("invoice_money"));
        dto.setInvoiceStatus(rs->getString("invoice_status"));
        dto.setStartDate(rs->getString("start_date"));
        dto.setEndDate(rs->getString("end_date"));
        dto.setDeliverMoney(rs->getInt64("deliver_money"));
        dto.setStatus(rs->getString("status"));
        dto.setDeliverStatus(rs->getString("deliver_status"));
      //  dto.setContent(rs->getString("content"));
        dto.setContractNo(rs->getString("contract_no"));
        dto.setLinkmanId(rs->getString("linkman_id"));
        dto.setChanceId(rs->getString("chance_id"));
        dto.setWebsiteId(rs->getString("website_id"));
        dto.setOurUserId(rs->getString("our_user_id"));
        dto.setIntro(rs->getString("intro"));
        dto.setRenewStatus(rs->getString("renew_status"));
        dto.setCreateUserId(rs->getString("create_user_id"));
        dto.setCreateTime(rs->getString("create_time"));
        dto.setGoodsMoney(rs->getInt64("goods_money"));
        return dto;
    }
};

