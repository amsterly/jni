package c.example.com.jni;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Administrator on 2015/10/29.
 */
public class jnidemo {
//    public jnidemo()
//    {
//        System.loadLibrary("JniTest");
//    }
    static
    {

        System.loadLibrary("aly");
    }


    //2.
    public static native String SayHello();
    public static native Student getStudentInfo();

    public static native Student updateStudentInfo(Student student);
    //归纳JNI通用的案例
    //1.从Java传递复杂对象集合List<Student>到Native,解析后赋值到另一个复杂对象集合List<People>并返回
    /*
    *
    * */
    public static native ArrayList<People> getPeopleInfo(ArrayList<Student> students);
}
