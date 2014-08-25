#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string show(unsigned char v) {
	char buf[9] = { 0 };
	for (int i = 7; i >= 0; --i) {
		buf[i] = (v & 1) + '0';
		v >>= 1;
	}
	
	return string(buf);
}

int main(int argc, char *argv[]) {
	bool flgcheck = false;
	bool comcheck = false;
	if (argc > 1) {
		if (string(argv[1]) == "-f") {
			flgcheck = true;
		} else if(string(argv[1]) == "-c") {
			comcheck = true;
		} else {
			return 0;
		}
	} else {
		return 0;
	}


	bool OF, SF, ZF, CF;
	OF = SF = ZF = CF = false;



	int val;
	char val8;
	for (int i = 0; i <= 0xff; ++i) {
		for (int j = 0; j <= 0xff; ++j) {
			unsigned char dst = i;
			unsigned char src = j;
			val8 = val = (char)dst - (char)src;
			(val8 < 0) ? SF = true : SF = false;
			(val != val8) ? OF = true : OF = false;
			(val == 0) ? ZF = true : ZF = false;
			(dst < src) ? CF = true : CF = false;
			
			if(flgcheck) {
				if (SF == OF) {
					printf("cmp 0x%02x(%d), 0x%02x(%d) : %d\n", dst, (char)dst, src, (char)src, val);
				}
			} else if (comcheck) {
				if ((char)dst >= (char)src) {
					printf("cmp 0x%02x(%d), 0x%02x(%d) : %d\n", dst, (char)dst, src, (char)src, val);
				}
			}
		}
	}
	
	return 0;
}
