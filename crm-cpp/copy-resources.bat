@rem �ر����������
@echo off
setlocal enabledelayedexpansion

@rem ===================���ƻ�����===================
echo --------------------------------
echo ���������ڸ���demo�б�����Դ������ģ����
echo ��Ҫ�������½�ģ������,(������ģ�����ڵ��ļ���·��)
set /p "newm=����ģ������(�磺sample)��"
echo --------------------------------
@rem ================================================

@rem ִ�и����߼�
xcopy arch-demo !newm! /S /Y /EXCLUDE:exclude.txt
@rem ����һЩ��Ŀ¼��֤�ṹ����
md !newm!\dao !newm!\service !newm!\domain\vo !newm!\domain\query !newm!\domain\dto
type nul > !newm!\zh-dict.yaml
type nul > !newm!\dao\.keep
type nul > !newm!\service\.keep
type nul > !newm!\domain\vo\.keep
type nul > !newm!\domain\query\.keep
type nul > !newm!\domain\dto\.keep
echo �ļ��������
pause