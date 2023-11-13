/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/27
 @FileName:StorageDetailsDO
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
#ifndef STORAGEDETAILSDO_H__
#define STORAGEDETAILSDO_H__
#include "../DoInclude.h"

class StorageDetailsDO
{
    CC_SYNTHESIZE(int,goods_id,GoodsId);
    CC_SYNTHESIZE(int, sku_id, SKUID);
    CC_SYNTHESIZE(string, goods_name, GoodsName);
    CC_SYNTHESIZE(string, sku_name, SKUName);
    CC_SYNTHESIZE(int, number, Number);
    CC_SYNTHESIZE(string, category_name, CateGoryName);
    CC_SYNTHESIZE(string, store_name, StoreName);
    CC_SYNTHESIZE(string, into_intro, IntoIntro);
    CC_SYNTHESIZE(string, into_time, IntoTime);
    CC_SYNTHESIZE(string, remarks, Remarks);
    CC_SYNTHESIZE(string, supplier_name, SupplierName);
public:
    StorageDetailsDO() :
        goods_id(0),
        sku_id(0),
        goods_name({}),
        sku_name({}),
        number(0),
        category_name({}),
        store_name({}),
        into_intro({}),
        into_time({}),
        remarks({}),
        supplier_name({})
    {}
};

#endif // STORAGEDETAILSDO_H__