//
// Created by Mirco Ceccarelli on 27/07/17.
//

#ifndef ESLABORATORIO_MAINWINDOW_H
#define ESLABORATORIO_MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QProgressBar>
#include <QTextEdit>
#include <QLabel>
#include "Observer.h"
#include "LoadResources.h"
#include <iostream>

class MainWindow : public QMainWindow, public Observer {
Q_OBJECT
public:
    MainWindow(LoadResources *resources_, QWidget *parent = 0);

    virtual ~MainWindow() {
        resources->removeObserver(this);
    }

    virtual void update() override;

    LoadResources *getResources() const {
        return resources;
    }

private slots:
    void loadResources();

private:

    LoadResources * resources;

    QPushButton * m_button;
    QProgressBar * progressBar;
    QTextEdit * text;

    QLabel * linkToGitHub;
    QLabel * title;
    QLabel * name;
};

#endif //ESLABORATORIO_MAINWINDOW_H
