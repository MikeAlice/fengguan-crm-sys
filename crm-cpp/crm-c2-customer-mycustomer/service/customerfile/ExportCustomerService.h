#pragma once
/*
* 负责人：老菌
*/
#ifndef _EXPORTCUSTOMER_SERVICE_
#define _EXPORTCUSTOMER_SERVICE_
#include <list>
#include <time.h>
#include "domain/query/customerfile/ExportCustomerQuery.h"
#include "domain/dto/customerfile/ExportCustomerDTO.h"
#include "domain/do/customer/CustomerDO.h"
#include "dao/customerfile/ExportCustomerDAO.h"
#include "domain/vo/BaseJsonVO.h"


/**
 * 导出文件服务实现
 */
class ExportCustomerService
{
public:
	/*
	* 负责人：老菌
	* 功能：根据创建人员和归属人员查询客户信息
	* @param const ExportCustomerQuery::Wrapper&  导出客户查询条件
	* @return list<ListCustomerDTO::Wrapper>  导出客户信息的DTO集合
	*/
	list<ExportCustomerDTO::Wrapper> listAll(const ExportCustomerQuery::Wrapper& query);

	/*
	* 负责人：老菌
	* 功能：将客户信息保存为Excel文件上传到FastDFS文件服务器
	* @param list<ListCustomerDTO::Wrapper>&  导出客户信息的DTO集合
	* @return string  上传文件的路径，为空则表示上传失败
	*/
	String uploadExportFile(list<ExportCustomerDTO::Wrapper>& dto);
	
};

#endif // !_EXPORTCUSTOMER_SERVICE_