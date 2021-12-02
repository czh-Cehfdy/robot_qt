/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_49;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLineEdit *line_edit_master;
    QLabel *label_2;
    QLineEdit *line_edit_host;
    QLabel *label_3;
    QLineEdit *line_edit_topic;
    QCheckBox *checkbox_use_environment;
    QCheckBox *checkbox_remember_settings;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btn_quit;
    QPushButton *btn_connect;
    QSpacerItem *verticalSpacer;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_47;
    QPushButton *btn_changeCarMode;
    QSpacerItem *horizontalSpacer_28;
    QHBoxLayout *horizontalLayout_46;
    QSpacerItem *horizontalSpacer_25;
    QPushButton *btn_simulation;
    QSpacerItem *horizontalSpacer_26;
    QPushButton *btn_trueCar;
    QSpacerItem *horizontalSpacer_27;
    QHBoxLayout *horizontalLayout_48;
    QSpacerItem *horizontalSpacer_34;
    QLabel *label_simulation_display;
    QSpacerItem *horizontalSpacer_32;
    QLabel *label_truecar_display;
    QSpacerItem *horizontalSpacer_33;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_scout;
    QVBoxLayout *verticalLayout_32;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_u;
    QPushButton *pushButton_i;
    QPushButton *pushButton_o;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_j;
    QCheckBox *checkBox_is_all;
    QPushButton *pushButton_l;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_n;
    QPushButton *pushButton_m;
    QPushButton *pushButton_br;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSlider *horizontalSlider_linera;
    QLabel *label_linera;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSlider *horizontalSlider_raw;
    QLabel *label_raw;
    QWidget *tab_14;
    QVBoxLayout *verticalLayout_19;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_15;
    QLabel *label_13;
    QTreeWidget *treeWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_50;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_51;
    QTextEdit *textEdit_quick_output;
    QTextEdit *textEdit_laser_cmd;
    QHBoxLayout *horizontalLayout_35;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *laser_btn;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_statue_text;
    QLabel *label_robot_staue_img;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tab_manager;
    QWidget *tab_status;
    QVBoxLayout *verticalLayout_26;
    QTabWidget *tabWidget_control;
    QWidget *tab_18;
    QVBoxLayout *verticalLayout_27;
    QTabWidget *tabWidget_3;
    QWidget *tab_16;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_29;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *refreash_topic_btn;
    QTableView *tableView_topic;
    QWidget *tab_17;
    QWidget *tab_10;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit_node1Display;
    QHBoxLayout *horizontalLayout_8;
    QTextEdit *textEdit_node1_cmd;
    QPushButton *btn_node1;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_9;
    QTextEdit *textEdit_node2Display;
    QHBoxLayout *horizontalLayout_9;
    QTextEdit *textEdit_node2_cmd;
    QPushButton *btn_node2;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_10;
    QTextEdit *textEdit_node3Display;
    QHBoxLayout *horizontalLayout_17;
    QTextEdit *textEdit_node3_cmd;
    QPushButton *btn_node3;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_11;
    QTextEdit *textEdit_node4Display;
    QHBoxLayout *horizontalLayout_18;
    QTextEdit *textEdit_node4_cmd;
    QPushButton *btn_node4;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_12;
    QTextEdit *textEdit_node5Display;
    QHBoxLayout *horizontalLayout_20;
    QTextEdit *textEdit_node5_cmd;
    QPushButton *btn_node5;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_23;
    QTextEdit *textEdit_node6Display;
    QHBoxLayout *horizontalLayout_21;
    QTextEdit *textEdit_node6_cmd;
    QPushButton *btn_node6;
    QWidget *tab_map;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_map;
    QHBoxLayout *horizontalLayout_42;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QPushButton *btn_loadmap;
    QPushButton *btn_closemap;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_43;
    QPushButton *btn_changeMode;
    QPushButton *btn_project;
    QPushButton *btn_develop;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_41;
    QPushButton *btn_getSP;
    QPushButton *btn_getTP;
    QPushButton *btn_pitch;
    QPushButton *btn_plan;
    QPushButton *btn_clear;
    QPushButton *btn_draw;
    QTabWidget *tabWidget_4;
    QWidget *tab_12;
    QHBoxLayout *horizontalLayout_14;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_33;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_14;
    QTextEdit *ST_GPS_display;
    QHBoxLayout *horizontalLayout_26;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_17;
    QTextEdit *Key_Pace_display;
    QLabel *label_23;
    QTextEdit *change_Key_Pace_display;
    QHBoxLayout *horizontalLayout_16;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *get_load_message;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *btn_clear_path;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_29;
    QTextBrowser *send_Pace_display;
    QHBoxLayout *horizontalLayout_25;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_chooseGPS;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_clear_path_2;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_21;
    QTextBrowser *goals_display;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *btn_send_path;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *btn_clear_path_ros;
    QSpacerItem *horizontalSpacer_11;
    QWidget *tab_6;
    QHBoxLayout *horizontalLayout_54;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_47;
    QHBoxLayout *horizontalLayout_53;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_49;
    QLabel *label_26;
    QLabel *label_truecardisplay;
    QLabel *label_33;
    QLabel *label_simdisplay;
    QSpacerItem *horizontalSpacer_31;
    QHBoxLayout *horizontalLayout_52;
    QLabel *label_34;
    QSpacerItem *horizontalSpacer_30;
    QTextEdit *textEdit_odomData;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_46;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_50;
    QLabel *label_35;
    QLineEdit *lineEdit_current;
    QLabel *label_36;
    QLineEdit *lineEdit_total;
    QLabel *label_37;
    QTextEdit *textEdit_dis;
    QHBoxLayout *horizontalLayout_51;
    QLabel *label_38;
    QSpacerItem *horizontalSpacer_29;
    QTextEdit *textEdit_odomDis;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_45;
    QHBoxLayout *horizontalLayout_38;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_42;
    QHBoxLayout *horizontalLayout_36;
    QPushButton *btn_display_gps;
    QPushButton *btn_close;
    QSpacerItem *horizontalSpacer_21;
    QHBoxLayout *horizontalLayout_40;
    QVBoxLayout *verticalLayout_43;
    QLabel *label_27;
    QLineEdit *get_longitude;
    QVBoxLayout *verticalLayout_44;
    QLabel *label_30;
    QLineEdit *get_latitude;
    QVBoxLayout *verticalLayout_45;
    QLabel *label_12;
    QLineEdit *get_status;
    QHBoxLayout *horizontalLayout_37;
    QLabel *label_32;
    QTextEdit *textEdit_gpsMsg;
    QHBoxLayout *horizontalLayout_39;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *btn_savegps;
    QSpacerItem *horizontalSpacer_15;
    QVBoxLayout *verticalLayout_41;
    QHBoxLayout *horizontalLayout_44;
    QSpacerItem *horizontalSpacer_24;
    QLabel *label_31;
    QSpacerItem *horizontalSpacer_23;
    QTextEdit *textEdit_gps_data;
    QHBoxLayout *horizontalLayout_29;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btn_display_data;
    QSpacerItem *horizontalSpacer_20;
    QWidget *tab_13;
    QPushButton *btn_test;
    QTextEdit *textEdit_test;
    QWidget *tab_RVIZ;
    QVBoxLayout *verticalLayout_25;
    QVBoxLayout *verticalLayout_24;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *set_start_btn;
    QPushButton *set_goal_btn;
    QPushButton *distance_measure_btn;
    QVBoxLayout *Layout_rviz;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_14;
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_RawImage;
    QPushButton *btn_DiaplayRawImage;
    QWidget *tab_8;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_PCLImage;
    QPushButton *btn_DisplayPCLImage;
    QWidget *tab_9;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_FusioImage;
    QPushButton *btn_DisplayFusionImage;
    QTextEdit *info_textEdit;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *enable_mouse_pushButton;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *measure_checkBox;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_41;
    QLineEdit *measure_width_lineEdit;
    QLabel *label_42;
    QLineEdit *measure_height_lineEdit;
    QLabel *label_43;
    QLineEdit *measure_distance_lineEdit;
    QWidget *tab_5;
    QHBoxLayout *horizontalLayout_27;
    QVBoxLayout *verticalLayout_40;
    QHBoxLayout *horizontalLayout_24;
    QPushButton *btn_interact;
    QLabel *label_7;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_30;
    QVBoxLayout *verticalLayout_rviz_obs;
    QWidget *widget;
    QVBoxLayout *verticalLayout_28;
    QHBoxLayout *horizontalLayout_34;
    QVBoxLayout *verticalLayout_37;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_19;
    QLabel *label_20;
    QTreeWidget *treeWidget_obstacles;
    QVBoxLayout *verticalLayout_39;
    QHBoxLayout *horizontalLayout_33;
    QVBoxLayout *verticalLayout_36;
    QCheckBox *checkBox_tip;
    QLabel *label_22;
    QLabel *label_obstacle_display;
    QVBoxLayout *verticalLayout_38;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_24;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_35;
    QTextEdit *textEdit_obstacle;
    QLabel *label_21;
    QVBoxLayout *verticalLayout_34;
    QLabel *label_9;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_31;
    QLabel *label_10;
    QLineEdit *lineEdit_sonar1;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *btn_sonar_startmeasure;
    QPushButton *btn_sonar_stopmeasure;
    QLabel *label_28;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_sonar_display;
    QTextEdit *textEdit_tip;
    QLabel *label_18;
    QWidget *tab_15;
    QVBoxLayout *verticalLayout_52;
    QChartView *widget_goal;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QStringLiteral("MainWindowDesign"));
        MainWindowDesign->resize(1368, 1030);
        MainWindowDesign->setMinimumSize(QSize(0, 0));
        MainWindowDesign->setMaximumSize(QSize(130000, 100000));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QStringLiteral("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_49 = new QVBoxLayout(centralwidget);
        verticalLayout_49->setObjectName(QStringLiteral("verticalLayout_49"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(280, 0));
        tabWidget->setMaximumSize(QSize(420, 16777215));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_8 = new QVBoxLayout(tab);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(280, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(label);

        line_edit_master = new QLineEdit(groupBox);
        line_edit_master->setObjectName(QStringLiteral("line_edit_master"));

        verticalLayout_4->addWidget(line_edit_master);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(label_2);

        line_edit_host = new QLineEdit(groupBox);
        line_edit_host->setObjectName(QStringLiteral("line_edit_host"));

        verticalLayout_4->addWidget(line_edit_host);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFrameShape(QFrame::StyledPanel);
        label_3->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(label_3);

        line_edit_topic = new QLineEdit(groupBox);
        line_edit_topic->setObjectName(QStringLiteral("line_edit_topic"));
        line_edit_topic->setEnabled(false);

        verticalLayout_4->addWidget(line_edit_topic);

        checkbox_use_environment = new QCheckBox(groupBox);
        checkbox_use_environment->setObjectName(QStringLiteral("checkbox_use_environment"));
        checkbox_use_environment->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_4->addWidget(checkbox_use_environment);

        checkbox_remember_settings = new QCheckBox(groupBox);
        checkbox_remember_settings->setObjectName(QStringLiteral("checkbox_remember_settings"));
        checkbox_remember_settings->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_4->addWidget(checkbox_remember_settings);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        btn_quit = new QPushButton(groupBox);
        btn_quit->setObjectName(QStringLiteral("btn_quit"));

        horizontalLayout->addWidget(btn_quit);

        btn_connect = new QPushButton(groupBox);
        btn_connect->setObjectName(QStringLiteral("btn_connect"));
        btn_connect->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_connect->sizePolicy().hasHeightForWidth());
        btn_connect->setSizePolicy(sizePolicy1);
        btn_connect->setMinimumSize(QSize(150, 0));
        btn_connect->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(btn_connect);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_7->addLayout(verticalLayout_4);

        verticalSpacer = new QSpacerItem(13, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        widget_8 = new QWidget(groupBox);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        verticalLayout_6 = new QVBoxLayout(widget_8);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_25 = new QLabel(widget_8);
        label_25->setObjectName(QStringLiteral("label_25"));
        QFont font;
        font.setPointSize(16);
        label_25->setFont(font);

        verticalLayout_6->addWidget(label_25);

        horizontalLayout_47 = new QHBoxLayout();
        horizontalLayout_47->setObjectName(QStringLiteral("horizontalLayout_47"));
        btn_changeCarMode = new QPushButton(widget_8);
        btn_changeCarMode->setObjectName(QStringLiteral("btn_changeCarMode"));
        btn_changeCarMode->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(143, 89, 2);\n"
"    font-size:15px;\n"
"    width:60px;\n"
"	height:30px;\n"
"border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(143, 89, 2) ;\n"
"     font-size:16px;\n"
"     border-radius: 20px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_47->addWidget(btn_changeCarMode);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_47->addItem(horizontalSpacer_28);


        verticalLayout_6->addLayout(horizontalLayout_47);

        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setObjectName(QStringLiteral("horizontalLayout_46"));
        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_46->addItem(horizontalSpacer_25);

        btn_simulation = new QPushButton(widget_8);
        btn_simulation->setObjectName(QStringLiteral("btn_simulation"));
        btn_simulation->setMinimumSize(QSize(80, 40));
        btn_simulation->setMaximumSize(QSize(80, 40));
        btn_simulation->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:19px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    background-color: ;\n"
"	background-color: rgb(248, 218, 179);\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:22px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_46->addWidget(btn_simulation);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_46->addItem(horizontalSpacer_26);

        btn_trueCar = new QPushButton(widget_8);
        btn_trueCar->setObjectName(QStringLiteral("btn_trueCar"));
        btn_trueCar->setMinimumSize(QSize(80, 40));
        btn_trueCar->setMaximumSize(QSize(80, 40));
        btn_trueCar->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:19px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    background-color: ;\n"
"	background-color: rgb(248, 218, 179);\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:22px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_46->addWidget(btn_trueCar);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_46->addItem(horizontalSpacer_27);


        verticalLayout_6->addLayout(horizontalLayout_46);

        horizontalLayout_48 = new QHBoxLayout();
        horizontalLayout_48->setObjectName(QStringLiteral("horizontalLayout_48"));
        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_48->addItem(horizontalSpacer_34);

        label_simulation_display = new QLabel(widget_8);
        label_simulation_display->setObjectName(QStringLiteral("label_simulation_display"));
        label_simulation_display->setMinimumSize(QSize(30, 30));
        label_simulation_display->setMaximumSize(QSize(30, 30));
        label_simulation_display->setPixmap(QPixmap(QString::fromUtf8(":/images/Red.png")));
        label_simulation_display->setScaledContents(true);

        horizontalLayout_48->addWidget(label_simulation_display);

        horizontalSpacer_32 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_48->addItem(horizontalSpacer_32);

        label_truecar_display = new QLabel(widget_8);
        label_truecar_display->setObjectName(QStringLiteral("label_truecar_display"));
        label_truecar_display->setMinimumSize(QSize(30, 30));
        label_truecar_display->setMaximumSize(QSize(30, 30));
        label_truecar_display->setPixmap(QPixmap(QString::fromUtf8(":/images/Red.png")));
        label_truecar_display->setScaledContents(true);

        horizontalLayout_48->addWidget(label_truecar_display);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_48->addItem(horizontalSpacer_33);

        horizontalLayout_48->setStretch(0, 1);
        horizontalLayout_48->setStretch(1, 1);
        horizontalLayout_48->setStretch(2, 1);
        horizontalLayout_48->setStretch(3, 1);
        horizontalLayout_48->setStretch(4, 1);

        verticalLayout_6->addLayout(horizontalLayout_48);


        verticalLayout_7->addWidget(widget_8);

        verticalSpacer_2 = new QSpacerItem(18, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        groupBox_scout = new QGroupBox(groupBox);
        groupBox_scout->setObjectName(QStringLiteral("groupBox_scout"));
        groupBox_scout->setMinimumSize(QSize(0, 150));
        groupBox_scout->setMaximumSize(QSize(16777215, 320));
        verticalLayout_32 = new QVBoxLayout(groupBox_scout);
        verticalLayout_32->setObjectName(QStringLiteral("verticalLayout_32"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_u = new QPushButton(groupBox_scout);
        pushButton_u->setObjectName(QStringLiteral("pushButton_u"));
        pushButton_u->setMinimumSize(QSize(0, 20));

        horizontalLayout_2->addWidget(pushButton_u);

        pushButton_i = new QPushButton(groupBox_scout);
        pushButton_i->setObjectName(QStringLiteral("pushButton_i"));
        pushButton_i->setMinimumSize(QSize(0, 20));

        horizontalLayout_2->addWidget(pushButton_i);

        pushButton_o = new QPushButton(groupBox_scout);
        pushButton_o->setObjectName(QStringLiteral("pushButton_o"));
        pushButton_o->setMinimumSize(QSize(0, 20));

        horizontalLayout_2->addWidget(pushButton_o);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_j = new QPushButton(groupBox_scout);
        pushButton_j->setObjectName(QStringLiteral("pushButton_j"));
        pushButton_j->setMinimumSize(QSize(0, 20));

        horizontalLayout_3->addWidget(pushButton_j);

        checkBox_is_all = new QCheckBox(groupBox_scout);
        checkBox_is_all->setObjectName(QStringLiteral("checkBox_is_all"));
        checkBox_is_all->setMinimumSize(QSize(70, 20));

        horizontalLayout_3->addWidget(checkBox_is_all);

        pushButton_l = new QPushButton(groupBox_scout);
        pushButton_l->setObjectName(QStringLiteral("pushButton_l"));
        pushButton_l->setMinimumSize(QSize(0, 20));

        horizontalLayout_3->addWidget(pushButton_l);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_n = new QPushButton(groupBox_scout);
        pushButton_n->setObjectName(QStringLiteral("pushButton_n"));
        pushButton_n->setMinimumSize(QSize(0, 20));

        horizontalLayout_4->addWidget(pushButton_n);

        pushButton_m = new QPushButton(groupBox_scout);
        pushButton_m->setObjectName(QStringLiteral("pushButton_m"));
        pushButton_m->setMinimumSize(QSize(0, 20));

        horizontalLayout_4->addWidget(pushButton_m);

        pushButton_br = new QPushButton(groupBox_scout);
        pushButton_br->setObjectName(QStringLiteral("pushButton_br"));
        pushButton_br->setMinimumSize(QSize(0, 20));

        horizontalLayout_4->addWidget(pushButton_br);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(groupBox_scout);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        horizontalSlider_linera = new QSlider(groupBox_scout);
        horizontalSlider_linera->setObjectName(QStringLiteral("horizontalSlider_linera"));
        horizontalSlider_linera->setMaximum(100);
        horizontalSlider_linera->setValue(0);
        horizontalSlider_linera->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider_linera);

        label_linera = new QLabel(groupBox_scout);
        label_linera->setObjectName(QStringLiteral("label_linera"));
        label_linera->setMinimumSize(QSize(30, 0));
        label_linera->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_5->addWidget(label_linera);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(groupBox_scout);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        horizontalSlider_raw = new QSlider(groupBox_scout);
        horizontalSlider_raw->setObjectName(QStringLiteral("horizontalSlider_raw"));
        horizontalSlider_raw->setMaximum(100);
        horizontalSlider_raw->setValue(0);
        horizontalSlider_raw->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(horizontalSlider_raw);

        label_raw = new QLabel(groupBox_scout);
        label_raw->setObjectName(QStringLiteral("label_raw"));
        label_raw->setMinimumSize(QSize(20, 0));
        label_raw->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_6->addWidget(label_raw);


        verticalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout_32->addLayout(verticalLayout_5);


        verticalLayout_7->addWidget(groupBox_scout);


        verticalLayout_3->addWidget(groupBox);


        verticalLayout_8->addWidget(frame);

        tabWidget->addTab(tab, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName(QStringLiteral("tab_14"));
        verticalLayout_19 = new QVBoxLayout(tab_14);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_15 = new QLabel(tab_14);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(16, 16));
        label_15->setMaximumSize(QSize(16, 16));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/images/classes/Displays.svg")));

        horizontalLayout_11->addWidget(label_15);

        label_13 = new QLabel(tab_14);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_11->addWidget(label_13);


        verticalLayout_18->addLayout(horizontalLayout_11);

        treeWidget = new QTreeWidget(tab_14);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->header()->setDefaultSectionSize(150);
        treeWidget->header()->setMinimumSectionSize(150);

        verticalLayout_18->addWidget(treeWidget);


        verticalLayout_19->addLayout(verticalLayout_18);

        tabWidget->addTab(tab_14, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_50 = new QVBoxLayout(tab_2);
        verticalLayout_50->setObjectName(QStringLiteral("verticalLayout_50"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_51 = new QVBoxLayout(groupBox_2);
        verticalLayout_51->setObjectName(QStringLiteral("verticalLayout_51"));
        textEdit_quick_output = new QTextEdit(groupBox_2);
        textEdit_quick_output->setObjectName(QStringLiteral("textEdit_quick_output"));
        textEdit_quick_output->setMaximumSize(QSize(16777215, 100));
        textEdit_quick_output->setStyleSheet(QLatin1String("background:rgb(0, 0, 0)\n"
""));

        verticalLayout_51->addWidget(textEdit_quick_output);

        textEdit_laser_cmd = new QTextEdit(groupBox_2);
        textEdit_laser_cmd->setObjectName(QStringLiteral("textEdit_laser_cmd"));

        verticalLayout_51->addWidget(textEdit_laser_cmd);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_35->addItem(horizontalSpacer_13);

        laser_btn = new QPushButton(groupBox_2);
        laser_btn->setObjectName(QStringLiteral("laser_btn"));

        horizontalLayout_35->addWidget(laser_btn);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_35->addItem(horizontalSpacer_22);


        verticalLayout_51->addLayout(horizontalLayout_35);

        verticalSpacer_4 = new QSpacerItem(20, 350, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_51->addItem(verticalSpacer_4);


        verticalLayout_50->addWidget(groupBox_2);

        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 1, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(35, 0));
        label_6->setMaximumSize(QSize(35, 16777215));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/images/robot2.png")));

        horizontalLayout_7->addWidget(label_6);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(100, 0));
        label_8->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(label_8);

        label_statue_text = new QLabel(centralwidget);
        label_statue_text->setObjectName(QStringLiteral("label_statue_text"));

        horizontalLayout_7->addWidget(label_statue_text);

        label_robot_staue_img = new QLabel(centralwidget);
        label_robot_staue_img->setObjectName(QStringLiteral("label_robot_staue_img"));
        label_robot_staue_img->setMinimumSize(QSize(32, 32));
        label_robot_staue_img->setMaximumSize(QSize(32, 32));
        label_robot_staue_img->setPixmap(QPixmap(QString::fromUtf8(":/images/power-v.png")));

        horizontalLayout_7->addWidget(label_robot_staue_img);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_7, 0, 1, 1, 1);

        tab_manager = new QTabWidget(centralwidget);
        tab_manager->setObjectName(QStringLiteral("tab_manager"));
        tab_manager->setMinimumSize(QSize(0, 0));
        tab_manager->setMaximumSize(QSize(100000, 100000));
        tab_manager->setLocale(QLocale(QLocale::English, QLocale::Australia));
        tab_manager->setTabBarAutoHide(false);
        tab_status = new QWidget();
        tab_status->setObjectName(QStringLiteral("tab_status"));
        verticalLayout_26 = new QVBoxLayout(tab_status);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        tabWidget_control = new QTabWidget(tab_status);
        tabWidget_control->setObjectName(QStringLiteral("tabWidget_control"));
        tabWidget_control->setMinimumSize(QSize(0, 0));
        tabWidget_control->setMaximumSize(QSize(16777215, 10000000));
        tab_18 = new QWidget();
        tab_18->setObjectName(QStringLiteral("tab_18"));
        verticalLayout_27 = new QVBoxLayout(tab_18);
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        tabWidget_3 = new QTabWidget(tab_18);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tab_16 = new QWidget();
        tab_16->setObjectName(QStringLiteral("tab_16"));
        verticalLayout_2 = new QVBoxLayout(tab_16);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_29 = new QLabel(tab_16);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setMinimumSize(QSize(150, 0));
        label_29->setMaximumSize(QSize(150, 30));
        QFont font1;
        font1.setPointSize(18);
        label_29->setFont(font1);

        horizontalLayout_22->addWidget(label_29);

        horizontalSpacer_12 = new QSpacerItem(428, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_12);

        refreash_topic_btn = new QPushButton(tab_16);
        refreash_topic_btn->setObjectName(QStringLiteral("refreash_topic_btn"));
        refreash_topic_btn->setMinimumSize(QSize(0, 0));
        refreash_topic_btn->setMaximumSize(QSize(120, 40));
        refreash_topic_btn->setCursor(QCursor(Qt::ArrowCursor));
        refreash_topic_btn->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/refreash.png"), QSize(), QIcon::Normal, QIcon::Off);
        refreash_topic_btn->setIcon(icon1);

        horizontalLayout_22->addWidget(refreash_topic_btn);


        verticalLayout_2->addLayout(horizontalLayout_22);

        tableView_topic = new QTableView(tab_16);
        tableView_topic->setObjectName(QStringLiteral("tableView_topic"));

        verticalLayout_2->addWidget(tableView_topic);

        tabWidget_3->addTab(tab_16, QString());
        tab_17 = new QWidget();
        tab_17->setObjectName(QStringLiteral("tab_17"));
        tabWidget_3->addTab(tab_17, QString());

        verticalLayout_27->addWidget(tabWidget_3);

        tabWidget_control->addTab(tab_18, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        gridLayout = new QGridLayout(tab_10);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_7 = new QGroupBox(tab_10);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        verticalLayout = new QVBoxLayout(groupBox_7);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit_node1Display = new QTextEdit(groupBox_7);
        textEdit_node1Display->setObjectName(QStringLiteral("textEdit_node1Display"));
        textEdit_node1Display->setMinimumSize(QSize(0, 0));
        textEdit_node1Display->setMaximumSize(QSize(16777215, 16777215));
        textEdit_node1Display->setStyleSheet(QStringLiteral("background:rgb(0, 0, 0)"));

        verticalLayout->addWidget(textEdit_node1Display);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        textEdit_node1_cmd = new QTextEdit(groupBox_7);
        textEdit_node1_cmd->setObjectName(QStringLiteral("textEdit_node1_cmd"));
        textEdit_node1_cmd->setMinimumSize(QSize(0, 0));
        textEdit_node1_cmd->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_8->addWidget(textEdit_node1_cmd);

        btn_node1 = new QPushButton(groupBox_7);
        btn_node1->setObjectName(QStringLiteral("btn_node1"));

        horizontalLayout_8->addWidget(btn_node1);


        verticalLayout->addLayout(horizontalLayout_8);


        gridLayout->addWidget(groupBox_7, 0, 0, 1, 1);

        groupBox_8 = new QGroupBox(tab_10);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        verticalLayout_9 = new QVBoxLayout(groupBox_8);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        textEdit_node2Display = new QTextEdit(groupBox_8);
        textEdit_node2Display->setObjectName(QStringLiteral("textEdit_node2Display"));
        textEdit_node2Display->setMinimumSize(QSize(0, 0));
        textEdit_node2Display->setMaximumSize(QSize(16777215, 16777215));
        textEdit_node2Display->setStyleSheet(QStringLiteral("background:rgb(0, 0, 0)"));

        verticalLayout_9->addWidget(textEdit_node2Display);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        textEdit_node2_cmd = new QTextEdit(groupBox_8);
        textEdit_node2_cmd->setObjectName(QStringLiteral("textEdit_node2_cmd"));
        textEdit_node2_cmd->setMinimumSize(QSize(0, 0));
        textEdit_node2_cmd->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_9->addWidget(textEdit_node2_cmd);

        btn_node2 = new QPushButton(groupBox_8);
        btn_node2->setObjectName(QStringLiteral("btn_node2"));

        horizontalLayout_9->addWidget(btn_node2);


        verticalLayout_9->addLayout(horizontalLayout_9);


        gridLayout->addWidget(groupBox_8, 0, 1, 1, 1);

        groupBox_6 = new QGroupBox(tab_10);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_10 = new QVBoxLayout(groupBox_6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        textEdit_node3Display = new QTextEdit(groupBox_6);
        textEdit_node3Display->setObjectName(QStringLiteral("textEdit_node3Display"));
        textEdit_node3Display->setMinimumSize(QSize(0, 0));
        textEdit_node3Display->setMaximumSize(QSize(16777215, 16777215));
        textEdit_node3Display->setStyleSheet(QStringLiteral("background:rgb(0, 0, 0)"));

        verticalLayout_10->addWidget(textEdit_node3Display);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        textEdit_node3_cmd = new QTextEdit(groupBox_6);
        textEdit_node3_cmd->setObjectName(QStringLiteral("textEdit_node3_cmd"));
        textEdit_node3_cmd->setMinimumSize(QSize(0, 0));
        textEdit_node3_cmd->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_17->addWidget(textEdit_node3_cmd);

        btn_node3 = new QPushButton(groupBox_6);
        btn_node3->setObjectName(QStringLiteral("btn_node3"));

        horizontalLayout_17->addWidget(btn_node3);


        verticalLayout_10->addLayout(horizontalLayout_17);


        gridLayout->addWidget(groupBox_6, 0, 2, 1, 2);

        groupBox_9 = new QGroupBox(tab_10);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setMinimumSize(QSize(0, 0));
        groupBox_9->setMaximumSize(QSize(500, 16777215));
        verticalLayout_11 = new QVBoxLayout(groupBox_9);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        textEdit_node4Display = new QTextEdit(groupBox_9);
        textEdit_node4Display->setObjectName(QStringLiteral("textEdit_node4Display"));
        textEdit_node4Display->setMinimumSize(QSize(0, 0));
        textEdit_node4Display->setMaximumSize(QSize(16777215, 16777215));
        textEdit_node4Display->setStyleSheet(QStringLiteral("background:rgb(0, 0, 0)"));

        verticalLayout_11->addWidget(textEdit_node4Display);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        textEdit_node4_cmd = new QTextEdit(groupBox_9);
        textEdit_node4_cmd->setObjectName(QStringLiteral("textEdit_node4_cmd"));
        textEdit_node4_cmd->setMinimumSize(QSize(0, 0));
        textEdit_node4_cmd->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_18->addWidget(textEdit_node4_cmd);

        btn_node4 = new QPushButton(groupBox_9);
        btn_node4->setObjectName(QStringLiteral("btn_node4"));

        horizontalLayout_18->addWidget(btn_node4);


        verticalLayout_11->addLayout(horizontalLayout_18);


        gridLayout->addWidget(groupBox_9, 1, 0, 1, 1);

        groupBox_10 = new QGroupBox(tab_10);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setMinimumSize(QSize(0, 0));
        groupBox_10->setMaximumSize(QSize(500, 16777215));
        verticalLayout_12 = new QVBoxLayout(groupBox_10);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        textEdit_node5Display = new QTextEdit(groupBox_10);
        textEdit_node5Display->setObjectName(QStringLiteral("textEdit_node5Display"));
        textEdit_node5Display->setMinimumSize(QSize(0, 0));
        textEdit_node5Display->setMaximumSize(QSize(16777215, 16777215));
        textEdit_node5Display->setStyleSheet(QStringLiteral("background:rgb(0, 0, 0)"));

        verticalLayout_12->addWidget(textEdit_node5Display);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        textEdit_node5_cmd = new QTextEdit(groupBox_10);
        textEdit_node5_cmd->setObjectName(QStringLiteral("textEdit_node5_cmd"));
        textEdit_node5_cmd->setMinimumSize(QSize(0, 0));
        textEdit_node5_cmd->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_20->addWidget(textEdit_node5_cmd);

        btn_node5 = new QPushButton(groupBox_10);
        btn_node5->setObjectName(QStringLiteral("btn_node5"));

        horizontalLayout_20->addWidget(btn_node5);


        verticalLayout_12->addLayout(horizontalLayout_20);


        gridLayout->addWidget(groupBox_10, 1, 1, 1, 2);

        groupBox_11 = new QGroupBox(tab_10);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setMinimumSize(QSize(0, 0));
        groupBox_11->setMaximumSize(QSize(500, 16777215));
        verticalLayout_23 = new QVBoxLayout(groupBox_11);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        textEdit_node6Display = new QTextEdit(groupBox_11);
        textEdit_node6Display->setObjectName(QStringLiteral("textEdit_node6Display"));
        textEdit_node6Display->setMinimumSize(QSize(0, 0));
        textEdit_node6Display->setMaximumSize(QSize(16777215, 16777215));
        textEdit_node6Display->setStyleSheet(QStringLiteral("background:rgb(0, 0, 0)"));

        verticalLayout_23->addWidget(textEdit_node6Display);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        textEdit_node6_cmd = new QTextEdit(groupBox_11);
        textEdit_node6_cmd->setObjectName(QStringLiteral("textEdit_node6_cmd"));
        textEdit_node6_cmd->setMinimumSize(QSize(0, 0));
        textEdit_node6_cmd->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_21->addWidget(textEdit_node6_cmd);

        btn_node6 = new QPushButton(groupBox_11);
        btn_node6->setObjectName(QStringLiteral("btn_node6"));

        horizontalLayout_21->addWidget(btn_node6);


        verticalLayout_23->addLayout(horizontalLayout_21);


        gridLayout->addWidget(groupBox_11, 1, 3, 1, 1);

        tabWidget_control->addTab(tab_10, QString());

        verticalLayout_26->addWidget(tabWidget_control);

        tab_manager->addTab(tab_status, QString());
        tab_map = new QWidget();
        tab_map->setObjectName(QStringLiteral("tab_map"));
        verticalLayout_22 = new QVBoxLayout(tab_map);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        label_map = new QLabel(tab_map);
        label_map->setObjectName(QStringLiteral("label_map"));
        label_map->setMinimumSize(QSize(900, 400));
        label_map->setMaximumSize(QSize(16777215, 400));

        verticalLayout_22->addWidget(label_map);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setObjectName(QStringLiteral("horizontalLayout_42"));
        widget_4 = new QWidget(tab_map);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 45));
        widget_4->setMaximumSize(QSize(350, 45));
        widget_4->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));
        horizontalLayout_10 = new QHBoxLayout(widget_4);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_11 = new QLabel(widget_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(150, 0));
        label_11->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_10->addWidget(label_11);

        btn_loadmap = new QPushButton(widget_4);
        btn_loadmap->setObjectName(QStringLiteral("btn_loadmap"));
        btn_loadmap->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_10->addWidget(btn_loadmap);

        btn_closemap = new QPushButton(widget_4);
        btn_closemap->setObjectName(QStringLiteral("btn_closemap"));
        btn_closemap->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_10->addWidget(btn_closemap);


        horizontalLayout_42->addWidget(widget_4);

        widget_3 = new QWidget(tab_map);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(260, 45));
        widget_3->setMaximumSize(QSize(260, 45));
        horizontalLayout_43 = new QHBoxLayout(widget_3);
        horizontalLayout_43->setObjectName(QStringLiteral("horizontalLayout_43"));
        btn_changeMode = new QPushButton(widget_3);
        btn_changeMode->setObjectName(QStringLiteral("btn_changeMode"));
        btn_changeMode->setMinimumSize(QSize(120, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu"));
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(75);
        btn_changeMode->setFont(font2);
        btn_changeMode->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(143, 89, 2);\n"
"    font-size:15px;\n"
"    width:60px;\n"
"	height:30px;\n"
"border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(143, 89, 2) ;\n"
"     font-size:16px;\n"
"     border-radius: 20px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_43->addWidget(btn_changeMode);

        btn_project = new QPushButton(widget_3);
        btn_project->setObjectName(QStringLiteral("btn_project"));
        btn_project->setStyleSheet(QLatin1String("QPushButton { \n"
"	color: rgb(143, 89, 2);\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(143, 89, 2) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(92, 53, 102) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_43->addWidget(btn_project);

        btn_develop = new QPushButton(widget_3);
        btn_develop->setObjectName(QStringLiteral("btn_develop"));
        btn_develop->setStyleSheet(QLatin1String("QPushButton { \n"
"	color: rgb(143, 89, 2);\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(143, 89, 2) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(92, 53, 102) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_43->addWidget(btn_develop);


        horizontalLayout_42->addWidget(widget_3);

        widget_5 = new QWidget(tab_map);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 45));
        widget_5->setMaximumSize(QSize(1600000, 45));
        horizontalLayout_41 = new QHBoxLayout(widget_5);
        horizontalLayout_41->setObjectName(QStringLiteral("horizontalLayout_41"));
        btn_getSP = new QPushButton(widget_5);
        btn_getSP->setObjectName(QStringLiteral("btn_getSP"));
        btn_getSP->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_41->addWidget(btn_getSP);

        btn_getTP = new QPushButton(widget_5);
        btn_getTP->setObjectName(QStringLiteral("btn_getTP"));
        btn_getTP->setCursor(QCursor(Qt::ArrowCursor));
        btn_getTP->setMouseTracking(false);
        btn_getTP->setFocusPolicy(Qt::StrongFocus);
        btn_getTP->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));
        btn_getTP->setFlat(false);

        horizontalLayout_41->addWidget(btn_getTP);

        btn_pitch = new QPushButton(widget_5);
        btn_pitch->setObjectName(QStringLiteral("btn_pitch"));
        btn_pitch->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_41->addWidget(btn_pitch);

        btn_plan = new QPushButton(widget_5);
        btn_plan->setObjectName(QStringLiteral("btn_plan"));
        btn_plan->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_41->addWidget(btn_plan);

        btn_clear = new QPushButton(widget_5);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));
        btn_clear->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_41->addWidget(btn_clear);

        btn_draw = new QPushButton(widget_5);
        btn_draw->setObjectName(QStringLiteral("btn_draw"));
        btn_draw->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_41->addWidget(btn_draw);


        horizontalLayout_42->addWidget(widget_5);


        verticalLayout_22->addLayout(horizontalLayout_42);

        tabWidget_4 = new QTabWidget(tab_map);
        tabWidget_4->setObjectName(QStringLiteral("tabWidget_4"));
        tabWidget_4->setMaximumSize(QSize(2000, 600));
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        horizontalLayout_14 = new QHBoxLayout(tab_12);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        widget_7 = new QWidget(tab_12);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        verticalLayout_33 = new QVBoxLayout(widget_7);
        verticalLayout_33->setObjectName(QStringLiteral("verticalLayout_33"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_14 = new QLabel(widget_7);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(170, 50));
        label_14->setMaximumSize(QSize(170, 50));

        horizontalLayout_13->addWidget(label_14);

        ST_GPS_display = new QTextEdit(widget_7);
        ST_GPS_display->setObjectName(QStringLiteral("ST_GPS_display"));
        ST_GPS_display->setMinimumSize(QSize(450, 60));
        ST_GPS_display->setMaximumSize(QSize(450, 60));

        horizontalLayout_13->addWidget(ST_GPS_display);


        verticalLayout_33->addLayout(horizontalLayout_13);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        label_17 = new QLabel(widget_7);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(0, 30));
        label_17->setMaximumSize(QSize(1000, 30));

        verticalLayout_20->addWidget(label_17);

        Key_Pace_display = new QTextEdit(widget_7);
        Key_Pace_display->setObjectName(QStringLiteral("Key_Pace_display"));

        verticalLayout_20->addWidget(Key_Pace_display);

        label_23 = new QLabel(widget_7);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMinimumSize(QSize(0, 30));
        label_23->setMaximumSize(QSize(100000, 30));

        verticalLayout_20->addWidget(label_23);

        change_Key_Pace_display = new QTextEdit(widget_7);
        change_Key_Pace_display->setObjectName(QStringLiteral("change_Key_Pace_display"));
        change_Key_Pace_display->setMinimumSize(QSize(0, 0));
        change_Key_Pace_display->setMaximumSize(QSize(10000, 16777215));

        verticalLayout_20->addWidget(change_Key_Pace_display);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_16);

        get_load_message = new QPushButton(widget_7);
        get_load_message->setObjectName(QStringLiteral("get_load_message"));
        get_load_message->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_16->addWidget(get_load_message);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_17);

        btn_clear_path = new QPushButton(widget_7);
        btn_clear_path->setObjectName(QStringLiteral("btn_clear_path"));
        btn_clear_path->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_16->addWidget(btn_clear_path);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_10);


        verticalLayout_20->addLayout(horizontalLayout_16);


        horizontalLayout_26->addLayout(verticalLayout_20);

        verticalLayout_29 = new QVBoxLayout();
        verticalLayout_29->setObjectName(QStringLiteral("verticalLayout_29"));
        send_Pace_display = new QTextBrowser(widget_7);
        send_Pace_display->setObjectName(QStringLiteral("send_Pace_display"));

        verticalLayout_29->addWidget(send_Pace_display);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_3);

        btn_chooseGPS = new QPushButton(widget_7);
        btn_chooseGPS->setObjectName(QStringLiteral("btn_chooseGPS"));
        btn_chooseGPS->setMinimumSize(QSize(80, 0));
        btn_chooseGPS->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_25->addWidget(btn_chooseGPS);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_4);

        btn_clear_path_2 = new QPushButton(widget_7);
        btn_clear_path_2->setObjectName(QStringLiteral("btn_clear_path_2"));
        btn_clear_path_2->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_25->addWidget(btn_clear_path_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_7);


        verticalLayout_29->addLayout(horizontalLayout_25);


        horizontalLayout_26->addLayout(verticalLayout_29);


        verticalLayout_33->addLayout(horizontalLayout_26);


        horizontalLayout_14->addWidget(widget_7);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        goals_display = new QTextBrowser(tab_12);
        goals_display->setObjectName(QStringLiteral("goals_display"));
        goals_display->setMinimumSize(QSize(300, 0));
        QFont font3;
        font3.setPointSize(12);
        goals_display->setFont(font3);

        verticalLayout_21->addWidget(goals_display);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_18);

        btn_send_path = new QPushButton(tab_12);
        btn_send_path->setObjectName(QStringLiteral("btn_send_path"));
        btn_send_path->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_19->addWidget(btn_send_path);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_19);

        btn_clear_path_ros = new QPushButton(tab_12);
        btn_clear_path_ros->setObjectName(QStringLiteral("btn_clear_path_ros"));
        btn_clear_path_ros->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:13px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:14px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_19->addWidget(btn_clear_path_ros);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_11);


        verticalLayout_21->addLayout(horizontalLayout_19);


        horizontalLayout_14->addLayout(verticalLayout_21);

        tabWidget_4->addTab(tab_12, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        horizontalLayout_54 = new QHBoxLayout(tab_6);
        horizontalLayout_54->setObjectName(QStringLiteral("horizontalLayout_54"));
        widget_12 = new QWidget(tab_6);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setMinimumSize(QSize(600, 0));
        widget_12->setMaximumSize(QSize(600, 16777215));
        verticalLayout_47 = new QVBoxLayout(widget_12);
        verticalLayout_47->setObjectName(QStringLiteral("verticalLayout_47"));
        horizontalLayout_53 = new QHBoxLayout();
        horizontalLayout_53->setObjectName(QStringLiteral("horizontalLayout_53"));
        widget_9 = new QWidget(widget_12);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        horizontalLayout_49 = new QHBoxLayout(widget_9);
        horizontalLayout_49->setObjectName(QStringLiteral("horizontalLayout_49"));
        label_26 = new QLabel(widget_9);
        label_26->setObjectName(QStringLiteral("label_26"));
        QFont font4;
        font4.setPointSize(17);
        label_26->setFont(font4);

        horizontalLayout_49->addWidget(label_26);

        label_truecardisplay = new QLabel(widget_9);
        label_truecardisplay->setObjectName(QStringLiteral("label_truecardisplay"));
        label_truecardisplay->setMinimumSize(QSize(30, 30));
        label_truecardisplay->setMaximumSize(QSize(30, 30));
        label_truecardisplay->setPixmap(QPixmap(QString::fromUtf8(":/images/Red.png")));
        label_truecardisplay->setScaledContents(true);

        horizontalLayout_49->addWidget(label_truecardisplay);

        label_33 = new QLabel(widget_9);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setFont(font4);

        horizontalLayout_49->addWidget(label_33);

        label_simdisplay = new QLabel(widget_9);
        label_simdisplay->setObjectName(QStringLiteral("label_simdisplay"));
        label_simdisplay->setMinimumSize(QSize(30, 30));
        label_simdisplay->setMaximumSize(QSize(30, 30));
        label_simdisplay->setPixmap(QPixmap(QString::fromUtf8(":/images/Red.png")));
        label_simdisplay->setScaledContents(true);

        horizontalLayout_49->addWidget(label_simdisplay);


        horizontalLayout_53->addWidget(widget_9);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_53->addItem(horizontalSpacer_31);


        verticalLayout_47->addLayout(horizontalLayout_53);

        horizontalLayout_52 = new QHBoxLayout();
        horizontalLayout_52->setObjectName(QStringLiteral("horizontalLayout_52"));
        label_34 = new QLabel(widget_12);
        label_34->setObjectName(QStringLiteral("label_34"));

        horizontalLayout_52->addWidget(label_34);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_52->addItem(horizontalSpacer_30);


        verticalLayout_47->addLayout(horizontalLayout_52);

        textEdit_odomData = new QTextEdit(widget_12);
        textEdit_odomData->setObjectName(QStringLiteral("textEdit_odomData"));

        verticalLayout_47->addWidget(textEdit_odomData);


        horizontalLayout_54->addWidget(widget_12);

        widget_10 = new QWidget(tab_6);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        verticalLayout_46 = new QVBoxLayout(widget_10);
        verticalLayout_46->setObjectName(QStringLiteral("verticalLayout_46"));
        widget_11 = new QWidget(widget_10);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setMinimumSize(QSize(350, 40));
        widget_11->setMaximumSize(QSize(350, 40));
        horizontalLayout_50 = new QHBoxLayout(widget_11);
        horizontalLayout_50->setObjectName(QStringLiteral("horizontalLayout_50"));
        label_35 = new QLabel(widget_11);
        label_35->setObjectName(QStringLiteral("label_35"));

        horizontalLayout_50->addWidget(label_35);

        lineEdit_current = new QLineEdit(widget_11);
        lineEdit_current->setObjectName(QStringLiteral("lineEdit_current"));
        lineEdit_current->setMinimumSize(QSize(45, 25));
        lineEdit_current->setMaximumSize(QSize(40, 25));
        QFont font5;
        font5.setPointSize(13);
        lineEdit_current->setFont(font5);
        lineEdit_current->setStyleSheet(QStringLiteral("color: rgb(193, 125, 17);"));

        horizontalLayout_50->addWidget(lineEdit_current);

        label_36 = new QLabel(widget_11);
        label_36->setObjectName(QStringLiteral("label_36"));

        horizontalLayout_50->addWidget(label_36);

        lineEdit_total = new QLineEdit(widget_11);
        lineEdit_total->setObjectName(QStringLiteral("lineEdit_total"));
        lineEdit_total->setMinimumSize(QSize(40, 25));
        lineEdit_total->setMaximumSize(QSize(40, 25));
        lineEdit_total->setFont(font5);
        lineEdit_total->setStyleSheet(QStringLiteral("color: rgb(245, 121, 0);"));

        horizontalLayout_50->addWidget(lineEdit_total);

        label_37 = new QLabel(widget_11);
        label_37->setObjectName(QStringLiteral("label_37"));

        horizontalLayout_50->addWidget(label_37);


        verticalLayout_46->addWidget(widget_11);

        textEdit_dis = new QTextEdit(widget_10);
        textEdit_dis->setObjectName(QStringLiteral("textEdit_dis"));
        textEdit_dis->setMinimumSize(QSize(0, 120));
        textEdit_dis->setMaximumSize(QSize(16777215, 120));

        verticalLayout_46->addWidget(textEdit_dis);

        horizontalLayout_51 = new QHBoxLayout();
        horizontalLayout_51->setObjectName(QStringLiteral("horizontalLayout_51"));
        label_38 = new QLabel(widget_10);
        label_38->setObjectName(QStringLiteral("label_38"));

        horizontalLayout_51->addWidget(label_38);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_51->addItem(horizontalSpacer_29);


        verticalLayout_46->addLayout(horizontalLayout_51);

        textEdit_odomDis = new QTextEdit(widget_10);
        textEdit_odomDis->setObjectName(QStringLiteral("textEdit_odomDis"));

        verticalLayout_46->addWidget(textEdit_odomDis);


        horizontalLayout_54->addWidget(widget_10);

        tabWidget_4->addTab(tab_6, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_45 = new QHBoxLayout(tab_3);
        horizontalLayout_45->setObjectName(QStringLiteral("horizontalLayout_45"));
        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setObjectName(QStringLiteral("horizontalLayout_38"));

        horizontalLayout_45->addLayout(horizontalLayout_38);

        widget_6 = new QWidget(tab_3);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(440, 0));
        widget_6->setMaximumSize(QSize(440, 16777215));
        verticalLayout_42 = new QVBoxLayout(widget_6);
        verticalLayout_42->setObjectName(QStringLiteral("verticalLayout_42"));
        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        btn_display_gps = new QPushButton(widget_6);
        btn_display_gps->setObjectName(QStringLiteral("btn_display_gps"));
        btn_display_gps->setMinimumSize(QSize(120, 0));
        btn_display_gps->setMaximumSize(QSize(120, 16777215));
        btn_display_gps->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:17px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:19px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_36->addWidget(btn_display_gps);

        btn_close = new QPushButton(widget_6);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        btn_close->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:17px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:19px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_36->addWidget(btn_close);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_36->addItem(horizontalSpacer_21);


        verticalLayout_42->addLayout(horizontalLayout_36);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setObjectName(QStringLiteral("horizontalLayout_40"));
        verticalLayout_43 = new QVBoxLayout();
        verticalLayout_43->setObjectName(QStringLiteral("verticalLayout_43"));
        label_27 = new QLabel(widget_6);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setMinimumSize(QSize(0, 25));
        label_27->setMaximumSize(QSize(16777215, 25));

        verticalLayout_43->addWidget(label_27);

        get_longitude = new QLineEdit(widget_6);
        get_longitude->setObjectName(QStringLiteral("get_longitude"));
        get_longitude->setMinimumSize(QSize(165, 60));
        get_longitude->setMaximumSize(QSize(165, 60));
        get_longitude->setFont(font);

        verticalLayout_43->addWidget(get_longitude);


        horizontalLayout_40->addLayout(verticalLayout_43);

        verticalLayout_44 = new QVBoxLayout();
        verticalLayout_44->setObjectName(QStringLiteral("verticalLayout_44"));
        label_30 = new QLabel(widget_6);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setMinimumSize(QSize(0, 25));
        label_30->setMaximumSize(QSize(16777215, 25));

        verticalLayout_44->addWidget(label_30);

        get_latitude = new QLineEdit(widget_6);
        get_latitude->setObjectName(QStringLiteral("get_latitude"));
        get_latitude->setMinimumSize(QSize(165, 60));
        get_latitude->setMaximumSize(QSize(165, 60));
        get_latitude->setFont(font);

        verticalLayout_44->addWidget(get_latitude);


        horizontalLayout_40->addLayout(verticalLayout_44);

        verticalLayout_45 = new QVBoxLayout();
        verticalLayout_45->setObjectName(QStringLiteral("verticalLayout_45"));
        label_12 = new QLabel(widget_6);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(0, 25));
        label_12->setMaximumSize(QSize(16777215, 25));

        verticalLayout_45->addWidget(label_12);

        get_status = new QLineEdit(widget_6);
        get_status->setObjectName(QStringLiteral("get_status"));
        get_status->setMinimumSize(QSize(65, 60));
        get_status->setMaximumSize(QSize(65, 60));
        QFont font6;
        font6.setPointSize(20);
        get_status->setFont(font6);

        verticalLayout_45->addWidget(get_status);


        horizontalLayout_40->addLayout(verticalLayout_45);


        verticalLayout_42->addLayout(horizontalLayout_40);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        label_32 = new QLabel(widget_6);
        label_32->setObjectName(QStringLiteral("label_32"));

        horizontalLayout_37->addWidget(label_32);

        textEdit_gpsMsg = new QTextEdit(widget_6);
        textEdit_gpsMsg->setObjectName(QStringLiteral("textEdit_gpsMsg"));
        textEdit_gpsMsg->setMinimumSize(QSize(340, 80));
        textEdit_gpsMsg->setMaximumSize(QSize(340, 80));
        textEdit_gpsMsg->setFont(font5);

        horizontalLayout_37->addWidget(textEdit_gpsMsg);


        verticalLayout_42->addLayout(horizontalLayout_37);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setObjectName(QStringLiteral("horizontalLayout_39"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_39->addItem(horizontalSpacer_14);

        btn_savegps = new QPushButton(widget_6);
        btn_savegps->setObjectName(QStringLiteral("btn_savegps"));
        btn_savegps->setMinimumSize(QSize(180, 40));
        btn_savegps->setMaximumSize(QSize(180, 40));
        QFont font7;
        btn_savegps->setFont(font7);
        btn_savegps->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:19px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    background-color: ;\n"
"	background-color: rgb(248, 218, 179);\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:22px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_39->addWidget(btn_savegps);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_39->addItem(horizontalSpacer_15);


        verticalLayout_42->addLayout(horizontalLayout_39);


        horizontalLayout_45->addWidget(widget_6);

        verticalLayout_41 = new QVBoxLayout();
        verticalLayout_41->setObjectName(QStringLiteral("verticalLayout_41"));
        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setObjectName(QStringLiteral("horizontalLayout_44"));
        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_44->addItem(horizontalSpacer_24);

        label_31 = new QLabel(tab_3);
        label_31->setObjectName(QStringLiteral("label_31"));

        horizontalLayout_44->addWidget(label_31);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_44->addItem(horizontalSpacer_23);


        verticalLayout_41->addLayout(horizontalLayout_44);

        textEdit_gps_data = new QTextEdit(tab_3);
        textEdit_gps_data->setObjectName(QStringLiteral("textEdit_gps_data"));

        verticalLayout_41->addWidget(textEdit_gps_data);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_8);

        btn_display_data = new QPushButton(tab_3);
        btn_display_data->setObjectName(QStringLiteral("btn_display_data"));
        btn_display_data->setMinimumSize(QSize(150, 0));
        btn_display_data->setMaximumSize(QSize(150, 16777215));
        btn_display_data->setStyleSheet(QLatin1String("QPushButton { \n"
"    color: rgb(1, 84, 161) ;\n"
"    font-size:17px;\n"
"    width:60px;\n"
"	height:30px;\n"
"    border:none;\n"
"}\n"
"QPushButton:hover{\n"
"     color: rgb(1, 84, 161) ;\n"
"     font-size:19px;\n"
"}\n"
"QPushButton:pressed{\n"
"	color: rgb(255, 26, 68) ;\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));

        horizontalLayout_29->addWidget(btn_display_data);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_20);


        verticalLayout_41->addLayout(horizontalLayout_29);


        horizontalLayout_45->addLayout(verticalLayout_41);

        tabWidget_4->addTab(tab_3, QString());
        tab_13 = new QWidget();
        tab_13->setObjectName(QStringLiteral("tab_13"));
        btn_test = new QPushButton(tab_13);
        btn_test->setObjectName(QStringLiteral("btn_test"));
        btn_test->setGeometry(QRect(100, 240, 89, 25));
        textEdit_test = new QTextEdit(tab_13);
        textEdit_test->setObjectName(QStringLiteral("textEdit_test"));
        textEdit_test->setGeometry(QRect(20, 20, 591, 211));
        tabWidget_4->addTab(tab_13, QString());

        verticalLayout_22->addWidget(tabWidget_4);

        tab_manager->addTab(tab_map, QString());
        tab_RVIZ = new QWidget();
        tab_RVIZ->setObjectName(QStringLiteral("tab_RVIZ"));
        verticalLayout_25 = new QVBoxLayout(tab_RVIZ);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        set_start_btn = new QPushButton(tab_RVIZ);
        set_start_btn->setObjectName(QStringLiteral("set_start_btn"));
        set_start_btn->setMinimumSize(QSize(150, 0));
        set_start_btn->setMaximumSize(QSize(150, 16777215));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/classes/SetInitialPose.png"), QSize(), QIcon::Normal, QIcon::Off);
        set_start_btn->setIcon(icon2);

        horizontalLayout_12->addWidget(set_start_btn);

        set_goal_btn = new QPushButton(tab_RVIZ);
        set_goal_btn->setObjectName(QStringLiteral("set_goal_btn"));
        set_goal_btn->setMinimumSize(QSize(150, 0));
        set_goal_btn->setMaximumSize(QSize(150, 16777215));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/classes/SetGoal.png"), QSize(), QIcon::Normal, QIcon::Off);
        set_goal_btn->setIcon(icon3);

        horizontalLayout_12->addWidget(set_goal_btn);

        distance_measure_btn = new QPushButton(tab_RVIZ);
        distance_measure_btn->setObjectName(QStringLiteral("distance_measure_btn"));
        distance_measure_btn->setMinimumSize(QSize(150, 0));
        distance_measure_btn->setMaximumSize(QSize(150, 16777215));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/class/images/classes/Measure.svg"), QSize(), QIcon::Normal, QIcon::Off);
        distance_measure_btn->setIcon(icon4);

        horizontalLayout_12->addWidget(distance_measure_btn);


        verticalLayout_24->addLayout(horizontalLayout_12);

        Layout_rviz = new QVBoxLayout();
        Layout_rviz->setObjectName(QStringLiteral("Layout_rviz"));

        verticalLayout_24->addLayout(Layout_rviz);

        verticalLayout_24->setStretch(0, 1);
        verticalLayout_24->setStretch(1, 20);

        verticalLayout_25->addLayout(verticalLayout_24);

        tab_manager->addTab(tab_RVIZ, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_14 = new QVBoxLayout(tab_4);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        tabWidget_2 = new QTabWidget(tab_4);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setMinimumSize(QSize(0, 0));
        tabWidget_2->setMaximumSize(QSize(16777215, 16777000));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        verticalLayout_17 = new QVBoxLayout(tab_7);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_RawImage = new QLabel(tab_7);
        label_RawImage->setObjectName(QStringLiteral("label_RawImage"));
        label_RawImage->setMinimumSize(QSize(320, 180));
        label_RawImage->setMaximumSize(QSize(1280, 720));
        label_RawImage->setStyleSheet(QStringLiteral("border:1px solid black"));

        verticalLayout_17->addWidget(label_RawImage);

        btn_DiaplayRawImage = new QPushButton(tab_7);
        btn_DiaplayRawImage->setObjectName(QStringLiteral("btn_DiaplayRawImage"));
        btn_DiaplayRawImage->setMinimumSize(QSize(120, 0));
        btn_DiaplayRawImage->setMaximumSize(QSize(120, 16777215));

        verticalLayout_17->addWidget(btn_DiaplayRawImage);

        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        verticalLayout_16 = new QVBoxLayout(tab_8);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        label_PCLImage = new QLabel(tab_8);
        label_PCLImage->setObjectName(QStringLiteral("label_PCLImage"));
        label_PCLImage->setMinimumSize(QSize(320, 180));
        label_PCLImage->setMaximumSize(QSize(1280, 720));
        label_PCLImage->setStyleSheet(QStringLiteral("border:1px solid black"));

        verticalLayout_16->addWidget(label_PCLImage);

        btn_DisplayPCLImage = new QPushButton(tab_8);
        btn_DisplayPCLImage->setObjectName(QStringLiteral("btn_DisplayPCLImage"));
        btn_DisplayPCLImage->setMinimumSize(QSize(120, 0));
        btn_DisplayPCLImage->setMaximumSize(QSize(120, 16777215));

        verticalLayout_16->addWidget(btn_DisplayPCLImage);

        tabWidget_2->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        verticalLayout_13 = new QVBoxLayout(tab_9);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        label_FusioImage = new QLabel(tab_9);
        label_FusioImage->setObjectName(QStringLiteral("label_FusioImage"));
        label_FusioImage->setMinimumSize(QSize(320, 180));
        label_FusioImage->setMaximumSize(QSize(1280, 720));
        label_FusioImage->setStyleSheet(QStringLiteral("border:1px solid black"));

        verticalLayout_13->addWidget(label_FusioImage);

        btn_DisplayFusionImage = new QPushButton(tab_9);
        btn_DisplayFusionImage->setObjectName(QStringLiteral("btn_DisplayFusionImage"));
        btn_DisplayFusionImage->setMinimumSize(QSize(120, 0));
        btn_DisplayFusionImage->setMaximumSize(QSize(120, 16777215));

        verticalLayout_13->addWidget(btn_DisplayFusionImage);

        tabWidget_2->addTab(tab_9, QString());

        verticalLayout_14->addWidget(tabWidget_2);

        info_textEdit = new QTextEdit(tab_4);
        info_textEdit->setObjectName(QStringLiteral("info_textEdit"));
        info_textEdit->setMinimumSize(QSize(0, 40));
        info_textEdit->setMaximumSize(QSize(16777215, 40));
        info_textEdit->setStyleSheet(QStringLiteral("background-color: rgb(50, 3, 3);"));

        verticalLayout_14->addWidget(info_textEdit);

        frame_4 = new QFrame(tab_4);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_15 = new QVBoxLayout(frame_4);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_16 = new QLabel(frame_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setStyleSheet(QStringLiteral("color: rgb(52, 101, 164);"));

        horizontalLayout_15->addWidget(label_16);

        horizontalSpacer_6 = new QSpacerItem(120, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_6);

        enable_mouse_pushButton = new QPushButton(frame_4);
        enable_mouse_pushButton->setObjectName(QStringLiteral("enable_mouse_pushButton"));

        horizontalLayout_15->addWidget(enable_mouse_pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_2);

        measure_checkBox = new QCheckBox(frame_4);
        measure_checkBox->setObjectName(QStringLiteral("measure_checkBox"));

        horizontalLayout_15->addWidget(measure_checkBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_5);

        label_41 = new QLabel(frame_4);
        label_41->setObjectName(QStringLiteral("label_41"));

        horizontalLayout_15->addWidget(label_41);

        measure_width_lineEdit = new QLineEdit(frame_4);
        measure_width_lineEdit->setObjectName(QStringLiteral("measure_width_lineEdit"));

        horizontalLayout_15->addWidget(measure_width_lineEdit);

        label_42 = new QLabel(frame_4);
        label_42->setObjectName(QStringLiteral("label_42"));

        horizontalLayout_15->addWidget(label_42);

        measure_height_lineEdit = new QLineEdit(frame_4);
        measure_height_lineEdit->setObjectName(QStringLiteral("measure_height_lineEdit"));

        horizontalLayout_15->addWidget(measure_height_lineEdit);

        label_43 = new QLabel(frame_4);
        label_43->setObjectName(QStringLiteral("label_43"));

        horizontalLayout_15->addWidget(label_43);

        measure_distance_lineEdit = new QLineEdit(frame_4);
        measure_distance_lineEdit->setObjectName(QStringLiteral("measure_distance_lineEdit"));

        horizontalLayout_15->addWidget(measure_distance_lineEdit);


        verticalLayout_15->addLayout(horizontalLayout_15);


        verticalLayout_14->addWidget(frame_4);

        tab_manager->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        horizontalLayout_27 = new QHBoxLayout(tab_5);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        verticalLayout_40 = new QVBoxLayout();
        verticalLayout_40->setObjectName(QStringLiteral("verticalLayout_40"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        btn_interact = new QPushButton(tab_5);
        btn_interact->setObjectName(QStringLiteral("btn_interact"));
        btn_interact->setMaximumSize(QSize(150, 16777215));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/class/images/classes/Interact.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_interact->setIcon(icon5);

        horizontalLayout_24->addWidget(btn_interact);

        label_7 = new QLabel(tab_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font8;
        font8.setPointSize(21);
        label_7->setFont(font8);

        horizontalLayout_24->addWidget(label_7);


        verticalLayout_40->addLayout(horizontalLayout_24);

        frame_3 = new QFrame(tab_5);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(0, 0));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_30 = new QVBoxLayout(frame_3);
        verticalLayout_30->setObjectName(QStringLiteral("verticalLayout_30"));
        verticalLayout_rviz_obs = new QVBoxLayout();
        verticalLayout_rviz_obs->setObjectName(QStringLiteral("verticalLayout_rviz_obs"));

        verticalLayout_30->addLayout(verticalLayout_rviz_obs);

        widget = new QWidget(frame_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(660, 300));
        widget->setMaximumSize(QSize(16777215, 300));
        verticalLayout_28 = new QVBoxLayout(widget);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        verticalLayout_37 = new QVBoxLayout();
        verticalLayout_37->setObjectName(QStringLiteral("verticalLayout_37"));
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        label_19 = new QLabel(widget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(20, 0));
        label_19->setMaximumSize(QSize(20, 16777215));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/class/images/classes/Displays.svg")));

        horizontalLayout_31->addWidget(label_19);

        label_20 = new QLabel(widget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(200, 0));
        label_20->setMaximumSize(QSize(1000, 20));

        horizontalLayout_31->addWidget(label_20);


        verticalLayout_37->addLayout(horizontalLayout_31);

        treeWidget_obstacles = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        treeWidget_obstacles->setHeaderItem(__qtreewidgetitem1);
        treeWidget_obstacles->setObjectName(QStringLiteral("treeWidget_obstacles"));
        treeWidget_obstacles->setMinimumSize(QSize(200, 0));
        treeWidget_obstacles->setMaximumSize(QSize(1000, 300));
        treeWidget_obstacles->setStyleSheet(QLatin1String("QTreeView::item {\n"
"        width:200px\n"
"    }"));

        verticalLayout_37->addWidget(treeWidget_obstacles);


        horizontalLayout_34->addLayout(verticalLayout_37);

        verticalLayout_39 = new QVBoxLayout();
        verticalLayout_39->setObjectName(QStringLiteral("verticalLayout_39"));
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setObjectName(QStringLiteral("verticalLayout_36"));
        checkBox_tip = new QCheckBox(widget);
        checkBox_tip->setObjectName(QStringLiteral("checkBox_tip"));

        verticalLayout_36->addWidget(checkBox_tip);

        label_22 = new QLabel(widget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font1);
        label_22->setStyleSheet(QStringLiteral("color: rgb(32, 74, 135);"));

        verticalLayout_36->addWidget(label_22);


        horizontalLayout_33->addLayout(verticalLayout_36);

        label_obstacle_display = new QLabel(widget);
        label_obstacle_display->setObjectName(QStringLiteral("label_obstacle_display"));
        label_obstacle_display->setMinimumSize(QSize(100, 100));
        label_obstacle_display->setMaximumSize(QSize(100, 100));
        label_obstacle_display->setPixmap(QPixmap(QString::fromUtf8(":/images/Green.png")));
        label_obstacle_display->setScaledContents(true);

        horizontalLayout_33->addWidget(label_obstacle_display);


        verticalLayout_39->addLayout(horizontalLayout_33);

        verticalLayout_38 = new QVBoxLayout();
        verticalLayout_38->setObjectName(QStringLiteral("verticalLayout_38"));
        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        label_24 = new QLabel(widget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMinimumSize(QSize(0, 20));
        label_24->setMaximumSize(QSize(16777215, 20));
        label_24->setFont(font3);

        horizontalLayout_32->addWidget(label_24);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_32->addWidget(lineEdit);


        verticalLayout_38->addLayout(horizontalLayout_32);

        verticalLayout_35 = new QVBoxLayout();
        verticalLayout_35->setObjectName(QStringLiteral("verticalLayout_35"));
        textEdit_obstacle = new QTextEdit(widget);
        textEdit_obstacle->setObjectName(QStringLiteral("textEdit_obstacle"));
        textEdit_obstacle->setMinimumSize(QSize(0, 80));
        textEdit_obstacle->setMaximumSize(QSize(16777215, 80));
        textEdit_obstacle->setFont(font6);

        verticalLayout_35->addWidget(textEdit_obstacle);

        label_21 = new QLabel(widget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(0, 20));
        label_21->setMaximumSize(QSize(16777215, 20));
        label_21->setFont(font3);

        verticalLayout_35->addWidget(label_21);


        verticalLayout_38->addLayout(verticalLayout_35);


        verticalLayout_39->addLayout(verticalLayout_38);


        horizontalLayout_34->addLayout(verticalLayout_39);


        verticalLayout_28->addLayout(horizontalLayout_34);


        verticalLayout_30->addWidget(widget);


        verticalLayout_40->addWidget(frame_3);


        horizontalLayout_27->addLayout(verticalLayout_40);

        verticalLayout_34 = new QVBoxLayout();
        verticalLayout_34->setObjectName(QStringLiteral("verticalLayout_34"));
        label_9 = new QLabel(tab_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font8);

        verticalLayout_34->addWidget(label_9);

        frame_5 = new QFrame(tab_5);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setMinimumSize(QSize(250, 850));
        frame_5->setMaximumSize(QSize(250, 1000));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_31 = new QVBoxLayout(frame_5);
        verticalLayout_31->setObjectName(QStringLiteral("verticalLayout_31"));
        label_10 = new QLabel(frame_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_31->addWidget(label_10);

        lineEdit_sonar1 = new QLineEdit(frame_5);
        lineEdit_sonar1->setObjectName(QStringLiteral("lineEdit_sonar1"));
        lineEdit_sonar1->setMinimumSize(QSize(0, 60));
        lineEdit_sonar1->setMaximumSize(QSize(16777215, 100));

        verticalLayout_31->addWidget(lineEdit_sonar1);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        btn_sonar_startmeasure = new QPushButton(frame_5);
        btn_sonar_startmeasure->setObjectName(QStringLiteral("btn_sonar_startmeasure"));
        btn_sonar_startmeasure->setMinimumSize(QSize(100, 35));
        btn_sonar_startmeasure->setMaximumSize(QSize(100, 35));

        horizontalLayout_30->addWidget(btn_sonar_startmeasure);

        btn_sonar_stopmeasure = new QPushButton(frame_5);
        btn_sonar_stopmeasure->setObjectName(QStringLiteral("btn_sonar_stopmeasure"));
        btn_sonar_stopmeasure->setMinimumSize(QSize(0, 35));
        btn_sonar_stopmeasure->setMaximumSize(QSize(100, 35));

        horizontalLayout_30->addWidget(btn_sonar_stopmeasure);


        verticalLayout_31->addLayout(horizontalLayout_30);

        label_28 = new QLabel(frame_5);
        label_28->setObjectName(QStringLiteral("label_28"));
        QFont font9;
        font9.setPointSize(14);
        label_28->setFont(font9);
        label_28->setStyleSheet(QStringLiteral("color: rgb(32, 74, 135);"));

        verticalLayout_31->addWidget(label_28);

        widget_2 = new QWidget(frame_5);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 150));
        widget_2->setMaximumSize(QSize(16777215, 150));
        horizontalLayout_28 = new QHBoxLayout(widget_2);
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        label_sonar_display = new QLabel(widget_2);
        label_sonar_display->setObjectName(QStringLiteral("label_sonar_display"));
        label_sonar_display->setMinimumSize(QSize(100, 100));
        label_sonar_display->setMaximumSize(QSize(100, 100));
        label_sonar_display->setPixmap(QPixmap(QString::fromUtf8(":/images/Green.png")));
        label_sonar_display->setScaledContents(true);

        horizontalLayout_28->addWidget(label_sonar_display);


        verticalLayout_31->addWidget(widget_2);

        textEdit_tip = new QTextEdit(frame_5);
        textEdit_tip->setObjectName(QStringLiteral("textEdit_tip"));
        textEdit_tip->setMinimumSize(QSize(0, 0));
        textEdit_tip->setMaximumSize(QSize(16777215, 300));
        textEdit_tip->setFont(font6);

        verticalLayout_31->addWidget(textEdit_tip);

        label_18 = new QLabel(frame_5);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(0, 50));
        label_18->setMaximumSize(QSize(16777215, 50));
        label_18->setFont(font6);

        verticalLayout_31->addWidget(label_18);


        verticalLayout_34->addWidget(frame_5);


        horizontalLayout_27->addLayout(verticalLayout_34);

        horizontalLayout_27->setStretch(0, 3);
        horizontalLayout_27->setStretch(1, 1);
        tab_manager->addTab(tab_5, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName(QStringLiteral("tab_15"));
        verticalLayout_52 = new QVBoxLayout(tab_15);
        verticalLayout_52->setObjectName(QStringLiteral("verticalLayout_52"));
        widget_goal = new QChartView(tab_15);
        widget_goal->setObjectName(QStringLiteral("widget_goal"));

        verticalLayout_52->addWidget(widget_goal);

        tab_manager->addTab(tab_15, QString());

        gridLayout_2->addWidget(tab_manager, 0, 0, 2, 1);

        gridLayout_2->setColumnStretch(0, 5);

        verticalLayout_49->addLayout(gridLayout_2);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1368, 28));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Preferences);
        menu_File->addSeparator();
        menu_File->addAction(actionAbout);
        menu_File->addAction(actionAbout_Qt);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        tabWidget->setCurrentIndex(0);
        tab_manager->setCurrentIndex(0);
        tabWidget_control->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(1);
        tabWidget_4->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", Q_NULLPTR));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindowDesign", "Ros Master", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindowDesign", "\344\270\273\350\212\202\347\202\271\345\234\260\345\235\200(ROS Master)", Q_NULLPTR));
        line_edit_master->setText(QApplication::translate("MainWindowDesign", "http://192.168.1.2:11311/", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindowDesign", "\346\234\254\346\234\272IP\345\234\260\345\235\200(Ros IP)", Q_NULLPTR));
        line_edit_host->setText(QApplication::translate("MainWindowDesign", "192.168.1.67", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindowDesign", "\350\256\241\347\256\227\346\234\272\345\220\215(Ros Hostname)", Q_NULLPTR));
        line_edit_topic->setText(QApplication::translate("MainWindowDesign", "unused", Q_NULLPTR));
        checkbox_use_environment->setText(QApplication::translate("MainWindowDesign", "\344\275\277\347\224\250\347\216\257\345\242\203\345\217\230\351\207\217(~/.bashrc)", Q_NULLPTR));
        checkbox_remember_settings->setText(QApplication::translate("MainWindowDesign", "\346\211\223\345\274\200\350\275\257\344\273\266\346\227\266\350\207\252\345\212\250\350\277\236\346\216\245ROS master", Q_NULLPTR));
        btn_quit->setText(QApplication::translate("MainWindowDesign", "\346\226\255\345\274\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btn_connect->setToolTip(QApplication::translate("MainWindowDesign", "Set the target to the current joint trajectory state.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btn_connect->setStatusTip(QApplication::translate("MainWindowDesign", "Clear all waypoints and set the target to the current joint trajectory state.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        btn_connect->setText(QApplication::translate("MainWindowDesign", "\350\277\236\346\216\245", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindowDesign", "\350\257\267\351\200\211\346\213\251\344\273\277\347\234\237\350\277\230\346\230\257\345\256\236\350\275\246\357\274\232", Q_NULLPTR));
        btn_changeCarMode->setText(QApplication::translate("MainWindowDesign", "\345\210\207\346\215\242\346\250\241\345\274\217", Q_NULLPTR));
        btn_simulation->setText(QApplication::translate("MainWindowDesign", "\344\273\277\347\234\237", Q_NULLPTR));
        btn_trueCar->setText(QApplication::translate("MainWindowDesign", "\345\256\236\350\275\246", Q_NULLPTR));
        label_simulation_display->setText(QString());
        label_truecar_display->setText(QString());
        groupBox_scout->setTitle(QApplication::translate("MainWindowDesign", "\346\234\272\345\231\250\344\272\272\346\211\213\345\212\250\346\216\247\345\210\266", Q_NULLPTR));
        pushButton_u->setText(QApplication::translate("MainWindowDesign", "u", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        pushButton_u->setShortcut(QApplication::translate("MainWindowDesign", "U", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pushButton_i->setText(QApplication::translate("MainWindowDesign", "i", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        pushButton_i->setShortcut(QApplication::translate("MainWindowDesign", "I", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pushButton_o->setText(QApplication::translate("MainWindowDesign", "o", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        pushButton_o->setShortcut(QApplication::translate("MainWindowDesign", "O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pushButton_j->setText(QApplication::translate("MainWindowDesign", "j", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        pushButton_j->setShortcut(QApplication::translate("MainWindowDesign", "J", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        checkBox_is_all->setText(QApplication::translate("MainWindowDesign", "\345\205\250\345\220\221\350\275\256", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        checkBox_is_all->setShortcut(QApplication::translate("MainWindowDesign", "K", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pushButton_l->setText(QApplication::translate("MainWindowDesign", "l", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        pushButton_l->setShortcut(QApplication::translate("MainWindowDesign", "L", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pushButton_n->setText(QApplication::translate("MainWindowDesign", "m", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        pushButton_n->setShortcut(QApplication::translate("MainWindowDesign", "M", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pushButton_m->setText(QApplication::translate("MainWindowDesign", ",", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        pushButton_m->setShortcut(QApplication::translate("MainWindowDesign", ",", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pushButton_br->setText(QApplication::translate("MainWindowDesign", ".", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        pushButton_br->setShortcut(QApplication::translate("MainWindowDesign", ".", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        label_4->setText(QApplication::translate("MainWindowDesign", "\347\272\277\351\200\237\345\272\246\357\274\232", Q_NULLPTR));
        label_linera->setText(QApplication::translate("MainWindowDesign", "0", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindowDesign", "\350\247\222\351\200\237\345\272\246\357\274\232", Q_NULLPTR));
        label_raw->setText(QApplication::translate("MainWindowDesign", "0", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindowDesign", "\345\237\272\346\234\254\346\216\247\345\210\266", Q_NULLPTR));
        label_15->setText(QString());
        label_13->setText(QApplication::translate("MainWindowDesign", "Display", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_14), QApplication::translate("MainWindowDesign", "rviz", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindowDesign", "\346\277\200\345\205\211\351\233\267\350\276\276", Q_NULLPTR));
        laser_btn->setText(QApplication::translate("MainWindowDesign", "\345\220\257\345\212\250\351\233\267\350\276\276", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindowDesign", "\345\277\253\346\215\267\346\214\207\344\273\244", Q_NULLPTR));
        label_6->setText(QString());
        label_8->setText(QApplication::translate("MainWindowDesign", "\346\234\272\345\231\250\344\272\272\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_statue_text->setText(QApplication::translate("MainWindowDesign", "\347\246\273\347\272\277", Q_NULLPTR));
        label_robot_staue_img->setText(QString());
        label_29->setText(QApplication::translate("MainWindowDesign", "\350\257\235\351\242\230\345\210\227\350\241\250\357\274\232", Q_NULLPTR));
        refreash_topic_btn->setText(QApplication::translate("MainWindowDesign", "\345\210\267\346\226\260", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_16), QApplication::translate("MainWindowDesign", "\350\257\235\351\242\230\344\277\241\346\201\257", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_17), QApplication::translate("MainWindowDesign", "\345\205\266\345\256\203", Q_NULLPTR));
        tabWidget_control->setTabText(tabWidget_control->indexOf(tab_18), QApplication::translate("MainWindowDesign", "\346\266\210\346\201\257\345\233\236\346\230\276\345\215\225\345\205\203", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindowDesign", "\350\212\202\347\202\271\345\274\200\345\220\257", Q_NULLPTR));
        btn_node1->setText(QApplication::translate("MainWindowDesign", "\346\211\223\345\274\200", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindowDesign", "\350\212\202\347\202\271\345\274\200\345\220\257", Q_NULLPTR));
        btn_node2->setText(QApplication::translate("MainWindowDesign", "\346\211\223\345\274\200", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindowDesign", "\350\212\202\347\202\271\345\274\200\345\220\257", Q_NULLPTR));
        btn_node3->setText(QApplication::translate("MainWindowDesign", "\346\211\223\345\274\200", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("MainWindowDesign", "\350\212\202\347\202\271\345\274\200\345\220\257", Q_NULLPTR));
        btn_node4->setText(QApplication::translate("MainWindowDesign", "\346\211\223\345\274\200", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("MainWindowDesign", "\350\212\202\347\202\271\345\274\200\345\220\257", Q_NULLPTR));
        btn_node5->setText(QApplication::translate("MainWindowDesign", "\346\211\223\345\274\200", Q_NULLPTR));
        groupBox_11->setTitle(QApplication::translate("MainWindowDesign", "\350\212\202\347\202\271\345\274\200\345\220\257", Q_NULLPTR));
        btn_node6->setText(QApplication::translate("MainWindowDesign", "\346\211\223\345\274\200", Q_NULLPTR));
        tabWidget_control->setTabText(tabWidget_control->indexOf(tab_10), QApplication::translate("MainWindowDesign", "\350\277\234\347\250\213\346\216\247\345\210\266\345\215\225\345\205\203", Q_NULLPTR));
        tab_manager->setTabText(tab_manager->indexOf(tab_status), QApplication::translate("MainWindowDesign", "\351\200\232\344\277\241\350\277\236\346\216\245", Q_NULLPTR));
        label_map->setText(QString());
        label_11->setText(QString());
        btn_loadmap->setText(QApplication::translate("MainWindowDesign", "\345\212\240\350\275\275\345\234\260\345\233\276", Q_NULLPTR));
        btn_closemap->setText(QApplication::translate("MainWindowDesign", "\345\205\263\351\227\255\345\234\260\345\233\276", Q_NULLPTR));
        btn_changeMode->setText(QApplication::translate("MainWindowDesign", "\345\210\207\346\215\242\345\274\200\345\217\221\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
        btn_project->setText(QApplication::translate("MainWindowDesign", "\351\241\271\347\233\256\346\250\241\345\274\217", Q_NULLPTR));
        btn_develop->setText(QApplication::translate("MainWindowDesign", "\345\274\200\345\217\221\346\250\241\345\274\217", Q_NULLPTR));
        btn_getSP->setText(QApplication::translate("MainWindowDesign", "\346\216\245\346\224\266\350\265\267\347\202\271", Q_NULLPTR));
        btn_getTP->setText(QApplication::translate("MainWindowDesign", "\346\213\276\345\217\226\347\273\210\347\202\271", Q_NULLPTR));
        btn_pitch->setText(QApplication::translate("MainWindowDesign", "\346\213\276\345\217\226", Q_NULLPTR));
        btn_plan->setText(QApplication::translate("MainWindowDesign", "\350\247\204\345\210\222", Q_NULLPTR));
        btn_clear->setText(QApplication::translate("MainWindowDesign", "\346\270\205\351\231\244", Q_NULLPTR));
        btn_draw->setText(QApplication::translate("MainWindowDesign", "\347\224\273\347\272\277", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindowDesign", "\350\265\267\347\202\271\343\200\201\347\273\210\347\202\271\347\273\217\347\272\254\345\272\246\345\235\220\346\240\207\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindowDesign", "\351\253\230\345\276\267\345\235\220\346\240\207\347\263\273\344\270\213\345\205\263\351\224\256\350\267\257\345\276\204\347\202\271\347\273\217\347\272\254\345\272\246\345\235\220\346\240\207\357\274\232", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindowDesign", "GPS\345\235\220\346\240\207\347\263\273\344\270\213\347\232\204\345\205\263\351\224\256\350\267\257\345\276\204\347\202\271\347\273\217\347\272\254\345\272\246\345\235\220\346\240\207\357\274\232", Q_NULLPTR));
        get_load_message->setText(QApplication::translate("MainWindowDesign", "\350\216\267\345\217\226\350\275\250\350\277\271", Q_NULLPTR));
        btn_clear_path->setText(QApplication::translate("MainWindowDesign", "\346\270\205\351\231\244\346\230\276\347\244\272", Q_NULLPTR));
        btn_chooseGPS->setText(QApplication::translate("MainWindowDesign", "\345\214\271\351\205\215\347\233\256\346\240\207\347\202\271", Q_NULLPTR));
        btn_clear_path_2->setText(QApplication::translate("MainWindowDesign", "\346\270\205\351\231\244\346\230\276\347\244\272", Q_NULLPTR));
        btn_send_path->setText(QApplication::translate("MainWindowDesign", "\344\270\213\345\217\221\350\275\250\350\277\271", Q_NULLPTR));
        btn_clear_path_ros->setText(QApplication::translate("MainWindowDesign", "\346\270\205\351\231\244\346\230\276\347\244\272", Q_NULLPTR));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_12), QApplication::translate("MainWindowDesign", "\346\211\213\345\212\250\350\247\204\345\210\222", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindowDesign", "\345\256\236\350\275\246", Q_NULLPTR));
        label_truecardisplay->setText(QString());
        label_33->setText(QApplication::translate("MainWindowDesign", "\344\273\277\347\234\237", Q_NULLPTR));
        label_simdisplay->setText(QString());
        label_34->setText(QApplication::translate("MainWindowDesign", "\344\275\215\345\247\277\344\277\241\346\201\257\345\256\236\346\227\266\345\233\236\346\230\276\357\274\232", Q_NULLPTR));
        label_35->setText(QApplication::translate("MainWindowDesign", "\345\275\223\345\211\215\346\230\257\347\254\254", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindowDesign", "\344\270\252\347\233\256\346\240\207\347\202\271\357\274\214\345\205\261", Q_NULLPTR));
        label_37->setText(QApplication::translate("MainWindowDesign", "\344\270\252\347\233\256\346\240\207\347\202\271", Q_NULLPTR));
        label_38->setText(QApplication::translate("MainWindowDesign", "\350\267\235\347\246\273\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_6), QApplication::translate("MainWindowDesign", "\345\257\274\350\210\252\346\225\260\346\215\256", Q_NULLPTR));
        btn_display_gps->setText(QApplication::translate("MainWindowDesign", "\346\230\276\347\244\272\347\273\217\347\272\254\345\272\246", Q_NULLPTR));
        btn_close->setText(QApplication::translate("MainWindowDesign", "\345\201\234\346\255\242", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindowDesign", "\345\275\223\345\211\215\347\273\217\345\272\246", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindowDesign", "\345\275\223\345\211\215\347\272\254\345\272\246", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindowDesign", "\350\247\243\347\232\204\347\212\266\346\200\201", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindowDesign", "\346\266\210\346\201\257\346\217\220\347\244\272\346\241\206", Q_NULLPTR));
        btn_savegps->setText(QApplication::translate("MainWindowDesign", "\344\277\235\345\255\230\350\207\263\346\225\260\346\215\256\345\272\223", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindowDesign", "GPS\347\202\271\351\207\207\351\233\206\346\225\260\346\215\256\345\272\223", Q_NULLPTR));
        btn_display_data->setText(QApplication::translate("MainWindowDesign", "\346\230\276\347\244\272\346\225\260\346\215\256\345\272\223\344\277\241\346\201\257", Q_NULLPTR));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_3), QApplication::translate("MainWindowDesign", "\351\207\207\351\233\206GPS", Q_NULLPTR));
        btn_test->setText(QApplication::translate("MainWindowDesign", "\346\265\213\350\257\225", Q_NULLPTR));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_13), QApplication::translate("MainWindowDesign", "\351\241\265", Q_NULLPTR));
        tab_manager->setTabText(tab_manager->indexOf(tab_map), QApplication::translate("MainWindowDesign", "\345\234\260\345\233\276\350\247\204\345\210\222", Q_NULLPTR));
        set_start_btn->setText(QApplication::translate("MainWindowDesign", "2D Pose Estimate", Q_NULLPTR));
        set_goal_btn->setText(QApplication::translate("MainWindowDesign", "2D Nav Goal", Q_NULLPTR));
        distance_measure_btn->setText(QApplication::translate("MainWindowDesign", "Distance tool", Q_NULLPTR));
        tab_manager->setTabText(tab_manager->indexOf(tab_RVIZ), QApplication::translate("MainWindowDesign", "Rviz", Q_NULLPTR));
        label_RawImage->setText(QApplication::translate("MainWindowDesign", "                                                                     \346\232\202\346\227\240\344\277\241\345\217\267\350\276\223\345\205\245\357\274\214\346\227\240\345\216\237\345\247\213\345\233\276\345\203\217\346\230\276\347\244\272\357\274\214\350\257\267\347\202\271\345\207\273\345\216\237\345\247\213\345\233\276\345\203\217\346\230\276\347\244\272\346\214\211\351\222\256\350\277\236\346\216\245\344\277\241\345\217\267\357\274\201", Q_NULLPTR));
        btn_DiaplayRawImage->setText(QApplication::translate("MainWindowDesign", "\345\216\237\345\247\213\345\233\276\345\203\217\346\230\276\347\244\272", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindowDesign", "\345\216\237\345\247\213\345\233\276\345\203\217\346\230\276\347\244\272", Q_NULLPTR));
        label_PCLImage->setText(QApplication::translate("MainWindowDesign", "                                                               \346\232\202\346\227\240\344\277\241\345\217\267\350\276\223\345\205\245\357\274\214\346\227\240\347\202\271\344\272\221\345\233\276\345\203\217\346\230\276\347\244\272\357\274\214\350\257\267\347\202\271\345\207\273\347\202\271\344\272\221\345\233\276\345\203\217\346\230\276\347\244\272\346\214\211\351\222\256\350\277\236\346\216\245\344\277\241\345\217\267\357\274\201", Q_NULLPTR));
        btn_DisplayPCLImage->setText(QApplication::translate("MainWindowDesign", "\347\202\271\344\272\221\345\233\276\345\203\217\346\230\276\347\244\272", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("MainWindowDesign", "\347\202\271\344\272\221\345\233\276\345\203\217\346\230\276\347\244\272", Q_NULLPTR));
        label_FusioImage->setText(QApplication::translate("MainWindowDesign", "                                                                   \346\232\202\346\227\240\344\277\241\345\217\267\350\276\223\345\205\245\357\274\214\346\227\240\350\236\215\345\220\210\345\233\276\345\203\217\346\230\276\347\244\272\357\274\214\350\257\267\347\202\271\345\207\273\350\236\215\345\220\210\345\233\276\345\203\217\346\230\276\347\244\272\346\214\211\351\222\256\350\277\236\346\216\245\344\277\241\345\217\267\357\274\201", Q_NULLPTR));
        btn_DisplayFusionImage->setText(QApplication::translate("MainWindowDesign", "\350\236\215\345\220\210\345\233\276\345\203\217\346\230\276\347\244\272", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QApplication::translate("MainWindowDesign", "\350\236\215\345\220\210\345\233\276\345\203\217\346\230\276\347\244\272", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindowDesign", "\350\267\235\347\246\273\346\265\213\351\207\217\346\240\217", Q_NULLPTR));
        enable_mouse_pushButton->setText(QApplication::translate("MainWindowDesign", "Enable  Mouse", Q_NULLPTR));
        measure_checkBox->setText(QApplication::translate("MainWindowDesign", "\345\274\200\345\247\213\346\265\213\351\207\217", Q_NULLPTR));
        label_41->setText(QApplication::translate("MainWindowDesign", "Width\357\274\232", Q_NULLPTR));
        label_42->setText(QApplication::translate("MainWindowDesign", "Height\357\274\232", Q_NULLPTR));
        label_43->setText(QApplication::translate("MainWindowDesign", "Distance\357\274\232", Q_NULLPTR));
        tab_manager->setTabText(tab_manager->indexOf(tab_4), QApplication::translate("MainWindowDesign", "\345\215\225\347\233\256\346\230\276\347\244\272", Q_NULLPTR));
        btn_interact->setText(QApplication::translate("MainWindowDesign", "interact", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindowDesign", "       \351\232\234\347\242\215\347\211\251\351\242\204\350\255\246\346\217\220\347\244\272", Q_NULLPTR));
        label_19->setText(QString());
        label_20->setText(QApplication::translate("MainWindowDesign", "\351\232\234\347\242\215\347\211\251\351\242\204\350\255\246RVIZ\346\230\276\347\244\272", Q_NULLPTR));
        checkBox_tip->setText(QApplication::translate("MainWindowDesign", "\345\220\257\345\212\250\351\242\204\350\255\246", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindowDesign", " \351\232\234\347\242\215\347\211\251\346\214\207\347\244\272\347\201\257\347\212\266\346\200\201 \357\274\232", Q_NULLPTR));
        label_obstacle_display->setText(QString());
        label_24->setText(QApplication::translate("MainWindowDesign", "\351\232\234\347\242\215\347\211\251\351\242\204\350\255\246\350\214\203\345\233\264(m)\357\274\232", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindowDesign", "                          \351\232\234\347\242\215\347\211\251\351\242\204\350\255\246\346\217\220\347\244\272\344\277\241\346\201\257", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindowDesign", "     \350\266\205\345\243\260\346\263\242\346\265\213\350\267\235\346\217\220\347\244\272", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindowDesign", "\350\266\205\345\243\260\346\263\242\350\267\235\347\246\273(cm)\357\274\232", Q_NULLPTR));
        btn_sonar_startmeasure->setText(QApplication::translate("MainWindowDesign", "\345\274\200\345\247\213\346\265\213\351\207\217", Q_NULLPTR));
        btn_sonar_stopmeasure->setText(QApplication::translate("MainWindowDesign", "\345\201\234\346\255\242\346\265\213\351\207\217", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindowDesign", "    \345\236\202\347\233\264\346\216\242\346\265\213\346\214\207\347\244\272\347\201\257\347\212\266\346\200\201 \357\274\232", Q_NULLPTR));
        label_sonar_display->setText(QString());
        label_18->setText(QApplication::translate("MainWindowDesign", "\351\242\204\350\255\246\346\217\220\347\244\272", Q_NULLPTR));
        tab_manager->setTabText(tab_manager->indexOf(tab_5), QApplication::translate("MainWindowDesign", "\351\242\204\350\255\246\346\217\220\347\244\272", Q_NULLPTR));
        tab_manager->setTabText(tab_manager->indexOf(tab_15), QApplication::translate("MainWindowDesign", "\351\241\265", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindowDesign", "\347\247\273\345\212\250\346\234\272\345\231\250\344\272\272\345\217\257\350\247\206\345\214\226\346\216\247\345\210\266\347\273\210\347\253\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
