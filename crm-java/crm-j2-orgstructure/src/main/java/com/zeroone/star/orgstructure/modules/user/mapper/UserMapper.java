package com.zeroone.star.orgstructure.modules.user.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.orgstructure.modules.user.entity.UserEntity;
import com.zeroone.star.orgstructure.modules.user.excel.UserExcel;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 * 系统用户表 Mapper 接口
 * </p>
 *
 * @author j2
 * @since 2023-10-19
 */
@Mapper
public interface UserMapper extends BaseMapper<UserEntity> {

    List<UserExcel> getUserExcelListByIds(@Param("userIdList") List<Integer> userIdList);
}
