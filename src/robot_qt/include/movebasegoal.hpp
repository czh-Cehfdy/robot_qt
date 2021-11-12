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
    movebasegoal(int argc, char** argv);
    movebasegoal(int argc, char** argv, std::string node_name);
    virtual ~movebasegoal();
    bool init();
    bool init(const std::string &master_url, const std::string &host_url);
    void run();
    void getGoalPoints(const vector<Eigen::VectorXd>& goals);//方便在两个类中调用
    bool doStuff(const double& x_set, const double& y_set, const double& z_set, const double& x, const double& y, const double& z, const double& w);
    void doneCB(const actionlib::SimpleClientGoalState& state,
                const move_base_msgs::MoveBaseResultConstPtr& result);
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
    vector<Eigen::VectorXd> m_goalPoints;

    double last_x_set; double last_y_set;
    bool success_ = false;
    size_t ind = 0;
};
}  // namespace robot_qt

#endif /* robot_qt_QNODE_HPP_ */
