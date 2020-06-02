set(MODULE_NAME 02_observer)
project(${MODULE_NAME})

set(SRCS
        Observable/Observable.cpp
        Observable/Observable.h
        Observable/ConcreteObservable.cpp
        Observable/ConcreteObservable.h
        Observer/Observer.cpp
        Observer/Observer.h
        Observer/ConcreteObserver.cpp
        Observer/ConcreteObserver.h
        RunningObservingSystem.cpp
        RunningObservingSystem.h
        main.cpp
        )

add_executable(${MODULE_NAME} ${SRCS})

target_include_directories(${MODULE_NAME}
    PUBLIC
        ${GLOG_INCLUDE_DIR}
        ${BOOST_INCLUDE_DIR}
        ${RAPIDJSON_INCLUDE_DIR}
        )

target_link_directories(${MODULE_NAME}
    PUBLIC
        ${GLOG_LIBRARY_DIR}
        ${BOOST_LIBRARY_DIR}
        )

target_link_libraries(${MODULE_NAME}
    PUBLIC
        pthread
        ssl
        crypto
        boost_system
        boost_thread
        glog
        )
