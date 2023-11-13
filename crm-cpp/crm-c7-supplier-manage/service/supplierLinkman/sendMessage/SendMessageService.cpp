#include "stdafx.h"
#include "SendMessageService.h"
#include "dao/supplierLinkman/sendMessage/SendMessageDAO.h"



std::list<SendMessageDO> SendMessageService::getNameAndPhone(const SendMessageDTO::Wrapper& dto)
{

		SendMessageDAO dao;
		return dao.getNameAndPhone(dto);
}