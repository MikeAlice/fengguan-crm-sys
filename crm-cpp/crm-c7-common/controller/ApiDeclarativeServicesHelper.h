#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/26 20:17:49

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
#ifndef _APIDECLARATIVESERVICESHELPER_H_
#define _APIDECLARATIVESERVICESHELPER_H_
/**
 * ��������ʽ������ú�򻯲������Լ��ڴ��ļ���ͳһ��������ʽ���������ͷ�ļ����������͵���
 */

// �������ͷ�ļ�
#include "oatpp/core/data/mapping/ObjectMapper.hpp"
#include "oatpp/web/client/HttpRequestExecutor.hpp"
#ifdef HTTP_SERVER_DEMO
#include "service/sample/declarative/SampleApiClient.h"
#endif
//////////////////////////////////////////////////////////////////////////
// #TIP: ��Ŀ�е�ApiClient�����ﵼ��

// ��ȡ��Ӧ�������б�
#include "service/listSupNameList/SupNameListApiClient.h"
// ��ȡ��Ӧ����ϵ�������б�
#include "service/listLinkmanNameList/LinkmanNameListApiClient.h"
// ��ȡ�ֿ������б�
#include "service/warehouse/WarehouseApiClient.h"
// ��ȡ���������б�
#include "service/area/AreaApiController.h"
// ��ȡ���������б�&��ȡ��λ�����б�&��ȡ��ɫ�����б�&ϵͳ�û������б�
#include "service/orgStructure/OrgStructureApiClient.h"
// ��ȡ�ͻ������б�&��ȡ��ϵ�������б�
#include "service/clientManage/ClientManageApiClient.h"
// ��ȡ�����˻��б�����&��ȡ���ÿ�֧���������б�����&��ȡ�����������������б�����
#include "service/financeType/FinanceTypeApiClient.h"
// ��ȡָ���ֵ�����Ӧ�ֵ��б�
#include "service/dataDict/DataDictApiClient.h"
// ��ȡ���ۻ��������б�&��ȡ���ۺ�ͬ�����б�
#include "service/saleManage/SaleManageApiClient.h"
// ��ȡ��Ʒ���������б���������������б�
#include "service/goodsCategoryNameList/GoodsNameListApiClient.h"
//////////////////////////////////////////////////////////////////////////

/**
 * ����һ������API Client�ĺ�
 * @param _VAR_CLIENT_: �����Ŀͻ��˱�������
 * @param _VAR_MAPPER_: ����JSON����ת����mapper�����������
 * @param _CLASS_CLIENT_: �ͻ�������
 * @param _EXECUTOR_NAME_: HttpRequestExecutorִ����������ơ��磺"gateway"
 */
#define API_CLIENT_CREATE(_VAR_CLIENT_, _VAR_MAPPER_, _CLASS_CLIENT_, _EXECUTOR_NAME_) \
OATPP_COMPONENT(std::shared_ptr<oatpp::web::client::HttpRequestExecutor>, requestExecutor, _EXECUTOR_NAME_); \
OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, _VAR_MAPPER_); \
auto _VAR_CLIENT_ = _CLASS_CLIENT_::createShared(requestExecutor, _VAR_MAPPER_)

#endif // !_APIDECLARATIVESERVICESHELPER_H_