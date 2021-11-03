/**
 * @file /include/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date 2021 陈泽华
 **/

/*****************************************************************************
** Ifdefs
*****************************************************************************/
#ifndef robot_qt_QNODE_HPP_
#define robot_qt_QNODE_HPP_
/*****************************************************************************
** Includes
*****************************************************************************/
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <QThread>
#include <iostream>
#include <string>     // std::string, std::to_string
#include <exception>
#include <QStringListModel>
#include <std_msgs/String.h>
#include <map>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Point.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <QImage>
#include <sensor_msgs/NavSatFix.h>
#include <typeinfo>
#include <QDebug>
#include <nav_msgs/Path.h>
#include <signal.h>
/*****************************************************************************
** Namespaces
*****************************************************************************/
using namespace std;
namespace robot_qt {

/*****************************************************************************
** Class
*****************************************************************************/

class CQNode : public QThread {
    Q_OBJECT
public:
    CQNode(int argc, char** argv);
    CQNode(int argc, char** argv, std::string node_name, std::string topic_name,int index = 0);
    virtual ~CQNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
    void disinit();
    void set_cmd_vel(char k,float linear,float angular);//共有设置速度的方法，方便在两个类中调用
    void sub_image(QString topic_name);
    QMap<QString,QString> get_topic_list();
	void run();
	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);
    cv::Mat mask;
    int count =0;
    int judge_count = 0;
    int judge_count_sonar = 0;

Q_SIGNALS:
	void loggingUpdated();
    void rosShutdown();
    void speed_vel(float,float);
    void power_vel(float);
    void image_val(QImage);
    void updateImage(const QImage& image);
    void updatePCLImage(const QImage& image);
    void updateSonar1Distance(const QString& Dis1);
    void updateSonar2Distance(const QString& Dis2);
    void updateSonarError(const QString& Error);
    void updateObstacleState(const QString& obstacle_range,const QString& obstacle_state);

    void update_StartPoint(QString longitude,QString latitude);
    void updatepoints(QString);
    void updateGetgps(QString longitude,QString latitude);
private:
	int init_argc;
	char** init_argv;
    std::string init_node_name;
    std::string init_topic_name;
    int init_index;
	ros::Publisher chatter_publisher;
    ros::Publisher cmd_vel_pub;
    QStringListModel logging_model;
    ros::Subscriber chatter_sub;
    ros::Subscriber sonar_sub;
    ros::Subscriber odom_sub;
    ros::Subscriber power_sub;
    ros::Subscriber points_sub;
    ros::Subscriber obstacle_sub;
    ros::Subscriber get_gps_sub;
    //map
    ros::Subscriber MapStartPoint_sub;

    //单目图像订阅
    QImage qRawImage;
    QImage qFusionImage;
    QImage PCLImage;

    image_transport::Subscriber RawImage_sub;
    image_transport::Subscriber PCLImage_sub;
    image_transport::Subscriber FusionImage_sub;

    QString sonar1_distance = 0;
    QString sonar2_distance = 0;
    QString sonar_error;
    QString device;
    QString obstacle_range = 0;
    QString obstacle_state = 0;



    //主界面功能回调函数
    void image_callback(const sensor_msgs::ImageConstPtr &msg);
    void power_callback(const std_msgs::Float32 &msg);
    void chatter_callback(const std_msgs::String &msg);
    void odom_callback(const nav_msgs::Odometry &msg);
    //地图回调函数
    void MapStartPoint_Callback(const sensor_msgs::NavSatFix &msg);
    //单目图像回调函数
    void RawImageCallback(const sensor_msgs::ImageConstPtr& msg);
    void PCLImageCallback(const sensor_msgs::ImageConstPtr& msg);
    void FusionImageCallback(const sensor_msgs::ImageConstPtr& msg);
    void points_callback(const std_msgs::String &msg);
    //超声波测距回调函数
    void sonar_callback(const geometry_msgs::Twist &msg);
    //障碍物
    void obstacle_callback(const geometry_msgs::Twist &msg);
    QImage Mat2QImage(cv::Mat const& src);
    //Get_gps
    void Get_gps_callback(const sensor_msgs::NavSatFix &msg);
};
}  // namespace robot_qt

#endif /* robot_qt_QNODE_HPP_ */
