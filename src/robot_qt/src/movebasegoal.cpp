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
    if(m_goalPoints.size()!=0){
        QString msggoal1 = QString::number(m_currentInd+1);
        QString msggoal2 = QString::number(m_goalPoints.size());
        emit updategoalMsg(msggoal1,msggoal2);
    }else{
        QString msggoal1 = QString::number(m_currentInd);
        QString msggoal2 = QString::number(m_goalPoints.size());
        emit updategoalMsg(msggoal1,msggoal2);
    }

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
    auto orx = msg.pose.pose.orientation.x;
    auto ory = msg.pose.pose.orientation.y;
    auto orz = msg.pose.pose.orientation.z;
    auto orw = msg.pose.pose.orientation.w;
    QString odommsg = "当前小车位姿信息如下-----------------------------------------------------------------------------------";
    emit updateOdomData(odommsg);
    odommsg = "odom信息：";
    emit updateOdomData(odommsg);
    odommsg = QString("x=%0      ,      y=%1").arg(x, 0, 'f',10).arg(y, 0, 'f',10);
    emit updateOdomData(odommsg);
    odommsg = "四元数信息：";
    emit updateOdomData(odommsg);
    odommsg = QString("x=%0,y=%1,z=%2,w=%3").arg(orx, 0, 'f',11).arg(ory, 0, 'f',11).arg(orz, 0, 'f',11).arg(orw, 0, 'f',11);
    emit updateOdomData(odommsg);
    auto dis = sqrt(pow(m_goalPoints[m_currentInd][0]-x,2)+pow(m_goalPoints[m_currentInd][1]-y,2));
    auto dis_delt = sqrt(pow(last_x-x,2)+pow(last_y-y,2));
    sum += dis_delt;
    if(m_lastInd==m_currentInd){
        isdisplayFlag =false;
        QString odomdis = QString("当前距离第%0个目标点距离：distance = %1").arg(m_currentInd+1).arg(dis);
        emit updateOdomDisData(odomdis);
      if(dis < set_dis)
      {
          if (m_currentInd != m_goalPoints.size()-1) {
              QString msg = "此时距离目标点仅剩:"+QString("%0").arg(dis)+"m，开始发下一个目标点";
              emit updateMBMsg(msg);
              odomdis = "此时距离目标点仅剩:"+QString("%0").arg(dis);
              emit updateOdomDisData(odomdis);
              m_currentInd += 1;
              send_flag =true;

          }
          else{
              if(send_last == false){
                  m_goalPoints[m_currentInd][5] = msg.pose.pose.orientation.z;
                  m_goalPoints[m_currentInd][6] = msg.pose.pose.orientation.w;
                  send_flag =true;
                  QString msg = "当前是最后一个点！！！此时 m_lastInd = -1; m_currentInd = 0，把终点姿态发一下";
                  emit updateMBMsg(msg);
                  send_last = true;
              }

          }
          if(dis < 0.5){
              if(m_currentInd == m_goalPoints.size()-1){
                  m_currentInd = 0;
                  m_lastInd = -1;
                  m_goalPoints.clear();
                  if(m_currentInd==0&&m_lastInd == -1&&m_goalPoints.size()==0){
                      QString odomdis = "当前最后一个目标点，当前距离小于0.5米，已经清空标志位和数据！";
                      emit updateOdomDisData(odomdis);
                  }

              }
          }

      }
    }
    else{
        if(!isdisplayFlag){
            QString odomdis = "目标点均已经发送完毕，不再显示距离！";
            emit updateOdomDisData(odomdis);
            isdisplayFlag = true;
        }
    }
    if(count_first > 200){
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
     goal.pose.position.z = m_goalPoints[i][2];

    //tf::Quaternion q;  这里给的都是单位四元素，
    //q.setRotation(tf::Vector3(0, 0, 1), th_set);
     goal.pose.orientation.x = m_goalPoints[i][3];
     goal.pose.orientation.y = m_goalPoints[i][4];
     goal.pose.orientation.z = m_goalPoints[i][5];
     goal.pose.orientation.w = m_goalPoints[i][6];
     msg = "第"+QString::number(i)+"个目标点信息格式已打包完毕…";
     emit updateMBMsg(msg);

     msg = "正准备发送第"+QString::number(i)+"个目标点…";
     emit updateMBMsg(msg);
     goals_pub.publish(goal);
     msg = "成功发送第"+QString::number(i)+"个目标点!!!";
     emit updateMBMsg(msg);
     m_lastInd = i;
}
void movebasegoal::getGoalPoints(const vector<Vector7d>& goals){
//    if (goals.size()==m_goalPoints.size()){
//        msg = "goals.size()==m_goalPoints.size()";
//        emit updateMBMsg(msg);
//        size_t count = 0;
//        for(size_t i = 0; i < goals.size();++i){
//            if(goals[i][0]==m_goalPoints[i][0]&&goals[i][1]==m_goalPoints[i][1]&&goals[i][2]==m_goalPoints[i][2]&&goals[i][3]==m_goalPoints[i][3]&&
//               goals[i][4]==m_goalPoints[i][4]&&goals[i][5]==m_goalPoints[i][5]&&goals[i][6]==m_goalPoints[i][6]){
//               count+=1;
//            }
//            }
//        if(count == goals.size()){
//            msg = "两次系列目标点相同，放弃处理，请检查!!!";
//            emit updateMBMsg(msg);
//            count = 0;
//            return;
//        }
//     }
//    else{
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
// }
}
void movebasegoal::run() {
    ros::NodeHandle nh;
    //实车用第第一个话题：odometry/imu_incremental 仿真用odom
    if(!istrueCar){
       QString msgstatus = "false";
       emit updatestatusMsg(msgstatus);
       odom_sub=nh.subscribe("odom",10,&movebasegoal::odom_callback,this);
    }else{
       QString msgstatus = "true";
       emit updatestatusMsg(msgstatus);
       odom_sub=nh.subscribe("odometry/imu_incremental",10,&movebasegoal::odom_callback,this);
    }
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
