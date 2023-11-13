package com.zeroone.star.systemmanagement.controller;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtDTO;
import com.zeroone.star.project.dto.j1.systemmanagement.CstFieldExtplusDTO;
import com.zeroone.star.project.j1.systemmanagement.CstFieldExtplusApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.systemmanagement.CstFieldExtplusUpdateVO;
import com.zeroone.star.project.vo.j1.systemmanagement.CstFieldExtplusVO;
import com.zeroone.star.systemmanagement.entity.CstFieldExt;
import com.zeroone.star.systemmanagement.service.CstFieldExtplusService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.apache.ibatis.annotations.Param;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;
import java.util.*;

@RestController
@RequestMapping("/CstPlus")
@Api(tags = "cst-field-ext")
public class CstFieldExtplusController implements CstFieldExtplusApis {
    @Autowired
    CstFieldExtplusService cstFieldExtplusService;

    @ApiOperation(value = "获取字段类型")
    @GetMapping("/gettype")
    public JsonVO<CstFieldExtplusVO> getFieldType(CstFieldExtplusDTO cstFieldExtplusDTO){
        System.out.println("field_ext_id:"+cstFieldExtplusDTO);
        QueryWrapper<CstFieldExt> wr= new QueryWrapper<>();
        wr.eq("field_ext_id",cstFieldExtplusDTO.getFieldExtId());
        CstFieldExt csv=cstFieldExtplusService.getOne(wr,false);
        CstFieldExtplusVO cstFieldExtplusVO=BeanUtil.copyProperties(csv,CstFieldExtplusVO.class);
        return JsonVO.success(cstFieldExtplusVO);
    }


    @PutMapping("/update")
    public JsonVO<List<CstFieldExtplusUpdateVO>> updateField(@RequestBody List<CstFieldExtplusDTO> cstFieldExtplusDTOList){
        int i=0;
        List<CstFieldExtplusUpdateVO> list=new ArrayList<>();
        while(i<cstFieldExtplusDTOList.size()){
            Map<String,String> extField=cstFieldExtplusDTOList.get(i).getExtField();
            Set keyset=extField.keySet();
            Iterator it=keyset.iterator();
            UpdateWrapper<CstFieldExt> wr=new UpdateWrapper<>();
            while(it.hasNext()){
                String key= (String) it.next();
                String value=(String)extField.get(key);
                wr.set(key,value).eq("field_ext_id",cstFieldExtplusDTOList.get(i).getFieldExtId());
                cstFieldExtplusService.update(wr);
            }
             QueryWrapper<CstFieldExt> wrp= new QueryWrapper<>();
             wrp.eq("field_ext_id",cstFieldExtplusDTOList.get(i).getFieldExtId());
             CstFieldExt cstFieldExt=cstFieldExtplusService.getOne(wrp);
             list.add(BeanUtil.copyProperties(cstFieldExt,CstFieldExtplusUpdateVO.class));
             i++;
        }
        return JsonVO.success(list);
    }
}
