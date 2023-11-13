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

//updateSupplierStatic,负责人：Juno
//只修改静态字段，且需要全部字段都传入
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


//updateSupplierExtFields,负责人：Juno
//支持修改扩展字段，需要全部字段都传入
int UpdateSupplierDAO::updateSupplierExtFields(const SupplierDO& uObj)
{
	//扩展字段修改
	map<string, string> ext = uObj.getExtFields();
	//bool b_ext = false;
	string sql;

	if (ext.empty())//只有静态字段
	{
		sql = "UPDATE `sup_supplier` SET `name`= ? , `ecotype`= ? , `trade`= ? , `address`= ? , `linkman`= ? , `tel`= ? , `fax`= ? , `email`= ? , `intro`= ? WHERE `supplier_id`= ? ";
	}
	else//有扩展字段
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


//updateSupplierExtFields,负责人：Juno
//支持修改扩展字段，只需传入需要修改的字段
int UpdateSupplierDAO::updateSupplierExtFields(const SupplierDO& uObj, const ModifySupplierDTO::Wrapper& dto)
{
	//扩展字段修改
	map<string, string> ext = uObj.getExtFields();
	bool ismodify = false;//是否传入了需要修改的字段
	string sql = "UPDATE `sup_supplier` SET ";

	//是否传入供应商名称
	if (dto->supplierName)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`name`=" + "'" + uObj.getName() + "'";
		ismodify = true;
	}

	//是否传入经济类型
	if (dto->ecoType)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`ecotype`=" + std::to_string(uObj.getEcotype());
		ismodify = true;
	}

	//是否传入行业类型
	if (dto->trade)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`trade`=" + std::to_string(uObj.getTrade());
		ismodify = true;
	}

	//是否传入联系地址
	if (dto->address)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`address`=" + "'" + uObj.getAddress() + "'";
		ismodify = true;
	}

	//是否传入联系人id
	if (dto->linkman)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`linkman`=" + std::to_string(uObj.getLinkman());
		ismodify = true;
	}

	//是否传入电话
	if (dto->telephone)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`tel`=" + "'" + uObj.getTel() + "'";
		ismodify = true;
	}

	//是否传入传真
	if (dto->fax)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`fax`=" + "'" + uObj.getFax() + "'";
		ismodify = true;
	}

	//是否传入邮箱
	if (dto->email)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`email`=" + "'" + uObj.getEmail() + "'";
		ismodify = true;
	}

	//是否传入介绍
	if (dto->intro)
	{
		if (ismodify)
		{
			sql = sql + ",";
		}
		sql = sql + "`intro`=" + "'" + uObj.getIntro() + "'";
		ismodify = true;
	}

	//是否传入扩展字段
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

	//判断是否有需要修改的字段传入
	if (ismodify)
	{
		sql = sql + " WHERE `supplier_id`= ? ";
		auto res = sqlSession->executeUpdate(sql, "%ull", uObj.getSupplierId());
		return res;
	}
	else
	{
		//所有字段都没改
		return 0;
	}
}
