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
    odom_count += 1;
    if(odom_count == 50){
        if(m_goalPoints.size()!=0){
            QString msggoal1 = QString::number(m_currentInd+1);
            QString msggoal2 = QString::number(m_goalPoints.size());
            emit updategoalMsg(msggoal1,msggoal2);
        }else{
//            QString msggoal1 = QString::number(m_currentInd);
//            QString msggoal2 = QString::number(m_goalPoints.size());
//            emit updategoalMsg(msggoal1,msggoal2);
        }

        if (m_currentInd > m_goalPoints.size()-1) {
            QString msg = "A total of "+QString::number(m_currentInd)+" target points have been sent";
            emit updateMBMsg(msg);
            m_lastInd = -1;
            m_currentInd = 0;
            msg = "Now m_lastInd = -1; m_currentInd = 0";
            emit updateMBMsg(msg);
        }
        if(count_first==0){
            QString msg = "Get New Target Goals，Current count_first == 0";
            emit updateMBMsg(msg);
            send_flag =true;
            msg = "send_flag =true，Ready to send target point "+QString::number(m_currentInd);
            emit updateMBMsg(msg);
        }
        count_first +=1;
        auto x = msg.pose.pose.position.x;
        auto y = msg.pose.pose.position.y;
        auto orx = msg.pose.pose.orientation.x;
        auto ory = msg.pose.pose.orientation.y;
        auto orz = msg.pose.pose.orientation.z;
        auto orw = msg.pose.pose.orientation.w;
        QString odommsg = "Current Pose Msgs--------------------------------------------------------------------------";
        emit updateOdomData(odommsg);
        odommsg = "Odom Msg:";
        emit updateOdomData(odommsg);
        odommsg = QString("x=%0      ,      y=%1").arg(x, 0, 'f',10).arg(y, 0, 'f',10);
        emit updateOdomData(odommsg);
        odommsg = "Quaternion Msgs:";
        emit updateOdomData(odommsg);
        odommsg = QString("x=%0,y=%1,z=%2,w=%3").arg(orx, 0, 'f',11).arg(ory, 0, 'f',11).arg(orz, 0, 'f',11).arg(orw, 0, 'f',11);
        emit updateOdomData(odommsg);
        auto dis = sqrt(pow(m_goalPoints[m_currentInd][0]-x,2)+pow(m_goalPoints[m_currentInd][1]-y,2));
        auto dis_delt = sqrt(pow(last_x-x,2)+pow(last_y-y,2));
        sum += dis_delt;
        if(m_lastInd==m_currentInd){
            isdisplayFlag =false;
            QString odomdis = QString("The current distance to the %0th target point is : %1").arg(m_currentInd+1).arg(dis);
            emit updateOdomDisData(odomdis);
          if(dis < set_dis)
          {
              if (m_currentInd != m_goalPoints.size()-1) {
                  QString msg = "The distance to the target point is only "+QString("%0").arg(dis)+"m， ready to send the next target point";
                  emit updateMBMsg(msg);
                  odomdis = "The distance to the target point is only:"+QString("%0").arg(dis);
                  emit updateOdomDisData(odomdis);
                  m_currentInd += 1;
                  send_flag =true;

              }
              else{
                  if(send_last == false){
                      m_goalPoints[m_currentInd][3] = msg.pose.pose.orientation.x;
                      m_goalPoints[m_currentInd][4] = msg.pose.pose.orientation.y;
                      m_goalPoints[m_currentInd][5] = msg.pose.pose.orientation.z;
                      m_goalPoints[m_currentInd][6] = msg.pose.pose.orientation.w;
                      send_flag =true;
                      QString msg = "The current is the last target point！！！Now m_lastInd = -1; m_currentInd = 0，Send Terminal Pose";
                      emit updateMBMsg(msg);
                      send_last = true;
                  }

              }
              if(dis < 0.5){
                  if(m_currentInd == m_goalPoints.size()-1){
                      m_currentInd = 0;
                      m_lastInd = -1;
//                      vector<Vector7d>().swap(m_goalPoints);
                      m_goalPoints.clear();
                      if(m_currentInd==0&&m_lastInd == -1&&m_goalPoints.size()==0){
                          QString odomdis = "Now is the last target point, the current distance is less than 0.5 meters, the flag bits and data have been cleared!";
                          emit updateOdomDisData(odomdis);
                      }
                  }
              }

          }
        }
        else{
            if(!isdisplayFlag){
                QString odomdis = "Target points have been sent, no longer display distance!";
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
                QString msg = "It seems that the target point car just sent is not running yet, send again…………send_flag is"+QString("%0").arg(send_flag);
                emit updateMBMsg(msg);
            }
            reset +=1;
            if(reset==5){
                send_flag =true;
                QString msg = "It seems that the target point car just sent has not run, it has been 3 times in a row, please check! Send it again for the last time...";
                emit updateMBMsg(msg);
            }
        }
        last_x = x;
        last_y = y;
        odom_count = 0;
    }

}
void movebasegoal::goalPub(const size_t& i){
     geometry_msgs::PoseStamped goal;
     msg = "Enter the "+QString::number(i)+"th target point send function...";
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
     msg = "The "+QString::number(i)+"th target point information format has been packaged...";
     emit updateMBMsg(msg);

     msg = "Preparing to send the "+QString::number(i)+"th target point";
     emit updateMBMsg(msg);
     goals_pub.publish(goal);
     msg = "The "+QString::number(i)+"th target point was sent successfully";
     emit updateMBMsg(msg);
     m_lastInd = i;
}
void movebasegoal::getGoalPoints(const vector<Vector7d>& goals){
        vector<Vector7d>().swap(m_goalPoints);
        vector<double>().swap(Disjudge);
        vector<Vector7d> m_temp;
        m_temp = goals;
        m_goalPoints = m_temp;

        msg = "Successfully call getGoalPoints to get a new set of target points!!!";
        emit updateMBMsg(msg);
        if(m_goalPoints.begin()!=m_goalPoints.end())
        {
            msg = "All target points have been received! Here are the details:";
            emit updateMBMsg(msg);
            for(size_t i = 0; i< m_goalPoints.size();++i){
             msg = "The information of the "+QString::number(i)+"th target point is："+QString("%0，%1").arg(m_goalPoints[i][0])
                     .arg(m_goalPoints[i][1]);
            emit updateMBMsg(msg);
            }
         }
        if(goals.begin()!=goals.end())
        {
            for(size_t i = 0; i< goals.size();++i){
                if(i==0){
                    double dis = sqrt(pow(goals[i][0]-0.0,2)+pow(goals[i][1]-0.0,2));
                    Disjudge.push_back(dis);
                    QString msg1 = QString("Distance (%0，%1)is：").arg(i+1).arg(0)+QString("%0").arg(dis);
                    emit updateDisMsg(msg1);
                }
                else{
                    double dis = sqrt(pow(goals[i][0]-goals[i-1][0],2)+pow(goals[i][1]-goals[i-1][1],2));
                    Disjudge.push_back(dis);
                    QString msg1 = QString("Distance (%0，%1)is：").arg(i+1).arg(i)+QString("%0").arg(dis);
                    emit updateDisMsg(msg1);
                }
            }
         }
        count_first = 0;
        msg = "Now count_first = 0";
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
       odom_sub=nh.subscribe("odometry/imu",10,&movebasegoal::odom_callback,this);
    }
    goals_pub = nh.advertise<geometry_msgs::PoseStamped>("move_base_simple/goal", 10);

    while ( ros::ok()) {
        if(send_flag){
           QString msg = "It is time to start the preparation before sending the target point, currently is the "+QString::number(m_currentInd)+"th target point";
           emit updateMBMsg(msg);
           goalPub(m_currentInd);
           send_flag = false;
        }
        ros::spinOnce();
    }
//	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

}  // namespace robot_qt
