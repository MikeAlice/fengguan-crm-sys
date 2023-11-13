#pragma once
//#ifndef _COLLECTIONRECORD_VO_
//#define _COLLECTIONRECORD_VO_

#include"stdafx.h"
#include"../../GlobalInclude.h"
#include"../../dto/collectionrecords/CollectionRecordDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class CollectionRecordJsonVO : public JsonVO<CollectionRecordDTO::Wrapper> {
	DTO_INIT(CollectionRecordJsonVO, JsonVO<CollectionRecordDTO::Wrapper>);
	
};


class CollectionRecordPageJsonVO : public JsonVO<CollectionRecordPageDTO::Wrapper> {
	DTO_INIT(CollectionRecordPageJsonVO, JsonVO<CollectionRecordPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

//#endif
