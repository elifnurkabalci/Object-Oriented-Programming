JFLAGS = -g
JC = javac
.SUFFIXES: .java .class

	
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
    DayofYearSet.java
	

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class