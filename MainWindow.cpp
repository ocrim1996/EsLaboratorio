//
// Created by Mirco Ceccarelli on 27/07/17.
//

#include <QDesktopWidget>
#include <QPainter>
#include "MainWindow.h"

MainWindow::MainWindow(LoadResources *resources_, QWidget *parent) : QMainWindow(parent), resources(resources_) {

    resources->registerObserver(this);

    this->setWindowTitle("Esercizio - Laboratorio di Programmazione - 2017");
    this->setFixedSize(QSize(600, 400));

    name = new QLabel("Mirco Ceccarelli", this);
    name->setGeometry(QRect(QPoint(15, 15), QSize(200, 30)));
    name->setAlignment(Qt::AlignLeft);

    linkToGitHub = new QLabel("<a href=\"https://github.com/ocrim1996/EsLaboratorio\">Link GitHub</a>", this);
    linkToGitHub->setOpenExternalLinks(true);
    linkToGitHub->setGeometry(QRect(QPoint(485, 15), QSize(100, 30)));
    linkToGitHub->setAlignment(Qt::AlignRight);

    title = new QLabel("Classe che carica file di risorse e aggiorna una progress bar (con QT).", this);
    title->setGeometry(QRect(QPoint(100, 60), QSize(400, 100)));
    title->setWordWrap(true);
    title->setAlignment(Qt::AlignCenter);
    QFont font = title->font();
    font.setPointSize(20);
    title->setFont(font);

    m_button = new QPushButton("Carica Risorse", this);
    m_button->setGeometry(QRect(QPoint(175, 200), QSize(250, 30)));

    progressBar = new QProgressBar(this);
    progressBar->setGeometry(QRect(QPoint(150, 170), QSize(300, 30)));

    text = new QTextEdit(this);
    text->setGeometry(QRect(QPoint(50, 240), QSize(500, 140)));
    text->setText("---> Pronto per caricare risorse\n");
    text->setReadOnly(true);

    QTextCursor c =  text->textCursor();
    c.movePosition(QTextCursor::End);
    text->setTextCursor(c);

    progressBar->setMinimum(0);
    progressBar->setMaximum(1000);
    progressBar->setValue(0);

    //Associa il bottone alla funzione
    connect(m_button, SIGNAL (released()), this, SLOT (loadResources()));
}

void MainWindow::update() {

    if (resources->didLoadFile()) {

        //Aggiorna Percentuale Progress Bar
        progressBar->setValue(progressBar->value() + (1000/resources->getNumberOfResources()));

        //Aggiorna Riquadro Testo
        QString log = "✅ File '" + QString(resources->getFilename()) + QString("' caricato con successo (") + QString::number(resources->getFilesize()) + QString(" bytes).") + "\n";
        text->append(log);

        //Aggiorna Testo Bottone
        QString percentText = QString::number(progressBar->value() / 10) + QString("% risorse caricate con successo!");
        m_button->setText(percentText);

    } else {

        //Aggiorna Riquadro Testo
        QString log = "❌ File '" + resources->getFilename() + QString(" non caricato!\n");
        text->append(log);
    }

};

void MainWindow::loadResources() {

    vector<const char*> filenames;

    filenames.push_back("logo.png");
    filenames.push_back("ciao.jpg");
    filenames.push_back("Jordan.png");
    filenames.push_back("Pizza.jpeg");
    filenames.push_back("Fiore.jpg");
    filenames.push_back("Coldplay.jpg");
    filenames.push_back("Canzone.mp3");
    filenames.push_back("Firenze.jpg");
    filenames.push_back("File.pdf");
    filenames.push_back("Python.py");
    filenames.push_back("Documento.tex");
    filenames.push_back("Tavolo.jpg");
    filenames.push_back("Word.docx");

    resources->load(filenames);

}