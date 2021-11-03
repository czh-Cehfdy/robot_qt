#include "../include/qrviz.hpp"
#include <QDebug>
#include <QException>
qrviz::qrviz(QVBoxLayout* layout)
{
    //创建rviz panel
    render_panel_=new rviz::RenderPanel();


    //向layout添加
    layout->addWidget(render_panel_);

    //创建rviz控制对象
    manager_=new rviz::VisualizationManager(render_panel_);
    tool_manager_=manager_->getToolManager();   //可以通过tool_manager_添加工具
    ROS_ASSERT(manager_!=NULL); //官方给出的，判断对象是否被分配成功了，不加会在kinetic版本中闪退

    //初始化render_panel 实现放大缩小等操作
    render_panel_->initialize(manager_->getSceneManager(),manager_); //获取屏幕对象

    manager_->setFixedFrame("velodyne");//map
    //初始化rviz控制对象
    manager_->initialize();
    manager_->startUpdate();
    manager_->removeAllDisplays();
}

void qrviz::Set_FixedFrame(QString Frame_name)
{
    manager_->setFixedFrame(Frame_name);
    qDebug()<<manager_->getFixedFrame();
}

//通过Grid_对象可以设置当前图层的一些属性
void qrviz::Display_Grid(int Cell_Count,QColor color,bool enable)
{
    if(Grid_!=NULL)   //为了保证图层的唯一性，判断Grid_对象是否有值
    {
        delete Grid_;   //如果有值，就删除对象
        Grid_=NULL;     //将其赋值为空
    }
    Grid_=manager_->createDisplay("rviz/Grid","myGrid",enable);
    //设置cell Count
    Grid_->subProp("Plane Cell Count")->setValue(Cell_Count); //setValue接收qt所有类型，可以直接传入
    //设置颜色
    Grid_->subProp("Color")->setValue(color);
    ROS_ASSERT(Grid_!=NULL);

}
void qrviz::Display_TF(bool enable)
{
    if(TF_!=NULL)
    {
        delete TF_;
        TF_=NULL;
    }
    TF_=manager_->createDisplay("rviz/TF","myTF",enable);
    ROS_ASSERT(TF_!=NULL);  //每创建一个对象都要断言一下,避免出现闪退的bug
}
void qrviz::Display_Axes(QString reference_frame,bool enable)
{
    if(Axes_!=NULL)
    {
        delete Axes_;
        Axes_=NULL;
    }
    Axes_=manager_->createDisplay("rviz/Axes","myAxes",enable);
    Axes_->subProp("Reference Frame")->setValue(reference_frame);
    ROS_ASSERT(Axes_!=NULL);  //每创建一个对象都要断言一下,避免出现闪退的bug
}
void qrviz::Display_LaserScan(QString laser_topic,bool enable)
{
    if(LaserScan_!=NULL)
    {
        delete LaserScan_;
        LaserScan_=NULL;
    }
    LaserScan_=manager_->createDisplay("rviz/LaserScan","myLaser",enable);
    LaserScan_->subProp("Topic")->setValue(laser_topic);
    ROS_ASSERT(LaserScan_!=NULL);
}

void qrviz::Display_PCL(QString PointCloud_topic,QString PointCloud_style,QString PointCloud_ColorTransformer,QString PointCloud_ChannelName,bool enable)
{
    if(PointCloud_!=NULL)
    {
        delete PointCloud_;
        PointCloud_=NULL;
    }
    PointCloud_=manager_->createDisplay("rviz/PointCloud","myPointCloud",enable);
    qDebug()<<PointCloud_topic;
    PointCloud_->subProp("Topic")->setValue(PointCloud_topic);
    PointCloud_->subProp("Style")->setValue(PointCloud_style);
    PointCloud_->subProp("Color Transformer")->setValue(PointCloud_ColorTransformer);
    PointCloud_->subProp("Channel Name")->setValue(PointCloud_ChannelName);

    qDebug()<<"我进入了设置函数里";
//    PointCloud2_->subProp("Use rainbow")->setValue("true");
//    PointCloud2_->subProp("Invert Rainbow")->setValue("false");
    PointCloud_->subProp("Size (Pixels)")->setValue("2");
    PointCloud_->subProp("Queue Size")->setValue("10");
    PointCloud_->subProp("Alpha")->setValue("1");
    ROS_ASSERT(PointCloud_!=NULL);
}
void qrviz::Display_PCL2(QString PointCloud2_topic,QString PointCloud2_style,QString PointCloud2_ColorTransformer,bool enable)
{
    if(PointCloud2_!=NULL)
    {
        delete PointCloud2_;
        PointCloud2_=NULL;
    }
    PointCloud2_=manager_->createDisplay("rviz/PointCloud2","myPointCloud2",enable);
    qDebug()<<PointCloud2_topic;
    PointCloud2_->subProp("Topic")->setValue(PointCloud2_topic);
    PointCloud2_->subProp("Style")->setValue(PointCloud2_style);
    PointCloud2_->subProp("Color Transformer")->setValue(PointCloud2_ColorTransformer);

    qDebug()<<"我进入了设置函数里";
//    PointCloud2_->subProp("Use rainbow")->setValue("true");
//    PointCloud2_->subProp("Invert Rainbow")->setValue("false");
    PointCloud2_->subProp("Size (m)")->setValue("0.01");
    PointCloud2_->subProp("Queue Size")->setValue("10");
    PointCloud2_->subProp("Alpha")->setValue("1");
    ROS_ASSERT(PointCloud2_!=NULL);
}

void qrviz::Display_PCL2_2(QString PointCloud2_topic,QString PointCloud2_style,QString PointCloud2_ColorTransformer,bool enable)
{
    if(PointCloud2_2!=NULL)
    {
        delete PointCloud2_2;
        PointCloud2_2=NULL;
    }
    PointCloud2_2=manager_->createDisplay("rviz/PointCloud2","myPointCloud2_2",enable);
    PointCloud2_2->subProp("Topic")->setValue(PointCloud2_topic);
    PointCloud2_2->subProp("Style")->setValue(PointCloud2_style);
    PointCloud2_2->subProp("Color Transformer")->setValue(PointCloud2_ColorTransformer);
    PointCloud2_2->subProp("Size (m)")->setValue("0.01");
    PointCloud2_2->subProp("Queue Size")->setValue("10");
    PointCloud2_2->subProp("Alpha")->setValue("1");
    ROS_ASSERT(PointCloud2_2!=NULL);
}

/** @fn     qrviz::Display_Map
 *  @brief  在rviz中显示地图
 *  @param  QString topic 话题
 *  @param  QString color_scheme 地图显示样式
 *  @return void
 */
void qrviz::Display_Map(QString topic,QString color_scheme,bool enable)
{
    if(Map_!=NULL)
    {
        delete Map_;
        Map_=NULL;
    }
    Map_=manager_->createDisplay("rviz/Map","myMap",enable);
    ROS_ASSERT(Map_!=NULL);
    Map_->subProp("Topic")->setValue(topic);
    Map_->subProp("Color Scheme")->setValue(color_scheme);
}
rviz::Display* Path_=NULL;
void qrviz::Display_Path(QString topic,QColor color,bool enable)
{
    if(Path_!=NULL)
    {
        delete Path_;
        Path_=NULL;
    }
    Path_=manager_->createDisplay("rviz/Path","myPath",enable);
    ROS_ASSERT(Path_!=NULL);
    Path_->subProp("Topic")->setValue(topic);
    Path_->subProp("Color")->setValue(color);
}
void qrviz::Set_Interact(){
    rviz::Tool* interact_tool=tool_manager_->addTool("rviz/interact");
    //设置当前使用的工具
    tool_manager_->setCurrentTool(interact_tool);
}
void qrviz::Set_Start_Pose()
{
    rviz::Tool* current_tool_=tool_manager_->addTool("rviz/SetInitialPose");
    //设置当前使用的工具
    tool_manager_->setCurrentTool(current_tool_);
}
void qrviz::Set_Goal_Pose()
{
     rviz::Tool* current_tool_=tool_manager_->addTool("rviz/SetGoal");
     //获取属性容器
     rviz::Property* pro=current_tool_->getPropertyContainer();
     //设置发布导航目标点的topic
     pro->subProp("Topic")->setValue("/move_base_simple/goal");
     //设置当前使用的工具
     tool_manager_->setCurrentTool(current_tool_);
}
