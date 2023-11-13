/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/26 9:58:26

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
#include <iostream>
#include "UseFastDfs.h"

std::string UseFastdfs::uploadFile(const std::string& file)
{
	// 开始上传文件
	std::string fieldName = client->uploadFile(file);
	std::cout << "upload success, field name: " << fieldName << std::endl;
	// 构建下载路径
	std::string downloadUrl = urlPrefix + fieldName;
	return downloadUrl;
}

std::string UseFastdfs::downloadFile(const std::string& downloadUrl, std::string savePath /*= "./public/fastdfs"*/)
{
	// 开始下载文件到保存路径
	std::string fullPath = client->downloadFile(downloadUrl, &savePath);
	std::cout << "downloaded " << downloadUrl << " and save to " << savePath << std::endl;
	return fullPath;
}

bool UseFastdfs::deleteFile(const std::string& fieldName)
{
	if (client->deleteFile(fieldName))
	{
		std::cout << "delete " << fieldName << " success" << std::endl;
		return true;
	}
	else
	{
		std::cerr << "delete " << fieldName << " failed" << std::endl;
		return false;
	}
}
