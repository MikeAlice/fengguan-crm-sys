
#pragma once

#ifndef _EXPORT_COLLECTIONRECORD_DTO_
#define _EXPORT_COLLECTIONRECORD_DTO_

#include "../../GlobalInclude.h"
//#include"../../query/collectionrecord/CollectionRecordQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class ExportCollectionRecordDTO : public oatpp::DTO
{

	DTO_INIT(ExportCollectionRecordDTO, DTO);

	// »Ø¿î±àºÅ
	DTO_FIELD(String, downloadUrl);
	DTO_FIELD_INFO(downloadUrl) {
		info->description = ZH_WORDS_GETTER("collectionRecord.field.downloadUrl");
	}

};



#endif