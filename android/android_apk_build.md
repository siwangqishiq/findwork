### Android APK包构建流程

查看gradle编译Task源码  

    dependencies{
        ... 
        //add
        compileOnly 'com.android.tools.build:gradle:3.0.1' //classpath中指定
        ...
    } 

    apply plugin: 'com.android.application' 

    com.android.application.properties 文件指定implement 

    implementation-class=com.android.build.gradle.AppPlugin

    入口AppPlugin.java

### apply方法 
依次执行 : 

    configureProject // 
    configureExtension // 
    createTask 



