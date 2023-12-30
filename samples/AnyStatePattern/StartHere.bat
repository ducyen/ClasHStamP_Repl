@echo off
rem Batch file to run a sample of Astah API on Windows

setlocal

set ASTAH_HOME=C:\Program Files\astah-professional
rem set PATH=%ASTAH_HOME%\jre\bin;%PATH%;
SET TOOL_DIR=..\..\release
SET PROJECT=Design.asta
SET EXT_CODE_OPT=y
SET ENCODING=UTF-8
SET JAVA_TOOL_OPTIONS=-Dfile.encoding=UTF-8

pushd "..\..\"

rem pushd %~dp0
set BAT_DIR=%CD%
set BIN_DIR="%BAT_DIR%\bin"
set RES_DIR=%BAT_DIR%\samples\AllSymbols
set LIB_DIR=%BAT_DIR%\lib
rem popd

if exist "%ASTAH_HOME%\jre\bin\javaw.exe" set PATH=%ASTAH_HOME%\jre\bin;%PATH%

rem Remove "rem" from following two lines, if you'd like to use j2sdk.
rem set JAVA_HOME=C:\jdk1.7.0_45
rem set PATH=%JAVA_HOME%\bin;%PATH%

set ASTAH_COM_JAR="%ASTAH_HOME%\astah-community.jar"
set ASTAH_UML_JAR="%ASTAH_HOME%\astah-uml.jar"
set ASTAH_PRO_JAR="%ASTAH_HOME%\astah-pro.jar"
set ASTAH_JAR=%ASTAH_COM_JAR%;%ASTAH_UML_JAR%;%ASTAH_PRO_JAR%
set API_JAR="%ASTAH_HOME%\astah-api.jar"

set CSV_JAR="%LIB_DIR%\commons-csv-1.1.jar"
set LOG_JAR="%LIB_DIR%\logback-loader-1.0.9b.jar"
set SLF_JAR="%LIB_DIR%\slf4j-api-1.6.6.jar"

set CLASSPATH=%BIN_DIR%;%ASTAH_JAR%;%API_JAR%;%CSV_JAR%;%LOG_JAR%;%SLF_JAR%

set INITIAL_HEAP_SIZE=16m
set MAXIMUM_HEAP_SIZE=256m

set JAVA_OPTS=-Xms%INITIAL_HEAP_SIZE% -Xmx%MAXIMUM_HEAP_SIZE%
set JAVA_OPTS=%JAVA_OPTS% -classpath %CLASSPATH%

popd

cmd -c
