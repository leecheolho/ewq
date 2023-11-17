#ifndef CR3_USER_H
#define CR3_USER_H

#include <QWidget>
#include "cr3_train.h"
#include <QSqlDatabase>
#include <QApplication>
#include <QButtonGroup>
#include <QScreen>
#include <QMessageBox>
#include <QMap>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QCalendarWidget>
#include <QWidget>
#include <QGridLayout>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class CR3_User; }
QT_END_NAMESPACE

class CR3_User : public QWidget
{
    Q_OBJECT

public:
    CR3_User(QWidget *parent = nullptr);
    ~CR3_User();
    QSqlDatabase userdb;
    void userdbClose();
    bool userdbOpen();


private:
    Ui::CR3_User *ui;
    QString username;

    int login_cnt = 0;

    QMessageBox msgbox1;
    QMessageBox msgbox2;
    QMessageBox msgbox3;
    QMessageBox msgbox4;
    QMessageBox msgbox5;
    QMessageBox msgbox6;
    QMessageBox msgbox7;
    QMessageBox msgbox8;
    QMessageBox msgbox9;
    QMessageBox msgbox10;
    QMessageBox msgbox11;
    QMessageBox msgbox12;
    QMessageBox msgbox13;
    QMessageBox msgbox14;
    QMessageBox msgbox15;
    QMessageBox msgbox16;
    QMessageBox msgbox17;
    QMessageBox msgbox18;
    QMessageBox msgbox19;

    QString username_text;
    QString userid_text;
    QString userph_text;
    QString userem_text;

    QString login_id;



    QString train_type;
    QString train_num;
    QString train_id;
    QString train_startpoint;
    QString train_destination;
    QString train_departurehour;
    QString train_departureminute;
    QString arrivalhour;
    QString arrivalminute;
    QString hochatype;
    QString seatnum;
    QString ticketingDate;
    QString buyDate;


    QString ChkPhone;
    bool startSelected = false;
    QString dateTimeTime;
    int totalCount = 0;
    int GoChk = 1;
    int changeChk = 0;
    QString StartPoint;
    QString ArrivePoint;


    int time_cnt = 0;
    QString selectTrainInfo;
    QString selectTrainInfo2;
    QSet<QAbstractButton*> clickedButtons;

    double discount = 0.0;

private slots:
    void LoginPage();
    void SignPage();
    void FindPage();
    void GoMap();
    void TicketingPage();
    void KTXPage();
    void MGHPage();
    void SMEPage();
    void KTXROYALPage();

    void Sign();
    void PhoneLogin();
    void CheckId(const QString& text);
    void CheckPw();
    void CheckBirth();
    void CheckName();
    void CheckPhone();

    void Login();
    void FindId();
    void FindPw();
    void AgreePage();

    void centerOnScreen();
    void TicketingUI();
    void TrainArrive();
    void TrainStart();
    void StartButtonClick();
    void ArriveButtonClick();
    void StartTime();
    void StartTime2();
    void handleDateTimeSelection(const QDateTime &dateTime);
    void handleCalendarSelection();
    void handleCalendarSelection2();
    void SelectAgeSeat();
    void ChangeSA();
    void ChangeSA2();
    void TrainView1();
    void TrainView2();
    void ktx_timeschedule();
    void itx_timeschedule();
    void flower_timeschedule();
    void on_comboBox_Train_activated(int index);
    void SelectSeat();
    void moveTrainPage();
    void BeforeDay();
    void BeforeTimeschedule();
    void BeforeTimeschedule2();
    void BeforeTimeschedule3();
    void AfterDay();
    void AfterTimeschedule();
    void SelectToMap(QAbstractButton* clickedButton);
    void currentTextChanged(const QString &text);
    void InitialTheme();

    void CurrentView();
    void CurrentView2();
    void CurrentView3();

    void MGH_SeatClicked(QAbstractButton *clickedButton);
    void SME_SeatClicked(QAbstractButton *clickedButton);
    void KTX_Normal_SeatClicked(QAbstractButton *clickedButton);
    void KTX_Special_SeatClicked(QAbstractButton *clickedButton);
    void on_pushButton_totalagree_clicked();

    void on_radioButton_1_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_4_clicked();

    void profile();
    void handleDeleteRequest();
    void performchangeId();
    void performchangePw();
    void logout();

    void purchaseNext();
    void TicketChkPage1();
    void TicketChkPage2();
};
#endif // CR3_USER_H
