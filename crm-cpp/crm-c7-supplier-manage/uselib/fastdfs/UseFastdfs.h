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
 * FastDFS组件库使用包装类
 * 负责人: Andrew
 */
class UseFastdfs
{
private:
	std::unique_ptr<FastDfsClient> client; // DFS客户端对象
	std::string urlPrefix; // URL前缀
public:
	UseFastdfs()
	{
		// 定义DFS客户端对象和URL前缀
		// 定义一个Nacos客户端对象，用于获取配置
		NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	#ifdef LINUX
		// 读取配置数据节点
		auto thirdServerConfig = ns.getConfig("third-services.yaml");
		// 从Nacos配置中心获取FastDFS客户端配置数据
		std::string config = ns.getConfigText("client.conf");
		// 定义客户端对象
		client = std::make_unique<FastDfsClient>(config, false);
	#else
		// 读取配置数据节点
		auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
		// 从配置中获取FastDFS客户端配置数据
		std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
		std::string ip = ipPort.substr(0, ipPort.find(":"));
		int port = stoi(ipPort.substr(ipPort.find(":") + 1));
		// 定义客户端对象
		client = std::make_unique<FastDfsClient>(ip, port);
	#endif
		// 构建URL前缀
		urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
	}
	/**
	 * 上传文件到FastDFS文件服务器, 返回文件下载路径
	 * @param file: 待上传文件路径
	 * @return std::string: 文件下载路径
	 */
	std::string uploadFile(const std::string& file);
	/**
	 * 从FastDFS服务器下载文件
	 * @param downloadUrl: 下载链接
	 * @param savePath: 文件保存路径, 默认'./public/fastdfs'
	 * @return std::string: 返回包含文件的路径名
	 */
	std::string downloadFile(const std::string& downloadUrl, std::string savePath = "./public/fastdfs");
	/**
	 * 删除FastDFS服务器上的文件
	 * @param fieldName: 待删除文件名, 包含组名+文件名
	 * @return bool: 删除是否成功
	 */
	bool deleteFile(const std::string& fieldName);
};

#endif // !_USEFASTDFS_H_