# Microsoft Developer Studio Project File - Name="WinGraphviz" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=WinGraphviz - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WinGraphviz.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WinGraphviz.mak" CFG="WinGraphviz - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WinGraphviz - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "WinGraphviz - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/WinGraphviz", BAAAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WinGraphviz - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /G5 /MTd /W3 /ZI /Od /I "." /I "..\graphviz-1.8.10" /I "..\graphviz-1.8.10\graph" /I "..\graphviz-1.8.10\cdt" /I "..\graphviz-1.8.10\pathplan" /I "..\graphviz-1.8.10\dotneato\common" /I "..\graphviz-1.8.10\dotneato\dotgen" /I "..\graphviz-1.8.10\dotneato\neatogen" /I "..\zlib" /I "..\graphviz-1.8.10\dotneato\twopigen" /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "MSWIN32" /D "HAVE_CONFIG_H" /FR /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x404 /d "_DEBUG"
# ADD RSC /l 0x404 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib libdotneato.lib libgraph.lib libdot.lib libcdt.lib libpathplan.lib libneato.lib libpack.lib libgd.lib libpng.lib zlib.lib freetype.lib libtwopi.lib libjpeg.lib /nologo /version:1.0 /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept /libpath:"D:\Project\graphviz-1.8.10\lib\Debug" /libpath:"D:\Project\lib\Debug"
# SUBTRACT LINK32 /incremental:no
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=.\Debug\WinGraphviz.dll
InputPath=.\Debug\WinGraphviz.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "WinGraphviz - Win32 Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinDependency"
# PROP BASE Intermediate_Dir "ReleaseMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinDependency"
# PROP Intermediate_Dir "ReleaseMinDependency"
# PROP Ignore_Export_Lib 1
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /I "." /I "..\graphviz-1.8.10" /I "..\graphviz-1.8.10\graph" /I "..\graphviz-1.8.10\cdt" /I "..\graphviz-1.8.10\pathplan" /I "..\graphviz-1.8.10\dotneato\common" /I "..\graphviz-1.8.10\dotneato\dotgen" /I "..\graphviz-1.8.10\dotneato\neatogen" /I "..\graphviz-1.8.10\dotneato\twopigen" /I "..\zlib" /D "NDEBUG" /D "_MBCS" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "MSWIN32" /FR /V"ERBOSE:LIB" /FD /LD -o3 /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib libdotneato.lib libgraph.lib libdot.lib libcdt.lib libpathplan.lib libneato.lib libpack.lib libgd.lib libpng.lib zlib.lib freetype.lib libtwopi.lib libjpeg.lib /nologo /subsystem:windows /dll /pdb:none /machine:I386 /libpath:"C:\Project\graphviz-1.8.10\lib\Release" /libpath:"C:\Project\lib\Release"
# SUBTRACT LINK32 /profile /map /debug /nodefaultlib
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\WinGraphviz.dll
InputPath=.\ReleaseMinDependency\WinGraphviz.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "WinGraphviz - Win32 Debug"
# Name "WinGraphviz - Win32 Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\dotneato.c
# End Source File
# Begin Source File

SOURCE="..\graphviz-1.8.10\tools\error\Error_win32_com_Imp.cpp"
# End Source File
# Begin Source File

SOURCE=.\IBinaryImage.cpp
# End Source File
# Begin Source File

SOURCE=.\IDOT.cpp
# End Source File
# Begin Source File

SOURCE=.\INEATO.cpp
# End Source File
# Begin Source File

SOURCE=.\ITWOPI.cpp
# End Source File
# Begin Source File

SOURCE="..\jpeg-6b\jmemnobs.c"
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Tools.cpp
# End Source File
# Begin Source File

SOURCE=.\WinGraphviz.cpp
# End Source File
# Begin Source File

SOURCE=.\WinGraphviz.def
# End Source File
# Begin Source File

SOURCE=.\WinGraphviz.idl
# ADD MTL /tlb ".\WinGraphviz.tlb" /h "WinGraphviz.h" /iid "WinGraphviz_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\WinGraphviz.rc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\dotneato.h
# End Source File
# Begin Source File

SOURCE=.\ErrorImp.h
# End Source File
# Begin Source File

SOURCE=.\IBinaryImage.h
# End Source File
# Begin Source File

SOURCE=.\IDOT.h
# End Source File
# Begin Source File

SOURCE=.\INEATO.h
# End Source File
# Begin Source File

SOURCE=.\ITWOPI.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Tools.h
# End Source File
# Begin Source File

SOURCE=.\WinGraphviz.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\BinaryImage.rgs
# End Source File
# Begin Source File

SOURCE=.\DOT.rgs
# End Source File
# Begin Source File

SOURCE=.\NEATO.rgs
# End Source File
# Begin Source File

SOURCE=.\TWOPI.rgs
# End Source File
# End Group
# End Target
# End Project
