#ifndef _BANKACCOUNT_SERVICE_
#define _BANKACCOUNT_SERVICE_
#include <list>
#include "domain/vo/bankaccount/BankAccountVO.h"
#include "domain/query/bankaccount/BankAccountQuery.h"
#include "domain/dto/bankaccount/BankAccountDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class BankAccountService
{
public:

	// ����ѯ�������ݵ���Ϊ�ļ�
	std::string exportData(const oatpp::List<BankAccountExportDTO::Wrapper>& dto);	// ��ȡ�����б�
	/*BankAccountDropListDTO::Wrapper getlistAll(const BankAccountListQuery::Wrapper& query);*/
	oatpp::List<BankAccountListDTO::Wrapper> getlistAll(const BankAccountListQuery::Wrapper& query);
	// ��ҳ��ѯ��������
	BankAccountPageDTO::Wrapper listAll(const BankAccountQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const BankAccountDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const BankAccountDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_BANKACCOUNT_SERVICE_
