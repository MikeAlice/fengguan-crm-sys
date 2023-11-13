#pragma once
#ifndef INSTORAGEVO_H__
#define INSTORAGEVO_H__

#include "../../GlobalInclude.h"
#include "../../dto/in_storage/InStorageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class InStorageJsonVO : public JsonVO<InStorageDTO::Wrapper> {
	DTO_INIT(InStorageJsonVO, JsonVO<InStorageDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class InStoragePageJsonVO : public JsonVO<InStoragePageDTO::Wrapper> {
	DTO_INIT(InStoragePageJsonVO, JsonVO<InStoragePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !INSTORAGEVO_H__