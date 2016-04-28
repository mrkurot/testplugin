CC=gcc
SRCS=testplugin.c
OBJS=testplugin.o

all:	testplugin.so

$(OBJS): ${SRCS}
	$(CC) -fPIC -Wall -c $(SRCS) -o ${OBJS} -DVERSION=\"`date "+%Y%m-%d_%R"`\" `pkg-config --cflags gtk+-2.0 pidgin purple atk cairo pango glib-2.0 dbus-1`

clean:
	rm testplugin.so *.o
	
testplugin.so: $(OBJS)
	$(CC) -shared -Wl,-soname,testplugin.so -o testplugin.so $(OBJS) -lcurl

install: testplugin.so
	cp -f testplugin.so ~/.purple/plugins/
