#pragma once
#ifndef _DICT_H_
#define _DICT_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 字典管理-数据对象
 */
class DictDTO : public oatpp::DTO
{
	DTO_INIT(DictDTO, DTO);

	//定义字典编号 用于删除 
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("dictmanage.field.dictid"));
	//定义字典名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("dictmanage.field.dictname"));
	//定义字典标签名称
	API_DTO_FIELD_DEFAULT(String, typetag, ZH_WORDS_GETTER("dictmanage.field.dicttypetag"));
	//定义排序
	API_DTO_FIELD_DEFAULT(Int32, sort, ZH_WORDS_GETTER("dictmanage.field.dictsort"));
	//定义是否启用
	API_DTO_FIELD_DEFAULT(Int32, visible, ZH_WORDS_GETTER("dictmanage.field.dictvis"));
};

/**
 * 分页传输对象
 */
class DictPageDTO : public PageDTO<DictDTO::Wrapper>
{
	DTO_INIT(DictPageDTO, PageDTO<DictDTO::Wrapper>);
};
/**
 * 下拉列表传输对象
 */
class DictTypeListDTO : public oatpp::DTO
{
	DTO_INIT(DictTypeListDTO, DTO)
	//定义字典分类编号 
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("dictmanage.field.dictid"));
	//定义字典分类
	API_DTO_FIELD_DEFAULT(String, tpyename, ZH_WORDS_GETTER("dictmanage.field.dicttpye"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DICT_H_
