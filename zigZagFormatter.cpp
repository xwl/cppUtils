#include <codecvt>
#include <iostream>
#include <sstream>
#include <string>

std::wstring convert(const std::wstring& s, int numRows, const std::wstring& spacing = L" ")
{
    if (numRows <= 1)
        return s;

    std::wstringstream ss;

    for (int row = 0; row < numRows; ++row)
    {
        for (int index = row; index < s.size(); index += numRows * 2 - 2)
        {
            ss << s[index];

            int numFirstSpace = numRows - 2 - row;
            int numSecondSpace = numRows - 2 - numFirstSpace - 1;
            for(int k = 0; k < numFirstSpace; ++k)
                ss << spacing;

            if (row != 0 && row != numRows -1) {
                int next = index + numRows * 2 - 2 - row * 2;
                if (next < s.size())
                    ss << s[next];
            }

            for(int k = 0; k < numSecondSpace; ++k)
                ss << spacing;
        }
        ss << std::endl;
    }

    std::wcout << ss.str();
    return ss.str();
}

int main(int argc, char *argv[])
{
    // These two lines are need for wcout to work on the terminal.
    const std::locale utf8( std::locale(), new std::codecvt_utf8<wchar_t> );
    std::wcout.imbue(utf8);

    convert(L"生当作人杰死亦为鬼雄至今思项羽不肯过江东", 5, L"  ");
    /* std::wcout << std::endl; */
    /* convert(L"TOMORROWWILLBEFINE", 5); */
    return 0;
}

/* output: 
 *
生      鬼      肯
当    为雄    不过
作  亦  至  羽  江
人死    今项    东
杰      思

*/
