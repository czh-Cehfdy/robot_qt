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
movebasegoal::movebasegoal(int argc, char** argv) :
    init_argc(argc),
    init_argv(argv)
    {}
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
    //MoveBaseClient ac("move_base", true);
    ac_ = new MoveBaseClient("move_base", true);
    //wait for the action server to come up
    while (!ac_->waitForServer(ros::Duration(5.0))) {
        QString msg = "Waiting for the move_base action server to come up";
        updateMBMsg(msg);
    }
    tf::StampedTransform world_pose;
    tf::TransformListener listener_;
    QString msg = "MoveBase节点初始化成功！";
    updateMBMsg(msg);
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
    ac_ = new MoveBaseClient("move_base", true);
    //wait for the action server to come up
    while (!ac_->waitForServer(ros::Duration(5.0))) {
        QString msg = "Waiting for the move_base action server to come up";
        updateMBMsg(msg);
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    start();
    return true;
}
bool movebasegoal::doStuff(const double& x_set, const double& y_set, const double& z_set, const double& x, const double& y, const double& z, const double& w){
    move_base_msgs::MoveBaseGoal goal;
    QString msg = "已进入处理阶段，进入doStuff函数…";
    updateMBMsg(msg);
    if (x_set != last_x_set || y_set != last_y_set)
    {
     //发送目标点
     goal.target_pose.header.frame_id = "map";
     goal.target_pose.header.stamp = ros::Time::now();

     goal.target_pose.pose.position.x = x_set;
     goal.target_pose.pose.position.y = y_set;
     goal.target_pose.pose.position.z = 0;

    //tf::Quaternion q;  这里给的都是单位四元素，
    //q.setRotation(tf::Vector3(0, 0, 1), th_set);
     goal.target_pose.pose.orientation.x = x;
     goal.target_pose.pose.orientation.y = y;
     goal.target_pose.pose.orientation.z = z;
     goal.target_pose.pose.orientation.w = w;
     msg = "目标点信息格式已打包完毕…";
     updateMBMsg(msg);

     msg = "正准备发送目标点………";
     updateMBMsg(msg);
     msg = "已经发送，等待回复………";
     updateMBMsg(msg);
     ac_->sendGoal(goal,boost::bind(&movebasegoal::doneCB, this, _1, _2),
        MoveBaseClient::SimpleActiveCallback(),
        MoveBaseClient::SimpleFeedbackCallback());
    success_ = false;
    }
    last_x_set = x_set; last_y_set = y_set;
    msg = "当前success_状态为："+QString("%0").arg(success_)+",正将其作为doStuff的返回值返回！";
    updateMBMsg(msg);
    return success_;
}
void movebasegoal::doneCB(const actionlib::SimpleClientGoalState& state,
                               const move_base_msgs::MoveBaseResultConstPtr& result){
    QString msg = "已经进入doneCB回调函数………";
    updateMBMsg(msg);
    msg = "返回的state结果是："+QString::fromStdString(state.toString());
    updateMBMsg(msg);
    // boost::unique_lock<boost::mutex> lock(wp_mutex_);
    switch (state.state_) {
    case actionlib::SimpleClientGoalState::ABORTED:
    {
        msg = "NavigationManager::moveBaseResultCallback: ABORTED";
        updateMBMsg(msg);
    }
    break;
    case actionlib::SimpleClientGoalState::SUCCEEDED:
    {
        msg = "NavigationManager::moveBaseResultCallback: SUCCEEDED";
        updateMBMsg(msg);
        success_ = true;
    }
    break;
    default:
        break;
    }
}
void movebasegoal::getGoalPoints(const vector<Eigen::VectorXd>& goals){
    m_goalPoints = goals;
}
void movebasegoal::run() {
    ros::NodeHandle nh;
    QString msg = "已进入自定义线程函数……";
    updateMBMsg(msg);
    if(m_goalPoints.begin()!=m_goalPoints.end())
    {
        QString msg = "已收到所有目标点信息！下面是详细信息：";
        updateMBMsg(msg);
        for(size_t i = 0; i< m_goalPoints.size();++i){
         msg = "第"+QString::number(i+1)+"个目标点信息为："+QString("%0，%1,%2,%3,%4,%5,%6,%7").arg(m_goalPoints[i][0])
                 .arg(m_goalPoints[i][1]).arg(m_goalPoints[i][2]).arg(m_goalPoints[i][3]).arg(m_goalPoints[i][4])
                 .arg(m_goalPoints[i][5]).arg(m_goalPoints[i][6]).arg(m_goalPoints[i][7]);
        updateMBMsg(msg);
        }
     }

    msg = "现在开始进行发送目标点前的准备工作，当前是第："+QString::number(ind+1)+"个目标点…";
    updateMBMsg(msg);
    doStuff(m_goalPoints[ind][0],m_goalPoints[ind][1],m_goalPoints[ind][2],m_goalPoints[ind][3],m_goalPoints[ind][4],
            m_goalPoints[ind][5],m_goalPoints[ind][6]);
    msg = "已经跳出第："+QString::number(ind+1)+"个目标点doStuff函数";
    updateMBMsg(msg);
    while ( ros::ok()) {
        msg = "进入while ( ros::ok())循环";
        updateMBMsg(msg);
        bool ok = doStuff(m_goalPoints[ind][0],m_goalPoints[ind][1],m_goalPoints[ind][2],m_goalPoints[ind][3],m_goalPoints[ind][4],
                m_goalPoints[ind][5],m_goalPoints[ind][6]);
        msg = "当前bool ok 值为："+ QString("%0").arg(ok);
        updateMBMsg(msg);
        if (ok) {

                  ind++;
                  msg = "已将 ind 重新赋值，当前 ind 值为："+ QString("%0").arg(ind);
                  updateMBMsg(msg);
                  if (ind > m_goalPoints.size()-1) {
                      msg = "所有目标点都已发送完毕，任务执行结束!";
                      updateMBMsg(msg);
                    break;
                }
         }
        ros::spinOnce();
    }


//	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

}  // namespace robot_qt
