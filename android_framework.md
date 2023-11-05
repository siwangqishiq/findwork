### Android系统架构 
    应用层 
    framework层 （ActivityThread AMS WMS）
    系统核心层 AndroidRunTime + Native c++库 
    硬件抽象层 
    linux内核


### Android系统启动流程
    系统自检 
        加载引导扇区
    bootloader 
        拉起内核 
    linux内核启动 
        操作系统内核启动
    init进程
        1.挂载运行时文件目录
        2.启动属性服务 为其他进程提供属性的查询及写入
        3.解析inir.rc脚本 fork方式启动Zygote进程
    Zygote进程
        1.启动AndroidRunTime 虚拟机
        2.加载JNI服务
        3.启动SystemServer进程
        4.启动 LocalServerSocket,监听AMS发起的fork进程请求
    SystemServer进程
         


### Android 应用启动流程

### View 事件传递

### View 布局绘制

### Binder IPC

### apk打包流程

