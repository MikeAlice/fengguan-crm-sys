#ifndef OUT_BOUNDDTO_H__
#define OUT_BOUNDDTO_H__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//Out_bound�������
class Out_boundDTO : public oatpp::DTO
{
	DTO_INIT(Out_boundDTO, DTO);

	// ��ƷID
	DTO_FIELD(UInt64, goods_id);
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("out_bound.field.goods_id");
	}
	// SKU ID
	DTO_FIELD(UInt64, sku_id);
	DTO_FIELD_INFO(sku_id) {
		info->description = ZH_WORDS_GETTER("out_bound.field.sku_id");
	}
	// ��Ʒ��
	DTO_FIELD(String, goods_name);
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("out_bound.field.goods_name");
	}
	// SKU��
	DTO_FIELD(String, sku_name);
	DTO_FIELD_INFO(sku_name) {
		info->description = ZH_WORDS_GETTER("out_bound.field.sku_name");
	}
	// ����
	DTO_FIELD(Int32, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("out_bound.field.number");
	}
	// ��Ʒ����
	DTO_FIELD(String, category_name);
	DTO_FIELD_INFO(category_name) {
		info->description = ZH_WORDS_GETTER("out_bound.field.category_name");
	}
	// �ֿ�����
	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("out_bound.field.store_name");
	}
	// ��Ӧ���ⵥ
	DTO_FIELD(Int32, out_bound_order);
	DTO_FIELD_INFO(out_bound_order) {
		info->description = ZH_WORDS_GETTER("out_bound.field.out_bound_order");
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

	//������
	DTO_FIELD(Int16, create_user_id);
	DTO_FIELD_INFO(create_user_id) {
		info->description = ZH_WORDS_GETTER("out_bound.field.create_user_id");
	}

	//����ʱ��
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("out_bound.field.create_time");
	}

	//״̬
	DTO_FIELD(Int16, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("out_bound.field.status");
	}

	//��Ӧ���ⵥ��
	DTO_FIELD(Int16, out_bound_id);
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
		info->description = ZH_WORDS_GETTER("out_bound.field. ctype");
	}
};

//ConfOut_bound�������,����ȷ�ϳ���
class ConfOut_boundDTO : public oatpp::DTO
{
	DTO_INIT(ConfOut_boundDTO, DTO);
	// ���ⵥid
	DTO_FIELD(Int64, out_id);
	DTO_FIELD_INFO(out_id) {
		info->description = ZH_WORDS_GETTER("confout_bound.field.out_id");
	}

	//״̬
	DTO_FIELD(Int16, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("confout_bound.field.status");
	}

	// ����
	DTO_FIELD(Int32, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("confout_bound.field.number");
	}

	//������
	DTO_FIELD(Int16, out_user_id);
	DTO_FIELD_INFO(out_user_id) {
		info->description = ZH_WORDS_GETTER("confout_bound.field.out_user_id");
	}
};

//DelOut_bound�������,����ɾ�����ⵥ
class DelOut_boundDTO : public oatpp::DTO
{
	DTO_INIT(DelOut_boundDTO, DTO);
	// ���ⵥid
	DTO_FIELD(Int64, out_id);
	DTO_FIELD_INFO(out_id) {
		info->description = ZH_WORDS_GETTER("delout_bound.field.out_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // OUTD_STOCKDTO_H__