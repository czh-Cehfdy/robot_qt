/**
 * @file /src/qnode.cpp
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
#include "../include/qnode.hpp"


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace robot_qt {

/*****************************************************************************
** Implementation
*****************************************************************************/
CQNode::CQNode(int argc, char** argv) :
    init_argc(argc),
    init_argv(argv)
    {}
CQNode::CQNode(int argc, char** argv,std::string node_name,std::string topic_name, int index) :
	init_argc(argc),
    init_argv(argv),
    init_node_name(node_name),
    init_topic_name(topic_name),
    init_index(index)
	{}

CQNode::~CQNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool CQNode::init() {
    ros::init(init_argc,init_argv,init_node_name);//"robot_qt"
    if ( ! ros::master::check() ) {  //如果rosmaster没有启动，返回false
        return false;
    }
    log(Info,"CQNode::init()");
    m_qnodeStart = true ;
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	start();
	return true;
}

bool CQNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
    ros::init(remappings,init_node_name);
    if ( ! ros::master::check() ) {
        return false;
    }
    m_qnodeStart = true ;
    log(Info,"CQNode::init(const std::string &master_url, const std::string &host_url)");
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	start();
	return true;
}

void CQNode::RawImageCallback(const sensor_msgs::ImageConstPtr& msg) {
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
void CQNode::FusionImageCallback(const sensor_msgs::ImageConstPtr& msg) {
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

void CQNode::PCLImageCallback(const sensor_msgs::ImageConstPtr& msg) {
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


void CQNode::MapStartPoint_Callback(const sensor_msgs::NavSatFix &msg) {
  try {
        if(msg.status.status == 4){
            count +=1;
            if(count==5){
                gpsState = true;
                count = 0;
            }
            if(gpsState==true && savegpsState ==true){
               emit update_StartPoint(QString::number(msg.longitude,'f',7),QString::number(msg.latitude,'f',7));
            }
        }
 }catch (...) {
    ROS_ERROR("接收移动机器人起点GPS坐标信息失败！");
    throw;   //接收了异常之后继续往外抛
  }
}






void CQNode::points_callback(const std_msgs::String &msg)
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

void CQNode::Get_gps_callback(const sensor_msgs::NavSatFix &msg){
    QString get_longitude = QString("%1").arg(msg.longitude, 0, 'f',9);
    QString get_latitude = QString("%1").arg(msg.latitude, 0, 'f',9);
    QString get_status = QString("%1").arg(msg.status.status);
    emit updateGetgps(get_longitude,get_latitude,get_status);

}
void CQNode::sonar_callback(const geometry_msgs::Twist &msg)
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
QMap<QString,QString> CQNode::get_topic_list()
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
void CQNode::obstacle_callback(const geometry_msgs::Twist &msg)
{
    obstacle_range = QString("%1").arg(msg.linear.x);  //20米的距离
    obstacle_state = QString("%1").arg(msg.linear.y);  //有障碍物是1.0，没有障碍物是0.0
    emit updateObstacleState(obstacle_range,obstacle_state);
}

QImage CQNode::Mat2QImage(cv::Mat const& src)
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

void CQNode::run() {
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    switch (init_index) {
    case 0: {
//        ROS_ERROR("yuanshi tuxiang  000");
      RawImage_sub = it.subscribe(init_topic_name, 10, &CQNode::RawImageCallback, this);
      break;
    }
    case 1: {
      PCLImage_sub = it.subscribe(init_topic_name, 1, &CQNode::PCLImageCallback, this);
      break;
    }
    case 2: {
      FusionImage_sub = it.subscribe(init_topic_name, 1, &CQNode::FusionImageCallback, this);
      break;
    }
    case 3: {
      MapStartPoint_sub = nh.subscribe(init_topic_name, 10, &CQNode::MapStartPoint_Callback, this);
      break;
    }
    case 4: {
      points_sub = nh.subscribe(init_topic_name, 10, &CQNode::points_callback, this);
      break;
    }
    case 5: {
      sonar_sub = nh.subscribe(init_topic_name, 1, &CQNode::sonar_callback, this);
      break;
    }
    case 6: {
      obstacle_sub = nh.subscribe(init_topic_name, 1, &CQNode::obstacle_callback, this);
      break;
    }
    case 7: {
      get_gps_sub = nh.subscribe(init_topic_name, 1, &CQNode::Get_gps_callback, this);
      break;
    }
      }

    while ( ros::ok()) {

        ros::spinOnce();
    }
//	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}
void CQNode::log( const LogLevel &level, const std::string &msg) {
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
