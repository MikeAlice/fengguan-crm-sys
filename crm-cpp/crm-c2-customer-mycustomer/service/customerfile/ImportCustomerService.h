#pragma once
/*
* 负责人：老菌
*/
#ifndef _IMPORTCUSTOMER_SERVICE_
#define _IMPORTCUSTOMER_SERVICE_


#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/customerfile/ImportResultDTO.h"
#include "ApiHelper.h"

/**
 * 导入文件服务实现
 */
class ImportCustomerService
{
public:
	/*
	* 负责人：老菌
	* 功能：接收上传的客户信息文件
	* @param request  客户上传文件请求
	* @return String	成功 返回上传文件保存在业务服务器上的路径
	*					失败 返回空字符串
	*/
	String uploadImportFile(std::shared_ptr<oatpp::web::protocol::http::incoming::Request>& request);

	/*
	* 负责人：老菌
	* 功能：解析上传文件中的客户信息并持久化到数据库
	* @param fileName  导入文件在本地磁盘的路径
	* @return ImportResultDTO  返回成功与失败信息
	*/
	ImportResultDTO::Wrapper importCustomer(String& fileName);

};

#endif // !_EXPORTCUSTOMER_SERVICE_