#include "stdafx.h"
#include "useFastDFS.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

string useFastDFS::useDfsWithNacos(string fileName)
{
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// ��ʼ�ϴ��ļ�
	std::string fieldName = client.uploadFile(fileName);
	// ��������·��
	std::string downloadUrl = urlPrefix + fieldName;
	// �������·��
	return downloadUrl;
}
