#pragma once
/*
* @Auther: Glasscats
* @Date: 2023/1025
*/

#ifndef _SENDINGFILEDTO_H
#define _SENDINGFILEDTO_H

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 附件信息传输数据对象
*/
class SendingFileDTO : public oatpp::DTO
{
	DTO_INIT(SendingFileDTO, DTO);
	// 附件src
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("File.field.file-url"), true, {});
	// 附件文字描述
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("File.field.file-alt"));
	// 附件链接地址
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("File.field.file-href"));
public:
	SendingFileDTO() {}
	SendingFileDTO(String url, String alt = "", String href = "")
	{
		this->url = url;
		this->alt = alt;
		this->href = href;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SENDINGFILEDTO_H
