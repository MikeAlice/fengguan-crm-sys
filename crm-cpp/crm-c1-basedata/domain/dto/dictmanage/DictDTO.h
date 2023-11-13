#pragma once
#ifndef _DICT_H_
#define _DICT_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ֵ����-���ݶ���
 */
class DictDTO : public oatpp::DTO
{
	DTO_INIT(DictDTO, DTO);

	//�����ֵ��� ����ɾ�� 
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("dictmanage.field.dictid"));
	//�����ֵ�����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("dictmanage.field.dictname"));
	//�����ֵ��ǩ����
	API_DTO_FIELD_DEFAULT(String, typetag, ZH_WORDS_GETTER("dictmanage.field.dicttypetag"));
	//��������
	API_DTO_FIELD_DEFAULT(Int32, sort, ZH_WORDS_GETTER("dictmanage.field.dictsort"));
	//�����Ƿ�����
	API_DTO_FIELD_DEFAULT(Int32, visible, ZH_WORDS_GETTER("dictmanage.field.dictvis"));
};

/**
 * ��ҳ�������
 */
class DictPageDTO : public PageDTO<DictDTO::Wrapper>
{
	DTO_INIT(DictPageDTO, PageDTO<DictDTO::Wrapper>);
};
/**
 * �����б������
 */
class DictTypeListDTO : public oatpp::DTO
{
	DTO_INIT(DictTypeListDTO, DTO)
	//�����ֵ������ 
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("dictmanage.field.dictid"));
	//�����ֵ����
	API_DTO_FIELD_DEFAULT(String, tpyename, ZH_WORDS_GETTER("dictmanage.field.dicttpye"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DICT_H_
