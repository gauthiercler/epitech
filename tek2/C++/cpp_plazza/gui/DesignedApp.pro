#-------------------------------------------------
#
# Project created by QtCreator 2017-04-28T11:36:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DesignedApp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES +=\
        mainwindow.cpp \
    sources/ACypher.cpp \
    sources/CaesarCypher.cpp \
    sources/Command.cpp \
    sources/CommandManager.cpp \
    sources/ConnectorPipe.cpp \
    sources/File.cpp \
    sources/main.cpp \
    sources/Mutex.cpp \
    sources/Office.cpp \
    sources/ProcessManager.cpp \
    sources/Reception.cpp \
    sources/Thread.cpp \
    sources/ThreadPool.cpp \
    sources/Utils.cpp \
    sources/Worker.cpp \
    sources/XorCracker.cpp \
    sources/XorCypher.cpp

HEADERS  += mainwindow.h \
    includes/ACypher.hpp \
    includes/CaesarCypher.hpp \
    includes/Command.hpp \
    includes/CommandManager.hpp \
    includes/CondVar.hpp \
    includes/Config.hpp \
    includes/ConnectorPipe.hpp \
    includes/Error.hpp \
    includes/File.hpp \
    includes/Mutex.hpp \
    includes/Office.hpp \
    includes/ProcessManager.hpp \
    includes/Reception.hpp \
    includes/Thread.hpp \
    includes/ThreadPool.hpp \
    includes/Utils.hpp \
    includes/Worker.hpp \
    includes/XorCracker.hpp \
    includes/XorCypher.hpp

FORMS    += mainwindow.ui

INCLUDEPATH += includes
