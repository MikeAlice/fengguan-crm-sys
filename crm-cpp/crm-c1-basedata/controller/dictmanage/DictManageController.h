#ifndef _DUCTMANAGE_CONTROLLER_
#define _DUCTMANAGE_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/dictmanage/DictDTO.h"
#include "domain/query/dictmanage/DictQuery.h"
#include "domain/vo/dictmanage/DictVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �ֵ���������
 */
class DictManageController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(DictManageController);
public:// ����ӿ�
	//���
	//���� ����ֵ� �ӿ����� ʹ��ZH_WORDS_GETTER(xx.yy)�������� ��zh-dict��������
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("dictmanage.add.newdict"), AddDictDTO, BooleanJsonVO::Wrapper);
	//���� ����ֵ� �ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "data-dictionary/dictmanage/add-dict", AddDictDTO, BODY_DTO(DictDTO::Wrapper, dto), execAddDict(dto, authObject->getPayload()));

	//�޸�
	//���� �޸��ֵ� �ӿ����� ʹ��ZH_WORDS_GETTER(xx.yy)�������� ��zh-dict��������
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("dictmanage.modify.modifydict"), ModifyDictDTO, BooleanJsonVO::Wrapper);
	//���� �޸��ֵ� �ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "data-dictionary/dictmanage/modify-dict", ModifyDictDTO, BODY_DTO(DictDTO::Wrapper, dto), execModifyDict(dto, authObject->getPayload()));

	//ɾ��
	//���� ɾ���ֵ� �ӿ����� ʹ��ZH_WORDS_GETTER(xx.yy)�������� ��zh-dict��������
	ENDPOINT_INFO(DeleteDict) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("dictmanage.delete.deletedict"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("dictmanage.field.id"), 1, true);
	}
	//���� ɾ���ֵ� �ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "data-dictionary/dictmanage/delete-dict/{id}",DeleteDict, PATH(UInt64, id), execDeleteDict(id));

	//��ѯ
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(QueryDict) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("dictmanage.get.getdict"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DictPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("dictmanage.field.name"), "kun", false);//�ֵ�����
		API_DEF_ADD_QUERY_PARAMS(String, "typetag", ZH_WORDS_GETTER("dictmanage.field.typetag"), "2.5years student", false);//�ֵ��������
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "data-dictionary/dictmanage/get-dict", QueryDict, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, DictQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryDict(userQuery, authObject->getPayload()));
	}
	//��ȡ��ҳ�б�
	//����ӿ�����
	ENDPOINT_INFO(PageDict) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("dictmanage.get.getpage"));
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DictTypePageJsonVO);
	}
	// ����ӿڴ���
	ENDPOINT(API_M_GET, "data-dictionary/dictmanage/get-pagedict", PageDict) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execPageDict());
	}

private:// ����ӿ�ִ�к���
	//����ֵ�ִ�к���
	Uint64JsonVO::Wrapper execAddDict(const DictDTO::Wrapper& dto,const PayloadDTO& payload);
	//�޸��ֵ�ִ�к���
	Uint64JsonVO::Wrapper execModifyDict(const DictDTO::Wrapper& dto, const PayloadDTO& payload);
	//ɾ���ֵ�ִ�к���
	Uint64JsonVO::Wrapper execDeleteDict(const UInt64& id);
	//��ѯ�ֵ�ִ�к���
	DictPageJsonVO::Wrapper execQueryDict(const DictQuery::Wrapper& query, const PayloadDTO& payload);
	//��ȡ��ҳ�б�ִ�к���
	DictTypePageJsonVO::Wrapper execPageDict();
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DUCTMANAGE_CONTwROLLER_