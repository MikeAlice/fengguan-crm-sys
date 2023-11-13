/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/25 19:12:25

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "ExportSupLinkmanService.h"
#include "dao/supplierLinkman/exportSupLinkman/ExportSupLinkmanDAO.h"
#include "domain/do/supplierLinkman/SupplierLinkmanDO.h"
#include <vector>
#include "CharsetConvertHepler.h"
#include "uselib/excel/UseExcel.h"
#include "uselib/fastdfs/UseFastdfs.h"
#include "uselib/redis/UseRedis.h"

std::string ExportSupLinkmanService::exportSupLinkman(const ExportSupLinkmanQuery::Wrapper& query)
{
	// 传递DAO, 查询数据库
	ExportSupLinkmanDAO dao;
	// 获取表头
	std::list<std::string> fields = dao.selectField("sup_linkman");
	// 获取扩展字段缓存
	UseRedis ur;
	auto ext = ur.list_getter<std::string>(redis_title);
	std::list<std::string> extends;
	// 为空则查询数据库建立缓存
	if (ext.empty())
	{
		extends = dao.selectExtField();
		std::vector<std::string> vec(extends.begin(), extends.end());
		if (vec.size() && ur.list_setter<std::string>(redis_title, vec))
			std::cout << redis_title << " has being cached to Redis" << std::endl;
		else
			std::cout << "failed to cache " << redis_title << std::endl;
	}
	else
		extends = std::list<std::string>(ext.begin(), ext.end());
	// 获取导出数据
	std::list<SupplierLinkmanDO> res = dao.selectAll(query, extends);

	// 构建测试数据
	std::vector<std::vector<std::string>> data;
	// 构建表头
	std::vector<std::string> header;
	for (std::string item : fields) header.push_back(item);
	header.push_back(CharsetConvertHepler::ansiToUtf8("supplier_name"));
	data.push_back(header);
	// 填充数据
	for (SupplierLinkmanDO item : res)
	{
		std::vector<std::string> row;

		row.push_back(to_string(item.getLinkmanId()));
		row.push_back(to_string(item.getSupplierId()));
		row.push_back(item.getName());
		row.push_back(to_string(item.getGender()));
		row.push_back(item.getPosition());
		row.push_back(item.getTel());
		row.push_back(item.getMobile());
		row.push_back(item.getQicq());
		row.push_back(item.getEmail());
		row.push_back(item.getZipcode());
		row.push_back(item.getAddress());
		row.push_back(item.getIntro());
		row.push_back(item.getCreateTime());
		row.push_back(to_string(item.getCreateUserId()));
		auto ext = item.getExtFields();
		for (size_t idx = 14; header[idx] != "supplier_name"; idx++)
			row.push_back(ext[header[idx]]);
		row.push_back(item.getSupplierName());

		data.push_back(row);
	}

	// 调用Excel组件写入Excel文件, 获取文件保存路径
	UseExcel excel;
	std::string fileName = excel.saveToExcel(data);

	// 调用FastDFS组件上传文件到文件服务器, 获取下载链接
	UseFastdfs dfs;
	std::string downloadUrl = dfs.uploadFile(fileName);

	return downloadUrl;
}
