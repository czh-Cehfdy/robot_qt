/**
 * @file /include/main_window.hpp
 *
 * @brief Qt based gui for robot_qt.
 *
 * @date 2021 陈泽华
 **/
#ifndef robot_qt_MAIN_WINDOW_H
#define robot_qt_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

/*****************************************************************************
** 在qt5中，QmainWindow存在与QtWidgets中，故需要在main_window.hpp中进行修改，将QtGui改为QtWidgets：
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "qnode_main.hpp"
#include "CCtrlDashBoard.h"
#include <QButtonGroup>
#include <QLabel>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QProcess>
#include <QString>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebChannel>
#include <QMessageBox>
#include <QJSValue>
#include <functional>
#include <QVariant>
#include <string>
#include <QComboBox>
#include "qrviz.hpp"   //添加qrviz的头文件
#include "QSpinBox"
#include <cmath>
#include <math.h>
#include <QVector>
#include "LocalCartesian.hpp"
/*****************************************************************************
** Namespace
*****************************************************************************/

namespace robot_qt {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(int argc, char** argv, QWidget *parent = nullptr);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();
    void DisplayRawImage(const QImage& image);
    void DisplayPCLImage(const QImage& image);
    void DisplayFusionImage(const QImage& image);
    //超声波
    void DisplaySonar1Distance(const QString& Dis1);
    void DisplaySonar2Distance(const QString& Dis2);
    void DisplaySonarError(const QString& Error);
    void DisplayObs(const QString& obstacle_range,const QString& obstacle_state);

    //gps
    void DisplayGetgps(const QString& longitude,const QString& latitude);
    //gps_distance
    static double distanceGPS(const double& longitude1,const double& latitude1,const double& longitude2,const double& latitude2);

    void mousePressEvent(QMouseEvent* event);
//    bool eventFilter(QObject *obj, QEvent *event);
    void GetStartPoint(QString longitude,QString latitude);

    void MyDrawNavPoint(QLabel* label);
    void MyDrawMeasureLine(QLabel* label);
//    void display_map();
    // mask search and interp
    bool CheckZero(cv::Mat& img, int x, int y);
    bool CheckCord(cv::Mat& img, int x, int y);
    void coords(const QString& city);
    void walking(const QString& origin,const QString& terminal);
    double transformLat(double x,double y);
    double transformLon(double x,double y);
    double *gcj02towgs84(double lng,double lat);
    bool out_of_china(double lng,double lat);
    cv::Point2i SearchNearestPoint(cv::Mat& img, int x, int y);
    QString obstacle_tip;
    QString sonar_tip;
    int save_gps_flag = 0;
    QVector<double> save_longitude;
    QVector<double> save_latitude;
    QVector<double> g_key_longitude;
    QVector<double> g_key_latitude;
    QVector<double> compare_longitude;
    QVector<double> compare_latitude;

    QVector<double> test_longitude;
    QVector<double> test_latitude;

    GeographicLib::LocalCartesian geoConverter;
    GeographicLib::LocalCartesian test_geoConverter;
    
    int count_gps = 0 ;
    int test_flag = 1 ;
    int btn_pitchFlag = 0;
    double xyz[3] = {0,0,0};
    double m_xyz[3] ={0,0,0};


public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
    void on_button_connect_clicked();
	void on_checkbox_use_environment_stateChanged(int state);

    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically
    void slot_linera_value_change(int);
    void slot_raw_value_change(int);
    void slot_pushbtn_click();
    void slot_quick_cmd_clicked();
    void slot_quick_output();
    void slot_rosShutdown();   //设置机器人在线、离线

    void slot_Qudong_start();
    void slot_location_start();
    void slot_movebase_start();
    void slot_goal_start();
//    void slot_scoutTeleop_start();
//    void slot_PCL_start();
//    void slot_controller_start();
//    void slot_planning_start();
//    void slot_carstart_start();

    void slot_Qudong_output();
    void slot_location_output();
    void slot_movebase_output();
    void slot_goal_output();
//    void slot_scoutTeleopcmd_output();
//    void slot_PCLcmd_output();
//    void slot_controllercmd_output();
//    void slot_planningcmd_output();
//    void slot_carstartcmd_output();

    void on_readoutput();
    void slot_roscore();
    void DisplayPoints(QString);
    void recieveJsMessage(const QString& np,const QString& path_points);
    void slot_treewidget_value_change(QString);
    void slot_display_grid(int);
    void slot_display_tf(int);
    void slot_display_laser(int);
    void slot_display_PCL(int);
    void slot_display_PCL2(int);
    void slot_display_PCL2_2(int);
    void slot_display_Map(int);
    void slot_display_Path(int);
    void slot_display_Path_small(int);
    void slot_display_Path_big(int);
    //rviz_obs
    void slot_treewidget_value_change_obs(QString);
    void slot_display_grid_obs(int);
    void slot_display_Axes_obs(int);
    void slot_display_PCL2_obs(int);
    void slot_display_PCL2_2_obs(int);

    void slot_interact();
//    void slot_set_start_pose(); //起始点信号与槽函数
//    void slot_set_goal_pose(); //终点信号与槽函数

    void slot_start_tip(int);

    //save_gps
    void slot_save_gps();
    void slot_dispaly_gpsdata();
    void slot_chooseGoalGPS();
    void slot_testgpsdata();

private slots:
    void on_btn_loadmap_clicked();




private:
    void initUis();
    void initVector();
    void initMap();
    void initconections();
    void initRviz();
    void initRviz_obstacles();
    void initWeb();
    void initTopicList();
    // 获取js函数返回值
    QString getJsRetString();
    qrviz* myrviz;   //初始化rviz的对象
    qrviz* myrviz_ObstaclesDisplay;   //初始化rviz的对象
//    rviz_distance_tool::DistanceTool* mydistancetool;
    //rviz1
    QComboBox* fixed_box; //需要获取其中的内容，所以要在.hpp中声明
    QComboBox* Global_Color_box;
    QSpinBox* Cell_Count_Box;
    QComboBox* Grid_Color_Box;
    QComboBox* Laser_Topic_box;
    QComboBox* Camera_box;

    QComboBox* PointCloud_Topic_box;
    QComboBox* PointCloud_Style_box;
    QComboBox* PointCloud_ColorTransformer_box;
    QComboBox* PointCloud_ChannelName_box;
    QComboBox* PointCloud2_Topic_box;
    QComboBox* PointCloud2_Style_box;
    QComboBox* PointCloud2_ColorTransformer_box;
    QComboBox* PointCloud2_2_Topic_box;
    QComboBox* PointCloud2_2_Style_box;
    QComboBox* PointCloud2_2_ColorTransformer_box;
    QComboBox* Map_Topic_box;
    QComboBox* Map_Color_Scheme_box;
    QComboBox* Path_Topic_box;
    QComboBox* Path_Color_box;
    QComboBox* Path_Topic_box_small;
    QComboBox* Path_Topic_box_big;
    QComboBox* Path_Color_box_small;
    QComboBox* Path_Color_box_big;

    //rviz_obs
    QComboBox* fixed_box_obs; //需要获取其中的内容，所以要在.hpp中声明
    QComboBox* Global_Color_box_obs;
    QSpinBox* Cell_Count_Box_obs;
    QComboBox* Grid_Color_Box_obs;
    QComboBox* Axes_ReferenceFrame_box_obs;

    QComboBox* PointCloud2_Topic_box_obs;
    QComboBox* PointCloud2_Style_box_obs;
    QComboBox* PointCloud2_ColorTransformer_box_obs;
    QComboBox* PointCloud2_2_Topic_box_obs;
    QComboBox* PointCloud2_2_Style_box_obs;
    QComboBox* PointCloud2_2_ColorTransformer_box_obs;

private:
	Ui::MainWindowDesign ui;
    CQNodeMain qnode_main;
    CQNode qnode_getStartPoint;
    CQNode qnode_raw_image;
    CQNode qnode_fusion_image;
    CQNode qnode_pcl_image;
    CQNode qnode_points;
    CQNode qnode_sonar;
    CQNode qnode_obstacle;
    CQNode rostopic_list;
    CQNode qnode_Get_gps;

    CCtrlDashBoard* speed_x_dashBoard;
    CCtrlDashBoard* speed_y_dashBoard;
    QProcess *laser_cmd;
    QProcess *Qudong_cmd = nullptr;
    QProcess *Location_cmd = nullptr;
    QProcess *Movebase_cmd = nullptr;
    QProcess *goal_cmd = nullptr;
    QProcess *cmd;
    // mouse point
    QPoint point;
    // measure point
    cv::Point2i p1;
    cv::Point2i p2;
    cv::Point3f rp1;
    cv::Point3f rp2;
    QWebEngineView *g_mapView = nullptr;
    QWebChannel *g_webChannel = nullptr;
    QWebChannel *g_getSPWebChannel = nullptr;
    const double pi = 3.1415926535897932384626;
    const double a = 6378245.0;
    const double ee = 0.00669342162296594323;
    const double x_pi = 3.14159265358979324 * 3000.0 / 180.0;
};

}  // namespace robot_qt

#endif // robot_hmi_MAIN_WINDOW_H
