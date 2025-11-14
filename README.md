# Clone msquic (including submodules)
git clone --recurse-submodules https://github.com/microsoft/msquic.git
cd msquic
git submodule update --init --recursive
git checkout v2.5.5

# Create build and install folders
mkdir -p build install
cd build

cmake -G "Unix Makefiles" \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_SHARED_LIBS=OFF \
  -DCMAKE_INTERPROCEDURAL_OPTIMIZATION=ON \
  -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
  -DCMAKE_C_FLAGS_RELEASE="-O3 -march=native -flto -fomit-frame-pointer -fdata-sections -ffunction-sections" \
  -DCMAKE_CXX_FLAGS_RELEASE="-O3 -march=native -flto -fomit-frame-pointer -fdata-sections -ffunction-sections" \
  -DCMAKE_EXE_LINKER_FLAGS="-flto -Wl,--gc-sections -s" \
  -DQUIC_TLS_LIB=quictls \
  -DQUIC_BUILD_TEST=OFF \
  -DQUIC_BUILD_TOOLS=OFF \
  -DQUIC_ENABLE_LOGGING=OFF \
  -DCMAKE_INSTALL_PREFIX="$(pwd)/../install" \
  ..

# Build
make -j$(nproc)

# Install to the "install" directory
make install