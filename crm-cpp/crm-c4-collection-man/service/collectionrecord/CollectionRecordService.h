#pragma once


#ifndef _COLLECTIONRECORD_SERVICE_
#define _COLLECTIONRECORD_SERVICE_

#include <list>
#include "domain/query/collectionrecord/CollectionRecordQuery.h"
#include "domain/dto/collectionrecords/CollectionRecordDTO.h"
#include "domain/dto/collectionrecords/delCollectionRecordDTO.h"
#include "domain/dto/collectionrecords/exportCollectionRecordDTO.h"
#include"domain/do/collectionrecord/CollectionRecordDO.h"




class CollectionRecordService
{
public:
	// ��ҳ��ѯ��������
	CollectionRecordPageDTO::Wrapper listCollectionRecord(const CollectionRecordQuery::Wrapper& query);
	// ��������
	uint64_t saveCollectrionRecord(const CollectionRecordDTO::Wrapper& dto);
	// ��������
	oatpp::String exportCollectionRecord(const DelCollectionRecordDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeCollectionRecord(uint64_t id);
};

#endif 


