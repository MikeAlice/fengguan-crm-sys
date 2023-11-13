#ifndef _BANKACCOUNT_DAO_
#define _BANKACCOUNT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/bankaccount/BankAccountDO.h"
#include "../../domain/query/bankaccount/BankAccountQuery.h"
#include"../../domain/dto/bankaccount/BankAccountDTO.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class BankAccountDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const BankAccountQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<BankAccountDO> selectWithPage(const BankAccountQuery::Wrapper& query);
	////��ȡ�����б�
	list<BankAccountListDO> selectWithList(const BankAccountListQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<BankAccountDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const BankAccountDO& iObj);
	// �޸�����
	int update(const BankAccountDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
	// ��������
	std::list<BankAccountDO> selectexport(const oatpp::List<BankAccountExportDTO::Wrapper>& dto);
	list<BankAccountListDO> selectPage();

};
#endif // !_BANKACCOUNT_DAO_
