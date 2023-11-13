#pragma once
/*
* 负责人：老菌
*/
#include "stdafx.h"
#ifndef _IMPORTRESULT_DTO_
#define _IMPORTRESULT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 导入客户信息结果传输对象
 */
class ImportResultDTO : public oatpp::DTO
{
	DTO_INIT(ImportResultDTO, DTO);

	// 导入成功行数
	API_DTO_FIELD_DEFAULT(Int32, success_count, ZH_WORDS_GETTER("customer.field.success_count"));

	// 导入失败行数
	API_DTO_FIELD_DEFAULT(Int32, fail_count, ZH_WORDS_GETTER("customer.field.fail_count"));


};

#include OATPP_CODEGEN_END(DTO)
#endif // !_IMPORTRESULT_DTO_