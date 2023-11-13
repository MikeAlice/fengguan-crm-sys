#include "stdafx.h"
#include "ConfirmStorageController.h"

StringJsonVO::Wrapper ConfirmStorageController::execModifyConfirmStorage(const ModifyByIDStorageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto tmp = StringJsonVO::createShared();
	if (!dto->id || dto->id == 0) {
		tmp->fail(ZH_WORDS_GETTER("confirmstorage.field.wrong_params"));
		return tmp;
	}
	InStorageService result;
	dto->into_user_id = payload.getId();
	if (result.updateIsStorage(dto))
		tmp->success(ZH_WORDS_GETTER("confirmstorage.field.success"));
	else
		tmp->fail(ZH_WORDS_GETTER("confirmstorage.field.fail"));
	return tmp;
}
