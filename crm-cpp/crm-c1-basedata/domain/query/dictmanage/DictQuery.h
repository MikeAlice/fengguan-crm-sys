#pragma once
#ifndef _DICTQUERY_H_
#define _DICTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询对象-字典管理查询对象
 */
class DictQuery : public PageQuery
{
	DTO_INIT(DictQuery, PageQuery);
	
	//定义字典名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("dictmanage.field.dictname"));
	//定义字典分类名称
	API_DTO_FIELD_DEFAULT(String, typetag, ZH_WORDS_GETTER("dictmanage.field.dicttypetag"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DICTQUERY_H_