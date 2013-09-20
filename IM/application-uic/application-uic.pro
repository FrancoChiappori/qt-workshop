TEMPLATE = lib

QT -= gui
QT += widgets

CONFIG += staticlib

INCLUDEPATH += include

SOURCES += \
    source/application-uic.cpp \
    source/gui.cpp \
    source/UserListModel.cpp \
    source/User.cpp \
    source/UserTreeItemModel.cpp

HEADERS += \
    include/application-uic/application-uic.h \
    include/application-uic/gui.h \
    include/application-uic/UserListModel.h \
    include/application-uic/User.h \
    include/application-uic/UserTreeItemModel.h

FORMS += \
    im_form.ui

unix: QMAKE_CXXFLAGS_DEBUG += -fprofile-arcs -ftest-coverage

include(../common.pri)
include(../messenger/messenger.pri)


