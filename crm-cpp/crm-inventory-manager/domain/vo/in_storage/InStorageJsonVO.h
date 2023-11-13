#pragma once
#ifndef INSTORAGEVO_H__
#define INSTORAGEVO_H__

#include "../../GlobalInclude.h"
#include "../../dto/in_storage/InStorageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class InStorageJsonVO : public JsonVO<InStorageDTO::Wrapper> {
	DTO_INIT(InStorageJsonVO, JsonVO<InStorageDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class InStoragePageJsonVO : public JsonVO<InStoragePageDTO::Wrapper> {
	DTO_INIT(InStoragePageJsonVO, JsonVO<InStoragePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !INSTORAGEVO_H__