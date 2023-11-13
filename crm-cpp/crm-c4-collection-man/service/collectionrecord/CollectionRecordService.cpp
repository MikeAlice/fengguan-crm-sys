#include "stdafx.h"
#include "CollectionRecordService.h"
#include"dao/collectionrecord/CollectionRecordDAO.h"
#include"domain/do/collectionrecord/CollectionRecordDO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"

CollectionRecordPageDTO::Wrapper CollectionRecordService::listCollectionRecord(const CollectionRecordQuery::Wrapper& query)
{

    auto pages = CollectionRecordPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    CollectionRecordDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0) 
    {
        return pages;
    }

    // 分页查询数据
    pages->total = count;
    pages->calcPages();
    // 分页查询数据
    pages->total = count;
    pages->calcPages();
    list<CollectionRecordDO> result = dao.selectWithPage(query);
    // 将DO转换成DTO
    for (CollectionRecordDO sub : result)
    {
        auto dto = CollectionRecordDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, record_id, record_id, 
            customer_name, customer_name, 
            contract_id, contract_id, 
            back_date,  back_date,
            stages,stages,
            bank_id, bank_id, 
            create_user_id, create_user_id, 
            create_time, create_time
        )
         pages->addData(dto);

    }
    return pages;
}

uint64_t CollectionRecordService::saveCollectrionRecord(const CollectionRecordDTO::Wrapper& dto)
{
    CollectionRecordDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, record_id, record_id,
        customer_name, customer_name,
        contract_id, contract_id,
        back_date, back_date,
        stages, stages,
        bank_id, bank_id,
        create_user_id, create_user_id,
        create_time, create_time
    )
    CollectionRecordDAO dao;
    
    return dao.insert(data);
}

oatpp::String CollectionRecordService::exportCollectionRecord(const DelCollectionRecordDTO::Wrapper& dto)
{
    CollectionRecordDAO dao;
    auto list=dao.selectById(dto);
    //组装数据--------------------------------------------
    std::vector<std::vector<std::string>> data;
    for (auto& record : list) {
        vector<std::string> row;
        row.push_back(std::to_string(record.getrecord_id()));
        row.push_back((record.getcustomer_name()));
        row.push_back(std::to_string(record.getcontract_id()));
        row.push_back((record.getback_date()));
        row.push_back(std::to_string(record.getstages()));
        row.push_back(std::to_string(record.getmoney()));
        row.push_back(std::to_string(record.getbank_id()));
        row.push_back(std::to_string(record.getcreate_user_id()));
        row.push_back((record.getcreate_time()));
        data.push_back(row);
    }
  

    //生成excel
    ExcelComponent excel;
    std::string fileName = "./public/excel/collectionRecord.xlsx";
    std::string sheetName = CharsetConvertHepler::ansiToUtf8("数据表1");
    excel.writeVectorToFile(fileName, sheetName, data);

    //上传到fastdfs
    FastDfsClient client("8.130.45.222");
    std::string fieldName = client.uploadFile(fileName);
    std::cout << "upload fieldname is : " << fieldName << std::endl;

    std::string urlPrefix = "http://8.130.45.222:8888/";

    std::string downloadUrl = urlPrefix + fieldName;
    std::cout << downloadUrl << std::endl;

    return downloadUrl;
}

bool CollectionRecordService::removeCollectionRecord(uint64_t id)
{   
    CollectionRecordDAO dao;
    return dao.deleteById(id);
}
