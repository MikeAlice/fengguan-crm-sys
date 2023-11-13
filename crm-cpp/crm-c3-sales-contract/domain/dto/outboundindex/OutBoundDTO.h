#pragma once
#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class OutBoundDTO : public oatpp::DTO
{
	DTO_INIT(OutBoundDTO, DTO);

	//出库单号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.id");
	}

	//仓库名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.name");
	}

	//创建人or创建时间
	DTO_FIELD(String, starttime);
	DTO_FIELD_INFO(starttime) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.starttime");
	}

	//状态
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.status");
	}

	//出库数量
	DTO_FIELD(String, quantity);
	DTO_FIELD_INFO(quantity) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.quantity");
	}

	//出库人员or时间
	DTO_FIELD(String,stoptime );
	DTO_FIELD_INFO(stoptime) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.stoptime");
	}

	//出库类型
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.type");
	}

	//出库备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.remark");
	}
};

/**
 * 示例分页传输对象
 */
class OutBoundPageDTO : public PageDTO<OutBoundDTO::Wrapper>
{
	DTO_INIT(OutBoundPageDTO, PageDTO<OutBoundDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_