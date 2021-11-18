/**
 * @file /src/movebasegoal.cpp
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
#include "../include/movebasegoal.hpp"


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace robot_qt {

/*****************************************************************************
** Implementation
*****************************************************************************/
movebasegoal::movebasegoal(int argc, char** argv,std::string node_name) :
    init_argc(argc),
    init_argv(argv),
    init_node_name(node_name)
    {}

movebasegoal::~movebasegoal() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
    wait();
}

bool movebasegoal::init() {
    ros::init(init_argc,init_argv,init_node_name);//"robot_qt"
    if ( ! ros::master::check() ) {  //如果rosmaster没有启动，返回false
        return false;
    }
    msg = "MoveBase节点初始化成功！";
    emit updateMBMsg(msg);
    m_qnodeStart = true ;
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    start();
    return true;
}

bool movebasegoal::init(const std::string &master_url, const std::string &host_url) {
    std::map<std::string,std::string> remappings;
    remappings["__master"] = master_url;
    remappings["__hostname"] = host_url;
    ros::init(remappings,init_node_name);
    if ( ! ros::master::check() ) {
        return false;
    }
    msg = "MoveBase节点初始化成功！";
    emit updateMBMsg(msg);
    m_qnodeStart = true ;
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    start();
    return true;
}
void movebasegoal::odom_callback(const nav_msgs::Odometry &msg)
{
    if (m_currentInd > m_goalPoints.size()-1) {
        QString msg = "所有总共"+QString::number(m_currentInd)+"个目标点均已成功发送！";
        emit updateMBMsg(msg);
        m_lastInd = -1;
        m_currentInd = 0;
        msg = "此时 m_lastInd = -1; m_currentInd = 0";
        emit updateMBMsg(msg);
    }
    if(count_first==0){
        QString msg = "我获取了新的系列目标点，此时count_first==0";
        emit updateMBMsg(msg);
        send_flag =true;
        msg = "send_flag =true 准备发送第"+QString::number(m_currentInd)+"个目标点";
        emit updateMBMsg(msg);
    }
    count_first +=1;
    auto x = msg.pose.pose.position.x;
    auto y = msg.pose.pose.position.y;
    auto dis = sqrt(pow(m_goalPoints[m_currentInd][0]-x,2)+pow(m_goalPoints[m_currentInd][1]-y,2));
    auto dis_delt = sqrt(pow(last_x-x,2)+pow(last_y-y,2));
    sum += dis_delt;

    if(m_lastInd==m_currentInd){
      if(dis < set_dis)
      {
          if (m_currentInd != m_goalPoints.size()-1) {
              QString msg = "此时距离目标点仅剩:"+QString("%0").arg(set_dis)+"m，开始发下一个目标点";
              emit updateMBMsg(msg);
              m_currentInd += 1;
              send_flag =true;

          }
          else{
              if(send_last == false){
                  m_goalPoints[m_currentInd][2] = msg.pose.pose.orientation.z;
                  m_goalPoints[m_currentInd][3] = msg.pose.pose.orientation.w;
                  send_flag =true;
                  QString msg = "当前是最后一个点！！！此时 m_lastInd = -1; m_currentInd = 0，把终点姿态发一下";
                  emit updateMBMsg(msg);
                  send_last = true;
              }

          }
          if(dis < 0.2){
              if(m_currentInd == m_goalPoints.size()-1){
                  m_currentInd = 0;
                  m_lastInd = -1;
              }
          }

      }
    }
    if(count_first > 20){
        count_first = 1;
        sum = 0;
    }
    if(sum < 0.2){
        if(reset==0){
            send_flag =true;
            QString msg = "好像刚发的目标点小车还没运行，重新发一次…send_flag为"+QString("%0").arg(send_flag);
            emit updateMBMsg(msg);
        }
        reset +=1;
        if(reset==5){
            send_flag =true;
            QString msg = "好像刚发的目标点小车还没运行，已经连续3次，请检查！再最后重新发一次…";
            emit updateMBMsg(msg);
        }
    }
    last_x = x;
    last_y = y;

}
void movebasegoal::goalPub(const size_t& i){
     geometry_msgs::PoseStamped goal;
     msg = "进入第"+QString::number(i)+"个目标点发送函数…";
     emit updateMBMsg(msg);
     //发送目标点
     goal.header.frame_id = "map";
     goal.header.stamp = ros::Time::now();

     goal.pose.position.x = m_goalPoints[i][0];
     goal.pose.position.y = m_goalPoints[i][1];
     goal.pose.position.z = 0;

    //tf::Quaternion q;  这里给的都是单位四元素，
    //q.setRotation(tf::Vector3(0, 0, 1), th_set);
     goal.pose.orientation.x = 0;
     goal.pose.orientation.y = 0;
     goal.pose.orientation.z = m_goalPoints[i][2];
     goal.pose.orientation.w = m_goalPoints[i][3];
     msg = "第"+QString::number(i)+"个目标点信息格式已打包完毕…";
     emit updateMBMsg(msg);

     msg = "正准备发送第"+QString::number(i)+"个目标点…";
     emit updateMBMsg(msg);
     goals_pub.publish(goal);
     msg = "成功发送第"+QString::number(i)+"个目标点!!!";
     emit updateMBMsg(msg);
     m_lastInd = i;
}
void movebasegoal::getGoalPoints(const vector<Eigen::Vector4d>& goals){
    if (equal(goals.begin(), goals.end(), m_goalPoints)){
        msg = "两次系列目标点相同，放弃处理，请检查!!!";
        emit updateMBMsg(msg);
    }
    else{
        m_goalPoints = goals;
        msg = "成功调用getGoalPoints函数获取新的系列目标点!!!";
        emit updateMBMsg(msg);
        if(m_goalPoints.begin()!=m_goalPoints.end())
        {
            msg = "已收到所有目标点信息！下面是详细信息：";
            emit updateMBMsg(msg);
            for(size_t i = 0; i< m_goalPoints.size();++i){
             msg = "第"+QString::number(i)+"个目标点信息为："+QString("%0，%1,%2,%3").arg(m_goalPoints[i][0])
                     .arg(m_goalPoints[i][1]).arg(m_goalPoints[i][2]).arg(m_goalPoints[i][3]);
            emit updateMBMsg(msg);
            }
         }
        count_first = 0;
        msg = "此时将count_first = 0";
        emit updateMBMsg(msg);
    }
}
void movebasegoal::run() {
    ros::NodeHandle nh;
//    odom_sub=nh.subscribe("odometry/imu_incremental",10,&movebasegoal::odom_callback,this);
    odom_sub=nh.subscribe("odom",10,&movebasegoal::odom_callback,this);
    goals_pub = nh.advertise<geometry_msgs::PoseStamped>("move_base_simple/goal", 10);

    while ( ros::ok()) {
        if(send_flag){
           QString msg = "现在开始进行发送目标点前的准备工作，当前是第"+QString::number(m_currentInd)+"个目标点…";
           emit updateMBMsg(msg);
           goalPub(m_currentInd);
           send_flag = false;
        }
        ros::spinOnce();
    }
//	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

}  // namespace robot_qt
