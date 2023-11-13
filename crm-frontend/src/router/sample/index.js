/*
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-20 17:30:31
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-10-22 22:06:11
 * @FilePath: \zero-one-crmsys\crm-frontend\src\router\sample\index.js
 * @Description:
 *
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved.
 */
const routes = [
  {
    path: '/sample',
    name: 'Sample',
    meta: {
      text: '样本'
    },
    redirect: { path: '/sample/file' },
    component: () => import('@/views/sample/SampleView.vue'),
    children: [
      {
        path: '/sample/file',
        component: () => import('@/views/sample/file/FileUpload.vue'),
        meta: {
          text: '文件上传'
        }
      },
      {
        path: '/sample/excel',
        component: () => import('@/views/sample/excel/Excel.vue'),
        meta: {
          text: 'Excel演示'
        }
      },
      {
        path: '/sample/print',
        component: () => import('@/views/sample/print/Print.vue'),
        meta: {
          text: '打印演示'
        }
      },
      {
        path: '/sample/editor',
        component: () => import('@/views/sample/editor/Editor.vue'),
        meta: {
          text: '富文本框演示'
        }
      },
      {
        path: '/sample/test',
        component: () => import('@/views/sample/TestView.vue'),
        meta: {
          text: '测试专用1'
        }
      },
      {
        path: '/sample/test1',
        component: () => import('@/views/sample/TestView1.vue'),
        meta: {
          text: '测试专用2'
        }
      },
      {
        path: '/sample/test2',
        component: () => import('@/views/sample/TestView2.vue'),
        meta: {
          text: '测试专用3'
        }
      },
      // 销售图表展示的临时路由，后期会删除
      {
        path: '/sample/chartDemo',
        component: () => import('@/views/sample/chartDemo/ChartDemo.vue')
      },
      {
        path: '/sample/newsCenter',
        component: () => import('@/views/sample/newsCenter/NewsCenterView.vue')
      },
      // table 表格组件开发时用例测试路由，后期会删除
      {
        path: '/sample/table',
        component: () => import('@/views/sample/table/TableText.vue')
      },
      {
        path: '/sample/testTable',
        component: () => import('@/views/sample/orgStructure/testTable.vue')
      },
      {
        path: '/sample/testEditor',
        component: () => import('@/components/Editor/index.vue')
      },
      // treemenu 菜单组件开发时用例测试路由，后期会删除
      {
        path: '/sample/treemenu',
        component: () => import('@/views/sample/TreeMenu_demo/TreeMenu.vue')
      },
      {
        path: '/sample/customChartTest',
        component: () => import('@/views/sample/CustomChartTest.vue')
      },
      {
        path: '/sample/bulkOpe',
        component: () => import('@/views/sample/BlukOpeTest.vue')
      },
      {
        path: '/sample/TreeTest',
        component: () => import('@/components/Tree/TreeTestView.vue')
      }
    ]
  }
]

export default routes
