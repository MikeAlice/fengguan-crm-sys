#pragma once

#ifndef _COLLECTIONS_VO_
#define _COLLECTIONS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/collectionplans/GetCollectionPlanListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ�ؿ�ƻ���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CollectionPlansVO : public JsonVO<GetCollectionPlanListDTO::Wrapper> {
	DTO_INIT(CollectionPlansVO, JsonVO<GetCollectionPlanListDTO::Wrapper>);
};

/**
 * ��ȡ�ؿ�ƻ���ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CollectionPlansPageJsonVO : public JsonVO<GetCollectionPlanListPageDTO::Wrapper> {
	DTO_INIT(CollectionPlansPageJsonVO, JsonVO<GetCollectionPlanListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !