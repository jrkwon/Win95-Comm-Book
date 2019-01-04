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
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

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

ALL : ".\Release\Hantle0.exe"

CLEAN : 
	-@erase ".\Release\CommPort.obj"
	-@erase ".\Release\Hantle0.exe"
	-@erase ".\Release\Hantle0.obj"
	-@erase ".\Release\Hantle0.pch"
	-@erase ".\Release\Hantle0.res"
	-@erase ".\Release\Hantle0Doc.obj"
	-@erase ".\Release\Hantle0View.obj"
	-@erase ".\Release\MainFrm.obj"
	-@erase ".\Release\Modem.obj"
	-@erase ".\Release\MonitorThread.obj"
	-@erase ".\Release\StdAfx.obj"

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
	".\Release\CommPort.obj" \
	".\Release\Hantle0.obj" \
	".\Release\Hantle0.res" \
	".\Release\Hantle0Doc.obj" \
	".\Release\Hantle0View.obj" \
	".\Release\MainFrm.obj" \
	".\Release\Modem.obj" \
	".\Release\MonitorThread.obj" \
	".\Release\StdAfx.obj"

".\Release\Hantle0.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

ALL : ".\Debug\Hantle0.exe"

CLEAN : 
	-@erase ".\Debug\CommPort.obj"
	-@erase ".\Debug\Hantle0.exe"
	-@erase ".\Debug\Hantle0.ilk"
	-@erase ".\Debug\Hantle0.obj"
	-@erase ".\Debug\Hantle0.pch"
	-@erase ".\Debug\Hantle0.pdb"
	-@erase ".\Debug\Hantle0.res"
	-@erase ".\Debug\Hantle0Doc.obj"
	-@erase ".\Debug\Hantle0View.obj"
	-@erase ".\Debug\MainFrm.obj"
	-@erase ".\Debug\Modem.obj"
	-@erase ".\Debug\MonitorThread.obj"
	-@erase ".\Debug\StdAfx.obj"
	-@erase ".\Debug\vc40.idb"
	-@erase ".\Debug\vc40.pdb"

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
	".\Debug\CommPort.obj" \
	".\Debug\Hantle0.obj" \
	".\Debug\Hantle0.res" \
	".\Debug\Hantle0Doc.obj" \
	".\Debug\Hantle0View.obj" \
	".\Debug\MainFrm.obj" \
	".\Debug\Modem.obj" \
	".\Debug\MonitorThread.obj" \
	".\Debug\StdAfx.obj"

".\Debug\Hantle0.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
	

!IF  "$(CFG)" == "Hantle0 - Win32 Release"


".\Release\Hantle0.obj" : $(SOURCE) $(DEP_CPP_HANTL) "$(INTDIR)"\
 ".\Release\Hantle0.pch"


!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"


".\Debug\Hantle0.obj" : $(SOURCE) $(DEP_CPP_HANTL) "$(INTDIR)"\
 ".\Debug\Hantle0.pch"


!ENDIF 

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
	

".\Release\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

".\Release\Hantle0.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Hantle0.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

".\Debug\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

".\Debug\Hantle0.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\Hantle0.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Hantle0 - Win32 Release"


".\Release\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 ".\Release\Hantle0.pch"


!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"


".\Debug\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 ".\Debug\Hantle0.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Hantle0Doc.cpp

!IF  "$(CFG)" == "Hantle0 - Win32 Release"

DEP_CPP_HANTLE=\
	".\CommPort.h"\
	".\Hantle0.h"\
	".\Hantle0Doc.h"\
	".\Hantle0View.h"\
	".\Modem.h"\
	".\StdAfx.h"\
	

".\Release\Hantle0Doc.obj" : $(SOURCE) $(DEP_CPP_HANTLE) "$(INTDIR)"\
 ".\Release\Hantle0.pch"


!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"

DEP_CPP_HANTLE=\
	".\CommPort.h"\
	".\Hantle0.h"\
	".\Hantle0Doc.h"\
	".\Hantle0View.h"\
	".\Modem.h"\
	".\StdAfx.h"\
	

".\Debug\Hantle0Doc.obj" : $(SOURCE) $(DEP_CPP_HANTLE) "$(INTDIR)"\
 ".\Debug\Hantle0.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Hantle0View.cpp

!IF  "$(CFG)" == "Hantle0 - Win32 Release"

DEP_CPP_HANTLE0=\
	".\CommPort.h"\
	".\Hantle0.h"\
	".\Hantle0Doc.h"\
	".\Hantle0View.h"\
	".\Modem.h"\
	".\StdAfx.h"\
	

".\Release\Hantle0View.obj" : $(SOURCE) $(DEP_CPP_HANTLE0) "$(INTDIR)"\
 ".\Release\Hantle0.pch"


!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"

DEP_CPP_HANTLE0=\
	".\CommPort.h"\
	".\Hantle0.h"\
	".\Hantle0Doc.h"\
	".\Hantle0View.h"\
	".\Modem.h"\
	".\StdAfx.h"\
	

".\Debug\Hantle0View.obj" : $(SOURCE) $(DEP_CPP_HANTLE0) "$(INTDIR)"\
 ".\Debug\Hantle0.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Hantle0.rc
DEP_RSC_HANTLE0_=\
	".\res\Hantle0.ico"\
	".\res\Hantle0.rc2"\
	".\res\Hantle0Doc.ico"\
	".\res\Toolbar.bmp"\
	

!IF  "$(CFG)" == "Hantle0 - Win32 Release"


".\Release\Hantle0.res" : $(SOURCE) $(DEP_RSC_HANTLE0_) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"


".\Debug\Hantle0.res" : $(SOURCE) $(DEP_RSC_HANTLE0_) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MonitorThread.cpp
DEP_CPP_MONIT=\
	".\CommPort.h"\
	".\MonitorThread.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Hantle0 - Win32 Release"


".\Release\MonitorThread.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 ".\Release\Hantle0.pch"


!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"


".\Debug\MonitorThread.obj" : $(SOURCE) $(DEP_CPP_MONIT) "$(INTDIR)"\
 ".\Debug\Hantle0.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CommPort.cpp
DEP_CPP_COMMP=\
	".\CommPort.h"\
	".\MonitorThread.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Hantle0 - Win32 Release"


".\Release\CommPort.obj" : $(SOURCE) $(DEP_CPP_COMMP) "$(INTDIR)"\
 ".\Release\Hantle0.pch"


!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"


".\Debug\CommPort.obj" : $(SOURCE) $(DEP_CPP_COMMP) "$(INTDIR)"\
 ".\Debug\Hantle0.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Modem.cpp
DEP_CPP_MODEM=\
	".\CommPort.h"\
	".\Modem.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Hantle0 - Win32 Release"


".\Release\Modem.obj" : $(SOURCE) $(DEP_CPP_MODEM) "$(INTDIR)"\
 ".\Release\Hantle0.pch"


!ELSEIF  "$(CFG)" == "Hantle0 - Win32 Debug"


".\Debug\Modem.obj" : $(SOURCE) $(DEP_CPP_MODEM) "$(INTDIR)"\
 ".\Debug\Hantle0.pch"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
