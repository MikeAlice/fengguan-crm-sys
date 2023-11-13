/*
* 负责人：老菌
*/
#include "stdafx.h"
#include "GetContactFieldService.h"
#include "dao/getcontactfieldext/GetContactFieldExtDAO.h"



ContactFieldDTO::Wrapper GetContactFieldService::getContactField()
{
	GetContactFieldExtDAO dao_ext;

	ContactFieldDTO::Wrapper dto = ContactFieldDTO::createShared();
	
	// 2表示添加后被禁用，0表示压根没添加，1表示启用。
	dto->customer_id = 1;
	dto->link_name = "link_name";
	dto->gender = 1;
	if (dao_ext.selectVisibleByName("link_postion") == 0 || dao_ext.selectVisibleByName("link_postion") == 1) {
		dto->postion = "link_postion";
	}
	if (dao_ext.selectVisibleByName("link_tel") == 0 || dao_ext.selectVisibleByName("link_tel") == 1) {
		dto->tel = "link_tel";
	}
	if (dao_ext.selectVisibleByName("link_mobile") == 0 || dao_ext.selectVisibleByName("link_mobile") == 1) {
		dto->mobile = "link_mobile";
	}
	if (dao_ext.selectVisibleByName("link_qicq") == 0 || dao_ext.selectVisibleByName("link_qicq") == 1) {
		dto->qicq = "link_qicq";
	}
	if (dao_ext.selectVisibleByName("link_email") == 0 || dao_ext.selectVisibleByName("link_email") == 1) {
		dto->email = "link_email";
	}
	if (dao_ext.selectVisibleByName("link_address") == 0 || dao_ext.selectVisibleByName("link_address") == 1) {
		dto->address = "link_address";
	}

	return dto;
}
