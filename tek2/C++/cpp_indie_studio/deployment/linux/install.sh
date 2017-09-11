#!/bin/bash

set -e

BASE_DIR=$PWD
BUILD_DIR="/$PWD/build"
export PATH=/$PWD/build/bin:/$PWD/build/lib:/$PWD/build/lib64:/$PWD/build/include:/$PATH
export PKG_CONFIG=$BUILD_DIR/bin/pkg-config
export LD_LIBRARY_PATH=$BUILD_DIR/lib:/$PWD/build/lib


function get_dependency()
{
    wget -O packages/$1 $2
}

function download_dependencies()
{
    get_dependency irrlicht.zip https://netcologne.dl.sourceforge.net/project/irrlicht/Irrlicht%20SDK/1.8/1.8.4/irrlicht-1.8.4.zip
    get_dependency libmessa.tar.gz ftp://ftp.freedesktop.org/pub/mesa/mesa-17.1.0-rc3.tar.gz
    get_dependency pkgconfig.tgz http://pkgconfig.freedesktop.org/releases/pkg-config-0.28.tar.gz
    get_dependency zlib.tar.gz http://zlib.net/zlib-1.2.11.tar.gz
    get_dependency glproto.tar.gz https://www.x.org/archive/individual/proto/glproto-1.4.17.tar.gz
    get_dependency libdrm.tar.gz https://dri.freedesktop.org/libdrm/libdrm-2.4.80.tar.gz
    get_dependency libpciaccess.tar.gz https://www.x.org/archive/individual/lib/libpciaccess-0.13.tar.gz
    get_dependency dri2proto.tar.gz https://www.x.org/archive/individual/proto/dri2proto-2.8.tar.gz
    get_dependency libxcb.tar.gz https://xcb.freedesktop.org/dist/libxcb-1.12.tar.gz
    get_dependency python.tar.xz https://www.python.org/ftp/python/2.7.10/Python-2.7.10.tar.xz
    get_dependency xcb-proto.tar.gz https://xcb.freedesktop.org/dist/xcb-proto-1.12.tar.gz
    get_dependency pthread-stubs.tar.gz https://xcb.freedesktop.org/dist/libpthread-stubs-0.4.tar.gz
    get_dependency libXau.tar.gz https://www.x.org/releases/individual/lib/libXau-1.0.8.tar.gz
    get_dependency xproto.tar.gz https://www.x.org/archive/individual/proto/xproto-7.0.31.tar.gz
    get_dependency xshmfence.tar.gz ftp://ftp.x.org/pub/individual/lib/libxshmfence-1.2.tar.gz
    get_dependency x11.tar.gz ftp://ftp.x.org/pub/individual/lib/libX11-1.6.5.tar.gz
    get_dependency xextproto.tar.gz https://www.x.org/releases/individual/proto/xextproto-7.3.0.tar.gz
    get_dependency xtrans.tar.gz ftp://ftp.x.org/pub/individual/lib/xtrans-1.3.5.tar.gz
    get_dependency kbproto.tar.gz https://www.x.org/archive/individual/proto/kbproto-1.0.7.tar.gz
    get_dependency inputproto.tar.gz https://www.x.org/archive/individual/proto/inputproto-2.3.2.tar.gz
    get_dependency perl.tar.gz http://www.cpan.org/src/5.0/perl-5.24.1.tar.gz
    get_dependency libxext.tar.gz https://www.x.org/releases/individual/lib/libXext-1.3.3.tar.gz
    get_dependency xdamage.tar.gz https://www.x.org/releases/individual/lib/libXdamage-1.1.4.tar.gz
    get_dependency damageproto.tar.gz https://www.x.org/archive/individual/proto/damageproto-1.2.1.tar.gz
    get_dependency xfixes.tar.gz https://www.x.org/archive//individual/lib/libXfixes-5.0.3.tar.gz
    get_dependency fixesproto.tar.gz https://www.x.org/archive/individual/proto/fixesproto-5.0.tar.gz
    get_dependency expat.tar.gz http://downloads.sourceforge.net/expat/expat-2.1.0.tar.gz
    get_dependency libxxf86vm.tar.gz https://www.x.org/releases/individual/lib/libXxf86vm-1.1.4.tar.gz
    get_dependency x86vidmodeproto.tar.gz https://www.x.org/releases/individual/proto/xf86vidmodeproto-2.3.1.tar.gz
    get_dependency xcursor.tar.gz ftp://ftp.x.org/pub/individual/lib/libXcursor-1.1.14.tar.gz
    get_dependency xrender.tar.gz https://www.x.org/releases/individual/lib/libXrender-0.9.10.tar.gz
    get_dependency renderproto.tar.gz https://www.x.org/archive/individual/proto/renderproto-0.11.tar.gz
    get_dependency cmake.tar.gz https://cmake.org/files/v3.8/cmake-3.8.1.tar.gz
    get_dependency xrandr.tar.gz https://www.x.org/releases/individual/lib/libXrandr-1.5.1.tar.gz
    get_dependency randrproto.tar.gz https://www.x.org/archive/individual/proto/randrproto-1.5.0.tar.gz
    get_dependency sfml.tar.gz https://www.sfml-dev.org/files/SFML-2.4.2-linux-gcc-64-bit.tar.gz
    get_dependency openal.tar.bz2 http://kcat.strangesoft.net/openal-releases/openal-soft-1.18.0.tar.bz2
    get_dependency vorbis.tar.gz http://downloads.xiph.org/releases/vorbis/libvorbis-1.3.5.tar.gz
    get_dependency libogg.tar.gz http://downloads.xiph.org/releases/ogg/libogg-1.3.2.tar.gz
    get_dependency flac.tar.xz http://downloads.xiph.org/releases/flac/flac-1.3.2.tar.xz
    get_dependency python3.tar.xz https://www.python.org/ftp/python/3.6.1/Python-3.6.1.tar.xz
}

function install()
{
    {
	if [[ $1 == *.tar.gz ]]
	then
	    tar -zxvf $1
	elif [[ $1 == *.tgz ]]
	then
	    tar -zxf $1
	elif [[ $1 == *.tar.xz ]]
	then
	    tar -xvf $1
	fi
	cd $2
	if [[ ${#3} -eq 0 ]]
	then
	    ./configure --prefix=$BUILD_DIR
	else
	    ./configure --prefix=$BUILD_DIR "$3"
	fi
	make install
	cd ..
    } || {
	echo "Error in $1"
	exit 1
    }
}

rm -rf packages
mkdir packages
download_dependencies

cd packages

install pkgconfig.tgz pkg-config-0.28 --with-internal-glib
install zlib.tar.gz zlib-1.2.11
install glproto.tar.gz glproto-1.4.17
install libpciaccess.tar.gz libpciaccess-0.13
install libdrm.tar.gz libdrm-2.4.80
install dri2proto.tar.gz dri2proto-2.8
install python.tar.xz Python-2.7.10 --enable-shared
install xcb-proto.tar.gz xcb-proto-1.12
install pthread-stubs.tar.gz libpthread-stubs-0.4
install xproto.tar.gz xproto-7.0.31
install libXau.tar.gz libXau-1.0.8
install libxcb.tar.gz libxcb-1.12
install xshmfence.tar.gz libxshmfence-1.2
install xextproto.tar.gz xextproto-7.3.0
install xtrans.tar.gz xtrans-1.3.5
install kbproto.tar.gz kbproto-1.0.7
install inputproto.tar.gz inputproto-2.3.2

###############
{
    tar -zxvf perl.tar.gz
    cd perl-5.24.1
    ./configure.gnu --prefix=$BUILD_DIR
    make install
    cd ..
} || {
    echo "Error perl"
    exit 1
}
##############

install x11.tar.gz libX11-1.6.5
install libxext.tar.gz libXext-1.3.3
install damageproto.tar.gz damageproto-1.2.1
install fixesproto.tar.gz fixesproto-5.0
install xfixes.tar.gz libXfixes-5.0.3
install xdamage.tar.gz libXdamage-1.1.4
install expat.tar.gz expat-2.1.0

tar -zxvf libmessa.tar.gz
cd mesa-17.1.0-rc3
./configure --prefix=$BUILD_DIR --with-dri-drivers= --with-gallium-drivers=r600 --disable-gallium-llvm
make install
cd ..



install x86vidmodeproto.tar.gz xf86vidmodeproto-2.3.1
install libxxf86vm.tar.gz libXxf86vm-1.1.4

unzip irrlicht.zip -d irrlicht
cd irrlicht/irrlicht-1.8.4/source/Irrlicht

sed -i "s/CXXFLAGS += /override &/" Makefile
sed -i "s/LDFLAGS += /override &/" Makefile

make NDEBUG=1 sharedlib LDFLAGS="-L../../../../../build/lib" CXXFLAGS="-I../../../../../build/include -fPIC"
make install INSTALL_DIR=$BUILD_DIR/lib

cd $BASE_DIR/packages


install renderproto.tar.gz renderproto-0.11
install xrender.tar.gz libXrender-0.9.10
install xcursor.tar.gz libXcursor-1.1.14


install randrproto.tar.gz randrproto-1.5.0
install xrandr.tar.gz libXrandr-1.5.1
install cmake.tar.gz cmake-3.8.1

tar -zxvf sfml.tar.gz
cp -r SFML-2.4.2/* $BUILD_DIR

tar -jxf openal.tar.bz2
cd openal-soft-1.18.0/
cmake . -DCMAKE_INSTALL_PREFIX=$BUILD_DIR
make install
cd ..

install libogg.tar.gz libogg-1.3.2
install vorbis.tar.gz libvorbis-1.3.5
install flac.tar.xz flac-1.3.2
install python3.tar.xz Python-3.6.1 --enable-shared

exit 0
