find_package(Qt4)

if (QT4_FOUND AND ENKI_FOUND)
	find_package(OpenGL REQUIRED)
	
	include(${QT_USE_FILE})
	
	include_directories(${ENKI_INCLUDE_DIR})
	
	set(playground_SRCS playground.cpp playground-vm-description.c)
	
	qt4_automoc(${playground_SRCS})
	
	#qt4_add_resources(playground_RCC_SRCS playground-textures.qrc)
	
	include_directories (${QT_INCLUDE_DIR} ${QT_QTNETWORK_INCLUDE_DIR} ${QT_QTOPENGL_INCLUDE_DIR} ${CMAKE_BINARY_DIR}/targets/playground .)
	
	add_executable(asebaplayground WIN32 ${playground_SRCS} ${playground_RCC_SRCS})
	
	if (WIN32)
		target_link_libraries(asebaplayground aseba ${ENKI_VIEWER_LIBRARY} ${ENKI_LIBRARY} ${QT_LIBRARIES} ${QT_QTNETWORK_LIBRARIES} ${QT_QTOPENGL_LIBRARIES} ${QT_QTMAIN_LIBRARY} ${EXTRA_LIBS} ${OPENGL_LIBRARIES})
	else (WIN32)
		target_link_libraries(asebaplayground aseba ${ENKI_VIEWER_LIBRARY} ${ENKI_LIBRARY} ${QT_LIBRARIES} ${QT_QTNETWORK_LIBRARIES} ${QT_QTOPENGL_LIBRARIES} ${EXTRA_LIBS} ${OPENGL_LIBRARIES})
	endif (WIN32)

endif (QT4_FOUND AND ENKI_FOUND)