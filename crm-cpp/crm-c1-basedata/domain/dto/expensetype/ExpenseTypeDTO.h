#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _EXPENSETYPE_DTO_
#define _EXPENSETYPE_DTO_
#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����֧���������
 */
class ExpenseTypeDTO : public oatpp::DTO
{
	DTO_INIT(ExpenseTypeDTO, DTO);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("expensetype.field.id");
	}
	// ��������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("expensetype.field.name");
	}
	// ������Ŀ
	DTO_FIELD(UInt64, parentID);
	DTO_FIELD_INFO(parentID) {
		info->description = ZH_WORDS_GETTER("expensetype.field.parentID");
	}
	// ��λ���
	DTO_FIELD(Int32, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("expensetype.field.sort");
	}
	// �Ƿ�����
	DTO_FIELD(Int32, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("expensetype.field.visible");
	}
	// ����
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("expensetype.field.intro");
	}
};

/**
 * ʾ����ҳ�������
 */
class ExpenseTypePageDTO : public PageDTO<ExpenseTypeDTO::Wrapper>
{
	DTO_INIT(ExpenseTypePageDTO, PageDTO<ExpenseTypeDTO::Wrapper>);
};
class ExpenseDTO : public oatpp::DTO
{
	DTO_INIT(ExpenseDTO, DTO);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("expense.field.id");
	}
	// ��������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("expense.field.name");
	}
	// ����ID
	DTO_FIELD(UInt64, parentid);
	DTO_FIELD_INFO(parentid) {
		info->description = ZH_WORDS_GETTER("expense.field.parentid");
	}
	// ��λ���
	DTO_FIELD(UInt64, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("expense.field.sort");
	}
	//�Ƿ�����
	DTO_FIELD(UInt64, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("expense.field.visible");
	}
	//���
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("expense.field.intro");
	}


};

/**
 * ����֧�����ͽṹ�����ݴ������
 */
class ExpenseTreeDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(ExpenseTreeDTO, DTO);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("expense.field.id");
	}
	// ��������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("expense.field.name");
	}
	// ����ID
	DTO_FIELD(UInt64, parentid);
	DTO_FIELD_INFO(parentid) {
		info->description = ZH_WORDS_GETTER("expense.field.parentid");
	}
	// ��λ���
	DTO_FIELD(UInt64, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("expense.field.sort");
	}
	//�Ƿ�����
	DTO_FIELD(UInt64, visible);
	DTO_FIELD_INFO(visible) {
		info->description = ZH_WORDS_GETTER("expense.field.visible");
	}
	//���
	DTO_FIELD(String, intro);
	DTO_FIELD_INFO(intro) {
		info->description = ZH_WORDS_GETTER("expense.field.intro");
	}

	// �ӽڵ�
	API_DTO_FIELD(List<ExpenseTreeDTO::Wrapper>, children, ZH_WORDS_GETTER("expense.field.child"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<ExpenseTreeDTO>(child), Wrapper::Class::getType()));
	}
};
/**
 * ʾ����ҳ�������
 */
class ExpensePageDTO : public PageDTO<ExpenseDTO::Wrapper>
{
	DTO_INIT(ExpensePageDTO, PageDTO<ExpenseDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPENSETYPE_DTO_