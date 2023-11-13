package com.zeroone.star.ownerindex.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.ownerindex.entity.User;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;
import org.apache.xmlbeans.impl.xb.xsdschema.Public;

import java.security.PublicKey;
import java.util.ArrayList;
import java.util.List;


@Mapper
public interface UserMapper extends BaseMapper<User> {


    @Select("SELECT password FROM fly_sys_user WHERE id = #{id}")
    public String SelectPwdById(Integer id);

    @Update("UPDATE fly_sys_user SET password = #{newPwd} WHERE id = #{id}")
    public Boolean modifyPwdById(@Param("id") Integer id, @Param("newPwd")String newPwd);



    @Select("SELECT id FROM fly_sys_user WHERE deptID = #{deptId}")
    List<Integer> getDeptUserIdList(@Param("deptId")Integer deptId);
    
}
