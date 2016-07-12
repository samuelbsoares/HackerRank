#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct bigInt {
	vector<int> a;
	bigInt() {
		a.push_back(0);
	}
	bigInt(int x) {
		if(x == 0)
			a.push_back(0);
		while(x != 0) {
			a.push_back(x % 10);
			x = x / 10;
		}
	}
	void operator += (const bigInt& b) {
		vector<int> x, y, z;
		x = a;
		y = b.a;
		int n = x.size();
		int m = y.size();
		if(n < m)
			for(int i = 0; i < m - n; ++i)
				x.push_back(0);
		else
			for(int i = 0; i < n - m; ++i)
				y.push_back(0);
		int h = 0;
		for(int i = 0; i < x.size(); ++i) {
			z.push_back(x[i] + y[i] + h);
			h = z[i] / 10;
			z[i] %= 10;
		}
		if(h == 1)
			z.push_back(1);
		while(z[z.size()-1] == 0)
			z.pop_back();
		a = z;
	}
	void operator -=( const bigInt& b) {
		for(int i = 0; i < b.a.size(); ++i) {
			a[i] -= b.a[i];
			if(a[i] < 0) {
				a[i] += 10;
				int j = i + 1;
				while(a[j] == 0) {
					a[j] = 9;
					++j;
				}
				--a[j];
			}
		}
		while(a[a.size()-1] == 0 && a.size() != 1)
			a.pop_back();
	}
	bigInt multByDigit(const bigInt& b, int x) {
		bigInt ans;
		vector<int> res;
		int h = 0;
		for(int i = 0; i < b.a.size(); ++i){
			res.push_back(b.a[i] * x + h);
			h = res[res.size()-1] / 10;
			res[res.size()-1] %= 10;
		}
		if(h != 0)
			res.push_back(h);
		ans.a = res;
		return ans;
	}
	void operator *=(const bigInt& b) {
		bigInt ans;
		for(int i = 0; i < b.a.size(); ++i) {
			vector<int> c;
			for(int j = 0; j < i; ++j)
				c.push_back(0);
			bigInt d;
			d = d.multByDigit(*this, b.a[i]);
			for(int j = 0; j < d.a.size(); ++j)
				c.push_back(d.a[j]);
			bigInt temp;
			temp.a = c;
			ans += temp;
		}
		*this = ans;
	}
	bigInt half(const bigInt& bb) {
		vector<int> ans;
		bigInt b = bb;
		int i = b.a.size() - 1;
		while(i >= 0){
			if(b.a[i] % 2 == 0) {
				if(i != 0)
					ans.push_back(b.a[i] / 2);
				--i;
			}
			else {
				if(b.a[i] != 1) {
					ans.push_back(b.a[i] / 2);
					b.a[i] = 1;
				}
				else {
					int x = b.a[i];
					if(i - 1 >= 0)
						x = x * 10 + b.a[i-1];
					if(i != 0)
					  ans.push_back(x / 2);
					--i;
					if(i - 1 >= 0)
						b.a[i] = 1;
				}
			}
		}
		bigInt res;
		reverse(ans.begin(), ans.end());
		res.a = ans;
		return res;
	}
};

istream& operator>> (istream& in, bigInt& x) {
	string s;
	x.a.clear();
	in >> s;
	for(int i = s.size() - 1; i >= 0; --i)
		x.a.push_back(s[i] - '0');
	return in; 
}
ostream& operator<< (ostream& out, const bigInt& x) {
	for(int i = x.a.size() - 1; i >= 0; --i)
		out << x.a[i];
	return out;
}
bigInt operator+ (const bigInt& a, const bigInt& b) {
	bigInt c;
	c = a;
	c += b;
	return c;
}
bigInt operator* (const bigInt& a, const bigInt& b) {
	bigInt c = a;
	c* = b;
	return c;
}
bigInt operator- (const bigInt& a, const bigInt b) {
	bigInt c;
	c = a;
	c -= b;
	return c;
}

int main() {
	int n, e;
    vector<int> sums;
    bigInt a(2), b(2);
    for (int j = 1; j < 10000; ++j) {
        int s(0);
        a *= b;
        for(int i = 0; i < a.a.size(); ++i)
            s += (a.a[i]);
        sums.push_back(s);
    }
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> e;
        cout << sums[e - 2] <<endl;
    }
    
  return 0;
}
