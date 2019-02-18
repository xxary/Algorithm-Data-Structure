#include<algorithm>
#include<iomanip>
#include<stdexcept>
#include<iostream>
#include<vector>
#include<string>

using std::cin;              using std::max;
using std::cout;             using std::setprecision;
using std::domain_error;     using std::sort;
using std::endl;             using std::streamsize;
using std::istream;          using std::string;
using std::vector;

struct Student {
	std::string name;
	double midterm, fin;
	vector<double> homework;
};

bool compare(const Student &x, const Student &y)
{
	return x.name < y.name;
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		hw.clear();
		double x;
		while (in >> x)
			hw.push_back(x);
		in.clear();
	}
	return in;
}

istream& read(istream& is, Student& s)
{
	is >> s.name >> s.midterm >> s.fin;
	read_hw(is, s.homework);
	return is;
}



double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("何もない");
	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

//double grade(double, double, double);
//double grade(double, double, const vector<double>&);
//double grade(const Student& s);
double grade(double midterm, double fin, double homework) {
	return 0.2*midterm + 0.4*fin + 0.4*homework;
}
double grade(double midterm, double fin, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("何もない");
	return grade(midterm, fin, median(hw));
}
double grade(const Student& s)
{
	return grade(s.midterm, s.fin, s.homework);
}

int main() {
	vector<Student> Students;
	Student record;
	string::size_type maxlen = 0;

	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		Students.push_back(record);
	}

	sort(Students.begin(), Students.end(), compare);

	for (vector<Student>::size_type i = 0; i != Students.size(); ++i) {
		cout << Students[i].name
			<< string(maxlen + 1 - Students[i].name.size(), ' ');
		try {
			double final_grade = grade(Students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (domain_error ez) {
			cout << ez.what();
		}
		cout << endl;
	}
	return 0;
}
