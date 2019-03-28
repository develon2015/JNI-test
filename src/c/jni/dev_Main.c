#include <dev_Main.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define e (**env)

jint Java_dev_Main_foo(JNIEnv *env, jclass c, jobject obj) {
	switch (fork()) {
	case -1:
		return 1;
	case 0:
		printf("我是子进程\n");
		exit(0);
		break;
	default:
		break;
	}

	jclass clazz = e.GetObjectClass(env, obj);
	if (clazz == NULL)
		return 1;
	jmethodID id = e.GetMethodID(env, clazz, "write", "(Ljava/lang/String;)V");
	if (id == NULL)
		return 2;
	e.CallObjectMethod(env, obj, id, e.NewStringUTF(env, "你好, JNI!\n"));

	id = e.GetMethodID(env, clazz, "flush", "()V");
	e.CallObjectMethod(env, obj, id);

	void b();
	b();

	return 0;
}
