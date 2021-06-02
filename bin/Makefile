# Ecrire make test pour compiler le jeu de test, puis ./exec pour lancer
# make exec pour l'interface
# Ajouter G=oui a la fin pour compiler avec l'option -g, et MAP=oui pour l'option -D MAP


ECHO = @echo
RM = @rm
RMFLAGS = -f
TOUCH = @touch

SOURCE = ../src

COMP = g++
EDL = g++
CCFLAGS = -ansi -pedantic -std=c++11 -I $(SOURCE)
LDFLAGS = -Wall -pedantic -std=c++11

INTERFACE = $(CONTROLLER) $(OBJET) $(SERVICE) $(VIEW)
OBJETS = $(INTERFACE:.h=.o)
EXE = airwatcher
EFFACE = clean

CONTROLLER = Main.h
OBJET = Agency.h Attribute.h Cleaner.h Date.h Individual.h Measurement.h Point.h Provider.h Sensor.h User.h
SERVICE = Service.h
VIEW = AbstractIHM.h IHMAgency.h IHMIndividual.h IHMProvider.h

Main=controller/Main

Agency=model/objet/Agency
Attribute=model/objet/Attribute
Cleaner=model/objet/Cleaner
Date=model/objet/Date
Individual=model/objet/Individual
Measurement=model/objet/Measurement
Point=model/objet/Point
Provider=model/objet/Provider
Sensor=model/objet/Sensor
User=model/objet/User

Service=model/service/Service

AbstractIHM=view/AbstractIHM
IHMAgency=view/IHMAgency
IHMIndividual=view/IHMIndividual
IHMProvider=view/IHMProvider

all: $(EXE)

affiche:
	$(ECHO) ">>> Interface <"$(INTERFACE)">"
	$(ECHO) ">>> Objets <"$(OBJETS)">"

$(EXE) : $(OBJETS)
	$(ECHO) ">>> Edition des liens de <"$(EXE)">"
	$(EDL) $(LDFLAGS) -o $(EXE) $(OBJETS)

define run
	$(ECHO) ">>> Compilation de < $< >"
	$(COMP)  $(CCFLAGS) -c $(SOURCE)/$<
endef

Main.o:$(Main).cpp
	$(run)

Agency.o:$(Agency).cpp
	$(run)

Attribute.o:$(Attribute).cpp
	$(run)

Cleaner.o:$(Cleaner).cpp
	$(run)

Date.o:$(Date).cpp
	$(run)

Individual.o:$(Individual).cpp
	$(run)

Measurement.o:$(Measurement).cpp
	$(run)

Provider.o:$(Provider).cpp
	$(run)

Point.o:$(Point).cpp
	$(run)

Sensor.o:$(Sensor).cpp
	$(run)

User.o:$(User).cpp
	$(run)

Service.o:$(Service).cpp
	$(run)

AbstractIHM.o:$(AbstractIHM).cpp
	$(run)

IHMAgency.o:$(IHMAgency).cpp
	$(run)

IHMIndividual.o:$(IHMIndividual).cpp
	$(run)

IHMProvider.o:$(IHMProvider).cpp
	$(run)

# Cible de nettoyage

$(EFFACE) :
	$(ECHO) ">>> Nettoyage du repertoire ($(EXE) $(OBJETS) $(OBJETSTEST) core)"
	$(RM) $(RMFLAGS) $(EXE) $(OBJETS) $(OBJETSTEST) core

controller/Main.cpp:

model/objet/Agency.cpp:
model/objet/Attribute.cpp:
model/objet/Cleaner.cpp:
model/objet/Date.cpp:
model/objet/Individual.cpp:
model/objet/Measurement.cpp:
model/objet/Point.cpp:
model/objet/Provider.cpp:
model/objet/Sensor.cpp:
model/objet/User.cpp:

model/service/Service.cpp:

view/AbstractIHM.cpp:
view/IHMAgency.cpp:
view/IHMIndividual.cpp:
view/IHMProvider.cpp:
