package com.zeroone.star.project.j1.systemindex;

import com.zeroone.star.project.dto.j1.systemmanagement.FlySysMethodDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface FlySysMethodApis {
    /**
     *
     * @param flySysMethodDTO
     * @return
     */
    public JsonVO<Boolean> DeleteMethod(FlySysMethodDTO flySysMethodDTO);
}
