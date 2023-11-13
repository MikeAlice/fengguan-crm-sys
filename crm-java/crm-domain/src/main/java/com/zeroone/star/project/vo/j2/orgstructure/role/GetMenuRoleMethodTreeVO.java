package com.zeroone.star.project.vo.j2.orgstructure.role;/**
 * @author muzili
 * @create 2023-10-18:57}
 */

import com.zeroone.star.project.vo.j2.orgstructure.role.base.BaseMenuVO;
import com.zeroone.star.project.vo.j2.orgstructure.role.base.BaseMethodVO;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * @programName: com.zeroone.star.project.vo.j2.orgstructure.role
 * @ClassName:GetMenuRoleMethodTreeVO
 * @Description TODO
 * @Author: Muzi
 * @Create: 2023/10/21 0021 18:57
 **/
@Data
public class GetMenuRoleMethodTreeVO extends BaseMenuVO {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "层级")
    private Integer level;
    @ApiModelProperty(value = "类型（0-非最后一级菜单 1-最后一级菜单）")
    private Integer type;
    @ApiModelProperty(value = "选中状态（0-未选中 1-选中）")
    private Integer selectState;
    @ApiModelProperty(value = "子节点")
    private List<GetMenuRoleMethodTreeVO> nodes;
    @ApiModelProperty(value = "最后一级菜单可能含有子节点")
    private List<SysMethodVo> sysMethodVoList;


    @Data
    public static class SysMethodVo extends BaseMethodVO{

        private static final long serialVersionUID = 1L;

        @ApiModelProperty(value = "选中状态：0=未选中；1=选中")
        private Integer selectState;
    }


}
