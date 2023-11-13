#pragma once
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
#ifndef _USEFASTDFS_H_
#define _USEFASTDFS_H_

#include <string>
#include <memory>
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

/**
 * FastDFS�����ʹ�ð�װ��
 * ������: Andrew
 */
class UseFastdfs
{
private:
	std::unique_ptr<FastDfsClient> client; // DFS�ͻ��˶���
	std::string urlPrefix; // URLǰ׺
public:
	UseFastdfs()
	{
		// ����DFS�ͻ��˶����URLǰ׺
		//����һ��Nacos�ͻ��˶������ڻ�ȡ����
		NacosClient _ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
		// ��ȡ�������ݽڵ�
		auto _thirdServerConfig = _ns.getConfig("./conf/third-services.yaml");
		// �������л�ȡFastDFS�ͻ�����������
		std::string _ipPort = YamlHelper().getString(&_thirdServerConfig, "fastdfs.tracker-servers");
		std::string _ip = _ipPort.substr(0, _ipPort.find(":"));
		int _port = stoi(_ipPort.substr(_ipPort.find(":") + 1));
		client = std::make_unique<FastDfsClient>(_ip, _port);
		// ����URLǰ׺
		urlPrefix = "http://" + YamlHelper().getString(&_thirdServerConfig, "fastdfs.nginx-servers") + "/";
	}
	/**
	 * �ϴ��ļ���FastDFS�ļ�������, �����ļ�����·��
	 * @param file: ���ϴ��ļ�·��
	 * @return std::string: �ļ�����·��
	 */
	std::string uploadFile(const std::string& file);
	/**
	 * ��FastDFS�����������ļ�
	 * @param downloadUrl: ��������
	 * @param savePath: �ļ�����·��, Ĭ��'./public/fastdfs'
	 * @return std::string: ���ذ����ļ���·����
	 */
	std::string downloadFile(const std::string& downloadUrl, std::string savePath = "./public/fastdfs");
	/**
	 * ɾ��FastDFS�������ϵ��ļ�
	 * @param fieldName: ��ɾ���ļ���, ��������+�ļ���
	 * @return bool: ɾ���Ƿ�ɹ�
	 */
	bool deleteFile(const std::string& fieldName);
};

#endif // !_USEFASTDFS_H_