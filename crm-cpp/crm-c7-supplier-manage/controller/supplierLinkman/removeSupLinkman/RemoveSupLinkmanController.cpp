/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/23 22:26:29

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
#include "RemoveSupLinkmanController.h"
#include "service/supplierLinkman/removeSupLinkman/RemoveSupLinkmanService.h"

BooleanJsonVO::Wrapper RemoveSupLinkmanController::execRemoveSupLinkman(const RemoveSupLinkmanDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto res = BooleanJsonVO::createShared();
	// ����У��
	if (dto->rows->empty())
	{
		res->init({}, RS_SUCCESS);
		return res;
	}

	RemoveSupLinkmanService service;
	auto flag = service.removeSupLinkman(dto);

	if (flag)
		res->success(flag);
	else
		res->fail(flag);
	return res;
}
