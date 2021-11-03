#ifndef QRVIZ_HPP
#define QRVIZ_HPP

#include <QObject>
#include <ros/ros.h>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include <rviz/tool_manager.h>
#include <rviz/tool.h>
#include <QVBoxLayout>
class qrviz
{
public:
    qrviz(QVBoxLayout* layout);  //通过QVBoxLayout对象联系两个类，进行交互
    void Set_FixedFrame(QString Frame_name); //设置一个公有函数，方便mainwindow中调用
    void Display_Grid(int Cell_Count,QColor color,bool enable);//设置Display_Grid参数

    void Display_TF(bool enable); //显示TF坐标变换
    void Display_LaserScan(QString laser_topic,bool enable); //显示雷达点云数据
    void Display_Map(QString topic,QString color_scheme, bool enable);  //显示地图
    void Display_Axes(QString reference_frame,bool enable);
    void Display_Path(QString topic,QColor color,bool enable);
    void Display_PCL(QString PointCloud_topic,QString PointCloud_style,QString PointCloud_ColorTransformer,QString PointCloud_ChannelName,bool enable); //显示雷达点云数据
    void Display_PCL2(QString PointCloud2_topic,QString PointCloud2_style,QString PointCloud2_ColorTransformer,bool enable); //显示雷达点云数据
    void Display_PCL2_2(QString PointCloud2_topic,QString PointCloud2_style,QString PointCloud2_ColorTransformer,bool enable); //显示雷达点云数据
    void Set_Interact();
    void Set_Start_Pose();  //由于获得起始点的按钮是在mainwindow中，但是我们需要在qrviz中调用，所以定义一个接口函数
    void Set_Goal_Pose();
//    void Display_Local_Map(QString map_topic,QString map_color,QString planner_topic,QColor planner_color,bool enable);
//    void Display_Global_Map(QString map_topic,QString map_color,QString planner_topic,QColor planner_color,bool enable);

private:
    rviz::RenderPanel* render_panel_;
    rviz::VisualizationManager* manager_;
    rviz::ToolManager* tool_manager_;   //声明rviz中的工具栏，放按钮
    rviz::Display* Grid_=NULL;
    rviz::Display* TF_=NULL;
    rviz::Display* Axes_=NULL;
    rviz::Display* LaserScan_=NULL;
    rviz::Display* PointCloud_=NULL;
    rviz::Display* PointCloud2_=NULL;
    rviz::Display* PointCloud2_2=NULL;
    rviz::Display* Map_=NULL;

//    rviz::Display* Global_Map_=NULL;
//    rviz::Display* Global_Planner_=NULL;
//    rviz::Display* Local_Map_=NULL;
//    rviz::Display* Local_Planner_=NULL;
};

#endif // QRVIZ_HPP
