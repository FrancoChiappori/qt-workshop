Qt workshop at Symposium 2013
=============================

[![Build Status](https://travis-ci.org/FrancoChiappori/qt-workshop.png)](https://travis-ci.org/FrancoChiappori/qt-workshop)

[![Coverage Status](https://coveralls.io/repos/FrancoChiappori/qt-workshop/badge.png)](https://coveralls.io/r/FrancoChiappori/qt-workshop)

Setup
-----

The project contains three skeletons applications.
One uses Qml, another Qt Designer ui forms and the third one uses QtWidgets in C++.

After you decided which one to use you may delete the *main-xxx*, *application-xxx* and *unit-tests-xxx* folders that you don't use.
And remove those entries from the main project file *IM.pro* as well.

Build
-----

### Qt Creator ###

Open *IM/IM.pro* with the Qt Creator.
Right click on *IM* in the *Projects* tab and select *Run qmake*.
Then use the hammer symbol to build the application and tests.

You can run the tests and the application from Qt Creater by selecting the desired executable (screen symbol)
and then click on the run button (green triangle symbol).

### Console ###

Create a directory on top level - besides the *IM* directory - and change into this newly created folder.
Then run qmake and call make:
```
qmake ../IM/IM.pro -r CONFIG+=debug
make
```

To run the tests make target check:
```
make check
```


