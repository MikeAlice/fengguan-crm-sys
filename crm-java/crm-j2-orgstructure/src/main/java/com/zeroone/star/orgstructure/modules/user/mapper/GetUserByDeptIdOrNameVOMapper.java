package com.zeroone.star.orgstructure.modules.user.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.j2.orgstructure.user.GetUserByDeptIdOrNameQuery;
import com.zeroone.star.project.vo.j2.orgstructure.user.GetUserByDeptIdOrNameVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * <p>
 * 用户表,角色表,职位表,部门表四表联查 Mapper 接口
 * </p>
 *
 * @author 礼拜一
 * @since 2023-10-21
 */
@Mapper
public interface GetUserByDeptIdOrNameVOMapper {
    Page<GetUserByDeptIdOrNameVO> selectAll(Page<GetUserByDeptIdOrNameQuery> page, @Param("query") GetUserByDeptIdOrNameQuery query);
}
