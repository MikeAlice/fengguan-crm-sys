#ifndef _GETCUSTOMERNAME_VO_
#define _GETCUSTOMERNAME_VO_

#include "../../GlobalInclude.h"
#include "../../dto/getcustomername/GetCustomerNameDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取客户名称列表显示JsonVO，用于响应给客户端的Json对象
 */
class GetCustomerNameJsonVO : public JsonVO<oatpp::List<GetCustomerNameDTO::Wrapper>> {
	DTO_INIT(GetCustomerNameJsonVO, JsonVO<oatpp::List<GetCustomerNameDTO::Wrapper>>);
public:
	GetCustomerNameJsonVO() {
		this->data = {};
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETCUSTOMERNAME_VO_
