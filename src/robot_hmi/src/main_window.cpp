/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/robot_hmi/main_window.hpp"
#include <string>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QJsonArray>
/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace robot_hmi {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
    , qnode_main(argc,argv),
      rostopic_list(argc,argv),
    qnode_GetStartPoint(argc, argv, "qnode_SP", "gps_data/rtk", 3),
    qnode_raw_image(argc, argv, "qnode_raw_image", "camera/image", 0),
    qnode_fusion_image(argc, argv, "qnode_fusion_image", "fusion/image", 2),
    qnode_pcl_image(argc, argv, "qnode_mask", "fusion/mask", 1),
    qnode_points(argc, argv, "qnode_Points", "points/location", 4),
    qnode_sonar(argc, argv, "qnode_Sonar", "sonar_pub", 5),
    qnode_obstacle(argc, argv, "qnode_Obstacle", "isObstacle_cloud", 6),
    qnode_Get_gps(argc, argv, "qnode_Get_gps", "fix", 7),
    PTR_(new QNode(argc, argv, "qnode_Get_gps", "fix", 7))
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    initUis();
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    ReadSettings();   //读取配置文件
	setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode_main, SIGNAL(rosShutdown()), this, SLOT(close()));

	/*********************
	** Logging
	**********************/
    ui.view_logging->setModel(qnode_main.loggingModel());
    QObject::connect(&qnode_main, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    /*********************
    ** Auto Start
    **********************/
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked();
    }

    connect(ui.horizontalSlider_raw,SIGNAL(valueChanged(int)),this,SLOT(slot_raw_value_change(int)));
    connect(ui.horizontalSlider_linera,SIGNAL(valueChanged(int)),this,SLOT(slot_linera_value_change(int)));
    connect(ui.pushButton_i,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));   //多个按钮链接同一个槽函数
    connect(ui.pushButton_j,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_l,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_n,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_m,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_br,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_u,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_o,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));

    connect(ui.laser_btn,SIGNAL(clicked()),this,SLOT(()));

    connect(ui.btn_QudongStart,SIGNAL(clicked()),this,SLOT(slot_Qudong_start()));
    connect(ui.btn_LocationStart,SIGNAL(clicked()),this,SLOT(slot_location_start()));
    connect(ui.btn_MoveBaseStart,SIGNAL(clicked()),this,SLOT(slot_movebase_start()));
    connect(ui.refreash_topic_btn,SIGNAL(clicked()),this,SLOT(slot_update_ROSTOPIC()));

    connect(ui.btn_send_path,SIGNAL(clicked()),this,SLOT(slot_goal_start()));
    connect(ui.btn_clear_path_ros,SIGNAL(clicked()),this,SLOT(slot_goal_output()));

    //get_gps
    connect(ui.btn_savegps,SIGNAL(clicked()),this,SLOT(slot_save_gps()));
    connect(ui.btn_display_data,SIGNAL(clicked()),this,SLOT(slot_dispaly_gpsdata()));
    connect(ui.btn_display_gps, &QPushButton::pressed, this, [=]() {
//          qnode_Get_gps.init();
          PTR_->init();
          ui.btn_DisplayPCLImage->setDisabled(true);
      });
    connect(ui.btn_close, &QPushButton::pressed, this, [=]() {
        if(!PTR_){
            delete PTR_;
            PTR_ = NULL;
        }

//          ui.btn_DisplayPCLImage->setDisabled(true);
      });

    connect(ui.btn_chooseGPS,SIGNAL(clicked()),this,SLOT(slot_chooseGoalGPS()));
    connect(ui.btn_test,SIGNAL(clicked()),this,SLOT(slot_testgpsdata()));

    connect(ui.btn_loadmap,&QPushButton::clicked, [&](){
        ui.btn_changeMode->setDisabled(false);
        ui.btn_loadmap->setDisabled(true);
        ui.label_11->setStyleSheet("color:rgb(78, 154, 6)");
        ui.label_11->setText("已成功加载地图！");
        ui.tabWidget_4->setVisible(true);

        ui.btn_changeMode->setVisible(true);
        ui.btn_changeMode->setDisabled(false);
        ui.btn_project->setVisible(true);
        ui.btn_project->setDisabled(true);
        ui.btn_develop->setVisible(true);
        ui.btn_develop->setDisabled(true);
    });
    connect(ui.btn_changeMode, &QPushButton::clicked, [&](){

        ui.btn_getSP->setVisible(false);
        ui.btn_getSP->setDisabled(true);

        ui.btn_getTP->setVisible(false);
        ui.btn_getTP->setDisabled(true);

        ui.btn_pitch->setVisible(false);
        ui.btn_pitch->setDisabled(true);

        ui.btn_plan->setVisible(false);
        ui.btn_plan->setDisabled(true);

        ui.btn_clear->setVisible(false);
        ui.btn_clear->setDisabled(true);

        ui.btn_draw->setVisible(false);
        ui.btn_draw->setDisabled(true);

        ui.btn_develop->setDisabled(false);
        ui.btn_project->setDisabled(false);

      });
    connect(ui.btn_develop, &QPushButton::clicked, [&](){
//        ui.btn_develop->setStyleSheet("QPushButton{border-image: url(:/qt/btn.png);}");
        ui.btn_getSP->setVisible(false);
        ui.btn_getSP->setDisabled(true);

        ui.btn_getTP->setVisible(false);
        ui.btn_getTP->setDisabled(true);

        ui.btn_pitch->setVisible(true);
        ui.btn_pitch->setDisabled(false);

        ui.btn_plan->setVisible(true);
        ui.btn_plan->setDisabled(false);

        ui.btn_clear->setVisible(true);
        ui.btn_clear->setDisabled(false);

        ui.btn_draw->setVisible(true);
        ui.btn_draw->setDisabled(false);

        ui.btn_develop->setDisabled(true);
        ui.btn_project->setDisabled(true);

      });

    connect(ui.btn_project, &QPushButton::clicked, [&]() {
        ui.btn_getSP->setVisible(true);
        ui.btn_getSP->setDisabled(false);

        ui.btn_getTP->setVisible(true);
        ui.btn_getTP->setDisabled(false);

        ui.btn_plan->setVisible(true);
        ui.btn_plan->setDisabled(false);

        ui.btn_clear->setVisible(true);
        ui.btn_clear->setDisabled(false);

        ui.btn_draw->setVisible(true);
        ui.btn_draw->setDisabled(false);

        ui.btn_develop->setDisabled(true);
        ui.btn_project->setDisabled(true);
      });



//    connect(ui.btn_closemap,&QPushButton::pressed, this, [=]() {
//        ui.btn_pitch->setVisible(false);

//    });


//    connect(ui.btn_PCL,SIGNAL(clicked()),this,SLOT(slot_PCL_start()));
//    connect(ui.btn_controller,SIGNAL(clicked()),this,SLOT(slot_controller_start()));
//    connect(ui.btn_planning,SIGNAL(clicked()),this,SLOT(slot_planning_start()));
//    connect(ui.btn_carStart,SIGNAL(clicked()),this,SLOT(slot_carstart_start()));
//    connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(slot_roscore()));

    cmd = new QProcess(this);
    connect(cmd , SIGNAL(readyReadStandardOutput()) , this , SLOT(on_readoutput()));
    ui.treeWidget->setColumnWidth(0, 180);  //设置列宽
    ui.treeWidget_obstacles->setColumnWidth(0, 180);  //设置列宽
    ui.tabWidget_control->setCurrentIndex(0);
    connect(ui.btn_interact,SIGNAL(clicked()),this,SLOT(slot_interact));

    connect(ui.checkBox_tip,SIGNAL(stateChanged(int)),this,SLOT(slot_start_tip(int)));   //障碍物预警check_box



    initMap();
    initconections();
    initRviz();
    initRviz_obstacles();


}
//初始化UI
void MainWindow::initUis()
{
    ui.button_connect->setIcon(QIcon(":/images/line.png"));
    ui.quit_button->setIcon(QIcon(":/images/quit.jpeg"));
    ui.groupBox_scout->setEnabled(false);
    ui.tab_manager->setCurrentIndex(0);
    ui.tabWidget->setCurrentIndex(0);
    ui.quit_button->setEnabled(false);


}
void MainWindow::initTopicList()
{
    ui.topic_listWidget->clear();
//    ui.topic_listWidget->addItem(QString("%1   (%2)").arg("Name","Type"));
    ui.topic_listWidget->addItem(QString("%1").arg("Name"));
    ui.topic_listWidget->setMinimumWidth(400);  //设置列宽

    QMap<QString,QString> topic_list= rostopic_list.get_topic_list();
    for(QMap<QString,QString>::iterator iter=topic_list.begin();iter!=topic_list.end();iter++)
    {
       ui.topic_listWidget->addItem(QString("%1").arg(iter.key())); //,iter.value()
    }
}
void MainWindow::initMap()
{
    ui.btn_loadmap->setDisabled(true);
    ui.label_11->setStyleSheet("color:rgb(204, 0, 0)");
    ui.label_11->setText("请连接master!");

    //map
    MapView = new QWebEngineView(this);
    QVBoxLayout* layout = new QVBoxLayout(ui.label_map);
    ui.label_map->setLayout(layout);
    layout->addWidget(MapView);

    initWeb();
    connect(ui.btn_loadmap,SIGNAL(clicked()),this,SLOT(on_btn_loadmap_clicked()));
    ui.btn_getSP->setVisible(false);
    ui.btn_getSP->setDisabled(true);

    ui.btn_getTP->setVisible(false);
    ui.btn_getTP->setDisabled(true);

    ui.btn_pitch->setVisible(false);
    ui.btn_pitch->setDisabled(true);

    ui.btn_plan->setVisible(false);
    ui.btn_plan->setDisabled(true);

    ui.btn_clear->setVisible(false);
    ui.btn_clear->setDisabled(true);

    ui.btn_draw->setVisible(false);
    ui.btn_draw->setDisabled(true);

    ui.btn_develop->setDisabled(false);
    ui.btn_project->setDisabled(false);

    ui.tabWidget_4->setVisible(false);
    ui.get_load_message->setDisabled(true);
    ui.btn_closemap->setDisabled(true);

    ui.btn_changeMode->setVisible(false);
    ui.btn_changeMode->setDisabled(true);
    ui.btn_project->setVisible(false);
    ui.btn_project->setDisabled(true);
    ui.btn_develop->setVisible(false);
    ui.btn_develop->setDisabled(true);

/**--------------自行测试时可注释此功能------------------------------**/
    //接收起点
    connect(ui.btn_getSP, &QPushButton::clicked, [&]()
    {
        qnode_GetStartPoint.init();
        ui.btn_getSP->setDisabled(true);
        ui.btn_pitch->setDisabled(true);
        ui.btn_getTP->setDisabled(false);
    });

//    //拾取终点
//    connect(ui.btn_getTP, &QPushButton::clicked, [&]()
//    {
//        QString pitch_tp = QString("pitchTP()");
//        MapView->page()->runJavaScript(pitch_tp);
//    });

    //拾取起点终点
    connect(ui.btn_pitch, &QPushButton::clicked, [&]()
    {
//        ui.btn_getSP->setDisabled(true);
//        ui.btn_getTP->setDisabled(true);
        ui.btn_pitch->setDisabled(true);
        btn_pitchFlag = 1;
        QString str_pitch = QString("pitch()");
        MapView->page()->runJavaScript(str_pitch);
    });

    //规划
    connect(ui.btn_plan, &QPushButton::clicked, [&]()
    {
//        ui.btn_plan->setDisabled(true);
        ui.get_load_message->setDisabled(false);
        QString str_plan = QString("plan()");
        MapView->page()->runJavaScript(str_plan);
    });

    //清除
    connect(ui.btn_clear, &QPushButton::clicked, [&]()
    {
//        ui.btn_getSP->setDisabled(false);
//        ui.btn_getTP->setDisabled(false);
        ui.get_load_message->setDisabled(true);
        ui.btn_pitch->setDisabled(false);
        btn_pitchFlag = 0;
        ui.btn_plan->setDisabled(false);
        QString str_clear = QString("clear()");
        MapView->page()->runJavaScript(str_clear);
    });

    //画线
    connect(ui.btn_clear, &QPushButton::clicked, [&]()
    {
        QString str_draw = QString("draw()");
        MapView->page()->runJavaScript(str_draw);
    });

    //获得轨迹点
    connect(ui.get_load_message, &QPushButton::clicked, [&]()
    {
        ui.get_load_message->setDisabled(true);
        QString str_getPoints = QString("get_points()");
        MapView->page()->runJavaScript(str_getPoints);
    });

    //清除信息
    connect(ui.btn_clear_path, &QPushButton::clicked, [&]()
    {
        if(btn_pitchFlag == 1){
            ui.get_load_message->setDisabled(false);
        }
        ui.Pace_text_display->clear();
        ui.Pace_Raw_text_display->clear();
        ui.ST_GPS_display->clear();
        ui.Key_Pace_Raw_text_display->clear();
        ui.Key_Pace_text_display->clear();
    });

    // 获取js返回值
//    connect(ui.get_load_message, &QPushButton::clicked, [&]()
//    {
//        auto str = getJsRetString();
//        ui.Pace_text_display->setText(str);
//    });
}


void MainWindow::initconections()
{
    //单目相机部分：
    connect(ui.btn_DiaplayRawImage, &QPushButton::pressed, this, [=]() {
          qnode_raw_image.init();
          ui.btn_DiaplayRawImage->setDisabled(true);
          QString str = "成功订阅单目原始图像并显示。";
          ui.info_textEdit->append("<font color=\"#00ff00\">" + str +
                                   "</font>");
      });

    connect(ui.btn_DisplayPCLImage, &QPushButton::pressed, this, [=]() {
          qnode_pcl_image.init();
          ui.btn_DisplayPCLImage->setDisabled(true);
          QString str = "成功订阅单目点云图像并显示。";
          ui.info_textEdit->append("<font color=\"#00ff00\">" + str +
                                   "</font>");
      });

    connect(ui.btn_DisplayFusionImage, &QPushButton::pressed, this, [=]() {
          qnode_fusion_image.init();
          ui.btn_DisplayFusionImage->setDisabled(true);
          QString str = "成功订阅单目融合图像并显示。";
          ui.info_textEdit->append("<font color=\"#00ff00\">" + str +
                                   "</font>");
      });

    //显示图像
//    connect(ui.btn_displaypoints, &QPushButton::pressed, this, [=]() {
//          qnode_points.init();
//          ui.btn_displaypoints->setDisabled(true);
//      });



    connect(ui.enable_mouse_pushButton, &QPushButton::pressed, this, [=]() {
        if (!ui.measure_checkBox->isEnabled()) {
          ui.measure_checkBox->setDisabled(false);
          ui.enable_mouse_pushButton->setText("Disable Mouse");

          QString str = "允许鼠标响应选点操作。";
          ui.info_textEdit->setText("<font color=\"#00ff00\">" + str +
                                    "</font>");
        } else {
          ui.measure_checkBox->setDisabled(true);
          ui.enable_mouse_pushButton->setText("Enable  Mouse");

          ui.measure_width_lineEdit->clear();
          ui.measure_height_lineEdit->clear();
          ui.measure_distance_lineEdit->clear();
          QString str = "禁用鼠标选点操作";
          ui.info_textEdit->append("<font color=\"#ff0000\">" + str +
                                   "</font>");  // green
        }
      });


    //信号更新主界面
    connect(&qnode_raw_image, SIGNAL(rosShutdown()), this, SLOT(close()));
    connect(&qnode_raw_image, &QNode::updateImage, this,&MainWindow::DisplayRawImage);

    connect(&qnode_pcl_image, SIGNAL(rosShutdown()), this, SLOT(close()));
    connect(&qnode_pcl_image, &QNode::updatePCLImage, this,&MainWindow::DisplayPCLImage);

    connect(&qnode_fusion_image, SIGNAL(rosShutdown()), this, SLOT(close()));
    connect(&qnode_fusion_image, &QNode::updateImage, this,&MainWindow::DisplayFusionImage);

    connect(&qnode_GetStartPoint, SIGNAL(rosShutdown()), this, SLOT(close()));
    connect(&qnode_GetStartPoint, &QNode::update_StartPoint, this,&MainWindow::GetStartPoint);

    connect(&qnode_points, SIGNAL(rosShutdown()), this, SLOT(close()));
    connect(&qnode_points, &QNode::updatepoints, this,&MainWindow::DisplayPoints);
    //超声波
    connect(&qnode_sonar, SIGNAL(rosShutdown()), this, SLOT(close()));
    connect(&qnode_sonar, &QNode::updateSonar1Distance, this,&MainWindow::DisplaySonar1Distance);
    connect(&qnode_sonar, &QNode::updateSonar2Distance, this,&MainWindow::DisplaySonar2Distance);
    connect(&qnode_sonar, &QNode::updateSonarError, this,&MainWindow::DisplaySonarError);

    connect(&qnode_obstacle, SIGNAL(rosShutdown()), this, SLOT(close()));
    connect(&qnode_obstacle, &QNode::updateObstacleState, this,&MainWindow::DisplayObs);

    ui.label_PCLImage->installEventFilter(this);

    //超声波按钮连接：
    connect(ui.btn_sonar_startmeasure, &QPushButton::pressed, this, [=]() {
          qnode_sonar.init();
          ui.btn_sonar_startmeasure->setDisabled(true);
          QString str = "成功订阅超声波数据并显示";
          ui.textEdit_tip->setText("<font color=\"#00ff00\">" + str +
                                   "</font>");
      });
    connect(ui.btn_sonar_stopmeasure, &QPushButton::pressed, this, [=]() {
          ui.btn_sonar_stopmeasure->setDisabled(true);
          ui.btn_sonar_startmeasure->setDisabled(false);
          ui.lineEdit_sonar1->setText(" ");
//          ui.lineEdit_sonar2->setText(" ");
          QString str = "成功关闭超声波数据";
          ui.textEdit_tip->setText("<font color=\"#00ff00\">" + str +
                                   "</font>");
      });

    //获取GPS
    connect(PTR_, &QNode::updateGetgps, this,&MainWindow::DisplayGetgps);

}
void MainWindow::initRviz()
{
    //rviz里信号与槽
    //set start pose
//    connect(ui.set_start_btn,SIGNAL(clicked()),this,SLOT(slot_set_start_pose()));
//    connect(ui.set_goal_btn,SIGNAL(clicked()),this,SLOT(slot_set_goal_pose()));

    //header
    ui.treeWidget->setHeaderLabels(QStringList()<<"key"<<"value");
    ui.treeWidget->setHeaderHidden(true);

///*** GLobal Options ***///
  //
    QTreeWidgetItem* Global=new QTreeWidgetItem(QStringList()<<"Global Options");
    Global->setIcon(0,QIcon("://images/options.png"));
    ui.treeWidget->addTopLevelItem(Global);
    Global->setExpanded(true);   //设置完父级对象后再设置展开
  // 添加 Fixed_frame 控件
    QTreeWidgetItem* Fixed_frame=new QTreeWidgetItem(QStringList()<<"Fixed Frame");
    fixed_box=new QComboBox();
    fixed_box->addItem("map");
    fixed_box->setMinimumWidth(150);
    fixed_box->setEditable(true);
    connect(fixed_box,SIGNAL(currentTextChanged(QString)),this,SLOT(slot_treewidget_value_change(QString)));

    Global->addChild(Fixed_frame);
    ui.treeWidget->setItemWidget(Fixed_frame,1,fixed_box);  //添加至01页

///*** Grid ***///

    QTreeWidgetItem* Grid=new QTreeWidgetItem(QStringList()<<"Grid");
    Grid->setIcon(0,QIcon(":/images/grid.png"));
    QCheckBox* Grid_Check=new QCheckBox();
    /*stateChanged选中了值为2，未选中值为1*/
    connect(Grid_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_grid(int)));
    //添加top节点
    ui.treeWidget->addTopLevelItem(Grid);
    //添加checkbox
    ui.treeWidget->setItemWidget(Grid,1,Grid_Check);
    //设置grid默认展开状态
    Grid->setExpanded(false);

    QTreeWidgetItem* Cell_Count=new QTreeWidgetItem(QStringList()<<"Plane Cell Count");
    Grid->addChild(Cell_Count);
    Cell_Count_Box=new QSpinBox();
    Cell_Count_Box->setValue(13);
    Cell_Count_Box->setMinimumWidth(150);
    ui.treeWidget->setItemWidget(Cell_Count,1,Cell_Count_Box);

    QTreeWidgetItem* Grid_Color=new QTreeWidgetItem(QStringList()<<"Color");
    Grid->addChild(Grid_Color);
    Grid_Color_Box=new QComboBox();
    Grid_Color_Box->addItem("160;160;160");
    Grid_Color_Box->setEditable(true);
    Grid_Color_Box->setMinimumWidth(150);
    ui.treeWidget->setItemWidget(Grid_Color,1,Grid_Color_Box);

///*** TF ***///
    QTreeWidgetItem* TF=new QTreeWidgetItem(QStringList()<<"TF");
    TF->setIcon(0,QIcon(":/images/classes/TF.png"));
    QCheckBox* TF_Check=new QCheckBox();
    connect(TF_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_tf(int)));
    ui.treeWidget->addTopLevelItem(TF);
    ui.treeWidget->setItemWidget(TF,1,TF_Check);

///*** LaserScan ***///
    QTreeWidgetItem* LaserScan=new QTreeWidgetItem(QStringList()<<"LaserScan");
    LaserScan->setIcon(0,QIcon(":/images/classes/LaserScan.png"));
    QCheckBox* Laser_Check=new QCheckBox();
    connect(Laser_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_laser(int)));
    ui.treeWidget->addTopLevelItem(LaserScan);
    ui.treeWidget->setItemWidget(LaserScan,1,Laser_Check);

    QTreeWidgetItem* LaserTopic=new QTreeWidgetItem(QStringList()<<"Topic");
    Laser_Topic_box=new QComboBox();
    Laser_Topic_box->addItem("/no_ground_filtered");
    Laser_Topic_box->setEditable(true);
    Laser_Topic_box->setMinimumWidth(150);
    LaserScan->addChild(LaserTopic);
    ui.treeWidget->setItemWidget(LaserTopic,1,Laser_Topic_box);
    LaserScan->setExpanded(true);

///*** PointCloud ***///
    QTreeWidgetItem* PCL=new QTreeWidgetItem(QStringList()<<"PointCloud");
    PCL->setIcon(0,QIcon(":/images/classes/PointCloud.png"));
    QCheckBox* PCL_Check=new QCheckBox();
    connect(PCL_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_PCL(int)));
    ui.treeWidget->addTopLevelItem(PCL);
    ui.treeWidget->setItemWidget(PCL,1,PCL_Check);

    //PointCloud2Topic topic
    QTreeWidgetItem* PointCloudTopic=new QTreeWidgetItem(QStringList()<<"Topic");
    PointCloud_Topic_box=new QComboBox();
    PointCloud_Topic_box->addItem("/lio_sam/deskew/cloud_deskewed");
    PointCloud_Topic_box->setEditable(true);
    PointCloud_Topic_box->setMinimumWidth(150);
    PCL->addChild(PointCloudTopic);

    //Style
    QTreeWidgetItem* PCLStyle=new QTreeWidgetItem(QStringList()<<"Style");
    PointCloud_Style_box=new QComboBox();
    PointCloud_Style_box->addItem("Points");
    PointCloud_Style_box->addItem("Squares");
    PointCloud_Style_box->addItem("Flat Squares");
    PointCloud_Style_box->addItem("Spheres");
    PointCloud_Style_box->addItem("Boxes");
    PointCloud_Style_box->setEditable(true);
    PointCloud_Style_box->setMinimumWidth(150);
    PCL->addChild(PCLStyle);

    QTreeWidgetItem* PCLColorTransformer=new QTreeWidgetItem(QStringList()<<"Color Transformer");
    PointCloud_ColorTransformer_box=new QComboBox();
    PointCloud_ColorTransformer_box->addItem("Intensity");
    PointCloud_ColorTransformer_box->addItem("AxisColor");
    PointCloud_ColorTransformer_box->addItem("FlatColor");
    PointCloud_ColorTransformer_box->setEditable(true);
    PointCloud_ColorTransformer_box->setMaximumWidth(150);
    PCL->addChild(PCLColorTransformer);

    QTreeWidgetItem* PCLChannelName=new QTreeWidgetItem(QStringList()<<"Channel Name");
    PointCloud_ChannelName_box=new QComboBox();
    PointCloud_ChannelName_box->addItem("Intensity");
    PointCloud_ChannelName_box->addItem("x");
    PointCloud_ChannelName_box->addItem("y");
    PointCloud_ChannelName_box->addItem("z");
    PointCloud_ChannelName_box->setEditable(true);
    PointCloud_ChannelName_box->setMinimumWidth(150);
    PCL->addChild(PCLChannelName);

    ui.treeWidget->setItemWidget(PointCloudTopic,1,PointCloud_Topic_box);
    ui.treeWidget->setItemWidget(PCLStyle,1,PointCloud_Style_box);
    ui.treeWidget->setItemWidget(PCLColorTransformer,1,PointCloud_ColorTransformer_box);
    ui.treeWidget->setItemWidget(PCLChannelName,1,PointCloud_ChannelName_box);
    PCL->setExpanded(false);


///*** PointCloud2 ***///
    QTreeWidgetItem* PCL2=new QTreeWidgetItem(QStringList()<<"PointCloud2");
    PCL2->setIcon(0,QIcon(":/images/classes/PointCloud2.png"));
    QCheckBox* PCL2_Check=new QCheckBox();
    connect(PCL2_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_PCL2(int)));
    ui.treeWidget->addTopLevelItem(PCL2);
    ui.treeWidget->setItemWidget(PCL2,1,PCL2_Check);

    //PointCloud2Topic topic
    QTreeWidgetItem* PointCloud2Topic=new QTreeWidgetItem(QStringList()<<"Topic");
    PointCloud2_Topic_box=new QComboBox();
    PointCloud2_Topic_box->addItem("velodyne_points");
    PointCloud2_Topic_box->setEditable(true);
    PointCloud2_Topic_box->setMinimumWidth(150);
    PCL2->addChild(PointCloud2Topic);

    //Style
    QTreeWidgetItem* PCL2Style=new QTreeWidgetItem(QStringList()<<"Style");
    PointCloud2_Style_box=new QComboBox();
    PointCloud2_Style_box->addItem("Flat Squares");
    PointCloud2_Style_box->addItem("Points");
    PointCloud2_Style_box->addItem("Squares");
    PointCloud2_Style_box->addItem("Spheres");
    PointCloud2_Style_box->addItem("Boxes");
    PointCloud2_Style_box->setEditable(true);
    PointCloud2_Style_box->setMinimumWidth(150);
    PCL2->addChild(PCL2Style);

    QTreeWidgetItem* PCL2ColorTransformer=new QTreeWidgetItem(QStringList()<<"Color Transformer");
    PointCloud2_ColorTransformer_box=new QComboBox();
    PointCloud2_ColorTransformer_box->addItem("Intensity");
    PointCloud2_ColorTransformer_box->addItem("AxisColor");
    PointCloud2_ColorTransformer_box->addItem("FlatColor");
    PointCloud2_ColorTransformer_box->setEditable(true);
    PointCloud2_ColorTransformer_box->setMinimumWidth(150);
    PCL2->addChild(PCL2ColorTransformer);

    ui.treeWidget->setItemWidget(PointCloud2Topic,1,PointCloud2_Topic_box);
    ui.treeWidget->setItemWidget(PCL2Style,1,PointCloud2_Style_box);
    ui.treeWidget->setItemWidget(PCL2ColorTransformer,1,PointCloud2_ColorTransformer_box);
    PCL2->setExpanded(false);

///*** PointCloud2_2 ***///
        QTreeWidgetItem* PCL2_2=new QTreeWidgetItem(QStringList()<<"PointCloud2_2");
        PCL2_2->setIcon(0,QIcon(":/images/classes/PointCloud2.png"));
        QCheckBox* PCL2_2_Check=new QCheckBox();
        connect(PCL2_2_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_PCL2_2(int)));
        ui.treeWidget->addTopLevelItem(PCL2_2);
        ui.treeWidget->setItemWidget(PCL2_2,1,PCL2_2_Check);

        //PointCloud2Topic topic
        QTreeWidgetItem* PointCloud2Topic_2=new QTreeWidgetItem(QStringList()<<"Topic");
        PointCloud2_2_Topic_box=new QComboBox();
        PointCloud2_2_Topic_box->addItem("velodyne_points");
        PointCloud2_2_Topic_box->setEditable(true);
        PointCloud2_2_Topic_box->setMinimumWidth(150);
        PCL2_2->addChild(PointCloud2Topic_2);

        //Style
        QTreeWidgetItem* PCL2Style_2=new QTreeWidgetItem(QStringList()<<"Style");
        PointCloud2_2_Style_box=new QComboBox();
        PointCloud2_2_Style_box->addItem("Flat Squares");
        PointCloud2_2_Style_box->addItem("Points");
        PointCloud2_2_Style_box->addItem("Squares");
        PointCloud2_2_Style_box->addItem("Spheres");
        PointCloud2_2_Style_box->addItem("Boxes");
        PointCloud2_2_Style_box->setEditable(true);
        PointCloud2_2_Style_box->setMinimumWidth(150);
        PCL2_2->addChild(PCL2Style_2);

        QTreeWidgetItem* PCL2ColorTransformer_2=new QTreeWidgetItem(QStringList()<<"Color Transformer");
        PointCloud2_2_ColorTransformer_box=new QComboBox();
        PointCloud2_2_ColorTransformer_box->addItem("Intensity");
        PointCloud2_2_ColorTransformer_box->addItem("AxisColor");
        PointCloud2_2_ColorTransformer_box->addItem("FlatColor");
        PointCloud2_2_ColorTransformer_box->setEditable(true);
        PointCloud2_2_ColorTransformer_box->setMinimumWidth(150);
        PCL2_2->addChild(PCL2ColorTransformer_2);

        ui.treeWidget->setItemWidget(PointCloud2Topic_2,1,PointCloud2_2_Topic_box);
        ui.treeWidget->setItemWidget(PCL2Style_2,1,PointCloud2_2_Style_box);
        ui.treeWidget->setItemWidget(PCL2ColorTransformer_2,1,PointCloud2_2_ColorTransformer_box);
        PCL2_2->setExpanded(false);

///*** map ***///
    QTreeWidgetItem* Map=new QTreeWidgetItem(QStringList()<<"Map");
    Map->setIcon(0,QIcon("://images/classes/Map.png"));
    QCheckBox* Map_Check=new QCheckBox();
    connect(Map_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_Map(int)));
    ui.treeWidget->addTopLevelItem(Map);
    ui.treeWidget->setItemWidget(Map,1,Map_Check);

    QTreeWidgetItem* MapTopic=new QTreeWidgetItem(QStringList()<<"Topic");
    Map_Topic_box=new QComboBox();
    Map_Topic_box->addItem("/map");
    Map_Topic_box->setEditable(true);
    Map_Topic_box->setMinimumWidth(150);
    Map->addChild(MapTopic);
    ui.treeWidget->setItemWidget(MapTopic,1,Map_Topic_box);

    QTreeWidgetItem* MapColorScheme=new QTreeWidgetItem(QStringList()<<"Color Scheme");
    Map_Color_Scheme_box=new QComboBox();
    Map_Color_Scheme_box->addItem("map");
    Map_Color_Scheme_box->addItem("costmap");
    Map_Color_Scheme_box->addItem("raw");
    Map_Color_Scheme_box->setMinimumWidth(150);
    Map->addChild(MapColorScheme);
    ui.treeWidget->setItemWidget(MapColorScheme,1,Map_Color_Scheme_box);

///*** Path ui ***///
    QTreeWidgetItem* Path=new QTreeWidgetItem(QStringList()<<"Path");
    Path->setIcon(0,QIcon(":/images/classes/Path.png"));
    QCheckBox* Path_Check=new QCheckBox();
    connect(Path_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_Path(int)));
    ui.treeWidget->addTopLevelItem(Path);
    ui.treeWidget->setItemWidget(Path,1,Path_Check);
    QTreeWidgetItem* PathTopic=new QTreeWidgetItem(QStringList()<<"Topic");
    Path_Topic_box=new QComboBox();
    Path_Topic_box->addItem("/move_base/DWAPlannerROS/local_plan");
    Path_Topic_box->setEditable(true);
    Path_Topic_box->setMinimumWidth(150);
    Path->addChild(PathTopic);
    ui.treeWidget->setItemWidget(PathTopic,1,Path_Topic_box);

    QTreeWidgetItem* PathColorScheme=new QTreeWidgetItem(QStringList()<<"Color");
    Path_Color_box=new QComboBox();
    Path_Color_box->addItem("0;12;255");
    Path_Color_box->setEditable(true);
    Path_Color_box->setMinimumWidth(150);
    Path->addChild(PathColorScheme);
    ui.treeWidget->setItemWidget(PathColorScheme,1,Path_Color_box);
}

void MainWindow::initRviz_obstacles()
{
    //header
    ui.treeWidget_obstacles->setHeaderLabels(QStringList()<<"key"<<"value");
    ui.treeWidget_obstacles->setHeaderHidden(true);


///*** GLobal Options ***///
  //
    QTreeWidgetItem* Global=new QTreeWidgetItem(QStringList()<<"Global Options");
    Global->setIcon(0,QIcon("://images/options.png"));
    ui.treeWidget_obstacles->addTopLevelItem(Global);
    Global->setExpanded(true);   //设置完父级对象后再设置展开
  // 添加 Fixed_frame 控件
    QTreeWidgetItem* Fixed_frame=new QTreeWidgetItem(QStringList()<<"Fixed Frame");
    fixed_box_obs=new QComboBox();
    fixed_box_obs->addItem("map");
    fixed_box_obs->addItem("rslidar");
    fixed_box_obs->addItem("velodyne");
    fixed_box_obs->setMaximumWidth(150);
    fixed_box_obs->setEditable(true);
    connect(fixed_box_obs,SIGNAL(currentTextChanged(QString)),this,SLOT(slot_treewidget_value_change_obs(QString)));

    Global->addChild(Fixed_frame);
    ui.treeWidget_obstacles->setItemWidget(Fixed_frame,1,fixed_box_obs);  //添加至01页


///*** Grid ***///

    QTreeWidgetItem* Grid=new QTreeWidgetItem(QStringList()<<"Grid");
    Grid->setIcon(0,QIcon(":/images/grid.png"));
    QCheckBox* Grid_Check=new QCheckBox();
    /*stateChanged选中了值为2，未选中值为1*/
    connect(Grid_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_grid_obs(int)));
    //添加top节点
    ui.treeWidget_obstacles->addTopLevelItem(Grid);
    //添加checkbox
    ui.treeWidget_obstacles->setItemWidget(Grid,1,Grid_Check);
    //设置grid默认展开状态
    Grid->setExpanded(false);

    QTreeWidgetItem* Cell_Count=new QTreeWidgetItem(QStringList()<<"Plane Cell Count");
    Grid->addChild(Cell_Count);
    Cell_Count_Box_obs=new QSpinBox();
    Cell_Count_Box_obs->setValue(13);
    Cell_Count_Box_obs->setMaximumWidth(150);
    ui.treeWidget_obstacles->setItemWidget(Cell_Count,1,Cell_Count_Box_obs);

    QTreeWidgetItem* Grid_Color=new QTreeWidgetItem(QStringList()<<"Color");
    Grid->addChild(Grid_Color);
    Grid_Color_Box_obs=new QComboBox();
    Grid_Color_Box_obs->addItem("160;160;160");
    Grid_Color_Box_obs->setEditable(true);
    Grid_Color_Box_obs->setMaximumWidth(150);
    ui.treeWidget_obstacles->setItemWidget(Grid_Color,1,Grid_Color_Box_obs);

///*** Axes ***///
    QTreeWidgetItem* Axes=new QTreeWidgetItem(QStringList()<<"Axes");
    Grid->setIcon(0,QIcon(":/images/classes/Axes.png"));
    QCheckBox* Axes_Check=new QCheckBox();
    /*stateChanged选中了值为2，未选中值为1*/
    connect(Axes_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_Axes_obs(int)));
    //添加top节点
    ui.treeWidget_obstacles->addTopLevelItem(Axes);
    //添加checkbox
    ui.treeWidget_obstacles->setItemWidget(Axes,1,Axes_Check);
    //设置grid默认展开状态
    Axes->setExpanded(false);

    //Axes_ReferenceFrame
    QTreeWidgetItem* Axes_ReferenceFrame=new QTreeWidgetItem(QStringList()<<"Reference Frame");
    Axes_ReferenceFrame_box_obs=new QComboBox();
    Axes_ReferenceFrame_box_obs->addItem("base_footprint");
    Axes_ReferenceFrame_box_obs->addItem("base_link");
    Axes_ReferenceFrame_box_obs->addItem("odom");
    Axes_ReferenceFrame_box_obs->setEditable(true);
    Axes_ReferenceFrame_box_obs->setMaximumWidth(150);
    Axes->addChild(Axes_ReferenceFrame);
    ui.treeWidget_obstacles->setItemWidget(Axes_ReferenceFrame,1,Axes_ReferenceFrame_box_obs);

///*** PointCloud2 ***///
    QTreeWidgetItem* PCL2=new QTreeWidgetItem(QStringList()<<"PointCloud2");
    PCL2->setIcon(0,QIcon(":/images/classes/PointCloud2.png"));
    QCheckBox* PCL2_Check=new QCheckBox();
    connect(PCL2_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_PCL2_obs(int)));
    ui.treeWidget_obstacles->addTopLevelItem(PCL2);
    ui.treeWidget_obstacles->setItemWidget(PCL2,1,PCL2_Check);

    //PointCloud2Topic topic
    QTreeWidgetItem* PointCloud2Topic=new QTreeWidgetItem(QStringList()<<"Topic");
    PointCloud2_Topic_box_obs=new QComboBox();
    PointCloud2_Topic_box_obs->addItem("rslidar_points");
    PointCloud2_Topic_box_obs->setEditable(true);
    PointCloud2_Topic_box_obs->setMaximumWidth(150);
    PCL2->addChild(PointCloud2Topic);

    //Style
    QTreeWidgetItem* PCL2Style=new QTreeWidgetItem(QStringList()<<"Style");
    PointCloud2_Style_box_obs=new QComboBox();
    PointCloud2_Style_box_obs->addItem("Flat Squares");
    PointCloud2_Style_box_obs->addItem("Points");
    PointCloud2_Style_box_obs->addItem("Squares");
    PointCloud2_Style_box_obs->addItem("Spheres");
    PointCloud2_Style_box_obs->addItem("Boxes");
    PointCloud2_Style_box_obs->setEditable(true);
    PointCloud2_Style_box_obs->setMaximumWidth(150);
    PCL2->addChild(PCL2Style);

    QTreeWidgetItem* PCL2ColorTransformer=new QTreeWidgetItem(QStringList()<<"Color Transformer");
    PointCloud2_ColorTransformer_box_obs=new QComboBox();
    PointCloud2_ColorTransformer_box_obs->addItem("FlatColor");
    PointCloud2_ColorTransformer_box_obs->addItem("Intensity");
    PointCloud2_ColorTransformer_box_obs->addItem("AxisColor");

    PointCloud2_ColorTransformer_box_obs->setEditable(true);
    PointCloud2_ColorTransformer_box_obs->setMaximumWidth(150);
    PCL2->addChild(PCL2ColorTransformer);

    ui.treeWidget_obstacles->setItemWidget(PointCloud2Topic,1,PointCloud2_Topic_box_obs);
    ui.treeWidget_obstacles->setItemWidget(PCL2Style,1,PointCloud2_Style_box_obs);
    ui.treeWidget_obstacles->setItemWidget(PCL2ColorTransformer,1,PointCloud2_ColorTransformer_box_obs);
    PCL2->setExpanded(true);

///*** PointCloud2_2 ***///
        QTreeWidgetItem* PCL2_2=new QTreeWidgetItem(QStringList()<<"PointCloud2_2");
        PCL2_2->setIcon(0,QIcon(":/images/classes/PointCloud2.png"));
        QCheckBox* PCL2_2_Check=new QCheckBox();
        connect(PCL2_2_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_PCL2_2_obs(int)));
        ui.treeWidget_obstacles->addTopLevelItem(PCL2_2);
        ui.treeWidget_obstacles->setItemWidget(PCL2_2,1,PCL2_2_Check);

        //PointCloud2Topic topic
        QTreeWidgetItem* PointCloud2Topic_2=new QTreeWidgetItem(QStringList()<<"Topic");
        PointCloud2_2_Topic_box_obs=new QComboBox();
        PointCloud2_2_Topic_box_obs->addItem("obstacle_cloud");
        PointCloud2_2_Topic_box_obs->setEditable(true);
        PointCloud2_2_Topic_box_obs->setMaximumWidth(150);
        PCL2_2->addChild(PointCloud2Topic_2);

        //Style
        QTreeWidgetItem* PCL2Style_2=new QTreeWidgetItem(QStringList()<<"Style");

        PointCloud2_2_Style_box_obs=new QComboBox();
        PointCloud2_2_Style_box_obs->addItem("Flat Squares");
        PointCloud2_2_Style_box_obs->addItem("Points");
        PointCloud2_2_Style_box_obs->addItem("Squares");
        PointCloud2_2_Style_box_obs->addItem("Spheres");
        PointCloud2_2_Style_box_obs->addItem("Boxes");
        PointCloud2_2_Style_box_obs->setEditable(true);
        PointCloud2_2_Style_box_obs->setMaximumWidth(150);
        PCL2_2->addChild(PCL2Style_2);

        QTreeWidgetItem* PCL2ColorTransformer_2=new QTreeWidgetItem(QStringList()<<"Color Transformer");
        PointCloud2_2_ColorTransformer_box_obs=new QComboBox();
        PointCloud2_2_ColorTransformer_box_obs->addItem("AxisColor");
        PointCloud2_2_ColorTransformer_box_obs->addItem("Intensity");
        PointCloud2_2_ColorTransformer_box_obs->addItem("FlatColor");
        PointCloud2_2_ColorTransformer_box_obs->setEditable(true);
        PointCloud2_2_ColorTransformer_box_obs->setMaximumWidth(150);
        PCL2_2->addChild(PCL2ColorTransformer_2);

        ui.treeWidget_obstacles->setItemWidget(PointCloud2Topic_2,1,PointCloud2_2_Topic_box_obs);
        ui.treeWidget_obstacles->setItemWidget(PCL2Style_2,1,PointCloud2_2_Style_box_obs);
        ui.treeWidget_obstacles->setItemWidget(PCL2ColorTransformer_2,1,PointCloud2_2_ColorTransformer_box_obs);
        PCL2_2->setExpanded(true);



///*** Path_small ui ***///
    QTreeWidgetItem* Path_small=new QTreeWidgetItem(QStringList()<<"Path");
    Path_small->setIcon(0,QIcon(":/images/classes/Path.png"));
    QCheckBox* Path_Check_small=new QCheckBox();
    connect(Path_Check_small,SIGNAL(stateChanged(int)),this,SLOT(slot_display_Path_small(int)));
    ui.treeWidget_obstacles->addTopLevelItem(Path_small);
    ui.treeWidget_obstacles->setItemWidget(Path_small,1,Path_Check_small);
    QTreeWidgetItem* PathTopic_small=new QTreeWidgetItem(QStringList()<<"Topic");
    Path_Topic_box_small=new QComboBox();
    Path_Topic_box_small->addItem("/trajectory1");
    Path_Topic_box_small->setEditable(true);
    Path_Topic_box_small->setMinimumWidth(150);
    Path_small->addChild(PathTopic_small);
    ui.treeWidget_obstacles->setItemWidget(PathTopic_small,1,Path_Topic_box_small);

    QTreeWidgetItem* PathColorScheme_small=new QTreeWidgetItem(QStringList()<<"Color");
    Path_Color_box_small=new QComboBox();
    Path_Color_box_small->addItem("25;255;0");
    Path_Color_box_small->setEditable(true);
    Path_Color_box_small->setMinimumWidth(150);
    Path_small->addChild(PathColorScheme_small);
    ui.treeWidget_obstacles->setItemWidget(PathColorScheme_small,1,Path_Color_box_small);

///*** Path_big ui ***///
    QTreeWidgetItem* Path_big=new QTreeWidgetItem(QStringList()<<"Path");
    Path_big->setIcon(0,QIcon(":/images/classes/Path.png"));
    QCheckBox* Path_Check_big=new QCheckBox();
    connect(Path_Check_big,SIGNAL(stateChanged(int)),this,SLOT(slot_display_Path_big(int)));
    ui.treeWidget_obstacles->addTopLevelItem(Path_big);
    ui.treeWidget_obstacles->setItemWidget(Path_big,1,Path_Check_big);
    QTreeWidgetItem* PathTopic_big=new QTreeWidgetItem(QStringList()<<"Topic");
    Path_Topic_box_big=new QComboBox();
    Path_Topic_box_big->addItem("/trajectory2");
    Path_Topic_box_big->setEditable(true);
    Path_Topic_box_big->setMinimumWidth(150);
    Path_big->addChild(PathTopic_big);
    ui.treeWidget_obstacles->setItemWidget(PathTopic_big,1,Path_Topic_box_big);

    QTreeWidgetItem* PathColorScheme_big=new QTreeWidgetItem(QStringList()<<"Color");
    Path_Color_box_big=new QComboBox();
    Path_Color_box_big->addItem("239;41;41");
    Path_Color_box_big->setEditable(true);
    Path_Color_box_big->setMinimumWidth(150);
    Path_big->addChild(PathColorScheme_big);
    ui.treeWidget_obstacles->setItemWidget(PathColorScheme_big,1,Path_Color_box_big);
}




/** @fn     WebTest::initUi
 *  @brief  界面初始化
 *  @return void
 */
void MainWindow::initWeb()
{
    m_pWebChannel = new QWebChannel(this);
    m_GetSPWebChannel = new QWebChannel(this);
    // 注册一个qtui对象  html端通过此名称向qt发送消息
    m_pWebChannel->registerObject(QString("qtui"), this);
    m_GetSPWebChannel->registerObject(QString("qGetPoints"), this);
    MapView->page()->setWebChannel(m_pWebChannel);
    MapView->page()->setWebChannel(m_GetSPWebChannel);
}

void MainWindow::slot_rosShutdown()
{
    ui.label_robot_staue_img->setPixmap(QPixmap::fromImage(QImage(":/images/offline.png")));
    ui.label_statue_text->setStyleSheet("color:red;");
    ui.label_statue_text->setText("离线");
    ui.button_connect->setEnabled(true);
    ui.line_edit_master->setReadOnly(false);
    ui.line_edit_host->setReadOnly(false);
    ui.line_edit_topic->setReadOnly(false);
}
/*****************************************************************************
** cmd执行终端操作
*****************************************************************************/
void MainWindow::slot_Qudong_start()
{
    Qudong_cmd=new QProcess;
    Qudong_cmd->start("bash");
    Qudong_cmd->write(ui.textEdit_qudong_cmd->toPlainText().toLocal8Bit()+"\n");
    connect(Qudong_cmd,SIGNAL(readyReadStandardError()),this,SLOT(slot_Qudong_output()));
    connect(Qudong_cmd,SIGNAL(readyReadStandardOutput()),this,SLOT(slot_Qudong_output()));
}
void MainWindow::slot_Qudong_output()
{
    ui.textEdit_QudongDisplay->append("<font color=\"#FF0000\">"+Qudong_cmd->readAllStandardError()+"</font>");
    ui.textEdit_QudongDisplay->append("<font color=\"#FFFFFF\">"+Qudong_cmd->readAllStandardOutput()+"</font>");
}

void MainWindow::slot_location_start()
{
    Location_cmd=new QProcess;
    Location_cmd->start("bash");
    Location_cmd->write(ui.textEdit_location_cmd->toPlainText().toLocal8Bit()+"\n");
    connect(Location_cmd,SIGNAL(readyReadStandardError()),this,SLOT(slot_location_output()));
    connect(Location_cmd,SIGNAL(readyReadStandardOutput()),this,SLOT(slot_location_output()));

}

void MainWindow::slot_location_output()
{
    ui.textEdit_locationDisplay->append("<font color=\"#FF0000\">"+Location_cmd->readAllStandardError()+"</font>");
    ui.textEdit_locationDisplay->append("<font color=\"#FFFFFF\">"+Location_cmd->readAllStandardOutput()+"</font>");
}

void MainWindow::slot_movebase_start()
{
    Movebase_cmd=new QProcess;
    Movebase_cmd->start("bash");
    Movebase_cmd->write(ui.textEdit_Movebase_cmd->toPlainText().toLocal8Bit()+"\n");
    connect(Movebase_cmd,SIGNAL(readyReadStandardError()),this,SLOT(slot_movebase_output()));
    connect(Movebase_cmd,SIGNAL(readyReadStandardOutput()),this,SLOT(slot_movebase_output()));

}
void MainWindow::slot_movebase_output()
{
    ui.textEdit_movebaseDisplay->append("<font color=\"#FF0000\">"+Movebase_cmd->readAllStandardError()+"</font>");
    ui.textEdit_movebaseDisplay->append("<font color=\"#FFFFFF\">"+Movebase_cmd->readAllStandardOutput()+"</font>");
}

void MainWindow::slot_goal_start()
{
   ui.btn_send_path->setDisabled(true);
   QString display_status = "轨迹信息下发至机器人，开始自主导航！";
   ui.Pace_rostopic_display->append("<font color=\"#00FF00\">"+display_status+"</font>");
}

void MainWindow::slot_goal_output()
{
    ui.btn_send_path->setDisabled(false);
    ui.Pace_rostopic_display->clear();
}

void MainWindow::slot_quick_cmd_clicked()
{
    laser_cmd=new QProcess;
    laser_cmd->start("bash");
    laser_cmd->write(ui.textEdit_laser_cmd->toPlainText().toLocal8Bit()+'\n');
    connect(laser_cmd,SIGNAL(readyReadStandardError()),this,SLOT(slot_quick_output()));
    connect(laser_cmd,SIGNAL(readyReadStandardOutput()),this,SLOT(slot_quick_output()));

}
void MainWindow::slot_quick_output()
{
    ui.textEdit_quick_output->append("<font color=\"#FF0000\">"+laser_cmd->readAllStandardError()+"</font>");
    ui.textEdit_quick_output->append("<font color=\"#FFFFFF\">"+laser_cmd->readAllStandardOutput()+"</font>");
}


void MainWindow::slot_roscore()
{
    cmd->start("bash");
    cmd->waitForStarted();
    cmd->write("cd\n");  //"\n"不可缺少
    cmd->write("rosrun turtlesim turtlesim_node\n");  //"\n"不可缺少
}
void MainWindow::on_readoutput()
{
//  ui.textEdit->append(cmd->readAllStandardOutput().data()); //将输出信息读取到编辑框
}

void MainWindow::DisplayPoints(QString data)
{
  ui.Pace_text_display->setText(data);

}

void MainWindow::slot_pushbtn_click()
{
  QPushButton* btn=qobject_cast<QPushButton*> (sender());  //进行类型转换，可以知道是哪一个按钮发送过来的
  qDebug()<<btn->text();
  char k=btn->text().toStdString()[0];
  bool is_all=ui.checkBox_is_all->isChecked();
  float linear=ui.label_linera->text().toFloat()*0.01;   //厘米
  float angular=ui.label_raw->text().toFloat()*0.01;

  switch (k) {
    case 'i':
      qnode_main.set_cmd_vel(is_all?'I':'i',linear,angular);  //is_all?'I':'i'如果被选中就是大写的I,没有选中就是小写的i
      break;
  case 'u':
    qnode_main.set_cmd_vel(is_all?'U':'u',linear,angular);
    break;
  case 'o':
    qnode_main.set_cmd_vel(is_all?'O':'o',linear,angular);
    break;
  case 'j':
    qnode_main.set_cmd_vel(is_all?'J':'j',linear,angular);
    break;
  case 'l':
    qnode_main.set_cmd_vel(is_all?'L':'l',linear,angular);
    break;
  case 'm':
    qnode_main.set_cmd_vel(is_all?'M':'m',linear,angular);
    break;
  case ',':
    qnode_main.set_cmd_vel(is_all?'<':',',linear,angular);
    break;
  case '.':
    qnode_main.set_cmd_vel(is_all?'>':'.',linear,angular);
    break;
  }
}

void MainWindow::slot_linera_value_change(int value)
{
    ui.label_linera->setText(QString::number(value));
}
void MainWindow::slot_raw_value_change(int value)
{
    ui.label_raw->setText(QString::number(value));
}

void MainWindow::slot_save_gps(){
    save_gps_flag = 1;
}
void MainWindow::slot_dispaly_gpsdata(){
    ui.textEdit_gps_data->clear();
    if(save_longitude.empty()||save_latitude.empty())
    {
        QString gpsData_null = "数据库为空，请存储好采样点后再试！";
        ui.textEdit_gps_data->append("<font color=\"#EE0000\">" + gpsData_null +
                           "</font>");
    }
    else{
      for (int i = 0; i < save_longitude.size(); ++i){
          QString gpsData = "数据库中第"+QString::number(i)+"个点的经纬度坐标为："+QString("%1").arg(save_longitude[i],0, 'f',7)+","+QString("%1").arg(save_latitude[i],0, 'f',7);
          ui.textEdit_gps_data->append("<font color=\"#4B0082\">" + gpsData +
                             "</font>");
          }
    }

}


MainWindow::~MainWindow() {
    if(Qudong_cmd){
//        Qudong_cmd->close();
        delete Qudong_cmd;
        Qudong_cmd = nullptr;
//        Qudong_cmd->waitForFinished();
    }
    if(Location_cmd){
        Location_cmd->close();
        delete Location_cmd;
        Location_cmd = nullptr;
//        Location_cmd->waitForFinished();
    }
    if(Movebase_cmd){
        Movebase_cmd->close();
        delete Movebase_cmd;
        Movebase_cmd = nullptr;
//        Movebase_cmd->waitForFinished();
    }
}

void MainWindow::GetStartPoint(QString longitude,QString latitude) {

//    QString jsStr= QString("getPC(%0,%1)").arg(longitude).arg(latitude);
//    MapView->page()->runJavaScript(jsStr);
}

/*****************************************************************************
** 单目图像
*****************************************************************************/
void MainWindow::DisplayRawImage(const QImage& image) {
  ui.label_RawImage->setPixmap(QPixmap::fromImage(image));
}
void MainWindow::DisplayPCLImage(const QImage& image) {
  ui.label_PCLImage->setPixmap(QPixmap::fromImage(image));
}
void MainWindow::DisplayFusionImage(const QImage& image) {
  ROS_ERROR("gengxinle  ------------------------");
  ui.label_FusioImage->setPixmap(QPixmap::fromImage(image));
}
/*****************************************************************************
** 超声波
*****************************************************************************/
void MainWindow::DisplaySonar1Distance(const QString& Dis1) {
//  ui.lineEdit_sonar1->setText(Dis1);
//  if(Dis1.toInt() <= 24){
//    ui.label_sonar_display->setPixmap(QPixmap(":/images/Green.png"));
//    sonar_tip = "探测距离为"+Dis1+"cm，正常路面，未发现凹坑！";
//    ui.textEdit_tip->setText("<font color=\"#00FF00\">" + sonar_tip + "</font>");
//    }
//  if(Dis1.toInt() >24 && Dis1.toInt() <200){

//    ui.label_sonar_display->setPixmap(QPixmap(":/images/Red.png"));
//    sonar_tip = "探测距离为"+Dis1+"cm，发现凹坑，发出黄色预警！";
//    ui.textEdit_tip->setText("<font color=\"#fff000\">" + sonar_tip + "</font>");
//  }
//  if(Dis1.toInt() > 200){

//    ui.label_sonar_display->setPixmap(QPixmap(":/images/Red.png"));
//    sonar_tip = "探测距离为"+Dis1+"cm，超过2m，请注意！";
//    ui.textEdit_tip->setText("<font color=\"#ff0000\">" + sonar_tip + "</font>");
//  }
}
void MainWindow::DisplaySonar2Distance(const QString& Dis2) {
  ui.lineEdit_sonar1->setText(Dis2);
  if(Dis2.toInt() <= 24){
    ui.label_sonar_display->setPixmap(QPixmap(":/images/Green.png"));
    sonar_tip = "探测距离为"+Dis2+"cm，正常路面，未发现凹坑！";
    ui.textEdit_tip->setText("<font color=\"#00FF00\">" + sonar_tip + "</font>");
    }
  if(Dis2.toInt() >24 && Dis2.toInt() <200){

    ui.label_sonar_display->setPixmap(QPixmap(":/images/Red.png"));
    sonar_tip = "探测距离为"+Dis2+"cm，发现凹坑，发出黄色预警！";
    ui.textEdit_tip->setText("<font color=\"#fff000\">" + sonar_tip + "</font>");
  }
  if(Dis2.toInt() > 200){

    ui.label_sonar_display->setPixmap(QPixmap(":/images/Red.png"));
    sonar_tip = "探测距离为"+Dis2+"cm，超过2m，请注意！";
    ui.textEdit_tip->setText("<font color=\"#ff0000\">" + sonar_tip + "</font>");
  }
}
void MainWindow::DisplaySonarError(const QString& Error) {
  ui.textEdit_tip->setText("<font color=\"#ff0000\">" + Error + "</font>");  // red
}
/*****************************************************************************
** 障碍物预警
*****************************************************************************/
void MainWindow::slot_start_tip(int state)
{
    bool enable=state>1?true:false;
    qnode_obstacle.init();
}

void MainWindow::DisplayObs(const QString& obstacle_range,const QString& obstacle_state) {
  ui.lineEdit->setText(obstacle_range);

  if(obstacle_state == "1"){
      qDebug()<<"obstacle_state == 1.0"<<endl;
      ui.label_obstacle_display->setPixmap(QPixmap(":/images/Red.png"));
      obstacle_tip = "前方20米内发现障碍物，发出红色预警！";
      ui.textEdit_obstacle->setText("<font color=\"#ff0000\">" + obstacle_tip + "</font>");
  }else if(obstacle_state == "0"){
      qDebug()<<"obstacle_state == 0.0"<<endl;
      ui.label_obstacle_display->setPixmap(QPixmap(":/images/Green.png"));
      obstacle_tip = "前方20米内未发现障碍物，正常同行！";
      ui.textEdit_obstacle->setText("<font color=\"#00FF00\">" + obstacle_tip + "</font>");

  }
}
/*****************************************************************************
** 采集GPS点信息
*****************************************************************************/
void MainWindow::DisplayGetgps(const QString& longitude,const QString& latitude){
    ui.get_longitude->setText(longitude);
    ui.get_latitude->setText(latitude);
    if(save_gps_flag){
        save_longitude.append(longitude.toDouble());
        save_latitude.append(latitude.toDouble());
        save_gps_flag = 0;
        QString time_str = "gps_data_";
        QDir *DataFile = new QDir;
        bool exist = DataFile->exists("DataFile");
        if(!exist)
        {
            bool isok = DataFile->mkdir("DataFile"); // 新建文件夹
            if(!isok)
            QMessageBox::warning(this,"sdf","can't mkdir",QMessageBox::Yes);
        }

        QString fileName = "DataFile/"+time_str+"datafile.txt";

        QString str = "this is testing for save data to txt file by Qt programming.";

        QFile file(fileName);

        if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))

        {

            QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);

        }

        QTextStream stream(&file);
        stream.setCodec("utf-8");
//        stream<<tr("手动采集的第")<<count_gps <<tr("个GPS经纬度信息为:")<<longitude<<","<<latitude<<"\n";
        stream <<longitude<<","<<latitude<<"\n";
        file.close();
        count_gps+=1;
    }
}
/*****************************************************************************
** 匹配目标GPS点，发送导航任务
*****************************************************************************/
void MainWindow::slot_chooseGoalGPS(){

    QVector<double> temp_vector;
    QVector<double> goal_longitude;
    QVector<double> goal_latitude;
    ui.textEdit->clear();
    QFile file("DataFile/gps_data_datafile.txt");
    if(! file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QString  error_log= "数据库文件读取失败！"+file.errorString();
        ui.Pace_rostopic_display->setText(error_log);
        return;
    }
    else
    {
        ui.Pace_rostopic_display->setText("数据库文件读取成功！");
        file.seek(0);  //重新定位在文件的第0位及开始位置
        QTextStream stream_gps(&file);
        while(! stream_gps.atEnd())
        {
          QString line=stream_gps.readLine();
          QStringList strlist=line.split(",");
          compare_longitude.append(strlist[0].toDouble());
          compare_latitude.append(strlist[1].toDouble());
        }
        file.close();
    }
    if(g_key_longitude.empty()||g_key_latitude.empty())
    {
        ui.Pace_rostopic_display->setText("数据库为空，请存储好采样点后再试！");
    }
    else{
      //开始匹配
      for (int i = 1; i < g_key_longitude.size(); ++i){
          QVector<double>().swap(temp_vector);  //每次使用前先清除元素并回收内存

          for (int j = 0; j < compare_longitude.size(); ++j){
             geoConverter.Reset(g_key_latitude[i], g_key_longitude[i], 0);
             geoConverter.Forward(compare_latitude[j], compare_longitude[j], 0, xyz[0], xyz[1], xyz[2]);

             double dis_=sqrt(xyz[0]*xyz[0]+xyz[1]*xyz[1]);
             qDebug()<< dis_;
//             distanceGPS(g_key_longitude[i],g_key_latitude[i],compare_longitude[j],compare_latitude[j])
             temp_vector.append(dis_);
             QString temp_vector_value = "第"+QString::number(i)+"个关键点到第"+QString::number(j)+"个点数据库中的点距离为："+QString("%1").arg(temp_vector[j],0, 'r');
             ui.textEdit->append("<font color=\"#4B0082\">" + temp_vector_value +
                                "</font>");
          }
          auto min = std::min_element(std::begin(temp_vector), std::end(temp_vector));
          QString gpsGoalData_ = "第"+QString::number(i)+"个点距离最近的点距离为："+QString("%1").arg(*min,0, 'r');
          ui.textEdit->append("<font color=\"#4B0082\">" + gpsGoalData_ +
                             "</font>");

          auto positionmin = std::distance(std::begin(temp_vector),min);
          goal_longitude.append(compare_longitude[positionmin]);
          goal_latitude.append(compare_latitude[positionmin]);
          }
      ui.Pace_rostopic_display->clear();
      for (int k = 0; k < goal_longitude.size(); ++k){
          QString gpsGoalData = "第"+QString::number(k)+"个点导航目标点的经纬度坐标为："+QString("%1").arg(goal_longitude[k],0, 'f',9)+","+QString("%1").arg(goal_latitude[k],0, 'f',10);
          ui.Pace_rostopic_display->append("<font color=\"#4B0082\">" + gpsGoalData +
                             "</font>");
      }

    }

}

void MainWindow::slot_testgpsdata()
{
    m_xyz[0] = 0;
    m_xyz[1] = 0;
    m_xyz[2] = 0;
    if(test_longitude.empty()||test_latitude.empty())
    {
        ui.textEdit_test->setText("要测试的数据为空，请存储好测试点后再试！");
    }
    else{
      //开始匹配
      for (int i = 0; i < test_longitude.size(); ++i){
//          qDebug()<<"test_flag:"<<test_flag;    每次一启动，就会以第一次的规划起点确定起点坐标系，后面再次规划都是相对于这里，只进来一次
          if(test_flag==1){
              test_geoConverter.Reset(compare_longitude[0], compare_latitude[0], 0);
              test_geoConverter.Forward(compare_longitude[0], compare_latitude[0], 0, m_xyz[0], m_xyz[1], m_xyz[2]);
              //用于匹配，计算实际偏差
              std::ofstream foutC_GPS("/home/czh/gaoDeGPS.csv", ios::app);
              foutC_GPS.setf(ios::fixed, ios::floatfield);
              foutC_GPS.precision(0);
              foutC_GPS << ros::Time::now().toSec()* 1e9 << ",";
              foutC_GPS.precision(5);
              foutC_GPS << m_xyz[0] << ","
                    << m_xyz[1] << ","
                    << 0 << ","
                    << 1 << ","
                    << 0 << ","
                    << 0 << ","
                    << 0 << ",0,0,0,0,0,0,0,0,0" << endl;
              foutC_GPS.close();
              test_flag = 2;
          }
          else
          {

              m_xyz[0] = 0;
              m_xyz[1] = 0;
              m_xyz[2] = 0;
              qDebug()<<"进来了:i是"<<i<<"经纬度是"<<test_latitude[i]<<","<<test_longitude[i];
              test_geoConverter.Forward(test_latitude[i], test_longitude[i], 0, m_xyz[0], m_xyz[1], m_xyz[2]);
              qDebug()<<"m_xyz[0]是："<<m_xyz[0]<<"m_xyz[1]是"<<m_xyz[1];
              //用于匹配，计算实际偏差
              std::ofstream foutC_GPS("/home/czh/gaoDeGPS.csv", ios::app);
              foutC_GPS.setf(ios::fixed, ios::floatfield);
              foutC_GPS.precision(0);
              foutC_GPS << ros::Time::now().toSec()* 1e9<< ",";
              foutC_GPS.precision(5);
              foutC_GPS << m_xyz[0] << ","
                    << m_xyz[1] << ","
                    << 0 << ","
                    << 1 << ","
                    << 0 << ","
                    << 0 << ","
                    << 0 << ",0,0,0,0,0,0,0,0,0" << endl;
              foutC_GPS.close();
          }


      }


    }

}
/*****************************************************************************
** 计算两GPS点之间距离，用于数据库距离匹配
*****************************************************************************/
double MainWindow::distanceGPS(const double& longitude1,const double& latitude1,const double& longitude2,const double& latitude2){
   const float EARTH_RADIUS = 6378137;
   const double PI = acos(-1);
   double a = latitude1 * PI / 180.0-latitude2 * PI / 180.0;
   double b = longitude1 * PI / 180.0-longitude2 * PI / 180.0;
   double sa2 = sin(a / 2.0);
   double sb2 = sin(b / 2.0);
   double distance = 2* EARTH_RADIUS* asin(sqrt(sa2 * sa2 + cos(sa2)
                           * cos(latitude2) * sb2 * sb2));
   return distance;  //单位为m
}
/*****************************************************************************
** mousePressEvent
*****************************************************************************/


void MainWindow::mousePressEvent(QMouseEvent* event)
{
//    QMessageBox::information(this, "提示", QString("点击了该Label"));
    point = event->globalPos();
    point = ui.label_FusioImage->mapFromGlobal(point);  //转至控件label的坐标相对位置
    if (ui.measure_checkBox->isChecked()) {
      if (p1.x == 0 && p1.y == 0) {
        QString str_1 = "请拾取第一个点！";
        ui.info_textEdit->append("<font color=\"0000FF\">" + str_1 +
                                 "</font>");
        p1 = SearchNearestPoint(qnode_pcl_image.mask,point.x(), point.y());
        // rp1.x = qnode_mask.mask.at<cv::Vec3f>(p1)[0];
        // rp1.y = qnode_mask.mask.at<cv::Vec3f>(p1)[1];
        // rp1.z = qnode_mask.mask.at<cv::Vec3f>(p1)[2];
        rp1 = qnode_pcl_image.mask.at<cv::Vec3f>(p1);

        // p1.x = point.x();
        // p1.y = point.y();

        // show on the linetext
        QString str_2 = "第一个点信息---   x为："+QString("%1").arg(p1.x)+"y为："+QString("%1").arg(p1.y)+"3D坐标中：x为："
                +QString("%1").arg(rp1.x)+"y为："+QString("%1").arg(rp1.y)+"z为："+QString("%1").arg(rp1.z)
                ;
        ui.info_textEdit->append("<font color=\"#00ff00\">" + str_2 +
                                 "</font>");
      } else {
        QString str_1 = "请拾取第二个点！";
        ui.info_textEdit->append("<font color=\"0000FF\">" + str_1 +
                                 "</font>");
        p2 = SearchNearestPoint(qnode_pcl_image.mask, point.x(), point.y());
        rp2 = qnode_pcl_image.mask.at<cv::Vec3f>(p2);

        // p2.x = point.x();
        // p2.y = point.y();

        QString str_2 = "第二个点信息---   x为："+QString("%1").arg(p2.x)+"y为："+QString("%1").arg(p2.y)+"3D坐标中：x为："
                +QString("%1").arg(rp2.x)+"y为："+QString("%1").arg(rp2.y)+"z为："+QString("%1").arg(rp2.z)
                ;
        ui.info_textEdit->append("<font color=\"#00ff00\">" + str_2 +
                                 "</font>");
//        if (fabs(rp1.x - rp2.x) > 1) {
//          // qDebug() << "the two points in x direction is over 1m, check it !";
//          str_2 = "两点在x方向上的距离超过1m,检查选点精度!!!";
//          ui.info_textEdit->append("<font color=\"#ff0000\">" + str_2 +
//                                    "</font>");  // red
//        } else {
          float w = fabs(rp2.y - rp1.y);
          float h = fabs(rp2.z - rp1.z);
          float distance_point = sqrt(w*w + h*h);
          float distance = (rp1.x + rp2.x) / 2;

          QString str = QString("%1").arg(w);
          ui.measure_width_lineEdit->setText(str);
          str = QString("%1").arg(h);
          ui.measure_height_lineEdit->setText(str);
          str = QString("%1").arg(distance_point);
          ui.measure_distance_lineEdit->setText(str);
//        }
        update();

        // p1.x = p2.x = p1.y = p2.y = 0;
      }
    }
}

bool MainWindow::CheckZero(cv::Mat& img, int x, int y) {
  if (img.at<cv::Vec3f>(y, x)[0] == 0.0 && img.at<cv::Vec3f>(y, x)[1] == 0.0 &&
      img.at<cv::Vec3f>(y, x)[2] == 0)
    return true;
  return false;
}

bool MainWindow::CheckCord(cv::Mat& img, int x, int y) {
  if (x < 0 || x > img.cols || y < 0 || y > img.rows) return false;
  return true;
}

cv::Point2i MainWindow::SearchNearestPoint(cv::Mat& img, int x, int y) {
  cv::Point2i res(0, 0);
  for (int radius = 1; radius < 20; ++radius) {
    for (int i = x - radius; i <= x + radius; ++i) {
      if (i == x - radius || i == x + radius) {
        for (int j = y - radius; j < y + radius; ++j) {
          if (CheckCord(img, i, j)) {
            if (!CheckZero(img, i, j)) {
              res.x = i;
              res.y = j;

              return res;
            }
          }
        }
      } else {
        int j = y - radius;
        if (CheckCord(img, i, j)) {
          if (!CheckZero(img, i, j)) {
            res.x = i;
            res.y = j;

            return res;
          }
        }
        j = y + radius;
        if (CheckCord(img, i, j)) {
          if (!CheckZero(img, i, j)) {
            res.x = i;
            res.y = j;

            return res;
          }
        }
      }
    }
  }
  // qDebug() << "did not find point";
  QString str = "没有找到对应点!!!";
  ui.info_textEdit->setText("<font color=\"#ff0000\">" + str +
                            "</font>");  // red

  return res;
}



/*****************************************************************************
** RVIZ
*****************************************************************************/
void MainWindow::slot_treewidget_value_change(QString){
    myrviz->Set_FixedFrame(fixed_box->currentText());
}

void MainWindow::slot_display_grid(int state){
    bool enable = state>1?true:false;  //为2时就被选中了，1为不选中
    QStringList qli=Grid_Color_Box->currentText().split(";");  //颜色采用;分隔的三个color
    QColor color=QColor(qli[0].toInt(),qli[1].toInt(),qli[2].toInt());
    myrviz->Display_Grid(Cell_Count_Box->text().toInt(),color,enable);//将QString类型转换为int类型
}
void MainWindow::slot_display_tf(int state)
{
    bool enable=state>1?true:false;
    qDebug()<<"我进入了slot_display_tf里面";
    myrviz->Display_TF(enable);
}
void MainWindow::slot_display_laser(int state)
{
    bool enable=state>1?true:false;
    qDebug()<<"我进入了：slot_display_laser";
    myrviz->Display_LaserScan(Laser_Topic_box->currentText(),enable);
}
void MainWindow::slot_display_PCL(int state)
{
    bool enable=state>1?true:false;
    myrviz->Display_PCL(PointCloud_Topic_box->currentText(),PointCloud_Style_box->currentText(),PointCloud_ColorTransformer_box->currentText(),PointCloud_ChannelName_box->currentText(),enable);
}
void MainWindow::slot_display_PCL2(int state)
{
    bool enable=state>1?true:false;
    myrviz->Display_PCL2(PointCloud2_Topic_box->currentText(),PointCloud2_Style_box->currentText(),PointCloud2_ColorTransformer_box->currentText(),enable);
}
void MainWindow::slot_display_PCL2_2(int state)
{
    bool enable=state>1?true:false;
    myrviz->Display_PCL2_2(PointCloud2_2_Topic_box->currentText(),PointCloud2_2_Style_box->currentText(),PointCloud2_2_ColorTransformer_box->currentText(),enable);
}

void MainWindow::slot_display_Map(int state)
{
    bool enable=state>1?true:false;
    myrviz->Display_Map(Map_Topic_box->currentText(),Map_Color_Scheme_box->currentText(),enable);
}

void MainWindow::slot_display_Path(int state)
{
    bool enable=state>1?true:false;
    QStringList qli=Path_Color_box->currentText().split(";");
    QColor color=QColor(qli[0].toInt(),qli[1].toInt(),qli[2].toInt());  //格式化color
    myrviz->Display_Path(Path_Topic_box->currentText(),color,enable);   //接口函数
}
//void MainWindow::slot_set_start_pose()
//{
//    myrviz->Set_Start_Pose();
//}
//void MainWindow::slot_set_goal_pose()
//{
//    myrviz->Set_Goal_Pose();
//}



void MainWindow::slot_treewidget_value_change_obs(QString){
    myrviz_ObstaclesDisplay->Set_FixedFrame(fixed_box_obs->currentText());
}

void MainWindow::slot_display_grid_obs(int state){
    bool enable = state>1?true:false;  //为2时就被选中了，1为不选中
    QStringList qli=Grid_Color_Box->currentText().split(";");  //颜色采用;分隔的三个color
    QColor color=QColor(qli[0].toInt(),qli[1].toInt(),qli[2].toInt());
    myrviz_ObstaclesDisplay->Display_Grid(Cell_Count_Box_obs->text().toInt(),color,enable);//将QString类型转换为int类型
}
void MainWindow::slot_display_Axes_obs(int state){

    bool enable = state>1?true:false;  //为2时就被选中了，1为不选中
    myrviz_ObstaclesDisplay->Display_Axes(Axes_ReferenceFrame_box_obs->currentText(),enable);//将QString类型转换为int类型
}

void MainWindow::slot_display_PCL2_obs(int state)
{
    bool enable=state>1?true:false;
    myrviz_ObstaclesDisplay->Display_PCL2(PointCloud2_Topic_box_obs->currentText(),PointCloud2_Style_box_obs->currentText(),PointCloud2_ColorTransformer_box_obs->currentText(),enable);
}
void MainWindow::slot_display_PCL2_2_obs(int state)
{
    bool enable=state>1?true:false;
    myrviz_ObstaclesDisplay->Display_PCL2_2(PointCloud2_2_Topic_box_obs->currentText(),PointCloud2_2_Style_box_obs->currentText(),PointCloud2_2_ColorTransformer_box_obs->currentText(),enable);
}
void MainWindow::slot_interact()
{
    myrviz_ObstaclesDisplay->Set_Interact();

}
void MainWindow::slot_display_Path_small(int state)
{
    bool enable=state>1?true:false;
    QStringList qli=Path_Color_box_small->currentText().split(";");
    QColor color_small=QColor(qli[0].toInt(),qli[1].toInt(),qli[2].toInt());  //格式化color
    myrviz_ObstaclesDisplay->Display_Path(Path_Topic_box_small->currentText(),color_small,enable);   //接口函数
}
void MainWindow::slot_display_Path_big(int state)
{
    bool enable=state>1?true:false;
    QStringList qli=Path_Color_box_big->currentText().split(";");
    QColor color_big=QColor(qli[0].toInt(),qli[1].toInt(),qli[2].toInt());  //格式化color
    myrviz_ObstaclesDisplay->Display_Path(Path_Topic_box_big->currentText(),color_big,enable);   //接口函数
}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

/* 功能：连接master节点
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked()
{
    //如果使用环境变量
    if ( ui.checkbox_use_environment->isChecked() )
    {
        if ( !qnode_main.init() ) {
            //showNoMasterMessage();
            QMessageBox::warning(nullptr, "失败", "连接ROS Master失败！请检查你的网络或连接字符串！", QMessageBox::Yes, QMessageBox::Yes);
            ui.label_robot_staue_img->setPixmap(QPixmap::fromImage(QImage(":/images/offline.png")));
            ui.label_statue_text->setStyleSheet("color:red;");
            ui.label_statue_text->setText("离线");
            ui.tab_manager->setTabEnabled(1,false); //左边显示功能栏
            ui.tabWidget->setTabEnabled(1,false); //右边显示功能栏
            ui.treeWidget->setEnabled(false);  //因为其他地方需要获取rviz对象，如果没有连接上master,需要将其设置为不可用，防止被意外调用
            ui.groupBox_scout->setEnabled(false);
            return ;
        }
        else {
			ui.button_connect->setEnabled(false);
            ui.treeWidget->setEnabled(true);     //连接上了master
            myrviz =new qrviz(ui.Layout_rviz);   //初始化rviz，通过传如rviz的布局，进行联系
            myrviz_ObstaclesDisplay = new qrviz(ui.verticalLayout_rviz_obs);

            ui.btn_loadmap->setDisabled(false);
            ui.label_11->setStyleSheet("color:rgb(115, 210, 22)");
            ui.label_11->setText("请加载地图");
		}
    }
    //如果不使用环境变量
    else
    {
        if ( ! qnode_main.init(ui.line_edit_master->text().toStdString(),
				   ui.line_edit_host->text().toStdString()) ) {
			showNoMasterMessage();
            QMessageBox::warning(nullptr, "失败", "连接ROS Master失败！请检查你的网络或连接字符串！", QMessageBox::Yes, QMessageBox::Yes);
            ui.label_robot_staue_img->setPixmap(QPixmap::fromImage(QImage(":/images/offline.png")));
            ui.label_statue_text->setStyleSheet("color:red;");
            ui.label_statue_text->setText("离线");
            ui.tab_manager->setTabEnabled(1,false);
            ui.tabWidget->setTabEnabled(1,false);
            ui.groupBox->setEnabled(false);
            ui.groupBox_scout->setEnabled(false);
            return ;
        }
        else
        {
            ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
			ui.line_edit_topic->setReadOnly(true);
            ui.treeWidget->setEnabled(true);     //连接上了master
            myrviz =new qrviz(ui.Layout_rviz);   //初始化rviz，通过传入rviz的布局，进行联系
            myrviz_ObstaclesDisplay = new qrviz(ui.verticalLayout_rviz_obs);
		}
	}
    ui.tab_manager->setTabEnabled(1,true);
    ui.tabWidget->setTabEnabled(1,true);
    ui.groupBox_scout->setEnabled(true);
    ui.button_connect->setEnabled(false);
    ui.quit_button->setEnabled(true);
    ui.label_robot_staue_img->setPixmap(QPixmap::fromImage(QImage(":/images/online.png")));
    ui.label_statue_text->setStyleSheet("color:green;");
    ui.label_statue_text->setText("在线");
    //显示话题列表
    initTopicList();
    ui.btn_loadmap->setDisabled(false);
    ui.label_11->setStyleSheet("color:rgb(115, 210, 22)");
    ui.label_11->setText("请加载地图");
}


void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
	//ui.line_edit_topic->setEnabled(enabled);
}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
        ui.view_logging->scrollToBottom();
}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "robot_hmi");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    //ui.line_edit_topic->setText(topic_name);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }
}

void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "robot_hmi");
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}

double MainWindow::transformLat(double x,double y)
{
    double ret = -100.0 + 2.0 * x + 3.0 * y + 0.2 * y * y + 0.1 * x * y + 0.2 *sqrt(abs(x));
    ret += (20.0 * sin(6.0 * x * pi) + 20.0 * sin(2.0 * x * pi)) * 2.0 / 3.0;
    ret += (20.0 * sin(y * pi) + 40.0 * sin(y / 3.0 * pi)) * 2.0 / 3.0;
    ret += (160.0 * sin(y / 12.0 * pi) + 320 * sin(y * pi / 30.0)) * 2.0 / 3.0;
    return ret;
}

double MainWindow::transformLon(double x,double y)
{
    double ret = 300.0 + x + 2.0 * y + 0.1 * x * x + 0.1 * x * y + 0.1 * sqrt(abs(x));
    ret += (20.0 * sin(6.0 * x * pi) + 20.0 * sin(2.0 * x * pi)) * 2.0 / 3.0;
    ret += (20.0 * sin(x * pi) + 40.0 * sin(x / 3.0 * pi)) * 2.0 / 3.0;
    ret += (150.0 * sin(x / 12.0 * pi) + 300.0 * sin(x / 30.0 * pi)) * 2.0 / 3.0;
    return ret;
}

double *MainWindow::gcj02towgs84(double lng,double lat)
{
    static double save[2];
    double wglng,wglat;
    if (out_of_china(lng, lat)) {
        wglng = lng;
        wglat = lat;
        return 0;
    } else {
      double dlat = transformLat(lng - 105.0, lat - 35.0);
      double dlng = transformLon(lng - 105.0, lat - 35.0);
      double radlat = lat / 180.0 * pi;
      double magic = sin(radlat);
      magic = 1 - ee * magic * magic;
      double sqrtmagic = sqrt(magic);
      dlat = (dlat * 180.0) / ((a * (1 - ee)) / (magic * sqrtmagic) * pi);
      dlng = (dlng * 180.0) / (a / sqrtmagic * cos(radlat) * pi);
      double mglat = lat + dlat;
      double mglng = lng + dlng;
      wglat = lat * 2 - mglat;
      wglng = lng * 2 - mglng;
      save[0] = wglng;
      save[1] = wglat;

      return save;
    }
}
bool MainWindow::out_of_china(double lng,double lat)
{
    // 纬度3.86~53.55,经度73.66~135.05
    return !(lng > 73.66 && lng < 135.05 && lat > 3.86 && lat < 53.55);
}

}  // namespace robot_hmi

/*****************************************************************************
** map
*****************************************************************************/

void robot_hmi::MainWindow::on_btn_loadmap_clicked()
{
    MapView->load(QUrl("file:///home/czh/study_code/QT_study/catkin_qt/src/robot_hmi/src/map_tcp.html"));
}

/** @fn     WebTest::getJsRetString
 *  @brief  获取web端返回值
 *  @return QString
 */
QString robot_hmi::MainWindow::getJsRetString()
{
    QEventLoop loop;
    QString jsStr = "getInfo();";

    QString retStr{}; // 返回值
    // 通过loop循环等到回调上来数据再继续
    MapView->page()->runJavaScript(jsStr, [&](const QVariant &v)
    {
        retStr = v.toString();
        loop.quit();
    });
    loop.exec();

    return retStr;
}

/** @fn     WebTest::recieveJsMessage
 *  @brief  接收来自webhtml的消息
 *  @param  const QString & jsMsg web端通知的消息
 *  @return void
 */



void robot_hmi::MainWindow::recieveJsMessage(const QString& np,const QString& path_points)
{
    QVector<double>().swap(g_key_longitude);
    QVector<double>().swap(g_key_latitude);
    QVector<double>().swap(test_longitude);
    QVector<double>().swap(test_latitude);

    QString start_GPS,end_GPS,start_GPS_true,end_GPS_true;
    start_GPS = np.section(';', 0, 0);
    end_GPS = np.section(';', 1, 1);
    start_GPS_true = np.section(';', 2, 2);
    end_GPS_true = np.section(';', -1, -1);

    QString Raw_GPS = "起点经纬度为："+start_GPS+";   "+"--------------------------------终点经纬度为："+end_GPS ;
    QString Raw_GPS_true = "真实规划的起点经纬度为："+start_GPS_true+";   "+"--------------终点经纬度为："+end_GPS_true;
    ui.ST_GPS_display->append("<font color=\"#FF00FF\">" + Raw_GPS +
                             "</font>");
    ui.ST_GPS_display->append("<font color=\"#00BF00\">" + Raw_GPS_true +
                             "</font>");

    QStringList Raw_list = np.split(";");
    QList<QString>::Iterator it = Raw_list.begin(),itend = Raw_list.end();
      int i = 0;
      for (;it != itend; it++,i++){
          if(i==2){
              QString Raw_Pace_display = "第"+QString::number(i-2)+"个点（起点）的经纬度坐标为："+Raw_list[i];
              ui.Pace_Raw_text_display->append("<font color=\"#4B0082\">" + Raw_Pace_display +
                                 "</font>");
              QString new1 = Raw_list[i].section(',', 0, 0);
              QString new2 = Raw_list[i].section(',', 1, 1);
              double * pnew = gcj02towgs84(new1.toDouble(),new2.toDouble());
              QString str1 = QString("%1").arg(QString::number(pnew[0],'f',6));
              QString str2 = QString("%1").arg(QString::number(pnew[1],'f',6));
              test_longitude.append(str1.toDouble());
              test_latitude.append(str2.toDouble());

              QString change_Pace_display = "第"+QString::number(i-2)+"个点（起点）的经纬度坐标为："+str1+""+","+""+str2;
              ui.Pace_text_display->append("<font color=\"#0000FF\">" + change_Pace_display +
                                 "</font>");
          }
          else if(i>2&&it != itend-1){
              QString Raw_Pace_display = "第"+QString::number(i-2)+"个点（中间点）的经纬度坐标为："+Raw_list[i];
              ui.Pace_Raw_text_display->append("<font color=\"#4B0082\">" + Raw_Pace_display +
                                 "</font>");
              QString new1 = Raw_list[i].section(',', 0, 0);
              QString new2 = Raw_list[i].section(',', 1, 1);
              double * pnew = gcj02towgs84(new1.toDouble(),new2.toDouble());
              QString str1 = QString("%1").arg(QString::number(pnew[0],'f',6));
              QString str2 = QString("%1").arg(QString::number(pnew[1],'f',6));
              test_longitude.append(str1.toDouble());
              test_latitude.append(str2.toDouble());
              QString change_Pace_display = "第"+QString::number(i-2)+"个点（中间点）的经纬度坐标为："+str1+""+","+""+str2;
              ui.Pace_text_display->append("<font color=\"#0000FF\">" + change_Pace_display +
                                 "</font>");
          }
          else if(it == itend-1){
              QString Raw_Pace_display = "第"+QString::number(i-2)+"个点（终点）的经纬度坐标为："+Raw_list[i];
              ui.Pace_Raw_text_display->append("<font color=\"#4B0082\">" + Raw_Pace_display +
                                 "</font>");
              QString new1 = Raw_list[i].section(',', 0, 0);
              QString new2 = Raw_list[i].section(',', 1, 1);
              double * pnew = gcj02towgs84(new1.toDouble(),new2.toDouble());
              QString str1 = QString("%1").arg(QString::number(pnew[0],'f',6));
              QString str2 = QString("%1").arg(QString::number(pnew[1],'f',6));
              test_longitude.append(str1.toDouble());
              test_latitude.append(str2.toDouble());
              QString change_Pace_display = "第"+QString::number(i-2)+"个点（终点）的经纬度坐标为："+str1+""+","+""+str2;
              ui.Pace_text_display->append("<font color=\"#0000FF\">" + change_Pace_display +
                                 "</font>");

          }
      }
      QStringList Key_Raw_list = path_points.split(";");
      QList<QString>::Iterator it_start = Key_Raw_list.begin(),itend_end = Key_Raw_list.end();
        int j = 0;
        for (;it_start != itend_end; it_start++,j++){
            if(j==1){
                QString Key_Raw_Pace_display = "第"+QString::number(j-1)+"个关键点（起点）的经纬度坐标为："+Key_Raw_list[j];
                ui.Key_Pace_Raw_text_display->append("<font color=\"#4B0082\">" + Key_Raw_Pace_display +
                                   "</font>");
                QString new1_key = Key_Raw_list[j].section(',', 0, 0);
                QString new2_key = Key_Raw_list[j].section(',', 1, 1);
                double * pnew_key = gcj02towgs84(new1_key.toDouble(),new2_key.toDouble());
                QString str1_key = QString("%1").arg(QString::number(pnew_key[0],'f',6));
                QString str2_key = QString("%1").arg(QString::number(pnew_key[1],'f',6));
                g_key_longitude.append(str1_key.toDouble());
                g_key_latitude.append(str2_key.toDouble());
                QString change_Key_Pace_display = "第"+QString::number(j-1)+"个关键点（起点）的经纬度坐标为："+str1_key+""+","+""+str2_key;
                ui.Key_Pace_text_display->append("<font color=\"#0000FF\">" + change_Key_Pace_display +
                                   "</font>");
            }
            else if(j>1&&it_start != itend_end-1){
                QString Key_Raw_Pace_display = "第"+QString::number(j-1)+"个关键点（中间点）的经纬度坐标为："+Key_Raw_list[j];
                ui.Key_Pace_Raw_text_display->append("<font color=\"#4B0082\">" + Key_Raw_Pace_display +
                                   "</font>");
                QString new1_key = Key_Raw_list[j].section(',', 0, 0);
                QString new2_key = Key_Raw_list[j].section(',', 1, 1);
                double * pnew_key = gcj02towgs84(new1_key.toDouble(),new2_key.toDouble());
                QString str1_key = QString("%1").arg(QString::number(pnew_key[0],'f',6));
                QString str2_key = QString("%1").arg(QString::number(pnew_key[1],'f',6));
                g_key_longitude.append(str1_key.toDouble());
                g_key_latitude.append(str2_key.toDouble());
                QString change_Key_Pace_display = "第"+QString::number(j-1)+"个关键点（中间点）的经纬度坐标为："+str1_key+""+","+""+str2_key;
                ui.Key_Pace_text_display->append("<font color=\"#0000FF\">" + change_Key_Pace_display +
                                   "</font>");
            }
            else if(it_start == itend_end-1){
                QString Key_Raw_Pace_display = "第"+QString::number(j-1)+"个关键点（终点）的经纬度坐标为："+Key_Raw_list[j];
                ui.Key_Pace_Raw_text_display->append("<font color=\"#4B0082\">" + Key_Raw_Pace_display +
                                   "</font>");
                QString new1_key = Key_Raw_list[j].section(',', 0, 0);
                QString new2_key = Key_Raw_list[j].section(',', 1, 1);
                double * pnew_key = gcj02towgs84(new1_key.toDouble(),new2_key.toDouble());
                QString str1_key = QString("%1").arg(QString::number(pnew_key[0],'f',6));
                QString str2_key = QString("%1").arg(QString::number(pnew_key[1],'f',6));
                g_key_longitude.append(str1_key.toDouble());
                g_key_latitude.append(str2_key.toDouble());
                QString change_Key_Pace_display = "第"+QString::number(j-1)+"个关键点（终点）的经纬度坐标为："+str1_key+""+","+""+str2_key;
                ui.Key_Pace_text_display->append("<font color=\"#0000FF\">" + change_Key_Pace_display +
                                   "</font>");
            }
        }

}
