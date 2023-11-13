/*
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-31 21:47:07
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-11-09 23:16:37
 * @FilePath: \zero-one-crmsys\crm-frontend\src\apis\sysManage\menu.js
 * @Description:
 *
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved.
 */
import Request from '../request'

// const getSysMenuTree = (data, success, fail) => {
//   Request.requestForm(Request.GET, baseUrl + '/tree')
//     .then((data) => {
//       if (data.data) {
//         success()
//         return
//       }
//       fail()
//     })
//     .catch((err) => {
//       console.warn(err)
//       fail()
//     })
// }

const getSysMenuTree = () => {
  return Request.requestForm(Request.GET, '/menu/tree')
}

//目前要求传一个id
const getMenuList = (id) => {
  return Request.requestForm(Request.GET, `/menu/${id}`)
}
const addMenu = (data) => {
  return Request.requestJson(
    Request.POST,
    '/systemmanagement/fly-sys-menu/add',
    data
  )
}

//删除菜单和子菜单，但现在只能传id
const deleteMenu = (id) => {
  return Request.requestForm(
    Request.DELETE,
    `/systemmanagement/fly-sys-menu/delete/${id}`
  )
}

const updateMenu = (data) => {
  return Request.requestJson(
    Request.PUT,
    '/systemmanagement/fly-sys-menu/update',
    data
  )
}

export { getSysMenuTree, addMenu, deleteMenu, updateMenu, getMenuList }
