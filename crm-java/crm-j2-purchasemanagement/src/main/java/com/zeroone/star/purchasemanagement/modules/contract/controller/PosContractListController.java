package com.zeroone.star.purchasemanagement.modules.contract.controller;


import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.j2.purchasemanagement.PosContractListApis;
import com.zeroone.star.project.query.j2.purchasemanagement.GetContractListPageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.purchasemanagement.GetContractListPageVO;
import com.zeroone.star.project.vo.j2.purchasemanagement.ExportContractDetailVO;
import com.zeroone.star.purchasemanagement.modules.contract.excel.ContractDetailExcel;
import com.zeroone.star.purchasemanagement.modules.contract.service.PosContractListService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.List;

/**
 * <p>
 * 采购订单商品表 前端控制器
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@RestController
@RequestMapping("/contract/pos-contract-list")
@Api(tags = "采购明细接口")
public class PosContractListController implements PosContractListApis {

    @Autowired
    private PosContractListService service;

    @Resource
    EasyExcelComponent easyExcel;

    @Resource
    FastDfsClientComponent dfsClient;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    @PostMapping("get-contract-list-page")
    @ApiOperation(value = "获取合同列表 (分页+条件)")
    @Override
    public JsonVO<GetContractListPageVO> getContractListPage(@Validated @RequestBody GetContractListPageQuery query) {
        return JsonVO.success(service.getContractListPage(query));
    }

    @GetMapping("export-contract-detail")
    @ApiOperation(value = "导出采购合同明细")
    @Override
    public JsonVO<ExportContractDetailVO> exportContractDetail(@ApiParam(value = "采购合同明细id集合", required = true) @RequestParam List<Integer> contractDetailIdList) throws Exception {
        // 导出数据
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        easyExcel.export("明细报表", out, ContractDetailExcel.class, service.getContractDetailExcelListByIds(contractDetailIdList));
        // 上传报表
        FastDfsFileInfo uploadInfo = dfsClient.uploadFile(out.toByteArray(), "xlsx");
        out.close();
        // 响应下载地址
        if (uploadInfo == null) {
            return JsonVO.fail(null);
        }
        ExportContractDetailVO result = new ExportContractDetailVO();
        result.setUrl(dfsClient.fetchUrl(uploadInfo, fileServerUrl, true));
        return JsonVO.success(result);
    }
}