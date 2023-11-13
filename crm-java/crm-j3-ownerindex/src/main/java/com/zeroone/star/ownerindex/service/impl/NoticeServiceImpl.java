package com.zeroone.star.ownerindex.service.impl;

import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.ownerindex.entity.SysUser;
import com.zeroone.star.ownerindex.entity.Notice;
import com.zeroone.star.ownerindex.entity.User;
import com.zeroone.star.ownerindex.mapper.SysUserMapper;
import com.zeroone.star.ownerindex.mapper.NoticeMapper;
import com.zeroone.star.ownerindex.mapper.UserMapper;
import com.zeroone.star.ownerindex.service.NoticeService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.ArrayDTO;
import com.zeroone.star.project.dto.j3.ownerindex.AddNoticeDTO;
import com.zeroone.star.project.dto.j3.ownerindex.QueryNoticeDTO;
import com.zeroone.star.project.query.j3.ownerindex.SearchNoticeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.ownerindex.GetNoticeVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * @Description: 实现类
 * @Author: your name
 * @Date: 2023/10/24 17:28
 */
@Service
public class NoticeServiceImpl implements NoticeService {

    @Autowired
    private NoticeMapper noticeMapper;

    @Autowired
    private UserMapper userMapper;

    @Autowired
    private UserHolder userHolder;

    @Override
    public PageDTO<QueryNoticeDTO> listNotice(SearchNoticeQuery searchNoticeQuery) throws Exception {
        UserDTO currentUser = userHolder.getCurrentUser();
        //创建动态条件构造器
        QueryWrapper<Notice> noticeQueryWrapper = new QueryWrapper<>();
        //文章标题
        String title = searchNoticeQuery.getTitle();
        //文章内容
        String content = searchNoticeQuery.getContent();
        //日期
//        DateTime createTime = searchNoticeQuery.getCreateTime();
//        if (title == null ){
//            title = "";
//        }else if (content == null) {
//            content = "";
//        }

        //当前需要查询的页码
        long pageIndex = searchNoticeQuery.getPageIndex();
        //每页记录的数据
        long pageSize = searchNoticeQuery.getPageSize();
        //创建页码
        Page<Notice> page = new Page<>(
                pageIndex,pageSize
        );
       //wapper语句
        noticeQueryWrapper.eq("owner_user_id",currentUser.getId());
        if (title != null){
            noticeQueryWrapper.like("title",title);
        }
        if (content != null){
            noticeQueryWrapper.like("content",content);
        }
//                .nested(qw->qw.isNotNull("create_time").
//                        eq("create_time",searchNoticeQuery.getCreateTime()));
        Page<Notice> noticePage = noticeMapper.selectPage(page, noticeQueryWrapper);
        //转化为list
        ArrayList<QueryNoticeDTO> list = new ArrayList<>();
        List<Notice> records = noticePage.getRecords();
        for (Notice record : records) {
            Notice notice = new Notice();
            list.add(notice.transition(record));
        }
        //获取总数
        Long count = noticeMapper.count();

        PageDTO<QueryNoticeDTO> dtoPageDTO = new PageDTO<>();

        dtoPageDTO.setTotal(noticeMapper.count());
        dtoPageDTO.setRows(list);
        dtoPageDTO.setTotal(count);
        dtoPageDTO.setPages(noticePage.getPages());
        dtoPageDTO.setPageSize(noticePage.getSize());
        dtoPageDTO.setPageIndex(pageIndex);
        return dtoPageDTO;
    }

    @Override
    public int addNotice(AddNoticeDTO addNoticeDTO) throws Exception {
        UserDTO currentUser = userHolder.getCurrentUser();
        Integer holderId = currentUser.getId();
//        //确定当前时间
//        addNoticeDTO.setCreateTime(DateTime.now());
//        //标记未读
//        addNoticeDTO.setStatus(-1);
        //两者皆为空的情况
        if (addNoticeDTO.getOwnerDeptId() == 0 && addNoticeDTO.getOwnerUserId() == 0)
            return -1;
        //接收部门的id
        Integer ownerDeptId = addNoticeDTO.getOwnerDeptId();
//        QueryWrapper<SysUser> wrapper = new QueryWrapper<>();
//        wrapper.eq("dept_id",ownerDeptId);
//        List<SysUser> sysUserList = sysUserMapper.selectList(wrapper);
        //将员工id全部提取出来

        List<Integer> userIdList = userMapper.getDeptUserIdList(ownerDeptId);
//        List<Integer> userIdList = sysUserList.stream().
//                map(SysUser::getId)
//                .collect(Collectors.toList());
        if (addNoticeDTO.getOwnerUserId() != null)
            userIdList.add(addNoticeDTO.getOwnerUserId());
        //批量添加
        for (Integer userId : userIdList){
            Notice tmpNotice = new Notice().reTransition(addNoticeDTO);
            tmpNotice.setCreateUserId(holderId);
            tmpNotice.setOwnerUserId(userId);
            tmpNotice.setCreateTime(DateTime.now());
            noticeMapper.insert(tmpNotice);
        }
        return userIdList.size();
    }


    @Override
    public Boolean updateNotice(ArrayDTO dto) {
        for (Integer id : dto.getIds()) {
            Notice notice = new Notice(id, 1);
            noticeMapper.updateById(notice);
        }
        return true;
    }

    /*根据id查询公告详情*/
    @Override
    public GetNoticeVO getNoticeById(Integer id) {
        GetNoticeVO noticeVO = noticeMapper.selectNotice(id);
        return noticeVO;
    }

    /*删除公告*/
    @Override
    public void deleteById(ArrayDTO dto) {
        for (Integer id : dto.getIds()) {
            noticeMapper.deleteById(id);
        }
    }


}
