NAME = Apollo # We'll compile the example with the library for now

SRCFILES =\
Apollo/Application/Game.cpp \
Apollo/Application/Application.cpp \
Apollo/Application/Window.cpp \
Apollo/Renderer/RenderingContext.cpp \
Apollo/Renderer/Shader.cpp \
Apollo/Renderer/Buffer.cpp \
Apollo/Platform/Cocoa/CocoaApplication.mm \
Apollo/Platform/Cocoa/CocoaWindow.mm \
Apollo/Platform/Cocoa/CocoaContext.mm \
Apollo/Platform/OpenGL/OpenGLLoader.cpp \
Apollo/Platform/OpenGL/OpenGLShader.cpp \
Apollo/Platform/OpenGL/OpenGLBuffer.cpp 

SANDBOXFILES =\
Sandbox/Example.cpp

CWD = $(shell pwd)/

COCOAFLAGS =\
-framework Cocoa \
-framework OpenGL \
-D APOLLO_COCOA \
-D GL_SILENCE_DEPRECATION \
-Wno-deprecated-declarations

FLAGS =\
-std=c++17 \
-o Bin/$(NAME) \
-iquote $(CWD)Apollo/ \
-I $(CWD) \
-I $(CWD)ThirdParty/gl3w/ \
$(COCOAFLAGS)

.SILENT:
cocoa:
	clang++ $(SRCFILES) $(SANDBOXFILES) $(FLAGS)

run:
	./Bin/$(NAME)

loc:
	git ls-files | xargs wc -l