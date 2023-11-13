/*
 @Author: linglan
 @Date: 2022/10/25 10:58:42

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
#include "RemoveReceiptRecordController.h"
#include "service/remove_receipt_record/ReceiptRecordService.h"

//删除收票记录（可批量） 负责人：灵岚
ReceiptRecordJsonVO::Wrapper RemoveReceiptRecordController::execRemoveReceiptRecord(const ReceiptRecordDTO::Wrapper& recordIds)
{
	// 定义返回数据对象
	auto jvo = ReceiptRecordJsonVO::createShared();
	auto& successResultList = *recordIds->record_id;
	auto failResult = ReceiptRecordDTO::Wrapper::createShared();
	auto& failResultList = *failResult->record_id;

	int flag = 1;//flag=1表示全部成功，flag=2表示部分成功，flag=3表示全部失败
	bool flag_check = false;//检查是否有id成功删除，用于判断是全部删除成功，还是部分成功

	// 参数校验
	if (successResultList.empty())
	{
		//jvo->init(std::list<UInt64>({1}), RS_PARAMS_INVALID);
		jvo->setStatus(ResultStatus(u8"参数为空，请传入参数", 9999));
		return jvo;
	}
	// 定义一个Service
	ReceiptRecordService service;

	// 执行数据删除
	for (auto& id : successResultList) {
		//若不成功，将id放入failResultList，并将flag置为false
		if (!service.removeData(id.getValue(0))) {
			//UInt64 newId = id.getValue(0);
			failResultList.push_back(UInt64(id.getValue(0)));

			if (flag_check){
				flag = 2;//部分执行成功
			}else{
				flag = 3;//全部执行失败
			}

		}else{
			flag_check = true;
			//对例外情况进行处理
			if (flag == 3)
			{
				flag = 2;//部分执行成功
			}
		}
	}
	
	//设置结果返回对象
	if (flag == 1)
	{
		//全部执行成功
		//若全部成功，返回所有执行成功的id List
		jvo->setStatus(ResultStatus(u8"操作成功：全部id删除成功，将返回所有成功的id"));
		jvo->data = recordIds;
	}
	else if(flag == 2)
	{
		//部分执行成功
		//若存在失败的id，返回所有执行失败的id List
		jvo->setStatus(ResultStatus(u8"操作失败：部分id删除成功，将返回所有操作失败的id", 9999));
		jvo->data = failResult;
	}
	else if (flag == 3)
	{
		//全部执行失败
		//若全部失败，返回所有执行失败的id List
		jvo->setStatus(ResultStatus(u8"操作失败：全部id删除失败，将返回所有操作失败的id", 9999));
		jvo->data = failResult;
	}
	// 响应结果
	return jvo;
}
