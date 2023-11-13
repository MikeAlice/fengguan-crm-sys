package com.zeroone.star.project.j3.ownerindex;

import com.zeroone.star.project.dto.j3.ownerindex.ModifyOwnerInfoDTO;
import com.zeroone.star.project.dto.j3.ownerindex.ModifyPwdDTO;
import com.zeroone.star.project.vo.JsonVO;

/***
 *@Description: 个人信息操作相关接口定义
 *@Param:
 *@Return:
 *@author: 4.5
 *@DateTime: 2023/10/20 19:54
 */
public interface OwnerInfoApis {

    /***
     *@Description: 修改用户密码接口
     *@Param: [com.zeroone.star.project.dto.j3.ownerindex.ModifyPwdDTO]
     *@Return: com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     *@author: 4.5
     *@DateTime: 2023/10/20 19:55
     * 已完成
     */
    JsonVO<Boolean> modifyPassword(ModifyPwdDTO dto) throws Exception;

    /***
     *@Description: 编辑个人信息接口
     *@Param: [com.zeroone.star.project.dto.j3.ownerindex.ModifyOwnerInfoDTO]
     *@Return: com.zeroone.star.project.vo.JsonVO<java.lang.Boolean>
     *@author: 4.5
     *@DateTime: 2023/10/20 21:26
     * 已完成
     */
    JsonVO<Boolean> modifyOwnerInfo(ModifyOwnerInfoDTO dto) throws Exception;
}
