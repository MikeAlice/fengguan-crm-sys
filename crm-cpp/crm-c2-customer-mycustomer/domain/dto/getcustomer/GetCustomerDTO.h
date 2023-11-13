#ifndef GETCUSTOMERDTO_H__
#define GETCUSTOMERDTO_H__
#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取客户列表传输对象
 */
class GetCustomerDTO :public oatpp::DTO
{
	DTO_INIT(GetCustomerDTO, DTO);
	//客户名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("getcustomer.field.name"));
	//客户ID
	API_DTO_FIELD_DEFAULT(UInt32, customer_id, ZH_WORDS_GETTER("getcustomer.field.customer_id"));
	//归属于
	API_DTO_FIELD_DEFAULT(UInt32, owner_user_id, ZH_WORDS_GETTER("getcustomer.field.owner_user_id"));
	//上次联系时间
	API_DTO_FIELD_DEFAULT(String, conn_time, ZH_WORDS_GETTER("getcustomer.field.conn_time"));
	//联系内容
	API_DTO_FIELD_DEFAULT(String, conn_body, ZH_WORDS_GETTER("getcustomer.field.conn_body"));
	//下次联系时间
	API_DTO_FIELD_DEFAULT(String, next_time, ZH_WORDS_GETTER("getcustomer.field.next_time"));
};

class GetCustomerPageDTO : public PageDTO<GetCustomerDTO::Wrapper>
{
	DTO_INIT(GetCustomerPageDTO, PageDTO<GetCustomerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // GETCUSTOMERDTO_H__