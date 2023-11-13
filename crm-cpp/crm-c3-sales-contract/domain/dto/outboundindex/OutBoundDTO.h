#pragma once
#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class OutBoundDTO : public oatpp::DTO
{
	DTO_INIT(OutBoundDTO, DTO);

	//���ⵥ��
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.id");
	}

	//�ֿ���
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.name");
	}

	//������or����ʱ��
	DTO_FIELD(String, starttime);
	DTO_FIELD_INFO(starttime) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.starttime");
	}

	//״̬
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.status");
	}

	//��������
	DTO_FIELD(String, quantity);
	DTO_FIELD_INFO(quantity) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.quantity");
	}

	//������Աorʱ��
	DTO_FIELD(String,stoptime );
	DTO_FIELD_INFO(stoptime) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.stoptime");
	}

	//��������
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.type");
	}

	//���ⱸע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("outboundindex.field.remark");
	}
};

/**
 * ʾ����ҳ�������
 */
class OutBoundPageDTO : public PageDTO<OutBoundDTO::Wrapper>
{
	DTO_INIT(OutBoundPageDTO, PageDTO<OutBoundDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_