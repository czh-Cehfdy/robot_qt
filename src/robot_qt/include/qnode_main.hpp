/**
 * @file /include/qnode_main.hpp
 *
 * @brief Communications central!
 *
 * @date 2021 陈泽华
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef robot_qt_QNODE_MAIN_HPP_
#define robot_qt_QNODE_MAIN_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>
#include <std_msgs/String.h>
#include <map>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Float32.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <QImage>
/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace robot_qt {

/*****************************************************************************
** Class
*****************************************************************************/

class CQNodeMain : public QThread {
    Q_OBJECT
public:
    CQNodeMain(int argc, char** argv);
    virtual ~CQNodeMain();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
    void set_cmd_vel(char k,float linear,float angular);//共有设置速度的方法，方便在两个类中调用
    void pub_location_points(const QString& np);//方便在两个类中调用
    void sub_points(QString topic_name);
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

Q_SIGNALS:
    void rosShutdown();
    void speed_vel(float,float);
    void power_vel(float);

private:
	int init_argc;
	char** init_argv;
    std::string init_node_name;
    std::string init_topic_name;
    int init_index;
	ros::Publisher chatter_publisher;
    ros::Publisher cmd_vel_pub;
    ros::Publisher loacation_pub;
    QStringListModel logging_model;
    ros::Subscriber chatter_sub;
    ros::Subscriber odom_sub;
    image_transport::Subscriber image_sub;
    //主界面功能回调函数
    void chatter_callback(const std_msgs::String &msg);
    void odom_callback(const nav_msgs::Odometry &msg);
    QImage Mat2QImage(cv::Mat const& src);
};
}  // namespace robot_qt

#endif /* robot_hmi_QNODE_MAIN_HPP_ */
