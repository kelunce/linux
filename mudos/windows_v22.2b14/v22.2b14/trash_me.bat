@echo off
cl -DWIN32 -D_ALL_SOURCE -G4 comptest.c -o comptest 
if errorlevel == 1 goto error
del trash_me.err >nul
goto ok
:error
echo ERROR > trash_me.err
:ok
