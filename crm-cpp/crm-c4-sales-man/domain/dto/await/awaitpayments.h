#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/10/19 20:19:10

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
#ifndef _FINDAWAPAYINFODTO_H_
#define _FINDAWAPAYINFODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *   查询待回款合同
 */
class FINDAWAPAYDTO : public oatpp::DTO
{
	DTO_INIT(FINDAWAPAYDTO, DTO);

	// 待回款合同的id
	DTO_FIELD(String, awaitpayments_id);
	DTO_FIELD_INFO(awaitpayments_id) {
		info->description = ZH_WORDS_GETTER("awaiting_.field.awaitpayments_id");
	}

	// 待回款合同的名称
	DTO_FIELD(String, awaitpayments_name);
	DTO_FIELD_INFO(awaitpayments_name) {
		info->description = ZH_WORDS_GETTER("awaiting_.field.awaitpayments_name");
	}

	// 待回款合同的总金额
	DTO_FIELD(UInt64, awaitpayments_all_money);
	DTO_FIELD_INFO(awaitpayments_all_money) {
		info->description = ZH_WORDS_GETTER("awaiting_.field.awaitpayments_all_money");
	}

	// 待回款合同的回款 rmoney = returned money
	DTO_FIELD(UInt64, awaitpayments_rmoney);
	DTO_FIELD_INFO(awaitpayments_rmoney) {
		info->description = ZH_WORDS_GETTER("awaiting_.field.awaitpayments_rmoney");
	}
	// 待回款合同的欠款 amoney = awating money
	DTO_FIELD(UInt64, awaitpayments_amoney);
	DTO_FIELD_INFO(awaitpayments_amoney) {
		info->description = ZH_WORDS_GETTER("awaiting_.field.awaitpayments_amoney");
	}

	// 待回款合同的创建时间
	DTO_FIELD(String, awaitpayments_time);
	DTO_FIELD_INFO(awaitpayments_time) {
		info->description = ZH_WORDS_GETTER("awaiting_.field.awaitpayments_time");
	}
	
};
class FINDAWAPAYPageDTO : public PageDTO<FINDAWAPAYDTO::Wrapper>
{
	DTO_INIT(FINDAWAPAYPageDTO, PageDTO<FINDAWAPAYDTO::Wrapper>);
};
class FINDAWACUSTDTO : public oatpp::DTO
{
	DTO_INIT(FINDAWACUSTDTO, DTO);

	// 待跟进客户的类型
	DTO_FIELD(String, cust_type);
	DTO_FIELD_INFO(cust_type) {
		info->description = ZH_WORDS_GETTER("awaiting_.field.cust_type");
	}

	// 待跟进客户的名称
	DTO_FIELD(String, cust_name);
	DTO_FIELD_INFO(cust_name) {
		info->description = ZH_WORDS_GETTER("awaiting_.field.cust_name");
	}
	// 待回款合同的创建时间
	DTO_FIELD(String, cust_time);
	DTO_FIELD_INFO(cust_time) {
		info->description = ZH_WORDS_GETTER("awaiting_.field.cust_time");
	}

};
class FINDAWACUSTDTOPageDTO : public PageDTO<FINDAWACUSTDTO::Wrapper>
{
	DTO_INIT(FINDAWACUSTDTOPageDTO, PageDTO<FINDAWACUSTDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_MODIFYOWNERINFODTO_H