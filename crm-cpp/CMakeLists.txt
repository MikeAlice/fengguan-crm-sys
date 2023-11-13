# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

# 指定工程名
project ("zero-one-crm")

# 设置安装目录前缀
#if(NOT CMAKE_INSTALL_PREFIX)
	set (CMAKE_INSTALL_PREFIX "../install/${PROJECT_NAME}" CACHE PATH "install path prefix" FORCE )
#endif()

# C++标准
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加宏定义
add_definitions(-DLINUX)
add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
add_definitions(-DCPP_JWT_USE_VENDORED_NLOHMANN_JSON)
add_definitions(-DOATPP_DISABLE_ENV_OBJECT_COUNTERS)
add_definitions(-DCHECK_TOKEN)
add_definitions(-DSTOP_PWD="01star")
add_definitions(-DOATPP_SWAGGER_SERVICE_NAME="crm api for linux")
add_definitions(-DOATPP_SWAGGER_RES_PATH="res")
add_definitions(-DBSONCXX_STATIC -DMONGOCXX_STATIC -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF)

# 在camke .. 的时候会输出提示目录路径
message (STATUS "Prefix dir is ${CMAKE_INSTALL_PREFIX}")
message (STATUS "Binary dir is ${PROJECT_BINARY_DIR}")
message (STATUS "Source dir is ${PROJECT_SOURCE_DIR}")

# 判断是否是Ubuntu系统
option (IS_UBUNTU "is ubuntu" OFF)
cmake_host_system_information(RESULT PRETTY_NAME QUERY OS_VERSION)
if (${PRETTY_NAME} MATCHES "Ubuntu")
	option (IS_UBUNTU "is ubuntu" ON)
endif()

# 检查OpenSSL库是否存在
find_package (OpenSSL REQUIRED)
if (OPENSSL_FOUND)
  include_directories (${OPENSSL_INCLUDE_DIRS})
  message (STATUS "OpenSSL Found!")
endif()

# 检查CURL库是否存在
find_package (CURL REQUIRED)
if (CURL_FOUND)
  include_directories (${CURL_INCLUDE_DIRS})
  message (STATUS "CURL Found!")
endif()

# 设置宏定义开关
option (USE_XLNT "use xlnt" ON)
option (USE_DFS "use fastdfs" ON)
option (USE_YML "use yaml" ON)
option (USE_NACOS "use nacos, need open yaml" ON)
option (USE_REDIS "use redis" ON)
option (USE_ROCKETMQ "use rocketmq" ON)
option (USE_MONGO "use mongodb" ON)
option (USE_ALISMS "use aliyun sms" ON)

# 选项宏定义
# 为了保证排除后编译通过，在单独使用这些库的地方加上对应的宏定义
if (USE_XLNT)
	add_definitions(-DUSE_XLNT)
endif()
if (USE_DFS)
	add_definitions(-DUSE_DFS)
endif()
if (USE_YML)
	add_definitions(-DUSE_YML)
endif()
if (USE_NACOS)
	add_definitions(-DUSE_NACOS)
endif()
if (USE_REDIS)
	add_definitions(-DUSE_REDIS)
endif()
if (USE_ROCKETMQ)
	add_definitions(-DUSE_ROCKETMQ)
endif()
if (USE_MONGO)
	add_definitions(-DUSE_MONGO)
endif()
if (USE_ALISMS)
	add_definitions(-DUSE_ALISMS)
endif()

# 包含子项目
add_subdirectory ("lib-oatpp")
add_subdirectory ("lib-mysql")
add_subdirectory ("lib-common")
add_subdirectory ("nacos-register")
# 这是示例模块，后期可以不编译它
#add_subdirectory ("arch-demo")
# 在后面添加你的模块
add_subdirectory ("crm-c1-basedata")
add_subdirectory ("crm-c2-customer-mycustomer")
add_subdirectory ("crm-c2-customer-publiccustomer")
add_subdirectory ("crm-c2-customer-contact")
add_subdirectory ("crm-c2-customer-servicerecords")
add_subdirectory ("crm-c3-sales-contract")
add_subdirectory ("crm-c3-sales-opportunities")
add_subdirectory ("crm-c4-collection-man")
add_subdirectory ("crm-c4-sales-man")
add_subdirectory ("crm-c5-financial-manager")
add_subdirectory ("crm-inventory-manager")
add_subdirectory ("crm-c6-fundmanagement-fincapitalrecord")
add_subdirectory ("crm-c6-fundmanagement-payment")
add_subdirectory ("crm-c7-common")
add_subdirectory ("crm-c7-supplier-manage")