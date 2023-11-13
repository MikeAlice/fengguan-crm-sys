/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2023/10/26 13:42:56

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
#include "stdafx.h"
#include "SendEmailService.h"
#include "dao/supplierLinkman/sendEmail/SendEmailDAO.h"
#include "domain/dto/supplierLinkman/SendEmailDTO.h"

/**
 * �����ˣ�����
 * SendEmail��Service��
 */
oatpp::List<SendEmailSendDTO::Wrapper> SendEmailService::listAll(const SendEmailRecvDTO::Wrapper& recvDTO)
{
	// �������ض���
	auto result = SendEmailListSendDTO::createShared();

	// ���µ���DAO�㣬�����ռ��˵�Id
	SendEmailDAO dao;
	std::list<SupplierLinkmanDO> listRecvDO = dao.selectAll(recvDTO);

	// ��DOת��ΪDTO
	for (SupplierLinkmanDO recvDO : listRecvDO)
	{
		auto DTO = SendEmailSendDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(DTO, recvDO, recv_name, Name, mail, Email);

		// ��װ����
		DTO->mess_type = recvDTO->type;
		DTO->mess = recvDTO->mess;
		DTO->contrast_name = "";
		result->addItem(DTO);
	}
	return result->rows;
}
