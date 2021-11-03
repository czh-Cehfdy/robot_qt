/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <sstream>
#include "../include/robot_hmi/qnode.hpp"


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace robot_hmi {

/*****************************************************************************
** Implementation
*****************************************************************************/
QNode::QNode(int argc, char** argv) :
    init_argc(argc),
    init_argv(argv)
    {}
QNode::QNode(int argc, char** argv,std::string node_name,std::string topic_name, int index) :
	init_argc(argc),
    init_argv(argv),
    init_node_name(node_name),
    init_topic_name(topic_name),
    init_index(index)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
    ros::init(init_argc,init_argv,init_node_name);//"robot_hmi"
    if ( ! ros::master::check() ) {  //如果rosmaster没有启动，返回false
        return false;
    }
    ROS_ERROR("init  000");
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	start();
	return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
    ros::init(remappings,init_node_name);
    if ( ! ros::master::check() ) {
        return false;
    }
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	start();
	return true;
}

void QNode::RawImageCallback(const sensor_msgs::ImageConstPtr& msg) {
  cv_bridge::CvImagePtr cv_ptr;
  try {
    cv_ptr = cv_bridge::toCvCopy(msg, "rgb8");
  } catch (cv_bridge::Exception& e) {
    ROS_ERROR("cv_bridge exception:%s", e.what());
    return;
  }

  cv::Mat img;
  img = cv_ptr->image;
  ROS_ERROR("yuanshi tuxiang");
  qRawImage = QImage(img.data, img.cols, img.rows, QImage::Format_RGB888);
  emit updateImage(qRawImage);
}
void QNode::FusionImageCallback(const sensor_msgs::ImageConstPtr& msg) {
  cv_bridge::CvImagePtr cv_ptr;
  try {
    cv_ptr = cv_bridge::toCvCopy(msg, "rgb8");
  } catch (cv_bridge::Exception& e) {
    ROS_ERROR("cv_bridge exception:%s", e.what());
    return;
  }

  cv::Mat img;
  img = cv_ptr->image;
  ROS_ERROR("ronghetuxiang ------------------------");
  qFusionImage = QImage(img.data, img.cols, img.rows, QImage::Format_RGB888);
  emit updateImage(qFusionImage);
}

void QNode::PCLImageCallback(const sensor_msgs::ImageConstPtr& msg) {
  cv_bridge::CvImagePtr cv_ptr;
  try {
    cv_ptr = cv_bridge::toCvCopy(msg,msg->encoding);
  } catch (cv_bridge::Exception& e) {
    ROS_ERROR("cv_bridge exception:%s", e.what());
    return;
  }
  mask = cv_ptr->image;
  QImage im=Mat2QImage(mask);
  emit updatePCLImage(im);

}


void QNode::MapStartPoint_Callback(const sensor_msgs::NavSatFix &msg) {
  try {
      count +=1;
      if(count ==2){
          emit update_StartPoint(QString::number(msg.longitude,'f',7),QString::number(msg.latitude,'f',7));
        }
 }catch (...) {
    ROS_ERROR("我接受了 divide的异常 但是我没有处理 我向上抛出");
    throw;   //接收了异常之后继续往外抛
  }
}






void QNode::points_callback(const std_msgs::String &msg)
{
    QString qstr;
    qstr = QString::fromStdString(msg.data);
    if(judge_count==1){
        emit updatepoints(qstr);
    }
    else {

    }
    judge_count +=1;
}

void QNode::Get_gps_callback(const sensor_msgs::NavSatFix &msg){
    QString get_longitude = QString("%1").arg(msg.longitude, 0, 'f',7);
    QString get_latitude = QString("%1").arg(msg.latitude, 0, 'f',7);
    emit updateGetgps(get_longitude,get_latitude);

}
void QNode::sonar_callback(const geometry_msgs::Twist &msg)
{
    if(msg.linear.x == 1){
        sonar1_distance = QString("%1").arg(msg.linear.y);
        emit updateSonar1Distance(sonar1_distance);

    }else if(msg.linear.x == 2)
    {
        sonar2_distance = QString("%1").arg(msg.linear.y);
        emit updateSonar2Distance(sonar2_distance);
    }else if(msg.linear.x == -1)
    {
        sonar_error = "超声波数据错误，请检查设备！";
        emit updateSonarError(sonar_error);
    }
}
QMap<QString,QString> QNode::get_topic_list()
{
    ros::master::V_TopicInfo topic_list;
    ros::master::getTopics(topic_list);
    QMap<QString,QString> res;
    for(auto topic:topic_list)
    {

        res.insert(QString::fromStdString(topic.name),QString::fromStdString(topic.datatype));

    }
    return res;
}
void QNode::obstacle_callback(const geometry_msgs::Twist &msg)
{
    obstacle_range = QString("%1").arg(msg.linear.x);  //20米的距离
    obstacle_state = QString("%1").arg(msg.linear.y);  //有障碍物是1.0，没有障碍物是0.0
    emit updateObstacleState(obstacle_range,obstacle_state);
}

QImage QNode::Mat2QImage(cv::Mat const& src)
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
void QNode::mySigintHandler() {
//    ros::shutdown();
    spin_flag = 0;
//    if(ros::isStarted()) {
//      ros::shutdown(); // explicitly needed since we use ros::start();
//      ros::waitForShutdown();
//    }
//    wait();

}
void QNode::run() {
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    switch (init_index) {
    case 0: {
//        ROS_ERROR("yuanshi tuxiang  000");
      RawImage_sub = it.subscribe(init_topic_name, 10, &QNode::RawImageCallback, this);
      break;
    }
    case 1: {
      PCLImage_sub = it.subscribe(init_topic_name, 1, &QNode::PCLImageCallback, this);
      break;
    }
    case 2: {
      FusionImage_sub = it.subscribe(init_topic_name, 1, &QNode::FusionImageCallback, this);
      break;
    }
    case 3: {
      MapStartPoint_sub = nh.subscribe(init_topic_name, 10, &QNode::MapStartPoint_Callback, this);
      break;
    }
    case 4: {
      points_sub = nh.subscribe(init_topic_name, 10, &QNode::points_callback, this);
      break;
    }
    case 5: {
      sonar_sub = nh.subscribe(init_topic_name, 1, &QNode::sonar_callback, this);
      break;
    }
    case 6: {
      obstacle_sub = nh.subscribe(init_topic_name, 1, &QNode::obstacle_callback, this);
      break;
    }
    case 7: {
      get_gps_sub = nh.subscribe(init_topic_name, 1, &QNode::Get_gps_callback, this);
      break;
    }
      }

    while ( ros::ok() ) {
        ros::spinOnce();
    }
//    while ( spin_flag == 1 ) {
//        ros::spinOnce();
//    }

	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

}  // namespace robot_hmi
