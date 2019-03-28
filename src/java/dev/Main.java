package dev;

import java.io.*;

public class Main {

	static {
		System.loadLibrary("dev");
	}

	public static native int foo(Writer w);

	public static void main(String[] args) {
		System.out.println("测试开始" + ", 系统编码: " + new OutputStreamWriter(System.out).getEncoding());
		Demo.test();
		try {
			int n = foo(new OutputStreamWriter(System.out, "UTF-8"));
			System.out.println(n);
		} catch (Throwable e) {
			e.printStackTrace();
		}
		System.out.println("结束");
	}
}
