#pragma once

#ifndef EXPENDITURESDO_H__
#define EXPENDITURESDO_H__
#include "../DoInclude.h"

class ExpendituresDO
{
	CC_SYNTHESIZE(int,record_id,RecordId);
	CC_SYNTHESIZE(string,type_,Type);
	CC_SYNTHESIZE(int,money,Money);
	CC_SYNTHESIZE(string,bank,Bank);
	CC_SYNTHESIZE(string,happen_date,HappenDate);
	CC_SYNTHESIZE(string,create_user,CreateUser);
	CC_SYNTHESIZE(string,create_time,CreateTime);
	CC_SYNTHESIZE(string,intro,Intro);
public:
	ExpendituresDO() {
		record_id = 0;
		type_ = "";
		money = 0;
		bank = "";
		happen_date = "";
		create_user = "";
		create_time = "";
		intro = "";
	}
};

class ExpendituresAddDO
{
	CC_SYNTHESIZE(int,record_id,RecordId);
	CC_SYNTHESIZE(int,type_,Type);
	CC_SYNTHESIZE(int,money,Money);
	CC_SYNTHESIZE(int,bank,Bank);
	CC_SYNTHESIZE(string,happen_date,HappenDate);
	CC_SYNTHESIZE(int,create_user,CreateUser);
	CC_SYNTHESIZE(string,create_time,CreateTime);
	CC_SYNTHESIZE(string,intro,Intro);
public:
	ExpendituresAddDO() {
		record_id = 0;
		type_ = 0;
		money = 0;
		bank = 0;
		happen_date = "";
		create_user = 0;
		create_time = "";
		intro = "";
	}
};

#endif // EXPENDITURESDO_H__
