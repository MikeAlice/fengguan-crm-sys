/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/27
 @FileName:StorageDetailsMapper
 @version:1.0
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
      https://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef STORAGEDETAILSMAPPER_H__
#define STORAGEDETAILSMAPPER_H__

#include "Mapper.h"
#include "domain/do/storagedetails/StorageDetailsDO.h"

class StorageDetailsMapper : public Mapper<StorageDetailsDO>
{
public:
	StorageDetailsDO mapper(ResultSet* resultSet) const override {
		StorageDetailsDO data;
		data.setGoodsId(resultSet->getInt(1));
		data.setSKUID(resultSet->getInt(2));
		data.setGoodsName(resultSet->getString(3));
		data.setSKUName(resultSet->getString(4));
		data.setNumber(resultSet->getInt(5));
		data.setCateGoryName(resultSet->getString(6));
		data.setStoreName(resultSet->getString(7));
		data.setIntoIntro(resultSet->getString(8));
		data.setIntoTime(resultSet->getString(9));
		data.setRemarks(resultSet->getString(10));
		data.setSupplierName(resultSet->getString(11));
		return data;
	}
};

#endif // STORAGEDETAILSMAPPER_H__