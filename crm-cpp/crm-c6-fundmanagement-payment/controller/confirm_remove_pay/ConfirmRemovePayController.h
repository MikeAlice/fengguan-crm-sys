#pragma once
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/confirm_remove_pay/ConfirmRemovePayDTO.h"
#include "oatpp/core/Types.hpp"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���������������ƻ�ɾ���ӿں�ȷ�ϸ���ӿ�
 * �����ˣ�rui
 */
class ConfirmRemovePayController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ConfirmRemovePayController);
	// 3 ����ӿ�
public:
	/*
	* ɾ���ӿڣ�
	*�����ˣ�rui
	*/
	// ����ɾ���ӿ�����
	ENDPOINT_INFO(removeConfirmpay) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("confirmpay.controller.delete.summary"), Uint64JsonVO::Wrapper);
	}
	// ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/payment/pay-plan/del/{plan_ids}", removeConfirmpay, BODY_DTO(oatpp::List<UInt64>, plan_ids), execRemoveConfirmpay(plan_ids));


	/*
	* ȷ�ϸ���ӿ�
	* �����ˣ�rui
	*/
	// �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("confirmpay.controller.put.summary"), modifyConfirmpay, Uint64JsonVO::Wrapper);
	// �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/payment/pay-plan/confirm/{plan_id}", modifyConfirmpay, PATH(UInt64, plan_id), execModifyConfirmpay(plan_id));


private:
	Uint64JsonVO::Wrapper execRemoveConfirmpay(oatpp::List<UInt64> plan_ids);
	Uint64JsonVO::Wrapper execModifyConfirmpay(const UInt64& id);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
//