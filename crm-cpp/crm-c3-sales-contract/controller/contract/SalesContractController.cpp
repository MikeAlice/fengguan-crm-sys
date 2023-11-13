#include "stdafx.h"
#include "SalesContractController.h"


//获取销售合同列表数据（用于输入表单下拉列表）长风
GetSalContListJsonVO::Wrapper SalesContractController::execQuerySalContList(const GetSalContListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	GetSalContListService service;
	// 查询数据
	auto result = service.getTitle(query);
	// 响应结果
	auto jvo = GetSalContListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//获取销售合同唯一编号 长风
GetSalesContractNoJsonVO::Wrapper SalesContractController::execQueryContractNo(const UInt64& contract_id)
{
	// 参数校验
	Int32 id = (Int32)contract_id;
	if (!id || id <= 0)
	{
		auto jvo = GetSalesContractNoJsonVO::createShared();
		return jvo;
	}
	// 定义一个Service
	GetSalesNoService service;
	// 查询数据
	auto result = service.getNo(contract_id);
	// 响应结果
	auto jvo = GetSalesContractNoJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//获取销售合同列表 归途   
SalesContractListPageJsonVO::Wrapper SalesContractController::execQuerySalConListGT(const SalesContractPageQuery::Wrapper& query) {
	//return SalesContractListPageJsonVO::createShared();

	// 定义一个service
	querySalesContractListService service;
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = SalesContractListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//获取合同详情 鼻子大的猪
BooleanJsonVO::Wrapper SalesContractController::execQuerySalConDetList(const SalesContractDetailDTO::Wrapper& dto, const PayloadDTO& payload)
{
	return BooleanJsonVO::createShared();
}
//获取合同清单 原味的原味包
ContractGoodsPageJsonVO::Wrapper SalesContractController::execQueryContractGoods(const ContractGoodsQuery::Wrapper& query, const PayloadDTO& payload) {
	ContractGoodsService service;
	auto result = service.listAll(query);
	auto jvo = ContractGoodsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//添加销售合同 原味的原味包
Uint64JsonVO::Wrapper SalesContractController::execAddSalesContract(const AddSalesContractDTO::Wrapper& dto) {
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 合同编号由“获取销售合同唯一编号”得到，不需要用户输入
	// 必要参数为：客户名称customer_name，联系人名称linkman_name，机会名称chance_name，我方人员名称our_user_name
	// 非空校验
	if (!dto->customer_name || !dto->linkman_name || !dto->chance_name || !dto->our_user_name) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	// contract_no 唯一性，暂时不写
	// start_date, end_date
	if (dto->start_date.getValue("") == "") {
		dto->start_date = "0000-00-00"; // 不能插入0000-00-00，后续需要修改
	}
	if (dto->end_date.getValue("") == "") {
		dto->end_date = "0000-00-00";
	}
	SalesContractService service;
	//执行插入
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else {
		jvo->fail(UInt64(id));
	}
	return jvo;
}
//删除销售合同 原味的原味包
Uint64JsonVO::Wrapper SalesContractController::execDeleteSalesContract(const String& contract_no) {
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!contract_no)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	SalesContractService service;
	// 执行数据删除
	uint64_t id = service.removeData(contract_no.getValue(""));
	if (id > 0) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}
//修改销售合同基础信息 咫尺之书
BooleanJsonVO::Wrapper SalesContractController::execModifyBasicInfo(const ModifySalContractBasicInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 创建返回参数
	auto jvo = BooleanJsonVO::createShared();
	// 参数校验
	if (dto->contract_id <= 0)
	{
		jvo->init(false, RS_PARAMS_INVALID);
		return jvo;
	}

	// TODO: 调用service执行更新
	SalContractService service;
	if (service.modifySalContractBasicInfo(dto, payload))
	{
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}

	return jvo;
}
//修改交付状态 咫尺之书
BooleanJsonVO::Wrapper SalesContractController::execModifyDeliverStatus(const ModifyDeliverStatusDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 创建返回参数
	auto jvo = BooleanJsonVO::createShared();
	// 参数校验
	vector<int> status{ -1, 1, 2, 3, 4, 5 };
	if (dto->contract_id <= 0 || find(status.begin(), status.end(), dto->deliver_status) == status.end())
	{
		jvo->init(false, RS_PARAMS_INVALID);
		return jvo;
	}

	// TODO: 调用service执行更新
	SalContractService service;
	if (service.modifyDeliverStatus(dto, payload))
	{
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}

	return jvo;
}
//录入明细 咫尺之书
BooleanJsonVO::Wrapper SalesContractController::execInputList(const InputListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 创建返回参数
	auto jvo = BooleanJsonVO::createShared();
	// 参数校验
	if (dto->contract_id <= 0)
	{
		jvo->init(false, RS_PARAMS_INVALID);
		return jvo;
	}

	// TODO: 调用service执行更新
	SalContractListService service;
	if (service.inputList(dto, payload))
	{
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}

	return jvo;
}
//删除明细 长风
Uint64JsonVO::Wrapper SalesContractController::execDeleteDetailsId(const UInt64& list_id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 参数校验
	if (!list_id || list_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	DeleteDetailsService service;
	// 执行数据删除
	if (service.removeData(list_id.getValue(0))) {
		jvo->success(list_id);
	}
	else
	{
		jvo->fail(list_id);
	}
	// 响应结果
	return jvo;
}
//添加合同附件 鼻子大的猪
StringJsonVO::Wrapper SalesContractController::execUploadOne(std::shared_ptr<IncomingRequest> request)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);
	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO(reader, "file", -1);
	// 3 读取数据
	request->transferBody(&reader);
	/* 打印上传总部分数 */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());
	// 4 解析数据
	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		/* 测试将文件保存到磁盘上面 */
		//string fullPath = "public/static/file/" + filename;
		//file.saveToFile(fullPath.c_str());

		/* 测试上传到FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// 获取文件后缀名
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}
		// 上传文件
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
	}
	// 5 响应结果
	/* TODO: 具体响应什么结果，需要根据你的业务需求来，下面是使用示例而已。 */
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}
//生成出库单 gugu
Int64JsonVO::Wrapper SalesContractController::execAddOutStock(const OutStockDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Int64JsonVO::createShared();

	if (!dto->store_name || !dto->number || !dto->status)
	{
		jvo->init(Int64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->store_name->empty() || dto->number < 0 || dto->status < 0)
	{
		jvo->init(Int64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	AddOutStockService service;
	// 执行数据新增

	return service.AddOutStock(dto, payload);
}
//导出销售合同 科文
StringJsonVO::Wrapper SalesContractController::execQueryExportSales(const ExportSalesQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	// 无需数据校验条件可以为空

	ExportSaleService  service;
	std::string downloadUrl = service.exportExportSales(query);

	jvo->success(downloadUrl);
	return jvo;

	// return ExportSalesJsonVO::Wrapper();
}


////未知 疑似来自鼻子大的猪
//BooleanJsonVO::Wrapper SalesContractController::execGetSalConList(const SalesContractDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	return BooleanJsonVO::createShared();
//}



