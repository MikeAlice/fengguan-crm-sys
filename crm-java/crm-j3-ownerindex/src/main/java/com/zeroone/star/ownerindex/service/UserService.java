package com.zeroone.star.ownerindex.service;


import com.zeroone.star.project.dto.j3.ownerindex.ModifyOwnerInfoDTO;
import com.zeroone.star.project.dto.j3.ownerindex.ModifyPwdDTO;

public interface UserService {

    public Boolean modifyPassword(ModifyPwdDTO dto) throws Exception;

    public Boolean modifyOwnerInfo(ModifyOwnerInfoDTO dto) throws Exception;


}
