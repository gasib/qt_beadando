@echo off
SetLocal EnableDelayedExpansion
(set PATH=E:\Qt\6.4.0\mingw_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=E:\Qt\6.4.0\mingw_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=E:\Qt\6.4.0\mingw_64\plugins
)
%*
EndLocal
