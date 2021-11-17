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
#ifndef MOVEBASEGOAL_HPP
#define MOVEBASEGOAL_HPP
/*****************************************************************************
** Includes
*****************************************************************************/
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <QThread>
#include <iostream>
#include <string>     // std::string, std::to_string
#include <Eigen/Eigen>
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>
#include "tf/tf.h"
#include <tf/transform_listener.h>
#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include <cmath>
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
/*****************************************************************************
** Namespaces
*****************************************************************************/
namespace robot_qt {

using namespace std;
/* Eigen是一个高层次的C ++库，有效支持得到的线性代数，矩阵和矢量运算，数值分析及其相关的算法。 */
using namespace Eigen;
/*****************************************************************************
** Class
*****************************************************************************/

class movebasegoal : public QThread {
    Q_OBJECT
public:
    movebasegoal(int argc, char** argv, std::string node_name);
    virtual ~movebasegoal();
    bool init();
    bool init(const std::string &master_url, const std::string &host_url);
    void run();
    void getGoalPoints(const vector<Eigen::Vector4d>& goals);//方便在两个类中调用
    void goalPub(const size_t& i);
    size_t m_currentInd = 0;
    size_t m_lastInd = -1;
    QString msg;
    float sum = 0.0;
    float last_x = 0.0;
    float last_y = 0.0;
    float set_dis = 1.0;
    bool send_last = false;
    int reset = 0;
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
    MoveBaseClient* ac_;
Q_SIGNALS:
    void rosShutdown();
    void updateMBMsg(const QString& Msg);

private:
    int init_argc;
    char** init_argv;
    std::string init_node_name;
    std::string init_topic_name;
    vector<Eigen::Vector4d> m_goalPoints;
    ros::Subscriber odom_sub;
    ros::Publisher goals_pub;
    bool send_flag = false;
    int count_first = 0;

    void odom_callback(const nav_msgs::Odometry &msg);


};
}  // namespace robot_qt

#endif /* robot_qt_QNODE_HPP_ */
