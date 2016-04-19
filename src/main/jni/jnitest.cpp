#include "c_example_com_jni_jnidemo.h"
#include <string.h>

/*
 * Class:     io_github_yanbober_ndkapplication_NdkJniUtils
 * Method:    getCLanguageString
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT jstring JNICALL Java_c_example_com_jni_jnidemo_SayHello
        (JNIEnv *env, jclass obj) {
//     return (*env)->NewStringUTF(env,"Hi I am aly.This just a test for Android Studio NDK JNI developer!");
    return env->NewStringUTF("Hi I am aly !");
}
//c.example.com.jni
JNIEXPORT jobject JNICALL Java_c_example_com_jni_jnidemo_getStudentInfo
        (JNIEnv *env, jclass obj) {
    //关于包描述符，这儿可以是 com/feixun/jni/Student 或者是 Lcom/feixun/jni/Student;
    //   这两种类型 都可以获得class引用
    jclass stucls = env->FindClass("c/example/com/jni/Student"); //或得Student类引用

    //获得得该类型的构造函数  函数名为 <init> 返回类型必须为 void 即 V
    jmethodID constrocMID = env->GetMethodID(stucls, "<init>", "(Ljava/lang/String;I)V");

    jstring str = env->NewStringUTF("Student named Aly");

    jobject stu_ojb = env->NewObject(stucls, constrocMID, str, 25);  //构造一个对象，调用该类的构造函数，并且传递参数


    return stu_ojb;
}

JNIEXPORT jobject JNICALL Java_c_example_com_jni_jnidemo_updateStudentInfo
        (JNIEnv *env, jclass cls, jobject obj) {
    jclass clazz;
    jfieldID fid;
    jstring j_str;
    jstring j_newStr;

    clazz = env->GetObjectClass(obj);
    if (clazz == NULL) {
        return NULL;
    }
    fid = env->GetFieldID(clazz, "name", "Ljava/lang/String;");
    if (clazz == NULL) {
        return NULL;
    }
    j_str = (jstring) (env)->GetObjectField(obj, fid);
    j_newStr = (env)->NewStringUTF("This is New Name hahah");
    (env)->SetObjectField(obj, fid, j_newStr);
    // 6.删除局部引用
    (env)->DeleteLocalRef(clazz);
    (env)->DeleteLocalRef(j_str);
    (env)->DeleteLocalRef(j_newStr);
    return obj;
//  (*env).GetObjectClass(obj);



}

JNIEXPORT jobject JNICALL
Java_c_example_com_jni_jnidemo_getPeopleInfo(JNIEnv *env, jclass cls, jobject students) {
    //获得ArrayList类引用 记住FindClass千万不能后面跟分号。。。
    jclass list_cls = env->FindClass("java/util/ArrayList");
    //获得得构造函数Id
    jmethodID list_costruct = env->GetMethodID(list_cls, "<init>", "()V");
    //创建一个Arraylist集合对象
    jobject list_obj = env->NewObject(list_cls, list_costruct);
    if(list_cls==NULL)
        return NULL;
    //获得add方法 后面的签名
    jmethodID list_add  = env->GetMethodID(list_cls,"add","(Ljava/lang/Object;)Z");
    //获取People类
    jclass peo_cls = env->FindClass("c/example/com/jni/People");
    //获取People类的构造函数 参数：String Student
    jmethodID peo_costruct = env->GetMethodID(peo_cls , "<init>", "(Ljava/lang/String;Lc/example/com/jni/Student;)V");
    //获取Student类
    jclass stu_cls=env->FindClass("c/example/com/jni/Student");
    //获取Student构造函数
    jmethodID stu_construct=env->GetMethodID(stu_cls, "<init>", "(Ljava/lang/String;I)V");
    for(int i = 0 ; i < 3 ; i++)
    {
        //构造java中的name
        jstring str = env->NewStringUTF("ssssss");
        //构造一个Student对象
        jobject stu_obj = env->NewObject(stu_cls, stu_construct, str, 11);
        //构造一个People对象
        jobject peo_obj = env->NewObject(peo_cls , peo_costruct , str,stu_obj);
        //执行Arraylist类实例的add方法，添加一个People对象
        env->CallBooleanMethod(list_obj , list_add , peo_obj);
    }
    return list_obj;
}