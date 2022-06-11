TARGET   = uro2mouse
OBJS     = $(TARGET).obj $(TARGET).res

TOOLPATH = C:/lcc/
INCPATH  = $(TOOLPATH)include/
MAKE     = $(TOOLPATH)bin/make.exe
CC       = $(TOOLPATH)bin/lcc.exe -I$(INCPATH) -O -c
RESCMP   = $(TOOLPATH)bin/lrc.exe -I$(INCPATH)
LINKER   = $(TOOLPATH)bin/lcclnk.exe -s -subsystem windows -o
UPX      = D:/osask/Projects/z_tools/upx.exe -9

LIBPATH  = $(TOOLPATH)lib/
LIBS     = 


ALL :
	$(MAKE) $(TARGET).exe

$(TARGET).obj: $(TARGET).c Makefile
	$(CC) $(TARGET).c

$(TARGET).res:	$(TARGET).rc Makefile
	$(RESCMP) $(TARGET).rc

$(TARGET).exe: $(OBJS) Makefile
	$(LINKER) $(TARGET).exe $(OBJS) $(LIBS)
	$(UPX) $(TARGET).exe

LINK :
	$(LINKER) $(TARGET).exe $(OBJS) $(LIBS)
	$(UPX) $(TARGET).exe
