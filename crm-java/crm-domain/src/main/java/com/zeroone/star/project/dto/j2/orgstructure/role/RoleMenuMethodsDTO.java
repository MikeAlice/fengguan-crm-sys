package com.zeroone.star.project.dto.j2.orgstructure.role;/**
 * @author muzili
 * @create 2023-10-18:49}
 */

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * @programName: com.zeroone.star.project.vo.j2.orgstructure.role
 * @ClassName:RoleMenuMethodsVO
 * @Description TODO
 * @Author: Muzi
 * @Create: 2023/10/24 0024 18:49
 **/
@Data
@ApiModel("角色-权限-系统方法请求体参数")
public class RoleMenuMethodsDTO {

    @ApiModelProperty(value = "角色ID")
    private Integer orderId;
    @ApiModelProperty(value = "选中的菜单权限ID集合")
    private List<Integer> menuID;
    @ApiModelProperty(value = "选中的系统方法ID集合")
    private List<Integer> methodID;
}
