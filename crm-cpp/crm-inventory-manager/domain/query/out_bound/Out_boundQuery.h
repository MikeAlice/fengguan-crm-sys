#ifndef OUT_BOUNDQUERY_H__
#define OUT_BOUNDQUERY_H__
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * out_bound��ѯ����
 */
class Out_boundQuery : public PageQuery
{
	DTO_INIT(Out_boundQuery, PageQuery);
	// ����
	DTO_FIELD(Int32, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("out_bound.field.number");
	}
	// ����ʱ��
	DTO_FIELD(String, out_time);
	DTO_FIELD_INFO(out_time) {
		info->description = ZH_WORDS_GETTER("out_bound.field.out_time");
	}
	// ��ע
	DTO_FIELD(String, remarks);
	DTO_FIELD_INFO(remarks) {
		info->description = ZH_WORDS_GETTER("out_bound.field.remarks");
	}
	// ��Ӧ������
	DTO_FIELD(String, supplier_name);
	DTO_FIELD_INFO(supplier_name) {
		info->description = ZH_WORDS_GETTER("out_bound.field.supplier_name");
	}
	//״̬
	DTO_FIELD(Int32, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("out_bound.field.status");
	}
	//��Ӧ���ⵥ��
	DTO_FIELD(Int32, out_bound_id);
	DTO_FIELD_INFO(out_bound_id) {
		info->description = ZH_WORDS_GETTER("out_bound.field.out_bound_id");
	}
	//������Ա
	DTO_FIELD(String, out_bound_person);
	DTO_FIELD_INFO(out_bound_person) {
		info->description = ZH_WORDS_GETTER("out_bound.field.out_type");
	}
	//��������
	DTO_FIELD(String, out_type);
	DTO_FIELD_INFO(out_type) {
		info->description = ZH_WORDS_GETTER("out_bound.field.out_type");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif //OUT_BOUNDQUERY_H__
