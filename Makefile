
JNL = jnl

all : 

$(JNL): jnl.cpp
	g++ -o $@ $^

testjnl: $(JNL)
	./$(JNL) -f > flgresult.txt
	./$(JNL) -c > cmpresult.txt
	diff flgresult.txt cmpresult.txt
