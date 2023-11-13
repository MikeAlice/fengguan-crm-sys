#pragma once
/*
* �����ˣ��Ͼ�
*/
#ifndef _IMPORTRESULT_VO_
#define _IMPORTRESULT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/customerfile/ImportResultDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ImportResultJsonVO : public JsonVO<ImportResultDTO::Wrapper> {
	DTO_INIT(ImportResultJsonVO, JsonVO<ImportResultDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORTRESULT_VO_