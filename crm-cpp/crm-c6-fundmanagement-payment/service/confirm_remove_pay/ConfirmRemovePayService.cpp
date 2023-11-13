/*


 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "stdafx.h"
#include "ConfirmRemovePayService.h"
#include "dao/confirm_remove_pay/ConfirmRemovePayDAO.h"
#include "domain/dto/confirm_remove_pay/ConfirmRemovePayDTO.h"



bool ConfirmRemovePayService::updateData(uint64_t id)
{
	ConfirmRemovePayDAO dao;
	return dao.update(id) == 1;
}

bool ConfirmRemovePayService::removeData(uint64_t id)
{
	ConfirmRemovePayDAO dao;
	return dao.deleteById(id) == 1;
}
