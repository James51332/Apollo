NAME = Apollo # We'll compile the example with the library for now

SRCFILES =\
Apollo/Application/Game.cpp \
Apollo/Application/Application.cpp \
Apollo/Application/Window.cpp \
Apollo/Platform/Cocoa/CocoaApplication.mm \
Apollo/Platform/Cocoa/CocoaWindow.mm

SANDBOXFILES =\
Sandbox/Example.cpp

CWD = $(shell pwd)/

COCOAFLAGS =\
-framework Cocoa

FLAGS =\
-std=c++17 \
-o Bin/$(NAME) \
-iquote $(CWD)Apollo/ \
-I $(CWD) \
$(COCOAFLAGS)

.SILENT:
cocoa:
	clang++ $(SRCFILES) $(SANDBOXFILES) $(FLAGS)