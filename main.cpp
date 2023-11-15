#include <iostream>
#include <string>

int addchars(char c1, char c2, char c3);
std::string addlines(std::string l1, std::string l2);
std::string revstr(std::string l);
std::string getridoffirstzeros(std::string l);

int main() {
	std::string n1, n2;
	std::getline(std::cin, n1);
	std::getline(std::cin, n2);

	std::cout << addlines(n1, n2);
	return 0;
}
std::string addlines(std::string l1, std::string l2) {
	if (l1 == "0" && l2 == "0") return "0";

	l1 = revstr(l1);
	l2 = revstr(l2);

	std::string res;
	int s1, s2, j = 0;
	s1 = l1.size();
	s2 = l2.size();

	char ost = '0';
	if (s1 >= s2) {
		for (int i = 0; j < s2; j++) {
			int r = addchars(l1[j], l2[j], ost);

			if (r == 0) {
				res += '0';
				ost = '0';
			}
			else if (r == 1) {
				res += '1';
				ost = '0';
			}
			else if (r == 2) {
				res += '0';
				ost = '1';
			}
			else {
				res += '1';
				ost = '1';
			}


		}
		for (int i = j; i < s1; i++) {
			int r = addchars(l1[i], ost, '0');

			if (r == 0) {
				res += '0';
				ost = '0';
			}
			else if (r == 1) {
				res += '1';
				ost = '0';
			}
			else if (r == 2) {
				res += '0';
				ost = '1';
			}
			else {
				res += '1';
				ost = '1';
			}
		}
		res += ost;
	}
	else {
		for (int i = 0; j < s1; j++) {
			int r = addchars(l1[j], l2[j], ost);

			if (r == 0) {
				res += '0';
				ost = '0';
			}
			else if (r == 1) {
				res += '1';
				ost = '0';
			}
			else if (r == 2) {
				res += '0';
				ost = '1';
			}
			else {
				res += '1';
				ost = '1';
			}


		}
		for (int i = j; i < s2; i++) {
			int r = addchars(l2[i], ost, '0');

			if (r == 0) {
				res += '0';
				ost = '0';
			}
			else if (r == 1) {
				res += '1';
				ost = '0';
			}
			else if (r == 2) {
				res += '0';
				ost = '1';
			}
			else {
				res += '1';
				ost = '1';
			}
		}
		res += ost;
	}

	res = revstr(res);
	res.pop_back();
	res = getridoffirstzeros(res);
	return res;
}
int addchars(char c1, char c2, char c3) {
	std::string n = { c1, c2, c3 };
	
	return std::count(n.begin(), n.end(), '1');
}
std::string revstr(std::string l) {
	std::string res;
	int s = l.size();
	for (int i = 0; i <= s; i++) {
		char cc = l[s - i];
		res += cc;
	}
	return res;
}
std::string getridoffirstzeros(std::string l) {
	std::string res;
	bool start = false;
	int s = l.size();
	for (int i = 0; i < s; i++) {
		char cc = l[i];
		if (!start && cc == '1') start = true;
		if (start) res += cc;
	}
	return res;
}
