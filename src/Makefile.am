EXTRA_DIST = GameWorld.h GameAssetManager.h GameAsset.h CubeAsset.h Camera.h PyramidAsset.h 

bin_PROGRAMS = shaderexample
shaderexample_SOURCES = main.cc 
shaderexample_LDADD = libhydra.la

lib_LTLIBRARIES = libhydra.la
libhydra_la_SOURCES = GameWorld.cc GameAssetManager.cc CubeAsset.cc Camera.cc PyramidAsset.cc
libhydra_la_LDFLAGS = -version-info 0:1

AM_CPPFLAGS = -DGL_GLEXT_PROTOTYPES -DGL3_PROTOTYPES
AM_CPPFLAGS += -std=c++11
AM_CPPFLAGS += $(gl_CFLAGS) $(glew_CFLAGS) $(sdl2_CFLAGS) $(BOOST_CPPFLAGS)
LIBS += $(gl_LIBS) $(glew_LIBS) $(sdl2_LIBS) $(BOOST_THREAD_LIBS) $(BOOST_PROGRAM_OPTIONS_LIBS)
