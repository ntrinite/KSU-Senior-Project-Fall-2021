#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/hammerhead/NO-TOUCH/KSU-Senior-Project-Fall-2021/ROS/src/rosserial/rosserial_vex_v5"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/hammerhead/NO-TOUCH/KSU-Senior-Project-Fall-2021/ROS/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/hammerhead/NO-TOUCH/KSU-Senior-Project-Fall-2021/ROS/install/lib/python2.7/dist-packages:/home/hammerhead/NO-TOUCH/KSU-Senior-Project-Fall-2021/ROS/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/hammerhead/NO-TOUCH/KSU-Senior-Project-Fall-2021/ROS/build" \
    "/usr/bin/python2" \
    "/home/hammerhead/NO-TOUCH/KSU-Senior-Project-Fall-2021/ROS/src/rosserial/rosserial_vex_v5/setup.py" \
     \
    build --build-base "/home/hammerhead/NO-TOUCH/KSU-Senior-Project-Fall-2021/ROS/build/rosserial/rosserial_vex_v5" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/hammerhead/NO-TOUCH/KSU-Senior-Project-Fall-2021/ROS/install" --install-scripts="/home/hammerhead/NO-TOUCH/KSU-Senior-Project-Fall-2021/ROS/install/bin"
