#include "cr3_user.h"
#include "ui_cr3_user.h"
#include <QMovie>
#include <QTimer>
#include <QPixmap>
#include <QDebug>
#include <QRegularExpression>
#include <QString>
#include <QMessageBox>
#include <QApplication>
#include <QCoreApplication>
#include <QObject>
#include <QPropertyAnimation>
#include <QRect>
#include <QSqlQuery>
#include <QScrollBar>
#include <QDateTimeEdit>

CR3_User::CR3_User(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CR3_User)
{
    ui->setupUi(this);

    setWindowTitle("CuteRail.CR3");
    centerOnScreen();
    TicketingUI();
    InitialTheme();
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->tabWidget_3->setCurrentIndex(0);


    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->start(3000);
//    connect(timer, &QTimer::timeout, this, &CR3_User::LoginPage);


    // 로딩 움직이게 하는 코드
    QMovie *movie = new QMovie(":/img/loading_Gear.gif");
    ui->label_loading->setMovie(movie);
    movie->start();
    // QLabel의 크기를 QMovie의 프레임 크기에 맞게 조정
    ui->label_loading->setScaledContents(true); // QLabel의 크기를 QMovie의 프레임 크기에 맞게 조정하도록 설정
    ui->label_loading->setAlignment(Qt::AlignCenter); // QLabel의 내용을 중앙 정렬 (옵션)


    // 유저 아이콘 경로 설정
    QPixmap ID(":/img/id_icon2.png");
    QPixmap PW(":/img/icon_password.png");
    QPixmap signId(":/img/id_icon2.png");
    QPixmap signPw(":/img/icon_password.png");
    QPixmap signPwChk(":/img/icon_passwordChk.png");
    QPixmap signBirth(":/img/icon_birth.png");
    QPixmap signEmail(":/img/icon_email.png");
    QPixmap signSex(":/img/icon_gender.png");
    QPixmap signName(":/img/icon_name.png");
    QPixmap signPhone(":/img/icon_phone.png");
    QPixmap findidName(":/img/icon_name.png");
    QPixmap findidPhone(":/img/icon_phone.png");
    QPixmap findpwId(":/img/id_icon2.png");
    QPixmap findpwName(":/img/icon_name.png");
    QPixmap findpwPhone(":/img/icon_phone.png");
    QPixmap profileName(":/img/icon_name.png");
    QPixmap profilePhone(":/img/icon_phone.png");
    QPixmap profileEmail(":/img/icon_email.png");
    QPixmap profileId(":/img/id_icon2.png");
    QPixmap changeId(":/img/id_icon2.png");
    QPixmap changePw(":/img/icon_password.png");


    // 유저 아이콘 넓이 라벨 크기에 맞추기
    int w_ID = ui->label_loginId->width();
    int w_PW = ui->label_loginPw->width();
    int w_signId = ui->label_signId->width();
    int w_signPw = ui->label_signPw->width();
    int w_signPwChk = ui->label_signPwChk->width();
    int w_signBirth = ui->label_signBirth->width();
    int w_signEmail = ui->label_signEmail->width();
    int w_signSex = ui->label_signGender->width();
    int w_signName = ui->label_signName->width();
    int w_signPhone = ui->label_signPhone->width();
    int w_findidName = ui->label_findIdName->width();
    int w_findidPhone = ui->label_findIdPhone->width();
    int w_findpwId = ui->label_findPwId->width();
    int w_findpwName = ui->label_findPwName->width();
    int w_findpwPhone = ui->label_findPwPhone->width();
    int w_profileName = ui->label_profileName->width();
    int w_profilePhone = ui->label_profilePhone->width();
    int w_profileEmail = ui->label_profileEmail->width();
    int w_profileId = ui->label_profileId->width();
    int w_changeId = ui->label_changeId->width();
    int w_changePw = ui->label_changePw->width();


    // 유저 아이콘 높이 라벨 크기에 맞추기
    int h_ID = ui->label_loginId->height();
    int h_PW = ui->label_loginPw->height();
    int h_signId = ui->label_signId->height();
    int h_signPw = ui->label_signPw->height();
    int h_signPwChk = ui->label_signPwChk->height();
    int h_signBirth = ui->label_signBirth->height();
    int h_signEmail = ui->label_signEmail->height();
    int h_signSex = ui->label_signGender->height();
    int h_signName = ui->label_signName->height();
    int h_signPhone = ui->label_signPhone->height();
    int h_findidName = ui->label_findIdName->height();
    int h_findidPhone = ui->label_findIdPhone->height();
    int h_findpwId = ui->label_findPwId->height();
    int h_findpwName = ui->label_findPwName->height();
    int h_findpwPhone = ui->label_findPwPhone->height();
    int h_profileName = ui->label_profileName->height();
    int h_profilePhone = ui->label_profilePhone->height();
    int h_profileEmail = ui->label_profileEmail->height();
    int h_profileId = ui->label_profileId->height();
    int h_changeId = ui->label_changeId->height();
    int h_changePw = ui->label_changePw->height();


    // 유저 아이콘 넓이, 높이 라벨 크기에 맞추기 최종
    ui->label_loginId->setPixmap(ID.scaled(w_ID,h_ID,Qt::KeepAspectRatio));
    ui->label_loginId_2->setPixmap(signPhone.scaled(w_signPhone,h_signPhone,Qt::KeepAspectRatio));
    ui->label_loginPw->setPixmap(PW.scaled(w_PW,h_PW,Qt::KeepAspectRatio));
    ui->label_loginPw_2->setPixmap(PW.scaled(w_PW,h_PW,Qt::KeepAspectRatio));
    ui->label_signId->setPixmap(signId.scaled(w_signId,h_signId,Qt::KeepAspectRatio));
    ui->label_signPw->setPixmap(signPw.scaled(w_signPw,h_signPw,Qt::KeepAspectRatio));
    ui->label_signPwChk->setPixmap(signPwChk.scaled(w_signPwChk,h_signPwChk,Qt::KeepAspectRatio));
    ui->label_signBirth->setPixmap(signBirth.scaled(w_signBirth,h_signBirth,Qt::KeepAspectRatio));
    ui->label_signEmail->setPixmap(signEmail.scaled(w_signEmail,h_signEmail,Qt::KeepAspectRatio));
    ui->label_signGender->setPixmap(signSex.scaled(w_signSex,h_signSex,Qt::KeepAspectRatio));
    ui->label_signName->setPixmap(signName.scaled(w_signName,h_signName,Qt::KeepAspectRatio));
    ui->label_signPhone->setPixmap(signPhone.scaled(w_signPhone,h_signPhone,Qt::KeepAspectRatio));
    ui->label_findIdName->setPixmap(findidName.scaled(w_findidName,h_findidName,Qt::KeepAspectRatio));
    ui->label_findIdPhone->setPixmap(findidPhone.scaled(w_findidPhone,h_findidPhone,Qt::KeepAspectRatio));
    ui->label_findPwId->setPixmap(findpwId.scaled(w_findpwId,h_findpwId,Qt::KeepAspectRatio));
    ui->label_findPwName->setPixmap(findpwName.scaled(w_findpwName,h_findpwName,Qt::KeepAspectRatio));
    ui->label_findPwPhone->setPixmap(findpwPhone.scaled(w_findpwPhone,h_findpwPhone,Qt::KeepAspectRatio));
    ui->label_profileName->setPixmap(profileName.scaled(w_profileName,h_profileName,Qt::KeepAspectRatio));
    ui->label_profilePhone->setPixmap(profilePhone.scaled(w_profilePhone,h_profilePhone,Qt::KeepAspectRatio));
    ui->label_profileEmail->setPixmap(profileEmail.scaled(w_profileEmail,h_profileEmail,Qt::KeepAspectRatio));
    ui->label_profileId->setPixmap(profileId.scaled(w_profileId,h_profileId,Qt::KeepAspectRatio));
    ui->label_changeId->setPixmap(changeId.scaled(w_changeId,h_changeId,Qt::KeepAspectRatio));
    ui->label_changePw->setPixmap(changePw.scaled(w_changePw,h_changePw,Qt::KeepAspectRatio));


    // @@@@@@@@@@@@@@ 페이지 이동 @@@@@@@@@@@@@@
    QButtonGroup * login_backButton = new QButtonGroup(this);
    login_backButton->addButton(ui->pushButton_backSign);
    login_backButton->addButton(ui->pushButton_backFind);
    login_backButton->addButton(ui->pushButton_backagree);
    login_backButton->addButton(ui->pushButton_agreecancel);
    connect(login_backButton, &QButtonGroup::buttonClicked, this, &CR3_User::LoginPage);

    QButtonGroup * loginButton1 = new QButtonGroup(this);
    loginButton1->addButton(ui->pushButton_login);
    connect(loginButton1, &QButtonGroup::buttonClicked, this, &CR3_User::Login);

    QButtonGroup * loginButton2 = new QButtonGroup(this);
    loginButton2->addButton(ui->pushButton_login_2);
    connect(loginButton2, &QButtonGroup::buttonClicked, this, &CR3_User::PhoneLogin);

    QButtonGroup * signButton = new QButtonGroup(this);
    signButton->addButton(ui->pushButton_sign);
    signButton->addButton(ui->pushButton_sign_2);
    connect(signButton, &QButtonGroup::buttonClicked, this, &CR3_User::AgreePage); // 함수만 바뀜

    QButtonGroup * findButton = new QButtonGroup(this);
    findButton->addButton(ui->pushButton_find);
    findButton->addButton(ui->pushButton_find_2);
    connect(findButton, &QButtonGroup::buttonClicked, this, &CR3_User::FindPage);


    // @@@@@@@@@@@@@@ 지도에서 출발지 도착지 고르기 @@@@@@@@@@@@@@
    QButtonGroup * selectButton = new QButtonGroup(this);
    selectButton->addButton(ui->pushButton_gbBusan_3);
    selectButton->addButton(ui->pushButton_gbSeoul_3);
    selectButton->addButton(ui->pushButton_gbIncheon_3);
    selectButton->addButton(ui->pushButton_gbGyangmeong_3);
    selectButton->addButton(ui->pushButton_gbCheonAn_3);
    selectButton->addButton(ui->pushButton_gbDaejeon_3);
    selectButton->addButton(ui->pushButton_gbSuwon_3);
    selectButton->addButton(ui->pushButton_gbDaegu_3);
    selectButton->addButton(ui->pushButton_hnSeoul_3);
    selectButton->addButton(ui->pushButton_hnYongsan_3);
    selectButton->addButton(ui->pushButton_hnIncheon_3);
    selectButton->addButton(ui->pushButton_hnGyangmeong_3);
    selectButton->addButton(ui->pushButton_hnCheonAn_3);
    selectButton->addButton(ui->pushButton_hnGongju_3);
    selectButton->addButton(ui->pushButton_hnDaejeon_3);
    selectButton->addButton(ui->pushButton_hnGyangju_3);
    selectButton->addButton(ui->pushButton_gjCheonAn_3);
    selectButton->addButton(ui->pushButton_gjSeoul_3);
    selectButton->addButton(ui->pushButton_gjIncheon_3);
    selectButton->addButton(ui->pushButton_gjGyangmeong_3);
    selectButton->addButton(ui->pushButton_gjDaegu_3);
    selectButton->addButton(ui->pushButton_gjDaejeon_3);
    selectButton->addButton(ui->pushButton_jrSeoul_3);
    selectButton->addButton(ui->pushButton_jrYongsan_3);
    selectButton->addButton(ui->pushButton_jrIncheon_3);
    selectButton->addButton(ui->pushButton_jrGyangmeong_3);
    selectButton->addButton(ui->pushButton_jrCheonAn_3);
    selectButton->addButton(ui->pushButton_jrDaejeon_3);
    selectButton->addButton(ui->pushButton_jrGongju_3);
    selectButton->addButton(ui->pushButton_jrJeonju_3);
    connect(selectButton, &QButtonGroup::buttonClicked, this, &CR3_User::SelectToMap);

    QButtonGroup * SeatButton = new QButtonGroup(this);
    SeatButton->addButton(ui->pushButton_ktx1A_2);
    SeatButton->addButton(ui->pushButton_ktx1B_2);
    SeatButton->addButton(ui->pushButton_ktx1C_2);
    SeatButton->addButton(ui->pushButton_ktx1D_2);
    SeatButton->addButton(ui->pushButton_ktx2A_2);
    SeatButton->addButton(ui->pushButton_ktx2B_2);
    SeatButton->addButton(ui->pushButton_ktx2C_2);
    SeatButton->addButton(ui->pushButton_ktx2D_2);
    SeatButton->addButton(ui->pushButton_ktx3A_2);
    SeatButton->addButton(ui->pushButton_ktx3C_2);
    SeatButton->addButton(ui->pushButton_ktx3B_2);
    SeatButton->addButton(ui->pushButton_ktx3D_2);
    SeatButton->addButton(ui->pushButton_ktx4A_2);
    SeatButton->addButton(ui->pushButton_ktx4B_2);
    SeatButton->addButton(ui->pushButton_ktx4C_2);
    SeatButton->addButton(ui->pushButton_ktx4D_2);
    SeatButton->addButton(ui->pushButton_ktx5A_2);
    SeatButton->addButton(ui->pushButton_ktx5B_2);
    SeatButton->addButton(ui->pushButton_ktx5C_2);
    SeatButton->addButton(ui->pushButton_ktx5D_2);
    SeatButton->addButton(ui->pushButton_ktx6A_2);
    SeatButton->addButton(ui->pushButton_ktx6B_2);
    SeatButton->addButton(ui->pushButton_ktx6C_2);
    SeatButton->addButton(ui->pushButton_ktx6D_2);
    SeatButton->addButton(ui->pushButton_ktx7A_2);
    SeatButton->addButton(ui->pushButton_ktx7B_2);
    SeatButton->addButton(ui->pushButton_ktx7C_2);
    SeatButton->addButton(ui->pushButton_ktx7D_2);
    SeatButton->addButton(ui->pushButton_ktx8A_2);
    SeatButton->addButton(ui->pushButton_ktx8B_2);
    SeatButton->addButton(ui->pushButton_ktx8C_2);
    SeatButton->addButton(ui->pushButton_ktx8D_2);
    SeatButton->addButton(ui->pushButton_ktx9A_2);
    SeatButton->addButton(ui->pushButton_ktx9B_2);
    SeatButton->addButton(ui->pushButton_ktx9C_2);
    SeatButton->addButton(ui->pushButton_ktx9D_2);
    SeatButton->addButton(ui->pushButton_ktx10A_2);
    SeatButton->addButton(ui->pushButton_ktx10B_2);
    SeatButton->addButton(ui->pushButton_ktx10C_2);
    SeatButton->addButton(ui->pushButton_ktx10D_2);
    SeatButton->addButton(ui->pushButton_11A_2);
    SeatButton->addButton(ui->pushButton_ktx11B_2);
    SeatButton->addButton(ui->pushButton_ktx11C_2);
    SeatButton->addButton(ui->pushButton_ktx11D_2);
    SeatButton->addButton(ui->pushButton_ktx12A_2);
    SeatButton->addButton(ui->pushButton_ktx12B_2);
    SeatButton->addButton(ui->pushButton_ktx12C_2);
    SeatButton->addButton(ui->pushButton_ktx12D_2);
    SeatButton->addButton(ui->pushButton_ktx13A_2);
    SeatButton->addButton(ui->pushButton_ktx13B_2);
    SeatButton->addButton(ui->pushButton_ktx13C_2);
    SeatButton->addButton(ui->pushButton_ktx13D_2);
    SeatButton->addButton(ui->pushButton_ktx14A_2);
    SeatButton->addButton(ui->pushButton_ktx14B_2);
    SeatButton->addButton(ui->pushButton_ktx14C_2);
    SeatButton->addButton(ui->pushButton_ktx14D_2);
    SeatButton->addButton(ui->pushButton_ktx15A_2);
    SeatButton->addButton(ui->pushButton_ktx15B_2);
    SeatButton->addButton(ui->pushButton_ktx15C_2);
    SeatButton->addButton(ui->pushButton_ktx15D_2);
    SeatButton->addButton(ui->pushButton_ktx16A_2);
    SeatButton->addButton(ui->pushButton_ktx16B_2);
    SeatButton->addButton(ui->pushButton_ktx16C_2);
    SeatButton->addButton(ui->pushButton_ktx16D_2);
    SeatButton->addButton(ui->pushButton_ktx17A_2);
    SeatButton->addButton(ui->pushButton_ktx17B_2);
    SeatButton->addButton(ui->pushButton_ktx17C_2);
    SeatButton->addButton(ui->pushButton_ktx17D_2);
    SeatButton->addButton(ui->pushButton_ktx18A_2);
    SeatButton->addButton(ui->pushButton_ktx18B_2);
    SeatButton->addButton(ui->pushButton_ktx18C_2);
    SeatButton->addButton(ui->pushButton_ktx18D_2);
    SeatButton->addButton(ui->pushButton_ktx19A_2);
    SeatButton->addButton(ui->pushButton_ktx19B_2);
    SeatButton->addButton(ui->pushButton_ktx19C_2);
    SeatButton->addButton(ui->pushButton_ktx19D_2);
    SeatButton->addButton(ui->pushButton_ktx20A_2);
    SeatButton->addButton(ui->pushButton_ktx20B_2);
    SeatButton->addButton(ui->pushButton_ktx20C_2);
    SeatButton->addButton(ui->pushButton_ktx20D_2);
    SeatButton->addButton(ui->pushButton_ktx21A_2);
    SeatButton->addButton(ui->pushButton_ktx21B_2);
    SeatButton->addButton(ui->pushButton_ktx21C_2);
    SeatButton->addButton(ui->pushButton_ktx21D_2);
    SeatButton->addButton(ui->pushButton_ktx22A_2);
    SeatButton->addButton(ui->pushButton_ktx22B_2);
    SeatButton->addButton(ui->pushButton_ktx22C_2);
    SeatButton->addButton(ui->pushButton_ktx22D_2);
    SeatButton->addButton(ui->pushButton_ktx23A_2);
    SeatButton->addButton(ui->pushButton_ktx23B_2);
    SeatButton->addButton(ui->pushButton_ktx23C_2);
    SeatButton->addButton(ui->pushButton_ktx23D_2);
    SeatButton->addButton(ui->pushButton_ktx24A_2);
    SeatButton->addButton(ui->pushButton_ktx24B_2);
    SeatButton->addButton(ui->pushButton_ktx24C_2);
    SeatButton->addButton(ui->pushButton_ktx24D_2);
    SeatButton->addButton(ui->pushButton_ktx25A);
    SeatButton->addButton(ui->pushButton_ktx25B);
    SeatButton->addButton(ui->pushButton_ktx25C);
    SeatButton->addButton(ui->pushButton_ktx25D);
    SeatButton->addButton(ui->pushButton_ktx26A);
    SeatButton->addButton(ui->pushButton_ktx26B);
    SeatButton->addButton(ui->pushButton_ktx26C);
    SeatButton->addButton(ui->pushButton_ktx26D);
    SeatButton->addButton(ui->pushButton_ktx27A);
    SeatButton->addButton(ui->pushButton_ktx27B);
    SeatButton->addButton(ui->pushButton_ktx27C);
    SeatButton->addButton(ui->pushButton_ktx27D);
    SeatButton->addButton(ui->pushButton_ktx28A);
    SeatButton->addButton(ui->pushButton_ktx28B);
    SeatButton->addButton(ui->pushButton_ktx28C);
    SeatButton->addButton(ui->pushButton_ktx28D);
    SeatButton->addButton(ui->pushButton_ktx29A);
    SeatButton->addButton(ui->pushButton_ktx29B);
    SeatButton->addButton(ui->pushButton_ktx29C);
    SeatButton->addButton(ui->pushButton_ktx29D);
    SeatButton->addButton(ui->pushButton_ktx30A);
    SeatButton->addButton(ui->pushButton_ktx30B);
    SeatButton->addButton(ui->pushButton_ktx30C);
    SeatButton->addButton(ui->pushButton_ktx30D);
    SeatButton->addButton(ui->pushButton_ktx31A);
    SeatButton->addButton(ui->pushButton_ktx31B);
    SeatButton->addButton(ui->pushButton_ktx31C);
    SeatButton->addButton(ui->pushButton_ktx31D);
    SeatButton->addButton(ui->pushButton_ktx32A);
    SeatButton->addButton(ui->pushButton_ktx32B);
    SeatButton->addButton(ui->pushButton_ktx32C);
    SeatButton->addButton(ui->pushButton_ktx32D);
    SeatButton->addButton(ui->pushButton_ktx33A);
    SeatButton->addButton(ui->pushButton_ktx33B);
    SeatButton->addButton(ui->pushButton_ktx33C);
    SeatButton->addButton(ui->pushButton_ktx33D);
    SeatButton->addButton(ui->pushButton_ktx34A);
    SeatButton->addButton(ui->pushButton_ktx34B);
    SeatButton->addButton(ui->pushButton_ktx34C);
    SeatButton->addButton(ui->pushButton_ktx34D);
    SeatButton->addButton(ui->pushButton_ktx35A);
    SeatButton->addButton(ui->pushButton_ktx35B);
    SeatButton->addButton(ui->pushButton_ktx35C);
    SeatButton->addButton(ui->pushButton_ktx35D);
    SeatButton->addButton(ui->pushButton_ktx36A);
    SeatButton->addButton(ui->pushButton_ktx36B);
    SeatButton->addButton(ui->pushButton_ktx36C);
    SeatButton->addButton(ui->pushButton_ktx36D);
    connect(SeatButton, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(KTX_Normal_SeatClicked(QAbstractButton*)));

    // KTX 특실 좌석 그룹
    QButtonGroup * ktx_SeatButton2 = new QButtonGroup(this);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal1A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal2A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal3A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal4A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal5A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal6A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal7A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal8A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal9A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal10A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal11A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal12A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal13A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal14A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal15A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal16A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal17A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal18A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal19A);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal20A);


    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal1B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal2B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal3B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal4B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal5B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal6B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal7B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal8B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal9B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal10B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal11B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal12B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal13B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal14B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal15B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal16B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal17B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal18B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal19B);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal20B);


    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal1C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal2C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal3C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal4C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal5C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal6C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal7C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal8C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal9C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal10C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal11C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal12C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal13C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal14C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal15C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal16C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal17C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal18C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal19C);
    ktx_SeatButton2->addButton(ui->pushButton_ktxloyal20C);
    connect(ktx_SeatButton2, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(KTX_Special_SeatClicked(QAbstractButton*)));


    // ITX-새마을 좌석 그룹
    QButtonGroup * itx_SeatButton = new QButtonGroup(this);
    itx_SeatButton->addButton(ui->pushButton_normalseat1A);
    itx_SeatButton->addButton(ui->pushButton_normalseat2A);
    itx_SeatButton->addButton(ui->pushButton_normalseat3A);
    itx_SeatButton->addButton(ui->pushButton_normalseat4A);
    itx_SeatButton->addButton(ui->pushButton_normalseat5A);
    itx_SeatButton->addButton(ui->pushButton_normalseat6A);
    itx_SeatButton->addButton(ui->pushButton_normalseat7A);
    itx_SeatButton->addButton(ui->pushButton_normalseat8A);
    itx_SeatButton->addButton(ui->pushButton_normalseat9A);
    itx_SeatButton->addButton(ui->pushButton_normalseat10A);
    itx_SeatButton->addButton(ui->pushButton_normalseat11A);
    itx_SeatButton->addButton(ui->pushButton_normalseat12A);
    itx_SeatButton->addButton(ui->pushButton_normalseat13A);
    itx_SeatButton->addButton(ui->pushButton_normalseat14A);
    itx_SeatButton->addButton(ui->pushButton_normalseat15A);
    itx_SeatButton->addButton(ui->pushButton_normalseat16A);
    itx_SeatButton->addButton(ui->pushButton_normalseat17A);
    itx_SeatButton->addButton(ui->pushButton_normalseat18A);
    itx_SeatButton->addButton(ui->pushButton_normalseat19A);
    itx_SeatButton->addButton(ui->pushButton_normalseat20A);
    itx_SeatButton->addButton(ui->pushButton_normalseat21A);
    itx_SeatButton->addButton(ui->pushButton_normalseat22A);
    itx_SeatButton->addButton(ui->pushButton_normalseat23A);
    itx_SeatButton->addButton(ui->pushButton_normalseat24A);
    itx_SeatButton->addButton(ui->pushButton_normalseat25A);
    itx_SeatButton->addButton(ui->pushButton_normalseat26A);
    itx_SeatButton->addButton(ui->pushButton_normalseat27A);
    itx_SeatButton->addButton(ui->pushButton_normalseat28A);
    itx_SeatButton->addButton(ui->pushButton_normalseat29A);
    itx_SeatButton->addButton(ui->pushButton_normalseat30A);
    itx_SeatButton->addButton(ui->pushButton_normalseat31A);
    itx_SeatButton->addButton(ui->pushButton_normalseat32A);
    itx_SeatButton->addButton(ui->pushButton_normalseat33A);
    itx_SeatButton->addButton(ui->pushButton_normalseat34A);
    itx_SeatButton->addButton(ui->pushButton_normalseat35A);
    itx_SeatButton->addButton(ui->pushButton_normalseat36A);
    itx_SeatButton->addButton(ui->pushButton_normalseat37A);
    itx_SeatButton->addButton(ui->pushButton_normalseat38A);
    itx_SeatButton->addButton(ui->pushButton_normalseat39A);
    itx_SeatButton->addButton(ui->pushButton_normalseat40A);
    itx_SeatButton->addButton(ui->pushButton_normalseat41A);
    itx_SeatButton->addButton(ui->pushButton_normalseat42A);



    itx_SeatButton->addButton(ui->pushButton_normalseat1B);
    itx_SeatButton->addButton(ui->pushButton_normalseat2B);
    itx_SeatButton->addButton(ui->pushButton_normalseat3B);
    itx_SeatButton->addButton(ui->pushButton_normalseat4B);
    itx_SeatButton->addButton(ui->pushButton_normalseat5B);
    itx_SeatButton->addButton(ui->pushButton_normalseat6B);
    itx_SeatButton->addButton(ui->pushButton_normalseat7B);
    itx_SeatButton->addButton(ui->pushButton_normalseat8B);
    itx_SeatButton->addButton(ui->pushButton_normalseat9B);
    itx_SeatButton->addButton(ui->pushButton_normalseat10B);
    itx_SeatButton->addButton(ui->pushButton_normalseat11B);
    itx_SeatButton->addButton(ui->pushButton_normalseat12B);
    itx_SeatButton->addButton(ui->pushButton_normalseat13B);
    itx_SeatButton->addButton(ui->pushButton_normalseat14B);
    itx_SeatButton->addButton(ui->pushButton_normalseat15B);
    itx_SeatButton->addButton(ui->pushButton_normalseat16B);
    itx_SeatButton->addButton(ui->pushButton_normalseat17B);
    itx_SeatButton->addButton(ui->pushButton_normalseat18B);
    itx_SeatButton->addButton(ui->pushButton_normalseat19B);
    itx_SeatButton->addButton(ui->pushButton_normalseat20B);
    itx_SeatButton->addButton(ui->pushButton_normalseat21B);
    itx_SeatButton->addButton(ui->pushButton_normalseat22B);
    itx_SeatButton->addButton(ui->pushButton_normalseat23B);
    itx_SeatButton->addButton(ui->pushButton_normalseat24B);
    itx_SeatButton->addButton(ui->pushButton_normalseat25B);
    itx_SeatButton->addButton(ui->pushButton_normalseat26B);
    itx_SeatButton->addButton(ui->pushButton_normalseat27B);
    itx_SeatButton->addButton(ui->pushButton_normalseat28B);
    itx_SeatButton->addButton(ui->pushButton_normalseat29B);
    itx_SeatButton->addButton(ui->pushButton_normalseat30B);
    itx_SeatButton->addButton(ui->pushButton_normalseat31B);
    itx_SeatButton->addButton(ui->pushButton_normalseat32B);
    itx_SeatButton->addButton(ui->pushButton_normalseat33B);
    itx_SeatButton->addButton(ui->pushButton_normalseat34B);
    itx_SeatButton->addButton(ui->pushButton_normalseat35B);
    itx_SeatButton->addButton(ui->pushButton_normalseat36B);
    itx_SeatButton->addButton(ui->pushButton_normalseat37B);
    itx_SeatButton->addButton(ui->pushButton_normalseat38B);
    itx_SeatButton->addButton(ui->pushButton_normalseat39B);
    itx_SeatButton->addButton(ui->pushButton_normalseat40B);
    itx_SeatButton->addButton(ui->pushButton_normalseat41B);
    itx_SeatButton->addButton(ui->pushButton_normalseat42B);



    itx_SeatButton->addButton(ui->pushButton_normalseat1C);
    itx_SeatButton->addButton(ui->pushButton_normalseat2C);
    itx_SeatButton->addButton(ui->pushButton_normalseat3C);
    itx_SeatButton->addButton(ui->pushButton_normalseat4C);
    itx_SeatButton->addButton(ui->pushButton_normalseat5C);
    itx_SeatButton->addButton(ui->pushButton_normalseat6C);
    itx_SeatButton->addButton(ui->pushButton_normalseat7C);
    itx_SeatButton->addButton(ui->pushButton_normalseat8C);
    itx_SeatButton->addButton(ui->pushButton_normalseat9C);
    itx_SeatButton->addButton(ui->pushButton_normalseat10C);
    itx_SeatButton->addButton(ui->pushButton_normalseat11C);
    itx_SeatButton->addButton(ui->pushButton_normalseat12C);
    itx_SeatButton->addButton(ui->pushButton_normalseat13C);
    itx_SeatButton->addButton(ui->pushButton_normalseat15C);
    itx_SeatButton->addButton(ui->pushButton_normalseat16C);
    itx_SeatButton->addButton(ui->pushButton_normalseat17C);
    itx_SeatButton->addButton(ui->pushButton_normalseat18C);
    itx_SeatButton->addButton(ui->pushButton_normalseat19C);
    itx_SeatButton->addButton(ui->pushButton_normalseat20C);
    itx_SeatButton->addButton(ui->pushButton_normalseat21C);
    itx_SeatButton->addButton(ui->pushButton_normalseat22C);
    itx_SeatButton->addButton(ui->pushButton_normalseat23C);
    itx_SeatButton->addButton(ui->pushButton_normalseat24C);
    itx_SeatButton->addButton(ui->pushButton_normalseat25C);
    itx_SeatButton->addButton(ui->pushButton_normalseat26C);
    itx_SeatButton->addButton(ui->pushButton_normalseat27C);
    itx_SeatButton->addButton(ui->pushButton_normalseat28C);
    itx_SeatButton->addButton(ui->pushButton_normalseat29C);
    itx_SeatButton->addButton(ui->pushButton_normalseat30C);
    itx_SeatButton->addButton(ui->pushButton_normalseat31C);
    itx_SeatButton->addButton(ui->pushButton_normalseat32C);
    itx_SeatButton->addButton(ui->pushButton_normalseat33C);
    itx_SeatButton->addButton(ui->pushButton_normalseat34C);
    itx_SeatButton->addButton(ui->pushButton_normalseat35C);
    itx_SeatButton->addButton(ui->pushButton_normalseat36C);
    itx_SeatButton->addButton(ui->pushButton_normalseat37C);
    itx_SeatButton->addButton(ui->pushButton_normalseat38C);
    itx_SeatButton->addButton(ui->pushButton_normalseat39C);
    itx_SeatButton->addButton(ui->pushButton_normalseat40C);
    itx_SeatButton->addButton(ui->pushButton_normalseat41C);
    itx_SeatButton->addButton(ui->pushButton_normalseat42C);


    itx_SeatButton->addButton(ui->pushButton_normalseat1D);
    itx_SeatButton->addButton(ui->pushButton_normalseat2D);
    itx_SeatButton->addButton(ui->pushButton_normalseat3D);
    itx_SeatButton->addButton(ui->pushButton_normalseat4D);
    itx_SeatButton->addButton(ui->pushButton_normalseat5D);
    itx_SeatButton->addButton(ui->pushButton_normalseat6D);
    itx_SeatButton->addButton(ui->pushButton_normalseat7D);
    itx_SeatButton->addButton(ui->pushButton_normalseat8D);
    itx_SeatButton->addButton(ui->pushButton_normalseat9D);
    itx_SeatButton->addButton(ui->pushButton_normalseat10D);
    itx_SeatButton->addButton(ui->pushButton_normalseat11D);
    itx_SeatButton->addButton(ui->pushButton_normalseat12D);
    itx_SeatButton->addButton(ui->pushButton_normalseat13D);
    itx_SeatButton->addButton(ui->pushButton_normalseat15D);
    itx_SeatButton->addButton(ui->pushButton_normalseat16D);
    itx_SeatButton->addButton(ui->pushButton_normalseat17D);
    itx_SeatButton->addButton(ui->pushButton_normalseat18D);
    itx_SeatButton->addButton(ui->pushButton_normalseat19D);
    itx_SeatButton->addButton(ui->pushButton_normalseat20D);
    itx_SeatButton->addButton(ui->pushButton_normalseat21D);
    itx_SeatButton->addButton(ui->pushButton_normalseat22D);
    itx_SeatButton->addButton(ui->pushButton_normalseat23D);
    itx_SeatButton->addButton(ui->pushButton_normalseat24D);
    itx_SeatButton->addButton(ui->pushButton_normalseat25D);
    itx_SeatButton->addButton(ui->pushButton_normalseat26D);
    itx_SeatButton->addButton(ui->pushButton_normalseat27D);
    itx_SeatButton->addButton(ui->pushButton_normalseat28D);
    itx_SeatButton->addButton(ui->pushButton_normalseat29D);
    itx_SeatButton->addButton(ui->pushButton_normalseat30D);
    itx_SeatButton->addButton(ui->pushButton_normalseat31D);
    itx_SeatButton->addButton(ui->pushButton_normalseat32D);
    itx_SeatButton->addButton(ui->pushButton_normalseat33D);
    itx_SeatButton->addButton(ui->pushButton_normalseat34D);
    itx_SeatButton->addButton(ui->pushButton_normalseat35D);
    itx_SeatButton->addButton(ui->pushButton_normalseat36D);
    itx_SeatButton->addButton(ui->pushButton_normalseat37D);
    itx_SeatButton->addButton(ui->pushButton_normalseat38D);
    itx_SeatButton->addButton(ui->pushButton_normalseat39D);
    itx_SeatButton->addButton(ui->pushButton_normalseat40D);
    itx_SeatButton->addButton(ui->pushButton_normalseat41D);
    itx_SeatButton->addButton(ui->pushButton_normalseat42D);

    connect(itx_SeatButton, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(SME_SeatClicked(QAbstractButton*)));

    // 무궁화호 좌석 그룹
    QButtonGroup * flowerSeatButton = new QButtonGroup(this);
    flowerSeatButton->addButton(ui->pushButton_normalseat1);
    flowerSeatButton->addButton(ui->pushButton_normalseat2);
    flowerSeatButton->addButton(ui->pushButton_normalseat3);
    flowerSeatButton->addButton(ui->pushButton_normalseat4);
    flowerSeatButton->addButton(ui->pushButton_normalseat5);
    flowerSeatButton->addButton(ui->pushButton_normalseat6);
    flowerSeatButton->addButton(ui->pushButton_normalseat7);
    flowerSeatButton->addButton(ui->pushButton_normalseat8);
    flowerSeatButton->addButton(ui->pushButton_normalseat9);
    flowerSeatButton->addButton(ui->pushButton_normalseat10);

    flowerSeatButton->addButton(ui->pushButton_normalseat11);
    flowerSeatButton->addButton(ui->pushButton_normalseat12);
    flowerSeatButton->addButton(ui->pushButton_normalseat13);
    flowerSeatButton->addButton(ui->pushButton_normalseat14);
    flowerSeatButton->addButton(ui->pushButton_normalseat15);
    flowerSeatButton->addButton(ui->pushButton_normalseat16);
    flowerSeatButton->addButton(ui->pushButton_normalseat17);
    flowerSeatButton->addButton(ui->pushButton_normalseat18);
    flowerSeatButton->addButton(ui->pushButton_normalseat19);
    flowerSeatButton->addButton(ui->pushButton_normalseat20);

    flowerSeatButton->addButton(ui->pushButton_normalseat21);
    flowerSeatButton->addButton(ui->pushButton_normalseat22);
    flowerSeatButton->addButton(ui->pushButton_normalseat23);
    flowerSeatButton->addButton(ui->pushButton_normalseat24);
    flowerSeatButton->addButton(ui->pushButton_normalseat25);
    flowerSeatButton->addButton(ui->pushButton_normalseat26);
    flowerSeatButton->addButton(ui->pushButton_normalseat27);
    flowerSeatButton->addButton(ui->pushButton_normalseat28);
    flowerSeatButton->addButton(ui->pushButton_normalseat29);
    flowerSeatButton->addButton(ui->pushButton_normalseat30);

    flowerSeatButton->addButton(ui->pushButton_normalseat31);
    flowerSeatButton->addButton(ui->pushButton_normalseat32);
    flowerSeatButton->addButton(ui->pushButton_normalseat33);
    flowerSeatButton->addButton(ui->pushButton_normalseat34);
    flowerSeatButton->addButton(ui->pushButton_normalseat35);
    flowerSeatButton->addButton(ui->pushButton_normalseat36);
    flowerSeatButton->addButton(ui->pushButton_normalseat37);
    flowerSeatButton->addButton(ui->pushButton_normalseat38);
    flowerSeatButton->addButton(ui->pushButton_normalseat39);
    flowerSeatButton->addButton(ui->pushButton_normalseat40);

    flowerSeatButton->addButton(ui->pushButton_normalseat41);
    flowerSeatButton->addButton(ui->pushButton_normalseat42);
    flowerSeatButton->addButton(ui->pushButton_normalseat43);
    flowerSeatButton->addButton(ui->pushButton_normalseat44);
    flowerSeatButton->addButton(ui->pushButton_normalseat45);
    flowerSeatButton->addButton(ui->pushButton_normalseat46);
    flowerSeatButton->addButton(ui->pushButton_normalseat47);
    flowerSeatButton->addButton(ui->pushButton_normalseat48);
    flowerSeatButton->addButton(ui->pushButton_normalseat49);
    flowerSeatButton->addButton(ui->pushButton_normalseat50);

    flowerSeatButton->addButton(ui->pushButton_normalseat51);
    flowerSeatButton->addButton(ui->pushButton_normalseat52);
    flowerSeatButton->addButton(ui->pushButton_normalseat53);
    flowerSeatButton->addButton(ui->pushButton_normalseat54);
    flowerSeatButton->addButton(ui->pushButton_normalseat55);
    flowerSeatButton->addButton(ui->pushButton_normalseat56);
    flowerSeatButton->addButton(ui->pushButton_normalseat57_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat58_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat59_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat60_3);

    flowerSeatButton->addButton(ui->pushButton_normalseat61_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat62_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat63_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat64_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat65_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat66_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat67_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat68_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat69_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat70_3);

    flowerSeatButton->addButton(ui->pushButton_normalseat71_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat72_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat73_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat74_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat75_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat76_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat77_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat78_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat79_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat80_3);

    flowerSeatButton->addButton(ui->pushButton_normalseat81_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat82_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat83_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat84_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat85_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat86_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat87_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat88_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat89_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat90_3);

    flowerSeatButton->addButton(ui->pushButton_normalseat91_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat92_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat93_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat94_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat95_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat96_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat97_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat98_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat99_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat100_3);

    flowerSeatButton->addButton(ui->pushButton_normalseat101_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat102_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat103_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat104_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat105_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat106_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat107_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat108_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat109_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat110_3);

    flowerSeatButton->addButton(ui->pushButton_normalseat111_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat112_3);
    flowerSeatButton->addButton(ui->pushButton_normalseat113_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat114_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat115_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat116_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat117_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat118_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat119_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat120_2);


    flowerSeatButton->addButton(ui->pushButton_normalseat121_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat122_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat123_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat124_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat125_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat126_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat127_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat128_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat129_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat130_2);

    flowerSeatButton->addButton(ui->pushButton_normalseat131_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat132_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat133_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat134_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat135_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat136_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat137_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat138_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat139_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat140_2);

    flowerSeatButton->addButton(ui->pushButton_normalseat141_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat142_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat143_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat144_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat145_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat146_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat147_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat148_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat149_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat150_2);

    flowerSeatButton->addButton(ui->pushButton_normalseat151_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat152_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat153_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat154_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat155_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat156_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat157_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat158_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat159_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat160_2);

    flowerSeatButton->addButton(ui->pushButton_normalseat161_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat162_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat163_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat164_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat165_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat166_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat167_2);
    flowerSeatButton->addButton(ui->pushButton_normalseat168_2);
    connect(flowerSeatButton, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(MGH_SeatClicked(QAbstractButton*)));


    // @@@@@@@@@@@@@@ 회원가입, 아이디찾기, 비번찾기 완료 버튼 @@@@@@@@@@@@@@
    connect(ui->pushButton_signUp, &QPushButton::clicked, this, &CR3_User::Sign);
    connect(ui->pushButton_findId, &QPushButton::clicked, this, &CR3_User::FindId);
    connect(ui->pushButton_findPw, &QPushButton::clicked, this, &CR3_User::FindPw);


    // @@@@@@@@@@@@@@ 지도 버튼, 열차조회에서 뒤로가기 버튼 @@@@@@@@@@@@@@
    connect(ui->pushButton_map1, &QPushButton::clicked, this, &CR3_User::GoMap);
    connect(ui->pushButton_map1_2, &QPushButton::clicked, this, &CR3_User::GoMap);
    connect(ui->pushButton_backTrain, &QPushButton::clicked, this, &CR3_User::TicketingPage);


    // @@@@@@@@@@@@@@ 회원가입 시 아이디, 비번, 비번확인, 생일, 이름, 휴대폰 번호 텍스트 변경 감지 @@@@@@@@@@@@@@
    connect(ui->lineEdit_signId, &QLineEdit::textChanged, this, &CR3_User::CheckId);
    connect(ui->lineEdit_signPw, &QLineEdit::textChanged, this, &CR3_User::CheckPw);
    connect(ui->lineEdit_signPwChk, &QLineEdit::textChanged, this, &CR3_User::CheckPw);
    connect(ui->lineEdit_signBirth, &QLineEdit::textChanged, this, &CR3_User::CheckBirth);
    connect(ui->lineEdit_signName, &QLineEdit::textChanged, this, &CR3_User::CheckName);
    connect(ui->lineEdit_signPhone, &QLineEdit::textChanged, this, &CR3_User::CheckPhone);


    // @@@@@@@@@@@@@@ 승차권 예매 시 달력, 출발지,도착지 이름 눌러서 선택, 출발지,도착지 교체, 승객 인원 선택, 열차 조회하기, 열차 조회에서 이전날 다음날 버튼 @@@@@@@@@@@@@@
    connect(ui->pushButton_startDay1, &QPushButton::clicked, this, &CR3_User::StartTime);
    connect(ui->pushButton_startDay1_2, &QPushButton::clicked, this, &CR3_User::StartTime);
    connect(ui->pushButton_startDay1_3, &QPushButton::clicked, this, &CR3_User::StartTime2);
    connect(ui->pushButton_start1, &QPushButton::clicked, this, &CR3_User::TrainStart);
    connect(ui->pushButton_start1_2, &QPushButton::clicked, this, &CR3_User::TrainStart);
    connect(ui->pushButton_arrive1, &QPushButton::clicked, this, &CR3_User::TrainArrive);
    connect(ui->pushButton_arrive1_2, &QPushButton::clicked, this, &CR3_User::TrainArrive);
    connect(ui->pushButton_changeSA1, &QPushButton::clicked, this, &CR3_User::ChangeSA);
    connect(ui->pushButton_changeSA1_2, &QPushButton::clicked, this, &CR3_User::ChangeSA2);
    connect(ui->pushButton_userNseat1, &QPushButton::clicked, this, &CR3_User::SelectAgeSeat);
    connect(ui->pushButton_userNseat1_2, &QPushButton::clicked, this, &CR3_User::SelectAgeSeat);
    connect(ui->pushButton_TrainView1, &QPushButton::clicked, this, &CR3_User::TrainView1);
    connect(ui->pushButton_TrainView2, &QPushButton::clicked, this, &CR3_User::TrainView2);
    connect(ui->pushButton_beforeDay, &QPushButton::clicked, this, &CR3_User::BeforeDay);
    connect(ui->pushButton_afterDay, &QPushButton::clicked, this, &CR3_User::AfterDay);


    // @@@@@@@@@@@@@@ 열차 좌석 선택에서 콤보박스로 열차 이동 @@@@@@@@@@@@@@
    connect(ui->comboBox_choiceMGH1, &QComboBox::currentTextChanged, this, &CR3_User::currentTextChanged);
    connect(ui->comboBox_choiceMGH2, &QComboBox::currentTextChanged, this, &CR3_User::currentTextChanged);
    connect(ui->comboBox_choiceMGH3, &QComboBox::currentTextChanged, this, &CR3_User::currentTextChanged);
    connect(ui->comboBox_choiceSME1, &QComboBox::currentTextChanged, this, &CR3_User::currentTextChanged);
    connect(ui->comboBox_choiceSME2, &QComboBox::currentTextChanged, this, &CR3_User::currentTextChanged);
    connect(ui->comboBox_choiceSME3, &QComboBox::currentTextChanged, this, &CR3_User::currentTextChanged);
    connect(ui->comboBox_choiceKTX1, &QComboBox::currentTextChanged, this, &CR3_User::currentTextChanged);
    connect(ui->comboBox_choiceKTX2, &QComboBox::currentTextChanged, this, &CR3_User::currentTextChanged);
    connect(ui->comboBox_choiceKTX3, &QComboBox::currentTextChanged, this, &CR3_User::currentTextChanged);
    connect(ui->comboBox_choiceKTXloyal1, &QComboBox::currentTextChanged, this, &CR3_User::currentTextChanged);
    connect(ui->comboBox_choiceKTXloyal2, &QComboBox::currentTextChanged, this, &CR3_User::currentTextChanged);


    // @@@@@@@@@@@@@@ 열차 좌석 선택에서 1호차, 2호차, 3호차 버튼으로 열차 이동 @@@@@@@@@@@@@@
    connect(ui->pushButton_MGHgo1to2, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_MGHgo2to1, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_MGHgo2to3, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_MGHgo3to2, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_SMEgo1to2, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_SMEgo2to1, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_SMEgo2to3, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_SMEgo3to2, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_KTXgo1to2, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_KTXgo2to1, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_KTXgo2to3, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_KTXgo3to2, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_KTXloyalgo1to2, &QPushButton::clicked, this, &CR3_User::moveTrainPage);
    connect(ui->pushButton_KTXloyalgo2to1, &QPushButton::clicked, this, &CR3_User::moveTrainPage);


    connect(ui->pushButton_purchaseNext, &QPushButton::clicked, this, &CR3_User::purchaseNext);
    connect(ui->pushButton_ticketNext, &QPushButton::clicked, this, &CR3_User::TicketChkPage2);
    connect(ui->pushButton_ticketPrevious, &QPushButton::clicked, this, &CR3_User::TicketChkPage1);
    connect(ui->pushButton_logout, &QPushButton::clicked, this, &CR3_User::logout);
    connect(ui->pushButton_deleteId, &QPushButton::clicked, this, &CR3_User::handleDeleteRequest);
    connect(ui->pushButton_changeId, &QPushButton::clicked, this, &CR3_User::performchangeId);
    connect(ui->pushButton_changePw, &QPushButton::clicked, this, &CR3_User::performchangePw);


    // @@@@@@@@@@@@@@  데이터 베이스 시작과 동시에 열기 @@@@@@@@@@@@@@
    if (!userdb.isOpen() && !userdbOpen())
    {
        qDebug() << "데이터베이스를 열지 못했습니다.";
    }

}



// @@@@@@@@@@@@@@  데이터베이스 열고 닫는 부분 @@@@@@@@@@@@@@
void CR3_User::userdbClose()
{
    // 데이터베이스 연결을 해제합니다.
    userdb.close();
}

bool CR3_User::userdbOpen()
{
    userdb = QSqlDatabase::addDatabase("QMYSQL");
    userdb.setHostName("10.10.21.126");
    userdb.setDatabaseName("cr3");
    userdb.setUserName("root");
    userdb.setPassword("lms3554");

    // 우리 테이블 이름 : user, train

    if (!userdb.open())
    {
        qDebug() << "데이터베이스를 열지 못했습니다.";
        return false;
    }
    else
    {
        qDebug() << "연결되었습니다.";
        return true;
    }
}


// @@@@@@@@@@@@@@  페이지 이동 함수 @@@@@@@@@@@@@@
void CR3_User::LoginPage() // 로그인 페이지
{
    ui->lineEdit_loginId->clear();
    ui->lineEdit_loginId_2->clear();
    ui->lineEdit_loginPw->clear();
    ui->lineEdit_loginPw_2->clear();
    ui->stackedWidget->setCurrentIndex(1);
}

void CR3_User::SignPage() // 회원가입 페이지
{
    ui->lineEdit_signId->clear();
    ui->lineEdit_signPw->clear();
    ui->lineEdit_signPwChk->clear();
    ui->lineEdit_signName->clear();
    ui->lineEdit_signPhone->clear();
    ui->lineEdit_signEmail->clear();
    ui->lineEdit_signBirth->clear();
    ui->stackedWidget->setCurrentIndex(2);
}

void CR3_User::FindPage() // 아이디/비번찾기 페이지
{
    ui->lineEdit_findIdName->clear();
    ui->lineEdit_findPwId->clear();
    ui->lineEdit_findIdPhone->clear();
    ui->lineEdit_findPwName->clear();
    ui->lineEdit_findPwPhone->clear();
    ui->stackedWidget->setCurrentIndex(3);
}

void CR3_User::GoMap() // 지도 이동 페이지
{
    ui->stackedWidget->setCurrentIndex(5);
}

void CR3_User::TicketingPage() // 승차권 예매 페이지
{
    ui->stackedWidget->setCurrentIndex(4);
}


void CR3_User::AgreePage() // 약관 동의 페이지
{
    ui->stackedWidget->setCurrentIndex(19);
}

void CR3_User::KTXPage()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void CR3_User::MGHPage()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void CR3_User::SMEPage()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void CR3_User::KTXROYALPage()
{
    ui->stackedWidget->setCurrentIndex(16);
}

// 약관 동의 체크 여부
void CR3_User::on_pushButton_totalagree_clicked()
{
    if (ui->checkBox_agree1->isChecked() && ui->checkBox_agree2->isChecked())
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->checkBox_agree1->setChecked(false);
        ui->checkBox_agree2->setChecked(false);
    }
    else
    {
        QMessageBox::critical(this, "경고", "체크 박스를 모두 체크해주세요.");
    }
}

// @@@@@@@@@@@@@@  회원가입 @@@@@@@@@@@@@@
void CR3_User::Sign()
{
    // 회원가입에서 입력했던 정보를 가져옴
    QString id = ui->lineEdit_signId->text();
    QString pw = ui->lineEdit_signPw->text();
    QString pwchk = ui->lineEdit_signPwChk->text();
    QString name = ui->lineEdit_signName->text();
    QString gender_choice;
    QString birth = ui->lineEdit_signBirth->text();
    QString email = ui->lineEdit_signEmail->text();
    QString phonenumber = ui->lineEdit_signPhone->text();

    // 이메일 콤보박스 설정
    QString emailchoice = ui->comboBox_signEmail->currentText();
    email += emailchoice;

    // 남녀 고르는 것 설정
    if (ui->radioButton_signMale->isChecked())
    {
        gender_choice = "남";
    }
    else if (ui->radioButton_signFemale->isChecked())
    {
        gender_choice = "여";
    }

    // 회원가입할 때 정보 하나라도 빠뜨렸을 시에 뜨는 메세지박스
    if (id.isEmpty() || pw.isEmpty() || pwchk.isEmpty() || name.isEmpty()
        || gender_choice.isEmpty() || birth.isEmpty() || email.isEmpty() || phonenumber.isEmpty())
    {
        // 회원가입 부분이 미완료 됐을 때
        msgbox5.setWindowTitle("CuteRail");
        msgbox5.setIcon(QMessageBox::Warning);
        msgbox5.setText("빈 칸을 모두 입력해 주세요.");
        msgbox5.setStandardButtons(QMessageBox::Ok);

        // Ok 누르면 창 닫힘
        if (msgbox5.exec() == QMessageBox::Ok)
        {
            msgbox5.close();
        }
    }
    else if (pw != pwchk)
    {
        // 비밀번호와 비밀번호 확인이 일치하지 않는 경우
        msgbox5.setWindowTitle("CuteRail");
        msgbox5.setIcon(QMessageBox::Warning);
        msgbox5.setText("비밀번호와 비밀번호 확인이 일치하지 않습니다.");
        msgbox5.setStandardButtons(QMessageBox::Ok);

        // Ok 누르면 창 닫힘
        if (msgbox5.exec() == QMessageBox::Ok)
        {
            msgbox5.close();
        }
    }
    else if (birth.length() != 8)
    {
        // 생년월일이 8자리가 아닌 경우
        msgbox5.setWindowTitle("CuteRail");
        msgbox5.setIcon(QMessageBox::Warning);
        msgbox5.setText("생년월일은 8자리로 입력하여야 합니다.");
        msgbox5.setStandardButtons(QMessageBox::Ok);

        // Ok 누르면 창 닫힘
        if (msgbox5.exec() == QMessageBox::Ok)
        {
            msgbox5.close();
        }
    }
    else if (pw.length() < 8 || !pw.contains(QRegularExpression("[!@#$%^&*()]")))
    {
        // 비밀번호가 8자리 이상이고 특수문자를 포함하지 않는 경우
        msgbox5.setWindowTitle("CuteRail");
        msgbox5.setIcon(QMessageBox::Warning);
        msgbox5.setText("비밀번호는 8자리 이상이며, 특수문자를 포함해야 합니다.");
        msgbox5.setStandardButtons(QMessageBox::Ok);

        // Ok 누르면 창 닫힘
        if (msgbox5.exec() == QMessageBox::Ok)
        {
            msgbox5.close();
        }
    }

    else if (phonenumber.length() != 13 || !phonenumber.contains(QRegularExpression("^\\d{3}-\\d{4}-\\d{4}$")))
    {
        // 휴대폰 번호가 13자리이고 정해진 형식이 아닌 경우
        msgbox5.setWindowTitle("CuteRail");
        msgbox5.setIcon(QMessageBox::Warning);
        msgbox5.setText("휴대폰 번호는 XXX-XXXX-XXXX 형식으로 입력해야 합니다.");
        msgbox5.setStandardButtons(QMessageBox::Ok);

        // Ok 누르면 창 닫힘
        if (msgbox5.exec() == QMessageBox::Ok)
        {
            msgbox5.close();
        }
    }

    else
    {
        // 모든 조건을 통과한 경우에만 회원가입 진행
        if (userdbOpen())
        {
            QSqlQuery query;
            query.prepare("INSERT INTO user (ID, PW, NAME, PHONE, GENDER, EMAIL, BIRTH) "
                          "VALUES (:signId, :signPw, :signName, :signPhone, :signGender, :signEmail, :signBirth)");
            query.bindValue(":signId", id);
            query.bindValue(":signPw", pw);
            query.bindValue(":signName", name);
            query.bindValue(":signPhone", phonenumber);
            query.bindValue(":signGender", gender_choice);
            query.bindValue(":signEmail", email);
            query.bindValue(":signBirth", birth);

            if (query.exec())
            {
                // 회원가입 성공 메시지를 표시합니다.
                msgbox1.setWindowTitle("CuteRail");
                msgbox1.setIcon(QMessageBox::Information);
                msgbox1.setText("회원가입이 성공적으로 완료되었습니다!");
                msgbox1.setStandardButtons(QMessageBox::Ok);

                if (msgbox1.exec() == QMessageBox::Ok)
                {
                    msgbox1.close();
                    ui->stackedWidget->setCurrentIndex(1);
                }
            }
            else
            {
                // 회원가입 실패 메시지를 표시합니다.
                msgbox1.critical(this, "CuteRail", "회원가입 중 오류가 발생했습니다.");
            }
        }
        else
        {
            // 데이터베이스 연결 오류 메시지를 표시합니다.
            msgbox1.critical(this, "CuteRail", "데이터베이스 연결에 실패했습니다.");
        }
    }
}

// @@@@@@@@@@@@@@ 회원가입 검사 @@@@@@@@@@@@@@
void CR3_User::CheckId(const QString& text)
{
    QRegularExpression englishNumberRegExp("^[A-Za-z0-9]*$"); // 영어 대소문자와 숫자만 입력 가능한 정규 표현식

    // 영어와 숫자 입력 필터를 적용한 validator 생성
    QValidator* englishNumberValidator = new QRegularExpressionValidator(englishNumberRegExp, this);

    // lineEdit_signId에 validator 설정
    ui->lineEdit_signId->setValidator(englishNumberValidator);


    if (!text.isEmpty())
    {
        QSqlQuery query;
        query.prepare("SELECT ID FROM user WHERE ID = :signId");
        query.bindValue(":signId", text);

        if (query.exec() && query.next())
        {
            // 아이디가 이미 존재하는 경우
            ui->label_signIdChk->setText("이미 존재하는 아이디입니다.");
        }
        else
        {
            // 아이디가 사용 가능한 경우
            ui->label_signIdChk->setText("사용 가능한 아이디입니다.");
        }
    }
    else
    {
        ui->label_signIdChk->clear();
    }
}

void CR3_User::CheckPw()
{
    QString signPw = ui->lineEdit_signPw->text();
    QString signPwChk = ui->lineEdit_signPwChk->text();
    if (!signPw.isEmpty() && !signPwChk.isEmpty())
    {
        if (signPw == signPwChk)
        {
            // 비밀번호와 비밀번호 확인이 일치하는 경우
            QRegularExpression specialCharPattern("[!@#$%^&*(),.?:{}|<>]+");
            if (!signPwChk.contains(specialCharPattern) || signPwChk.length() < 8)
            {
                ui->label_signPwChk2->setText("비밀번호는 8자리 이상, 특수문자를 포함해야 합니다.");
            }
            else
            {
                ui->label_signPwChk2->setText("비밀번호를 확인하였습니다.");

            }
        }
        else
        {
            // 비밀번호와 비밀번호 확인이 일치하지 않는 경우
            ui->label_signPwChk2->setText("비밀번호를 다시 확인해주세요.");
        }
    }
    else
    {
        ui->label_signPwChk2->clear();
    }
}

void CR3_User::CheckBirth()
{
    QString signBirth = ui->lineEdit_signBirth->text();


    if (signBirth.length() != 8)
    {
        // 생년월일이 8자리가 아닌 경우 경고 메시지를 표시합니다.
        ui->label_signBirth2->setText("생년월일은 8자리로 입력하세요.");
    }
    else
    {
        ui->label_signBirth2->setText("생년월일을 확인하였습니다.");
    }
}

void CR3_User::CheckName()
{
    QRegularExpression koreanRegExp("^[가-힣]*$"); // 한글만 입력 가능한 정규 표현식

    // 한글 입력 필터를 적용한 validator 생성
    QValidator* koreanValidator = new QRegularExpressionValidator(koreanRegExp, this);

    // lineEdit_signName에 validator 설정
    ui->lineEdit_signName->setValidator(koreanValidator);
}

void CR3_User::CheckPhone()
{
    QString signPhone = ui->lineEdit_signPhone->text();

    // 입력된 숫자를 하이픈(-)으로 구분하여 11자리로.
    QString ChkPhone = signPhone;
    ChkPhone.remove(QRegularExpression("[^0-9]"));

    if (ChkPhone.length() == 11)
    {
        ChkPhone = ChkPhone.left(3) + "-" + ChkPhone.mid(3, 4) + "-" + ChkPhone.right(4);
        ui->lineEdit_signPhone->setText(ChkPhone);
        ui->label_signPhone2->setText("휴대폰 번호를 확인하였습니다.");
    }
    else
    {
        ui->label_signPhone2->setText("휴대폰 번호는 11자리 숫자로 입력하세요.");
    }
}

void CR3_User::Login()
{
    username = ui->lineEdit_loginId->text();

    QString loginID = ui->lineEdit_loginId->text();
    QString loginPW = ui->lineEdit_loginPw->text();

    if (loginID.isEmpty() || loginPW.isEmpty())
    {
        msgbox2.warning(this, "로그인 오류", "아이디와 비밀번호를 입력하세요.");
        return;
    }

    if (!userdbOpen())
    {
        msgbox2.critical(this, "데이터베이스 오류", "데이터베이스 연결에 실패했습니다.");
        return;
    }

    QSqlQuery query;

    // 데이터베이스에서 아이디와 비밀번호 확인
    query.prepare("SELECT ID, EMAIL FROM user WHERE ID = :loginID AND PW = :loginPW");
    query.bindValue(":loginID", loginID);
    query.bindValue(":loginPW", loginPW);

    if (query.exec())
    {
        if (query.next())
        {
            QString email = query.value(1).toString();

            if (email == "회원탈퇴")
            {
                msgbox7.setWindowTitle("탈퇴된 계정");
                msgbox7.setIcon(QMessageBox::Information);
                msgbox7.setText("탈퇴된 계정입니다!\n아이디 또는 비밀번호를 다시 입력하세요!");
                msgbox7.setStandardButtons(QMessageBox::Ok);
                msgbox7.exec(); // 메시지 박스를 표시하고 대기합니다.

                ui->lineEdit_loginId->clear();
                ui->lineEdit_loginPw->clear();
                return; // 로그인을 막습니다.
            }

            //지호추가 수정(아이디안보이게삭제)
            //            QString loggedInID = query.value(0).toString();
            msgbox2.information(this, "로그인 성공", "로그인되었습니다.");
            login_id = loginID;
            profile();
            QSqlQuery query;
            query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTPOINT, DESTINATION, "
                        "DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, "
                          "SEATNUM, TICKETINGDATE, BUYDATE FROM TICKETINGINfo WHERE ID = :loginID");
            query.bindValue(":loginID", login_id);
            if (query.exec() && query.next())
            {
                QString train_type = query.value(0).toString();
                QString train_num = query.value(1).toString();
                QString train_startpoint = query.value(2).toString();
                QString train_destination = query.value(3).toString();
                QString train_departurehour = query.value(4).toString();
                QString train_departureminute = query.value(5).toString();
                QString train_arrivalhour = query.value(6).toString();
                QString train_arrivalminute = query.value(7).toString();
                QString train_seatnum = query.value(8).toString();
                QString train_ticketingDate = query.value(9).toString();
                QString train_buyDate = query.value(10).toString();

                ui->label_Reserve_Date_2->setText("예매일자: " + train_ticketingDate);
                ui->label_Start_City_2->setText(train_startpoint);
                ui->label_Arrive_City_2->setText(train_destination);
                ui->label_Start_Time_2->setText(train_departurehour + ":" + train_departureminute);
                ui->label_Arrive_Time_2->setText(train_arrivalhour + ":" + train_arrivalminute);
                ui->label_Train_Name_2->setText(train_type + train_num + " 열차");
                ui->label_Train_Num_2->setText(train_type + train_num);
                ui->label_Trainseat_Num_2->setText(train_seatnum);
                ui->label_Reserve_YearDate_2->setText(train_buyDate);
            }
            ui->stackedWidget->setCurrentIndex(4);
        }
        else
        {
            msgbox2.warning(this, "로그인 실패", "아이디 또는 비밀번호가 올바르지 않습니다.");

            login_cnt++;

            if (login_cnt == 5)
            {
                msgbox2.setWindowTitle("로그인");
                msgbox2.setIcon(QMessageBox::Information);
                msgbox2.setText("아이디 또는 비밀번호를 5회 틀리셨습니다!\n아이디 또는 비밀번호를 찾아주세요!");
                msgbox2.setStandardButtons(QMessageBox::Ok);
                if (msgbox2.exec() == QMessageBox::Ok)
                    msgbox2.close();

                login_cnt = 0;
            }
        }
    }
    else
    {
        msgbox2.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");
    }
}



// @@@@@@@@@@@@@@  휴대폰 번호 로그인 @@@@@@@@@@@@@@
void CR3_User::PhoneLogin()
{
    username = ui->lineEdit_loginId_2->text();

    QString loginPhonenum = ui->lineEdit_loginId_2->text();
    QString loginPW = ui->lineEdit_loginPw_2->text();


    if (loginPhonenum.isEmpty() || loginPW.isEmpty())
    {
        msgbox2.warning(this, "CuteRail", "휴대폰 번호와 비밀번호를 입력하세요.");
        return ;
    }

    if (!userdbOpen())
    {
        msgbox2.critical(this, "CuteRail", "데이터베이스 연결에 실패했습니다.");
        return;
    }

    QSqlQuery query;

    // 데이터베이스에서 아이디와 비밀번호 확인
    query.prepare("SELECT PHONE, EMAIL, ID FROM user WHERE PHONE = :loginPhonenum AND PW = :loginPW");
    query.bindValue(":loginPhonenum", loginPhonenum);
    query.bindValue(":loginPW", loginPW);


    if (query.exec())
    {
        if (query.next())
        {
            QString email = query.value(1).toString();

            if (email == "회원탈퇴")
            {
                msgbox7.setWindowTitle("탈퇴된 계정");
                msgbox7.setIcon(QMessageBox::Information);
                msgbox7.setText("탈퇴된 계정입니다!\n아이디 또는 비밀번호를 다시 입력하세요!");
                msgbox7.setStandardButtons(QMessageBox::Ok);
                msgbox7.exec(); // 메시지 박스를 표시하고 대기합니다.

                ui->lineEdit_loginId_2->clear();
                ui->lineEdit_loginPw_2->clear();
                return; // 로그인을 막습니다.
            }

            msgbox2.information(this, "CuteRail", "로그인되었습니다.");
            profile();
            login_id = query.value(2).toString();
            qDebug() << login_id << "애비ㅑㅜ아지붕";
            QSqlQuery query;
            query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTPOINT, DESTINATION, "
                        "DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, "
                          "SEATNUM, TICKETINGDATE, BUYDATE FROM TICKETINGINfo WHERE ID = :loginID");
            query.bindValue(":loginID", login_id);
            if (query.exec() && query.next())
            {
                QString train_type = query.value(0).toString();
                QString train_num = query.value(1).toString();
                QString train_startpoint = query.value(2).toString();
                QString train_destination = query.value(3).toString();
                QString train_departurehour = query.value(4).toString();
                QString train_departureminute = query.value(5).toString();
                QString train_arrivalhour = query.value(6).toString();
                QString train_arrivalminute = query.value(7).toString();
                QString train_seatnum = query.value(8).toString();
                QString train_ticketingDate = query.value(9).toString();
                QString train_buyDate = query.value(10).toString();

                ui->label_Reserve_Date_2->setText("예매일자: " + train_ticketingDate);
                ui->label_Start_City_2->setText(train_startpoint);
                ui->label_Arrive_City_2->setText(train_destination);
                ui->label_Start_Time_2->setText(train_departurehour + ":" + train_departureminute);
                ui->label_Arrive_Time_2->setText(train_arrivalhour + ":" + train_arrivalminute);
                ui->label_Train_Name_2->setText(train_type + train_num + " 열차");
                ui->label_Train_Num_2->setText(train_type + train_num);
                ui->label_Trainseat_Num_2->setText(train_seatnum);
                ui->label_Reserve_YearDate_2->setText(train_buyDate);
            }
            ui->stackedWidget->setCurrentIndex(4);
        }
        else
        {
            msgbox2.warning(this, "CuteRail", "아이디 또는 비밀번호가 올바르지 않습니다.");

            login_cnt++;

            if(login_cnt == 5)
            {
                msgbox2.setWindowTitle("CuteRail");
                msgbox2.setIcon(QMessageBox::Information);
                msgbox2.setText("아이디 또는 비밀번호를 5회 틀리셨습니다!\n아이디 또는 비밀번호를 찾아주시기 바랍니다!");
                msgbox2.setStandardButtons(QMessageBox::Ok);
                if(msgbox2.exec() == QMessageBox::Ok)
                    msgbox2.close();

                login_cnt = 0;
            }
        }
    }
    else
    {
        msgbox2.critical(this, "CuteRail", "데이터베이스 조회 중 오류가 발생했습니다.");
    }
}

// @@@@@@@@@@@@@@  아이디 비번찾기 @@@@@@@@@@@@@@
void CR3_User::FindId()
{
    QString findName = ui->lineEdit_findIdName->text();
    QString findPhone = ui->lineEdit_findIdPhone->text();

    if (findName.isEmpty() || findPhone.isEmpty())
    {
        msgbox3.warning(this, "CuteRail", "이름과 전화번호를 입력하세요.");
        return;
    }

    if (!userdbOpen())
    {
        msgbox3.critical(this, "CuteRail", "데이터베이스 연결에 실패했습니다.");
        return;
    }

    QSqlQuery query;
    // 데이터베이스에서 일치하는 아이디 찾기
    query.prepare("SELECT ID FROM user WHERE NAME = :findName AND PHONE = :findPhone");
    query.bindValue(":findName", findName);
    query.bindValue(":findPhone", findPhone);

    if (query.exec())
    {
        if (query.next())
        {
            QString foundID = query.value(0).toString();
            msgbox3.information(this, "CuteRail", "아이디 : " + foundID + " 입니다. ");

            ui->stackedWidget->setCurrentIndex(1);
        }
        else
        {
            msgbox3.warning(this, "CuteRail", "일치하는 정보를 찾을 수 없습니다.");
        }
    }
    else
    {
        QMessageBox::critical(this, "CuteRail", "데이터베이스 조회 중 오류가 발생했습니다.");
    }
}

void CR3_User::FindPw()
{
    QString findID = ui->lineEdit_findPwId->text();
    QString findName = ui->lineEdit_findPwName->text();
    QString findPhone = ui->lineEdit_findPwPhone->text();

    if (findID.isEmpty() || findName.isEmpty() || findPhone.isEmpty())
    {
        msgbox4.warning(this, "CuteRail", "아이디, 이름, 전화번호를 입력하세요.");
        return;
    }

    if (!userdbOpen())
    {
        msgbox4.critical(this, "CuteRail", "데이터베이스 연결에 실패했습니다.");
        return;
    }

    QSqlQuery query;

    // 데이터베이스에서 일치하는 비밀번호 찾기
    query.prepare("SELECT PW FROM user WHERE ID = :findID AND NAME = :findName AND PHONE = :findPhone");
    query.bindValue(":findID", findID);
    query.bindValue(":findName", findName);
    query.bindValue(":findPhone", findPhone);

    if (query.exec())
    {
        if (query.next())
        {
            QString foundPW = query.value(0).toString();
            msgbox4.information(this, "CuteRail", "비밀번호: " + foundPW);

            ui->stackedWidget->setCurrentIndex(1);
        }
        else
        {
            msgbox4.warning(this, "CuteRail", "일치하는 정보를 찾을 수 없습니다.");
        }
    }
    else
    {
        msgbox4.critical(this, "CuteRail", "데이터베이스 조회 중 오류가 발생했습니다.");
    }
}

///////////////////////////////////////////////////////////////// 여기까지 회원정보 구간 //////////////////////////////////////////////////////////////


// @@@@@@@@@@@@@@ 창 가운데에 띄우는 함수 @@@@@@@@@@@@@@
void CR3_User::centerOnScreen()
{
    // 현재 화면의 크기 정보 가져오기
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    // 창의 크기 정보 가져오기
    int windowWidth = width();
    int windowHeight = height();

    // 화면 중앙 위치 계산
    int x = (screenGeometry.width() - windowWidth) / 2;
    int y = (screenGeometry.height() - windowHeight) / 2;

    // 창의 위치 설정
    move(x, y);
}


// @@@@@@@@@@@@@@@@@ 승차권 예매 UI @@@@@@@@@@@@@@@@@@
void CR3_User::TicketingUI()
{
    // 현재 날짜와 시간 가져오기
    QDateTime currentDateTime = QDateTime::currentDateTime();

    // 현재 요일 계산
    int dayOfWeek = currentDateTime.date().dayOfWeek(); // 1 (월요일)부터 7 (일요일)까지의 값

    // 한글 요일로 변환
    QString koreanDayOfWeek;
    switch (dayOfWeek)
    {
    case 1:
        koreanDayOfWeek = "(월)";
        break;
    case 2:
        koreanDayOfWeek = "(화)";
        break;
    case 3:
        koreanDayOfWeek = "(수)";
        break;
    case 4:
        koreanDayOfWeek = "(목)";
        break;
    case 5:
        koreanDayOfWeek = "(금)";
        break;
    case 6:
        koreanDayOfWeek = "(토)";
        break;
    case 7:
        koreanDayOfWeek = "(일)";
        break;
    default:
        koreanDayOfWeek = "알 수 없음";
        break;
    }

    // 형식화된 문자열 생성
    QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 " + koreanDayOfWeek + " hh:mm");

    // QLabel에 문자열 설정
    ui->label_startTime1->setAlignment(Qt::AlignCenter);
    ui->label_startTime1_2->setAlignment(Qt::AlignCenter);
    ui->label_startTime1_3->setAlignment(Qt::AlignCenter);
    ui->label_startTime1->setText(formattedDateTime);
    ui->label_startTime1_2->setText(formattedDateTime);
    ui->label_startTime1_3->setText(formattedDateTime);
}


// @@@@@@@@@@@@@@@@@ 이름 눌러서 도착지 선택 다이얼로그 부르기 @@@@@@@@@@@@@@@@@@
void CR3_User::TrainArrive()
{
    QDialog *newDialog = new QDialog(this);
    newDialog->setWindowTitle("도착지 선택");

    QGridLayout *layout = new QGridLayout(newDialog);

    // 도착지 리스트
    QStringList ArriveList = {"서울", "광주송정", "부산", "대구", "대전", "울산", "인천", "수원", "광명", "공주", "전주", "천안아산", "용산"};

    // 도착지 버튼을 생성하고 그리드 레이아웃에 추가
    for (int i = 0; i < ArriveList.size(); ++i)
    {
        QPushButton *button = new QPushButton(ArriveList[i], newDialog);
        layout->addWidget(button, i / 4, i % 4); // 4x4 그리드 레이아웃에 추가
        connect(button, &QPushButton::clicked, this, &CR3_User::ArriveButtonClick);
    }

    newDialog->exec();
}


// @@@@@@@@@@@@@@@@@ 이름 눌러서 출발지 선택 다이얼로그 부르기 @@@@@@@@@@@@@@@@@@
void CR3_User::TrainStart()
{
    QDialog *newDialog = new QDialog(this);
    newDialog->setWindowTitle("출발지 선택");

    QGridLayout *layout = new QGridLayout(newDialog);

    // 도착지 리스트
    QStringList ArriveList = {"서울", "광주송정", "부산", "대구", "대전", "울산", "인천", "수원", "광명", "공주", "전주", "천안아산", "용산"};

    // 도착지 버튼을 생성하고 그리드 레이아웃에 추가
    for (int i = 0; i < ArriveList.size(); ++i)
    {
        QPushButton *button = new QPushButton(ArriveList[i], newDialog);
        layout->addWidget(button, i / 4, i % 4); // 4x4 그리드 레이아웃에 추가
        connect(button, &QPushButton::clicked, this, &CR3_User::StartButtonClick);
    }

    newDialog->exec();
}


// @@@@@@@@@@@@@@@@@ 이름 눌러서 도착지 선택 @@@@@@@@@@@@@@@@@@
void CR3_User::ArriveButtonClick()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        QString buttonText = button->text();
        ui->pushButton_arrive1->setText(buttonText);
        ui->pushButton_arrive1_2->setText(buttonText);
        // 버튼 텍스트를 사용하여 원하는 작업 수행
        QDialog *dialog = qobject_cast<QDialog*>(button->parentWidget());
        if (dialog)
        {
            dialog->accept();
        }
    }
}


// @@@@@@@@@@@@@@@@@ 이름 눌러서 출발지 선택 @@@@@@@@@@@@@@@@@@
void CR3_User::StartButtonClick()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        QString buttonText = button->text();
        ui->pushButton_start1->setText(buttonText);
        ui->pushButton_start1_2->setText(buttonText);
        // 버튼 텍스트를 사용하여 원하는 작업 수행
        QDialog *dialog = qobject_cast<QDialog*>(button->parentWidget());
        if (dialog)
        {
            dialog->accept();
        }
    }
}


// @@@@@@@@@@@@@@@@@ 가는날 달력 다이얼로그 불러와서 날짜 선택 @@@@@@@@@@@@@@@@@@
void CR3_User::StartTime()
{
    QDialog *newDialog = new QDialog(this);
    newDialog->setWindowTitle("가는날");

    QVBoxLayout *layout = new QVBoxLayout(newDialog);

    QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime(), newDialog);
    dateTimeEdit->setDisplayFormat("시간을 먼저 골라주세요         시간: hh");
    layout->addWidget(dateTimeEdit); // 날짜와 시간 입력 위젯 추가

    QCalendarWidget *newCalendar = new QCalendarWidget(newDialog);

    // 최소 날짜를 현재 날짜로 설정 // 이러면 현재보다 이전 날짜는 선택 불가능
    newCalendar->setMinimumDate(QDate::currentDate());

    layout->addWidget(newCalendar); // 캘린더 위젯 추가

    // 타이머 생성
    QTimer* timer = new QTimer(this);
    timer->setSingleShot(true);
    // 타이머의 타임아웃 시그널에 연결
    connect(timer, &QTimer::timeout, this, [=]() {
        // 원하는 날짜와 시간을 설정
        QDateTime newDateTime = QDateTime::currentDateTime().addSecs(1);
        // QDateTimeEdit 위젯의 값을 설정
        dateTimeEdit->setDateTime(newDateTime);
    });
    // 타이머를 1초 (1000 밀리초) 주기로 시작
    timer->start(100);

    connect(dateTimeEdit, &QDateTimeEdit::dateTimeChanged, this, &CR3_User::handleDateTimeSelection);
    connect(newCalendar, &QCalendarWidget::selectionChanged, this, &CR3_User::handleCalendarSelection);

    newCalendar->setFirstDayOfWeek(Qt::Monday); // 주간 뷰 시작 요일 설정 (월요일부터 시작하도록)
    newCalendar->setSelectionMode(QCalendarWidget::SingleSelection); // 하나의 날짜만 선택 가능하도록 설정
    newCalendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader); // 주간 뷰에서 수직 헤더 숨기기
    QTextCharFormat saturdayFormat;
    saturdayFormat.setForeground(Qt::black); // 토요일의 텍스트 색상을 검은색으로 설정
    newCalendar->setWeekdayTextFormat(Qt::Saturday, saturdayFormat);
    QTextCharFormat sundayFormat;
    sundayFormat.setForeground(Qt::red); // 일요일의 텍스트 색상을 빨간색으로 설정
    newCalendar->setWeekdayTextFormat(Qt::Sunday, sundayFormat);

    newDialog->exec();
}


// @@@@@@@@@@@@@@@@@ 오는날 달력 다이얼로그 불러와서 날짜 선택 @@@@@@@@@@@@@@@@@@
void CR3_User::StartTime2()
{
    QDialog *newDialog = new QDialog(this);
    newDialog->setWindowTitle("오는날");

    QVBoxLayout *layout = new QVBoxLayout(newDialog);

    QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime(), newDialog);
    dateTimeEdit->setDisplayFormat("시간을 먼저 골라주세요         시간: hh");
    layout->addWidget(dateTimeEdit); // 날짜와 시간 입력 위젯 추가

    QCalendarWidget *newCalendar = new QCalendarWidget(newDialog);

    // 최소 날짜를 현재 날짜로 설정 // 이러면 현재보다 이전 날짜는 선택 불가능
    newCalendar->setMinimumDate(QDate::currentDate());

    layout->addWidget(newCalendar); // 캘린더 위젯 추가

    // 타이머 생성
    QTimer* timer = new QTimer(this);
    timer->setSingleShot(true);
    // 타이머의 타임아웃 시그널에 연결
    connect(timer, &QTimer::timeout, this, [=]() {
        // 원하는 날짜와 시간을 설정
        QDateTime newDateTime = QDateTime::currentDateTime().addSecs(1);
        // QDateTimeEdit 위젯의 값을 설정
        dateTimeEdit->setDateTime(newDateTime);
    });
    // 타이머를 1초 (1000 밀리초) 주기로 시작
    timer->start(100);

    connect(dateTimeEdit, &QDateTimeEdit::dateTimeChanged, this, &CR3_User::handleDateTimeSelection);
    connect(newCalendar, &QCalendarWidget::selectionChanged, this, &CR3_User::handleCalendarSelection2);

    newDialog->exec();
}


// @@@@@@@@@@@@@@@@@ 시, 분 선택한 것 시간:00으로 바꿔줌 @@@@@@@@@@@@@@@@@@
void CR3_User::handleDateTimeSelection(const QDateTime &dateTime)
{
    dateTimeTime = dateTime.toString("hh:00");
}


// @@@@@@@@@@@@@@@@@ 달력 선택했을 때 라벨에 선택한 날짜 가져다줌 @@@@@@@@@@@@@@@@@@
void CR3_User::handleCalendarSelection()
{
    QCalendarWidget *newCalendar = qobject_cast<QCalendarWidget*>(sender());
    if (newCalendar)
    {
        QDate selectedDate = newCalendar->selectedDate(); // 캘린더에서 선택한 날짜 가져오기

        QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime(), nullptr);
        dateTimeEdit->setDisplayFormat("hh:00");
        QDateTime selectedDateTime(selectedDate, dateTimeEdit->time()); // 선택한 날짜와 시간을 포함하는 QDateTime 객체 생성

        int dayOfWeek = selectedDate.dayOfWeek();
        QString dayOfWeekString;

        switch (dayOfWeek) {
        case Qt::Monday:
            dayOfWeekString = "(월)";
            break;
        case Qt::Tuesday:
            dayOfWeekString = "(화)";
            break;
        case Qt::Wednesday:
            dayOfWeekString = "(수)";
            break;
        case Qt::Thursday:
            dayOfWeekString = "(목)";
            break;
        case Qt::Friday:
            dayOfWeekString = "(금)";
            break;
        case Qt::Saturday:
            dayOfWeekString = "(토)";
            break;
        case Qt::Sunday:
            dayOfWeekString = "(일)";
            break;
        default:
            dayOfWeekString = "알 수 없음";
            break;
        }

        // 선택한 날짜와 시간을 문자열로 변환
        QString formattedDateTime = selectedDateTime.toString("yyyy년 MM월 dd일") + " " + dayOfWeekString + " " + dateTimeTime;

        // QLabel에 문자열 설정
        ui->label_startTime1->setText(formattedDateTime);
        ui->label_startTime1_2->setText(formattedDateTime);
        // 다이얼로그를 닫음
        QDialog *dialog = qobject_cast<QDialog*>(newCalendar->parentWidget());
        if (dialog)
        {
            dialog->accept();
        }
    }
}


// @@@@@@@@@@@@@@@@@ 달력 선택했을 때 라벨에 선택한 날짜 가져다줌2 @@@@@@@@@@@@@@@@@@
void CR3_User::handleCalendarSelection2()
{
    QCalendarWidget *newCalendar = qobject_cast<QCalendarWidget*>(sender());
    if (newCalendar)
    {
        QDate selectedDate = newCalendar->selectedDate(); // 캘린더에서 선택한 날짜 가져오기

        QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime(), nullptr);
        dateTimeEdit->setDisplayFormat("hh:00");
        QDateTime selectedDateTime(selectedDate, dateTimeEdit->time()); // 선택한 날짜와 시간을 포함하는 QDateTime 객체 생성

        int dayOfWeek = selectedDate.dayOfWeek();
        QString dayOfWeekString;

        switch (dayOfWeek) {
        case Qt::Monday:
            dayOfWeekString = "(월)";
            break;
        case Qt::Tuesday:
            dayOfWeekString = "(화)";
            break;
        case Qt::Wednesday:
            dayOfWeekString = "(수)";
            break;
        case Qt::Thursday:
            dayOfWeekString = "(목)";
            break;
        case Qt::Friday:
            dayOfWeekString = "(금)";
            break;
        case Qt::Saturday:
            dayOfWeekString = "(토)";
            break;
        case Qt::Sunday:
            dayOfWeekString = "(일)";
            break;
        default:
            dayOfWeekString = "알 수 없음";
            break;
        }

        // 선택한 날짜와 시간을 문자열로 변환
        QString formattedDateTime = selectedDateTime.toString("yyyy년 MM월 dd일") + " " + dayOfWeekString + " " + dateTimeTime;

        // QLabel에 문자열 설정
        ui->label_startTime1_3->setText(formattedDateTime);

        // 다이얼로그를 닫음
        QDialog *dialog = qobject_cast<QDialog*>(newCalendar->parentWidget());
        if (dialog)
        {
            dialog->accept();
        }
    }
}


// @@@@@@@@@@@@@@@@@ 승객 연력 및 인원 수 고르기 @@@@@@@@@@@@@@@@@@
void CR3_User::SelectAgeSeat()
{
    totalCount = 0; // 모든 수량의 합계를 저장할 변수

    QDialog *newDialog = new QDialog(this);
    newDialog->setWindowTitle("승객 연령 및 좌석수");

    QVBoxLayout *layout1 = new QVBoxLayout(newDialog);

    QStringList labelTexts = {
                              "<center>최소 1명 - 최대 9명</center>",
                              "어른(만 13세 이상)",
                              "어린이(만 6-12세)",
                              "유아(만 6세 미만)",
                              "경로(만 65세 이상)",
                              "중증 장애인",
                              "경증 장애인"
    };

//    QVector<QLabel *> quantityLabels; // 수량 라벨들을 저장하는 벡터

    for (int i = 0; i < labelTexts.size(); ++i)
    {
        QWidget *widget = new QWidget;
        QHBoxLayout *widgetLayout = new QHBoxLayout(widget);

        QLabel *label = new QLabel;
        label->setText(labelTexts[i]);

        // 첫 번째 라벨에는 푸쉬버튼과 수량 라벨 추가하지 않음
        if (i != 0)
        {
            QPushButton *minusButton = new QPushButton("-");
            QPushButton *plusButton = new QPushButton("+");
            QLabel *quantityLabel = new QLabel("0");
//            quantityLabels.append(quantityLabel); // 수량 라벨을 벡터에 추가

            // 버튼 클릭 시 수량 업데이트
            connect(minusButton, &QPushButton::clicked, [=]() {
                int currentQuantity = quantityLabel->text().toInt();
                if (currentQuantity > 0) {
                    quantityLabel->setText(QString::number(currentQuantity - 1));
                    totalCount -= 1; // 합계에서 1 감소
                }
            });
            connect(plusButton, &QPushButton::clicked, [=]() {
                int currentQuantity = quantityLabel->text().toInt();
                if (currentQuantity < 9) {
                    quantityLabel->setText(QString::number(currentQuantity + 1));
                    totalCount += 1; // 합계에서 1 증가
                }
            });

            // 동그란 모양의 스타일 시트 설정
            QString buttonStyle = "QPushButton {"
                                  "  border-radius: 12px;" // 반지름을 버튼 크기의 절반으로 설정
                                  "  border: 1px solid black;"
                                  "  background-color: white;" // 버튼 배경색
                                  "  color: black;" // 버튼 텍스트 색상
                                  "  padding: 3px;" // 텍스트와 버튼 경계 사이의 여백
                                  "  font-size: 16px;" // 폰트 크기 설정
                                  "  width: 16px;" // 버튼의 너비를 설정
                                  "  height: 16px;" // 버튼의 높이를 설정
                                  "}";

            minusButton->setStyleSheet(buttonStyle);
            plusButton->setStyleSheet(buttonStyle);

            // 수평 스페이서 추가
            QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

            widgetLayout->addWidget(label);
            widgetLayout->addItem(spacer); // 수평 스페이서 추가
            widgetLayout->addWidget(minusButton);
            widgetLayout->addWidget(quantityLabel);
            widgetLayout->addWidget(plusButton);
        }

        else
        {
            widgetLayout->addWidget(label);
        }

        layout1->addWidget(widget);
    }

    // 확인 버튼 추가
    QPushButton *confirmButton = new QPushButton("확인");
    layout1->addWidget(confirmButton);

    // "확인" 버튼 클릭 시 합계 업데이트
    connect(confirmButton, &QPushButton::clicked, [=]() {
        ui->label_userNseatChk1->setText("총 " + QString::number(totalCount) + "명");
        ui->label_userNseatChk1_2->setText("총 " + QString::number(totalCount) + "명");
        ui->label_userNseatChk1->setAlignment(Qt::AlignCenter);
        ui->label_userNseatChk1_2->setAlignment(Qt::AlignCenter);
        newDialog->accept();
    });

    newDialog->exec();
}


// @@@@@@@@@@@@@@@@@ 지도에서 출발지, 도착지 고를 때 @@@@@@@@@@@@@@@@@@
void CR3_User::SelectToMap(QAbstractButton* clickedButton)
{
    if (clickedButton)
    {
        QString buttonText = clickedButton->text();

        if (!startSelected) // 출발지가 선택되지 않은 경우
        {
            QMessageBox::information(this, "출발지 변경", "출발지가 " + buttonText + "(으)로 변경되었습니다.\n이제 도착지를 골라주세요.");
            ui->pushButton_start1->setText(buttonText);
            ui->pushButton_start1_2->setText(buttonText);
            startSelected = true; // 출발지가 선택되었음을 표시
        }
        else // 출발지가 이미 선택된 경우
        {
            QMessageBox::information(this, "도착지 변경", "도착지가 " + buttonText + "(으)로 변경되었습니다.");
            ui->pushButton_arrive1->setText(buttonText);
            ui->pushButton_arrive1_2->setText(buttonText);
            ui->stackedWidget->setCurrentIndex(4);
            startSelected = false; // 출발지 선택 상태 초기화
        }
    }
}


// @@@@@@@@@@@@@@@@@ 출발지, 도착지 교체 @@@@@@@@@@@@@@@@@@
void CR3_User::ChangeSA()
{
    QString Start1 = ui->pushButton_start1->text();
    QString Arrive1 = ui->pushButton_arrive1->text();

    QString Result1 = Arrive1;
    Arrive1 = Start1;
    ui->pushButton_start1->setText(Result1);
    ui->pushButton_arrive1->setText(Arrive1);
    ui->pushButton_start1_2->setText(Result1);
    ui->pushButton_arrive1_2->setText(Arrive1);
}


// @@@@@@@@@@@@@@@@@ 출발지, 도착지 교체 왕복에서@@@@@@@@@@@@@@@@@@
void CR3_User::ChangeSA2()
{
    QString Start2 = ui->pushButton_start1_2->text();
    QString Arrive2 = ui->pushButton_arrive1_2->text();

    QString Result2 = Arrive2;
    Arrive2 = Start2;
    ui->pushButton_start1_2->setText(Result2);
    ui->pushButton_arrive1_2->setText(Arrive2);
    ui->pushButton_start1->setText(Result2);
    ui->pushButton_arrive1->setText(Arrive2);
}





// 현재 열차 시간표
void CR3_User::CurrentView()

{
    qDebug() << "커런트 뷰!";
    QLayoutItem* item;
    while ((item = ui->verticalLayout_TrainView->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    QString originalText = ui->label_startTime1->text();
    QString timeAndMinute = originalText.split(" ").last(); // "hh:mm" 형식으로 추출
    QStringList parts = timeAndMinute.split(":");
    QString part1 = parts[0];
    QString part2 = parts[1];

    // 시간과 분을 뺀 문자열을 만듦
    QString withoutTime = originalText.left(originalText.indexOf(timeAndMinute));

    // 새로운 형식으로 문자열 조합
    QString newText = withoutTime;

    ui->label_ChooseDay->setText(newText);
    ui->label_ViewStart->setText(ui->pushButton_start1->text());
    ui->label_ViewArrive->setText(ui->pushButton_arrive1->text());

    QString start1 = ui->pushButton_start1->text();
    QString arrive1 = ui->pushButton_arrive1->text();

    QSqlQuery query;
    query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTINGPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, TRAINPRICE, TRAINSPECIALPRICE FROM TRAINfo "
                  "WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION AND ((DEPARTUREHOUR > :DEPARTUREHOUR) OR (DEPARTUREHOUR = :DEPARTUREHOUR AND DEPARTUREMINUTE > :DEPARTUREMINUTE))");
    query.bindValue(":STARTINGPOINT",start1);
    query.bindValue(":DESTINATION", arrive1);
    query.bindValue(":DEPARTUREHOUR",part1);
    query.bindValue(":DEPARTUREMINUTE",part2);


    if (query.exec())
    {
        int maxTextWidth = 69;

        while(query.next())
        {
            QString traintype = query.value("TRAINTYPE").toString();
            QString trainnum = query.value("TRAINNUM").toString();
            QString startingpoint = query.value("STARTINGPOINT").toString();
            QString departurehour = query.value("DEPARTUREHOUR").toString();
            QString departureminute = query.value("DEPARTUREMINUTE").toString();
            QString destination = query.value("DESTINATION").toString();
            QString arrivalhour = query.value("ARRIVALHOUR").toString();
            QString arrivalminute = query.value("ARRIVALMINUTE").toString();
            QString trainprice = query.value("TRAINPRICE").toString();
            QString trainspecialprice = query.value("TRAINSPECIALPRICE").toString();


            // 특 우등실에 값이 없을 때 "─" 이걸로 나타냄
            if (trainspecialprice.isEmpty()) {
                trainspecialprice = "─";
            }

            QLabel *textLabel1 = new QLabel(traintype + "\n" + trainnum);
            QLabel *textLabel2 = new QLabel(departurehour + ":" + departureminute + "\n" + startingpoint);
            QLabel *textLabel3 = new QLabel(arrivalhour + ":" + arrivalminute + "\n" + destination);


            QPushButton *button1 = new QPushButton(trainprice);
            QPushButton *button2 = new QPushButton(trainspecialprice);
            textLabel1->setFixedWidth(maxTextWidth);
            QString buttonStyle = "QPushButton {"

                                  "  border: 1px solid black;"
                                  "  background-color: white;" // 버튼 배경색
                                  "  color: black;" // 버튼 텍스트 색상
                                  "  padding: 0px;" // 텍스트와 버튼 경계 사이의 여백
                                  "  font-size: 12px;" // 폰트 크기 설정
                                  "  width: 13px;" // 버튼의 너비를 설정
                                  "  height: 36px;" // 버튼의 높이를 설정
                                  "}";
            button1->setStyleSheet(buttonStyle);
            button2->setStyleSheet(buttonStyle);
            if (traintype == "KTX")
            {
                // KTX 버튼 생성
                QPushButton *ktxButton = new QPushButton(trainprice);
                ktxButton->setStyleSheet(buttonStyle);

                // KTX 버튼에 대한 이벤트 핸들러 연결
//                connect(ktxButton, &QPushButton::clicked, this, &CR3_User::KTXPage);
                connect(ktxButton, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    KTXPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(ktxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }
//                connect(button2, &QPushButton::clicked, this, &CR3_User::KTXROYALPage);
                connect(button2, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    KTXROYALPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(button2, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXROYALPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }

                // 레이아웃에 KTX 버튼 추가
                QHBoxLayout *ktxLayout = new QHBoxLayout;
                ktxLayout->addWidget(textLabel1);
                ktxLayout->addWidget(textLabel2);
                ktxLayout->addWidget(textLabel3);
                ktxLayout->addWidget(ktxButton);
                ktxLayout->addWidget(button2);  // 다른 버튼 추가
                QVBoxLayout *ktxMainLayout = new QVBoxLayout;
                ktxMainLayout->addLayout(ktxLayout);
                QWidget *ktxWidget = new QWidget;
                ktxWidget->setLayout(ktxMainLayout);

                ui->verticalLayout_TrainView->addWidget(ktxWidget);
            }
            else if (traintype == "ITX-새마을")
                {
                // ITX-새마을 버튼 생성
                QPushButton *itxButton = new QPushButton(trainprice);
                itxButton->setStyleSheet(buttonStyle);

                // ITX-새마을 버튼에 대한 이벤트 핸들러 연결
//                connect(itxButton, &QPushButton::clicked, this, &CR3_User::SMEPage);
                connect(itxButton, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    SMEPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(itxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        SMEPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }

                // 레이아웃에 ITX-새마을 버튼 추가
                QHBoxLayout *itxLayout = new QHBoxLayout;
                itxLayout->addWidget(textLabel1);
                itxLayout->addWidget(textLabel2);
                itxLayout->addWidget(textLabel3);
                itxLayout->addWidget(itxButton);
                itxLayout->addWidget(button2);  // 다른 버튼 추가

                QVBoxLayout *itxMainLayout = new QVBoxLayout;
                itxMainLayout->addLayout(itxLayout);
                QWidget *itxWidget = new QWidget;
                itxWidget->setLayout(itxMainLayout);

                ui->verticalLayout_TrainView->addWidget(itxWidget);
            }
            else if (traintype == "무궁화호")
                {
                // 무궁화호 버튼 생성
                QPushButton *muguButton = new QPushButton(trainprice);
                muguButton->setStyleSheet(buttonStyle);

                // 무궁화호 버튼에 대한 이벤트 핸들러 연결
//                connect(muguButton, &QPushButton::clicked, this, &CR3_User::MGHPage);
                connect(muguButton, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    MGHPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(muguButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        MGHPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }

                // 레이아웃에 무궁화호 버튼 추가
                QHBoxLayout *muguLayout = new QHBoxLayout;
                muguLayout->addWidget(textLabel1);
                muguLayout->addWidget(textLabel2);
                muguLayout->addWidget(textLabel3);
                muguLayout->addWidget(muguButton);
                muguLayout->addWidget(button2);  // 다른 버튼 추가
                QVBoxLayout *muguMainLayout = new QVBoxLayout;
                muguMainLayout->addLayout(muguLayout);
                QWidget *muguWidget = new QWidget;
                muguWidget->setLayout(muguMainLayout);

                ui->verticalLayout_TrainView->addWidget(muguWidget);
            }
        }
    }
    else
    {
        msgbox4.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");
    }
}

void CR3_User::CurrentView2()

{
    qDebug() << "커런트 뷰!";
    QLayoutItem* item;
    while ((item = ui->verticalLayout_TrainView->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    QString originalText = ui->label_startTime1_2->text();
    QString timeAndMinute = originalText.split(" ").last(); // "hh:mm" 형식으로 추출
    QStringList parts = timeAndMinute.split(":");
    QString part1 = parts[0];
    QString part2 = parts[1];

    // 시간과 분을 뺀 문자열을 만듦
    QString withoutTime = originalText.left(originalText.indexOf(timeAndMinute));

    // 새로운 형식으로 문자열 조합
    QString newText = withoutTime;

    ui->label_ChooseDay->setText(newText);
    ui->label_ViewStart->setText(ui->pushButton_start1->text());
    ui->label_ViewArrive->setText(ui->pushButton_arrive1->text());

    QString start1 = ui->pushButton_start1->text();
    QString arrive1 = ui->pushButton_arrive1->text();

    QSqlQuery query;
    query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTINGPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, TRAINPRICE, TRAINSPECIALPRICE FROM TRAINfo "
                  "WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION AND ((DEPARTUREHOUR > :DEPARTUREHOUR) OR (DEPARTUREHOUR = :DEPARTUREHOUR AND DEPARTUREMINUTE > :DEPARTUREMINUTE))");
    query.bindValue(":STARTINGPOINT",start1);
    query.bindValue(":DESTINATION", arrive1);
    query.bindValue(":DEPARTUREHOUR",part1);
    query.bindValue(":DEPARTUREMINUTE",part2);


    if (query.exec())
    {
        int maxTextWidth = 69;

        while(query.next())
        {
            QString traintype = query.value("TRAINTYPE").toString();
            QString trainnum = query.value("TRAINNUM").toString();
            QString startingpoint = query.value("STARTINGPOINT").toString();
            QString departurehour = query.value("DEPARTUREHOUR").toString();
            QString departureminute = query.value("DEPARTUREMINUTE").toString();
            QString destination = query.value("DESTINATION").toString();
            QString arrivalhour = query.value("ARRIVALHOUR").toString();
            QString arrivalminute = query.value("ARRIVALMINUTE").toString();
            QString trainprice = query.value("TRAINPRICE").toString();
            QString trainspecialprice = query.value("TRAINSPECIALPRICE").toString();


            // 특 우등실에 값이 없을 때 "─" 이걸로 나타냄
            if (trainspecialprice.isEmpty()) {
                trainspecialprice = "─";
            }

            QLabel *textLabel1 = new QLabel(traintype + "\n" + trainnum);
            QLabel *textLabel2 = new QLabel(departurehour + ":" + departureminute + "\n" + startingpoint);
            QLabel *textLabel3 = new QLabel(arrivalhour + ":" + arrivalminute + "\n" + destination);


            QPushButton *button1 = new QPushButton(trainprice);
            QPushButton *button2 = new QPushButton(trainspecialprice);
            textLabel1->setFixedWidth(maxTextWidth);
            QString buttonStyle = "QPushButton {"

                                  "  border: 1px solid black;"
                                  "  background-color: white;" // 버튼 배경색
                                  "  color: black;" // 버튼 텍스트 색상
                                  "  padding: 0px;" // 텍스트와 버튼 경계 사이의 여백
                                  "  font-size: 12px;" // 폰트 크기 설정
                                  "  width: 13px;" // 버튼의 너비를 설정
                                  "  height: 36px;" // 버튼의 높이를 설정
                                  "}";
            button1->setStyleSheet(buttonStyle);
            button2->setStyleSheet(buttonStyle);
            if (traintype == "KTX")
            {
                // KTX 버튼 생성
                QPushButton *ktxButton = new QPushButton(trainprice);
                ktxButton->setStyleSheet(buttonStyle);

                // KTX 버튼에 대한 이벤트 핸들러 연결
                //                connect(ktxButton, &QPushButton::clicked, this, &CR3_User::KTXPage);
                connect(ktxButton, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    KTXPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(ktxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }
                //                connect(button2, &QPushButton::clicked, this, &CR3_User::KTXROYALPage);
                connect(button2, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    KTXROYALPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(button2, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXROYALPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }

                // 레이아웃에 KTX 버튼 추가
                QHBoxLayout *ktxLayout = new QHBoxLayout;
                ktxLayout->addWidget(textLabel1);
                ktxLayout->addWidget(textLabel2);
                ktxLayout->addWidget(textLabel3);
                ktxLayout->addWidget(ktxButton);
                ktxLayout->addWidget(button2);  // 다른 버튼 추가
                QVBoxLayout *ktxMainLayout = new QVBoxLayout;
                ktxMainLayout->addLayout(ktxLayout);
                QWidget *ktxWidget = new QWidget;
                ktxWidget->setLayout(ktxMainLayout);

                ui->verticalLayout_TrainView->addWidget(ktxWidget);
            }
            else if (traintype == "ITX-새마을")
                {
                // ITX-새마을 버튼 생성
                QPushButton *itxButton = new QPushButton(trainprice);
                itxButton->setStyleSheet(buttonStyle);

                // ITX-새마을 버튼에 대한 이벤트 핸들러 연결
                //                connect(itxButton, &QPushButton::clicked, this, &CR3_User::SMEPage);
                connect(itxButton, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    SMEPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(itxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        SMEPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }

                // 레이아웃에 ITX-새마을 버튼 추가
                QHBoxLayout *itxLayout = new QHBoxLayout;
                itxLayout->addWidget(textLabel1);
                itxLayout->addWidget(textLabel2);
                itxLayout->addWidget(textLabel3);
                itxLayout->addWidget(itxButton);
                itxLayout->addWidget(button2);  // 다른 버튼 추가

                QVBoxLayout *itxMainLayout = new QVBoxLayout;
                itxMainLayout->addLayout(itxLayout);
                QWidget *itxWidget = new QWidget;
                itxWidget->setLayout(itxMainLayout);

                ui->verticalLayout_TrainView->addWidget(itxWidget);
            }
            else if (traintype == "무궁화호")
                {
                // 무궁화호 버튼 생성
                QPushButton *muguButton = new QPushButton(trainprice);
                muguButton->setStyleSheet(buttonStyle);

                // 무궁화호 버튼에 대한 이벤트 핸들러 연결
                //                connect(muguButton, &QPushButton::clicked, this, &CR3_User::MGHPage);
                connect(muguButton, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    MGHPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(muguButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        MGHPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }

                // 레이아웃에 무궁화호 버튼 추가
                QHBoxLayout *muguLayout = new QHBoxLayout;
                muguLayout->addWidget(textLabel1);
                muguLayout->addWidget(textLabel2);
                muguLayout->addWidget(textLabel3);
                muguLayout->addWidget(muguButton);
                muguLayout->addWidget(button2);  // 다른 버튼 추가
                QVBoxLayout *muguMainLayout = new QVBoxLayout;
                muguMainLayout->addLayout(muguLayout);
                QWidget *muguWidget = new QWidget;
                muguWidget->setLayout(muguMainLayout);

                ui->verticalLayout_TrainView->addWidget(muguWidget);
            }
        }
    }
    else
    {
        msgbox4.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");
    }
}

void CR3_User::CurrentView3()

{
    qDebug() << "커런트 뷰!";
    QLayoutItem* item;
    while ((item = ui->verticalLayout_TrainView->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    QString originalText = ui->label_startTime1_3->text();
    QString timeAndMinute = originalText.split(" ").last(); // "hh:mm" 형식으로 추출
    QStringList parts = timeAndMinute.split(":");
    QString part1 = parts[0];
    QString part2 = parts[1];

    // 시간과 분을 뺀 문자열을 만듦
    QString withoutTime = originalText.left(originalText.indexOf(timeAndMinute));

    // 새로운 형식으로 문자열 조합
    QString newText = withoutTime;

    ui->label_ChooseDay->setText(newText);
    ui->label_ViewStart->setText(ui->pushButton_start1->text());
    ui->label_ViewArrive->setText(ui->pushButton_arrive1->text());

    QString start1 = ui->pushButton_start1->text();
    QString arrive1 = ui->pushButton_arrive1->text();

    QSqlQuery query;
    query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTINGPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, TRAINPRICE, TRAINSPECIALPRICE FROM TRAINfo "
                  "WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION AND ((DEPARTUREHOUR > :DEPARTUREHOUR) OR (DEPARTUREHOUR = :DEPARTUREHOUR AND DEPARTUREMINUTE > :DEPARTUREMINUTE))");
    query.bindValue(":STARTINGPOINT",start1);
    query.bindValue(":DESTINATION", arrive1);
    query.bindValue(":DEPARTUREHOUR",part1);
    query.bindValue(":DEPARTUREMINUTE",part2);


    if (query.exec())
    {
        int maxTextWidth = 69;

        while(query.next())
        {
            QString traintype = query.value("TRAINTYPE").toString();
            QString trainnum = query.value("TRAINNUM").toString();
            QString startingpoint = query.value("STARTINGPOINT").toString();
            QString departurehour = query.value("DEPARTUREHOUR").toString();
            QString departureminute = query.value("DEPARTUREMINUTE").toString();
            QString destination = query.value("DESTINATION").toString();
            QString arrivalhour = query.value("ARRIVALHOUR").toString();
            QString arrivalminute = query.value("ARRIVALMINUTE").toString();
            QString trainprice = query.value("TRAINPRICE").toString();
            QString trainspecialprice = query.value("TRAINSPECIALPRICE").toString();


            // 특 우등실에 값이 없을 때 "─" 이걸로 나타냄
            if (trainspecialprice.isEmpty()) {
                trainspecialprice = "─";
            }

            QLabel *textLabel1 = new QLabel(traintype + "\n" + trainnum);
            QLabel *textLabel2 = new QLabel(departurehour + ":" + departureminute + "\n" + startingpoint);
            QLabel *textLabel3 = new QLabel(arrivalhour + ":" + arrivalminute + "\n" + destination);


            QPushButton *button1 = new QPushButton(trainprice);
            QPushButton *button2 = new QPushButton(trainspecialprice);
            textLabel1->setFixedWidth(maxTextWidth);
            QString buttonStyle = "QPushButton {"

                                  "  border: 1px solid black;"
                                  "  background-color: white;" // 버튼 배경색
                                  "  color: black;" // 버튼 텍스트 색상
                                  "  padding: 0px;" // 텍스트와 버튼 경계 사이의 여백
                                  "  font-size: 12px;" // 폰트 크기 설정
                                  "  width: 13px;" // 버튼의 너비를 설정
                                  "  height: 36px;" // 버튼의 높이를 설정
                                  "}";
            button1->setStyleSheet(buttonStyle);
            button2->setStyleSheet(buttonStyle);
            if (traintype == "KTX")
            {
                // KTX 버튼 생성
                QPushButton *ktxButton = new QPushButton(trainprice);
                ktxButton->setStyleSheet(buttonStyle);

                // KTX 버튼에 대한 이벤트 핸들러 연결
                //                connect(ktxButton, &QPushButton::clicked, this, &CR3_User::KTXPage);
                connect(ktxButton, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    KTXPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(ktxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }
                //                connect(button2, &QPushButton::clicked, this, &CR3_User::KTXROYALPage);
                connect(button2, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    KTXROYALPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(button2, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXROYALPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }

                // 레이아웃에 KTX 버튼 추가
                QHBoxLayout *ktxLayout = new QHBoxLayout;
                ktxLayout->addWidget(textLabel1);
                ktxLayout->addWidget(textLabel2);
                ktxLayout->addWidget(textLabel3);
                ktxLayout->addWidget(ktxButton);
                ktxLayout->addWidget(button2);  // 다른 버튼 추가
                QVBoxLayout *ktxMainLayout = new QVBoxLayout;
                ktxMainLayout->addLayout(ktxLayout);
                QWidget *ktxWidget = new QWidget;
                ktxWidget->setLayout(ktxMainLayout);

                ui->verticalLayout_TrainView->addWidget(ktxWidget);
            }
            else if (traintype == "ITX-새마을")
                {
                // ITX-새마을 버튼 생성
                QPushButton *itxButton = new QPushButton(trainprice);
                itxButton->setStyleSheet(buttonStyle);

                // ITX-새마을 버튼에 대한 이벤트 핸들러 연결
                //                connect(itxButton, &QPushButton::clicked, this, &CR3_User::SMEPage);
                connect(itxButton, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    SMEPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(itxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        SMEPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }

                // 레이아웃에 ITX-새마을 버튼 추가
                QHBoxLayout *itxLayout = new QHBoxLayout;
                itxLayout->addWidget(textLabel1);
                itxLayout->addWidget(textLabel2);
                itxLayout->addWidget(textLabel3);
                itxLayout->addWidget(itxButton);
                itxLayout->addWidget(button2);  // 다른 버튼 추가

                QVBoxLayout *itxMainLayout = new QVBoxLayout;
                itxMainLayout->addLayout(itxLayout);
                QWidget *itxWidget = new QWidget;
                itxWidget->setLayout(itxMainLayout);

                ui->verticalLayout_TrainView->addWidget(itxWidget);
            }
            else if (traintype == "무궁화호")
                {
                // 무궁화호 버튼 생성
                QPushButton *muguButton = new QPushButton(trainprice);
                muguButton->setStyleSheet(buttonStyle);

                // 무궁화호 버튼에 대한 이벤트 핸들러 연결
                //                connect(muguButton, &QPushButton::clicked, this, &CR3_User::MGHPage);
                connect(muguButton, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    MGHPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(muguButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        MGHPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }

                // 레이아웃에 무궁화호 버튼 추가
                QHBoxLayout *muguLayout = new QHBoxLayout;
                muguLayout->addWidget(textLabel1);
                muguLayout->addWidget(textLabel2);
                muguLayout->addWidget(textLabel3);
                muguLayout->addWidget(muguButton);
                muguLayout->addWidget(button2);  // 다른 버튼 추가
                QVBoxLayout *muguMainLayout = new QVBoxLayout;
                muguMainLayout->addLayout(muguLayout);
                QWidget *muguWidget = new QWidget;
                muguWidget->setLayout(muguMainLayout);

                ui->verticalLayout_TrainView->addWidget(muguWidget);
            }
        }
    }
    else
    {
        msgbox4.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");
    }
}



void CR3_User::TrainView1()
{
    qDebug() << "트레인뷰";
    if (totalCount > 0)
    {
        GoChk = 1;
        if (changeChk == 1)
        {
            ChangeSA();
            changeChk = 0;
        }
        ui->stackedWidget->setCurrentIndex(6);
        // ui->label_startTime1->text()에서 시간과 분을 추출
        QString originalText = ui->label_startTime1->text();
        QString timeAndMinute = originalText.split(" ").last(); // "hh:mm" 형식으로 추출
        QStringList parts = timeAndMinute.split(":");
        QString part1 = parts[0];
        QString part2 = parts[1];

        // 시간과 분을 뺀 문자열을 만듦
        QString withoutTime = originalText.left(originalText.indexOf(timeAndMinute));

        // 새로운 형식으로 문자열 조합
        QString newText = withoutTime;
        qDebug() << "선택된 날짜13134444: " << newText;

        ui->label_ChooseDay->setText(newText);
        ui->label_ViewStart->setText(ui->pushButton_start1->text());
        ui->label_ViewArrive->setText(ui->pushButton_arrive1->text());

        QString start1 = ui->pushButton_start1->text();
        QString arrive1 = ui->pushButton_arrive1->text();

        QSqlQuery query;
        query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTINGPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, TRAINPRICE, TRAINSPECIALPRICE FROM TRAINfo "
                      "WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION AND ((DEPARTUREHOUR > :DEPARTUREHOUR) OR (DEPARTUREHOUR = :DEPARTUREHOUR AND DEPARTUREMINUTE > :DEPARTUREMINUTE))");
        query.bindValue(":STARTINGPOINT",start1);
        query.bindValue(":DESTINATION", arrive1);
        query.bindValue(":DEPARTUREHOUR",part1);
        query.bindValue(":DEPARTUREMINUTE",part2);


        if (query.exec())
        {
            int maxTextWidth = 69;

            while(query.next())
            {
                QString traintype = query.value("TRAINTYPE").toString();
                QString trainnum = query.value("TRAINNUM").toString();
                QString startingpoint = query.value("STARTINGPOINT").toString();
                QString departurehour = query.value("DEPARTUREHOUR").toString();
                QString departureminute = query.value("DEPARTUREMINUTE").toString();
                QString destination = query.value("DESTINATION").toString();
                QString arrivalhour = query.value("ARRIVALHOUR").toString();
                QString arrivalminute = query.value("ARRIVALMINUTE").toString();
                QString trainprice = query.value("TRAINPRICE").toString();
                QString trainspecialprice = query.value("TRAINSPECIALPRICE").toString();


                // 특 우등실에 값이 없을 때 "─" 이걸로 나타냄
                if (trainspecialprice.isEmpty()) {
                    trainspecialprice = "─";
                }

                QLabel *textLabel1 = new QLabel(traintype + "\n" + trainnum);
                QLabel *textLabel2 = new QLabel(departurehour + ":" + departureminute + "\n" + startingpoint);
                QLabel *textLabel3 = new QLabel(arrivalhour + ":" + arrivalminute + "\n" + destination);


                QPushButton *button1 = new QPushButton(trainprice);
                QPushButton *button2 = new QPushButton(trainspecialprice);
                textLabel1->setFixedWidth(maxTextWidth);
                QString buttonStyle = "QPushButton {"

                                      "  border: 1px solid black;"
                                      "  background-color: white;" // 버튼 배경색
                                      "  color: black;" // 버튼 텍스트 색상
                                      "  padding: 0px;" // 텍스트와 버튼 경계 사이의 여백
                                      "  font-size: 12px;" // 폰트 크기 설정
                                      "  width: 13px;" // 버튼의 너비를 설정
                                      "  height: 36px;" // 버튼의 높이를 설정
                                      "}";
                button1->setStyleSheet(buttonStyle);
                button2->setStyleSheet(buttonStyle);

                if (traintype == "KTX")
                {
                    // KTX 버튼 생성
                    QPushButton *ktxButton = new QPushButton(trainprice);
                    ktxButton->setStyleSheet(buttonStyle);

                    // KTX 버튼에 대한 이벤트 핸들러 연결
                    //                connect(ktxButton, &QPushButton::clicked, this, &CR3_User::KTXPage);
                    connect(ktxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(ktxButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            KTXPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }
                    //                connect(button2, &QPushButton::clicked, this, &CR3_User::KTXROYALPage);
                    connect(button2, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXROYALPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(button2, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            KTXROYALPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 KTX 버튼 추가
                    QHBoxLayout *ktxLayout = new QHBoxLayout;
                    ktxLayout->addWidget(textLabel1);
                    ktxLayout->addWidget(textLabel2);
                    ktxLayout->addWidget(textLabel3);
                    ktxLayout->addWidget(ktxButton);
                    ktxLayout->addWidget(button2);  // 다른 버튼 추가
                    QVBoxLayout *ktxMainLayout = new QVBoxLayout;
                    ktxMainLayout->addLayout(ktxLayout);
                    QWidget *ktxWidget = new QWidget;
                    ktxWidget->setLayout(ktxMainLayout);

                    ui->verticalLayout_TrainView->addWidget(ktxWidget);
                }
                else if (traintype == "ITX-새마을")
                {
                    // ITX-새마을 버튼 생성
                    QPushButton *itxButton = new QPushButton(trainprice);
                    itxButton->setStyleSheet(buttonStyle);

                    // ITX-새마을 버튼에 대한 이벤트 핸들러 연결
                    //                connect(itxButton, &QPushButton::clicked, this, &CR3_User::SMEPage);
                    connect(itxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        SMEPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(itxButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            SMEPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 ITX-새마을 버튼 추가
                    QHBoxLayout *itxLayout = new QHBoxLayout;
                    itxLayout->addWidget(textLabel1);
                    itxLayout->addWidget(textLabel2);
                    itxLayout->addWidget(textLabel3);
                    itxLayout->addWidget(itxButton);
                    itxLayout->addWidget(button2);  // 다른 버튼 추가

                    QVBoxLayout *itxMainLayout = new QVBoxLayout;
                    itxMainLayout->addLayout(itxLayout);
                    QWidget *itxWidget = new QWidget;
                    itxWidget->setLayout(itxMainLayout);

                    ui->verticalLayout_TrainView->addWidget(itxWidget);
                }
                else if (traintype == "무궁화호")
                {
                    // 무궁화호 버튼 생성
                    QPushButton *muguButton = new QPushButton(trainprice);
                    muguButton->setStyleSheet(buttonStyle);

                    // 무궁화호 버튼에 대한 이벤트 핸들러 연결
                    //                connect(muguButton, &QPushButton::clicked, this, &CR3_User::MGHPage);
                    connect(muguButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        MGHPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(muguButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            MGHPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 무궁화호 버튼 추가
                    QHBoxLayout *muguLayout = new QHBoxLayout;
                    muguLayout->addWidget(textLabel1);
                    muguLayout->addWidget(textLabel2);
                    muguLayout->addWidget(textLabel3);
                    muguLayout->addWidget(muguButton);
                    muguLayout->addWidget(button2);  // 다른 버튼 추가
                    QVBoxLayout *muguMainLayout = new QVBoxLayout;
                    muguMainLayout->addLayout(muguLayout);
                    QWidget *muguWidget = new QWidget;
                    muguWidget->setLayout(muguMainLayout);

                    ui->verticalLayout_TrainView->addWidget(muguWidget);
                }
            }
        }
        else
        {
            msgbox4.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");
        }
    }
    else
    {
        QMessageBox::warning(this, "탑승 인원", "탑승 인원을 골라주세요");
    }
}


// @@@@@@@@@@@@@@@@@ 열차 조회 왕복 @@@@@@@@@@@@@@@@@@
void CR3_User::TrainView2()
{
    if (totalCount > 0)
    {
        GoChk = 2;
        if (changeChk == 1)
        {
            ChangeSA();
            changeChk = 0;
        }
        ui->label_View->setText("가는 열차 조회");
        ui->stackedWidget->setCurrentIndex(6);
        // ui->label_startTime1->text()에서 시간과 분을 추출
        QString originalText = ui->label_startTime1->text();
        QString timeAndMinute = originalText.split(" ").last(); // "hh:mm" 형식으로 추출
        QStringList parts = timeAndMinute.split(":");
        QString part1 = parts[0];
        QString part2 = parts[1];

        // 시간과 분을 뺀 문자열을 만듦
        QString withoutTime = originalText.left(originalText.indexOf(timeAndMinute));

        // 새로운 형식으로 문자열 조합
        QString newText = withoutTime;

        ui->label_ChooseDay->setText(newText);
        ui->label_ViewStart->setText(ui->pushButton_start1_2->text());
        ui->label_ViewArrive->setText(ui->pushButton_arrive1_2->text());
        StartPoint = ui->label_ViewStart->text();
        ArrivePoint = ui->label_ViewArrive->text();

        QSqlQuery query;
        query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTINGPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, TRAINPRICE, TRAINSPECIALPRICE FROM TRAINfo "
                      "WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION AND ((DEPARTUREHOUR > :DEPARTUREHOUR) OR (DEPARTUREHOUR = :DEPARTUREHOUR AND DEPARTUREMINUTE > :DEPARTUREMINUTE))");
        query.bindValue(":STARTINGPOINT",StartPoint);
        query.bindValue(":DESTINATION", ArrivePoint);
        query.bindValue(":DEPARTUREHOUR",part1);
        query.bindValue(":DEPARTUREMINUTE",part2);

        if (query.exec())
        {
            int maxTextWidth = 69;

            while(query.next())
            {
                QString traintype = query.value("TRAINTYPE").toString();
                QString trainnum = query.value("TRAINNUM").toString();
                QString startingpoint = query.value("STARTINGPOINT").toString();
                QString departurehour = query.value("DEPARTUREHOUR").toString();
                QString departureminute = query.value("DEPARTUREMINUTE").toString();
                QString destination = query.value("DESTINATION").toString();
                QString arrivalhour = query.value("ARRIVALHOUR").toString();
                QString arrivalminute = query.value("ARRIVALMINUTE").toString();
                QString trainprice = query.value("TRAINPRICE").toString();
                QString trainspecialprice = query.value("TRAINSPECIALPRICE").toString();


                // 특 우등실에 값이 없을 때 "─" 이걸로 나타냄
                if (trainspecialprice.isEmpty()) {
                    trainspecialprice = "─";
                }

                QLabel *textLabel1 = new QLabel(traintype + "\n" + trainnum);
                QLabel *textLabel2 = new QLabel(departurehour + ":" + departureminute + "\n" + startingpoint);
                QLabel *textLabel3 = new QLabel(arrivalhour + ":" + arrivalminute + "\n" + destination);


                QPushButton *button1 = new QPushButton(trainprice);
                QPushButton *button2 = new QPushButton(trainspecialprice);
                textLabel1->setFixedWidth(maxTextWidth);
                QString buttonStyle = "QPushButton {"

                                      "  border: 1px solid black;"
                                      "  background-color: white;" // 버튼 배경색
                                      "  color: black;" // 버튼 텍스트 색상
                                      "  padding: 0px;" // 텍스트와 버튼 경계 사이의 여백
                                      "  font-size: 12px;" // 폰트 크기 설정
                                      "  width: 13px;" // 버튼의 너비를 설정
                                      "  height: 36px;" // 버튼의 높이를 설정
                                      "}";
                button1->setStyleSheet(buttonStyle);
                button2->setStyleSheet(buttonStyle);

                if (traintype == "KTX")
                {
                    // KTX 버튼 생성
                    QPushButton *ktxButton = new QPushButton(trainprice);
                    ktxButton->setStyleSheet(buttonStyle);

                    // KTX 버튼에 대한 이벤트 핸들러 연결
                    //                connect(ktxButton, &QPushButton::clicked, this, &CR3_User::KTXPage);
                    connect(ktxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(ktxButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            KTXPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }
                    //                connect(button2, &QPushButton::clicked, this, &CR3_User::KTXROYALPage);
                    connect(button2, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXROYALPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(button2, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            KTXROYALPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 KTX 버튼 추가
                    QHBoxLayout *ktxLayout = new QHBoxLayout;
                    ktxLayout->addWidget(textLabel1);
                    ktxLayout->addWidget(textLabel2);
                    ktxLayout->addWidget(textLabel3);
                    ktxLayout->addWidget(ktxButton);
                    ktxLayout->addWidget(button2);  // 다른 버튼 추가
                    QVBoxLayout *ktxMainLayout = new QVBoxLayout;
                    ktxMainLayout->addLayout(ktxLayout);
                    QWidget *ktxWidget = new QWidget;
                    ktxWidget->setLayout(ktxMainLayout);

                    ui->verticalLayout_TrainView->addWidget(ktxWidget);
                }
                else if (traintype == "ITX-새마을")
                {
                    // ITX-새마을 버튼 생성
                    QPushButton *itxButton = new QPushButton(trainprice);
                    itxButton->setStyleSheet(buttonStyle);

                    // ITX-새마을 버튼에 대한 이벤트 핸들러 연결
                    //                connect(itxButton, &QPushButton::clicked, this, &CR3_User::SMEPage);
                    connect(itxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        SMEPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(itxButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            SMEPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }


                    // 레이아웃에 ITX-새마을 버튼 추가
                    QHBoxLayout *itxLayout = new QHBoxLayout;
                    itxLayout->addWidget(textLabel1);
                    itxLayout->addWidget(textLabel2);
                    itxLayout->addWidget(textLabel3);
                    itxLayout->addWidget(itxButton);
                    itxLayout->addWidget(button2);  // 다른 버튼 추가

                    QVBoxLayout *itxMainLayout = new QVBoxLayout;
                    itxMainLayout->addLayout(itxLayout);
                    QWidget *itxWidget = new QWidget;
                    itxWidget->setLayout(itxMainLayout);

                    ui->verticalLayout_TrainView->addWidget(itxWidget);
                }
                else if (traintype == "무궁화호")
                {
                    // 무궁화호 버튼 생성
                    QPushButton *muguButton = new QPushButton(trainprice);
                    muguButton->setStyleSheet(buttonStyle);

                    // 무궁화호 버튼에 대한 이벤트 핸들러 연결
                    //                connect(muguButton, &QPushButton::clicked, this, &CR3_User::MGHPage);
                    connect(muguButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        MGHPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(muguButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            MGHPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 무궁화호 버튼 추가
                    QHBoxLayout *muguLayout = new QHBoxLayout;
                    muguLayout->addWidget(textLabel1);
                    muguLayout->addWidget(textLabel2);
                    muguLayout->addWidget(textLabel3);
                    muguLayout->addWidget(muguButton);
                    muguLayout->addWidget(button2);  // 다른 버튼 추가
                    QVBoxLayout *muguMainLayout = new QVBoxLayout;
                    muguMainLayout->addLayout(muguLayout);
                    QWidget *muguWidget = new QWidget;
                    muguWidget->setLayout(muguMainLayout);

                    ui->verticalLayout_TrainView->addWidget(muguWidget);
                }
            }
        }
        else
        {
            msgbox4.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");
        }
    }
    else
    {
        QMessageBox::warning(this, "탑승 인원", "탑승 인원을 골라주세요");
    }
}


void CR3_User::ktx_timeschedule()
{
    QString originalText = ui->label_startTime1->text();
    QString timeAndMinute = originalText.split(" ").last(); // "hh:mm" 형식으로 추출

    // 시간과 분을 뺀 문자열을 만듦
    QString withoutTime = originalText.left(originalText.indexOf(timeAndMinute));

    // 새로운 형식으로 문자열 조합
    QString newText = withoutTime;

    ui->label_ChooseDay->setText(newText);
    ui->label_ViewStart->setText(ui->pushButton_start1->text());
    ui->label_ViewArrive->setText(ui->pushButton_arrive1->text());
    QString start1 = ui->pushButton_start1->text();
    QString arrive1 = ui->pushButton_arrive1->text();
    QStringList parts = timeAndMinute.split(":");
    QString part1 = parts[0];
    QString part2 = parts[1];
    QSqlQuery query;
    query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTINGPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, TRAINPRICE, TRAINSPECIALPRICE FROM TRAINfo "
                  "WHERE TRAINTYPE =:TRAINTYPE AND STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION AND ((DEPARTUREHOUR > :DEPARTUREHOUR) OR (DEPARTUREHOUR = :DEPARTUREHOUR AND DEPARTUREMINUTE > :DEPARTUREMINUTE))");
    query.bindValue(":TRAINTYPE","KTX");
    query.bindValue(":STARTINGPOINT",start1);
    query.bindValue(":DESTINATION", arrive1);
    query.bindValue(":DEPARTUREHOUR", part1);
    query.bindValue(":DEPARTUREMINUTE",part2);

    if (query.exec())
    {
        int maxTextWidth = 69;

        while(query.next())
        {
            QString traintype = query.value("TRAINTYPE").toString();
            QString trainnum = query.value("TRAINNUM").toString();
            QString startingpoint = query.value("STARTINGPOINT").toString();
            QString departurehour = query.value("DEPARTUREHOUR").toString();
            QString departureminute = query.value("DEPARTUREMINUTE").toString();
            QString destination = query.value("DESTINATION").toString();
            QString arrivalhour = query.value("ARRIVALHOUR").toString();
            QString arrivalminute = query.value("ARRIVALMINUTE").toString();
            QString trainprice = query.value("TRAINPRICE").toString();
            QString trainspecialprice = query.value("TRAINSPECIALPRICE").toString();


            // 특 우등실에 값이 없을 때 "─" 이걸로 나타냄
            if (trainspecialprice.isEmpty()) {
                trainspecialprice = "─";
            }

            QLabel *textLabel1 = new QLabel(traintype + "\n" + trainnum);
            QLabel *textLabel2 = new QLabel(departurehour + ":" + departureminute + "\n" + startingpoint);
            QLabel *textLabel3 = new QLabel(arrivalhour + ":" + arrivalminute + "\n" + destination);
            QPushButton *button1 = new QPushButton(trainprice);
            QPushButton *button2 = new QPushButton(trainspecialprice);
            textLabel1->setFixedWidth(maxTextWidth);
            QString buttonStyle = "QPushButton {"

                                  "  border: 1px solid black;"
                                  "  background-color: white;" // 버튼 배경색
                                  "  color: black;" // 버튼 텍스트 색상
                                  "  padding: 0px;" // 텍스트와 버튼 경계 사이의 여백
                                  "  font-size: 12px;" // 폰트 크기 설정
                                  "  width: 13px;" // 버튼의 너비를 설정
                                  "  height: 36px;" // 버튼의 높이를 설정
                                  "}";
            button1->setStyleSheet(buttonStyle);
            button2->setStyleSheet(buttonStyle);
            QHBoxLayout *layout = new QHBoxLayout;
            layout->addWidget(textLabel1);
            layout->addWidget(textLabel2);
            layout->addWidget(textLabel3);
            layout->addWidget(button1);
            layout->addWidget(button2);
            QVBoxLayout *mainLayout = new QVBoxLayout;
            mainLayout->addLayout(layout);
            QWidget *trainWidget = new QWidget;
            trainWidget->setLayout(mainLayout);

            ui->verticalLayout_TrainView->addWidget(trainWidget);

            //일반실로 이동하면 됨
//            connect(button1, &QPushButton::clicked, this, &CR3_User::KTXPage);
            connect(button1, &QPushButton::clicked, this, [=](){
                selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                KTXPage(); // KTX 페이지로 이동
                ui->label_9999->setText(selectTrainInfo);
                qDebug() << "보여줘요: " << ui->label_9999->text();
            });
            if (GoChk == 3)
            {
                connect(button1, &QPushButton::clicked, this, [=](){
                    selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    KTXPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo2);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
            }
            //특실로 이동하면 됨
//            connect(button2, &QPushButton::clicked, this, &CR3_User::KTXROYALPage);
            connect(button2, &QPushButton::clicked, this, [=](){
                selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                KTXROYALPage(); // KTX 페이지로 이동
                ui->label_9999->setText(selectTrainInfo);
                qDebug() << "보여줘요: " << ui->label_9999->text();
            });
            if (GoChk == 3)
            {
                connect(button2, &QPushButton::clicked, this, [=](){
                    selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    KTXROYALPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo2);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
            }
        }

    }
    else
    {
        msgbox4.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");

    }

}


void CR3_User::itx_timeschedule()
{
    QString originalText = ui->label_startTime1->text();
    QString timeAndMinute = originalText.split(" ").last(); // "hh:mm" 형식으로 추출

    // 시간과 분을 뺀 문자열을 만듦
    QString withoutTime = originalText.left(originalText.indexOf(timeAndMinute));

    // 새로운 형식으로 문자열 조합
    QString newText = withoutTime;

    ui->label_ChooseDay->setText(newText);
    ui->label_ViewStart->setText(ui->pushButton_start1->text());
    ui->label_ViewArrive->setText(ui->pushButton_arrive1->text());
    QString start1 = ui->pushButton_start1->text();
    QString arrive1 = ui->pushButton_arrive1->text();
    QStringList parts = timeAndMinute.split(":");
    QString part1 = parts[0];
    QString part2 = parts[1];

    QSqlQuery query;
    query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTINGPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, TRAINPRICE, TRAINSPECIALPRICE FROM TRAINfo "
                  "WHERE TRAINTYPE =:TRAINTYPE AND STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION AND ((DEPARTUREHOUR > :DEPARTUREHOUR) OR (DEPARTUREHOUR = :DEPARTUREHOUR AND DEPARTUREMINUTE > :DEPARTUREMINUTE))");
    query.bindValue(":TRAINTYPE","ITX-새마을");
    query.bindValue(":STARTINGPOINT",start1);
    query.bindValue(":DESTINATION", arrive1);
    query.bindValue(":DEPARTUREHOUR", part1);
    query.bindValue(":DEPARTUREMINUTE", part2);

    if (query.exec())
    {
        int maxTextWidth = 69;

        while(query.next())
        {
            QString traintype = query.value("TRAINTYPE").toString();
            QString trainnum = query.value("TRAINNUM").toString();
            QString startingpoint = query.value("STARTINGPOINT").toString();
            QString departurehour = query.value("DEPARTUREHOUR").toString();
            QString departureminute = query.value("DEPARTUREMINUTE").toString();
            QString destination = query.value("DESTINATION").toString();
            QString arrivalhour = query.value("ARRIVALHOUR").toString();
            QString arrivalminute = query.value("ARRIVALMINUTE").toString();
            QString trainprice = query.value("TRAINPRICE").toString();
            QString trainspecialprice = query.value("TRAINSPECIALPRICE").toString();


            // 특 우등실에 값이 없을 때 "─" 이걸로 나타냄
            if (trainspecialprice.isEmpty()) {
                trainspecialprice = "─";
            }


            QLabel *textLabel1 = new QLabel(traintype + "\n" + trainnum);
            QLabel *textLabel2 = new QLabel(departurehour + ":" + departureminute + "\n" + startingpoint);
            QLabel *textLabel3 = new QLabel(arrivalhour + ":" + arrivalminute + "\n" + destination);
            QPushButton *button1 = new QPushButton(trainprice);
            QPushButton *button2 = new QPushButton(trainspecialprice);
            textLabel1->setFixedWidth(maxTextWidth);
            QString buttonStyle = "QPushButton {"

                                  "  border: 1px solid black;"
                                  "  background-color: white;" // 버튼 배경색
                                  "  color: black;" // 버튼 텍스트 색상
                                  "  padding: 0px;" // 텍스트와 버튼 경계 사이의 여백
                                  "  font-size: 12px;" // 폰트 크기 설정
                                  "  width: 13px;" // 버튼의 너비를 설정
                                  "  height: 36px;" // 버튼의 높이를 설정
                                  "}";
            button1->setStyleSheet(buttonStyle);
            button2->setStyleSheet(buttonStyle);
            QHBoxLayout *layout = new QHBoxLayout;
            layout->addWidget(textLabel1);
            layout->addWidget(textLabel2);
            layout->addWidget(textLabel3);
            layout->addWidget(button1);
            layout->addWidget(button2);
            QVBoxLayout *mainLayout = new QVBoxLayout;
            mainLayout->addLayout(layout);
            QWidget *trainWidget = new QWidget;
            trainWidget->setLayout(mainLayout);

            ui->verticalLayout_TrainView->addWidget(trainWidget);

            //일반실로 이동하면 됨
//            connect(button1, &QPushButton::clicked, this, &CR3_User::SMEPage);
            connect(button1, &QPushButton::clicked, this, [=](){
                selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                SMEPage(); // KTX 페이지로 이동
                ui->label_9999->setText(selectTrainInfo);
                qDebug() << "보여줘요: " << ui->label_9999->text();
            });
            if (GoChk == 3)
            {
                connect(button1, &QPushButton::clicked, this, [=](){
                    selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    SMEPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo2);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
            }
        }
    }
    else
    {
        msgbox4.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");

    }

}


void CR3_User::flower_timeschedule()
{
    QString originalText = ui->label_startTime1->text();
    QString timeAndMinute = originalText.split(" ").last(); // "hh:mm" 형식으로 추출

    // 시간과 분을 뺀 문자열을 만듦
    QString withoutTime = originalText.left(originalText.indexOf(timeAndMinute));

    // 새로운 형식으로 문자열 조합
    QString newText = withoutTime;

    ui->label_ChooseDay->setText(newText);
    ui->label_ViewStart->setText(ui->pushButton_start1->text());
    ui->label_ViewArrive->setText(ui->pushButton_arrive1->text());
    QString start1 = ui->pushButton_start1->text();
    QString arrive1 = ui->pushButton_arrive1->text();
    QStringList parts = timeAndMinute.split(":");
    QString part1 = parts[0];
    QString part2 = parts[1];

    QSqlQuery query;
    query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTINGPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, TRAINPRICE, TRAINSPECIALPRICE FROM TRAINfo "
                  "WHERE TRAINTYPE =:TRAINTYPE AND STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION AND ((DEPARTUREHOUR > :DEPARTUREHOUR) OR (DEPARTUREHOUR = :DEPARTUREHOUR AND DEPARTUREMINUTE > :DEPARTUREMINUTE))");
    query.bindValue(":TRAINTYPE","무궁화호");
    query.bindValue(":STARTINGPOINT",start1);
    query.bindValue(":DESTINATION", arrive1);
    query.bindValue(":DEPARTUREHOUR", part1);
    query.bindValue(":DEPARTUREMINUTE", part2);

    if (query.exec())
    {
        int maxTextWidth = 69;

        while(query.next())
        {
            QString traintype = query.value("TRAINTYPE").toString();
            QString trainnum = query.value("TRAINNUM").toString();
            QString startingpoint = query.value("STARTINGPOINT").toString();
            QString departurehour = query.value("DEPARTUREHOUR").toString();
            QString departureminute = query.value("DEPARTUREMINUTE").toString();
            QString destination = query.value("DESTINATION").toString();
            QString arrivalhour = query.value("ARRIVALHOUR").toString();
            QString arrivalminute = query.value("ARRIVALMINUTE").toString();
            QString trainprice = query.value("TRAINPRICE").toString();
            QString trainspecialprice = query.value("TRAINSPECIALPRICE").toString();


            // 특 우등실에 값이 없을 때 "─" 이걸로 나타냄
            if (trainspecialprice.isEmpty()) {
                trainspecialprice = "─";
            }


            QLabel *textLabel1 = new QLabel(traintype + "\n" + trainnum);
            QLabel *textLabel2 = new QLabel(departurehour + ":" + departureminute + "\n" + startingpoint);
            QLabel *textLabel3 = new QLabel(arrivalhour + ":" + arrivalminute + "\n" + destination);
            QPushButton *button1 = new QPushButton(trainprice);
            QPushButton *button2 = new QPushButton(trainspecialprice);
            textLabel1->setFixedWidth(maxTextWidth);
            QString buttonStyle = "QPushButton {"

                                  "  border: 1px solid black;"
                                  "  background-color: white;" // 버튼 배경색
                                  "  color: black;" // 버튼 텍스트 색상
                                  "  padding: 0px;" // 텍스트와 버튼 경계 사이의 여백
                                  "  font-size: 12px;" // 폰트 크기 설정
                                  "  width: 13px;" // 버튼의 너비를 설정
                                  "  height: 36px;" // 버튼의 높이를 설정
                                  "}";
            button1->setStyleSheet(buttonStyle);
            button2->setStyleSheet(buttonStyle);
            QHBoxLayout *layout = new QHBoxLayout;
            layout->addWidget(textLabel1);
            layout->addWidget(textLabel2);
            layout->addWidget(textLabel3);
            layout->addWidget(button1);
            layout->addWidget(button2);
            QVBoxLayout *mainLayout = new QVBoxLayout;
            mainLayout->addLayout(layout);
            QWidget *trainWidget = new QWidget;
            trainWidget->setLayout(mainLayout);

            ui->verticalLayout_TrainView->addWidget(trainWidget);

            //일반실로 이동하면 됨
//            connect(button1, &QPushButton::clicked, this, &CR3_User::MGHPage);
            connect(button1, &QPushButton::clicked, this, [=](){
                selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                MGHPage(); // KTX 페이지로 이동
                ui->label_9999->setText(selectTrainInfo);
                qDebug() << "보여줘요: " << ui->label_9999->text();
            });
            if (GoChk == 3)
            {
                connect(button1, &QPushButton::clicked, this, [=](){
                    selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    MGHPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo2);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
            }
        }
    }
    else
    {
        msgbox4.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");

    }

}

void CR3_User::on_comboBox_Train_activated(int index)
{
    if (index == 0)
    {
        QLayoutItem* item;
        while ((item = ui->verticalLayout_TrainView->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        TrainView1();

    }

    else if(index==1)
    {
        QLayoutItem* item;
        while ((item = ui->verticalLayout_TrainView->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        ktx_timeschedule();

    }
    else if(index==2)
    {
        QLayoutItem* item;
        while ((item = ui->verticalLayout_TrainView->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        itx_timeschedule();

    }
    else if(index==3)
    {
        QLayoutItem* item;
        while ((item = ui->verticalLayout_TrainView->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        flower_timeschedule();

    }

}

// 이전날 누를 시 시간표 최신화
void CR3_User::BeforeTimeschedule()
{
    if (time_cnt > 0)
    {
        QLayoutItem* item;
        while ((item = ui->verticalLayout_TrainView->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }

        ui->label_ViewStart->setText(ui->pushButton_start1->text());
        ui->label_ViewArrive->setText(ui->pushButton_arrive1->text());
        QString start1 = ui->pushButton_start1->text();
        QString arrive1 = ui->pushButton_arrive1->text();
        QSqlQuery query;
        query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTINGPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, TRAINPRICE, TRAINSPECIALPRICE FROM TRAINfo "
                      "WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
        query.bindValue(":STARTINGPOINT",start1);
        query.bindValue(":DESTINATION", arrive1);

        if (query.exec())
        {
            int maxTextWidth = 69;

            while(query.next())
            {
                QString traintype = query.value("TRAINTYPE").toString();
                QString trainnum = query.value("TRAINNUM").toString();
                QString startingpoint = query.value("STARTINGPOINT").toString();
                QString departurehour = query.value("DEPARTUREHOUR").toString();
                QString departureminute = query.value("DEPARTUREMINUTE").toString();
                QString destination = query.value("DESTINATION").toString();
                QString arrivalhour = query.value("ARRIVALHOUR").toString();
                QString arrivalminute = query.value("ARRIVALMINUTE").toString();
                QString trainprice = query.value("TRAINPRICE").toString();
                QString trainspecialprice = query.value("TRAINSPECIALPRICE").toString();


                // 특 우등실에 값이 없을 때 "─" 이걸로 나타냄
                if (trainspecialprice.isEmpty()) {
                    trainspecialprice = "─";
                }


                QLabel *textLabel1 = new QLabel(traintype + "\n" + trainnum);
                QLabel *textLabel2 = new QLabel(departurehour + ":" + departureminute + "\n" + startingpoint);
                QLabel *textLabel3 = new QLabel(arrivalhour + ":" + arrivalminute + "\n" + destination);


                QPushButton *button1 = new QPushButton(trainprice);
                QPushButton *button2 = new QPushButton(trainspecialprice);
                textLabel1->setFixedWidth(maxTextWidth);
                QString buttonStyle = "QPushButton {"

                                      "  border: 1px solid black;"
                                      "  background-color: white;" // 버튼 배경색
                                      "  color: black;" // 버튼 텍스트 색상
                                      "  padding: 0px;" // 텍스트와 버튼 경계 사이의 여백
                                      "  font-size: 12px;" // 폰트 크기 설정
                                      "  width: 13px;" // 버튼의 너비를 설정
                                      "  height: 36px;" // 버튼의 높이를 설정
                                      "}";
                button1->setStyleSheet(buttonStyle);
                button2->setStyleSheet(buttonStyle);

                if (traintype == "KTX")
                {
                    // KTX 버튼 생성
                    QPushButton *ktxButton = new QPushButton(trainprice);
                    ktxButton->setStyleSheet(buttonStyle);

                    // KTX 버튼에 대한 이벤트 핸들러 연결
                    //                connect(ktxButton, &QPushButton::clicked, this, &CR3_User::KTXPage);
                    connect(ktxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(ktxButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            KTXPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }
                    //                connect(button2, &QPushButton::clicked, this, &CR3_User::KTXROYALPage);
                    connect(button2, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXROYALPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(button2, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            KTXROYALPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 KTX 버튼 추가
                    QHBoxLayout *ktxLayout = new QHBoxLayout;
                    ktxLayout->addWidget(textLabel1);
                    ktxLayout->addWidget(textLabel2);
                    ktxLayout->addWidget(textLabel3);
                    ktxLayout->addWidget(ktxButton);
                    ktxLayout->addWidget(button2);  // 다른 버튼 추가
                    QVBoxLayout *ktxMainLayout = new QVBoxLayout;
                    ktxMainLayout->addLayout(ktxLayout);
                    QWidget *ktxWidget = new QWidget;
                    ktxWidget->setLayout(ktxMainLayout);

                    ui->verticalLayout_TrainView->addWidget(ktxWidget);
                }
                else if (traintype == "ITX-새마을")
                {
                    // ITX-새마을 버튼 생성
                    QPushButton *itxButton = new QPushButton(trainprice);
                    itxButton->setStyleSheet(buttonStyle);

                    // ITX-새마을 버튼에 대한 이벤트 핸들러 연결
                    //                connect(itxButton, &QPushButton::clicked, this, &CR3_User::SMEPage);
                    connect(itxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        SMEPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(itxButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            SMEPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 ITX-새마을 버튼 추가
                    QHBoxLayout *itxLayout = new QHBoxLayout;
                    itxLayout->addWidget(textLabel1);
                    itxLayout->addWidget(textLabel2);
                    itxLayout->addWidget(textLabel3);
                    itxLayout->addWidget(itxButton);
                    itxLayout->addWidget(button2);  // 다른 버튼 추가

                    QVBoxLayout *itxMainLayout = new QVBoxLayout;
                    itxMainLayout->addLayout(itxLayout);
                    QWidget *itxWidget = new QWidget;
                    itxWidget->setLayout(itxMainLayout);

                    ui->verticalLayout_TrainView->addWidget(itxWidget);
                }
                else if (traintype == "무궁화호")
                {
                    // 무궁화호 버튼 생성
                    QPushButton *muguButton = new QPushButton(trainprice);
                    muguButton->setStyleSheet(buttonStyle);

                    // 무궁화호 버튼에 대한 이벤트 핸들러 연결
                    //                connect(muguButton, &QPushButton::clicked, this, &CR3_User::MGHPage);
                    connect(muguButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        MGHPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(muguButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            MGHPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 무궁화호 버튼 추가
                    QHBoxLayout *muguLayout = new QHBoxLayout;
                    muguLayout->addWidget(textLabel1);
                    muguLayout->addWidget(textLabel2);
                    muguLayout->addWidget(textLabel3);
                    muguLayout->addWidget(muguButton);
                    muguLayout->addWidget(button2);  // 다른 버튼 추가
                    QVBoxLayout *muguMainLayout = new QVBoxLayout;
                    muguMainLayout->addLayout(muguLayout);
                    QWidget *muguWidget = new QWidget;
                    muguWidget->setLayout(muguMainLayout);

                    ui->verticalLayout_TrainView->addWidget(muguWidget);
                }
            }
            time_cnt -= 1;
            qDebug() << "time_cnt: " <<time_cnt;
            if (time_cnt == 0)
            {

                CurrentView();
            }
        }
        else
        {
            msgbox4.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");
        }
    }
}

void CR3_User::BeforeTimeschedule2()
{
    if (time_cnt > 0)
    {
        QLayoutItem* item;
        while ((item = ui->verticalLayout_TrainView->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }

        ui->label_ViewStart->setText(ui->pushButton_start1->text());
        ui->label_ViewArrive->setText(ui->pushButton_arrive1->text());
        QString start1 = ui->pushButton_start1->text();
        QString arrive1 = ui->pushButton_arrive1->text();
        QSqlQuery query;
        query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTINGPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, TRAINPRICE, TRAINSPECIALPRICE FROM TRAINfo "
                      "WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
        query.bindValue(":STARTINGPOINT",start1);
        query.bindValue(":DESTINATION", arrive1);

        if (query.exec())
        {
            int maxTextWidth = 69;

            while(query.next())
            {
                QString traintype = query.value("TRAINTYPE").toString();
                QString trainnum = query.value("TRAINNUM").toString();
                QString startingpoint = query.value("STARTINGPOINT").toString();
                QString departurehour = query.value("DEPARTUREHOUR").toString();
                QString departureminute = query.value("DEPARTUREMINUTE").toString();
                QString destination = query.value("DESTINATION").toString();
                QString arrivalhour = query.value("ARRIVALHOUR").toString();
                QString arrivalminute = query.value("ARRIVALMINUTE").toString();
                QString trainprice = query.value("TRAINPRICE").toString();
                QString trainspecialprice = query.value("TRAINSPECIALPRICE").toString();


                // 특 우등실에 값이 없을 때 "─" 이걸로 나타냄
                if (trainspecialprice.isEmpty()) {
                    trainspecialprice = "─";
                }


                QLabel *textLabel1 = new QLabel(traintype + "\n" + trainnum);
                QLabel *textLabel2 = new QLabel(departurehour + ":" + departureminute + "\n" + startingpoint);
                QLabel *textLabel3 = new QLabel(arrivalhour + ":" + arrivalminute + "\n" + destination);


                QPushButton *button1 = new QPushButton(trainprice);
                QPushButton *button2 = new QPushButton(trainspecialprice);
                textLabel1->setFixedWidth(maxTextWidth);
                QString buttonStyle = "QPushButton {"

                                      "  border: 1px solid black;"
                                      "  background-color: white;" // 버튼 배경색
                                      "  color: black;" // 버튼 텍스트 색상
                                      "  padding: 0px;" // 텍스트와 버튼 경계 사이의 여백
                                      "  font-size: 12px;" // 폰트 크기 설정
                                      "  width: 13px;" // 버튼의 너비를 설정
                                      "  height: 36px;" // 버튼의 높이를 설정
                                      "}";
                button1->setStyleSheet(buttonStyle);
                button2->setStyleSheet(buttonStyle);

                if (traintype == "KTX")
                {
                    // KTX 버튼 생성
                    QPushButton *ktxButton = new QPushButton(trainprice);
                    ktxButton->setStyleSheet(buttonStyle);

                    // KTX 버튼에 대한 이벤트 핸들러 연결
                    //                connect(ktxButton, &QPushButton::clicked, this, &CR3_User::KTXPage);
                    connect(ktxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(ktxButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            KTXPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }
                    //                connect(button2, &QPushButton::clicked, this, &CR3_User::KTXROYALPage);
                    connect(button2, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXROYALPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(button2, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            KTXROYALPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 KTX 버튼 추가
                    QHBoxLayout *ktxLayout = new QHBoxLayout;
                    ktxLayout->addWidget(textLabel1);
                    ktxLayout->addWidget(textLabel2);
                    ktxLayout->addWidget(textLabel3);
                    ktxLayout->addWidget(ktxButton);
                    ktxLayout->addWidget(button2);  // 다른 버튼 추가
                    QVBoxLayout *ktxMainLayout = new QVBoxLayout;
                    ktxMainLayout->addLayout(ktxLayout);
                    QWidget *ktxWidget = new QWidget;
                    ktxWidget->setLayout(ktxMainLayout);

                    ui->verticalLayout_TrainView->addWidget(ktxWidget);
                }
                else if (traintype == "ITX-새마을")
                {
                    // ITX-새마을 버튼 생성
                    QPushButton *itxButton = new QPushButton(trainprice);
                    itxButton->setStyleSheet(buttonStyle);

                    // ITX-새마을 버튼에 대한 이벤트 핸들러 연결
                    connect(itxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        SMEPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(itxButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            SMEPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 ITX-새마을 버튼 추가
                    QHBoxLayout *itxLayout = new QHBoxLayout;
                    itxLayout->addWidget(textLabel1);
                    itxLayout->addWidget(textLabel2);
                    itxLayout->addWidget(textLabel3);
                    itxLayout->addWidget(itxButton);
                    itxLayout->addWidget(button2);  // 다른 버튼 추가

                    QVBoxLayout *itxMainLayout = new QVBoxLayout;
                    itxMainLayout->addLayout(itxLayout);
                    QWidget *itxWidget = new QWidget;
                    itxWidget->setLayout(itxMainLayout);

                    ui->verticalLayout_TrainView->addWidget(itxWidget);
                }
                else if (traintype == "무궁화호")
                {
                    // 무궁화호 버튼 생성
                    QPushButton *muguButton = new QPushButton(trainprice);
                    muguButton->setStyleSheet(buttonStyle);

                    // 무궁화호 버튼에 대한 이벤트 핸들러 연결
                    //                connect(muguButton, &QPushButton::clicked, this, &CR3_User::MGHPage);
                    connect(muguButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        MGHPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(muguButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            MGHPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 무궁화호 버튼 추가
                    QHBoxLayout *muguLayout = new QHBoxLayout;
                    muguLayout->addWidget(textLabel1);
                    muguLayout->addWidget(textLabel2);
                    muguLayout->addWidget(textLabel3);
                    muguLayout->addWidget(muguButton);
                    muguLayout->addWidget(button2);  // 다른 버튼 추가
                    QVBoxLayout *muguMainLayout = new QVBoxLayout;
                    muguMainLayout->addLayout(muguLayout);
                    QWidget *muguWidget = new QWidget;
                    muguWidget->setLayout(muguMainLayout);

                    ui->verticalLayout_TrainView->addWidget(muguWidget);
                }
            }
            time_cnt -= 1;
            qDebug() << "time_cnt: " <<time_cnt;
            if (time_cnt == 0)
            {

                CurrentView2();
            }
        }
        else
        {
            msgbox4.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");
        }
    }
}

void CR3_User::BeforeTimeschedule3()
{
    if (time_cnt > 0)
    {
        QLayoutItem* item;
        while ((item = ui->verticalLayout_TrainView->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }

        ui->label_ViewStart->setText(ui->pushButton_start1->text());
        ui->label_ViewArrive->setText(ui->pushButton_arrive1->text());
        QString start1 = ui->pushButton_start1->text();
        QString arrive1 = ui->pushButton_arrive1->text();
        QSqlQuery query;
        query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTINGPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, TRAINPRICE, TRAINSPECIALPRICE FROM TRAINfo "
                      "WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
        query.bindValue(":STARTINGPOINT",start1);
        query.bindValue(":DESTINATION", arrive1);

        if (query.exec())
        {
            int maxTextWidth = 69;

            while(query.next())
            {
                QString traintype = query.value("TRAINTYPE").toString();
                QString trainnum = query.value("TRAINNUM").toString();
                QString startingpoint = query.value("STARTINGPOINT").toString();
                QString departurehour = query.value("DEPARTUREHOUR").toString();
                QString departureminute = query.value("DEPARTUREMINUTE").toString();
                QString destination = query.value("DESTINATION").toString();
                QString arrivalhour = query.value("ARRIVALHOUR").toString();
                QString arrivalminute = query.value("ARRIVALMINUTE").toString();
                QString trainprice = query.value("TRAINPRICE").toString();
                QString trainspecialprice = query.value("TRAINSPECIALPRICE").toString();


                // 특 우등실에 값이 없을 때 "─" 이걸로 나타냄
                if (trainspecialprice.isEmpty()) {
                    trainspecialprice = "─";
                }


                QLabel *textLabel1 = new QLabel(traintype + "\n" + trainnum);
                QLabel *textLabel2 = new QLabel(departurehour + ":" + departureminute + "\n" + startingpoint);
                QLabel *textLabel3 = new QLabel(arrivalhour + ":" + arrivalminute + "\n" + destination);


                QPushButton *button1 = new QPushButton(trainprice);
                QPushButton *button2 = new QPushButton(trainspecialprice);
                textLabel1->setFixedWidth(maxTextWidth);
                QString buttonStyle = "QPushButton {"

                                      "  border: 1px solid black;"
                                      "  background-color: white;" // 버튼 배경색
                                      "  color: black;" // 버튼 텍스트 색상
                                      "  padding: 0px;" // 텍스트와 버튼 경계 사이의 여백
                                      "  font-size: 12px;" // 폰트 크기 설정
                                      "  width: 13px;" // 버튼의 너비를 설정
                                      "  height: 36px;" // 버튼의 높이를 설정
                                      "}";
                button1->setStyleSheet(buttonStyle);
                button2->setStyleSheet(buttonStyle);

                if (traintype == "KTX")
                {
                    // KTX 버튼 생성
                    QPushButton *ktxButton = new QPushButton(trainprice);
                    ktxButton->setStyleSheet(buttonStyle);

                    // KTX 버튼에 대한 이벤트 핸들러 연결
                    //                connect(ktxButton, &QPushButton::clicked, this, &CR3_User::KTXPage);
                    connect(ktxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(ktxButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            KTXPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }
                    //                connect(button2, &QPushButton::clicked, this, &CR3_User::KTXROYALPage);
                    connect(button2, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXROYALPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(button2, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            KTXROYALPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 KTX 버튼 추가
                    QHBoxLayout *ktxLayout = new QHBoxLayout;
                    ktxLayout->addWidget(textLabel1);
                    ktxLayout->addWidget(textLabel2);
                    ktxLayout->addWidget(textLabel3);
                    ktxLayout->addWidget(ktxButton);
                    ktxLayout->addWidget(button2);  // 다른 버튼 추가
                    QVBoxLayout *ktxMainLayout = new QVBoxLayout;
                    ktxMainLayout->addLayout(ktxLayout);
                    QWidget *ktxWidget = new QWidget;
                    ktxWidget->setLayout(ktxMainLayout);

                    ui->verticalLayout_TrainView->addWidget(ktxWidget);
                }
                else if (traintype == "ITX-새마을")
                {
                    // ITX-새마을 버튼 생성
                    QPushButton *itxButton = new QPushButton(trainprice);
                    itxButton->setStyleSheet(buttonStyle);

                    // ITX-새마을 버튼에 대한 이벤트 핸들러 연결
                    //                connect(itxButton, &QPushButton::clicked, this, &CR3_User::SMEPage);
                    connect(itxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        SMEPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(itxButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            SMEPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 ITX-새마을 버튼 추가
                    QHBoxLayout *itxLayout = new QHBoxLayout;
                    itxLayout->addWidget(textLabel1);
                    itxLayout->addWidget(textLabel2);
                    itxLayout->addWidget(textLabel3);
                    itxLayout->addWidget(itxButton);
                    itxLayout->addWidget(button2);  // 다른 버튼 추가

                    QVBoxLayout *itxMainLayout = new QVBoxLayout;
                    itxMainLayout->addLayout(itxLayout);
                    QWidget *itxWidget = new QWidget;
                    itxWidget->setLayout(itxMainLayout);

                    ui->verticalLayout_TrainView->addWidget(itxWidget);
                }
                else if (traintype == "무궁화호")
                {
                    // 무궁화호 버튼 생성
                    QPushButton *muguButton = new QPushButton(trainprice);
                    muguButton->setStyleSheet(buttonStyle);

                    // 무궁화호 버튼에 대한 이벤트 핸들러 연결
                    //                connect(muguButton, &QPushButton::clicked, this, &CR3_User::MGHPage);
                    connect(muguButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        MGHPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                    if (GoChk == 3)
                    {
                        connect(muguButton, &QPushButton::clicked, this, [=](){
                            selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                            MGHPage(); // KTX 페이지로 이동
                            ui->label_9999->setText(selectTrainInfo2);
                            qDebug() << "보여줘요: " << ui->label_9999->text();
                        });
                    }

                    // 레이아웃에 무궁화호 버튼 추가
                    QHBoxLayout *muguLayout = new QHBoxLayout;
                    muguLayout->addWidget(textLabel1);
                    muguLayout->addWidget(textLabel2);
                    muguLayout->addWidget(textLabel3);
                    muguLayout->addWidget(muguButton);
                    muguLayout->addWidget(button2);  // 다른 버튼 추가
                    QVBoxLayout *muguMainLayout = new QVBoxLayout;
                    muguMainLayout->addLayout(muguLayout);
                    QWidget *muguWidget = new QWidget;
                    muguWidget->setLayout(muguMainLayout);

                    ui->verticalLayout_TrainView->addWidget(muguWidget);
                }
            }
            time_cnt -= 1;
            qDebug() << "time_cnt: " <<time_cnt;
            if (time_cnt == 0)
            {

                CurrentView3();
            }
        }
        else
        {
            msgbox4.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");
        }
    }
}


// @@@@@@@@@@@@@@@@@ 열차 조회에서 이전날 @@@@@@@@@@@@@@@@@@
void CR3_User::BeforeDay()
{
    // 현재 라벨에 표시된 날짜를 가져와서 QDate로 변환
    if (GoChk == 1)
    {
        QString selectDateString = ui->label_startTime1->text();
        QStringList parts = selectDateString.split(" "); // 공백으로 문자열 분할
        QString datePart; // 날짜 부분을 저장할 변수 초기화

        // 분할된 부분 중에서 요일과 시간을 제외한 부분을 선택
        if (parts.size() >= 4) {
            datePart = parts[0] + " " + parts[1] + " " + parts[2];
        } else {
            // 처리할 부분이 충분하지 않다면 에러 처리 또는 기본값 설정
            datePart = "날짜를 찾을 수 없음";
        }

        // 추출한 날짜 부분을 이용하여 QDate로 변환
        QDate selectedDate = QDate::fromString(datePart, "yyyy년 MM월 dd일");

        QString currentDateString = ui->label_ChooseDay->text();
        int indexOfParenthesis = currentDateString.lastIndexOf('('); // 요일 정보의 시작 위치 찾기
        if (indexOfParenthesis != -1)
        {
            QString datePart = currentDateString.mid(0, indexOfParenthesis).trimmed(); // 요일 정보 이전의 부분 추출
            QDate currentDate = QDate::fromString(datePart, "yyyy년 MM월 dd일");
            qDebug() << currentDate;

            // 가져온 날짜를 그대로 사용
            QDate minDate = selectedDate;

            // 이전 날짜와 최소 날짜 비교
            if (currentDate > minDate)
            {
                currentDate = currentDate.addDays(-1);

                // 요일을 문자열로 변환
                QString dayOfWeekString;
                switch (currentDate.dayOfWeek()) {
                case Qt::Monday:
                    dayOfWeekString = "(월)";
                    break;
                case Qt::Tuesday:
                    dayOfWeekString = "(화)";
                    break;
                case Qt::Wednesday:
                    dayOfWeekString = "(수)";
                    break;
                case Qt::Thursday:
                    dayOfWeekString = "(목)";
                    break;
                case Qt::Friday:
                    dayOfWeekString = "(금)";
                    break;
                case Qt::Saturday:
                    dayOfWeekString = "(토)";
                    break;
                case Qt::Sunday:
                    dayOfWeekString = "(일)";
                    break;
                default:
                    dayOfWeekString = "알 수 없음";
                    break;
                }
                // 날짜와 요일을 함께 표시하는 형식으로 변환
                QString formattedDate = currentDate.toString("yyyy년 MM월 dd일") + dayOfWeekString;

                ui->label_ChooseDay->setText(formattedDate);
            }
            BeforeTimeschedule();
        }
        else
        {
            QDate currentDate = QDate::fromString(currentDateString, "yyyy년 MM월 dd일");

            // 가져온 날짜를 그대로 사용
            QDate minDate = selectedDate;

            // 이전 날짜와 최소 날짜 비교
            if (currentDate > minDate)
            {
                currentDate = currentDate.addDays(-1);

                // 요일을 문자열로 변환
                QString dayOfWeekString;
                switch (currentDate.dayOfWeek()) {
                case Qt::Monday:
                    dayOfWeekString = "(월)";
                    break;
                case Qt::Tuesday:
                    dayOfWeekString = "(화)";
                    break;
                case Qt::Wednesday:
                    dayOfWeekString = "(수)";
                    break;
                case Qt::Thursday:
                    dayOfWeekString = "(목)";
                    break;
                case Qt::Friday:
                    dayOfWeekString = "(금)";
                    break;
                case Qt::Saturday:
                    dayOfWeekString = "(토)";
                    break;
                case Qt::Sunday:
                    dayOfWeekString = "(일)";
                    break;
                default:
                    dayOfWeekString = "알 수 없음";
                    break;
                }

                // 날짜와 요일을 함께 표시하는 형식으로 변환
                QString formattedDate = currentDate.toString("yyyy년 MM월 dd일") + dayOfWeekString;

                ui->label_ChooseDay->setText(formattedDate);
            }
            BeforeTimeschedule();
        }
    }

    else if (GoChk == 2)
    {
        QString selectDateString = ui->label_startTime1_2->text();
        QStringList parts = selectDateString.split(" "); // 공백으로 문자열 분할
        QString datePart; // 날짜 부분을 저장할 변수 초기화

        // 분할된 부분 중에서 요일과 시간을 제외한 부분을 선택
        if (parts.size() >= 4) {
            datePart = parts[0] + " " + parts[1] + " " + parts[2];
        } else {
            // 처리할 부분이 충분하지 않다면 에러 처리 또는 기본값 설정
            datePart = "날짜를 찾을 수 없음";
        }

        // 추출한 날짜 부분을 이용하여 QDate로 변환
        QDate selectedDate = QDate::fromString(datePart, "yyyy년 MM월 dd일");

        QString currentDateString = ui->label_ChooseDay->text();
        int indexOfParenthesis = currentDateString.lastIndexOf('('); // 요일 정보의 시작 위치 찾기
        if (indexOfParenthesis != -1)
        {
            QString datePart = currentDateString.mid(0, indexOfParenthesis).trimmed(); // 요일 정보 이전의 부분 추출
            QDate currentDate = QDate::fromString(datePart, "yyyy년 MM월 dd일");
            qDebug() << currentDate;

            // 가져온 날짜를 그대로 사용
            QDate minDate = selectedDate;

            // 이전 날짜와 최소 날짜 비교
            if (currentDate > minDate)
            {
                currentDate = currentDate.addDays(-1);

                // 요일을 문자열로 변환
                QString dayOfWeekString;
                switch (currentDate.dayOfWeek()) {
                case Qt::Monday:
                    dayOfWeekString = "(월)";
                    break;
                case Qt::Tuesday:
                    dayOfWeekString = "(화)";
                    break;
                case Qt::Wednesday:
                    dayOfWeekString = "(수)";
                    break;
                case Qt::Thursday:
                    dayOfWeekString = "(목)";
                    break;
                case Qt::Friday:
                    dayOfWeekString = "(금)";
                    break;
                case Qt::Saturday:
                    dayOfWeekString = "(토)";
                    break;
                case Qt::Sunday:
                    dayOfWeekString = "(일)";
                    break;
                default:
                    dayOfWeekString = "알 수 없음";
                    break;
                }
                // 날짜와 요일을 함께 표시하는 형식으로 변환
                QString formattedDate = currentDate.toString("yyyy년 MM월 dd일") + dayOfWeekString;

                ui->label_ChooseDay->setText(formattedDate);
            }
            BeforeTimeschedule2();
        }
        else
        {
            QDate currentDate = QDate::fromString(currentDateString, "yyyy년 MM월 dd일");

            // 가져온 날짜를 그대로 사용
            QDate minDate = selectedDate;

            // 이전 날짜와 최소 날짜 비교
            if (currentDate > minDate)
            {
                currentDate = currentDate.addDays(-1);

                // 요일을 문자열로 변환
                QString dayOfWeekString;
                switch (currentDate.dayOfWeek()) {
                case Qt::Monday:
                    dayOfWeekString = "(월)";
                    break;
                case Qt::Tuesday:
                    dayOfWeekString = "(화)";
                    break;
                case Qt::Wednesday:
                    dayOfWeekString = "(수)";
                    break;
                case Qt::Thursday:
                    dayOfWeekString = "(목)";
                    break;
                case Qt::Friday:
                    dayOfWeekString = "(금)";
                    break;
                case Qt::Saturday:
                    dayOfWeekString = "(토)";
                    break;
                case Qt::Sunday:
                    dayOfWeekString = "(일)";
                    break;
                default:
                    dayOfWeekString = "알 수 없음";
                    break;
                }

                // 날짜와 요일을 함께 표시하는 형식으로 변환
                QString formattedDate = currentDate.toString("yyyy년 MM월 dd일") + dayOfWeekString;

                ui->label_ChooseDay->setText(formattedDate);
            }
            BeforeTimeschedule2();
        }
    }

    else if (GoChk == 3)
    {
        QString selectDateString = ui->label_startTime1_3->text();
        QStringList parts = selectDateString.split(" "); // 공백으로 문자열 분할
        QString datePart; // 날짜 부분을 저장할 변수 초기화

        // 분할된 부분 중에서 요일과 시간을 제외한 부분을 선택
        if (parts.size() >= 4) {
            datePart = parts[0] + " " + parts[1] + " " + parts[2];
        } else {
            // 처리할 부분이 충분하지 않다면 에러 처리 또는 기본값 설정
            datePart = "날짜를 찾을 수 없음";
        }

        // 추출한 날짜 부분을 이용하여 QDate로 변환
        QDate selectedDate = QDate::fromString(datePart, "yyyy년 MM월 dd일");

        QString currentDateString = ui->label_ChooseDay->text();
        int indexOfParenthesis = currentDateString.lastIndexOf('('); // 요일 정보의 시작 위치 찾기
        if (indexOfParenthesis != -1)
        {
            QString datePart = currentDateString.mid(0, indexOfParenthesis).trimmed(); // 요일 정보 이전의 부분 추출
            QDate currentDate = QDate::fromString(datePart, "yyyy년 MM월 dd일");
            qDebug() << currentDate;

            // 가져온 날짜를 그대로 사용
            QDate minDate = selectedDate;

            // 이전 날짜와 최소 날짜 비교
            if (currentDate > minDate)
            {
                                                                                              currentDate = currentDate.addDays(-1);

                                                                                              // 요일을 문자열로 변환
                                                                                              QString dayOfWeekString;
                                                                                              switch (currentDate.dayOfWeek()) {
                                                                                              case Qt::Monday:
                    dayOfWeekString = "(월)";
                    break;
                                                                                              case Qt::Tuesday:
                    dayOfWeekString = "(화)";
                    break;
                                                                                              case Qt::Wednesday:
                    dayOfWeekString = "(수)";
                    break;
                                                                                              case Qt::Thursday:
                    dayOfWeekString = "(목)";
                    break;
                                                                                              case Qt::Friday:
                    dayOfWeekString = "(금)";
                    break;
                                                                                              case Qt::Saturday:
                    dayOfWeekString = "(토)";
                    break;
                                                                                              case Qt::Sunday:
                    dayOfWeekString = "(일)";
                    break;
                                                                                              default:
                    dayOfWeekString = "알 수 없음";
                    break;
                                                                                              }
                                                                                              // 날짜와 요일을 함께 표시하는 형식으로 변환
                                                                                              QString formattedDate = currentDate.toString("yyyy년 MM월 dd일") + dayOfWeekString;

                                                                                                                                                                            ui->label_ChooseDay->setText(formattedDate);
            }
            BeforeTimeschedule3();
        }
        else
        {
            QDate currentDate = QDate::fromString(currentDateString, "yyyy년 MM월 dd일");

            // 가져온 날짜를 그대로 사용
            QDate minDate = selectedDate;

            // 이전 날짜와 최소 날짜 비교
            if (currentDate > minDate)
            {
                                                                                              currentDate = currentDate.addDays(-1);

                                                                                              // 요일을 문자열로 변환
                                                                                              QString dayOfWeekString;
                                                                                              switch (currentDate.dayOfWeek()) {
                                                                                              case Qt::Monday:
                    dayOfWeekString = "(월)";
                    break;
                                                                                              case Qt::Tuesday:
                    dayOfWeekString = "(화)";
                    break;
                                                                                              case Qt::Wednesday:
                    dayOfWeekString = "(수)";
                    break;
                                                                                              case Qt::Thursday:
                    dayOfWeekString = "(목)";
                    break;
                                                                                              case Qt::Friday:
                    dayOfWeekString = "(금)";
                    break;
                                                                                              case Qt::Saturday:
                    dayOfWeekString = "(토)";
                    break;
                                                                                              case Qt::Sunday:
                    dayOfWeekString = "(일)";
                    break;
                                                                                              default:
                    dayOfWeekString = "알 수 없음";
                    break;
                                                                                              }

                                                                                              // 날짜와 요일을 함께 표시하는 형식으로 변환
                                                                                              QString formattedDate = currentDate.toString("yyyy년 MM월 dd일") + dayOfWeekString;

                                                                                                                                                                            ui->label_ChooseDay->setText(formattedDate);
            }
            BeforeTimeschedule3();
        }
    }
}


// 다음날 누를 시 시간표 최신화
void CR3_User::AfterTimeschedule()
{
    QLayoutItem* item;
    while ((item = ui->verticalLayout_TrainView->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    ui->label_ViewStart->setText(ui->pushButton_start1->text());
    ui->label_ViewArrive->setText(ui->pushButton_arrive1->text());
    QString start1 = ui->pushButton_start1->text();
    QString arrive1 = ui->pushButton_arrive1->text();

    QSqlQuery query;
    query.prepare("SELECT TRAINTYPE, TRAINNUM, STARTINGPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE, ARRIVALHOUR, ARRIVALMINUTE, TRAINPRICE, TRAINSPECIALPRICE FROM TRAINfo "
                  "WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
    query.bindValue(":STARTINGPOINT",start1);
    query.bindValue(":DESTINATION", arrive1);


    if (query.exec())
    {
        int maxTextWidth = 69;

        while(query.next())
        {
            QString traintype = query.value("TRAINTYPE").toString();
            QString trainnum = query.value("TRAINNUM").toString();
            QString startingpoint = query.value("STARTINGPOINT").toString();
            QString departurehour = query.value("DEPARTUREHOUR").toString();
            QString departureminute = query.value("DEPARTUREMINUTE").toString();
            QString destination = query.value("DESTINATION").toString();
            QString arrivalhour = query.value("ARRIVALHOUR").toString();
            QString arrivalminute = query.value("ARRIVALMINUTE").toString();
            QString trainprice = query.value("TRAINPRICE").toString();
            QString trainspecialprice = query.value("TRAINSPECIALPRICE").toString();


            // 특 우등실에 값이 없을 때 "─" 이걸로 나타냄
            if (trainspecialprice.isEmpty()) {
                trainspecialprice = "─";
            }


            QLabel *textLabel1 = new QLabel(traintype + "\n" + trainnum);
            QLabel *textLabel2 = new QLabel(departurehour + ":" + departureminute + "\n" + startingpoint);
            QLabel *textLabel3 = new QLabel(arrivalhour + ":" + arrivalminute + "\n" + destination);


            QPushButton *button1 = new QPushButton(trainprice);
            QPushButton *button2 = new QPushButton(trainspecialprice);
            textLabel1->setFixedWidth(maxTextWidth);
            QString buttonStyle = "QPushButton {"

                                  "  border: 1px solid black;"
                                  "  background-color: white;" // 버튼 배경색
                                  "  color: black;" // 버튼 텍스트 색상
                                  "  padding: 0px;" // 텍스트와 버튼 경계 사이의 여백
                                  "  font-size: 12px;" // 폰트 크기 설정
                                  "  width: 13px;" // 버튼의 너비를 설정
                                  "  height: 36px;" // 버튼의 높이를 설정
                                  "}";
            button1->setStyleSheet(buttonStyle);
            button2->setStyleSheet(buttonStyle);

            if (traintype == "KTX")
            {
                // KTX 버튼 생성
                QPushButton *ktxButton = new QPushButton(trainprice);
                ktxButton->setStyleSheet(buttonStyle);

                // KTX 버튼에 대한 이벤트 핸들러 연결
                //                connect(ktxButton, &QPushButton::clicked, this, &CR3_User::KTXPage);
                connect(ktxButton, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    KTXPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(ktxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }
                //                connect(button2, &QPushButton::clicked, this, &CR3_User::KTXROYALPage);
                connect(button2, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    KTXROYALPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(button2, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        KTXROYALPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }

                // 레이아웃에 KTX 버튼 추가
                QHBoxLayout *ktxLayout = new QHBoxLayout;
                ktxLayout->addWidget(textLabel1);
                ktxLayout->addWidget(textLabel2);
                ktxLayout->addWidget(textLabel3);
                ktxLayout->addWidget(ktxButton);
                ktxLayout->addWidget(button2);  // 다른 버튼 추가
                QVBoxLayout *ktxMainLayout = new QVBoxLayout;
                ktxMainLayout->addLayout(ktxLayout);
                QWidget *ktxWidget = new QWidget;
                ktxWidget->setLayout(ktxMainLayout);

                ui->verticalLayout_TrainView->addWidget(ktxWidget);
            }

            else if (traintype == "ITX-새마을")
            {
                // ITX-새마을 버튼 생성
                QPushButton *itxButton = new QPushButton(trainprice);
                itxButton->setStyleSheet(buttonStyle);

                // ITX-새마을 버튼에 대한 이벤트 핸들러 연결
                //                connect(itxButton, &QPushButton::clicked, this, &CR3_User::SMEPage);
                connect(itxButton, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    SMEPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(itxButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        SMEPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }

                // 레이아웃에 ITX-새마을 버튼 추가
                QHBoxLayout *itxLayout = new QHBoxLayout;
                itxLayout->addWidget(textLabel1);
                itxLayout->addWidget(textLabel2);
                itxLayout->addWidget(textLabel3);
                itxLayout->addWidget(itxButton);
                itxLayout->addWidget(button2);  // 다른 버튼 추가

                QVBoxLayout *itxMainLayout = new QVBoxLayout;
                itxMainLayout->addLayout(itxLayout);
                QWidget *itxWidget = new QWidget;
                itxWidget->setLayout(itxMainLayout);

                ui->verticalLayout_TrainView->addWidget(itxWidget);
            }

            else if (traintype == "무궁화호")
            {
                // 무궁화호 버튼 생성
                QPushButton *muguButton = new QPushButton(trainprice);
                muguButton->setStyleSheet(buttonStyle);

                // 무궁화호 버튼에 대한 이벤트 핸들러 연결
                //                connect(muguButton, &QPushButton::clicked, this, &CR3_User::MGHPage);
                connect(muguButton, &QPushButton::clicked, this, [=](){
                    selectTrainInfo = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                    MGHPage(); // KTX 페이지로 이동
                    ui->label_9999->setText(selectTrainInfo);
                    qDebug() << "보여줘요: " << ui->label_9999->text();
                });
                if (GoChk == 3)
                {
                    connect(muguButton, &QPushButton::clicked, this, [=](){
                        selectTrainInfo2 = traintype + " " + trainnum + " " + departurehour + ":" + departureminute + " " + startingpoint + " " + arrivalhour + ":" + arrivalminute + " " + destination;
                        MGHPage(); // KTX 페이지로 이동
                        ui->label_9999->setText(selectTrainInfo2);
                        qDebug() << "보여줘요: " << ui->label_9999->text();
                    });
                }

                // 레이아웃에 무궁화호 버튼 추가
                QHBoxLayout *muguLayout = new QHBoxLayout;
                muguLayout->addWidget(textLabel1);
                muguLayout->addWidget(textLabel2);
                muguLayout->addWidget(textLabel3);
                muguLayout->addWidget(muguButton);
                muguLayout->addWidget(button2);  // 다른 버튼 추가
                QVBoxLayout *muguMainLayout = new QVBoxLayout;
                muguMainLayout->addLayout(muguLayout);
                QWidget *muguWidget = new QWidget;
                muguWidget->setLayout(muguMainLayout);

                ui->verticalLayout_TrainView->addWidget(muguWidget);
            }
        }
        time_cnt += 1;
        qDebug() << time_cnt;

    }
    else
    {
        msgbox4.critical(this, "데이터베이스 오류", "데이터베이스 조회 중 오류가 발생했습니다.");

    }


}

// @@@@@@@@@@@@@@@@@ 열차 조회에서 다음날 @@@@@@@@@@@@@@@@@@
void CR3_User::AfterDay()
{
    // 현재 라벨에 표시된 날짜를 가져와서 QDate로 변환
    QString currentDateString = ui->label_ChooseDay->text();
    int indexOfParenthesis = currentDateString.lastIndexOf('('); // 요일 정보의 시작 위치 찾기
    if (indexOfParenthesis != -1)
    {
        QString datePart = currentDateString.mid(0, indexOfParenthesis).trimmed(); // 요일 정보 이전의 부분 추출
        QDate currentDate = QDate::fromString(datePart, "yyyy년 MM월 dd일");
        qDebug() << currentDate;

        currentDate = currentDate.addDays(1);

        // 요일을 문자열로 변환
        QString dayOfWeekString;
        switch (currentDate.dayOfWeek()) {
        case Qt::Monday:
            dayOfWeekString = "(월)";
            break;
        case Qt::Tuesday:
            dayOfWeekString = "(화)";
            break;
        case Qt::Wednesday:
            dayOfWeekString = "(수)";
            break;
        case Qt::Thursday:
            dayOfWeekString = "(목)";
            break;
        case Qt::Friday:
            dayOfWeekString = "(금)";
            break;
        case Qt::Saturday:
            dayOfWeekString = "(토)";
            break;
        case Qt::Sunday:
            dayOfWeekString = "(일)";
            break;
        default:
            dayOfWeekString = "알 수 없음";
            break;
        }

        // 날짜와 요일을 함께 표시하는 형식으로 변환
        QString formattedDate = currentDate.toString("yyyy년 MM월 dd일") + " " + dayOfWeekString;

        ui->label_ChooseDay->setText(formattedDate);
        AfterTimeschedule();
    }
    else
    {
        QDate currentDate = QDate::fromString(currentDateString, "yyyy년 MM월 dd일");
        currentDate = currentDate.addDays(1);

        // 요일을 문자열로 변환
        QString dayOfWeekString;
        switch (currentDate.dayOfWeek()) {
        case Qt::Monday:
            dayOfWeekString = "(월)";
            break;
        case Qt::Tuesday:
            dayOfWeekString = "(화)";
            break;
        case Qt::Wednesday:
            dayOfWeekString = "(수)";
            break;
        case Qt::Thursday:
            dayOfWeekString = "(목)";
            break;
        case Qt::Friday:
            dayOfWeekString = "(금)";
            break;
        case Qt::Saturday:
            dayOfWeekString = "(토)";
            break;
        case Qt::Sunday:
            dayOfWeekString = "(일)";
            break;
        default:
            dayOfWeekString = "알 수 없음";
            break;
        }

        // 날짜와 요일을 함께 표시하는 형식으로 변환
        QString formattedDate = currentDate.toString("yyyy년 MM월 dd일") + " " + dayOfWeekString;

        ui->label_ChooseDay->setText(formattedDate);
        AfterTimeschedule();
    }
}




// @@@@@@@@@@@@@@@@@ 편도, 왕복 열차 고르고 나서 좌석 고르기 @@@@@@@@@@@@@@@@@@
void CR3_User::SelectSeat()
{
    if (GoChk == 1)
    {
        ui->label_View->setText("가는 열차 조회");
        QMessageBox::information(this, "갑니다", "가자요");
        ui->stackedWidget->setCurrentIndex(18);
    }

    else if (GoChk == 2)
    {
        QMessageBox::information(this, "옵니다", "오는 열차 선택해주세요");
        GoChk = 3;
        time_cnt = -1;
        QString originalText = ui->label_startTime1_3->text();
        QString timeAndMinute = originalText.split(" ").last(); // "hh:mm" 형식으로 추출
        QString withoutTime = originalText.left(originalText.indexOf(timeAndMinute));

        // 새로운 형식으로 문자열 조합
        QString newText = withoutTime;
        ui->label_ChooseDay->setText(newText);
        ui->label_View->setText("오는 열차 조회");
        QString Start1 = ui->label_ViewStart->text();
        QString Arrive1 = ui->label_ViewArrive->text();

        QString Result1 = Arrive1;
        Arrive1 = Start1;
        ui->label_ViewStart->setText(Result1);
        ui->label_ViewArrive->setText(Arrive1);
        ui->pushButton_start1->setText(Result1);
        ui->pushButton_arrive1->setText(Arrive1);
        AfterTimeschedule();
    }

    else if (GoChk == 3)
    {
        ui->stackedWidget->setCurrentIndex(18);
    }
}


// @@@@@@@@@@@@@@@@@ 열차 호차 이동 @@@@@@@@@@@@@@@@@@
void CR3_User::moveTrainPage()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

    if (clickedButton == ui->pushButton_MGHgo1to2)
    {
        ui->stackedWidget->setCurrentIndex(8);
        ui->comboBox_choiceMGH2->setCurrentText("무궁화호 2호차");
    }

    else if (clickedButton == ui->pushButton_MGHgo2to1)
    {
        ui->stackedWidget->setCurrentIndex(7);
        ui->comboBox_choiceMGH1->setCurrentText("무궁화호 1호차");
    }

    else if (clickedButton == ui->pushButton_MGHgo2to3)
    {
        ui->stackedWidget->setCurrentIndex(9);
        ui->comboBox_choiceMGH3->setCurrentText("무궁화호 3호차");
    }

    else if (clickedButton == ui->pushButton_MGHgo3to2)
    {
        ui->stackedWidget->setCurrentIndex(8);
        ui->comboBox_choiceMGH2->setCurrentText("무궁화호 2호차");
    }

    else if (clickedButton == ui->pushButton_SMEgo1to2)
    {
        ui->stackedWidget->setCurrentIndex(11);
        ui->comboBox_choiceSME2->setCurrentText("새마을호 2호차");
    }

    else if (clickedButton == ui->pushButton_SMEgo2to1)
    {
        ui->stackedWidget->setCurrentIndex(10);
        ui->comboBox_choiceSME1->setCurrentText("새마을호 1호차");
    }

    else if (clickedButton == ui->pushButton_SMEgo2to3)
    {
        ui->stackedWidget->setCurrentIndex(12);
        ui->comboBox_choiceSME3->setCurrentText("새마을호 3호차");
    }

    else if (clickedButton == ui->pushButton_SMEgo3to2)
    {
        ui->stackedWidget->setCurrentIndex(11);
        ui->comboBox_choiceSME2->setCurrentText("새마을호 2호차");
    }

    else if (clickedButton == ui->pushButton_KTXgo1to2)
    {
        ui->stackedWidget->setCurrentIndex(14);
        ui->comboBox_choiceKTX2->setCurrentText("KTX 2호차");
    }

    else if (clickedButton == ui->pushButton_KTXgo2to1)
    {
        ui->stackedWidget->setCurrentIndex(13);
        ui->comboBox_choiceKTX1->setCurrentText("KTX 1호차");
    }

    else if (clickedButton == ui->pushButton_KTXgo2to3)
    {
        ui->stackedWidget->setCurrentIndex(15);
        ui->comboBox_choiceKTX3->setCurrentText("KTX 3호차");
    }

    else if (clickedButton == ui->pushButton_KTXgo3to2)
    {
        ui->stackedWidget->setCurrentIndex(14);
        ui->comboBox_choiceKTX2->setCurrentText("KTX 2호차");
    }

    else if (clickedButton == ui->pushButton_KTXloyalgo1to2)
    {
        ui->stackedWidget->setCurrentIndex(17);
        ui->comboBox_choiceKTXloyal2->setCurrentText("KTX 특실 2호차");
    }

    else if (clickedButton == ui->pushButton_KTXloyalgo2to1)
    {
        ui->stackedWidget->setCurrentIndex(16);
        ui->comboBox_choiceKTXloyal1->setCurrentText("KTX 특실 1호차");
    }
}


// @@@@@@@@@@@@@@@@@ 열차 콤보박스로 호차 이동 @@@@@@@@@@@@@@@@@@
void CR3_User::currentTextChanged(const QString &text)
{
    qDebug() << "발동 됨";
    // 선택된 텍스트에 따라 스택 위젯의 페이지 설정
    if (text == "무궁화호 1호차")
    {
        ui->stackedWidget->setCurrentIndex(7);
        ui->comboBox_choiceMGH1->setCurrentText("무궁화호 1호차");
    }
    else if (text == "무궁화호 2호차")
    {
        ui->stackedWidget->setCurrentIndex(8);
        ui->comboBox_choiceMGH2->setCurrentText("무궁화호 2호차");
    }
    else if (text == "무궁화호 3호차")
    {
        ui->stackedWidget->setCurrentIndex(9);
        ui->comboBox_choiceMGH3->setCurrentText("무궁화호 3호차");
    }
    else if (text == "새마을호 1호차")
    {
        ui->stackedWidget->setCurrentIndex(10);
        ui->comboBox_choiceSME1->setCurrentText("새마을호 1호차");
    }
    else if (text == "새마을호 2호차")
    {
        ui->stackedWidget->setCurrentIndex(11);
        ui->comboBox_choiceSME2->setCurrentText("새마을호 2호차");
    }
    else if (text == "새마을호 3호차")
    {
        ui->stackedWidget->setCurrentIndex(12);
        ui->comboBox_choiceSME3->setCurrentText("새마을호 3호차");
    }
    else if (text == "KTX 1호차")
    {
        ui->stackedWidget->setCurrentIndex(13);
        ui->comboBox_choiceKTX1->setCurrentText("KTX 1호차");
    }
    else if (text == "KTX 2호차")
    {
        ui->stackedWidget->setCurrentIndex(14);
        ui->comboBox_choiceKTX2->setCurrentText("KTX 2호차");
    }
    else if (text == "KTX 3호차")
    {
        ui->stackedWidget->setCurrentIndex(15);
        ui->comboBox_choiceKTX3->setCurrentText("KTX 3호차");
    }
    else if (text == "KTX 특실 1호차")
    {
        ui->stackedWidget->setCurrentIndex(16);
        ui->comboBox_choiceKTXloyal1->setCurrentText("KTX 특실 1호차");
    }
    else if (text == "KTX 특실 2호차")
    {
        ui->stackedWidget->setCurrentIndex(17);
        ui->comboBox_choiceKTXloyal2->setCurrentText("KTX 특실 2호차");
    }
}



// @@@@@@@@@@@@@@  테마 @@@@@@@@@@@@@@
void CR3_User::InitialTheme()
{
    // 현재 다이얼로그에 스타일 시트 변경
    QString WidgetStyleSheet = "QWidget {"
                               "   background-color: rgb(255, 255, 255);"
                               "   color: black;"
                               "}";

    this->setStyleSheet(WidgetStyleSheet); // 현재 다이얼로그에 스타일 시트 적용
}





//무궁화 선택시 바뀌는 이미지
void CR3_User::MGH_SeatClicked(QAbstractButton *clickedButton)
{
    if (GoChk == 1)
    {
        if (clickedButton && clickedButtons.size() < totalCount)
        {
            QString buttonText = clickedButton->text(); // 클릭한 버튼의 텍스트를 가져옵니다.
            QString SeatPlus = selectTrainInfo + " " + buttonText; // LALALA 변수의 값을 클릭한 버튼의 텍스트로 설정합니다.
            selectTrainInfo = SeatPlus;
            ui->label_9999->setText(selectTrainInfo);
            qDebug() << "LALALA 값 변경됨: " << selectTrainInfo;
                    QPixmap pixmap(":/img/KTXloyal.png");
            QIcon icon(pixmap);
            clickedButton->setIcon(icon);
            clickedButton->setDisabled(true); // 클릭 불가능하게 설정
            clickedButtons.insert(clickedButton);


            // 모든 클릭 가능한 버튼을 눌렀을 때 스택 위젯을 변경
            QStringList parts = selectTrainInfo.split(" ");
            QString TrainNum = parts[0] + parts[1];
            QString TrainStart = parts[3];
            QString TrainStartTime = parts[2];
            QString TrainArrive = parts[5];
            QString TrainArriveTime = parts[4];

            QString TrainSeat;

            for (int i = 6; i < totalCount + 6 && i < parts.size(); ++i)
            {
                qDebug() << i;
                TrainSeat += parts[i];

                if (i < totalCount + 5 && i < parts.size() - 1)
                {
                    TrainSeat += ",";
                }
            }

            QStringList StartTimeParts = TrainStartTime.split(":");
            QStringList ArriveTimeParts = TrainArriveTime.split(":");

            train_type = parts[0];
            train_num = parts[1];
            train_startpoint = parts[3];
            train_departurehour = StartTimeParts[0];
            train_departureminute = StartTimeParts[1];
            train_destination= parts[5];
            arrivalhour = ArriveTimeParts[0];
            arrivalminute = ArriveTimeParts[1];
            seatnum = TrainSeat;

            ui->label_purchaseSeat->setText(TrainSeat);

            ui->label_purchaseDate->setText(ui->label_ChooseDay->text());
            ui->label_purchaseNum->setText(TrainNum);
            ui->label_purchaseStart->setText(TrainStart);
            ui->label_purchaseStartTime->setText(TrainStartTime);
            ui->label_purchaseArrive->setText(TrainArrive);
            ui->label_purchaseArriveTime->setText(TrainArriveTime);

            ticketingDate = ui->label_purchaseDate->text();

            //승차권에 들어갈 내용
            ui->label_Reserve_Date_2->setText("예매일자:" + ui->label_purchaseDate->text());
            ui->label_Start_City_2->setText(ui->label_purchaseStart->text());
            ui->label_Start_Time_2->setText(ui->label_purchaseStartTime->text());
            ui->label_Arrive_City_2->setText(ui->label_purchaseArrive->text());
            ui->label_Arrive_Time_2->setText(ui->label_purchaseArriveTime->text());
            ui->label_Train_Name_2->setText(ui->label_purchaseNum->text() + " 열차");
            ui->label_Train_Num_2->setText(ui->label_purchaseNum->text());
            ui->label_Trainseat_Num_2->setText(ui->label_purchaseSeat->text());
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 hh:mm");
            ui->label_Reserve_YearDate_2->setText("발급일시: " + formattedDateTime);

            buyDate = ui->label_Reserve_YearDate_2->text();

            // 여기까지


            QString totalCountString = QString::number(totalCount);
            ui->label_purchaseTotalCount->setText(totalCountString);

            QSqlQuery query;
            query.prepare("SELECT TRAINPRICE FROM TRAINfo WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
            query.bindValue(":STARTINGPOINT", TrainStart);
            query.bindValue(":DESTINATION", TrainArrive);

            if (query.exec() && query.next())
            {
                QString trainprice = query.value("TRAINPRICE").toString();
                trainprice.remove("원");
                int price = trainprice.toInt();
                int realprice = price * totalCount;
                QString realrealprice = QString::number(realprice);
                ui->label_purchaseTicketPrice->setText(realrealprice + "원");
                ui->label_purchaseTotalPay->setText(ui->label_purchaseTicketPrice->text());
            }


            if (clickedButtons.size() == totalCount)
            {
                ui->stackedWidget->setCurrentIndex(18);
            }
        }
    }
    else if (GoChk == 2)
    {
        if (clickedButton && clickedButtons.size() < totalCount)
        {
            QString buttonText = clickedButton->text(); // 클릭한 버튼의 텍스트를 가져옵니다.
            QString SeatPlus = selectTrainInfo + " " + buttonText; // LALALA 변수의 값을 클릭한 버튼의 텍스트로 설정합니다.
            selectTrainInfo = SeatPlus;
            ui->label_9999->setText(selectTrainInfo);
            qDebug() << "LALALA 값 변경됨: " << selectTrainInfo;
                    QPixmap pixmap(":/img/KTXloyal.png");
            QIcon icon(pixmap);
            clickedButton->setIcon(icon);
            clickedButton->setDisabled(true); // 클릭 불가능하게 설정
            clickedButtons.insert(clickedButton);

            QStringList parts = selectTrainInfo.split(" ");
            QString TrainNum = parts[0] + parts[1];
            QString TrainStart = parts[3];
            QString TrainStartTime = parts[2];
            QString TrainArrive = parts[5];
            QString TrainArriveTime = parts[4];

            QString TrainSeat;

            for (int i = 6; i < totalCount + 6 && i < parts.size(); ++i)
            {
                qDebug() << i;
                TrainSeat += parts[i];

                if (i < totalCount + 5 && i < parts.size() - 1)
                {
                    TrainSeat += ",";
                }
            }

            QStringList StartTimeParts = TrainStartTime.split(":");
            QStringList ArriveTimeParts = TrainArriveTime.split(":");

            train_type = parts[0];
            train_num = parts[1];
            train_startpoint = parts[3];
            train_departurehour = StartTimeParts[0];
            train_departureminute = StartTimeParts[1];
            train_destination= parts[5];
            arrivalhour = ArriveTimeParts[0];
            arrivalminute = ArriveTimeParts[1];
            seatnum = TrainSeat;

            ui->label_purchaseSeat->setText(TrainSeat);

            ui->label_purchaseDate->setText(ui->label_ChooseDay->text());
            ui->label_purchaseNum->setText(TrainNum);
            ui->label_purchaseStart->setText(TrainStart);
            ui->label_purchaseStartTime->setText(TrainStartTime);
            ui->label_purchaseArrive->setText(TrainArrive);
            ui->label_purchaseArriveTime->setText(TrainArriveTime);

            ticketingDate = ui->label_purchaseDate->text();

            //승차권에 들어갈 내용
            ui->label_Reserve_Date_2->setText("예매일자:" + ui->label_purchaseDate->text());
            ui->label_Start_City_2->setText(ui->label_purchaseStart->text());
            ui->label_Start_Time_2->setText(ui->label_purchaseStartTime->text());
            ui->label_Arrive_City_2->setText(ui->label_purchaseArrive->text());
            ui->label_Arrive_Time_2->setText(ui->label_purchaseArriveTime->text());
            ui->label_Train_Name_2->setText(ui->label_purchaseNum->text() + " 열차");
            ui->label_Train_Num_2->setText(ui->label_purchaseNum->text());
            ui->label_Trainseat_Num_2->setText(ui->label_purchaseSeat->text());
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 hh:mm");
            ui->label_Reserve_YearDate_2->setText("발급일시: " + formattedDateTime);

            buyDate = ui->label_Reserve_YearDate_2->text();
            // 여기까지


            QString totalCountString = QString::number(totalCount);
            ui->label_purchaseTotalCount->setText(totalCountString);

            QSqlQuery query;
            query.prepare("SELECT TRAINPRICE FROM TRAINfo WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
            query.bindValue(":STARTINGPOINT", TrainStart);
            query.bindValue(":DESTINATION", TrainArrive);

            if (query.exec() && query.next())
            {
                QString trainprice = query.value("TRAINPRICE").toString();
                trainprice.remove("원");
                int price = trainprice.toInt();
                int realprice = price * totalCount;
                QString realrealprice = QString::number(realprice);
                ui->label_purchaseTicketPrice->setText(realrealprice + "원");
                ui->label_purchaseTotalPay->setText(ui->label_purchaseTicketPrice->text());
            }


            if (clickedButtons.size() == totalCount)
            {
                ui->stackedWidget->setCurrentIndex(18);
            }
        }
    }
    else if (GoChk == 3)
    {
        int totalCountCopy = totalCount;
        totalCountCopy += totalCount;
        qDebug() << "토탈카운트체크: " << totalCountCopy;
        if (clickedButton && clickedButtons.size() < totalCountCopy)
        {
            QString buttonText = clickedButton->text(); // 클릭한 버튼의 텍스트를 가져옵니다.
            QString SeatPlus = selectTrainInfo2 + " " + buttonText; // LALALA 변수의 값을 클릭한 버튼의 텍스트로 설정합니다.
            selectTrainInfo2 = SeatPlus;
            ui->label_9999->setText(selectTrainInfo2);
            qDebug() << "LALALA 값 변경됨: " << selectTrainInfo2;
                    QPixmap pixmap(":/img/KTXloyal.png");
            QIcon icon(pixmap);
            clickedButton->setIcon(icon);
            clickedButton->setDisabled(true); // 클릭 불가능하게 설정
            clickedButtons.insert(clickedButton);

            // 모든 클릭 가능한 버튼을 눌렀을 때 스택 위젯을 변경
            QStringList parts = selectTrainInfo2.split(" ");
            QString TrainNum = parts[0] + parts[1];
            QString TrainStart = parts[3];
            QString TrainStartTime = parts[2];
            QString TrainArrive = parts[5];
            QString TrainArriveTime = parts[4];

            QString TrainSeat;

            for (int i = 6; i < totalCount + 6 && i < parts.size(); ++i)
            {
                qDebug() << i;
                TrainSeat += parts[i];

                if (i < totalCount + 5 && i < parts.size() - 1)
                {
                    TrainSeat += ",";
                }
            }

            QStringList StartTimeParts = TrainStartTime.split(":");
            QStringList ArriveTimeParts = TrainArriveTime.split(":");

            train_type = parts[0];
            train_num = parts[1];
            train_startpoint = parts[3];
            train_departurehour = StartTimeParts[0];
            train_departureminute = StartTimeParts[1];
            train_destination= parts[5];
            arrivalhour = ArriveTimeParts[0];
            arrivalminute = ArriveTimeParts[1];
            seatnum = TrainSeat;

            ui->label_purchaseSeat->setText(TrainSeat);

            ui->label_purchaseDate->setText(ui->label_ChooseDay->text());
            ui->label_purchaseNum->setText(TrainNum);
            ui->label_purchaseStart->setText(TrainStart);
            ui->label_purchaseStartTime->setText(TrainStartTime);
            ui->label_purchaseArrive->setText(TrainArrive);
            ui->label_purchaseArriveTime->setText(TrainArriveTime);

            ticketingDate = ui->label_purchaseDate->text();

            //승차권에 들어갈 내용
            ui->label_Reserve_Date_3->setText("예매일자:" + ui->label_purchaseDate->text());
            ui->label_Start_City_3->setText(ui->label_purchaseStart->text());
            ui->label_Start_Time_3->setText(ui->label_purchaseStartTime->text());
            ui->label_Arrive_City_3->setText(ui->label_purchaseArrive->text());
            ui->label_Arrive_Time_3->setText(ui->label_purchaseArriveTime->text());
            ui->label_Train_Name_3->setText(ui->label_purchaseNum->text() + " 열차");
            ui->label_Train_Num_3->setText(ui->label_purchaseNum->text());
            ui->label_Trainseat_Num_3->setText(ui->label_purchaseSeat->text());
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 hh:mm");
            ui->label_Reserve_YearDate_3->setText("발급일시: " + formattedDateTime);

                                                              buyDate = ui->label_Reserve_YearDate_3->text();
            // 여기까지


            QString totalCountString = QString::number(totalCount);
            ui->label_purchaseTotalCount->setText(totalCountString);

            QSqlQuery query;
            query.prepare("SELECT TRAINPRICE FROM TRAINfo WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
            query.bindValue(":STARTINGPOINT", TrainStart);
            query.bindValue(":DESTINATION", TrainArrive);

            if (query.exec() && query.next())
            {
                QString trainprice = query.value("TRAINPRICE").toString();
                trainprice.remove("원");
                int price = trainprice.toInt();
                int realprice = price * totalCount;
                QString realrealprice = QString::number(realprice);
                ui->label_purchaseTicketPrice->setText(realrealprice + "원");
                ui->label_purchaseTotalPay->setText(ui->label_purchaseTicketPrice->text());
            }
            if (clickedButtons.size() == totalCountCopy)
            {
                ui->stackedWidget->setCurrentIndex(18);
            }
        }
    }
}

void CR3_User::SME_SeatClicked(QAbstractButton *clickedButton)
{
    if (GoChk == 1)
    {
        if (clickedButton && clickedButtons.size() < totalCount)
        {
            QString buttonText = clickedButton->text(); // 클릭한 버튼의 텍스트를 가져옵니다.
            QString SeatPlus = selectTrainInfo + " " + buttonText; // LALALA 변수의 값을 클릭한 버튼의 텍스트로 설정합니다.
            selectTrainInfo = SeatPlus;
            ui->label_9999->setText(selectTrainInfo);
            qDebug() << "LALALA 값 변경됨: " << selectTrainInfo;
                    QPixmap pixmap(":/img/KTXloyal.png");
            QIcon icon(pixmap);
            clickedButton->setIcon(icon);
            clickedButton->setDisabled(true); // 클릭 불가능하게 설정
            clickedButtons.insert(clickedButton);


            // 모든 클릭 가능한 버튼을 눌렀을 때 스택 위젯을 변경
            QStringList parts = selectTrainInfo.split(" ");
            QString TrainNum = parts[0] + parts[1];
            QString TrainStart = parts[3];
            QString TrainStartTime = parts[2];
            QString TrainArrive = parts[5];
            QString TrainArriveTime = parts[4];

            QString TrainSeat;

            for (int i = 6; i < totalCount + 6 && i < parts.size(); ++i)
            {
                qDebug() << i;
                TrainSeat += parts[i];

                if (i < totalCount + 5 && i < parts.size() - 1)
                {
                    TrainSeat += ",";
                }
            }

            QStringList StartTimeParts = TrainStartTime.split(":");
            QStringList ArriveTimeParts = TrainArriveTime.split(":");

            train_type = parts[0];
            train_num = parts[1];
            train_startpoint = parts[3];
            train_departurehour = StartTimeParts[0];
            train_departureminute = StartTimeParts[1];
            train_destination= parts[5];
            arrivalhour = ArriveTimeParts[0];
            arrivalminute = ArriveTimeParts[1];
            seatnum = TrainSeat;

            ui->label_purchaseSeat->setText(TrainSeat);

            ui->label_purchaseDate->setText(ui->label_ChooseDay->text());
            ui->label_purchaseNum->setText(TrainNum);
            ui->label_purchaseStart->setText(TrainStart);
            ui->label_purchaseStartTime->setText(TrainStartTime);
            ui->label_purchaseArrive->setText(TrainArrive);
            ui->label_purchaseArriveTime->setText(TrainArriveTime);

            ticketingDate = ui->label_purchaseDate->text();


            //승차권에 들어갈 내용
            ui->label_Reserve_Date_2->setText("예매일자:" + ui->label_purchaseDate->text());
            ui->label_Start_City_2->setText(ui->label_purchaseStart->text());
            ui->label_Start_Time_2->setText(ui->label_purchaseStartTime->text());
            ui->label_Arrive_City_2->setText(ui->label_purchaseArrive->text());
            ui->label_Arrive_Time_2->setText(ui->label_purchaseArriveTime->text());
            ui->label_Train_Name_2->setText(ui->label_purchaseNum->text() + " 열차");
            ui->label_Train_Num_2->setText(ui->label_purchaseNum->text());
            ui->label_Trainseat_Num_2->setText(ui->label_purchaseSeat->text());
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 hh:mm");
            ui->label_Reserve_YearDate_2->setText("발급일시: " + formattedDateTime);

            // 여기까지
            buyDate = ui->label_Reserve_YearDate_2->text();


            QString totalCountString = QString::number(totalCount);
            ui->label_purchaseTotalCount->setText(totalCountString);

            QSqlQuery query;
            query.prepare("SELECT TRAINPRICE FROM TRAINfo WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
            query.bindValue(":STARTINGPOINT", TrainStart);
            query.bindValue(":DESTINATION", TrainArrive);

            if (query.exec() && query.next())
            {
                QString trainprice = query.value("TRAINPRICE").toString();
                trainprice.remove("원");
                int price = trainprice.toInt();
                int realprice = price * totalCount;
                QString realrealprice = QString::number(realprice);
                ui->label_purchaseTicketPrice->setText(realrealprice + "원");
                ui->label_purchaseTotalPay->setText(ui->label_purchaseTicketPrice->text());
            }


            if (clickedButtons.size() == totalCount)
            {
                ui->stackedWidget->setCurrentIndex(18);
            }
        }
    }
    else if (GoChk == 2)
    {
        if (clickedButton && clickedButtons.size() < totalCount)
        {
            QString buttonText = clickedButton->text(); // 클릭한 버튼의 텍스트를 가져옵니다.
            QString SeatPlus = selectTrainInfo + " " + buttonText; // LALALA 변수의 값을 클릭한 버튼의 텍스트로 설정합니다.
            selectTrainInfo = SeatPlus;
            ui->label_9999->setText(selectTrainInfo);
            qDebug() << "LALALA 값 변경됨: " << selectTrainInfo;
                    QPixmap pixmap(":/img/KTXloyal.png");
            QIcon icon(pixmap);
            clickedButton->setIcon(icon);
            clickedButton->setDisabled(true); // 클릭 불가능하게 설정
            clickedButtons.insert(clickedButton);

            QStringList parts = selectTrainInfo.split(" ");
            QString TrainNum = parts[0] + parts[1];
            QString TrainStart = parts[3];
            QString TrainStartTime = parts[2];
            QString TrainArrive = parts[5];
            QString TrainArriveTime = parts[4];

            QString TrainSeat;

            for (int i = 6; i < totalCount + 6 && i < parts.size(); ++i)
            {
                qDebug() << i;
                TrainSeat += parts[i];

                if (i < totalCount + 5 && i < parts.size() - 1)
                {
                    TrainSeat += ",";
                }
            }

            QStringList StartTimeParts = TrainStartTime.split(":");
            QStringList ArriveTimeParts = TrainArriveTime.split(":");

            train_type = parts[0];
            train_num = parts[1];
            train_startpoint = parts[3];
            train_departurehour = StartTimeParts[0];
            train_departureminute = StartTimeParts[1];
            train_destination= parts[5];
            arrivalhour = ArriveTimeParts[0];
            arrivalminute = ArriveTimeParts[1];
            seatnum = TrainSeat;

            ui->label_purchaseSeat->setText(TrainSeat);

            ui->label_purchaseDate->setText(ui->label_ChooseDay->text());
            ui->label_purchaseNum->setText(TrainNum);
            ui->label_purchaseStart->setText(TrainStart);
            ui->label_purchaseStartTime->setText(TrainStartTime);
            ui->label_purchaseArrive->setText(TrainArrive);
            ui->label_purchaseArriveTime->setText(TrainArriveTime);

            ticketingDate = ui->label_purchaseDate->text();

            //승차권에 들어갈 내용
            ui->label_Reserve_Date_2->setText("예매일자:" + ui->label_purchaseDate->text());
            ui->label_Start_City_2->setText(ui->label_purchaseStart->text());
            ui->label_Start_Time_2->setText(ui->label_purchaseStartTime->text());
            ui->label_Arrive_City_2->setText(ui->label_purchaseArrive->text());
            ui->label_Arrive_Time_2->setText(ui->label_purchaseArriveTime->text());
            ui->label_Train_Name_2->setText(ui->label_purchaseNum->text() + " 열차");
            ui->label_Train_Num_2->setText(ui->label_purchaseNum->text());
            ui->label_Trainseat_Num_2->setText(ui->label_purchaseSeat->text());
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 hh:mm");
            ui->label_Reserve_YearDate_2->setText("발급일시: " + formattedDateTime);

            // 여기까지
            buyDate = ui->label_Reserve_YearDate_2->text();


            QString totalCountString = QString::number(totalCount);
            ui->label_purchaseTotalCount->setText(totalCountString);

            QSqlQuery query;
            query.prepare("SELECT TRAINPRICE FROM TRAINfo WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
            query.bindValue(":STARTINGPOINT", TrainStart);
            query.bindValue(":DESTINATION", TrainArrive);

            if (query.exec() && query.next())
            {
                QString trainprice = query.value("TRAINPRICE").toString();
                trainprice.remove("원");
                int price = trainprice.toInt();
                int realprice = price * totalCount;
                QString realrealprice = QString::number(realprice);
                ui->label_purchaseTicketPrice->setText(realrealprice + "원");
                ui->label_purchaseTotalPay->setText(ui->label_purchaseTicketPrice->text());
            }


            if (clickedButtons.size() == totalCount)
            {
                ui->stackedWidget->setCurrentIndex(18);
            }

        }
    }
    else if (GoChk == 3)
    {
        int totalCountCopy = totalCount;
        totalCountCopy += totalCount;
        qDebug() << "토탈카운트체크: " << totalCountCopy;
        if (clickedButton && clickedButtons.size() < totalCountCopy)
        {
            QString buttonText = clickedButton->text(); // 클릭한 버튼의 텍스트를 가져옵니다.
            QString SeatPlus = selectTrainInfo2 + " " + buttonText; // LALALA 변수의 값을 클릭한 버튼의 텍스트로 설정합니다.
            selectTrainInfo2 = SeatPlus;
            ui->label_9999->setText(selectTrainInfo2);
            qDebug() << "LALALA 값 변경됨: " << selectTrainInfo2;
                    QPixmap pixmap(":/img/KTXloyal.png");
            QIcon icon(pixmap);
            clickedButton->setIcon(icon);
            clickedButton->setDisabled(true); // 클릭 불가능하게 설정
            clickedButtons.insert(clickedButton);

            // 모든 클릭 가능한 버튼을 눌렀을 때 스택 위젯을 변경
            QStringList parts = selectTrainInfo2.split(" ");
            QString TrainNum = parts[0] + parts[1];
            QString TrainStart = parts[3];
            QString TrainStartTime = parts[2];
            QString TrainArrive = parts[5];
            QString TrainArriveTime = parts[4];

            QString TrainSeat;

            for (int i = 6; i < totalCount + 6 && i < parts.size(); ++i)
            {
                qDebug() << i;
                TrainSeat += parts[i];

                if (i < totalCount + 5 && i < parts.size() - 1)
                {
                    TrainSeat += ",";
                }
            }

            QStringList StartTimeParts = TrainStartTime.split(":");
            QStringList ArriveTimeParts = TrainArriveTime.split(":");

            train_type = parts[0];
            train_num = parts[1];
            train_startpoint = parts[3];
            train_departurehour = StartTimeParts[0];
            train_departureminute = StartTimeParts[1];
            train_destination= parts[5];
            arrivalhour = ArriveTimeParts[0];
            arrivalminute = ArriveTimeParts[1];
            seatnum = TrainSeat;

            ui->label_purchaseSeat->setText(TrainSeat);

            ui->label_purchaseDate->setText(ui->label_ChooseDay->text());
            ui->label_purchaseNum->setText(TrainNum);
            ui->label_purchaseStart->setText(TrainStart);
            ui->label_purchaseStartTime->setText(TrainStartTime);
            ui->label_purchaseArrive->setText(TrainArrive);
            ui->label_purchaseArriveTime->setText(TrainArriveTime);

            ticketingDate = ui->label_purchaseDate->text();

            //승차권에 들어갈 내용
            ui->label_Reserve_Date_3->setText("예매일자:" + ui->label_purchaseDate->text());
            ui->label_Start_City_3->setText(ui->label_purchaseStart->text());
            ui->label_Start_Time_3->setText(ui->label_purchaseStartTime->text());
            ui->label_Arrive_City_3->setText(ui->label_purchaseArrive->text());
            ui->label_Arrive_Time_3->setText(ui->label_purchaseArriveTime->text());
            ui->label_Train_Name_3->setText(ui->label_purchaseNum->text() + " 열차");
            ui->label_Train_Num_3->setText(ui->label_purchaseNum->text());
            ui->label_Trainseat_Num_3->setText(ui->label_purchaseSeat->text());
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 hh:mm");
            ui->label_Reserve_YearDate_3->setText("발급일시: " + formattedDateTime);

            // 여기까지

            buyDate = ui->label_Reserve_YearDate_3->text();

            QString totalCountString = QString::number(totalCount);
            ui->label_purchaseTotalCount->setText(totalCountString);

            QSqlQuery query;
            query.prepare("SELECT TRAINPRICE FROM TRAINfo WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
            query.bindValue(":STARTINGPOINT", TrainStart);
            query.bindValue(":DESTINATION", TrainArrive);

            if (query.exec() && query.next())
            {
                QString trainprice = query.value("TRAINPRICE").toString();
                trainprice.remove("원");
                int price = trainprice.toInt();
                int realprice = price * totalCount;
                QString realrealprice = QString::number(realprice);
                ui->label_purchaseTicketPrice->setText(realrealprice + "원");
                ui->label_purchaseTotalPay->setText(ui->label_purchaseTicketPrice->text());
            }
            if (clickedButtons.size() == totalCountCopy)
            {
                ui->stackedWidget->setCurrentIndex(18);
            }
        }
    }
}

////KTX일반좌석 선택시 바뀌는 이미지
void CR3_User::KTX_Normal_SeatClicked(QAbstractButton *clickedButton)
{
    if (GoChk == 1)
    {
        if (clickedButton && clickedButtons.size() < totalCount)
        {
            QString buttonText = clickedButton->text(); // 클릭한 버튼의 텍스트를 가져옵니다.
            QString SeatPlus = selectTrainInfo + " " + buttonText; // LALALA 변수의 값을 클릭한 버튼의 텍스트로 설정합니다.
            selectTrainInfo = SeatPlus;
            ui->label_9999->setText(selectTrainInfo);
            qDebug() << "LALALA 값 변경됨: " << selectTrainInfo;
                    QPixmap pixmap(":/img/KTXloyal.png");
            QIcon icon(pixmap);
            clickedButton->setIcon(icon);
            clickedButton->setDisabled(true); // 클릭 불가능하게 설정
            clickedButtons.insert(clickedButton);


            // 모든 클릭 가능한 버튼을 눌렀을 때 스택 위젯을 변경
            QStringList parts = selectTrainInfo.split(" ");
            QString TrainNum = parts[0] + parts[1];
            QString TrainStart = parts[3];
            QString TrainStartTime = parts[2];
            QString TrainArrive = parts[5];
            QString TrainArriveTime = parts[4];

            QString TrainSeat;

            for (int i = 6; i < totalCount + 6 && i < parts.size(); ++i)
            {
                qDebug() << i;
                TrainSeat += parts[i];

                if (i < totalCount + 5 && i < parts.size() - 1)
                {
                    TrainSeat += ",";
                }
            }

            QStringList StartTimeParts = TrainStartTime.split(":");
            QStringList ArriveTimeParts = TrainArriveTime.split(":");

            train_type = parts[0];
            train_num = parts[1];
            train_startpoint = parts[3];
            train_departurehour = StartTimeParts[0];
            train_departureminute = StartTimeParts[1];
            train_destination= parts[5];
            arrivalhour = ArriveTimeParts[0];
            arrivalminute = ArriveTimeParts[1];
            seatnum = TrainSeat;

            ui->label_purchaseSeat->setText(TrainSeat);

            ui->label_purchaseDate->setText(ui->label_ChooseDay->text());
            ui->label_purchaseNum->setText(TrainNum);
            ui->label_purchaseStart->setText(TrainStart);
            ui->label_purchaseStartTime->setText(TrainStartTime);
            ui->label_purchaseArrive->setText(TrainArrive);
            ui->label_purchaseArriveTime->setText(TrainArriveTime);

            ticketingDate = ui->label_purchaseDate->text();


            //승차권에 들어갈 내용
            ui->label_Reserve_Date_2->setText("예매일자:" + ui->label_purchaseDate->text());
            ui->label_Start_City_2->setText(ui->label_purchaseStart->text());
            ui->label_Start_Time_2->setText(ui->label_purchaseStartTime->text());
            ui->label_Arrive_City_2->setText(ui->label_purchaseArrive->text());
            ui->label_Arrive_Time_2->setText(ui->label_purchaseArriveTime->text());
            ui->label_Train_Name_2->setText(ui->label_purchaseNum->text() + " 열차");
            ui->label_Train_Num_2->setText(ui->label_purchaseNum->text());
            ui->label_Trainseat_Num_2->setText(ui->label_purchaseSeat->text());
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 hh:mm");
            ui->label_Reserve_YearDate_2->setText("발급일시: " + formattedDateTime);

            // 여기까지
            buyDate = ui->label_Reserve_YearDate_2->text();


            QString totalCountString = QString::number(totalCount);
            ui->label_purchaseTotalCount->setText(totalCountString);

            QSqlQuery query;
            query.prepare("SELECT TRAINPRICE FROM TRAINfo WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
            query.bindValue(":STARTINGPOINT", TrainStart);
            query.bindValue(":DESTINATION", TrainArrive);

            if (query.exec() && query.next())
            {
                QString trainprice = query.value("TRAINPRICE").toString();
                trainprice.remove("원");
                int price = trainprice.toInt();
                int realprice = price * totalCount;
                QString realrealprice = QString::number(realprice);
                ui->label_purchaseTicketPrice->setText(realrealprice + "원");
                ui->label_purchaseTotalPay->setText(ui->label_purchaseTicketPrice->text());
            }


            if (clickedButtons.size() == totalCount)
            {
                ui->stackedWidget->setCurrentIndex(18);
            }
        }
    }
    else if (GoChk == 2)
    {
        if (clickedButton && clickedButtons.size() < totalCount)
        {
            QString buttonText = clickedButton->text(); // 클릭한 버튼의 텍스트를 가져옵니다.
            QString SeatPlus = selectTrainInfo + " " + buttonText; // LALALA 변수의 값을 클릭한 버튼의 텍스트로 설정합니다.
            selectTrainInfo = SeatPlus;
            ui->label_9999->setText(selectTrainInfo);
            qDebug() << "LALALA 값 변경됨: " << selectTrainInfo;
                    QPixmap pixmap(":/img/KTXloyal.png");
            QIcon icon(pixmap);
            clickedButton->setIcon(icon);
            clickedButton->setDisabled(true); // 클릭 불가능하게 설정
            clickedButtons.insert(clickedButton);

            QStringList parts = selectTrainInfo.split(" ");
            QString TrainNum = parts[0] + parts[1];
            QString TrainStart = parts[3];
            QString TrainStartTime = parts[2];
            QString TrainArrive = parts[5];
            QString TrainArriveTime = parts[4];

            QString TrainSeat;

            for (int i = 6; i < totalCount + 6 && i < parts.size(); ++i)
            {
                qDebug() << i;
                TrainSeat += parts[i];

                if (i < totalCount + 5 && i < parts.size() - 1)
                {
                    TrainSeat += ",";
                }
            }

            QStringList StartTimeParts = TrainStartTime.split(":");
            QStringList ArriveTimeParts = TrainArriveTime.split(":");

            train_type = parts[0];
            train_num = parts[1];
            train_startpoint = parts[3];
            train_departurehour = StartTimeParts[0];
            train_departureminute = StartTimeParts[1];
            train_destination= parts[5];
            arrivalhour = ArriveTimeParts[0];
            arrivalminute = ArriveTimeParts[1];
            seatnum = TrainSeat;

            ui->label_purchaseSeat->setText(TrainSeat);

            ui->label_purchaseDate->setText(ui->label_ChooseDay->text());
            ui->label_purchaseNum->setText(TrainNum);
            ui->label_purchaseStart->setText(TrainStart);
            ui->label_purchaseStartTime->setText(TrainStartTime);
            ui->label_purchaseArrive->setText(TrainArrive);
            ui->label_purchaseArriveTime->setText(TrainArriveTime);

            ticketingDate = ui->label_purchaseDate->text();

            //승차권에 들어갈 내용
            ui->label_Reserve_Date_2->setText("예매일자:" + ui->label_purchaseDate->text());
            ui->label_Start_City_2->setText(ui->label_purchaseStart->text());
            ui->label_Start_Time_2->setText(ui->label_purchaseStartTime->text());
            ui->label_Arrive_City_2->setText(ui->label_purchaseArrive->text());
            ui->label_Arrive_Time_2->setText(ui->label_purchaseArriveTime->text());
            ui->label_Train_Name_2->setText(ui->label_purchaseNum->text() + " 열차");
            ui->label_Train_Num_2->setText(ui->label_purchaseNum->text());
            ui->label_Trainseat_Num_2->setText(ui->label_purchaseSeat->text());
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 hh:mm");
            ui->label_Reserve_YearDate_2->setText("발급일시: " + formattedDateTime);

            // 여기까지
            buyDate = ui->label_Reserve_YearDate_3->text();


            QString totalCountString = QString::number(totalCount);
            ui->label_purchaseTotalCount->setText(totalCountString);

            QSqlQuery query;
            query.prepare("SELECT TRAINPRICE FROM TRAINfo WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
            query.bindValue(":STARTINGPOINT", TrainStart);
            query.bindValue(":DESTINATION", TrainArrive);

            if (query.exec() && query.next())
            {
                QString trainprice = query.value("TRAINPRICE").toString();
                trainprice.remove("원");
                int price = trainprice.toInt();
                int realprice = price * totalCount;
                QString realrealprice = QString::number(realprice);
                ui->label_purchaseTicketPrice->setText(realrealprice + "원");
                ui->label_purchaseTotalPay->setText(ui->label_purchaseTicketPrice->text());
            }


            if (clickedButtons.size() == totalCount)
            {
                ui->stackedWidget->setCurrentIndex(18);
            }

        }
    }
    else if (GoChk == 3)
    {
        int totalCountCopy = totalCount;
        totalCountCopy += totalCount;
        qDebug() << "토탈카운트체크: " << totalCountCopy;
        if (clickedButton && clickedButtons.size() < totalCountCopy)
        {
            QString buttonText = clickedButton->text(); // 클릭한 버튼의 텍스트를 가져옵니다.
            QString SeatPlus = selectTrainInfo2 + " " + buttonText; // LALALA 변수의 값을 클릭한 버튼의 텍스트로 설정합니다.
            selectTrainInfo2 = SeatPlus;
            ui->label_9999->setText(selectTrainInfo2);
            qDebug() << "LALALA 값 변경됨: " << selectTrainInfo2;
                    QPixmap pixmap(":/img/KTXloyal.png");
            QIcon icon(pixmap);
            clickedButton->setIcon(icon);
            clickedButton->setDisabled(true); // 클릭 불가능하게 설정
            clickedButtons.insert(clickedButton);

            // 모든 클릭 가능한 버튼을 눌렀을 때 스택 위젯을 변경
            QStringList parts = selectTrainInfo2.split(" ");
            QString TrainNum = parts[0] + parts[1];
            QString TrainStart = parts[3];
            QString TrainStartTime = parts[2];
            QString TrainArrive = parts[5];
            QString TrainArriveTime = parts[4];

            QString TrainSeat;

            for (int i = 6; i < totalCount + 6 && i < parts.size(); ++i)
            {
                qDebug() << i;
                TrainSeat += parts[i];

                if (i < totalCount + 5 && i < parts.size() - 1)
                {
                    TrainSeat += ",";
                }
            }

            QStringList StartTimeParts = TrainStartTime.split(":");
            QStringList ArriveTimeParts = TrainArriveTime.split(":");

            train_type = parts[0];
            train_num = parts[1];
            train_startpoint = parts[3];
            train_departurehour = StartTimeParts[0];
            train_departureminute = StartTimeParts[1];
            train_destination= parts[5];
            arrivalhour = ArriveTimeParts[0];
            arrivalminute = ArriveTimeParts[1];
            seatnum = TrainSeat;

            ui->label_purchaseSeat->setText(TrainSeat);

            ui->label_purchaseDate->setText(ui->label_ChooseDay->text());
            ui->label_purchaseNum->setText(TrainNum);
            ui->label_purchaseStart->setText(TrainStart);
            ui->label_purchaseStartTime->setText(TrainStartTime);
            ui->label_purchaseArrive->setText(TrainArrive);
            ui->label_purchaseArriveTime->setText(TrainArriveTime);

            ticketingDate = ui->label_purchaseDate->text();

            //승차권에 들어갈 내용
            ui->label_Reserve_Date_3->setText("예매일자:" + ui->label_purchaseDate->text());
            ui->label_Start_City_3->setText(ui->label_purchaseStart->text());
            ui->label_Start_Time_3->setText(ui->label_purchaseStartTime->text());
            ui->label_Arrive_City_3->setText(ui->label_purchaseArrive->text());
            ui->label_Arrive_Time_3->setText(ui->label_purchaseArriveTime->text());
            ui->label_Train_Name_3->setText(ui->label_purchaseNum->text() + " 열차");
            ui->label_Train_Num_3->setText(ui->label_purchaseNum->text());
            ui->label_Trainseat_Num_3->setText(ui->label_purchaseSeat->text());
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 hh:mm");
            ui->label_Reserve_YearDate_3->setText("발급일시: " + formattedDateTime);

            // 여기까지
            buyDate = ui->label_Reserve_YearDate_3->text();


            QString totalCountString = QString::number(totalCount);
            ui->label_purchaseTotalCount->setText(totalCountString);

            QSqlQuery query;
            query.prepare("SELECT TRAINPRICE FROM TRAINfo WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
            query.bindValue(":STARTINGPOINT", TrainStart);
            query.bindValue(":DESTINATION", TrainArrive);

            if (query.exec() && query.next())
            {
                QString trainprice = query.value("TRAINPRICE").toString();
                trainprice.remove("원");
                int price = trainprice.toInt();
                int realprice = price * totalCount;
                QString realrealprice = QString::number(realprice);
                ui->label_purchaseTicketPrice->setText(realrealprice + "원");
                ui->label_purchaseTotalPay->setText(ui->label_purchaseTicketPrice->text());
            }
            if (clickedButtons.size() == totalCountCopy)
            {
                ui->stackedWidget->setCurrentIndex(18);
            }
        }
    }
}

//KTX 특우등좌석 선택시 바뀌는 이미지
void CR3_User::KTX_Special_SeatClicked(QAbstractButton *clickedButton)
{
    if (GoChk == 1)
    {
        if (clickedButton && clickedButtons.size() < totalCount)
        {
            QString buttonText = clickedButton->text(); // 클릭한 버튼의 텍스트를 가져옵니다.
            QString SeatPlus = selectTrainInfo + " " + buttonText; // LALALA 변수의 값을 클릭한 버튼의 텍스트로 설정합니다.
            selectTrainInfo = SeatPlus;
            ui->label_9999->setText(selectTrainInfo);
            qDebug() << "LALALA 값 변경됨: " << selectTrainInfo;
                    QPixmap pixmap(":/img/KTXloyal.png");
            QIcon icon(pixmap);
            clickedButton->setIcon(icon);
            clickedButton->setDisabled(true); // 클릭 불가능하게 설정
            clickedButtons.insert(clickedButton);


            // 모든 클릭 가능한 버튼을 눌렀을 때 스택 위젯을 변경
            QStringList parts = selectTrainInfo.split(" ");
            QString TrainNum = parts[0] + parts[1];
            QString TrainStart = parts[3];
            QString TrainStartTime = parts[2];
            QString TrainArrive = parts[5];
            QString TrainArriveTime = parts[4];

            QString TrainSeat;

            for (int i = 6; i < totalCount + 6 && i < parts.size(); ++i)
            {
                qDebug() << i;
                TrainSeat += parts[i];

                if (i < totalCount + 5 && i < parts.size() - 1)
                {
                    TrainSeat += ",";
                }
            }

            QStringList StartTimeParts = TrainStartTime.split(":");
            QStringList ArriveTimeParts = TrainArriveTime.split(":");

            train_type = parts[0];
            train_num = parts[1];
            train_startpoint = parts[3];
            train_departurehour = StartTimeParts[0];
            train_departureminute = StartTimeParts[1];
            train_destination= parts[5];
            arrivalhour = ArriveTimeParts[0];
            arrivalminute = ArriveTimeParts[1];
            seatnum = TrainSeat;

            ui->label_purchaseSeat->setText(TrainSeat);

            ui->label_purchaseDate->setText(ui->label_ChooseDay->text());
            ui->label_purchaseNum->setText(TrainNum);
            ui->label_purchaseStart->setText(TrainStart);
            ui->label_purchaseStartTime->setText(TrainStartTime);
            ui->label_purchaseArrive->setText(TrainArrive);
            ui->label_purchaseArriveTime->setText(TrainArriveTime);

            ticketingDate = ui->label_purchaseDate->text();


            //승차권에 들어갈 내용
            ui->label_Reserve_Date_2->setText("예매일자:" + ui->label_purchaseDate->text());
            ui->label_Start_City_2->setText(ui->label_purchaseStart->text());
            ui->label_Start_Time_2->setText(ui->label_purchaseStartTime->text());
            ui->label_Arrive_City_2->setText(ui->label_purchaseArrive->text());
            ui->label_Arrive_Time_2->setText(ui->label_purchaseArriveTime->text());
            ui->label_Train_Name_2->setText(ui->label_purchaseNum->text() + " 열차");
            ui->label_Train_Num_2->setText(ui->label_purchaseNum->text());
            ui->label_Trainseat_Num_2->setText(ui->label_purchaseSeat->text());
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 hh:mm");
            ui->label_Reserve_YearDate_2->setText("발급일시: " + formattedDateTime);

            // 여기까지

            buyDate = ui->label_Reserve_YearDate_2->text();

            QString totalCountString = QString::number(totalCount);
            ui->label_purchaseTotalCount->setText(totalCountString);

            QSqlQuery query;
            query.prepare("SELECT TRAINPRICE FROM TRAINfo WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
            query.bindValue(":STARTINGPOINT", TrainStart);
            query.bindValue(":DESTINATION", TrainArrive);

            if (query.exec() && query.next())
            {
                QString trainprice = query.value("TRAINPRICE").toString();
                trainprice.remove("원");
                int price = trainprice.toInt();
                int realprice = price * totalCount;
                QString realrealprice = QString::number(realprice);
                ui->label_purchaseTicketPrice->setText(realrealprice + "원");
                ui->label_purchaseTotalPay->setText(ui->label_purchaseTicketPrice->text());
            }


            if (clickedButtons.size() == totalCount)
            {
                ui->stackedWidget->setCurrentIndex(18);
            }
        }
    }
    else if (GoChk == 2)
    {
        if (clickedButton && clickedButtons.size() < totalCount)
        {
            QString buttonText = clickedButton->text(); // 클릭한 버튼의 텍스트를 가져옵니다.
            QString SeatPlus = selectTrainInfo + " " + buttonText; // LALALA 변수의 값을 클릭한 버튼의 텍스트로 설정합니다.
            selectTrainInfo = SeatPlus;
            ui->label_9999->setText(selectTrainInfo);
            qDebug() << "LALALA 값 변경됨: " << selectTrainInfo;
                    QPixmap pixmap(":/img/KTXloyal.png");
            QIcon icon(pixmap);
            clickedButton->setIcon(icon);
            clickedButton->setDisabled(true); // 클릭 불가능하게 설정
            clickedButtons.insert(clickedButton);

            QStringList parts = selectTrainInfo.split(" ");
            QString TrainNum = parts[0] + parts[1];
            QString TrainStart = parts[3];
            QString TrainStartTime = parts[2];
            QString TrainArrive = parts[5];
            QString TrainArriveTime = parts[4];

            QString TrainSeat;

            for (int i = 6; i < totalCount + 6 && i < parts.size(); ++i)
            {
                qDebug() << i;
                TrainSeat += parts[i];

                if (i < totalCount + 5 && i < parts.size() - 1)
                {
                    TrainSeat += ",";
                }
            }

            QStringList StartTimeParts = TrainStartTime.split(":");
            QStringList ArriveTimeParts = TrainArriveTime.split(":");

            train_type = parts[0];
            train_num = parts[1];
            train_startpoint = parts[3];
            train_departurehour = StartTimeParts[0];
            train_departureminute = StartTimeParts[1];
            train_destination= parts[5];
            arrivalhour = ArriveTimeParts[0];
            arrivalminute = ArriveTimeParts[1];
            seatnum = TrainSeat;

            ui->label_purchaseSeat->setText(TrainSeat);

            ui->label_purchaseDate->setText(ui->label_ChooseDay->text());
            ui->label_purchaseNum->setText(TrainNum);
            ui->label_purchaseStart->setText(TrainStart);
            ui->label_purchaseStartTime->setText(TrainStartTime);
            ui->label_purchaseArrive->setText(TrainArrive);
            ui->label_purchaseArriveTime->setText(TrainArriveTime);

            ticketingDate = ui->label_purchaseDate->text();

            //승차권에 들어갈 내용
            ui->label_Reserve_Date_2->setText("예매일자:" + ui->label_purchaseDate->text());
            ui->label_Start_City_2->setText(ui->label_purchaseStart->text());
            ui->label_Start_Time_2->setText(ui->label_purchaseStartTime->text());
            ui->label_Arrive_City_2->setText(ui->label_purchaseArrive->text());
            ui->label_Arrive_Time_2->setText(ui->label_purchaseArriveTime->text());
            ui->label_Train_Name_2->setText(ui->label_purchaseNum->text() + " 열차");
            ui->label_Train_Num_2->setText(ui->label_purchaseNum->text());
            ui->label_Trainseat_Num_2->setText(ui->label_purchaseSeat->text());
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 hh:mm");
            ui->label_Reserve_YearDate_2->setText("발급일시: " + formattedDateTime);

            // 여기까지
            buyDate = ui->label_Reserve_YearDate_2->text();


            QString totalCountString = QString::number(totalCount);
            ui->label_purchaseTotalCount->setText(totalCountString);

            QSqlQuery query;
            query.prepare("SELECT TRAINPRICE FROM TRAINfo WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
            query.bindValue(":STARTINGPOINT", TrainStart);
            query.bindValue(":DESTINATION", TrainArrive);

            if (query.exec() && query.next())
            {
                QString trainprice = query.value("TRAINPRICE").toString();
                trainprice.remove("원");
                int price = trainprice.toInt();
                int realprice = price * totalCount;
                QString realrealprice = QString::number(realprice);
                ui->label_purchaseTicketPrice->setText(realrealprice + "원");
                ui->label_purchaseTotalPay->setText(ui->label_purchaseTicketPrice->text());
            }


            if (clickedButtons.size() == totalCount)
            {
                ui->stackedWidget->setCurrentIndex(18);
            }

        }
    }
    else if (GoChk == 3)
    {
        int totalCountCopy = totalCount;
        totalCountCopy += totalCount;
        qDebug() << "토탈카운트체크: " << totalCountCopy;
        if (clickedButton && clickedButtons.size() < totalCountCopy)
        {
            QString buttonText = clickedButton->text(); // 클릭한 버튼의 텍스트를 가져옵니다.
            QString SeatPlus = selectTrainInfo2 + " " + buttonText; // LALALA 변수의 값을 클릭한 버튼의 텍스트로 설정합니다.
            selectTrainInfo2 = SeatPlus;
            ui->label_9999->setText(selectTrainInfo2);
            qDebug() << "LALALA 값 변경됨: " << selectTrainInfo2;
                    QPixmap pixmap(":/img/KTXloyal.png");
            QIcon icon(pixmap);
            clickedButton->setIcon(icon);
            clickedButton->setDisabled(true); // 클릭 불가능하게 설정
            clickedButtons.insert(clickedButton);

            // 모든 클릭 가능한 버튼을 눌렀을 때 스택 위젯을 변경
            QStringList parts = selectTrainInfo2.split(" ");
            QString TrainNum = parts[0] + parts[1];
            QString TrainStart = parts[3];
            QString TrainStartTime = parts[2];
            QString TrainArrive = parts[5];
            QString TrainArriveTime = parts[4];

            QString TrainSeat;

            for (int i = 6; i < totalCount + 6 && i < parts.size(); ++i)
            {
                qDebug() << i;
                TrainSeat += parts[i];

                if (i < totalCount + 5 && i < parts.size() - 1)
                {
                    TrainSeat += ",";
                }
            }

            QStringList StartTimeParts = TrainStartTime.split(":");
            QStringList ArriveTimeParts = TrainArriveTime.split(":");

            train_type = parts[0];
            train_num = parts[1];
            train_startpoint = parts[3];
            train_departurehour = StartTimeParts[0];
            train_departureminute = StartTimeParts[1];
            train_destination= parts[5];
            arrivalhour = ArriveTimeParts[0];
            arrivalminute = ArriveTimeParts[1];
            seatnum = TrainSeat;

            ui->label_purchaseSeat->setText(TrainSeat);

            ui->label_purchaseDate->setText(ui->label_ChooseDay->text());
            ui->label_purchaseNum->setText(TrainNum);
            ui->label_purchaseStart->setText(TrainStart);
            ui->label_purchaseStartTime->setText(TrainStartTime);
            ui->label_purchaseArrive->setText(TrainArrive);
            ui->label_purchaseArriveTime->setText(TrainArriveTime);

            ticketingDate = ui->label_purchaseDate->text();

            //승차권에 들어갈 내용
            ui->label_Reserve_Date_3->setText("예매일자:" + ui->label_purchaseDate->text());
            ui->label_Start_City_3->setText(ui->label_purchaseStart->text());
            ui->label_Start_Time_3->setText(ui->label_purchaseStartTime->text());
            ui->label_Arrive_City_3->setText(ui->label_purchaseArrive->text());
            ui->label_Arrive_Time_3->setText(ui->label_purchaseArriveTime->text());
            ui->label_Train_Name_3->setText(ui->label_purchaseNum->text() + " 열차");
            ui->label_Train_Num_3->setText(ui->label_purchaseNum->text());
            ui->label_Trainseat_Num_3->setText(ui->label_purchaseSeat->text());
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy년 MM월 dd일 hh:mm");
            ui->label_Reserve_YearDate_3->setText("발급일시: " + formattedDateTime);

            // 여기까지
            buyDate = ui->label_Reserve_YearDate_3->text();


            QString totalCountString = QString::number(totalCount);
            ui->label_purchaseTotalCount->setText(totalCountString);

            QSqlQuery query;
            query.prepare("SELECT TRAINPRICE FROM TRAINfo WHERE STARTINGPOINT = :STARTINGPOINT AND DESTINATION = :DESTINATION");
            query.bindValue(":STARTINGPOINT", TrainStart);
            query.bindValue(":DESTINATION", TrainArrive);

            if (query.exec() && query.next())
            {
                QString trainprice = query.value("TRAINPRICE").toString();
                trainprice.remove("원");
                int price = trainprice.toInt();
                int realprice = price * totalCount;
                QString realrealprice = QString::number(realprice);
                ui->label_purchaseTicketPrice->setText(realrealprice + "원");
                ui->label_purchaseTotalPay->setText(ui->label_purchaseTicketPrice->text());
            }
            if (clickedButtons.size() == totalCountCopy)
            {
                ui->stackedWidget->setCurrentIndex(18);
            }
        }
    }
}



void CR3_User::on_radioButton_1_clicked()
{
    discount = 0.1;
}


void CR3_User::on_radioButton_2_clicked()
{
    discount = 0.2;
}


void CR3_User::on_radioButton_3_clicked()
{
    discount = 0.1;
}


void CR3_User::on_radioButton_4_clicked()
{
    discount = 0.1;
}


void CR3_User::profile()
{
    ui->stackedWidget->setCurrentIndex(8);

    // 데이터베이스 연결이 열려 있지 않으면 열려고 시도합니다.
    if (!userdb.isOpen() && !userdbOpen())
    {
        qDebug() << "데이터베이스를 열지 못했습니다.";
        return;
    }

    QSqlQuery query;

    query.prepare("SELECT * FROM user WHERE ID = :ID");
    query.bindValue(":ID", username);

    if (!query.exec()) {
        qDebug() << "오류: 쿼리 실행 실패. ";
            return;
    }



    if (query.next())
    {
        QString usernames = query.value("NAME").toString();
        QString userphs = query.value("PHONE").toString();
        QString userems = query.value("EMAIL").toString();
        QString userids = query.value("ID").toString();

        // 레이블에 값을 설정합니다.
        ui->label_profileName2->setText(usernames);
        ui->label_profilePhone2->setText(userphs);
        ui->label_profileEmail2->setText(userems);
        ui->label_profileId2->setText(userids);
    }
    else
    {
        qDebug() << "해당 ID를 가진 사용자를 찾을 수 없습니다.";
    }
}


//
void CR3_User::handleDeleteRequest()
{
    if (!userdb.isOpen() && !userdbOpen())
    {
        qDebug() << "데이터베이스를 열지 못했습니다.";
        return;
    }

    QString delete_user = "회원탈퇴";
    QSqlQuery query;

    query.prepare("UPDATE user SET EMAIL = :email WHERE ID = :ID");
    query.bindValue(":ID", username);
    query.bindValue(":email", delete_user);

    if(!query.exec())
    {
        qDebug() << "회원탈퇴 실패";
    }
    else
    {
        msgbox8.setWindowTitle("회원탈퇴");
        msgbox8.setIcon(QMessageBox::Information);
        msgbox8.setText("탈퇴를 하시겠습니까?");
        msgbox8.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

        if(msgbox8.exec() == QMessageBox::Yes)
        {
            // 이미 위에서 쿼리를 실행했으므로 추가로 실행할 필요 없습니다.
            msgbox8.close();
            msgbox8.information(this, "회원탈퇴 완료", "회원탈퇴가 완료되었습니다.");

            ui->stackedWidget->setCurrentIndex(1); // "예"를 선택한 경우 화면을 변경합니다.
            ui->lineEdit_loginId->clear();
            ui->lineEdit_loginPw->clear();
        }
        else
        {
            // "아니요"를 선택한 경우 메시지 박스만 닫습니다.
            msgbox8.close();
        }
    }
}

//
void CR3_User::performchangeId()
{
    QString changedId = ui->lineEdit_changeId->text();

    // 정규 표현식을 사용하여 입력 값 검사
    QRegularExpression englishNumberRegExp("^[A-Za-z0-9]*$"); // 영어 대소문자와 숫자만 입력 가능한 정규 표현식
    QValidator* englishNumberValidator = new QRegularExpressionValidator(englishNumberRegExp, this);
    ui->lineEdit_changeId->setValidator(englishNumberValidator);

    if (changedId.isEmpty())
    {
        msgbox9.setWindowTitle("프로필 관리창");
        msgbox9.setIcon(QMessageBox::Warning);
        msgbox9.setText("아이디 칸을 입력해 주세요.");
        msgbox9.setStandardButtons(QMessageBox::Ok);

        // Ok 누르면 창 닫힘
        if (msgbox9.exec() == QMessageBox::Ok)
        {
            msgbox9.close();
            return;
        }
    }


    if (!englishNumberRegExp.match(changedId).hasMatch())
    {
        // 입력 값이 정규 표현식과 일치하지 않으면 메시지 박스 표시

        msgbox10.setIcon(QMessageBox::Critical);
        msgbox10.setWindowTitle("입력 오류");
        msgbox10.setText("영어 대소문자와 숫자만 입력 가능합니다.");
        msgbox10.exec();
        return;
    }


    if (!userdb.isOpen() && !userdbOpen())
    {
        qDebug() << "데이터베이스를 열지 못했습니다.";
        return;
    }

    // 새로운 아이디가 이미 존재하는지 확인
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT ID FROM user WHERE ID = :changeId");
    checkQuery.bindValue(":changeId", changedId);

    if (checkQuery.exec() && checkQuery.next())
    {
        // 이미 존재하는 아이디인 경우 메시지 박스 표시

        msgbox11.setIcon(QMessageBox::Critical);
        msgbox11.setWindowTitle("아이디 변경 실패");
        msgbox11.setText("이미 존재하는 아이디입니다.");
        msgbox11.exec();
        ui->lineEdit_changeId->clear();
    }
    else
    {
        // 아이디 변경 로직을 수행하고 메시지 박스 표시
        QSqlQuery query;
        query.prepare("UPDATE user SET ID = :changeId WHERE ID = :ID");
        query.bindValue(":changeId", changedId);
        query.bindValue(":ID", username);

        if (query.exec())
        {

            msgbox12.setIcon(QMessageBox::Information);
            msgbox12.setWindowTitle("아이디 변경 성공");
            msgbox12.setText("아이디가 성공적으로 변경되었습니다.");
            msgbox12.exec();
            ui->stackedWidget->setCurrentIndex(1);
            ui->lineEdit_loginId->clear();
            ui->lineEdit_loginPw->clear();
        }
        else
        {

            msgbox13.setIcon(QMessageBox::Critical);
            msgbox13.setWindowTitle("아이디 변경 실패");
            msgbox13.setText("아이디 변경 중 오류가 발생했습니다.");
            msgbox13.exec();

            ui->lineEdit_changeId->clear();
        }
    }
}


//
void CR3_User::performchangePw()
{
    QString changePw = ui->lineEdit_changePw->text();
    QRegularExpression specialCharPattern("[!@#$%^&*(),.?:{}|<>]+");

    if (changePw.isEmpty())
    {
        msgbox14.setWindowTitle("프로필 관리창");
        msgbox14.setIcon(QMessageBox::Warning);
        msgbox14.setText("비밀번호 칸을 입력해 주세요.");
        msgbox14.setStandardButtons(QMessageBox::Ok);

        // Ok 누르면 창 닫힘
        if (msgbox14.exec() == QMessageBox::Ok)
        {
            msgbox14.close();
            return;
        }
    }

    if (changePw.length() < 8 || !specialCharPattern.match(changePw).hasMatch())
    {
        // 입력 값이 정규 표현식과 일치하지 않으면 메시지 박스 표시

        msgbox15.setIcon(QMessageBox::Critical);
        msgbox15.setWindowTitle("입력 오류");
        msgbox15.setText("비밀번호는 8글자이상 특수문자 포함이여야 합니다.");
        msgbox15.exec();
        return;
    }

    if (!userdb.isOpen() && !userdbOpen())
    {
        qDebug() << "데이터베이스를 열지 못했습니다.";
        return;
    }


    if (changePw.isEmpty())
    {
        msgbox16.setWindowTitle("프로필 관리창");
        msgbox16.setIcon(QMessageBox::Warning);
        msgbox16.setText("비밀번호 칸을 입력해 주세요.");
        msgbox16.setStandardButtons(QMessageBox::Ok);

        // Ok 누르면 창 닫힘
        if (msgbox16.exec() == QMessageBox::Ok)
        {
            msgbox16.close();
        }
    }

    else
    {
        QSqlQuery query;
        query.prepare("UPDATE user SET PW = :changeId WHERE ID = :ID");
        query.bindValue(":changeId", changePw);
        query.bindValue(":ID", username);

        if (query.exec())
        {
            msgbox17.setIcon(QMessageBox::Information);
            msgbox17.setWindowTitle("비밀번호 변경 성공");
            msgbox17.setText("비밀번호가 성공적으로 변경되었습니다.");
            msgbox17.exec();
            ui->stackedWidget->setCurrentIndex(1);
            ui->lineEdit_loginId->clear();
            ui->lineEdit_loginPw->clear();
        }
        else
        {
            msgbox18.setIcon(QMessageBox::Critical);
            msgbox18.setWindowTitle("비밀번호 변경 실패");
            msgbox18.setText("비밀번호 변경 중 오류가 발생했습니다.");
            msgbox18.exec();
            ui->lineEdit_changePw->clear();
        }
    }
}


void CR3_User::logout()
{
    msgbox19.setWindowTitle("로그아웃");
    msgbox19.setIcon(QMessageBox::Information);
    msgbox19.setText("로그아웃 하시겠습니까?");
    msgbox19.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    if(msgbox19.exec() == QMessageBox::Yes)
    {
        // 이미 위에서 쿼리를 실행했으므로 추가로 실행할 필요 없습니다.
        msgbox19.close();
        msgbox19.information(this, "로그아웃 완료", "로그아웃 완료되었습니다.");

        ui->stackedWidget->setCurrentIndex(1); // "예"를 선택한 경우 화면을 변경합니다.

        ui->lineEdit_loginId->clear();
        ui->lineEdit_loginPw->clear();
    }
    else
    {
        // "아니요"를 선택한 경우 메시지 박스만 닫습니다.
        msgbox19.close();
    }
}

void CR3_User::purchaseNext()
{
    if (GoChk == 2)
    {
        // 모든 클릭 가능한 버튼을 눌렀을 때 스택 위젯을 변경
        if (clickedButtons.size() == totalCount)
        {
            ui->stackedWidget->setCurrentIndex(6);
            QMessageBox::information(this, "CuteRail", "오는날의 열차를 선택해주세요");
            GoChk = 3;
            changeChk = 1;
            time_cnt = -1;
            QString originalText = ui->label_startTime1_3->text();
            QString timeAndMinute = originalText.split(" ").last(); // "hh:mm" 형식으로 추출
            QString withoutTime = originalText.left(originalText.indexOf(timeAndMinute));

            // 새로운 형식으로 문자열 조합
            QString newText = withoutTime;
            ui->label_ChooseDay->setText(newText);
            ui->label_View->setText("오는 열차 조회");
            QString Start1 = ui->label_ViewStart->text();
            QString Arrive1 = ui->label_ViewArrive->text();

            QString Result1 = Arrive1;
            Arrive1 = Start1;
            ui->label_ViewStart->setText(Result1);
            ui->label_ViewArrive->setText(Arrive1);
            ui->pushButton_start1->setText(Result1);
            ui->pushButton_arrive1->setText(Arrive1);
            AfterTimeschedule();
        }
    }
    else
    {
        QMessageBox::information(this, "CuteRail", "결제되었습니다.");

        QSqlQuery query;
        query.prepare("INSERT INTO TICKETINGINfo (ID, TRAINTYPE, TRAINNUM, STARTPOINT, DESTINATION, DEPARTUREHOUR, DEPARTUREMINUTE"
                      ", ARRIVALHOUR, ARRIVALMINUTE, SEATNUM, TICKETINGDATE, BUYDATE) "
                      "VALUES (:ID, :TRAINTYPE, :TRAINNUM, :STARTPOINT, :DESTINATION, :DEPARTUREHOUR, :DEPARTUREMINUTE"
                      ", :ARRIVALHOUR, :ARRIVALMINUTE, :SEATNUM, :TICKETINGDATE, :BUYDATE)");
        query.bindValue(":ID", login_id);
        query.bindValue(":TRAINTYPE", train_type);
        query.bindValue(":TRAINNUM", train_num);
        query.bindValue(":STARTPOINT", train_startpoint);
        query.bindValue(":DESTINATION", train_destination);
        query.bindValue(":DEPARTUREHOUR", train_departurehour);
        query.bindValue(":DEPARTUREMINUTE", train_departureminute);
        query.bindValue(":ARRIVALHOUR", arrivalhour);
        query.bindValue(":ARRIVALMINUTE", arrivalminute);
        query.bindValue(":SEATNUM", seatnum);
        query.bindValue(":TICKETINGDATE", ticketingDate);
        query.bindValue(":BUYDATE", buyDate);

        if (query.exec())
        {
            qDebug() << "디비에 담김";
            qDebug() << login_id << "담겨야 됨";
            qDebug() << train_type;
            qDebug() << train_num;
            qDebug() << train_startpoint;
            qDebug() << train_destination;
            qDebug() << train_departurehour;
            qDebug() << train_departureminute;
            qDebug() << arrivalhour;
            qDebug() << arrivalminute;
            qDebug() << seatnum;
        }
        else
        {
            qDebug() << "디비에 안 담김";
        }

    }

    ui->stackedWidget->setCurrentIndex(4);
    ui->tabWidget_2->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(0);

}


void CR3_User::TicketChkPage1()
{
    if (GoChk == 3)
    {
        ui->stackedWidget_2->setCurrentIndex(0);
    }
    else
    {
        QMessageBox::warning(this, "CuteRail", "왕복 티켓이 존재하지 않습니다.");
    }
}

void CR3_User::TicketChkPage2()
{
    if (GoChk == 3)
    {
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::warning(this, "CuteRail", "왕복 티켓이 존재하지 않습니다.");
    }
}

//@@@@@@@@@@@@@@@@@ 실행 끝나면 데이터베이스 닫음 @@@@@@@@@@@@@@@@@@
CR3_User::~CR3_User()
{
    userdbClose();
    delete ui;
}
