#pragma once
/*
* 负责人：老菌
*/
#ifndef _IMPORTRESULT_VO_
#define _IMPORTRESULT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/customerfile/ImportResultDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 导入结果显示JsonVO，用于响应给客户端的Json对象
 */
class ImportResultJsonVO : public JsonVO<ImportResultDTO::Wrapper> {
	DTO_INIT(ImportResultJsonVO, JsonVO<ImportResultDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORTRESULT_VO_