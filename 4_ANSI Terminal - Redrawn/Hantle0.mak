# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Hantle0 - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Hantle0 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Hantle0 - Win32 Release" && "$(CFG)" !=\
 "Hantle0 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Hantle0.mak" CFG="Hantle0 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Hantle0 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Hantle0 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "Hantle0 - Win32 Debug"
RSC=rc.exe
MTL=mktyplib.exe
CPP=cl.exe

!IF  "$(CFG)" == "Hantle0 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\Hantle0.exe"

CLEAN : 
	-@erase "$(INTDIR)\CommPort.obj"
	-@erase "$(INTDIR)\Hantle0.obj"
	-@erase "$(INTDIR)\Hantle0.pch"
	-@erase "$(INTDIR)\Hantle0.res"
	-@erase "$(INTDIR)\Hantle0Doc.obj"
	-@erase "$(INTDIR)\Hantle0View.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\Modem.obj"
	-@erase "$(INTDIR)\MonitorThread.obj"
	-@erase "$(INTDIR)\SetPortDlg.obj"
	-@erase "$(INTDIR)\SetTerminalDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TermANSI.obj"
	-@erase "$(OUTDIR)\Hantle0.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Hantle0.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x412 /fo"$(INTDIR)/Hantle0.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Hantle0.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Hantle0.pdb" /machine:I386 /out:"$(OUTDIR)/Hantle0.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CommPort.obj" \
	"$(INTDIR)\Hantle0.obj" \
	"$(INTDIR)\Hantle0.res" \
	"$(INTDIR)\Hantle0Doc.obj" \
	"$(INTDIR)\Hantle0View.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Modem.obj" \
	"$(INTDIR)\MonitorThread.obj" \
	"$(INTDIR)\SetPortDlg.obj" \
	"$(INTDIR)\SetTerminalDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TermANSI.obj"

"$(OUTDIR)\Hantle0.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\Hantle0.exe"

CLEAN : 
	-@erase "$(INTDIR)\CommPort.obj"
	-@erase "$(INTDIR)\Hantle0.obj"
	-@erase "$(INTDIR)\Hantle0.pch"
	-@erase "$(INTDIR)\Hantle0.res"
	-@erase "$(INTDIR)\Hantle0Doc.obj"
	-@erase "$(INTDIR)\Hantle0View.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\Modem.obj"
	-@erase "$(INTDIR)\MonitorThread.obj"
	-@erase "$(INTDIR)\SetPortDlg.obj"
	-@erase "$(INTDIR)\SetTerminalDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TermANSI.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Hantle0.exe"
	-@erase "$(OUTDIR)\Hantle0.ilk"
	-@erase "$(OUTDIR)\Hantle0.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Hantle0.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x412 /fo"$(INTDIR)/Hantle0.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Hantle0.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Hantle0.pdb" /debug /machine:I386 /out:"$(OUTDIR)/Hantle0.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CommPort.obj" \
	"$(INTDIR)\Hantle0.obj" \
	"$(INTDIR)\Hantle0.res" \
	"$(INTDIR)\Hantle0Doc.obj" \
	"$(INTDIR)\Hantle0View.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Modem.obj" \
	"$(INTDIR)\MonitorThread.obj" \
	"$(INTDIR)\SetPortDlg.obj" \
	"$(INTDIR)\SetTerminalDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TermANSI.obj"

"$(OUTDIR)\Hantle0.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "Hantle0 - Win32 Release"
# Name "Hantle0 - Win32 Debug"

!IF  "$(CFG)" == "Hantle0 - Win32 Release"

!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "Hantle0 - Win32 Release"

!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Hantle0.cpp
DEP_CPP_HANTL=\
	".\CommPort.h"\
	".\Hantle0.h"\
	".\Hantle0Doc.h"\
	".\Hantle0View.h"\
	".\MainFrm.h"\
	".\Modem.h"\
	".\StdAfx.h"\
	".\TermANSI.h"\
	

"$(INTDIR)\Hantle0.obj" : $(SOURCE) $(DEP_CPP_HANTL) "$(INTDIR)"\
 "$(INTDIR)\Hantle0.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Hantle0 - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Hantle0.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Hantle0.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Hantle0.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Hantle0.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\CommPort.h"\
	".\Hantle0.h"\
	".\Hantle0Doc.h"\
	".\MainFrm.h"\
	".\Modem.h"\
	".\StdAfx.h"\
	".\TermANSI.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Hantle0.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Hantle0Doc.cpp
DEP_CPP_HANTLE=\
	".\CommPort.h"\
	".\Hantle0.h"\
	".\Hantle0Doc.h"\
	".\Hantle0View.h"\
	".\Modem.h"\
	".\StdAfx.h"\
	".\TermANSI.h"\
	

"$(INTDIR)\Hantle0Doc.obj" : $(SOURCE) $(DEP_CPP_HANTLE) "$(INTDIR)"\
 "$(INTDIR)\Hantle0.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Hantle0View.cpp
DEP_CPP_HANTLE0=\
	".\CommPort.h"\
	".\Hantle0.h"\
	".\Hantle0Doc.h"\
	".\Hantle0View.h"\
	".\Modem.h"\
	".\SetPortDlg.h"\
	".\SetTerminalDlg.h"\
	".\StdAfx.h"\
	".\TermANSI.h"\
	

"$(INTDIR)\Hantle0View.obj" : $(SOURCE) $(DEP_CPP_HANTLE0) "$(INTDIR)"\
 "$(INTDIR)\Hantle0.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Hantle0.rc
DEP_RSC_HANTLE0_=\
	".\res\Hantle0.ico"\
	".\res\Hantle0.rc2"\
	".\res\Hantle0Doc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\Hantle0.res" : $(SOURCE) $(DEP_RSC_HANTLE0_) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\MonitorThread.cpp
DEP_CPP_MONIT=\
	".\CommPort.h"\
	".\MonitorThread.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MonitorThread.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 "$(INTDIR)\Hantle0.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CommPort.cpp
DEP_CPP_COMMP=\
	".\CommPort.h"\
	".\MonitorThread.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CommPort.obj" : $(SOURCE) $(DEP_CPP_COMMP) "$(INTDIR)"\
 "$(INTDIR)\Hantle0.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Modem.cpp
DEP_CPP_MODEM=\
	".\CommPort.h"\
	".\Modem.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Modem.obj" : $(SOURCE) $(DEP_CPP_MODEM) "$(INTDIR)"\
 "$(INTDIR)\Hantle0.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\SetPortDlg.cpp
DEP_CPP_SETPO=\
	".\CommPort.h"\
	".\Hantle0.h"\
	".\Hantle0Doc.h"\
	".\Modem.h"\
	".\SetPortDlg.h"\
	".\StdAfx.h"\
	".\TermANSI.h"\
	

"$(INTDIR)\SetPortDlg.obj" : $(SOURCE) $(DEP_CPP_SETPO) "$(INTDIR)"\
 "$(INTDIR)\Hantle0.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\SetTerminalDlg.cpp
DEP_CPP_SETTE=\
	".\CommPort.h"\
	".\Hantle0.h"\
	".\Hantle0Doc.h"\
	".\Hantle0View.h"\
	".\Modem.h"\
	".\SetTerminalDlg.h"\
	".\StdAfx.h"\
	".\TermANSI.h"\
	

"$(INTDIR)\SetTerminalDlg.obj" : $(SOURCE) $(DEP_CPP_SETTE) "$(INTDIR)"\
 "$(INTDIR)\Hantle0.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\TermANSI.cpp
DEP_CPP_TERMA=\
	".\CommPort.h"\
	".\Hantle0Doc.h"\
	".\Hantle0View.h"\
	".\Modem.h"\
	".\StdAfx.h"\
	".\TermANSI.h"\
	

"$(INTDIR)\TermANSI.obj" : $(SOURCE) $(DEP_CPP_TERMA) "$(INTDIR)"\
 "$(INTDIR)\Hantle0.pch"


# End Source File
# End Target
# End Project
################################################################################
