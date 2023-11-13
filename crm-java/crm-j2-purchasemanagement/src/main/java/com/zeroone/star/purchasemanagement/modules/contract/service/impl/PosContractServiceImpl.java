package com.zeroone.star.purchasemanagement.modules.contract.service.impl;

import cn.hutool.core.collection.CollectionUtil;
import cn.hutool.core.date.DateUtil;
import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.AddContractDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.ContractSelectDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.ModifyContractDTO;
import com.zeroone.star.project.dto.j2.purchasemanagement.SelectContractDTO;
import com.zeroone.star.project.query.j2.purchasemanagement.GetContractListWithPageConditionQuery;
import com.zeroone.star.project.vo.j2.purchasemanagement.*;
import com.zeroone.star.project.vo.j2.purchasemanagement.base.BasePosContractVO;
import com.zeroone.star.purchasemanagement.common.config.PurchaseManagementException;
import com.zeroone.star.purchasemanagement.common.utils.ConvertUtil;
import com.zeroone.star.purchasemanagement.modules.contract.entity.PosContractEntity;
import com.zeroone.star.purchasemanagement.modules.contract.entity.PosContractFileEntity;
import com.zeroone.star.purchasemanagement.modules.contract.entity.PosContractListEntity;
import com.zeroone.star.purchasemanagement.modules.contract.enums.PosContractEnum;
import com.zeroone.star.purchasemanagement.modules.contract.excel.PosContractExcel;
import com.zeroone.star.purchasemanagement.modules.contract.mapper.PosContractMapper;
import com.zeroone.star.purchasemanagement.modules.contract.service.PosContractFileService;
import com.zeroone.star.purchasemanagement.modules.contract.service.PosContractListService;
import com.zeroone.star.purchasemanagement.modules.contract.service.PosContractService;
import com.zeroone.star.purchasemanagement.modules.other.entity.FlySysUserEntity;
import com.zeroone.star.purchasemanagement.modules.other.entity.SupLinkmanEntity;
import com.zeroone.star.purchasemanagement.modules.other.entity.SupSupplierEntity;
import com.zeroone.star.purchasemanagement.modules.other.service.FlySysUserService;
import com.zeroone.star.purchasemanagement.modules.other.service.SupLinkmanService;
import com.zeroone.star.purchasemanagement.modules.other.service.SupSupplierService;
import org.apache.commons.lang.StringUtils;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.math.BigDecimal;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * <p>
 * 采购合同 服务实现类
 * </p>
 *
 * @author j2
 * @since 2023-10-29
 */
@Service
public class PosContractServiceImpl extends ServiceImpl<PosContractMapper, PosContractEntity> implements PosContractService {
    @Autowired
    private PosContractListService posContractListService;
    @Autowired
    private PosContractFileService posContractFileService;
    @Resource
    SupLinkmanService supLinkmanService;
    @Resource
    SupSupplierService supSupplierService;
    @Resource
    FlySysUserService flySysUserService;
    @Resource
    FastDfsClientComponent dfsClient;
    @Resource
    EasyExcelComponent easyExcel;

    @Value("${fastdfs.nginx-servers}")
    private String fastdfsServerUrl;

    /**
     * 获取合同列表 (分页+条件)
     *
     * @param getContractListWithPageConditionQuery 获取合同列表查询参数
     * @return 合同列表分页模型
     */
    @Override
    public GetContractListWithPageConditionVO getContractListWithPageCondition(GetContractListWithPageConditionQuery getContractListWithPageConditionQuery) {
        // 获取合同金额统计信息
        GetContractListWithPageConditionVO.ContractMoneyStatistic contractMoneyStatistic = getContractMoneyStatistic();
        // 构建分页对象
        Page<PosContractEntity> page = new Page<>(getContractListWithPageConditionQuery.getPageIndex(), getContractListWithPageConditionQuery.getPageSize());
        // 分页查询采购合同列表
        List<GetContractListWithPageConditionVO.ContractVO> list = getContractPageList(getContractListWithPageConditionQuery, page);
        // 遍历，填充字段
        fillContractPageListField(list);
        // 构造vo并返回
        return constructContractPageVO(contractMoneyStatistic, page, list);
    }

    /**
     * 获取合同详情
     *
     * @param contractId 合同ID
     * @return 合同详情vo模型
     */
    @Override
    public GetContractDetailVO getContractDetail(Integer contractId) {
        // 查询采购合同基本信息
        GetContractDetailVO result = baseMapper.getContractBaseInfoById(contractId);
        // 设置合同状态
        result.setShowStatus(PosContractEnum.statusMap.get(result.getStatus()));
        // 查询合同合计统计信息
        GetContractDetailVO.TotalStatistic totalStatistic = getContractDetailTotalStatistic(contractId);
        // 查询采购明细列表
        List<GetContractDetailVO.PurchaseDetail> purchaseDetailList = ConvertUtil.sourceToTarget(posContractListService.lambdaQuery()
                .eq(PosContractListEntity::getContractId, contractId).orderByDesc(PosContractListEntity::getCreateTime).list(), GetContractDetailVO.PurchaseDetail.class);
        // 查询付款记录列表
        List<GetContractDetailVO.PayRecord> payRecordList = baseMapper.getPayRecordListByContractId(contractId);
        // 查询收款记录列表
        List<GetContractDetailVO.InvoiceRecord> invoiceRecordList = baseMapper.getInvoiceRecordListByContractId(contractId);
        // 查询合同附件列表
        List<GetContractDetailVO.ContractFile> contractFileList = ConvertUtil.sourceToTarget(posContractFileService.lambdaQuery()
                .eq(PosContractFileEntity::getContractId, contractId).orderByDesc(PosContractFileEntity::getCreateTime).list(), GetContractDetailVO.ContractFile.class);
        // 填充合同详情vo并返回
        return fillContractDetailVO(result, totalStatistic, purchaseDetailList, payRecordList, invoiceRecordList, contractFileList);
    }

    /**
     * 获取合同清单
     *
     * @param contractId 合同id
     * @return 合同清单vo模型
     */
    @Override
    public GetContractInventoryVO getContractInventory(Integer contractId) {
        GetContractInventoryVO contractInventoryVO = new GetContractInventoryVO();
        // 获取posContractList的mapper
        BaseMapper<PosContractListEntity> mapper = posContractListService.getBaseMapper();
        // 封装查询条件为合同id相同
        QueryWrapper wrapper = new QueryWrapper();
        wrapper.eq("contract_id", contractId);
        // 通过mp获取数据库查询结果
        List list = mapper.selectList(wrapper);
        // 定义GetContractInventoryVO.TotalCount的对象，及其对象中的属性
        GetContractInventoryVO.TotalCount totalCount = new GetContractInventoryVO.TotalCount();
        Integer totalNum = 0;
        BigDecimal totalGoodsMoney = new BigDecimal("0");
        // 遍历并求和
        for (Object o : list) {
            PosContractListEntity listVO = (PosContractListEntity) o;
            BigDecimal goodsMoney = listVO.getGoodsMoney();
            totalGoodsMoney = goodsMoney.add(totalGoodsMoney);
            String num = listVO.getNum();
            int i = Integer.parseInt(num);
            totalNum += i;
        }
        String allNum = totalNum.toString();
        // 封装具体值到totalCount里面
        totalCount.setTotalNum(allNum);
        totalCount.setTotalGoodsMoney(totalGoodsMoney);
        // 封装具体值到contractInventoryVO里面
        contractInventoryVO.setList(list);
        contractInventoryVO.setTotalCount(totalCount);
        // 返回ContractInventoryVO对象
        return contractInventoryVO;
    }


    private GetContractDetailVO fillContractDetailVO(GetContractDetailVO result, GetContractDetailVO.TotalStatistic totalStatistic, List<GetContractDetailVO.PurchaseDetail> purchaseDetailList, List<GetContractDetailVO.PayRecord> payRecordList, List<GetContractDetailVO.InvoiceRecord> invoiceRecordList, List<GetContractDetailVO.ContractFile> contractFileList) {
        result.setTotalStatistic(totalStatistic);
        result.setPurchaseDetailList(purchaseDetailList);
        result.setPayRecordList(payRecordList);
        result.setInvoiceRecordList(invoiceRecordList);
        result.setContractFileList(contractFileList);
        return result;
    }

    private GetContractDetailVO.TotalStatistic getContractDetailTotalStatistic(Integer contractId) {
        // 采购明细-数量合计、小计合计统计信息
        GetContractDetailVO.TotalStatistic totalStatistic = baseMapper.getContractDetailNumMoneyStatistic(contractId);
        // 付款记录-金额合计统计信息
        totalStatistic.setPayTotalMoney(baseMapper.getPayRecordTotalMoney(contractId));
        // 收票记录-金额合计统计信息
        totalStatistic.setInvoiceTotalMoney(baseMapper.getInvoiceTotalMoney(contractId));
        return totalStatistic;
    }

    private GetContractListWithPageConditionVO constructContractPageVO(GetContractListWithPageConditionVO.ContractMoneyStatistic contractMoneyStatistic, Page<PosContractEntity> page, List<GetContractListWithPageConditionVO.ContractVO> list) {
        PageDTO<GetContractListWithPageConditionVO.ContractVO> pageDTO = new PageDTO<>();
        pageDTO.setPageIndex(page.getCurrent());
        pageDTO.setPages(page.getPages());
        pageDTO.setPageSize(page.getSize());
        pageDTO.setTotal(page.getTotal());
        pageDTO.setRows(list);
        GetContractListWithPageConditionVO result = ConvertUtil.sourceToTarget(pageDTO, GetContractListWithPageConditionVO.class);
        result.setContractMoney(contractMoneyStatistic);
        return result;
    }

    private void fillContractPageListField(List<GetContractListWithPageConditionVO.ContractVO> list) {
        list.forEach(item -> {
            // 支付状态
            item.setShowPayStatus(PosContractEnum.payStatusMap.get(item.getPayStatus()));
            // 收票状态
            item.setShowInvoiceStatus(PosContractEnum.invoiceStatusMap.get(item.getInvoiceStatus()));
            // 合同状态
            item.setShowStatus(PosContractEnum.statusMap.get(item.getStatus()));
            // 收货状态
            item.setShowReceStatus(PosContractEnum.receStatusMap.get(item.getReceStatus()));
            // 是否显示查看清单 - 已录入明细则显示
            item.setIsShowViewList(item.getReceStatus() >= 2 ? 1 : 2);
            // 是否显示录入明细 - 未录入明细则显示
            item.setIsShowEntryList(item.getReceStatus() == 1 ? 1 : 2);
            // 是否显示生成入库单 - 已录入明细但未入库 | 部分入库但没有代入库单则显示
            item.setIsShowGenerateInto(item.getReceStatus() == 2 || item.getReceStatus() == 4 ? 1 : 2);
            // 是否显示删除明细 - 已录入明细但未入库则显示
            item.setIsShowDeleteList(item.getReceStatus() == 2 ? 1 : 2);
            // 是否显示删除 - 合同状态为临时单
            item.setIsShowDelete(item.getStatus() == 1 ? 1 : 2);
            // 是否显示修改合同 - 合同状态为临时单
            item.setIsShowUpdateContract(item.getStatus() == 1 ? 1 : 2);
        });
    }

    private List<GetContractListWithPageConditionVO.ContractVO> getContractPageList(GetContractListWithPageConditionQuery getContractListWithPageConditionQuery, Page<PosContractEntity> page) {
        Date now = new Date();
        // 查询参数转化 - 起始、结束日期字符串转为yyyy-MM-dd的日期字符串
        getContractListWithPageConditionQuery.setStartDate(dateDMTOFormat(now, getContractListWithPageConditionQuery.getStartDate()));
        getContractListWithPageConditionQuery.setEndDate(dateDMTOFormat(now, getContractListWithPageConditionQuery.getEndDate()));
        return baseMapper.getContractListWithPage(page, getContractListWithPageConditionQuery);
    }

    private String dateDMTOFormat(Date now, String dateStr) {
        if (StrUtil.isEmpty(dateStr)) {
            return dateStr;
        }
        if (!dateStr.endsWith("d") && !dateStr.endsWith("m")) {
            throw new RuntimeException("日期查询参数只能以d、m结尾");
        }
        int offset = Integer.parseInt(dateStr.substring(0, dateStr.length() - 1));
        return dateStr.endsWith("d") ?
                DateUtil.format(DateUtil.offsetDay(now, -offset), "yyyy-MM-dd") :
                DateUtil.format(DateUtil.offsetMonth(now, -offset), "yyyy-MM-dd");
    }

    private GetContractListWithPageConditionVO.ContractMoneyStatistic getContractMoneyStatistic() {
        return baseMapper.getContractMoneyStatistic();
    }



    @Override
    public void updateContract(ModifyContractDTO modifyContractDTO) {
        validContractIdExist(modifyContractDTO.getContractId());
        validSupplierIdExist(modifyContractDTO.getSupplierId());
        validLinkmanIdExist(modifyContractDTO.getLinkmanId());
        validOurUserId(modifyContractDTO.getOurUserId());
        PosContractEntity posContractEntity = ConvertUtil.sourceToTarget(modifyContractDTO, PosContractEntity.class);
        baseMapper.updateById(posContractEntity);
    }

    private void validContractIdExist(Integer contractId) {
        PosContractEntity byId = getById(contractId);
        if(byId==null){
            throw new PurchaseManagementException("采购合同id不存在");
        }
    }

    private void validOurUserId(Integer ourUserId) {
        FlySysUserEntity byId = flySysUserService.getById(ourUserId);
        if(byId==null){
            throw new PurchaseManagementException("我方联系人id不存在");
        }
    }

    private void validLinkmanIdExist(Integer linkmanId) {
        SupLinkmanEntity byId = supLinkmanService.getById(linkmanId);
        if(byId==null){
            throw new PurchaseManagementException("客户联系人id不存在");
        }
    }

    private void validSupplierIdExist(Integer supplierId) {
        SupSupplierEntity byId = supSupplierService.getById(supplierId);
        if(byId==null){
            throw new PurchaseManagementException("客户id不存在");
        }
    }
    /**
     * 添加合同
     * @param addContractDTO
     */
    @Override
    public void saveContract(AddContractDTO addContractDTO)  {
        PosContractEntity posContractEntity = ConvertUtil.sourceToTarget(addContractDTO, PosContractEntity.class);
        baseMapper.insert(posContractEntity);
    }

    /**
     * 获取合同唯一编号
     * @return
     */
    @Override
    public GetContractNoVO getContractNo() {
        SimpleDateFormat df = new SimpleDateFormat("yyyyMMdd");
        String date = df.format(new Date());
        LambdaQueryWrapper<PosContractEntity> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.orderByDesc(PosContractEntity::getCreateTime)
                .last("limit 1");
        PosContractEntity one = getOne(queryWrapper);
        String contractNo=one.getContractNo();
        String substringDate = contractNo.substring(0,8);
        String substring=String.valueOf(Integer.parseInt(contractNo.substring(8))+1);
        if(!substringDate.equals(date)){
            substring= String.valueOf(0);
            substringDate=date;
        }
        String string = substringDate+substring;
        GetContractNoVO getContractNoVO = new GetContractNoVO();
        getContractNoVO.setContractNo(string);
        return getContractNoVO;
    }

    /**
     * 导出合同
     * @param contractIds 合同id集合
     * @return
     */
    @Override
    public ExportContractVO exportContract(List<Integer> contractIds) throws Exception {
        //判断合同id集合是否为空
        if(CollectionUtil.isEmpty(contractIds)){
            throw new RuntimeException("合同id集合不能为");
        }
        QueryWrapper queryWrapper=new QueryWrapper();
        queryWrapper.in("contract_id",contractIds);
        List<PosContractEntity> list = baseMapper.selectList(queryWrapper);

        List<PosContractExcel> listExcel=new ArrayList<>();

        //遍历获取合同实体类
        for (PosContractEntity posContractEntity : list) {
            //获取合同实体类中supplier_id
            Integer supplierId = posContractEntity.getSupplierId();
            SupSupplierEntity supSupplierEntity = supSupplierService.getById(supplierId);
            //获取供应商的名字
            String supplierName = supSupplierEntity.getName();
            //将实体类转换为导出报表实体类
            PosContractExcel posContractExcel = ConvertUtil.sourceToTarget(posContractEntity, PosContractExcel.class);
            posContractExcel.setSupplierName(supplierName);
            //将转化的导出报表实体类加入集合
            listExcel.add(posContractExcel);
        }

        //导出数据
        ByteArrayOutputStream out=new ByteArrayOutputStream();
        easyExcel.export("采购合同报表",out,PosContractExcel.class,listExcel);

        //上传报表
        FastDfsFileInfo uploadInfo = dfsClient.uploadFile(out.toByteArray(), "xlsx");
        out.close();
        //获取文件地址并返回
        String url = dfsClient.fetchUrl(uploadInfo, fastdfsServerUrl, true);
        //构建VO并返回
        ExportContractVO exportContractVO=new ExportContractVO();
        exportContractVO.setUrl(url);
        return exportContractVO;
    }

    /**
     * 下拉列表-获取采购合同内容
     * @param dto
     * @return
     */
    @Override
    public ContractSelectDTO selectContract(SelectContractDTO dto) {
        //采购合同标题为空传所有
        ContractSelectDTO result = new ContractSelectDTO();
        if (StringUtils.isBlank(dto.getTitle())){
            List<PosContractEntity> contracts = list(new QueryWrapper<PosContractEntity>().eq("supplier_id", dto.getSupplierId()).lt("pay_status",3));
            result.setContracts(convertList(contracts));
        }else{
            List<PosContractEntity> contracts = list(new QueryWrapper<PosContractEntity>().eq("supplier_id", dto.getSupplierId()).like("title",dto.getTitle()).lt("pay_status",3));
            result.setContracts(convertList(contracts));
        }
        return result;
    }

    public static List<BasePosContractVO> convertList(List<PosContractEntity> contractEntities) {
        List<BasePosContractVO> baseContracts = new ArrayList<>();
        for (PosContractEntity contractEntity : contractEntities) {
            BasePosContractVO baseContract = new BasePosContractVO();
            BeanUtils.copyProperties(contractEntity,baseContract);
            baseContracts.add(baseContract);
        }
        return baseContracts;
    }
}
