#pragma once

#ifndef _COLLECTIONS_VO_
#define _COLLECTIONS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/collectionplans/GetCollectionPlanListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取回款计划显示JsonVO，用于响应给客户端的Json对象
 */
class CollectionPlansVO : public JsonVO<GetCollectionPlanListDTO::Wrapper> {
	DTO_INIT(CollectionPlansVO, JsonVO<GetCollectionPlanListDTO::Wrapper>);
};

/**
 * 获取回款计划分页显示JsonVO，用于响应给客户端的Json对象
 */
class CollectionPlansPageJsonVO : public JsonVO<GetCollectionPlanListPageDTO::Wrapper> {
	DTO_INIT(CollectionPlansPageJsonVO, JsonVO<GetCollectionPlanListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !