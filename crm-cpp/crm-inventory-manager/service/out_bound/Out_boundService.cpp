#include "stdafx.h"
#include "Out_boundService.h"
#include "dao/out_bound/Out_boundDAO.h"
#include "Macros.h"


// 确认出库（修改出库状态） 负责人：千亿
uint64_t Out_boundService::updateData(const ConfOut_boundDTO::Wrapper& dto)
{
    // 组装DO数据
    Out_boundDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Out_id, out_id, Out_user_id, out_user_id);
    Out_boundDAO dao;
    return dao.update(data);
}

// 删除出库单（通过出库单ID删除数据） 负责人：千亿
uint64_t Out_boundService::removeData(const oatpp::List<DelOut_boundDTO::Wrapper>& dto)
{
    Out_boundDAO dao;
    return dao.removeData(dto);
}
