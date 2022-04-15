#include "wordle.h"
#include "ui_wordle.h"
#include "WordleFile.h"
#include <vector>

#define ROW_COUNT 5
#define COLUMN_COUNT 6

using namespace std;

vector<QTextEdit*> grid;
vector<string> wordlist;
int position[ROW_COUNT][COLUMN_COUNT];

struct
{
    int count;
    int row;
    int col;
} r_c_count;



Wordle::Wordle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wordle)
{
    ui->setupUi(this);
    r_c_count.count = 0;
    r_c_count.col = 0;
    r_c_count.row = 0;
    makeVector();

}

Wordle::~Wordle()
{
    delete ui;
}

void Wordle::makeVector()
{
    grid.push_back(ui->text0_0);
    grid.push_back(ui->text0_1);
    grid.push_back(ui->text0_2);
    grid.push_back(ui->text0_3);
    grid.push_back(ui->text0_4);
    grid.push_back(ui->text1_0);
    grid.push_back(ui->text1_1);
    grid.push_back(ui->text1_2);
    grid.push_back(ui->text1_3);
    grid.push_back(ui->text1_4);
    grid.push_back(ui->text2_0);
    grid.push_back(ui->text2_1);
    grid.push_back(ui->text2_2);
    grid.push_back(ui->text2_3);
    grid.push_back(ui->text2_4);
    grid.push_back(ui->text3_0);
    grid.push_back(ui->text3_1);
    grid.push_back(ui->text3_2);
    grid.push_back(ui->text3_3);
    grid.push_back(ui->text3_4);
    grid.push_back(ui->text4_0);
    grid.push_back(ui->text4_1);
    grid.push_back(ui->text4_2);
    grid.push_back(ui->text4_3);
    grid.push_back(ui->text4_4);
    grid.push_back(ui->text5_0);
    grid.push_back(ui->text5_1);
    grid.push_back(ui->text5_2);
    grid.push_back(ui->text5_3);
    grid.push_back(ui->text5_4);


    for (int i = 0; 1 < sizeof(position); i++)
    {
        for (int j = 0; 1 < sizeof(position[0]); j++)
        {
            position[i][j] = r_c_count.count;
            r_c_count.count++;
        }
    }
    r_c_count.count = 0;
}

void Wordle::on_Abutton_clicked()
{
    letterEnter("A");
}

void Wordle::on_Bbutton_clicked()
{
    letterEnter("B");
}

void Wordle::on_Cbutton_clicked()
{
    letterEnter("C");
}

void Wordle::on_Dbutton_clicked()
{
    letterEnter("D");
}

void Wordle::on_Ebutton_clicked()
{
    letterEnter("E");
}

void Wordle::on_Fbutton_clicked()
{
    letterEnter("F");
}

void Wordle::on_Gbutton_clicked()
{
    letterEnter("G");
}

void Wordle::on_Hbutton_clicked()
{
    letterEnter("H");
}

void Wordle::on_Ibutton_clicked()
{
    letterEnter("I");
}

void Wordle::on_Jbutton_clicked()
{
    letterEnter("J");
}

void Wordle::on_Kbutton_clicked()
{
    letterEnter("K");
}

void Wordle::on_Lbutton_clicked()
{
    letterEnter("L");
}

void Wordle::on_Mbutton_clicked()
{
    letterEnter("M");
}

void Wordle::on_Nbutton_clicked()
{
    letterEnter("N");
}

void Wordle::on_Obutton_clicked()
{
    letterEnter("O");
}

void Wordle::on_Pbutton_clicked()
{
    letterEnter("P");
}


void Wordle::on_Qbutton_clicked()
{
    letterEnter("Q");
}

void Wordle::on_Rbutton_clicked()
{
    letterEnter("R");
}

void Wordle::on_Sbutton_clicked()
{
    letterEnter("S");
}

void Wordle::on_Tbutton_clicked()
{
    letterEnter("T");
}

void Wordle::on_Ubutton_clicked()
{
    letterEnter("U");
}

void Wordle::on_Vbutton_clicked()
{
    letterEnter("V");
}

void Wordle::on_Wbutton_clicked()
{
    letterEnter("W");
}

void Wordle::on_Xbutton_clicked()
{
    letterEnter("X");
}

void Wordle::on_Ybutton_clicked()
{
    letterEnter("Y");
}

void Wordle::on_Zbutton_clicked()
{
    letterEnter("Z");
}

void Wordle::on_enterButton_clicked()
{
    if (position[4][r_c_count.row] == r_c_count.count)
    {
        checkWord();
        r_c_count.row++;
        r_c_count.count++;
    }
}

void Wordle::on_backButton_clicked()
{
    if (position[0][r_c_count.row] != r_c_count.count)
    {
        r_c_count.count--;
        grid[r_c_count.count]->setText("");
    }
}

void Wordle::game()
{

}

inline void Wordle::letterEnter(string letter)
{
    if (position[4][r_c_count.row] != r_c_count.count)
    {
        grid[r_c_count.count]->setText(QString::fromStdString(letter));
        r_c_count.count++;
    }
}

void Wordle::checkWord()
{

}
