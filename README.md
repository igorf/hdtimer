# README #

JAVA class:
--------------------------------


```
#!java

package highrestimer;

import java.math.*;

public class HighResTimer {
	private double timeDiff;
	private double runtimeDiff;

	static {
		System.loadLibrary("timer");
	}

	public native void start();
	public native void stop();
	public native void diff();

	public HighResTimer() {
		timeDiff = 0;
		runtimeDiff = 0;
	}

	public double getDifference() {
		return timeDiff;
	}

	public double getRuntimeDifference() {
        diff();
		return runtimeDiff;
	}
}
```

--------------------------------