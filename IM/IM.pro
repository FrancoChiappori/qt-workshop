TEMPLATE = subdirs

SUBDIRS = \
    main-uic \
    application-uic \
    unit-tests-uic \
    messenger \
    unit-tests

# dependencies for the UI forms skeleton
main-uic.depends = messenger application-uic
unit-tests-uic.depends = application-uic

unit-tests.depends = messenger

OTHER_FILES += \
    ../README.md

