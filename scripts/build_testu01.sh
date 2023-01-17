DIR=$(cd $(dirname $0); cd ..; pwd)
cd ${DIR}/third_party/testu01
chmod 755 configure
chmod 755 install-sh
chmod 755 bootstrap
./bootstrap
./configure --prefix=${DIR}/build_testu01
make install -j4
git add . && git reset --hard HEAD