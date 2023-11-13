#include "stdafx.h"
#include "UseFastDFS.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

string UseFastDFS::useDfsWithNacos(string fileName)
{
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// ��ʼ�ϴ��ļ�
	std::string fieldName = client.uploadFile(fileName);
	// ��������·��
	std::string downloadUrl = urlPrefix + fieldName;
	// �������·��
	return downloadUrl;
}
