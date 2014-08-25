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
	bool summary = false;
	bool flgcheck = false;
	bool subflg = false;
	int index = 1;
	if (argc > 1) {
		if (string(argv[index]) == "-s") {
			summary = true;
			++index;
		} else if(string(argv[index]) == "-f") {
			flgcheck = true;
			++index;
		}

		if (string(argv[index]) == "sub") {
			subflg = true;
		}
	}

	if(!flgcheck) {
		for (int i = 0; i <= 0xff; ++i) {
			for (int j = 0; j <= 0xff; ++j) {
				int r;
				
				if(subflg) {
					r = (char)(i & 0xff) - (char)(j & 0xff);
				} else {
					r = (char)(i & 0xff) + (char)(j & 0xff);
				}
				string ov;
				if (r < -128 || r > 127) {
					ov = "of";
				} else {
					ov = "-";
				}
				if(summary) {
					printf("%d (%s)\n", r, ov.c_str());
				} else {
					if (subflg) {
						printf("%d(%s) - (%d)(%s) = %d (%s)\n", (char)i, show(i).c_str(), (char)j, show(j).c_str(), r, ov.c_str());
					} else {
						printf("%d(%s) + %d(%s) = %d (%s)\n", (char)i, show(i).c_str(), (char)j, show(j).c_str(), r, ov.c_str());
					}
				}
			}
		}

		return 0;
	}
	int  val;
	char val8;
	if (flgcheck) {
		for (int i = 0; i <= 0xff; ++i) {
			for (int j = 0; j <= 0xff; ++j) {
				unsigned char src = i;
				unsigned char dst = j;
				if (subflg) {
					val8 = val = (char)src - (char)dst;
				} else {
					val8 = val = (char)src + (char)dst;
				}

				//				val8 = val = (char)(i & 0xff) + (char)(j & 0xff);
				string ov;
				if (val8 != val) {
					ov = "of";
				} else {
					ov = "-";
				}
				printf("%d (%s)\n", val, ov.c_str());
			}
		}
		
	}

}
