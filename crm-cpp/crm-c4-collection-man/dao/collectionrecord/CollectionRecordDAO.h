#pragma once


#include"BaseDAO.h"
#include"../../domain/do/collectionrecord/CollectionRecordDO.h"
#include"../../domain/query/collectionrecord/CollectionRecordQuery.h"
#include"../../domain/dto/collectionrecords/exportCollectionRecordDTO.h"
#include"../../domain/dto/collectionrecords/delCollectionRecordDTO.h"

class CollectionRecordDAO:public BaseDAO{
public:
	uint64_t count(const CollectionRecordQuery::Wrapper& query);

	list<CollectionRecordDO> selectWithPage(const CollectionRecordQuery::Wrapper& query);

	uint64_t insert(const CollectionRecordDO& iObj);

	int deleteById(uint64_t id);

	list<CollectionRecordDO> selectById(const DelCollectionRecordDTO::Wrapper& exportdto);

};

















