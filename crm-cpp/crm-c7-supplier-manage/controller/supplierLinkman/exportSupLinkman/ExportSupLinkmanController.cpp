/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/20 23:50:53

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
#include "ExportSupLinkmanController.h"
#include "service/supplierLinkman/exportSupLinkman/ExportSupLinkmanService.h"

StringJsonVO::Wrapper ExportSupLinkmanController::execExportSupLinkman(const ExportSupLinkmanQuery::Wrapper& query)
{
	auto downloadUrl = StringJsonVO::createShared();
	
	ExportSupLinkmanService service;
	auto url = service.exportSupLinkman(query);

	if (url != "")
		downloadUrl->success(url);
	else
		downloadUrl->fail("");
	return downloadUrl;
}
