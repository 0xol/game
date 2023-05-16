cxx = g++
cxxflags = -g -O2 -Iinclude
ld = ld

libs = -lraylib

all:
	if [ -d "bin" ]; then rm -rf bin; fi
	mkdir bin
	$(cxx) $(cxxflags) -c src/init.cpp -o bin/init.o
	$(cxx) $(cxxflags) -c src/handlers/stacktrace.cpp -o bin/handlers_stacktrace.o
	
linux: all
	$(cxx) -O2 -g -rdynamic bin/*.o -o midnight $(libs) -no-pie -lboost_stacktrace_noop -lGL -lm -lpthread -ldl -lrt -lX11 -DPLATFORM_DESKTOP 

windows: all
	$(cxx) -O2 -g bin/*.o -o midnight.exe $(libs) -lopengl32 -lws2_32 -lgdi32 -lImagehlp -lwinmm -DPLATFORM_DESKTOP