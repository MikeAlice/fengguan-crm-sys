#include "stdafx.h"
#include <iostream>
#include "SendMessageController.h"
#include "domain/dto/supplierLinkman/SendMessageDeclDTO.h"
#include "service/supplierLinkman/sendMessage/SendMessageService.h"
#include "controller/ApiDeclarativeServicesHelper.h"
#include <CharsetConvertHepler.h>
Uint64JsonVO::Wrapper SendMessageController::execSendMessage(const SendMessageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();
	try {
		//参数检查
		if (dto->supplier_list->empty() || dto->type==0) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		std::cout << dto->type << std::endl;

		//组装dto
		SendMessageService service;
		list<SendMessageDO> result = service.getNameAndPhone(dto);
		auto items = SendMessageDeclListDTO::createShared();
		//oatpp::List<SendMessageDeclDTO> items;
		for (auto data :result) {
			auto tempDTO = SendMessageDeclDTO::createShared();
			tempDTO->mess_type = dto->type;
			tempDTO->recv_name = data.getName();
			std::cout << CharsetConvertHepler::utf8ToAnsi(data.getName()) << std::endl;

			tempDTO->phone = data.getMobile();
			items->addItem(tempDTO);
			//items->push_back(tempDTO);
		}
		for (auto d : *(items->rows)) {
		}

		//调用声明式服务
		API_CLIENT_CREATE(ac, om, SendMessageApiClient, "msg-server-api");
		// 构建凭证
		std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();


		//  jvo->init(-1, RS_CONTENT_TYPE_ERR);
		return ac->smss(token, items->rows)->readBodyToDto<Uint64JsonVO::Wrapper>(om);

	}
	catch (std::exception e) {
		cout << "不存在某些供应商联系人" << endl;
		jvo->init(UInt64(-2), RS_PARAMS_INVALID);
		return jvo;
	}

}
