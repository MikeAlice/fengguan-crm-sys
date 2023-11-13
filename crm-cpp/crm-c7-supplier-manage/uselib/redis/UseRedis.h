#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/10/30 23:01:45

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
#ifndef _USEREDIS_H_
#define _USEREDIS_H_

#include "RedisClient.h"
#include <unordered_map>
#include "ServerInfo.h"
#include "NacosClient.h"
#include "YamlHelper.h"
#include <memory>

/**
 * Redis++库使用类
 * 负责人: Andrew
 */
class UseRedis
{
	std::unique_ptr<RedisClient> client;
public:
	// 默认构造函数
	UseRedis()
	{
		//获取配置
		NacosClient nacosClient(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	#ifdef LINUX
		YAML::Node node = nacosClient.getConfig("data-source.yaml");
	#else
		YAML::Node node = nacosClient.getConfig("./conf/data-source.yaml");
	#endif

		//获取redis相关配置
		YamlHelper yaml;
		string host = yaml.getString(&node, "spring.redis.host");
		string port = yaml.getString(&node, "spring.redis.port");
		string password = yaml.getString(&node, "spring.redis.password");

		//创建RedisClient对象
		client = std::make_unique<RedisClient>(host, atoi(port.c_str()), password);
	}
	/**
	 * Redis HASH Setter
	 */
	template<typename T, typename U>
	bool hash_setter(const std::string& title, const std::unordered_map<T, U>& hash);
	/**
	 * Redis HASH Getter
	 */
	template<typename T, typename U>
	std::unordered_map<T, U> hash_getter(const std::string& title);
	/**
	 * Redis LIST Setter
	 */
	template<typename T>
	bool list_setter(const std::string& title, const std::vector<T>& data);
	/**
	 * Redis LIST Getter
	 */
	template<typename T>
	std::vector<T> list_getter(const std::string& title);
};

template<typename T, typename U>
bool UseRedis::hash_setter(const std::string& title, const std::unordered_map<T, U>& hash)
{
	return client->execute<bool>([&](Redis* r) { 
		return r->hset(title, hash.begin(), hash.end()); 
	});
}

template<typename T, typename U>
std::unordered_map<T, U> UseRedis::hash_getter(const std::string& title)
{
	std::unordered_map<T, U> res;
	client->execute<int>([&](Redis* r) { 
		r->hgetall(title, std::inserter(res, res.begin()));
		return 1;
	});
	return res;
}

template<typename T>
bool UseRedis::list_setter(const std::string& title, const std::vector<T>& data)
{
	return client->execute<bool>([&](Redis* r) {
		return r->rpush(title, data.begin(), data.end());
	});
}

template<typename T>
std::vector<T>
UseRedis::list_getter(const std::string& title)
{
	std::vector<T> vec;
	client->execute<int>([&](Redis* r) {
		r->lrange(title, 0, -1, std::back_inserter(vec));
		return 1;
	});
	return vec;
}

#endif // !_USEREDIS_H_