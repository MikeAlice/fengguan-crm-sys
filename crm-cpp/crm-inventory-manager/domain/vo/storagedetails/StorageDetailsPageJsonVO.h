/*
 Copyright yunyin. All rights reserved.
 
 @Author: yunyin
 @Date: 2023/10/20
 @FileName:StorageDetailsPageJsonVO
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

#ifndef STORAGEDETAILSPAGEJSONVO_H__
#define STORAGEDETAILSPAGEJSONVO_H__
#include "../../GlobalInclude.h"
#include "../../dto/storagedetails/StorageDetailsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * StorageDetailsPageJsonVO
 */
class StorageDetailsPageJsonVO : public JsonVO<StorageDetailsPageDTO::Wrapper>
{
	DTO_INIT(StorageDetailsPageJsonVO, JsonVO<StorageDetailsPageDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)
#endif // STORAGEDETAILSPAGEJSONVO_H__