#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   Ui::MainWindow   *getUi() const {return this->ui;};
   const std::vector<std::string>   getTypes() const {return this->types ; };
   const std::string    getFilename() const {return filename;};
   bool     isSended() const {return this->sended; };
   void     reset() {this->sended = false;};

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<std::string>    types;
    std::string filename;
    bool    sended;
    bool    correctFile;
};

#endif // MAINWINDOW_H
