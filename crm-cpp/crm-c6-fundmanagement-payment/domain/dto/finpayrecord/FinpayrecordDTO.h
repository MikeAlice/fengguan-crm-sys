#pragma once
#ifndef _FINPAYRECORD_DTO_
#define _FINPAYRECORD_DTO_
#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DelFinpayrecordDTO :public oatpp::DTO {

	DTO_INIT(DelFinpayrecordDTO, DTO);

	API_DTO_FIELD_DEFAULT(UInt64, record_id, ZH_WORDS_GETTER("fin_pay_record.field.record_id"));

};


#include OATPP_CODEGEN_END(DTO)

#endif // !_FINPAYRECORD_DTO_
