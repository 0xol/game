all:
	python3 make.py

linux: all
	$(cxx) -O2 -g -rdynamic bin/*.o -o midnight $(libs) -no-pie -lboost_stacktrace_noop -lGL -lm -lpthread -ldl -lrt -lX11 -DPLATFORM_DESKTOP 