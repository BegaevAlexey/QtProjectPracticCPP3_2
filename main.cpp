// main.cpp  - поиск коэффициента D функции f(x)=(1+t)^(-a) и постраение графика этой функции

#include <QApplication>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "well.h"
#include "getvectorwell.h"
#include "qcustomplot.h"

//функция принимает имя файла
//и возращает контейнер vector объектов Well
std::vector<Well> getVectorWell(const char* NameFile);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //строка, хранящая путь к файлу
    std::string fileName("/home/alexey/qtProject/practic/data.txt");

    //создаем вектор объектов well
    std::vector<Well> wells(getVectorWell(fileName.c_str()));

    //поиск коэффициента (-a)
    double a_;
    for(auto well: wells)
        a_=+ log(well.q()/well.q0())/log(well.timeSum()+1);

    // создаем виджет QCustomPlot
    QCustomPlot cPlot;

    const int A=1.5;
    const int range=100*A+1;
    // генерируем данные
    QVector<double> x(range), y(range);
    for (int i=0; i<range; ++i)
    {
        x[i] = i/(50.0) - A; // x изменяется от -1 до 1
        y[i] = pow((1+x[i]),a_);
    }
    // создаем график и добавляем данные:
    cPlot.addGraph();
    cPlot.graph(0)->setData(x, y);

    // задаем обозначения осей координат:
    cPlot.xAxis->setLabel("x");
    cPlot.yAxis->setLabel("y");

    // устанавливаем диапазоны отображения данных:
    cPlot.xAxis->setRange(-A, A);
    cPlot.yAxis->setRange(0, 1.8);

    // рисуем график
    cPlot.replot();

    //название графика
    std::string label("f(x)=(1+t)^(-a), -a=");
    std::string fStr = std::to_string(a_);
    label += fStr;
    cPlot.setWindowTitle(label.c_str());

    cPlot.resize(548, 420);
    cPlot.show();

    return app.exec();
}

