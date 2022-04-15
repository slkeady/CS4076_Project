#ifndef WORDLE_H
#define WORDLE_H

#include "qtextedit.h"
#include "WordleFile.h"
#include <QDialog>
#include <vector>

namespace Ui {
class Wordle;
}

class Wordle : public QDialog
{
    Q_OBJECT

public:
    explicit Wordle(QWidget *parent = nullptr);
    ~Wordle();
    friend class WordleFile;

private slots:

    void on_Abutton_clicked();
    void on_Bbutton_clicked();
    void on_Cbutton_clicked();
    void on_Dbutton_clicked();
    void on_Ebutton_clicked();
    void on_Fbutton_clicked();
    void on_Gbutton_clicked();
    void on_Hbutton_clicked();
    void on_Ibutton_clicked();
    void on_Jbutton_clicked();
    void on_Kbutton_clicked();
    void on_Lbutton_clicked();
    void on_Mbutton_clicked();
    void on_Nbutton_clicked();
    void on_Obutton_clicked();
    void on_Pbutton_clicked();
    void on_Qbutton_clicked();
    void on_Rbutton_clicked();
    void on_Sbutton_clicked();
    void on_Tbutton_clicked();
    void on_Ubutton_clicked();
    void on_Vbutton_clicked();
    void on_Wbutton_clicked();
    void on_Xbutton_clicked();
    void on_Ybutton_clicked();
    void on_Zbutton_clicked();

    void on_enterButton_clicked();
    void on_backButton_clicked();

private:
    Ui::Wordle *ui;
    std::vector<QTextEdit*> grid;
    std::vector<string> wordlist;
    void game();
    void letterEnter(std::string letter);
    int position[5][6];
    int count;
    int row;
    void checkWord();
    void makeVector();
};

#endif // WORDLE_H
