CXX = g++

CXXFLAGS = -std=c++0x

OBJS = Belt.o CargoCompartment.o Cell.o CentralCoreShaft.o Cockpit.o CommandOffice.o DetentionBlock.o GameClient.o HangarBay.o MillenniumFalcon.o main.o Player.o PowerControls.o PowerTrench.o Space.o TrashCompactor.o

SRCS = Belt.cpp CargoCompartment.cpp Cell.cpp CentralCoreShaft.cpp Cockpit.cpp CommandOffice.cpp DetentionBlock.cpp GameClient.cpp HangarBay.cpp MillenniumFalcon.cpp main.cpp Player.cpp PowerControls.cpp PowerTrench.cpp Space.cpp TrashCompactor.cpp

HEADERS = Belt.h CargoCompartment.h Cell.h CentralCoreShaft.h Cockpit.h CommandOffice.h DetentionBlock.h GameClient.h HangarBay.h MillenniumFalcon.h clearScreen.hpp Player.h PowerControls.h PowerTrench.h Space.h TrashCompactor.h

StarWars: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o StarWars

clean:
	rm -f .o StarWars
