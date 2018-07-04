TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lcurl
LIBS += -lgumbo
LIBS += -lhtmlcxx

SOURCES += \
    Hooker.cpp \
    NetBug.cpp \
    Parser.cpp \
    test.cpp \
    SpecParser.cpp

HEADERS += \
    Hooker.h \
    Parser.h \
    SpecParser.h \
    NetBug.h

