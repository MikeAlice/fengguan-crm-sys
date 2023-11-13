#pragma once

#ifndef _DEL_COLLECTIONRECORD_DTO_
#define _DEL_COLLECTIONRECORD_DTO_

#include "../../GlobalInclude.h"
//#include"../../query/collectionrecord/CollectionRecordQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class DelCollectionRecordDTO : public oatpp::DTO
{

	DTO_INIT(DelCollectionRecordDTO, DTO);

	// »Ø¿î±àºÅ
	DTO_FIELD(List<UInt64>, record_id) = {};
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.record_id_List");
	}
	
};



#endif