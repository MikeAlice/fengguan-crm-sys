#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/28 0:20:54

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
#ifndef _INSERTSUPLINKMANDAO_H_
#define _INSERTSUPLINKMANDAO_H_

#include "BaseDAO.h"
#include "domain/do/supplierLinkman/SupplierLinkmanDO.h"
#include "domain/dto/supplierLinkman/SupplierLinkmanDTO.h"
#include "domain/dto/PayloadDTO.h"

/**
 * ������Ӧ����ϵ��DAO���ݳ־ò�
 * ������: Andrew
 */
class InsertSupLinkmanDAO : public BaseDAO
{
public:
	/**
	 * ������Ӧ����ϵ��
	 * @param const SupplierLinkmanDO&: ���ڻ�ȡ������������
	 * @return uint64_t: ����������Ӧ����ϵ��Ψһ��ʶID
	 */
	uint64_t insert(const SupplierLinkmanDO& data);
	/**
	 * ������Ӧ����ϵ��
	 * @param const AddSupplierLinkmanDTO&: ���ڻ�ȡ������������
	 * @param const PayloadDTO&: ��ȡ�û������Ϣ
	 * @return uint64_t: ����������Ӧ����ϵ��Ψһ��ʶID
	 */
	uint64_t insert(const AddSupplierLinkmanDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif // !_INSERTSUPLINKMANDAO_H_