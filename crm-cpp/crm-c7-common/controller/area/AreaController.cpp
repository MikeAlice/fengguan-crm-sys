/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2023/11/01 16:19:50

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
#include "AreaController.h"
#include "../ApiDeclarativeServicesHelper.h"

PullListArrayJsonVO::Wrapper AreaController::execQueryArea(const PayloadDTO& payload)
{
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, AreaApiClient, "area-api");
	// ���ؽ��
	return ac->area(token)->readBodyToDto<PullListArrayJsonVO::Wrapper>(om);
}