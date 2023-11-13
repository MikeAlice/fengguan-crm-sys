#pragma once
/*
* �����ˣ��Ͼ�
*/
#include "stdafx.h"
#ifndef _IMPORTRESULT_DTO_
#define _IMPORTRESULT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����ͻ���Ϣ����������
 */
class ImportResultDTO : public oatpp::DTO
{
	DTO_INIT(ImportResultDTO, DTO);

	// ����ɹ�����
	API_DTO_FIELD_DEFAULT(Int32, success_count, ZH_WORDS_GETTER("customer.field.success_count"));

	// ����ʧ������
	API_DTO_FIELD_DEFAULT(Int32, fail_count, ZH_WORDS_GETTER("customer.field.fail_count"));


};

#include OATPP_CODEGEN_END(DTO)
#endif // !_IMPORTRESULT_DTO_