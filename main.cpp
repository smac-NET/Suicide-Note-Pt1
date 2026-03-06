#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <functional>

using namespace std;

vector<string> split(const string& s) 
{
    vector<string> res;
    stringstream ss(s);
    string line;

    while (getline(ss, line))
        res.push_back(line);

    return res;
}

string join(const vector<string>& v)
{
    string res;

    for (size_t i = 0; i < v.size(); i++)
    {
        res += v[i];
        if (i != v.size() - 1)
            res += "\n";
    }

    return res;
}



string diag_2_sym(const string& s) 
{

    vector<string> m = split(s);
    int n = m.size();

    vector<string> r(n, string(n, ' '));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            r[n - 1 - j][n - 1 - i] = m[i][j];

    return join(r);
}




string rot_90_counter(const string& s)
{

    vector<string> m = split(s);
    int n = m.size();

    vector<string> r(n, string(n, ' '));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            r[n - 1 - j][i] = m[i][j];

    return join(r);
}




string selfie_diag2_counterclock(const string& s)
{

    vector<string> orig = split(s);
    vector<string> diag = split(diag_2_sym(s));
    vector<string> rot = split(rot_90_counter(s));

    int n = orig.size();

    vector<string> res(n);

    for (int i = 0; i < n; i++)
        res[i] = orig[i] + "|" + diag[i] + "|" + rot[i];

    return join(res);
}



string oper(function<string(const string&)> fct, const string& s)
{
    return fct(s);
}


int main() 
{

    string s =
        "abcd\n"
        "efgh\n"
        "ijkl\n"
        "mnop";

    cout << "cub:\n";
    cout << oper(diag_2_sym, s) << "\n\n";

    cout << "-rotate cub:\n";
    cout << oper(rot_90_counter, s) << "\n\n";

    cout << "-mmatrix cub:\n";
    cout << oper(selfie_diag2_counterclock, s) << endl;

    return 0;
}