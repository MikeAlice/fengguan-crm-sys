package com.zeroone.star.oauth2.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.oauth2.entity.FlySysUser;
import org.apache.ibatis.annotations.Mapper;

/**
 * @author SleepyHead
 * @description 针对表【fly_sys_user(系统用户表)】的数据库操作Mapper
 * @createDate 2023-10-21 17:26:54
 * @Entity generator.domain.FlySysUser
 */
@Mapper
public interface FlySysUserMapper extends BaseMapper<FlySysUser> {

}
