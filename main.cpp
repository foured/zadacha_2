#include <iostream>
#include <string>

std::string numtocell(double n);
std::string revbin_str(std::string l);
std::string dectobin_str(long long n);
std::string fracparttobin_str(double n);

int main() {
	double n;
	std::cin >> n;
	std::cout << numtocell(n);

	return 0;
}
std::string numtocell(double n) {
	bool isNegative = n < 0;
	if (isNegative) n *= -1;

	double dPart;
	long long llPart;

	llPart = (long long)n;
	dPart = n - (double)llPart;

	std::string llPartDec_str = dectobin_str(llPart), dPartDec_str = fracparttobin_str(dPart);
	std::string order, mantissa, res;
	int step;

	if (n >= 1) {
		step = llPartDec_str.size() + 126;

		for (int i = 1; llPartDec_str[i] != '\0'; i++) {
			mantissa += llPartDec_str[i];
		}
		mantissa += dPartDec_str;
	}
	else {
		step = 0;
		while (dPartDec_str[step] != '1') {
			step++;
		}
		step = -(step + 1) + 127;

		bool start = false;
		for (int i = 0; dPartDec_str[i] != '\0'; i++) {
			char cc = dPartDec_str[i];

			if (start) mantissa += cc;
			if (!start && cc == '1') start = true;
		}
		std::cout << mantissa << std::endl;
	}
	order = dectobin_str(step);
	int ras = 8 - order.size();
	for (int i = 0; i < ras; i++) {
		order = '0' + order;
	}

	ras = 23 - mantissa.size();
	for (int i = 0; i < ras; i++) {
		mantissa += '0';
	}

	res += '0' + (int)isNegative;
	res += order;
	res += mantissa;
	return res;
}
std::string fracparttobin_str(double n) {
	std::string res = "";
	int i = 0;

	while (i < 23) {
		i++;
		n *= 2;

		if (n > 1) {
			res += '1';
			n -= 1.0;
		}
		else if (n == 1) {
			res += '1';
			break;
		}
		else {
			res += '0';
		}
	}
	return res;
}
std::string revbin_str(std::string l) {
	std::string res = "";

	for (int i = 0; i < l.size(); i++) {
		if (l[i] == '1') res += '0';
		else if (l[i] == '0') res += '1';
	}

	return res;
}
std::string dectobin_str(long long n) {
	if (n < 0) n *= -1;

	if (n == 0) return "0";

	std::string l = "";
	while (n) {
		int d = n % 2;
		n /= 2;

		if (d == 1) l = '1' + l;
		else l = '0' + l;
	}
	return l;
}
