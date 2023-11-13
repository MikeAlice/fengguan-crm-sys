#pragma once
#ifndef _PAYRECORDS_VO_
#define _PAYRECORDS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/payrecords/PayrecordsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个付款记录显示JsonVO对象，用于响应给客户端
*/
class PayrecordsJsonVO : public JsonVO<PayrecordsDTO::Wrapper>{
	DTO_INIT(PayrecordsJsonVO, JsonVO<PayrecordsDTO::Wrapper>);
};

/**
 * 定义一个付款记录列表分页显示JsonVO对象，用于响应给客户端
 */
class PayrecordsPageJsonVO : public JsonVO<PayrecordsPageDTO::Wrapper>{
template<class __Z__T__PARAM> friend class oatpp::data::mapping::type::__class::Object; public: typedef PayrecordsPageJsonVO Z__CLASS; typedef JsonVO<PayrecordsPageDTO::Wrapper> Z__CLASS_EXTENDED; typedef oatpp::data::mapping::type::DTOWrapper<Z__CLASS> Wrapper; private: static const oatpp::Type* getParentType() {
    return oatpp::Object<Z__CLASS_EXTENDED>::Class::getType();
} static const char* Z__CLASS_TYPE_NAME() {
    return "PayrecordsPageJsonVO";
} static oatpp::data::mapping::type::BaseObject::Properties* Z__CLASS_GET_FIELDS_MAP() {
    static oatpp::data::mapping::type::BaseObject::Properties map = oatpp::data::mapping::type::BaseObject::Properties(); return &map;
} public: template<typename ... Args> static Wrapper createShared(Args... args) {
    return Wrapper(std::make_shared<Z__CLASS>(args...), Wrapper::Class::getType());
};
};

#include OATPP_CODEGEN_END(DTO)
#endif // _PAYRECORDS_H_