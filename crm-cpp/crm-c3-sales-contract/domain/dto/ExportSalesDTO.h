#pragma once
#include "domain/GlobalInclude.h"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

class ExportSalesDTO : public oatpp::DTO {
    DTO_INIT(ExportSalesDTO, DTO);
    API_DTO_FIELD_DEFAULT(String, title, ZH_WORDS_GETTER("SalesContract.field.title"));
    API_DTO_FIELD_DEFAULT(String, contract_id, ZH_WORDS_GETTER("SalesContract.field.contract_id"));
    API_DTO_FIELD_DEFAULT(String, customer_id, ZH_WORDS_GETTER("SalesContract.field.customer_id"));
 //   API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("SalesContract.field.name"));
    API_DTO_FIELD_DEFAULT(String, money, ZH_WORDS_GETTER("SalesContract.field.money"));
    API_DTO_FIELD_DEFAULT(String, zero_money, ZH_WORDS_GETTER("SalesContract.field.zero_money"));
    API_DTO_FIELD_DEFAULT(String, back_money, ZH_WORDS_GETTER("SalesContract.field.back_money"));
    API_DTO_FIELD_DEFAULT(String, owe_money, ZH_WORDS_GETTER("SalesContract.field.owe_money"));
    API_DTO_FIELD_DEFAULT(String, back_status, ZH_WORDS_GETTER("SalesContract.field.back_status"));
    API_DTO_FIELD_DEFAULT(String, invoice_money, ZH_WORDS_GETTER("SalesContract.field.invoice_money"));
    API_DTO_FIELD_DEFAULT(String, invoice_status, ZH_WORDS_GETTER("SalesContract.field.invoice_status"));
    API_DTO_FIELD_DEFAULT(String, start_date, ZH_WORDS_GETTER("SalesContract.field.start_date"));
    API_DTO_FIELD_DEFAULT(String, end_date, ZH_WORDS_GETTER("SalesContract.field.end_date"));
    API_DTO_FIELD_DEFAULT(String, deliver_money, ZH_WORDS_GETTER("SalesContract.field.deliver_money"));
    API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("SalesContract.field.status"));
    API_DTO_FIELD_DEFAULT(String, deliver_status, ZH_WORDS_GETTER("SalesContract.field.deliver_status"));
  //  API_DTO_FIELD_DEFAULT(String, content, ZH_WORDS_GETTER("SalesContract.field.content"));
    API_DTO_FIELD_DEFAULT(String, contract_no, ZH_WORDS_GETTER("SalesContract.field.contract_no"));
    API_DTO_FIELD_DEFAULT(String, linkman_id, ZH_WORDS_GETTER("SalesContract.field.linkman_id"));
    API_DTO_FIELD_DEFAULT(String, chance_id, ZH_WORDS_GETTER("SalesContract.field.chance_id"));
    API_DTO_FIELD_DEFAULT(String, website_id, ZH_WORDS_GETTER("SalesContract.field.website_id"));
    API_DTO_FIELD_DEFAULT(String, our_user_id, ZH_WORDS_GETTER("SalesContract.field.our_user_id"));
    API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("SalesContract.field.intro"));
    API_DTO_FIELD_DEFAULT(String, renew_status, ZH_WORDS_GETTER("SalesContract.field.renew_status"));
    API_DTO_FIELD_DEFAULT(String, create_user_id, ZH_WORDS_GETTER("SalesContract.field.create_user_id"));
    API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("SalesContract.field.create_time"));
    API_DTO_FIELD_DEFAULT(String, goods_money, ZH_WORDS_GETTER("SalesContract.field.goods_money"));
};
