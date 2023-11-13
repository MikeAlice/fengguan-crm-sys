#ifndef _SMSEMAIL_QUERY_
#define _SMSEMAIL_QUERY_
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 查询邮件短信对象
 */
class SmsEmailQuery : public oatpp::DTO
{
	DTO_INIT(SmsEmailQuery, DTO);
	//客户编号
	DTO_FIELD(List<UInt32>, chance_id);
	DTO_FIELD_INFO(chance_id) {
		info->description = ZH_WORDS_GETTER("opportunities.field.smsemail.id");
	}
	//发送内容
	DTO_FIELD(String, mess);
	DTO_FIELD_INFO(mess) {
		info->description = ZH_WORDS_GETTER("opportunities.field.smsemail.mess");
	}
	//发送类型
	DTO_FIELD(UInt32, mess_type);
	DTO_FIELD_INFO(mess_type) {
		info->description = ZH_WORDS_GETTER("opportunities.field.smsemail.mess_type");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SMSEMAIL_QUERY_
