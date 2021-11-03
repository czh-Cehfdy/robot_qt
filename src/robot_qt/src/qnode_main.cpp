/**
 * @file /src/qnode_main.cpp
 *
 * @brief Ros communication central!
 *
 * @date 2021 陈泽华
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <sstream>
#include "../include/qnode_main.hpp"


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace robot_qt {

/*****************************************************************************
** Implementation
*****************************************************************************/
CQNodeMain::CQNodeMain(int argc, char** argv) :
    init_argc(argc),
    init_argv(argv)
    {}

CQNodeMain::~CQNodeMain() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool CQNodeMain::init() {
    ros::init(init_argc,init_argv,"robot_qt");//
    if ( ! ros::master::check() ) {  //如果rosmaster没有启动，返回false
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	// Add your ros communications here.
    ros::NodeHandle nh;
    chatter_publisher = nh.advertise<std_msgs::String>("chatter", 1000);
    chatter_sub=nh.subscribe("chatter",1000,&CQNodeMain::chatter_callback,this);
    cmd_vel_pub=nh.advertise<geometry_msgs::Twist>("cmd_vel",1000);
    loacation_pub = nh.advertise<std_msgs::String>("location", 1000);
    power_sub=nh.subscribe("power",1000,&CQNodeMain::power_callback,this);
    odom_sub=nh.subscribe("raw_odom",1000,&CQNodeMain::odom_callback,this);
	start();
	return true;
}

bool CQNodeMain::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
    ros::init(remappings,"robot_qt");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.

	// Add your ros communications here.
    ros::NodeHandle nh;
    chatter_publisher = nh.advertise<std_msgs::String>("chatter", 1000);
    chatter_sub=nh.subscribe("chatter",1000,&CQNodeMain::chatter_callback,this);
    cmd_vel_pub=nh.advertise<geometry_msgs::Twist>("cmd_vel",1000);
    loacation_pub = nh.advertise<std_msgs::String>("location", 1000);
    power_sub=nh.subscribe("power",1000,&CQNodeMain::power_callback,this);
    odom_sub=nh.subscribe("raw_odom",1000,&CQNodeMain::odom_callback,this);
	start();
	return true;
}

QImage CQNodeMain::Mat2QImage(cv::Mat const& src)
{
  QImage dest(src.cols, src.rows, QImage::Format_ARGB32);

  const float scale = 255.0;

  if (src.depth() == CV_8U) {
    if (src.channels() == 1) {
      for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
          int level = src.at<quint8>(i, j);
          dest.setPixel(j, i, qRgb(level, level, level));
        }
      }
    } else if (src.channels() == 3) {
      for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
          cv::Vec3b bgr = src.at<cv::Vec3b>(i, j);
          dest.setPixel(j, i, qRgb(bgr[2], bgr[1], bgr[0]));
        }
      }
    }
  } else if (src.depth() == CV_32F) {
    if (src.channels() == 1) {
      for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
          int level = scale * src.at<float>(i, j);
          dest.setPixel(j, i, qRgb(level, level, level));
        }
      }
    } else if (src.channels() == 3) {
      for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
          cv::Vec3f bgr = scale * src.at<cv::Vec3f>(i, j);
          dest.setPixel(j, i, qRgb(bgr[2], bgr[1], bgr[0]));
        }
      }
    }
  }

  return dest;
}
void CQNodeMain::power_callback(const std_msgs::Float32 &msg)
{
    emit power_vel(msg.data);
}
void CQNodeMain::odom_callback(const nav_msgs::Odometry &msg)
{
    emit speed_vel(msg.twist.twist.linear.x,msg.twist.twist.linear.y);
}
void CQNodeMain::set_cmd_vel(char k,float linear,float angular)
{
    // Map for movement keys 获取每个字母对应的方向
    std::map<char, std::vector<float>> moveBindings
    {
      {'i', {1, 0, 0, 0}},
      {'o', {1, 0, 0, -1}},
      {'j', {0, 0, 0, 1}},
      {'l', {0, 0, 0, -1}},
      {'u', {1, 0, 0, 1}},
      {',', {-1, 0, 0, 0}},
      {'.', {-1, 0, 0, 1}},
      {'m', {-1, 0, 0, -1}},
      {'O', {1, -1, 0, 0}},
      {'I', {1, 0, 0, 0}},
      {'J', {0, 1, 0, 0}},
      {'L', {0, -1, 0, 0}},
      {'U', {1, 1, 0, 0}},
      {'<', {-1, 0, 0, 0}},
      {'>', {-1, -1, 0, 0}},
      {'M', {-1, 1, 0, 0}},
      {'t', {0, 0, 1, 0}},
      {'b', {0, 0, -1, 0}},
      {'k', {0, 0, 0, 0}},
      {'K', {0, 0, 0, 0}}
    };
    char key=k;
    // Grab the direction data
    int x = moveBindings[key][0];
    int y = moveBindings[key][1];
    int z = moveBindings[key][2];
    int th = moveBindings[key][3];

    geometry_msgs::Twist twist;
    twist.linear.x=x*linear;
    twist.linear.y=0.0;
    twist.linear.z=0.0;

    twist.angular.x=0;
    twist.angular.y=0;
    twist.angular.z=th*angular;

    cmd_vel_pub.publish(twist);
}
void CQNodeMain::pub_location_points(const QString& np)
{
    int i= 0;
    ros::Rate loop_rate(1);
    std::string msg = np.toStdString();
    std_msgs::String msg_location;
    std::stringstream ss;
    ss << msg;
    msg_location.data = ss.str();
    while (i<5) {
        loacation_pub.publish(msg_location);
        loop_rate.sleep();
        ++i;
    }

}

void CQNodeMain::chatter_callback(const std_msgs::String &msg)
{
//    log(Info,"I recive"+msg.data);
}
void CQNodeMain::run() {
    ros::Rate loop_rate(1);
    int count = 0;
    while ( ros::ok() ) {
        ros::spinOnce();
    }
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


void CQNodeMain::log( const LogLevel &level, const std::string &msg) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Fatal) : {
				ROS_FATAL_STREAM(msg);
				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
				break;
		}
	}
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
	Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}

}  // namespace robot_qt
