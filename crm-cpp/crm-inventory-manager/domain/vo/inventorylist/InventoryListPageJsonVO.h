/*
 Copyright ruodi. All rights reserved.

 @Author: ruodi
 @Date: 2023/10/20
 @FileName:InventoryListPageJsonVO
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

#ifndef INVENTORYLISTOPAGEJSONVO_H__
#define INVENTORYLISTOPAGEJSONVO_H__
#include "../../GlobalInclude.h"
#include "../../dto/inventorylist/InventorylistDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *InventoryList
 */
class InventoryListJsonVO : public JsonVO<InventoryListDTO::Wrapper>
{
	DTO_INIT(InventoryListJsonVO, JsonVO<InventoryListDTO::Wrapper>);

};

/**
 * InventoryListPage
 */
class InventoryListPageJsonVO : public JsonVO<InventoryListPageDTO::Wrapper>
{
	DTO_INIT(InventoryListPageJsonVO, JsonVO<InventoryListPageDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)
#endif // INVENTORYLISTOPAGEJSONVO_H__
