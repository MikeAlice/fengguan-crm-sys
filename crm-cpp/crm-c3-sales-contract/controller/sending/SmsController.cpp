#include "stdafx.h"
#include "SmsController.h"
//#include "sms/aliyun/AliSmsSender.h"

SmsDTO::Wrapper SmsController::execSendSms(const SmsDTO::Wrapper& smsDto) {
    //AliSmsSender sender;
    //for (size_t i = 0; i < (*smsDto->phoneNumber).size(); ++i) {
    //    std::shared_ptr<AliSmsResult> res = 
    //        sender.sendSms(smsDto->phoneNumber[i], 
    //            "Your Sign Name", "Your Template Code", "{\"code\":\"Your Code\"}");
    //}
    // TODO: Add your business logic here
    // For now, it's an empty function
    return  SmsDTO::createShared();
}