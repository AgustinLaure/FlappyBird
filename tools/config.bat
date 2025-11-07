set projectDir=%~1
set outDir=%~2

@echo off

echo "Copiando archivos..."

copy "%projectDir%\include\raylib-5.5_win32_msvc16\*.dll" "%outDir%"  /y
xcopy "%projectDir%\res" "%outDir%\res" /y /i /e /s