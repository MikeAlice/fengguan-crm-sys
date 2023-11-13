#pragma once
/*
* �����ˣ��Ͼ�
*/
#include "stdafx.h"
#ifndef _EXPORTCUSTOMER_QUERY_
#define _EXPORTCUSTOMER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����ͻ���ѯ����
 */
class ExportCustomerQuery : public oatpp::DTO
{
	DTO_INIT(ExportCustomerQuery, DTO);

	// �ͻ�ID�б�
	API_DTO_FIELD_DEFAULT(List<Int32>, customer_id_list, ZH_WORDS_GETTER("customer.field.customer_id_list"));

	// ������Ա
	API_DTO_FIELD_DEFAULT(UInt32, create_user_id, ZH_WORDS_GETTER("customer.field.create_user_id"));

	// ������Ա
	API_DTO_FIELD_DEFAULT(UInt32, owner_user_id, ZH_WORDS_GETTER("customer.field.owner_user_id"));

};


#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTCUSTOMER_QUERY_
