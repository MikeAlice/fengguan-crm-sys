USE `zocrm_sys`;

-- 栏目数据
-- ----------------------------
-- Records of fly_sys_menu
-- ----------------------------
INSERT INTO `fly_sys_menu` VALUES (1, '系统管理', 'SystemManage', 'cogs', 0, 1, 1, '');
INSERT INTO `fly_sys_menu` VALUES (2, '客户管理', 'Customer', 'user', 0, 20, 1, '');
INSERT INTO `fly_sys_menu` VALUES (3, '统计分析', '', 'line-chart', 0, 50, 1, '');
INSERT INTO `fly_sys_menu` VALUES (4, '系统设置', '', '#', 1, 11, 1, '');
INSERT INTO `fly_sys_menu` VALUES (5, '组织结构', '', '#', 1, 12, 1, '');
INSERT INTO `fly_sys_menu` VALUES (6, '商品管理', '', 'goods', 1, 13, 1, '');
INSERT INTO `fly_sys_menu` VALUES (7, '数据字典', '', '#', 1, 13, 1, '');
INSERT INTO `fly_sys_menu` VALUES (8, '消息通知', '', '/sysmanage/Message/message_show/', 4, 116, 1, '');
INSERT INTO `fly_sys_menu` VALUES (9, '销售管理', '', 'sal', 2, 22, 0, '');
INSERT INTO `fly_sys_menu` VALUES (10, '采购合同统计', '', '/erp/ChartPurchase/chart_purchase_show/', 3, 23, 1, '');
INSERT INTO `fly_sys_menu` VALUES (11, '公共客户', '', '/crm/CstCustomerComm/cst_customer_comm_show/', 2, 213, 1, '');
INSERT INTO `fly_sys_menu` VALUES (12, '供应商管理', '', 'users', 0, 31, 1, '');
INSERT INTO `fly_sys_menu` VALUES (13, '采购管理', '', 'ship', 0, 32, 1, '');
INSERT INTO `fly_sys_menu` VALUES (14, '库存管理', 'kucun', 'cube', 0, 40, 1, '');
INSERT INTO `fly_sys_menu` VALUES (15, '系统参数', 'system', '/sysmanage/SysConfig/sys_config/', 4, 111, 1, '');
INSERT INTO `fly_sys_menu` VALUES (16, '系统菜单', '', '/sysmanage/Menu/menu_show/', 4, 112, 1, '');
INSERT INTO `fly_sys_menu` VALUES (17, '密码修改', 'serial', '/sysmanage/Sys/sys_password_modify/', 4, 113, 1, '');
INSERT INTO `fly_sys_menu` VALUES (18, '商品规格', 'system log', '/goods/GoodsSpec/goods_spec_show/', 6, 136, 1, '');
INSERT INTO `fly_sys_menu` VALUES (19, '数据库管理', 'database', '/sysmanage/SysData/sys_data/', 4, 115, 1, '');
INSERT INTO `fly_sys_menu` VALUES (20, '系统升级', '#', '/sysmanage/Sys/sys_upgrade/', 4, 115, 1, '');
INSERT INTO `fly_sys_menu` VALUES (21, '部门管理', '', '/sysmanage/Dept/dept_show/', 5, 115, 1, '');
INSERT INTO `fly_sys_menu` VALUES (22, '岗位管理', '', '/sysmanage/Position/position_show/', 5, 122, 1, '');
INSERT INTO `fly_sys_menu` VALUES (23, '角色管理', 'Role Management', '/sysmanage/Role/role_show/', 5, 122, 1, '');
INSERT INTO `fly_sys_menu` VALUES (24, '用户管理', 'Sys User Management', '/sysmanage/User/user_show/', 5, 124, 1, '');
INSERT INTO `fly_sys_menu` VALUES (25, '商品维护', 'product_dict', '/goods/Goods/goods_show/', 6, 131, 1, '');
INSERT INTO `fly_sys_menu` VALUES (26, '商品分类', '', '/goods/GoodsCategory/goods_category_show/', 6, 134, 1, '');
INSERT INTO `fly_sys_menu` VALUES (27, '商品品牌', 'ProductType', '/goods/GoodsBrand/goods_brand_show/', 6, 133, 1, '');
INSERT INTO `fly_sys_menu` VALUES (28, '商品类型', '', '/goods/GoodsAttr/goods_attr_show/', 6, 135, 1, '');
INSERT INTO `fly_sys_menu` VALUES (29, '字典管理', '', '/crm/CstDict/cst_dict_show/', 7, 141, 1, '');
INSERT INTO `fly_sys_menu` VALUES (30, '仓库管理', '', '/erp/StockStore/stock_store_show/', 1, 142, 1, '');
INSERT INTO `fly_sys_menu` VALUES (31, '经济类型', '', '/crm/CstDict/cst_dict_show/type/ecotype/', 7, 143, 0, '');
INSERT INTO `fly_sys_menu` VALUES (32, '客户来源', '', '/crm/CstDict/cst_dict_show/type/source/', 7, 144, 0, '');
INSERT INTO `fly_sys_menu` VALUES (33, '销售方式', '', '/crm/CstDict/cst_dict_show/type/salemode/', 7, 145, 0, '');
INSERT INTO `fly_sys_menu` VALUES (34, '销售阶段', '', '/crm/CstDict/cst_dict_show/type/salestage/', 7, 146, 0, '');
INSERT INTO `fly_sys_menu` VALUES (35, '服务类型', 'Service Type', '/crm/CstDict/cst_dict_show/type/services/', 7, 147, 0, '');
INSERT INTO `fly_sys_menu` VALUES (36, '服务方式', '', '/crm/CstDict/cst_dict_show/type/servicesmodel/', 7, 148, 0, '');
INSERT INTO `fly_sys_menu` VALUES (37, '我的客户', 'Customer List', '/crm/CstCustomer/cst_customer_show/', 2, 211, 1, '');
INSERT INTO `fly_sys_menu` VALUES (38, '客户联系人', 'Customer Linkman', '/crm/CstLinkman/cst_linkman_show/', 2, 214, 1, '');
INSERT INTO `fly_sys_menu` VALUES (39, '公告通知', '#', '/sysmanage/Notice/notice_show/', 1, 213, 1, '');
INSERT INTO `fly_sys_menu` VALUES (40, '服务记录', 'Service', '/crm/CstService/cst_service_show/', 2, 215, 1, '');
INSERT INTO `fly_sys_menu` VALUES (41, '地区管理', '#', '/sysmanage/Area/area_show/', 1, 215, 1, '');
INSERT INTO `fly_sys_menu` VALUES (42, '销售机会', '', '/crm/CstChance/cst_chance_show/', 2, 221, 1, '');
INSERT INTO `fly_sys_menu` VALUES (43, '跟踪记录', '', '/crm/CstTrace/cst_trace_show/', 2, 222, 1, '');
INSERT INTO `fly_sys_menu` VALUES (44, '产品报价', '', '/crm/CstQuoted/cst_quoted_show/', 9, 223, 0, '');
INSERT INTO `fly_sys_menu` VALUES (45, '项目报备', '', '/crm/CstFiling/cst_filing_show/', 9, 224, 0, '');
INSERT INTO `fly_sys_menu` VALUES (46, '销售合同', 'sale contract', '/crm/SalContract/sal_contract_show/', 2, 231, 1, '');
INSERT INTO `fly_sys_menu` VALUES (47, '多维度统计', 'Contract', '/erp/ChartDime/chart_dime_show/', 3, 232, 1, '');
INSERT INTO `fly_sys_menu` VALUES (48, '销售合同统计', 'Contact', '/erp/ChartSale/chart_sale_show/', 3, 233, 1, '');
INSERT INTO `fly_sys_menu` VALUES (49, '字段扩展', 'Sale order', '/crm/CstFieldExt/cst_field_ext_show/', 1, 241, 1, '');
INSERT INTO `fly_sys_menu` VALUES (50, '下属客户', 'Order Sale', '/crm/CstCustomerDept/cst_customer_dept_show/', 2, 212, 1, '');
INSERT INTO `fly_sys_menu` VALUES (51, '供应商列表', 'Supplier', '/erp/SupSupplier/sup_supplier_show/', 12, 311, 1, '');
INSERT INTO `fly_sys_menu` VALUES (52, '供应商联系人', '', '/erp/SupLinkman/sup_linkman_show/', 12, 312, 1, '');
INSERT INTO `fly_sys_menu` VALUES (53, '商品SKU', '', '/goods/GoodsSku/goods_sku_show/', 6, 132, 1, '');
INSERT INTO `fly_sys_menu` VALUES (54, '采购订单', 'POS', '/erp/PosContract/pos_contract_show/', 13, 321, 1, '');
INSERT INTO `fly_sys_menu` VALUES (55, '采购明细', 'POS Detail', '/erp/PosContractList/pos_contract_list_show/', 13, 322, 1, '');
INSERT INTO `fly_sys_menu` VALUES (56, '库存清单', '', '/erp/StockGoodsSku/stock_goods_sku_show//', 14, 331, 1, '');
INSERT INTO `fly_sys_menu` VALUES (57, '入库单', '', '/erp/StockInto/stock_into_show/', 14, 332, 1, '');
INSERT INTO `fly_sys_menu` VALUES (58, '入库明细', '', '/erp/StockIntoList/stock_into_list_show/', 14, 333, 1, '');
INSERT INTO `fly_sys_menu` VALUES (59, '出库单', '', '/erp/StockOut/stock_out_show/', 14, 334, 1, '');
INSERT INTO `fly_sys_menu` VALUES (60, '出库明细', '', '/erp/StockOutList/stock_out_list_show/', 14, 335, 1, '');
INSERT INTO `fly_sys_menu` VALUES (61, '系统方法', 'System Model', '/sysmanage/Method/method_show/', 4, 112, 1, '');
INSERT INTO `fly_sys_menu` VALUES (63, '财务管理', 'Finace', 'money', 0, 60, 1, '');
INSERT INTO `fly_sys_menu` VALUES (64, '资金注入抽取', '统计分析', '/erp/FinCapitalRecord/fin_capital_record_show/', 63, 41, 1, '');
INSERT INTO `fly_sys_menu` VALUES (65, '财务类型', '财务类型', 'finance', 1, 42, 1, '');
INSERT INTO `fly_sys_menu` VALUES (66, '付款管理', '付款管理', 'pay', 63, 43, 1, '');
INSERT INTO `fly_sys_menu` VALUES (67, '回款管理', '回款管理', 'back', 63, 44, 1, '');
INSERT INTO `fly_sys_menu` VALUES (68, '收入开支', '收入开支', '收入开支', 63, 45, 1, '');
INSERT INTO `fly_sys_menu` VALUES (69, '费用收入类型', 'income', '/erp/FinIncomeType/fin_income_type_show/', 65, 1, 1, '');
INSERT INTO `fly_sys_menu` VALUES (70, '费用开支类型', 'income', '/erp/FinExpensesType/fin_expenses_type_show/', 65, 2, 1, '');
INSERT INTO `fly_sys_menu` VALUES (71, '银行帐号管理', '银行帐号管理', '/erp/FinBankAccount/fin_bank_account_show/', 65, 3, 1, '');
INSERT INTO `fly_sys_menu` VALUES (72, '付款计划', 'FinPayPlan', '/erp/FinPayPlan/fin_pay_plan_show/', 66, 1, 1, '');
INSERT INTO `fly_sys_menu` VALUES (73, '付款记录', '付款记录', '/erp/FinPayRecord/fin_pay_record_show/', 66, 2, 1, '');
INSERT INTO `fly_sys_menu` VALUES (74, '收票记录', '收票记录', '/erp/FinInvoiceRece/fin_invoice_rece_show/', 66, 3, 1, '');
INSERT INTO `fly_sys_menu` VALUES (75, '回款计划', '回款计划', '/erp/FinRecePlan/fin_rece_plan_show/', 67, 1, 1, '');
INSERT INTO `fly_sys_menu` VALUES (76, '回款记录', '回款记录', '/erp/FinReceRecord/fin_rece_record_show/', 67, 2, 1, '');
INSERT INTO `fly_sys_menu` VALUES (77, '开票记录', '开票记录', '/erp/FinInvoicePay/fin_invoice_pay_show/', 67, 3, 1, '');
INSERT INTO `fly_sys_menu` VALUES (78, '报销单审核', '报销单审核', '报销单审核', 68, 1, 0, '');
INSERT INTO `fly_sys_menu` VALUES (79, '其它收入单', '其它收入单', '/erp/FinIncomeRecord/fin_income_record_show/', 68, 2, 1, '');
INSERT INTO `fly_sys_menu` VALUES (80, '费用支出单', '费用支出单', '/erp/FinExpensesRecord/fin_expenses_record_show/', 68, 3, 1, '');
INSERT INTO `fly_sys_menu` VALUES (81, '邮件群发', 'email', 'email', 1, 20, 0, '');
INSERT INTO `fly_sys_menu` VALUES (82, '发送地址', 'sendFrom', '/tools/EmailSend/email_from_show/', 81, 0, 1, '');
INSERT INTO `fly_sys_menu` VALUES (83, '接收地址', 'sendFrom', '/tools/EmailSend/email_receiver_show/', 81, 0, 1, '');
INSERT INTO `fly_sys_menu` VALUES (84, '方案定制', 'sendFrom', '/tools/EmailSend/email_scheme_show/', 81, 2, 1, '');
INSERT INTO `fly_sys_menu` VALUES (85, '邮件模板', 'moban', '/tools/EmailSend/email_mb_show/', 81, 0, 1, '');
INSERT INTO `fly_sys_menu` VALUES (86, '日志跟踪', 'schemeLog', '/tools/EmailSend/email_scheme_log_show/', 81, 1, 1, '');
INSERT INTO `fly_sys_menu` VALUES (87, '帐户流水记录', 'Flow', '/erp/FinFlowRecord/fin_flow_record_show/', 63, 46, 1, '');
INSERT INTO `fly_sys_menu` VALUES (88, '网站管理', 'website', '/crm/CstWebsite/cst_website_show/', 2, 232, 1, '');
INSERT INTO `fly_sys_menu` VALUES (89, '字典分类', '栏目名称', '/crm/CstDictType/cst_dict_type_show/', 7, 1, 1, '');
INSERT INTO `fly_sys_menu` VALUES (90, '基础数据', '', '/basicData', 0, 100, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (91, '数据字典', '', '/basicData/dictionary', 90, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (92, '字典分类', '', '/basicData/dictionary/classification', 91, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (93, '字典管理', '', '/basicData/dictionary/management', 91, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (94, '地区管理', '', '/basicData/regional', 90, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (95, '财务类型', '', '/basicData/financial', 90, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (96, '费用收入类型', '', '/basicData/financial/incomeType', 95, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (97, '费用开支类型', '', '/basicData/financial/expenseType', 95, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (98, '银行账号管理', '', '/basicData/financial/bankAccount', 95, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (99, '仓库管理', '', '/basicData/warehouse', 90, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (100, '商品管理', '', '/basicData/product', 90, 23, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (101, '商品品牌', '', '/basicData/product/brand', 100, 12, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (102, '商品类型', '', '/basicData/product/type', 100, 13, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (103, '商品分类', '', '/basicData/product/classification', 100, 14, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (104, '商品规格', '', '/basicData/product/specification', 100, 15, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (105, '商品维护', '', '/basicData/product/maintenace', 100, 16, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (106, '商品SKU', '', '/basicData/product/SKU', 100, 17, 1, 'IconPostCard');
INSERT INTO `fly_sys_menu` VALUES (107, '客户管理', '', '/customer', 0, 0, 1, 'IconAvatar');
INSERT INTO `fly_sys_menu` VALUES (108, '我的客户', '', '/customer/client', 107, 0, 1, 'IconAvatar');
INSERT INTO `fly_sys_menu` VALUES (109, '下属客户', '', '/customer/subCustomers', 107, 0, 1, 'IconAvatar');
INSERT INTO `fly_sys_menu` VALUES (110, '公海客户', '', '/customer/seasClients', 107, 0, 1, 'IconAvatar');
INSERT INTO `fly_sys_menu` VALUES (111, '联系人', '', '/customer/links', 107, 0, 1, 'IconAvatar');
INSERT INTO `fly_sys_menu` VALUES (112, '服务记录', '', '/customer/serviceRecord', 107, 0, 1, 'IconAvatar');
INSERT INTO `fly_sys_menu` VALUES (113, '资金管理', 'Fund Management', '/fund', 0, 0, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (114, '资金注入抽取', 'Fund Injection Extraction', '/fund/injectionExtraction', 113, 0, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (115, '回款管理', 'Collection Management', '/fund/collection', 113, 1, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (116, '收入开支', 'Income Expense', '/fund/incomeExpense', 113, 2, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (117, '账户流水记录', 'Account Transaction Record', '/fund/records', 113, 3, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (118, '付款管理', 'Payment Management', '/fund/payment', 113, 4, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (119, '回款计划', 'Collection Plan', '/fund/collection/collectionPlan', 115, 0, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (120, '回款记录', 'Collection Record', '/fund/collection/collectionRecords', 115, 1, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (121, '开票记录', 'Invoice Record', '/fund/collection/invoiceRecords', 115, 2, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (122, '其他收入单', 'Other Income', '/fund/incomeExpense/income', 116, 0, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (123, '费用支出单', 'Cost Expenses', '/fund/incomeExpense/expense', 116, 1, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (124, '付款计划', 'Payment Plan', '/fund/payment/plan', 118, 0, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (125, '付款记录', 'Payment Record', '/fund/payment/paymentRecords', 118, 1, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (126, '收票记录', 'Receipt Record', '/fund/payment/ticketRecords', 118, 2, 1, 'IconCollectionTag');
INSERT INTO `fly_sys_menu` VALUES (127, '个人首页', 'Homepage', '/homepage', 0, 0, 1, 'IconUser');
INSERT INTO `fly_sys_menu` VALUES (128, '公告通知', 'Notice', '/homepage/notice', 127, 0, 1, 'IconUser');
INSERT INTO `fly_sys_menu` VALUES (129, '消息通知', 'Message', '/homepage/message', 127, 1, 1, 'IconUser');
INSERT INTO `fly_sys_menu` VALUES (130, '修改密码', 'Change Password', '/homepage/password', 127, 2, 1, 'IconUser');
INSERT INTO `fly_sys_menu` VALUES (131, '编辑资料', 'Edit Information', '/homepage/information', 127, 3, 1, 'IconUser');
INSERT INTO `fly_sys_menu` VALUES (132, '库存管理', 'Inventory', '/inventory', 0, 0, 1, 'IconHouse');
INSERT INTO `fly_sys_menu` VALUES (133, '库存清单', 'Inventory List', '/inventory/inventoryList', 132, 0, 1, 'IconHouse');
INSERT INTO `fly_sys_menu` VALUES (134, '入库单', 'Storage Receipt', '/inventory/storageReceipt', 132, 1, 1, 'IconHouse');
INSERT INTO `fly_sys_menu` VALUES (135, '入库明细', 'Stock Storage Details', '/inventory/StockStorageDetails', 132, 2, 1, 'IconHouse');
INSERT INTO `fly_sys_menu` VALUES (136, '出库单', 'Warehousing Details', '/inventory/WarehousingDetails', 132, 3, 1, 'IconHouse');
INSERT INTO `fly_sys_menu` VALUES (137, '出库明细', 'Out storage details', '/inventory/outstoragedetails', 132, 4, 1, 'IconHouse');
INSERT INTO `fly_sys_menu` VALUES (138, '组织结构', 'Organization', '/organization', 0, 0, 1, 'IconOperation');
INSERT INTO `fly_sys_menu` VALUES (139, '部门管理', 'Department Management', '/organization/department', 138, 0, 1, 'IconOperation');
INSERT INTO `fly_sys_menu` VALUES (140, '岗位管理', 'Post Management', '/organization/post', 138, 1, 1, 'IconOperation');
INSERT INTO `fly_sys_menu` VALUES (141, '角色管理', 'Role Management', '/organization/role', 138, 2, 1, 'IconOperation');
INSERT INTO `fly_sys_menu` VALUES (142, '用户管理', 'User Management', '/organization/user', 138, 3, 1, 'IconOperation');
INSERT INTO `fly_sys_menu` VALUES (143, '销售管理', 'Sale Management', '/sale', 0, 0, 1, 'IconShop');
INSERT INTO `fly_sys_menu` VALUES (144, '销售机会', 'Sales Opportunity', '/sale/opportunity', 143, 0, 1, 'IconShop');
INSERT INTO `fly_sys_menu` VALUES (145, '跟踪记录', 'Tracking Records', '/sale/trackRecords', 143, 1, 1, 'IconShop');
INSERT INTO `fly_sys_menu` VALUES (146, '销售合同', 'Sales Contract', '/sale/saleContract', 143, 2, 1, 'IconShop');
INSERT INTO `fly_sys_menu` VALUES (147, '销售简报', 'Sales Kit', '/sale/saleKit', 143, 3, 1, 'IconShop');
INSERT INTO `fly_sys_menu` VALUES (148, '供应商管理', 'Supplier Management', '/supplier', 0, 0, 1, 'IconVan');
INSERT INTO `fly_sys_menu` VALUES (149, '供应商列表', 'Supplier List', '/supplier/list', 148, 0, 1, 'IconVan');
INSERT INTO `fly_sys_menu` VALUES (150, '供应商联系人', 'Supplier Contacts', '/supplier/contact', 148, 1, 1, 'IconVan');
INSERT INTO `fly_sys_menu` VALUES (151, '系统管理', 'System Management', '/system', 0, 0, 1, 'IconSetting');
INSERT INTO `fly_sys_menu` VALUES (152, '系统参数', 'System Parameters', '/system/parameter', 151, 0, 1, 'IconSetting');
INSERT INTO `fly_sys_menu` VALUES (153, '菜单管理', 'Menu Management', '/system/menu', 151, 1, 1, 'IconSetting');
INSERT INTO `fly_sys_menu` VALUES (154, '权限管理', 'Permission Management', '/system/power', 151, 2, 1, 'IconSetting');
INSERT INTO `fly_sys_menu` VALUES (155, '字段扩展', 'Field Extension', '/system/field', 151, 3, 1, 'IconSetting');

-- ----------------------------
-- Records of fly_sys_role_menu
-- ----------------------------
INSERT INTO `fly_sys_role_menu`(`role_id`, `menu_id`) 
VALUES 
(1,90),
(1,91),
(1,92),
(1,93),
(1,94),
(1,95),
(1,96),
(1,97),
(1,98),
(1,99),
(1,100),
(1,101),
(1,102),
(1,103),
(1,104),
(1,105),
(1,106),
(1,107),
(1,108),
(1,109),
(1,110),
(1,111),
(1,112),
(1,113),
(1,114),
(1,115),
(1,116),
(1,117),
(1,118),
(1,119),
(1,120),
(1,121),
(1,122),
(1,123),
(1,124),
(1,125),
(1,126),
(1,127),
(1,128),
(1,129),
(1,130),
(1,131),
(1,132),
(1,133),
(1,134),
(1,135),
(1,136),
(1,137),
(1,138),
(1,139),
(1,140),
(1,141),
(1,142),
(1,143),
(1,144),
(1,145),
(1,146),
(1,147),
(1,148),
(1,149),
(1,150),
(1,151),
(1,152),
(1,153),
(1,154),
(1,155);





-- 方法数据
INSERT INTO `fly_sys_method` VALUES (1, 99, '增加仓库', '/j3-controller-warehouse/add-store', 0, 1);
INSERT INTO `fly_sys_method` VALUES (2, 99, '删除仓库', '/j3-controller-warehouse/delete-store', 0, 1);
INSERT INTO `fly_sys_method` VALUES (3, 99, '获取仓库下拉列表', '/j3-controller-warehouse/getStoreSelect', 0, 1);
INSERT INTO `fly_sys_method` VALUES (4, 99, '导入仓库', '/j3-controller-warehouse/import-store', 0, 1);
INSERT INTO `fly_sys_method` VALUES (5, 99, '修改仓库信息', '/j3-controller-warehouse/modify-store-info', 0, 1);
INSERT INTO `fly_sys_method` VALUES (6, 99, '查询仓库', '/j3-controller-warehouse/query-store', 0, 1);
INSERT INTO `fly_sys_method` VALUES (7, 94, '删除地区', '/j3-area/deleteArea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (8, 94, '新增地区', '/j3-area/insertArea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (9, 94, '修改地区', '/j3-area/modifyArea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (10, 94, '获取区域列表', '/j3-area/query-list-area', 0, 1);
INSERT INTO `fly_sys_method` VALUES (11, 94, '获取区域名称结构树', '/j3-area/query-tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (12, 94, '获取区域下拉列表', '/j3-area/select-area', 0, 1);
INSERT INTO `fly_sys_method` VALUES (13, 108, '获取客户名称列表', '/customer-mycustomer/get-customername', 0, 1);
INSERT INTO `fly_sys_method` VALUES (14, 108, '获取客户列表', '/customer-mycustomer/get-customer', 0, 1);
INSERT INTO `fly_sys_method` VALUES (15, 108, '获取客户详细信息', '/customer-mycustomer/query-customer-details', 0, 1);
INSERT INTO `fly_sys_method` VALUES (16, 108, '获取客户基础信息表单数据项', '/customer-mycustomer/get-base-custormer-info', 0, 1);
INSERT INTO `fly_sys_method` VALUES (17, 108, '添加客户', '/customer-mycustomer/post-customers', 0, 1);
INSERT INTO `fly_sys_method` VALUES (18, 108, '修改客户基础信息', '/customer-mycustomer/put-customers', 0, 1);
INSERT INTO `fly_sys_method` VALUES (19, 108, '删除客户', '/customer-mycustomer/delete-custormer', 0, 1);
INSERT INTO `fly_sys_method` VALUES (20, 108, '投入公海', '/customer-mycustomer/inves-hightsea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (21, 108, '导出客户', '/customer-mycustomer/get-customername', 0, 1);
INSERT INTO `fly_sys_method` VALUES (22, 108, '上传导入文件', '/customer-mycustomer/upload-customer-file', 0, 1);
INSERT INTO `fly_sys_method` VALUES (23, 110, '领取客户', '/crm-c2-customer-publiccustomer/receive-custormer', 0, 1);
INSERT INTO `fly_sys_method` VALUES (24, 111, '获取联系人名称', '/customer-contact/query-contact-name', 0, 1);
INSERT INTO `fly_sys_method` VALUES (25, 111, '获取联系人列表', '/customer-contact/query-contact-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (26, 111, '获取联系人表单数据项', '/customer-contact/get-contact-field', 0, 1);
INSERT INTO `fly_sys_method` VALUES (27, 111, '添加联系人', '/customer-contact/add-contact', 0, 1);
INSERT INTO `fly_sys_method` VALUES (28, 111, '修改联系人', '/customer-contact/modify-contact', 0, 1);
INSERT INTO `fly_sys_method` VALUES (29, 111, '删除联系人', '/customer-contact/remove-contact', 0, 1);
INSERT INTO `fly_sys_method` VALUES (30, 111, '导出联系人', '/customer-contact/query-contact-file', 0, 1);
INSERT INTO `fly_sys_method` VALUES (31, 111, '发送短信接口', '/customer-contact/send-sms', 0, 1);
INSERT INTO `fly_sys_method` VALUES (32, 111, '发送邮件接口', '/customer-contact/send-email', 0, 1);
INSERT INTO `fly_sys_method` VALUES (33, 112, '分页查询服务记录', '/customer-servicerecords/service-note', 0, 1);
INSERT INTO `fly_sys_method` VALUES (34, 112, '添加服务记录', '/customer-servicerecords/add-service', 0, 1);
INSERT INTO `fly_sys_method` VALUES (35, 112, '修改服务记录', '/customer-servicerecords/modify-service', 0, 1);
INSERT INTO `fly_sys_method` VALUES (36, 112, '删除服务记录(批量)', '/customer-servicerecords/remove-service{service_id_s}', 0, 1);
INSERT INTO `fly_sys_method` VALUES (37, 112, '导出服务记录', '/customer-servicerecords/export-servicenote', 0, 1);
INSERT INTO `fly_sys_method` VALUES (38, 112, '发送短信接口', '/customer-servicerecords/send-sms', 0, 1);
INSERT INTO `fly_sys_method` VALUES (39, 112, '发送邮件接口', '/customer-servicerecords/send-email', 0, 1);
INSERT INTO `fly_sys_method` VALUES (40, 144, '获取销售机会列表(分页+条件)', '/sales-opportunities/query-invoices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (41, 144, '添加销售机会', '/sales-opportunities/insert-sales-opportunity', 0, 1);
INSERT INTO `fly_sys_method` VALUES (42, 144, '修改销售机会', '/sales-opportunities/update-sales-opportunity', 0, 1);
INSERT INTO `fly_sys_method` VALUES (43, 144, '删除销售机会(支持批量删除)', '/sales-opportunities/delete-sales-opportunity', 0, 1);
INSERT INTO `fly_sys_method` VALUES (44, 144, '获取销售机名称会列表(用于输入表单下拉列表)', '/sales-opportunities/sales-oppo-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (45, 144, '导出销售机会', '/sales-opportunities/export-sales-opportunity', 0, 1);
INSERT INTO `fly_sys_method` VALUES (46, 144, '发邮件(支持批量)', '/sales-opportunities/salesContract/Mail/', 0, 1);
INSERT INTO `fly_sys_method` VALUES (47, 144, '发短信(支持批量)', '/sales-opportunities/salesContract/Sms/', 0, 1);
INSERT INTO `fly_sys_method` VALUES (48, 145, '增加跟踪记录', '/crm-c4-sales-man/add-trace', 0, 1);
INSERT INTO `fly_sys_method` VALUES (49, 145, '修改跟踪记录', '/crm-c4-sales-man/modify-trace', 0, 1);
INSERT INTO `fly_sys_method` VALUES (50, 145, '获取跟踪记录', '/crm-c4-sales-man/get', 0, 1);
INSERT INTO `fly_sys_method` VALUES (51, 145, '单独删除跟踪记录', '/crm-c4-sales-man/delete-trace/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (52, 145, '批量删除跟踪记录', '/crm-c4-sales-man/delete-tracelist', 0, 1);
INSERT INTO `fly_sys_method` VALUES (53, 145, '下载跟踪记录文件', '/crm-c4-sales-man/downloadfile-trace', 0, 1);
INSERT INTO `fly_sys_method` VALUES (54, 145, '单独删除跟踪记录', '/crm-c4-sales-man/record/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (55, 145, '导出跟踪记录', '/crm-c4-sales-man/recordsfile/download', 0, 1);
INSERT INTO `fly_sys_method` VALUES (56, 145, '获取销售榜', '/crm-c4-sales-man/querySalesChart', 0, 1);
INSERT INTO `fly_sys_method` VALUES (57, 147, '进行数量统计', '/crm-c4-sales-man/queryNumberCounting', 0, 1);
INSERT INTO `fly_sys_method` VALUES (58, 147, '查询跟踪记录', '/crm-c4-sales-man/await/query', 0, 1);
INSERT INTO `fly_sys_method` VALUES (59, 147, '', '/crm-c4-sales-man/await/queryC', 0, 1);
INSERT INTO `fly_sys_method` VALUES (60, 145, '发送预约提醒短信(支持批量)', '/crm-c4-sales-man/sendms', 0, 1);
INSERT INTO `fly_sys_method` VALUES (61, 145, '发送预约提醒邮件(支持批量)', '/crm-c4-sales-man/sendem', 0, 1);
INSERT INTO `fly_sys_method` VALUES (62, 146, '获取销售合同列表数据(用于输入表单下拉列表)', '/sales-contract/sales-cont-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (63, 146, '获取销售合同唯一编号', '/sales-contract/get-salesNo/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (64, 146, '获取销售合同列表(分页+条件)', '/sales-contract/get-sales-contract-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (65, 146, '获取合同详情', '/sales-contract/get-sales-contract-detail-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (66, 146, '获取合同清单', '/sales-contract/get-contract-goods', 0, 1);
INSERT INTO `fly_sys_method` VALUES (67, 146, '添加销售合同', '/sales-contract/add-contract', 0, 1);
INSERT INTO `fly_sys_method` VALUES (68, 146, '删除销售合同', '/sales-contract/delete-contract/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (69, 146, '修改销售合同基础信息', '/sales-contract/modify-basic-info', 0, 1);
INSERT INTO `fly_sys_method` VALUES (70, 146, '修改交付状态', '/sales-contract/modify-deliver-status', 0, 1);
INSERT INTO `fly_sys_method` VALUES (71, 146, '录入明细', '/sales-contract/input-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (72, 146, '删除明细', '/sales-contract/delete-contract-details/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (73, 146, '添加合同附件', '/sales-contract/contractfile/upload', 0, 1);
INSERT INTO `fly_sys_method` VALUES (74, 146, '生成出库单', '/sales-contract/add-out_stock', 0, 1);
INSERT INTO `fly_sys_method` VALUES (75, 146, '导出销售合同', '/sales-contract/ExportSales', 0, 1);
INSERT INTO `fly_sys_method` VALUES (76, 146, '发短信(支持批量)', '/sales-contract/sms', 0, 1);
INSERT INTO `fly_sys_method` VALUES (77, 146, '发邮件(支持批量)', '/sales-contract/email', 0, 1);
INSERT INTO `fly_sys_method` VALUES (78, 115, '修改回款计划', '/collection-man/update-pay-plan', 0, 1);
INSERT INTO `fly_sys_method` VALUES (79, 115, '确认回款计划', '/collection-man/update-confirm-plan', 0, 1);
INSERT INTO `fly_sys_method` VALUES (80, 115, '获取回款列表', '/collection-man/collectionplans/get-collectionplans', 0, 1);
INSERT INTO `fly_sys_method` VALUES (81, 115, '添加回款计划', '/collection-man/collectionplans/add-collection', 0, 1);
INSERT INTO `fly_sys_method` VALUES (82, 115, '查询回款记录', '/collection-man/collectionRecord/qurery', 0, 1);
INSERT INTO `fly_sys_method` VALUES (83, 115, '新增回款记录', '/collection-man/collectionRecord/add', 0, 1);
INSERT INTO `fly_sys_method` VALUES (84, 115, '删除回款记录', '/collection-man/collectionRecord/delete', 0, 1);
INSERT INTO `fly_sys_method` VALUES (85, 115, '导出回款记录', '/collection-man/collectionRecord/export', 0, 1);
INSERT INTO `fly_sys_method` VALUES (86, 115, '删除回款计划', '/collection-man/payback-manage/del-payplan', 0, 1);
INSERT INTO `fly_sys_method` VALUES (87, 115, '获取金额信息', '/collection-man/payback-manage/select-amountinfo', 0, 1);
INSERT INTO `fly_sys_method` VALUES (88, 115, '删除开票记录(支持批量删除)', '/collection-man/BillingRecords/DelBillingRecords', 0, 1);
INSERT INTO `fly_sys_method` VALUES (89, 115, '导出开票记录', '/collection-man/BillingRecords/ExportBillingRecords', 0, 1);
INSERT INTO `fly_sys_method` VALUES (90, 115, '分页查询开票', '/collection-man/Invoice/qurery', 0, 1);
INSERT INTO `fly_sys_method` VALUES (91, 115, '新增开票', '/collection-man/Invoice/add', 0, 1);
INSERT INTO `fly_sys_method` VALUES (92, 116, '删除单据', '/financial-manager/delete-expenditures-invoices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (93, 116, '导出单据', '/financial-manager/export-expenditures-invoices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (94, 116, '新增单据', '/financial-manager/add-expenditures-invoices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (95, 116, '查询单据', '/financial-manager/query-invoices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (96, 116, '删除单据', '/financial-manager/delete-invoices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (97, 116, '导出收入单', '/financial-manager/export-data', 0, 1);
INSERT INTO `fly_sys_method` VALUES (98, 117, '查询流水记录', '/financial-manager/query-flowrecord', 0, 1);
INSERT INTO `fly_sys_method` VALUES (99, 117, '导出流水记录', '/financial-manager/export-flowrecord', 0, 1);
INSERT INTO `fly_sys_method` VALUES (100, 116, '新增收入单', '/financial-manager/insert-income', 0, 1);
INSERT INTO `fly_sys_method` VALUES (101, 116, '分页查询收入单', '/financial-manager/query-income', 0, 1);
INSERT INTO `fly_sys_method` VALUES (102, 132, '获取入库明细项列表(分页+条件)', '/inventory-manager/query-storage-details', 0, 1);
INSERT INTO `fly_sys_method` VALUES (103, 132, '导出入库明细', '/inventory-manager/export-storage-details', 0, 1);
INSERT INTO `fly_sys_method` VALUES (104, 132, '确认入库', '/inventory-manager/modify-ConfirmStorage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (105, 132, '删除入库单', '/inventory-manager/delete-storage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (106, 132, '获取出库明细项列表', '/inventory-manager/query-outbound-detail', 0, 1);
INSERT INTO `fly_sys_method` VALUES (107, 132, '导出出库明细', '/inventory-manager/export-outbound-details', 0, 1);
INSERT INTO `fly_sys_method` VALUES (108, 132, '获取入库单列表(分页+条件)', '/inventory-manager/query-instorage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (109, 132, '查询入库明细', '/inventory-manager/query-instorage_details/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (110, 132, '添加入库单', '/inventory-manager/add-instorage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (111, 132, '获取库存列表(分页+条件)', '/inventory-manager/query-inventory-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (112, 132, '导出库存列表信息', '/inventory-manager/export-inventory-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (113, 132, '确认出库', '/inventory-manager/confirm-outstock', 0, 1);
INSERT INTO `fly_sys_method` VALUES (114, 132, '删除出库单', '/inventory-manager/delete-outstock', 0, 1);
INSERT INTO `fly_sys_method` VALUES (115, 132, '获取出库单项列表(分页+条件)', '/inventory-manager/query-out-stock', 0, 1);
INSERT INTO `fly_sys_method` VALUES (116, 132, '添加出库单', '/inventory-manager/add-out_stock', 0, 1);
INSERT INTO `fly_sys_method` VALUES (117, 132, '获取出库单明细', '/inventory-manager/out-stock-details', 0, 1);
INSERT INTO `fly_sys_method` VALUES (118, 114, '获取银行账户列表数据', '/fin-capital-record/query-bank-account', 0, 1);
INSERT INTO `fly_sys_method` VALUES (119, 114, '查询资金注入抽取单号记录', '/fin-capital-record/query-data', 0, 1);
INSERT INTO `fly_sys_method` VALUES (120, 114, '添加资金注入抽取单号记录', '/fin-capital-record/add-data', 0, 1);
INSERT INTO `fly_sys_method` VALUES (121, 114, '导出资金注入抽取单号记录(批量)', '/fin_capital_record/export-data', 0, 1);
INSERT INTO `fly_sys_method` VALUES (122, 114, '删除资金注入抽取单号(批量)', '/fin-capital-record/remove-data', 0, 1);
INSERT INTO `fly_sys_method` VALUES (123, 0, '获取供应商名称列表', '/common/query-supplier-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (124, 0, '获取供应商联系人名称列表', '/common/query-linkman-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (125, 0, '获取仓库名称列表', '/common/warehouse', 0, 1);
INSERT INTO `fly_sys_method` VALUES (126, 0, '获取区域名称列表', '/common/area', 0, 1);
INSERT INTO `fly_sys_method` VALUES (127, 0, '获取部门名称列表', '/common/department-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (128, 0, '获取岗位名称列表', '/common/position-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (129, 0, '获取角色名称列表', '/common/role-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (130, 0, '系统用户名称列表', '/common/sys-user-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (131, 0, '获取客户名称列表', '/common/client-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (132, 0, '获取联系人名称列表', '/common/query-contact-name', 0, 1);
INSERT INTO `fly_sys_method` VALUES (133, 0, '获取费用收入类型名称列表', '/common/cost-income-type-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (134, 0, '获取费用开支类型名称列表', '/common/cost-expense-type-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (135, 0, '获取银行账户列表', '/common/bank-account-1ist', 0, 1);
INSERT INTO `fly_sys_method` VALUES (136, 0, '获取指定字典分类对应字典列表', '/common/data-dict-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (137, 0, '获取销售机会名称列表', '/common/sale-opportunity-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (138, 0, '获取销售合同名称列表', '/common/sale-contract-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (139, 0, '获取商品分类名称列表', '/common/goods-category-name-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (140, 148, '修改供应商', '/supplier-manage/supplier/modify-supplier', 0, 1);
INSERT INTO `fly_sys_method` VALUES (141, 148, '获取供应商基础信息表单数据项', '/supplier-manage/supplier/query-sup-form-item', 0, 1);
INSERT INTO `fly_sys_method` VALUES (142, 148, '获取供应商列表(分页+条件)', '/supplier-manage/supplier/get-supplier', 0, 1);
INSERT INTO `fly_sys_method` VALUES (143, 148, '添加供应商', '/supplier-manage/supplier/add-supplier', 0, 1);
INSERT INTO `fly_sys_method` VALUES (144, 148, '删除供应商', '/supplier-manage/supplier/remove-supplier', 0, 1);
INSERT INTO `fly_sys_method` VALUES (145, 148, '导出供应商联系人', '/supplier-manage/supplier-linkman/export-linkman', 0, 1);
INSERT INTO `fly_sys_method` VALUES (146, 148, '批量发短信', '/supplier-manage/supplier-linkman/send-message', 0, 1);
INSERT INTO `fly_sys_method` VALUES (147, 148, '修改供应商联系人', '/supplier-manage/supplier-linkman/modify-link-man', 0, 1);
INSERT INTO `fly_sys_method` VALUES (148, 148, '删除供应商联系人', '/supplier-manage/supplier-linkman/remove-linkman', 0, 1);
INSERT INTO `fly_sys_method` VALUES (149, 148, '获取供应商联系人基础信息表单数据项', '/supplier-manage/supplier-linkman/basic-data', 0, 1);
INSERT INTO `fly_sys_method` VALUES (150, 148, '批量发邮件', '/supplier-manage/supplier-linkman/send-email', 0, 1);
INSERT INTO `fly_sys_method` VALUES (151, 148, '获取供应商联系人名称列表', '/supplier-manage/supplier-linkman/query-name-pull-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (152, 148, '获取供应商联系人列表(分页+条件)', '/supplier-manage/supplier-linkman/query-linkman-page', 0, 1);
INSERT INTO `fly_sys_method` VALUES (153, 148, '添加供应商联系人', '/supplier-manage/supplier-linkman/add-linkman', 0, 1);
INSERT INTO `fly_sys_method` VALUES (154, 0, '授权登录', '/login/auth-login', 0, 1);
INSERT INTO `fly_sys_method` VALUES (155, 0, '获取当前用户', '/login/current-user', 0, 1);
INSERT INTO `fly_sys_method` VALUES (156, 0, '获取菜单', '/login/get-menus', 0, 1);
INSERT INTO `fly_sys_method` VALUES (157, 0, '退出登录', '/login/logout', 0, 1);
INSERT INTO `fly_sys_method` VALUES (158, 0, '刷新登录', '/login/refresh-token', 0, 1);
INSERT INTO `fly_sys_method` VALUES (159, 0, '分页查询系统提示消息', '/sysindex/system-message/query-all-message', 0, 1);
INSERT INTO `fly_sys_method` VALUES (160, 0, '分页查询系统公告', '/sysindex/system-message/query-all-notice', 0, 1);
INSERT INTO `fly_sys_method` VALUES (161, 0, '编号查询系统提示消息', '/sysindex/system-message/query-byid-message', 0, 1);
INSERT INTO `fly_sys_method` VALUES (162, 0, '编号查询系统公告', '/sysindex/system-message/query-byid-notice', 0, 1);
INSERT INTO `fly_sys_method` VALUES (163, 0, '根据商机预计销售额统计商机数量', '/sysindex/count-business-money', 0, 1);
INSERT INTO `fly_sys_method` VALUES (164, 0, '根据商机销售状态分类统计商机数量', '/sysindex/count-business-salestage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (165, 0, '根据商机预计成功率统计商机数量', '/sysindex/count-business-successrate', 0, 1);
INSERT INTO `fly_sys_method` VALUES (166, 0, '根据客户等级统计数量', '/sysindex/count-customer-grade', 0, 1);
INSERT INTO `fly_sys_method` VALUES (167, 0, '根据客户行业统计数量', '/sysindex/count-customer-industryr', 0, 1);
INSERT INTO `fly_sys_method` VALUES (168, 0, '统计客户数量', '/sysindex/count-customer-number', 0, 1);
INSERT INTO `fly_sys_method` VALUES (169, 0, '根据客户来源统计数量', '/sysindex/count-customer-source', 0, 1);
INSERT INTO `fly_sys_method` VALUES (170, 0, '标记通知为已读', '/sysindex/mark-as-read', 0, 1);
INSERT INTO `fly_sys_method` VALUES (171, 0, '查询公告通知提醒列表', '/sysindex/query-announcement-notices', 0, 1);
INSERT INTO `fly_sys_method` VALUES (172, 151, '获取字段类型', '/CstPlus/gettype', 0, 1);
INSERT INTO `fly_sys_method` VALUES (173, 151, 'updateField', '/CstPlus/update', 0, 1);
INSERT INTO `fly_sys_method` VALUES (174, 151, '获取可扩展表单列表（分页）', '/systemmanagement/cst-field-ext-plus/list-page', 0, 1);
INSERT INTO `fly_sys_method` VALUES (175, 151, '添加扩展字段', '/systemmanagement/cst-field-ext/add', 0, 1);
INSERT INTO `fly_sys_method` VALUES (176, 151, '获取可扩展表单列表', '/systemmanagement/cst-field-ext/list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (177, 151, '删除扩展字段', '/systemmanagement/cst-field-ext/remove-by-id', 0, 1);
INSERT INTO `fly_sys_method` VALUES (178, 151, '批量删除扩展字段', '/systemmanagement/cst-field-ext/remove-by-ids', 0, 1);
INSERT INTO `fly_sys_method` VALUES (179, 151, '获取系统参数', '/systemmanagement/fly-sys-config/list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (180, 151, '更新系统参数', '/systemmanagement/fly-sys-config/update', 0, 1);
INSERT INTO `fly_sys_method` VALUES (181, 151, '添加系统菜单', '/systemmanagement/fly-sys-menu/add', 0, 1);
INSERT INTO `fly_sys_method` VALUES (182, 151, '删除菜单和子菜单', '/systemmanagement/fly-sys-menu/delete/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (183, 151, '修改菜单', '/systemmanagement/fly-sys-menu/update', 0, 1);
INSERT INTO `fly_sys_method` VALUES (184, 151, '添加权限', '/systemmanagement/fly-sys-method/add-method', 0, 1);
INSERT INTO `fly_sys_method` VALUES (185, 151, '删除权限', '/systemmanagement/fly-sys-method/deletemethod', 0, 1);
INSERT INTO `fly_sys_method` VALUES (186, 151, '获取权限列表', '/systemmanagement/fly-sys-method/getMethodList', 0, 1);
INSERT INTO `fly_sys_method` VALUES (187, 151, '修改权限', '/systemmanagement/fly-sys-method/modify-method', 0, 1);
INSERT INTO `fly_sys_method` VALUES (188, 151, '查询菜单名称树', '/menu/tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (189, 151, '查询菜单列表', '/menu/{id}', 0, 1);
INSERT INTO `fly_sys_method` VALUES (190, 138, '新增岗位', '/orgstructure/position/position/add-position', 0, 1);
INSERT INTO `fly_sys_method` VALUES (191, 138, '删除岗位', '/orgstructure/position/position/delete-position', 0, 1);
INSERT INTO `fly_sys_method` VALUES (192, 138, '获取岗位名称结构树', '/orgstructure/position/position/list-name-tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (193, 138, '获取岗位列表 (分页+条件)', '/orgstructure/position/position/query-all', 0, 1);
INSERT INTO `fly_sys_method` VALUES (194, 138, '获取岗位名称列表数据 (用于输入表单下拉列表)', '/orgstructure/position/position/query-name-all\r\n', 0, 1);
INSERT INTO `fly_sys_method` VALUES (195, 138, '修改岗位', '/orgstructure/position/position/update-position', 0, 1);
INSERT INTO `fly_sys_method` VALUES (196, 138, '新增用户', '/orgstructure/user/user/add-user', 0, 1);
INSERT INTO `fly_sys_method` VALUES (197, 138, '删除用户', '/orgstructure/user/user/delete-user', 0, 1);
INSERT INTO `fly_sys_method` VALUES (198, 138, '导出用户', '/orgstructure/user/user/export-user', 0, 1);
INSERT INTO `fly_sys_method` VALUES (199, 138, '系统用户名列表数据 (用于输入表单下拉列表)', '/orgstructure/user/user/get-userName-list', 0, 1);
INSERT INTO `fly_sys_method` VALUES (200, 138, '导入用户', '/orgstructure/user/user/import-user', 0, 1);
INSERT INTO `fly_sys_method` VALUES (201, 138, '冻结-解冻用户', '/orgstructure/user/user/modify-user-status', 0, 1);
INSERT INTO `fly_sys_method` VALUES (202, 138, '获取用户列表 (分页+条件)', '/orgstructure/user/user/query-all-by-deptid-or-name', 0, 1);
INSERT INTO `fly_sys_method` VALUES (203, 138, '修改用户', '/orgstructure/user/user/update-user', 0, 1);
INSERT INTO `fly_sys_method` VALUES (204, 138, '新增角色', '/orgstructure/role/role/add-role', 0, 1);
INSERT INTO `fly_sys_method` VALUES (205, 138, '获取角色名称结构树', '/orgstructure/role/role/list-name-tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (206, 138, '修改角色', '/orgstructure/role/role/modify-role', 0, 1);
INSERT INTO `fly_sys_method` VALUES (207, 138, '获取角色列表 (分页+条件)', '/orgstructure/role/role/query-all', 0, 1);
INSERT INTO `fly_sys_method` VALUES (208, 138, '获取角色名称列表数据 (用于输入表单下拉列表)', '/orgstructure/role/role/query-name-all', 0, 1);
INSERT INTO `fly_sys_method` VALUES (209, 138, '删除角色', '/orgstructure/role/role/remove-role', 0, 1);
INSERT INTO `fly_sys_method` VALUES (210, 138, '获取角色菜单权限树形数据', '/orgstructure/role/role-menu/role-check-power', 0, 1);
INSERT INTO `fly_sys_method` VALUES (211, 138, '修改角色菜单权限', '/orgstructure/role/role-menu/role-check-power-save', 0, 1);
INSERT INTO `fly_sys_method` VALUES (212, 138, '新增部门', '/orgstructure/dept/dept/add-dept', 0, 1);
INSERT INTO `fly_sys_method` VALUES (213, 138, '获取部门名称列表数据 (用于输入表单下拉列表)', '/orgstructure/dept/dept/list-name-all', 0, 1);
INSERT INTO `fly_sys_method` VALUES (214, 138, '获取部门名称结构树', '/orgstructure/dept/dept/list-name-tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (215, 138, '修改部门', '/orgstructure/dept/dept/modify-dept', 0, 1);
INSERT INTO `fly_sys_method` VALUES (216, 138, '获取部门列表 (分页+条件)', '/orgstructure/dept/dept/query-all', 0, 1);
INSERT INTO `fly_sys_method` VALUES (217, 138, '删除部门', '/orgstructure/dept/dept/remove-dept', 0, 1);
INSERT INTO `fly_sys_method` VALUES (218, 0, '添加采购合同', '/purchasemanagement/contract/pos-contract/add-contract', 0, 1);
INSERT INTO `fly_sys_method` VALUES (219, 0, '导出采购合同', '/purchasemanagement/contract/pos-contract/export-contract', 0, 1);
INSERT INTO `fly_sys_method` VALUES (220, 0, '获取合同详情', '/purchasemanagement/contract/pos-contract/get-contract-detail', 0, 1);
INSERT INTO `fly_sys_method` VALUES (221, 0, '获取合同清单', '/purchasemanagement/contract/pos-contract/get-contract-inventory', 0, 1);
INSERT INTO `fly_sys_method` VALUES (222, 0, '获取合同列表 (分页+条件)', '/purchasemanagement/contract/pos-contract/get-contract-list-with-page-condition', 0, 1);
INSERT INTO `fly_sys_method` VALUES (223, 0, '获取合同唯一编号', '/purchasemanagement/contract/pos-contract/getContractNo', 0, 1);
INSERT INTO `fly_sys_method` VALUES (224, 0, '修改采购合同基本信息', '/purchasemanagement/contract/pos-contract/modify-contract', 0, 1);
INSERT INTO `fly_sys_method` VALUES (225, 0, '导出采购合同明细', '/purchasemanagement/contract/pos-contract-list/export-contract-detail', 0, 1);
INSERT INTO `fly_sys_method` VALUES (226, 0, '获取合同列表 (分页+条件)', '/purchasemanagement/contract/pos-contract-list/get-contract-list-page', 0, 1);
INSERT INTO `fly_sys_method` VALUES (227, 127, '编辑资料', '/j3-owner-info/modify-owner-info', 0, 1);
INSERT INTO `fly_sys_method` VALUES (228, 127, '修改密码', '/j3-owner-info/modify-password', 0, 1);
INSERT INTO `fly_sys_method` VALUES (229, 127, '发布公告', '/j3-notice-remind/add-notice', 0, 1);
INSERT INTO `fly_sys_method` VALUES (230, 127, '查看指定公告详情', '/j3-notice-remind/get-notice', 0, 1);
INSERT INTO `fly_sys_method` VALUES (231, 127, '获取系统公告', '/j3-notice-remind/query-notion', 0, 1);
INSERT INTO `fly_sys_method` VALUES (232, 127, '删除公告（可批量删除）', '/j3-notice-remind/remove-notice', 0, 1);
INSERT INTO `fly_sys_method` VALUES (233, 127, '标记已读公告（可批量标记）', '/j3-notice-remind/update-notice', 0, 1);
INSERT INTO `fly_sys_method` VALUES (234, 127, '标记消息已读（批量操作）', '/j3-message-remind/mark-read-message', 0, 1);
INSERT INTO `fly_sys_method` VALUES (235, 127, '发布消息', '/j3-message-remind/publish-message', 0, 1);
INSERT INTO `fly_sys_method` VALUES (236, 127, '消息删除', '/j3-message-remind/deleteMassage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (237, 127, '根据分页条件获取消息列表', '/j3-message-remind/queryMessage', 0, 1);
INSERT INTO `fly_sys_method` VALUES (238, 127, '查看消息详情', '/j3-message-remind/{id}', 0, 1);
INSERT INTO `fly_sys_method` VALUES (239, 94, '删除地区', '/j3-area/deleteArea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (240, 94, '新增地区', '/j3-area/insertArea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (241, 94, '修改地区', '/j3-area/modifyArea', 0, 1);
INSERT INTO `fly_sys_method` VALUES (242, 94, '获取区域列表', '/j3-area/query-list-area', 0, 1);
INSERT INTO `fly_sys_method` VALUES (243, 94, '获取区域名称结构树', '/j3-area/query-tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (244, 94, '获取区域下拉列表', '/j3-area/select-area', 0, 1);
INSERT INTO `fly_sys_method` VALUES (245, 99, '导出仓库', '/j3-controller-warehouse/export-store', 0, 1);
INSERT INTO `fly_sys_method` VALUES (246, 100, '删除sku', '/goods/commoditySku/del-sku', 0, 1);
INSERT INTO `fly_sys_method` VALUES (247, 100, '修改SKU', '/goods/commoditySku/edit-sku', 0, 1);
INSERT INTO `fly_sys_method` VALUES (248, 100, '获取SKU列表(分页+条件)', '/goods/commoditySku/query-sku', 0, 1);
INSERT INTO `fly_sys_method` VALUES (249, 100, '新增商品分类', '/goods/category/add', 0, 1);
INSERT INTO `fly_sys_method` VALUES (250, 100, '获取商品分类', '/goods/category/get/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (251, 100, '分页获取商品分类', '/goods/category/list-goods-category', 0, 1);
INSERT INTO `fly_sys_method` VALUES (252, 100, '获取商品分类名称树', '/goods/category/list-goods-category-name-tree', 0, 1);
INSERT INTO `fly_sys_method` VALUES (253, 100, '修改商品分类', '/goods/category/modify', 0, 1);
INSERT INTO `fly_sys_method` VALUES (254, 100, '删除商品分类', '/goods/category/remove/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (255, 100, '添加品牌', '/goods/commodityBrand/add-brand', 0, 1);
INSERT INTO `fly_sys_method` VALUES (256, 100, '修改品牌', '/goods/commodityBrand/modify-brand', 0, 1);
INSERT INTO `fly_sys_method` VALUES (257, 100, '获取品牌列表条件查询', '/goods/commodityBrand/query-brand', 0, 1);
INSERT INTO `fly_sys_method` VALUES (258, 100, '删除品牌列表', '/goods/commodityBrand/remove-brand', 0, 1);
INSERT INTO `fly_sys_method` VALUES (259, 100, '添加类型', '/goods/type/add-type', 0, 1);
INSERT INTO `fly_sys_method` VALUES (260, 100, '删除类型', '/goods/type/delete-type', 0, 1);
INSERT INTO `fly_sys_method` VALUES (261, 100, '查询详细信息', '/goods/type/find-detailed-type\r\n', 0, 1);
INSERT INTO `fly_sys_method` VALUES (262, 100, '查询简单信息', '/goods/type/find-simple-type', 0, 1);
INSERT INTO `fly_sys_method` VALUES (263, 100, '修改详细信息', '/goods/type/modify-detailed-type', 0, 1);
INSERT INTO `fly_sys_method` VALUES (264, 100, '发布商品', '/goods/maintenance/add-goods', 0, 1);
INSERT INTO `fly_sys_method` VALUES (265, 100, '删除商品(支持批量操作)', '/goods/maintenance/delete-goods', 0, 1);
INSERT INTO `fly_sys_method` VALUES (266, 100, '获取商品详细信息', '/goods/maintenance/get-content/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (267, 100, '获取商品类型名称列表 (用于输入表单下拉列表)', '/goods/maintenance/get-goodsNames', 0, 1);
INSERT INTO `fly_sys_method` VALUES (268, 100, '分页查询', '/goods/maintenance/list-goods-pages', 0, 1);
INSERT INTO `fly_sys_method` VALUES (269, 100, '推荐-取消推荐(支持批量操作)', '/goods/maintenance/recommend-goods', 0, 1);
INSERT INTO `fly_sys_method` VALUES (270, 100, '修改商品', '/goods/maintenance/update-goods', 0, 1);
INSERT INTO `fly_sys_method` VALUES (271, 100, '上架-下架商品(支持批量操作)', '/goods/maintenance/update-state', 0, 1);
INSERT INTO `fly_sys_method` VALUES (272, 100, '增加商品规格', '/goods/commoditySpec/add-spec', 0, 1);
INSERT INTO `fly_sys_method` VALUES (273, 100, '删除商品规格', '/goods/commoditySpec/delete-spec', 0, 1);
INSERT INTO `fly_sys_method` VALUES (274, 100, '获取商品规格列表(分页+条件)', '/goods/commoditySpec/get-commodity-spec', 0, 1);
INSERT INTO `fly_sys_method` VALUES (275, 100, '修改商品规格', '/goods/commoditySpec/modify-spec', 0, 1);
INSERT INTO `fly_sys_method` VALUES (276, 118, '查询付款计划', '/payment/pay-plan/query', 0, 1);
INSERT INTO `fly_sys_method` VALUES (277, 118, '删除收票记录(可批量)', '/payment/receipt-record/delete{record_id}', 0, 1);
INSERT INTO `fly_sys_method` VALUES (278, 118, '添加付款记录', '/payment/payrecord', 0, 1);
INSERT INTO `fly_sys_method` VALUES (279, 118, '增加收票记录', '/payment/invoice/post', 0, 1);
INSERT INTO `fly_sys_method` VALUES (280, 118, '删除付款记录', '/payment/pay-record/delete', 0, 1);
INSERT INTO `fly_sys_method` VALUES (281, 118, '导出付款记录', '/payment/pay-record/export', 0, 1);
INSERT INTO `fly_sys_method` VALUES (282, 118, '获取收票记录列表(分页+条件)', '/payment/invoice/query', 0, 1);
INSERT INTO `fly_sys_method` VALUES (283, 118, '', '/payment/capital/export:', 0, 1);
INSERT INTO `fly_sys_method` VALUES (284, 118, '删除付款计划', '/payment/pay-plan/del/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (285, 118, '确认付款', '/payment/pay-plan/confirm/**', 0, 1);
INSERT INTO `fly_sys_method` VALUES (286, 118, '修改付款计划', '/payment/pay-plan/update', 0, 1);
INSERT INTO `fly_sys_method` VALUES (287, 118, '添加付款计划', '/payment/pay-plan/post', 0, 1);
INSERT INTO `fly_sys_method` VALUES (288, 118, '', '/payment/pay-record/page-query:', 0, 1);
INSERT INTO `fly_sys_method` VALUES (289, 118, '', '/payment/contray/query:', 0, 1);
INSERT INTO `fly_sys_method` VALUES (290, 0, '消息服务', 'message_service', 1, 0);
INSERT INTO `fly_sys_method` VALUES (291, 0, '消息服务', 'message_service', 1, 0);
INSERT INTO `fly_sys_method` VALUES (292, 0, '消息服务', 'message_service', 1, 0);



-- 部门管理
INSERT INTO `fly_sys_dept` VALUES('1','技术部','0','1','1','12345677','02888133145','主要是用来产的哟');
INSERT INTO `fly_sys_dept` VALUES('2','商务部','0','0','1','028 8976214','028 8976214','');
INSERT INTO `fly_sys_dept` VALUES('6','行政部','0','1','1','02861833149','02861833149','');

-- 职位数据
INSERT INTO `fly_sys_position` VALUES('1','董事会','0','1','1','董事会，管理全公司的信息的');
INSERT INTO `fly_sys_position` VALUES('2','总经理','1','10','1','');
INSERT INTO `fly_sys_position` VALUES('3','财务总监','1','20','1','');
INSERT INTO `fly_sys_position` VALUES('4','人事总监','1','21','0','');
INSERT INTO `fly_sys_position` VALUES('5','技术总监','1','31','1','');

-- 权限维护
INSERT IGNORE INTO `fly_sys_role` (`id`, `sort`, `visible`, `name`, `intro`)  VALUES (1, 1, 1, '超级管理员', '权限介绍,这是最高管理权限');
INSERT IGNORE INTO `fly_sys_power` (`id`, `master`, `master_value`, `access`, `access_value`, `operation`) VALUES (1, 'role', '1', 'SYS_MENU', '1', NULL);
INSERT IGNORE INTO `fly_sys_power` (`id`, `master`, `master_value`, `access`, `access_value`, `operation`) VALUES (2, 'role', '1', 'SYS_METHOD', '1', NULL);

-- 系统管理员
INSERT INTO `fly_sys_user` (`id`, `account`, `password`, `name`, `gender`, `tel`, `mobile`, `qicq`, `address`, `zipcode`, `email`, `roleID`, `deptID`, `positionID`, `intro`, `adt`, `identity`) VALUES (1, 'admin', '$2a$10$K7U.Xolbbz3fGsAzpIawmeQuTWt/W0TXA8DpugqRwWsE0PeRSi1Vu', '管理员', '1', '', '', '', '', '', '', '1', 1, 5, '', NULL, NULL);
INSERT INTO `fly_sys_user_role` (`id`, `role_id`, `user_id`) VALUES (1, 1, 1);

-- 系统参数
INSERT INTO `fly_sys_config` VALUES('1','系统根网址： ','cfg_basehost','http://www.zostar.com','string','0');
INSERT INTO `fly_sys_config` VALUES('2','主页链接名： ','cfg_indexname','零壹CRM','string','0');
INSERT INTO `fly_sys_config` VALUES('3','系统名称:','cfg_webname','零壹客户管理系统','string','0');
INSERT INTO `fly_sys_config` VALUES('4','系统版信息:','cfg_powerby','零壹星球','bstring','0');
INSERT INTO `fly_sys_config` VALUES('5','每张默认关键字： ','cfg_keywords','零壹星球','bstring','0');
INSERT INTO `fly_sys_config` VALUES('6','系统描述:','cfg_intro','零壹客户管理系统','bstring','0');
INSERT INTO `fly_sys_config` VALUES('7','系统主页链接： ','cfg_indexurl','/','string','0');

-- 字典分类
INSERT INTO `cst_dict_type` VALUES('1','客户等级','','level','0','1','','','');
INSERT INTO `cst_dict_type` VALUES('2','隶属行业','','trade','0','1','','','');
INSERT INTO `cst_dict_type` VALUES('3','经济类型','','ecotype','0','1','','','');
INSERT INTO `cst_dict_type` VALUES('4','客户来源','','source','0','1','','','');
INSERT INTO `cst_dict_type` VALUES('5','销售方式','','salemode','0','1','','','');
INSERT INTO `cst_dict_type` VALUES('6','销售阶段','','salestage','0','1','','','');
INSERT INTO `cst_dict_type` VALUES('7','服务类型','','services','0','1','','','');
INSERT INTO `cst_dict_type` VALUES('8','服务方式','','servicesmodel','0','1','','','');
INSERT INTO `cst_dict_type` VALUES('9','消息类型','','messagetype','0','1','','','');

-- 字典管理
INSERT INTO `cst_dict` VALUES('1','VIP客户','level','3','1');
INSERT INTO `cst_dict` VALUES('23','一般客户','level','4','1');
INSERT INTO `cst_dict` VALUES('24','工业品企业','trade','1','1');
INSERT INTO `cst_dict` VALUES('25','国有经济','ecotype','1','1');
INSERT INTO `cst_dict` VALUES('26','集体经济','ecotype','2','1');
INSERT INTO `cst_dict` VALUES('27','私营经济','ecotype','3','1');
INSERT INTO `cst_dict` VALUES('28','个体经济','ecotype','4','1');
INSERT INTO `cst_dict` VALUES('29','联营经济','ecotype','5','1');
INSERT INTO `cst_dict` VALUES('30','股份制经济','ecotype','6','1');
INSERT INTO `cst_dict` VALUES('31','外商投资经济','ecotype','7','1');
INSERT INTO `cst_dict` VALUES('32','港澳台投资经济','ecotype','8','1');
INSERT INTO `cst_dict` VALUES('33','其它经济','ecotype','9','1');
INSERT INTO `cst_dict` VALUES('34','客户介绍','source','1','1');
INSERT INTO `cst_dict` VALUES('35','电话来访','source','2','1');
INSERT INTO `cst_dict` VALUES('36','独立开发','source','3','1');
INSERT INTO `cst_dict` VALUES('37','电话','salemode','1','1');
INSERT INTO `cst_dict` VALUES('38','初期沟通','salestage','3','0');
INSERT INTO `cst_dict` VALUES('39','立项评估','salestage','2','0');
INSERT INTO `cst_dict` VALUES('40','需求分析','salestage','3','0');
INSERT INTO `cst_dict` VALUES('41','方案制定','salestage','4','0');
INSERT INTO `cst_dict` VALUES('42','商务谈判','salestage','5','0');
INSERT INTO `cst_dict` VALUES('43','合同签订','salestage','6','0');
INSERT INTO `cst_dict` VALUES('44','失单','salestage','7','0');
INSERT INTO `cst_dict` VALUES('45','投诉','services','1','1');
INSERT INTO `cst_dict` VALUES('46','培训','services','2','1');
INSERT INTO `cst_dict` VALUES('47','升级','services','3','1');
INSERT INTO `cst_dict` VALUES('48','互联网企业','trade','1','1');
INSERT INTO `cst_dict` VALUES('49','电话 ','servicesmodel','1','1');
INSERT INTO `cst_dict` VALUES('50','QQ','servicesmodel','2','1');
INSERT INTO `cst_dict` VALUES('51','服务行业','trade','1','1');
INSERT INTO `cst_dict` VALUES('52','网络资源','source','4','1');
INSERT INTO `cst_dict` VALUES('53','上门','salemode','2','1');
INSERT INTO `cst_dict` VALUES('54','维护','services','4','1');
INSERT INTO `cst_dict` VALUES('55','现场','servicesmodel','3','1');
INSERT INTO `cst_dict` VALUES('56','邮寄','salemode','3','1');
INSERT INTO `cst_dict` VALUES('57','网络','salemode','4','1');
INSERT INTO `cst_dict` VALUES('58','网络','servicesmodel','4','1');
INSERT INTO `cst_dict` VALUES('59','消费品企业','trade','1','1');
INSERT INTO `cst_dict` VALUES('60','原材料企业','trade','1','1');
INSERT INTO `cst_dict` VALUES('61','农业企业','trade','1','1');
INSERT INTO `cst_dict` VALUES('62','没接电话','talk','1','1');
INSERT INTO `cst_dict` VALUES('63','不需要','talk','2','1');
INSERT INTO `cst_dict` VALUES('64','挂了','talk','3','1');
INSERT INTO `cst_dict` VALUES('65','空号','talk','4','1');
INSERT INTO `cst_dict` VALUES('66','加微信号','talk','5','1');
INSERT INTO `cst_dict` VALUES('67','超级客户1','level','0','1');
INSERT INTO `cst_dict` VALUES('68','超级客户2','level','0','1');
INSERT INTO `cst_dict` VALUES('69','节日祝福','messagetype','1','1');
INSERT INTO `cst_dict` VALUES('70','新品推荐','messagetype','1','1');
INSERT INTO `cst_dict` VALUES('71','合同到期','messagetype','1','1');
INSERT INTO `cst_dict` VALUES('72','联系人预约','messagetype','1','1');
INSERT INTO `cst_dict` VALUES('73','服务记录预约','messagetype','1','1');
INSERT INTO `cst_dict` VALUES('74','销售机会预约','messagetype','1','1');
INSERT INTO `cst_dict` VALUES('75','跟踪记录预约','messagetype','1','1');
INSERT INTO `cst_dict` VALUES('76','供应商联系人预约','messagetype','1','1');

-- 扩展字段数据
INSERT INTO `cst_field_ext` (`field_ext_id`, `main_table`, `ext_table`, `show_name`, `field_name`, `field_type`, `default_value`, `maxlength`, `desc`, `visible`, `is_system`, `is_must`, `sort`, `create_time`, `create_user_id`) VALUES (2, 'cst_customer', 'cst_customer', '客户代表', 'linkman', 'varchar', '', '250', '', 1, 1, 1, 0, '2019-05-28 12:15:19', 1);
INSERT INTO `cst_field_ext` (`field_ext_id`, `main_table`, `ext_table`, `show_name`, `field_name`, `field_type`, `default_value`, `maxlength`, `desc`, `visible`, `is_system`, `is_must`, `sort`, `create_time`, `create_user_id`) VALUES (3, 'cst_customer', 'cst_customer', '客户来源', 'source', 'option', '网络,客户介绍,主动开发', '250', '', 1, 1, 1, 0, '2019-05-28 12:16:35', 1);
INSERT INTO `cst_field_ext` (`field_ext_id`, `main_table`, `ext_table`, `show_name`, `field_name`, `field_type`, `default_value`, `maxlength`, `desc`, `visible`, `is_system`, `is_must`, `sort`, `create_time`, `create_user_id`) VALUES (4, 'cst_customer', 'cst_customer', '客户等级', 'grade', 'option', '普通客户,一般客户,重点客户', '250', '', 1, 1, 1, 0, '2019-05-28 12:17:40', 1);
INSERT INTO `cst_field_ext` (`field_ext_id`, `main_table`, `ext_table`, `show_name`, `field_name`, `field_type`, `default_value`, `maxlength`, `desc`, `visible`, `is_system`, `is_must`, `sort`, `create_time`, `create_user_id`) VALUES (5, 'cst_customer', 'cst_customer', '客户行业', 'industry', 'option', '互联网企业,服务行业,原材料企业', '250', '', 1, 1, 1, 0, '2019-05-28 12:19:04', 1);
INSERT INTO `cst_field_ext` (`field_ext_id`, `main_table`, `ext_table`, `show_name`, `field_name`, `field_type`, `default_value`, `maxlength`, `desc`, `visible`, `is_system`, `is_must`, `sort`, `create_time`, `create_user_id`) VALUES (6, 'cst_customer', 'cst_customer', '联系手机', 'mobile', 'varchar', '', '250', '', 1, 1, 1, 0, '2019-05-28 12:20:17', 1);
INSERT INTO `cst_field_ext` (`field_ext_id`, `main_table`, `ext_table`, `show_name`, `field_name`, `field_type`, `default_value`, `maxlength`, `desc`, `visible`, `is_system`, `is_must`, `sort`, `create_time`, `create_user_id`) VALUES (7, 'cst_customer', 'cst_customer', '联系电话', 'tel', 'varchar', '', '250', '', 1, 1, 1, 0, '2019-05-28 12:20:25', 1);
INSERT INTO `cst_field_ext` (`field_ext_id`, `main_table`, `ext_table`, `show_name`, `field_name`, `field_type`, `default_value`, `maxlength`, `desc`, `visible`, `is_system`, `is_must`, `sort`, `create_time`, `create_user_id`) VALUES (8, 'cst_customer', 'cst_customer', '联系地址', 'address', 'varchar', '', '250', '', 1, 1, 1, 0, '2019-05-28 12:20:33', 1);
INSERT INTO `cst_field_ext` (`field_ext_id`, `main_table`, `ext_table`, `show_name`, `field_name`, `field_type`, `default_value`, `maxlength`, `desc`, `visible`, `is_system`, `is_must`, `sort`, `create_time`, `create_user_id`) VALUES (9, 'cst_customer', 'cst_customer', '客户介绍', 'intro', 'textarea', '', '250', '', 1, 1, 1, 0, '2019-05-28 12:20:54', 1);

