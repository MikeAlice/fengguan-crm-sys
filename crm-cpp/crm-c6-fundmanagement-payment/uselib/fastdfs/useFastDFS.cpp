#include "stdafx.h"
#include "useFastDFS.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

string useFastDFS::useDfsWithNacos(string fileName)
{
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// 开始上传文件
	std::string fieldName = client.uploadFile(fileName);
	// 构建下载路径
	std::string downloadUrl = urlPrefix + fieldName;
	// 输出下载路径
	return downloadUrl;
}
