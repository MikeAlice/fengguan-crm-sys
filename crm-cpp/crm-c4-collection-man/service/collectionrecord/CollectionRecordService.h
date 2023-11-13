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
	// 分页查询所有数据
	CollectionRecordPageDTO::Wrapper listCollectionRecord(const CollectionRecordQuery::Wrapper& query);
	// 保存数据
	uint64_t saveCollectrionRecord(const CollectionRecordDTO::Wrapper& dto);
	// 导出数据
	oatpp::String exportCollectionRecord(const DelCollectionRecordDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeCollectionRecord(uint64_t id);
};

#endif 


