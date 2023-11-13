/*
 Copyright Zero One Star. All rights reserved.

 @Author: Tapioca
 @Date: 2023/10/25 15:01:08

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
#include "LinkmanDAO.h"
#include <map>

//定义条件解析宏，减少重复代码
// par1:参数名
// par2:函数名
#define SUPPLIERLINKMAN_DANAMIC_PARSE(uObj, sql, par1, par2) \
if (!uObj.get##par2().empty()) { \
	sql = sql + "`" + par1 + "`="; \
    sql = sql + "\"" + uObj.get##par2() + "\"";\
    sql = sql + ",";\
} 

int LinkmanDAO::updateLinkman(const SupplierLinkmanDO& uObj) {
    std::map<std::string, std::string>ext = uObj.getExtFields();
    string sql;

    sql = "UPDATE `sup_linkman` SET ";

    SUPPLIERLINKMAN_DANAMIC_PARSE(uObj, sql, "name", Name);

    if (uObj.getGender() != 0) {
        sql = sql + "`" + "gender" + "`="; 
        sql = sql + "\"" + to_string(uObj.getGender()) + "\"";
        sql = sql + ",";
    };
    
    SUPPLIERLINKMAN_DANAMIC_PARSE(uObj, sql, "position", Position);
    SUPPLIERLINKMAN_DANAMIC_PARSE(uObj, sql, "tel", Tel);
    SUPPLIERLINKMAN_DANAMIC_PARSE(uObj, sql, "mobile", Mobile);
    SUPPLIERLINKMAN_DANAMIC_PARSE(uObj, sql, "qicq", Qicq);
    SUPPLIERLINKMAN_DANAMIC_PARSE(uObj, sql, "email", Email);
    SUPPLIERLINKMAN_DANAMIC_PARSE(uObj, sql, "address", Address);
    if (uObj.getSupplierId() != 0) {
        sql = sql + "`" + "supplier_id" + "`=";
        sql = sql + "\"" + to_string(uObj.getSupplierId()) + "\"";
        sql = sql + ",";
    };

    //扩展字段不为空时则拼接上去
    if (!ext.empty()) {
        for (auto it : ext) {
            sql = sql + "`" + it.first + "`= \"" + it.second + "\",";
        }
    }
    sql.pop_back();

    sql = sql + " WHERE `linkman_id`=?";

    return sqlSession->executeUpdate(sql,"%ull",uObj.getLinkmanId());

}
