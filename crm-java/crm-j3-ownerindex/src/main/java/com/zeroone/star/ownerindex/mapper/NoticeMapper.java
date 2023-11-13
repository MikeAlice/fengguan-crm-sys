package com.zeroone.star.ownerindex.mapper;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.core.toolkit.Constants;
import com.zeroone.star.ownerindex.entity.Notice;
import com.zeroone.star.project.vo.j3.ownerindex.GetNoticeVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;


import java.util.List;


@Mapper
public interface NoticeMapper extends BaseMapper<Notice> {


    @Override
    <P extends IPage<Notice>> P selectPage(P page, @Param(Constants.WRAPPER)Wrapper<Notice> queryWrapper);

    @Select("SELECT title,content FROM fly_sys_user_notice WHERE id = #{id}")
    GetNoticeVO selectNotice(Integer id);

    @Select("SELECT count(id) FROM fly_sys_user_notice")
    Long count();




}
