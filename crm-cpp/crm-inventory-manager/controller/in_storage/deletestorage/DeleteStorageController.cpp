#include "stdafx.h"
#include "DeleteStorageController.h"

Int64JsonVO::Wrapper DeleteStorageController::execDeleteStorage(const List<DeleteByIDStorageDTO::Wrapper>& dto, const PayloadDTO& payload)
{
    auto tmp = Int64JsonVO::createShared();
    for (auto it = dto->begin(); it != dto->end(); it++) {
        if ((*it)->id <= 0) {
            tmp->fail(-1);
            return tmp;
        }
    }
    int num = 0;
    InStorageService service;
    for (auto it = dto->begin(); it != dto->end(); it++) {
        if (service.removeData((*it)->id))
            num++;
    }
    if (num == 0)
        tmp->fail(-1);
    else
        tmp->success(num);
    return tmp;
}
