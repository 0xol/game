cxx = g++
cxxflags = -g -O2 -Iinclude
ld = ld

libs = -lraylib

all:
	if [ -d "bin" ]; then rm -rf bin; fi
	mkdir bin

#single file handlers
	$(cxx) $(cxxflags) -c src/init.cpp -o bin/init.o
	$(cxx) $(cxxflags) -c src/handlers/stacktrace.cpp -o bin/handlers_stacktrace.o
	$(cxx) $(cxxflags) -c src/handlers/memoryFunc.cpp -o bin/handlers_memoryFunc.o

#gameThread
	$(cxx) $(cxxflags) -c src/handlers/gameThread/main.cpp -o bin/handlers_gameThread_main.o

#engineThread
	$(cxx) $(cxxflags) -c src/handlers/engineThread/main.cpp -o bin/handlers_engineThread_main.o
	$(cxx) $(cxxflags) -c src/handlers/engineThread/mainMenu.cpp -o bin/handlers_engineThread_mainMenu.o
	$(cxx) $(cxxflags) -c src/handlers/engineThread/menus.cpp -o bin/handlers_engineThread_menus.o

#external libs
	$(cxx) $(cxxflags) -c src/external/rlImGui.cpp -o bin/external_rlImGui.o
	$(cxx) $(cxxflags) -c src/external/imgui.cpp -o bin/external_imgui.o
	$(cxx) $(cxxflags) -c src/external/imgui_draw.cpp -o bin/external_imgui_draw.o
	$(cxx) $(cxxflags) -c src/external/imgui_tables.cpp -o bin/external_imgui_tables.o
	$(cxx) $(cxxflags) -c src/external/imgui_widgets.cpp -o bin/external_imgui_widgets.o
	$(cxx) $(cxxflags) -c src/external/imgui_demo.cpp -o bin/external_imgui_demo.o

linux: all
	$(cxx) -O2 -g -rdynamic bin/*.o -o midnight $(libs) -no-pie -lboost_stacktrace_noop -lGL -lm -lpthread -ldl -lrt -lX11 -DPLATFORM_DESKTOP 

windows: all
	$(cxx) -O2 -g bin/*.o -o midnight.exe $(libs) -lopengl32 -lws2_32 -lgdi32 -lImagehlp -lwinmm -DPLATFORM_DESKTOP