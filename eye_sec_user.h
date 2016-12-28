#ifndef EYE_SEC_USER_H
#define EYE_SEC_USER_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "eye_sec_user.h"
#include "Pixel.h"
#include "lodepng.h"
#include "Compare.h"
#include "Parser.h"
#include "pictureConvert.h"
#include "Person.h"
#include "eyelibrary.h"

namespace Ui {
class eye_sec_user;
}

class eye_sec_user : public QMainWindow
{
    Q_OBJECT

public:
    explicit eye_sec_user(QWidget *parent = 0);
    ~eye_sec_user();

private slots:

    void on_submit_clicked(std::vector<Person> people, eyeLibrary lib);

    void on_exit_button_clicked();


private:
    Ui::eye_sec_user *ui;
};

void check_valid(QString input);
std::vector<QString> initialize_namelist();
void set_username(std::vector<QString> namelist, QString name);
void import_picture();
void save_changes(QString name, QString filename);
bool is_equal(std::string s1, std::string s2);
int getPerson(std::vector<Person> people, std::string name);


#endif // EYE_SEC_USER_H
