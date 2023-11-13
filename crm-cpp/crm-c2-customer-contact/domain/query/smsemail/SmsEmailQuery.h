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
	DTO_INIT(SmsEmailQuery,DTO);
	//联系人编号
	DTO_FIELD(List<UInt32>, linkman_id);
	DTO_FIELD_INFO(linkman_id) {
		info->description = ZH_WORDS_GETTER("smsemail.field.linkman_id");
	}
	//发送类型
	DTO_FIELD(UInt64, ctype);
	DTO_FIELD_INFO(ctype) {
		info->description = ZH_WORDS_GETTER("smsemail.field.ctype");
	}
	//发送内容
	DTO_FIELD(String, content);
	DTO_FIELD_INFO(content) {
		info->description = ZH_WORDS_GETTER("smsemail.field.content");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SMSEMAIL_QUERY_
