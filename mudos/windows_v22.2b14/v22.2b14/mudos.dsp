# Microsoft Developer Studio Project File - Name="mudos" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=mudos - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mudos.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mudos.mak" CFG="mudos - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mudos - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mudos - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mudos - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /FR /YX /c
# ADD CPP /nologo /G4 /W3 /GX /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "WIN95" /D "MSDOS" /YX /FD /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /machine:IX86

!ELSEIF  "$(CFG)" == "mudos - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WinDebug"
# PROP Intermediate_Dir "WinDebug"
# PROP Ignore_Export_Lib 0
# ADD BASE CPP /nologo /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /FR /YX /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "MSDOS" /D "WINNT" /YX /FD /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "mudos - Win32 Release"
# Name "mudos - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\add_action.c
# End Source File
# Begin Source File

SOURCE=.\add_action.h
# End Source File
# Begin Source File

SOURCE=.\applies.c
# End Source File
# Begin Source File

SOURCE=.\applies.h
# End Source File
# Begin Source File

SOURCE=.\array.c
# End Source File
# Begin Source File

SOURCE=.\avltree.c
# End Source File
# Begin Source File

SOURCE=.\backend.c
# End Source File
# Begin Source File

SOURCE=.\binaries.c
# End Source File
# Begin Source File

SOURCE=.\buffer.c
# End Source File
# Begin Source File

SOURCE=.\call_out.c
# End Source File
# Begin Source File

SOURCE=.\ccode.c
# End Source File
# Begin Source File

SOURCE=.\cfuns.c
# End Source File
# Begin Source File

SOURCE=.\class.c
# End Source File
# Begin Source File

SOURCE=.\comm.c
# End Source File
# Begin Source File

SOURCE=.\compile_file.c
# End Source File
# Begin Source File

SOURCE=.\compiler.c
# End Source File
# Begin Source File

SOURCE=.\packages\contrib.c
# End Source File
# Begin Source File

SOURCE=.\crc32.c
# End Source File
# Begin Source File

SOURCE=.\amiga\crypt.c
# End Source File
# Begin Source File

SOURCE=.\packages\develop.c
# End Source File
# Begin Source File

SOURCE=.\disassembler.c
# End Source File
# Begin Source File

SOURCE=.\dumpstat.c
# End Source File
# Begin Source File

SOURCE=.\ed.c
# End Source File
# Begin Source File

SOURCE=.\efuns_main.c
# End Source File
# Begin Source File

SOURCE=.\efuns_port.c
# End Source File
# Begin Source File

SOURCE=.\eoperators.c
# End Source File
# Begin Source File

SOURCE=.\file.c
# End Source File
# Begin Source File

SOURCE=.\function.c
# End Source File
# Begin Source File

SOURCE=.\function.h
# End Source File
# Begin Source File

SOURCE=.\generate.c
# End Source File
# Begin Source File

SOURCE=.\grammar.c
# End Source File
# Begin Source File

SOURCE=.\hash.c
# End Source File
# Begin Source File

SOURCE=.\icode.c
# End Source File
# Begin Source File

SOURCE=.\mudlib\interface.c
# End Source File
# Begin Source File

SOURCE=.\interpret.c
# End Source File
# Begin Source File

SOURCE=.\lex.c
# End Source File
# Begin Source File

SOURCE=.\local_options
# End Source File
# Begin Source File

SOURCE=.\main.c
# End Source File
# Begin Source File

SOURCE=.\mapping.c
# End Source File
# Begin Source File

SOURCE=.\master.c
# End Source File
# Begin Source File

SOURCE=.\master.h
# End Source File
# Begin Source File

SOURCE=.\packages\math.c
# End Source File
# Begin Source File

SOURCE=.\md.c
# End Source File
# Begin Source File

SOURCE=.\packages\mudlib_stats.c
# End Source File
# Begin Source File

SOURCE=.\packages\mudlib_stats.h
# End Source File
# Begin Source File

SOURCE=.\object.c
# End Source File
# Begin Source File

SOURCE=.\otable.c
# End Source File
# Begin Source File

SOURCE=.\parse.c
# End Source File
# Begin Source File

SOURCE=.\port.c
# End Source File
# Begin Source File

SOURCE=.\program.c
# End Source File
# Begin Source File

SOURCE=.\qsort.c
# End Source File
# Begin Source File

SOURCE=.\rc.c
# End Source File
# Begin Source File

SOURCE=.\reclaim.c
# End Source File
# Begin Source File

SOURCE=.\regexp.c
# End Source File
# Begin Source File

SOURCE=.\replace_program.c
# End Source File
# Begin Source File

SOURCE=.\scratchpad.c
# End Source File
# Begin Source File

SOURCE=.\simul_efun.c
# End Source File
# Begin Source File

SOURCE=.\simulate.c
# End Source File
# Begin Source File

SOURCE=.\socket_ctrl.c
# End Source File
# Begin Source File

SOURCE=.\socket_efuns.c
# End Source File
# Begin Source File

SOURCE=.\socket_err.c
# End Source File
# Begin Source File

SOURCE=.\packages\sockets.c
# End Source File
# Begin Source File

SOURCE=.\sprintf.c
# End Source File
# Begin Source File

SOURCE=.\stralloc.c
# End Source File
# Begin Source File

SOURCE=.\swap.c
# End Source File
# Begin Source File

SOURCE=.\trees.c
# End Source File
# Begin Source File

SOURCE=.\packages\uids.c
# End Source File
# Begin Source File

SOURCE=.\packages\uids.h
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\backend.h
# End Source File
# Begin Source File

SOURCE=.\comm.h
# End Source File
# Begin Source File

SOURCE=.\compiler.h
# End Source File
# Begin Source File

SOURCE=.\debug.h
# End Source File
# Begin Source File

SOURCE=.\ed.h
# End Source File
# Begin Source File

SOURCE=.\eoperators.h
# End Source File
# Begin Source File

SOURCE=.\file.h
# End Source File
# Begin Source File

SOURCE=.\generate.h
# End Source File
# Begin Source File

SOURCE=.\lex.h
# End Source File
# Begin Source File

SOURCE=.\lpc_incl.h
# End Source File
# Begin Source File

SOURCE=.\main.h
# End Source File
# Begin Source File

SOURCE=.\network_incl.h
# End Source File
# Begin Source File

SOURCE=.\scratchpad.h
# End Source File
# Begin Source File

SOURCE=.\simul_efun.h
# End Source File
# Begin Source File

SOURCE=.\socket_ctrl.h
# End Source File
# Begin Source File

SOURCE=.\socket_efuns.h
# End Source File
# Begin Source File

SOURCE=.\std.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
