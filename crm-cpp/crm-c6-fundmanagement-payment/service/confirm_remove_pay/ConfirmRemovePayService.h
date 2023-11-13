#pragma once
/*


 Copyright Zero One Star. All rights reserved.

 @Author: rui
 @Date: 2022/10/28 

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
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include "domain/dto/confirm_remove_pay/ConfirmRemovePayDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ConfirmRemovePayService
{
public:
	// �޸�����
	bool updateData(uint64_t id);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

