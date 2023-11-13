#ifndef OUT_BOUNDCONTROLLER_H__
#define OUT_BOUNDCONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/out_bound/Out_boundDTO.h"
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * Out_bound������������������ϸ
 */
class Out_boundController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(Out_boundController);
	// 3 ����ӿ�
public:

	//ȷ�ϳ���ӿ�  �����ˣ�ǧ��
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/inventory-manager/confirm-outstock", confirmOutstock, BODY_DTO(ConfOut_boundDTO::Wrapper, dto), execConfirmOutstock(dto, authObject->getPayload()));
	ENDPOINT_INFO(confirmOutstock) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("out_bound.controller.put.summary"));	//Ŀ¼��.controller.������.summary
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "out_id", ZH_WORDS_GETTER("out_bound.field.out_id"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(Int32, "status", ZH_WORDS_GETTER("out_bound.field.status"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "number", ZH_WORDS_GETTER("out_bound.field.number"), 100, true);
		API_DEF_ADD_QUERY_PARAMS(Int64, "out_user_id", ZH_WORDS_GETTER("out_bound.field.out_user_id"), 123, true);
	}

	//ɾ�����ⵥ�ӿ�  �����ˣ�ǧ��
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/inventory-manager/delete-outstock", deleteOutstock, BODY_DTO(List<DelOut_boundDTO::Wrapper>, dto), execDeleteOutstock(dto, authObject->getPayload()));
	ENDPOINT_INFO(deleteOutstock) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("out_bound.controller.delete.summary"));	//Ŀ¼��.controller.������.summary
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ	
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "out_id", ZH_WORDS_GETTER("out_bound.field.out_id"), 123, true);
	}

private:
	// �ڴ���Ӷ���
	BooleanJsonVO::Wrapper execConfirmOutstock(const ConfOut_boundDTO::Wrapper& dto, const PayloadDTO& payload);//ȷ�ϳ��� �����ˣ�ǧ��
	BooleanJsonVO::Wrapper execDeleteOutstock(const List<DelOut_boundDTO::Wrapper>& dto, const PayloadDTO& payload);//ɾ�����ⵥ �����ˣ�ǧ��
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif //OUT_BOUNDCONTROLLER_H__
