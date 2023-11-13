//2023年10月19日
//作者：狗皮电耗子
//内容：客户基础信息表DTO

#pragma once
#ifndef _CUSTORMER_H_
#define _CUSTORMER_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CustormerDTO : public oatpp::DTO
{
	DTO_INIT(CustormerDTO, DTO);
	//客户代表
	API_DTO_FIELD_DEFAULT(String, linkman, ZH_WORDS_GETTER("mycustormer.info.linkman"));
	// 客户来源
	API_DTO_FIELD_DEFAULT(String, source, ZH_WORDS_GETTER("mycustormer.info.source"));
	// 客户等级
	API_DTO_FIELD_DEFAULT(String, grade, ZH_WORDS_GETTER("mycustormer.info.grade"));
	// 客户行业
	API_DTO_FIELD_DEFAULT(String, industry, ZH_WORDS_GETTER("mycustormer.info.indusry"));
	// 联系手机
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("mycustormer.info.mobile"));
	// 联系电话
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("mycustormer.info.tel"));
	// 联系地址
	API_DTO_FIELD_DEFAULT(String, address, ZH_WORDS_GETTER("mycustormer.info.address"));
	// 客户介绍
	API_DTO_FIELD_DEFAULT(String, intro, ZH_WORDS_GETTER("mycustormer.info.intro"));
	// 客户需求
	API_DTO_FIELD_DEFAULT(String, needs, ZH_WORDS_GETTER("mycustormer.info.needs"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_CUSTORMER_H_
