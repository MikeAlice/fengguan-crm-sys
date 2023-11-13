#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Tapioca
 @Date: 2023/10/22 10:45:11

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
#ifndef _MODIFYLINKMAN_H_
#define _MODIFYLINKMAN_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/dto/supplierLinkman/LinkmanDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �޸Ĺ�Ӧ����ϵ��Controller
 * ������: tapioca
 */
class ModifyLinkmanController : public oatpp::web::server::api::ApiController
{
    // ����������������
    API_ACCESS_DECLARE(ModifyLinkmanController);
public: // ����ӿ�

    // �����޸���ϵ�˶˵�����
    ENDPOINT_INFO(modifyLinkman) {

        // ����ӿ�ͨ����Ϣ
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("supplier-linkman.modify-link-man.summary"), Uint64JsonVO::Wrapper);
    }

    // �����޸���ϵ�˶˵�
    ENDPOINT(API_M_PUT, SUP_LINKMAN(/modify-link-man), modifyLinkman, BODY_DTO(LinkmanDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		//��Ӧ���
		API_HANDLER_RESP_VO(execModifyLinkman(dto, authObject->getPayload()));
    }

private: // ����ӿ�ִ�к���
    // �޸��û���Ϣ
    Uint64JsonVO::Wrapper execModifyLinkman(const LinkmanDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MODIFYLINKMAN_H_