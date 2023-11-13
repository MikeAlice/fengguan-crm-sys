#include "stdafx.h"
#include "Out_boundService.h"
#include "dao/out_bound/Out_boundDAO.h"
#include "Macros.h"


// ȷ�ϳ��⣨�޸ĳ���״̬�� �����ˣ�ǧ��
uint64_t Out_boundService::updateData(const ConfOut_boundDTO::Wrapper& dto)
{
    // ��װDO����
    Out_boundDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Out_id, out_id, Out_user_id, out_user_id);
    Out_boundDAO dao;
    return dao.update(data);
}

// ɾ�����ⵥ��ͨ�����ⵥIDɾ�����ݣ� �����ˣ�ǧ��
uint64_t Out_boundService::removeData(const oatpp::List<DelOut_boundDTO::Wrapper>& dto)
{
    Out_boundDAO dao;
    return dao.removeData(dto);
}
