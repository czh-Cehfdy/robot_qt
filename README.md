
># robot_qt项目使用说明
>ubuntu下Qt与ros配置及上位机软件编译

### 一、下载安装Qt

安装之前，请确保您已经安装ubuntu18.04系统以及ros-melodic版本的ros，ros-kinetic会存在一些问题，本人是在ros-melodic版本上进行开发的。

🎯 注意:请安装qt5.9.9版本，此版本很稳定，可以实现本程序功能，其它版本未经过测试，可能会有问题！


### 二、配置catkin_create_qt_pkg环境

**2.1 安装依赖包** 

- 网络依赖包
- sudo apt install net-tools
- 导航依赖包
- sudo apt-get install libsdl1.2-dev
- sudo apt-get install libsdl-image1.2-dev
- sudo apt-get install ros-melodic-tf2-sensor-msgs
- sudo apt-get install ros-melodic-move-base-msgs
- sudo apt install ros-melodic-map-server
- sudo apt install ros-melodic-gmapping
- qt依赖包
- sudo apt install ros-melodic-qt-create
- sudo apt install ros-melodic-qt-build 
- sudo apt install qtmultimedia5-dev
- sudo apt install qtwebengine5-*
- sudo apt install libqt5webengine5
- sudo apt install libqt5charts5-dev



**2.2 编译功能包** 

🎯自己新建一个工作空间，将代码中的src目录整体复制到你的工作空间下，然后执行：catkin_make,
倘若没有报错，那么恭喜你，环境配置好了！

🎯 接下来，在qtcreator中打开项目，操作如下：
- 任意终端输入：qtcreator
- 在弹出来的qtcreator中按照如下操作即可
