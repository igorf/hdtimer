echo "Compiling Shared Timer Library."
	gcc -I "/Library/Java/JavaVirtualMachines/jdk1.8.0_45.jdk/Contents/Home/include/" -I "/Library/Java/JavaVirtualMachines/jdk1.8.0_45.jdk/Contents/Home/include/darwin" -dynamiclib -shared -fPIC timer_library.c -o libtimer.dylib 
if [ $? -ne 0 ]
then
	echo "Error in Compieling Timer ibrary. Quiting..."
	exit 0
fi
echo "Done."
