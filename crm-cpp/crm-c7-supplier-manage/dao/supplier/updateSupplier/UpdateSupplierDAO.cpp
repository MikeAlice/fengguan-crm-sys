/*
 Copyright Zero One Star. All rights reserved.

 @Author: juno
 @Date: 2023/10/25 18:26:52

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
#include "UpdateSupplierDAO.h"

//updateSupplierStatic,�����ˣ�Juno
//ֻ�޸ľ�̬�ֶΣ�����Ҫȫ���ֶζ�����
int UpdateSupplierDAO::updateSupplierStatic(const SupplierDO& uObj)
{
	string sql = "UPDATE `sup_supplier` SET `name`= ? , `area_id`= ? , `level`= ? , `ecotype`= ? , `trade`= ? , `satisfy`= ? , `credit`= ? , `address`= ? , `linkman`= ? , `website`= ? , `zipcode`= ? , `tel`= ? , `fax`= ? , `email`= ? , `intro`= ? WHERE `supplier_id`= ? ";
	auto res = sqlSession->executeUpdate(sql, "%s%ull%ull%ull%ull%ull%ull%s%s%s%s%s%s%s%s%ull",
									uObj.getName(), uObj.getAreaId(), uObj.getLevel(),
									uObj.getEcotype(), uObj.getTrade(), uObj.getSatisfy(),
									uObj.getCredit(), uObj.getAddress(), uObj.getLinkman(),
									uObj.getWebsite(), uObj.getZipcode(), uObj.getTel(),
									uObj.getFax(), uObj.getEmail(), uObj.getIntro(),
									uObj.getSupplierId());
	return res;
}


//updateSupplierExtFields,�����ˣ�Juno
//֧���޸���չ�ֶΣ���Ҫȫ���ֶζ�����
int UpdateSupplierDAO::updateSupplierExtFields(const SupplierDO& uObj)
{
	//��չ�ֶ��޸�
	map<string, string> ext = uObj.getExtFields();
	//bool b_ext = false;
	string sql;

	if (ext.empty())//ֻ�о�̬�ֶ�
	{
		sql = "UPDATE `sup_supplier` SET `name`= ? , `ecotype`= ? , `trade`= ? , `address`= ? , `linkman`= ? , `tel`= ? , `fax`= ? , `email`= ? , `intro`= ? WHERE `supplier_id`= ? ";
	}
	else//����չ�ֶ�
	{
		string sql0 = "UPDATE `sup_supplier`"
					  " SET "
					  "`name`= ? , `ecotype`= ? , "
					  "`trade`= ? , `address`= ? , `linkman`= ? , "
					  "`tel`= ? , `fax`= ? , `email`= ? , "
					  "`intro`= ? "; 
		for (auto &p : ext)
		{
			sql0 = sql0 + ", " + p.first + "=" + "'" + p.second + "'";
		}
		sql = sql0 + " WHERE `supplier_id`= ? ";
	}
	auto res = sqlSession->executeUpdate(sql, "%s%ull%ull%s%ull%s%s%s%s%ull",
		uObj.getName(),
		uObj.getEcotype(), uObj.getTrade(), 
		uObj.getAddress(), uObj.getLinkman(),
		uObj.getTel(),
		uObj.getFax(), uObj.getEmail(), uObj.getIntro(),
		uObj.getSupplierId());
	return res;
}


//updateSupplierExtFields,�����ˣ�Juno
//֧���޸���չ�ֶΣ�ֻ�贫����Ҫ�޸ĵ��ֶ�
int UpdateSupplierDAO::updateSupplierExtFields(const SupplierDO& uObj, const ModifySupplierDTO::Wrapper& dto)
{
	//��չ�ֶ��޸�
	map<string, string> ext = uObj.getExtFields();
	bool ismodify = false;//�Ƿ�������Ҫ�޸ĵ��ֶ�
	string sql = "UPDATE `sup_supplier` SET ";

	//�Ƿ��빩Ӧ������
	if (dto->supplierName)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`name`=" + "'" + uObj.getName() + "'";
		ismodify = true;
	}

	//�Ƿ��뾭������
	if (dto->ecoType)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`ecotype`=" + std::to_string(uObj.getEcotype());
		ismodify = true;
	}

	//�Ƿ�����ҵ����
	if (dto->trade)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`trade`=" + std::to_string(uObj.getTrade());
		ismodify = true;
	}

	//�Ƿ�����ϵ��ַ
	if (dto->address)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`address`=" + "'" + uObj.getAddress() + "'";
		ismodify = true;
	}

	//�Ƿ�����ϵ��id
	if (dto->linkman)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`linkman`=" + std::to_string(uObj.getLinkman());
		ismodify = true;
	}

	//�Ƿ���绰
	if (dto->telephone)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`tel`=" + "'" + uObj.getTel() + "'";
		ismodify = true;
	}

	//�Ƿ��봫��
	if (dto->fax)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`fax`=" + "'" + uObj.getFax() + "'";
		ismodify = true;
	}

	//�Ƿ�������
	if (dto->email)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`email`=" + "'" + uObj.getEmail() + "'";
		ismodify = true;
	}

	//�Ƿ������
	if (dto->intro)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`intro`=" + "'" + uObj.getIntro() + "'";
		ismodify = true;
	}

	//�Ƿ�����չ�ֶ�
	if (!ext.empty())
	{
		for (auto& p : ext)
		{
			if (ismodify)
			{
				sql = sql + ",";
			}
			sql = sql + p.first + "=" + "'" + p.second + "'";
			ismodify = true;
		}
	}

	//�ж��Ƿ�����Ҫ�޸ĵ��ֶδ���
	if (ismodify)
	{
		sql = sql + " WHERE `supplier_id`= ? ";
		auto res = sqlSession->executeUpdate(sql, "%ull", uObj.getSupplierId());
		return res;
	}
	else
	{
		//�����ֶζ�û��
		return 0;
	}
}
