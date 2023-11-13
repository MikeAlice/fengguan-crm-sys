/*
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-29 13:05:59
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-11-10 16:37:05
 * @FilePath: \zero-one-crmsys\crm-frontend\src\stores\sysManage\menu.js
 * @Description:
 *
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved.
 */
import { defineStore } from 'pinia'
import {
  getSysMenuTree,
  getMenuList,
  addMenu,
  updateMenu,
  deleteMenu
} from '@/apis/sysManage/menu.js'
const useSysMenu = defineStore('sysmenu', {
  state: () => ({
    sendData: {
      tableColumnAttribute: [
        {
          prop: 'name',
          label: '菜单名称'
        },
        {
          prop: 'nameEn',
          label: '菜单英文名称'
        },
        {
          prop: 'url',
          label: '菜单路径'
        }
        // {
        //   prop: 'shifouqiyong',
        //   label: '启用',
        //   useSwitch: true
        // }
      ],
      tableData: [],
      useDropdownMenu: false,
      useSelectColumn: false,
      useHeader: false,
      usePagination: false,
      //在树形菜单里显示
      title: ''
    },
    sendTreeData: [],
    parentids: []
  }),

  actions: {
    //通过调用此函数改变store数据
    async getSysMenuTree() {
      const res = await getSysMenuTree().catch((e) => e)
      console.log(res.data)
      // this.sendTreeData = res.data.children
      function convertTreeData(treeData) {
        if (!treeData || !Array.isArray(treeData)) {
          return []
        }

        return treeData.map((node) => {
          const newNode = {
            id: node.id,
            label: node.name,
            value: node.id, // 新增 value 属性，值为 id
            children: convertTreeData(node.children)
          }
          return newNode
        })
      }
      this.sendTreeData = convertTreeData(res.data.children)
      console.log('sendTreeData', this.sendTreeData)
    },
    async getMenuList(id) {
      const res = await getMenuList(id).catch((e) => e)
      this.sendData.tableData = res.data
    },
    async getDropMenu(id) {
      const res = await getMenuList(id).catch((e) => e)
      this.sendData.parentids = res.data
    },
    async addMenu(data) {
      const res = await addMenu(data)
      return res
    },
    async updateMenu(data) {
      const res = await updateMenu(data)
      return res
    },
    async deleteMenu(id) {
      const res = await deleteMenu(id)
      return res
    }
  }
})

export default useSysMenu
