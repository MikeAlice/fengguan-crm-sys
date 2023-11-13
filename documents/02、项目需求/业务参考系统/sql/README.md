# 执行`SQL`注意事项

***注意：这里存放初始的数据库结构，如果后续根据业务需要对数据库进行了修改，需要将新的数据库脚本备份到此目录下面。***

`SQL`文件说明:

- `zocrm_sys.sql`：数据库导出数据脚本，包括：建库、建表、测试数据。
- `zocrm_sys_struct`：数据库表结构，包括：建库、建表。
- `zocrm_sys_init.sql`：用于插入一些系统初始数据，需要根据系统情况维护此脚本文件。

在执行 `SQL` 文件的时候如果运行报错的话，检查你的 `sql_mode` 是否删除了下面的选项：

```txt
ONLY_FULL_GROUP_BY
NO_ZERO_DAT
NO_ZERO_IN_DATE
```

你可以通过下面命令行查看`sql_mode`情况

```sql
# 查看当前sql_mode
select @@sql_mode;
# 查看全局sql_mode
select @@global.sql_mode;
```

你可以通过下列指令修改（服务器重启后将会失效）

```sql
# 修改全局
set @@global.sql_mode = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';
# 修改当前
set @@sql_mode = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';
```

想要永久生效需要修改`my.ini`配置文件

在导入`sql`的时候还有可能因为数据库`max_allowed_packet`过小导致问题，通过下面命令修改

```	sql
set global max_allowed_packet=1024102416;
```

