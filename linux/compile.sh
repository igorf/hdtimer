echo "Compiling Shared Timer Library."
	gcc -shared -I "/usr/lib/jvm/java-7-oracle/include" -I "/usr/lib/jvm/java-7-oracle/include/linux" -fPIC timer_library.c -lrt -o libtimer.so
if [ $? -ne 0 ]
then
	echo "Error in Compieling Timer ibrary. Quiting..."
	exit 0
fi
echo "Done."
